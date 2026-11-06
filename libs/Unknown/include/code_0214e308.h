#pragma once

#include "types.h"

// One reading, 8 bytes: x, y, touched flag and validity. The values from the other processor are raw;
// TP_GetCalibratedPoint converts x and y to screen coordinates.
typedef struct TPData {
    // Horizontal position: a 12-bit raw value in a raw sample, 0..0xff after TP_GetCalibratedPoint.
    /* 00 */ u16 mX;
    // Vertical position: a 12-bit raw value in a raw sample, 0..0xbf after TP_GetCalibratedPoint.
    /* 02 */ u16 mY;
    // 1 while the panel is touched, otherwise 0.
    /* 04 */ u16 mTouch;
    // 0 when the reading is usable (1 for x invalid, 2 for y invalid, 3 for both).
    /* 06 */ u16 mValidity;
} TPData;

// Stored conversion for TP_GetCalibratedPoint: the origin, the size of a screen dot and 0x10000000 divided by that
// size, for x and then y.
typedef struct TPCalibrateParam {
    /* 00 */ s16 mX0;
    /* 02 */ s16 mY0;
    /* 04 */ s16 mXDotSize;
    /* 06 */ s16 mYDotSize;
} TPCalibrateParam;

typedef struct TPiCalibrateParam {
    /* 00 */ s32 mX0;
    /* 04 */ s32 mXDotSize;
    /* 08 */ s32 mXDotSizeInv;
    /* 0c */ s32 mY0;
    /* 10 */ s32 mYDotSize;
    /* 14 */ s32 mYDotSizeInv;
} TPiCalibrateParam;

typedef enum TPRequestCommand {
    TP_REQUEST_COMMAND_SAMPLING = 0,
    TP_REQUEST_COMMAND_AUTO_ON = 1,
    TP_REQUEST_COMMAND_AUTO_OFF = 2,
    TP_REQUEST_COMMAND_SET_STABILITY = 3,
    TP_REQUEST_COMMAND_AUTO_SAMPLING = 0x10
} TPRequestCommand;

typedef enum TPRequestResult {
    TP_RESULT_SUCCESS = 0,
    TP_RESULT_INVALID_PARAMETER,
    TP_RESULT_ILLEGAL_STATUS,
    TP_RESULT_EXCLUSIVE,
    TP_RESULT_PXI_BUSY
} TPRequestResult;

typedef enum TPState { TP_STATE_READY = 0, TP_STATE_SAMPLING, TP_STATE_AUTO_SAMPLING, TP_STATE_AUTO_WAIT_END } TPState;

// result is a TPRequestResult and index the ring position, both passed as bytes.
typedef void (*TPRecvCallback)(TPRequestCommand command, u8 result, u8 index);

// The two shared halfwords at 0x027fffaa and 0x027fffac that carry a reading, split into bit fields.
typedef union SPITpData {
    u16 halfs[2];
    struct {
        /* 00 */ u32 mX : 12;
        /* 00 */ u32 mY : 12;
        /* 00 */ u32 mTouch : 1;
        /* 00 */ u32 mValidity : 2;
        /* 00 */ u32 : 5;
    } e;
} SPITpData;

// Calibration words in the shared block at 0x027ffc80, read by TP_GetUserInfo.
typedef struct Unk0214eadc {
    /* 00 */ u8 mUnk_00[0x58];
    /* 58 */ u16 mRawX1;
    /* 5a */ u16 mRawY1;
    /* 5c */ u8 mDx1;
    /* 5d */ u8 mDy1;
    /* 5e */ u16 mRawX2;
    /* 60 */ u16 mRawY2;
    /* 62 */ u8 mDx2;
    /* 63 */ u8 mDy2;
} Unk0214eadc;

// State of the touch panel channel, 0x38 bytes, one instance.
typedef struct TouchPanelState {
    // Called when a request finishes or a sample arrives; 0 for none. Nothing sets it in this game.
    /* 00 */ TPRecvCallback mCallback;
    // The unconverted sample of the last single-sample request.
    /* 04 */ TPData mRawSample;
    // Ring position of the newest automatic sample; wraps at mAutoSampleBufferCount.
    /* 0c */ u16 mAutoSampleIndex;
    // The frequency argument of the last automatic sampling start.
    /* 0e */ u16 mFrequence;
    // The ring the automatic sampling writes into (the caller's array of TPData); 0 until a start request.
    /* 10 */ TPData *mAutoSampleBuffer;
    // Number of entries in mAutoSampleBuffer.
    /* 14 */ u16 mAutoSampleBufferCount;
    /* 16 */ u8 mUnk_16[2];
    // The stored calibration; used only while mCalibrated is set.
    /* 18 */ TPiCalibrateParam mCalibration;
    // 1 once a calibration is stored; 0 after init or when TP_SetCalibrateParam gets a null pointer.
    /* 30 */ u16 mCalibrated;
    // Panel state (TPState): ready, or automatic sampling running.
    /* 32 */ vu16 mState;
    // One bit per request (1 single sample, 2 start, 4 stop): set when the command word is refused or the reply is an
    // error, cleared when the request is sent.
    /* 34 */ vu16 mErrorFlags;
    // One bit per request, set when the request is sent and cleared by its reply.
    /* 36 */ vu16 mBusyFlags;
} TouchPanelState;

// Set once by TP_Init.
extern u16 gTouchPanelInitialized;
// The touch panel channel state.
extern TouchPanelState gTouchPanelState;

// Returns the error bits selected by command_flgs (1 single sample, 2 start, 4 stop).
u32 TP_CheckError(u32 commandFlgs);
// Spins until none of the busy bits in commandFlgs is set (1 single sample, 2 start, 4 stop).
void TP_WaitBusy(u32 commandFlgs);
// Converts a raw sample to screen coordinates with the stored calibration, clamped to 0..0xff and 0..0xbf; the
// coordinates are 0 when the sample is not touched. Copies the sample unchanged when no calibration is stored.
void TP_GetCalibratedPoint(TPData *disp, const TPData *raw);
// Computes the calibration from two raw points (12-bit values) and their screen positions (below 0x100 and 0xc0).
// Returns 1, with the output possibly partly written, when a value is out of range, two paired values are equal or a
// result does not fit 16 bits; returns 0 on success.
u32 TP_CalcCalibrateParam(TPCalibrateParam *calibrate, u16 rawX1, u16 rawY1, u16 dx1, u16 dy1, u16 rawX2, u16 rawY2,
                          u16 dx2, u16 dy2);
// Returns the ring position of the newest automatic sample.
u16 TP_GetLatestIndexInAuto(void);
// Sends the command word that stops the automatic sampling; marks the request busy, or sets its error bit and calls the
// callback when the word is refused. Returns at once.
void TP_RequestAutoSamplingStopAsync(void);
// Stores the ring (samplingBufs, bufSize entries, the touch field of each cleared) and sends the two command words that
// start the sampling on its own. Marks the request busy, or sets its error bit and calls the callback when a word is
// refused. Returns at once.
void TP_RequestAutoSamplingStartAsync(u16 vcount, u16 frequence, TPData *samplingBufs, u16 bufSize);
// Waits until the single-sample request has finished. Returns 1 when it failed, otherwise copies the unconverted sample
// to result and returns 0.
u32 TP_WaitRawResult(TPData *result);
// Sends the command word for one sample and marks the request busy. When the word is refused, sets the request's error
// bit and calls the callback. Returns at once.
void TP_RequestSamplingAsync(void);
// Stores the calibration (origin and dot size of each axis and 0x10000000 divided by the dot size, 0 for a zero size)
// and marks the panel calibrated. A null pointer marks it not calibrated.
void TP_SetCalibrateParam(TPCalibrateParam *param);
// Reads the eight stored calibration values from the shared block at 0x027ffc80 and computes the calibration with
// TP_CalcCalibrateParam. Zeroes it when the four raw values are all 0 or the calculation refuses. Always returns 1.
BOOL TP_GetUserInfo(TPCalibrateParam *calibrate);
// Starts the touch panel channel once. Clears the callback, the ring, the calibration flag and the busy and error bits,
// waits for the other processor on PXI tag 6 and installs the receive handler. Later calls return at once.
void TP_Init(void);
// Receive handler of PXI tag 6. An error word sets the error bit of its request and calls the callback with
// TP_RESULT_PXI_BUSY. A word for the automatic sampling stores the next ring entry from the shared halfwords and calls
// the callback. A final word with result 0 clears the busy bit of its request (the single-sample request also stores
// the sample); results 2, 3 and 4 set the error bit and call the callback with 1, 2 and 3; any other result stops in an
// endless loop with interrupts off.
void TPi_TpCallback(u32 tag, u32 data, BOOL err);
