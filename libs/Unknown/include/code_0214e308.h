#pragma once

#include "types.h"

// One reading, 8 bytes: x, y, touched flag and invalid bits. The values from the other processor are raw;
// TP_GetCalibratedPoint converts x and y to screen coordinates.
typedef struct TouchSample {
    // Horizontal position: a 12-bit raw value in a raw sample, 0..0xff after TP_GetCalibratedPoint.
    /* 00 */ u16 mX;
    // Vertical position: a 12-bit raw value in a raw sample, 0..0xbf after TP_GetCalibratedPoint.
    /* 02 */ u16 mY;
    // 1 while the panel is touched, otherwise 0.
    /* 04 */ u16 mTouched;
    // 0 when the reading is usable; the game ignores a reading where it is not 0 and stores 3 when there is no panel.
    /* 06 */ u16 mInvalidBits;
} TouchSample;

// Four halfwords; TP_GetCalibratedPoint and TP_CalcCalibrateParam fill them, TP_SetCalibrateParam reads them and
// TP_GetUserInfo clears them.
typedef struct Unk0214e334 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk0214e334;

// Stored conversion from raw values to screen coordinates, six words: for each axis an origin, a scale and 0x10000000
// divided by the scale.
typedef struct TouchCalibration {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} TouchCalibration;

// Two fixed-address halfwords ReceiveTouchPanelReply reads, split into bit fields.
typedef union Unk0214ec18 {
    u16 h[2];
    struct {
        /* 00 */ u32 mUnk_00_0 : 12;
        /* 00 */ u32 mUnk_00_12 : 12;
        /* 00 */ u32 mUnk_00_24 : 1;
        /* 00 */ u32 mUnk_00_25 : 2;
        /* 00 */ u32 : 5;
    } f;
} Unk0214ec18;

// Fixed-address object read by TP_GetUserInfo.
typedef struct Unk0214eadc {
    /* 00 */ u8 mUnk_00[0x58];
    /* 58 */ u16 mUnk_58;
    /* 5a */ u16 mUnk_5a;
    /* 5c */ u8 mUnk_5c;
    /* 5d */ u8 mUnk_5d;
    /* 5e */ u16 mUnk_5e;
    /* 60 */ u16 mUnk_60;
    /* 62 */ u8 mUnk_62;
    /* 63 */ u8 mUnk_63;
} Unk0214eadc;

// State of the touch panel channel, 0x38 bytes, one instance: callback, latest single sample, ring of automatic samples
// (index, buffer, count), calibration and its flag, and the error and busy bits.
typedef struct TouchPanelState {
    // Called with (request number or 0x10 for a ring sample, result, ring index) when a request finishes or a sample
    // arrives; 0 for none. Nothing sets it in this build.
    /* 00 */ void (*mCallback)(u32, u8, u8);
    // The unconverted sample of the last single-sample request.
    /* 04 */ TouchSample mRawSample;
    // Ring position of the newest automatic sample; wraps at mAutoSampleBufferCount.
    /* 0c */ u16 mAutoSampleIndex;
    /* 0e */ u16 mUnk_0e;
    // The ring the automatic sampling writes into (the caller's array of TouchSample); 0 until a start request.
    /* 10 */ TouchSample *mAutoSampleBuffer;
    // Number of entries in mAutoSampleBuffer.
    /* 14 */ u16 mAutoSampleBufferCount;
    /* 16 */ u8 mUnk_16[2];
    // The stored calibration; used only while mCalibrated is set.
    /* 18 */ TouchCalibration mCalibration;
    // 1 once a calibration is stored; 0 after init or when TP_SetCalibrateParam gets a null pointer.
    /* 30 */ u16 mCalibrated;
    /* 32 */ vu16 mUnk_32;
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

// Returns the error bits selected by the argument (1 single sample, 2 start, 4 stop).
u32 TP_CheckError(u32 a);
// Spins until none of the busy bits in the argument is set (1 single sample, 2 start, 4 stop).
void TP_WaitBusy(u32 a);
// Converts a raw sample to screen coordinates with the stored calibration, clamped to 0..0xff and 0..0xbf; the
// coordinates are 0 when the sample is not touched. Copies the sample unchanged when no calibration is stored.
void TP_GetCalibratedPoint(Unk0214e334 *out, const TouchSample *in);
// Computes the calibration from two raw points (12-bit values) and their screen positions (below 0x100 and 0xc0).
// Returns 1, with the output possibly partly written, when a value is out of range, two paired values are equal or a
// result does not fit 16 bits; returns 0 on success.
u32 TP_CalcCalibrateParam(Unk0214e334 *out, u16 a, u16 b, u16 c, u16 d, u16 e, u16 f, u16 g, u16 h);
// Returns the ring position of the newest automatic sample.
u32 TP_GetLatestIndexInAuto(void);
// Sends the command word that stops the automatic sampling; marks the request busy, or sets its error bit and calls the
// callback when the word is refused. Returns at once.
void TP_RequestAutoSamplingStopAsync(void);
// Stores the ring (p, n entries, the touched field of each cleared) and sends the two command words that start the
// sampling on its own; the first two arguments go into those words. Marks the request busy, or sets its error bit and
// calls the callback when a word is refused. Returns at once.
void TP_RequestAutoSamplingStartAsync(u32 a, u32 b, TouchSample *p, u32 n);
// Waits until the single-sample request has finished. Returns 1 when it failed, otherwise copies the unconverted sample
// to the output and returns 0.
u32 TP_WaitRawResult(TouchSample *out);
// Sends the command word for one sample and marks the request busy. When the word is refused, sets the request's error
// bit and calls the callback. Returns at once.
void TP_RequestSamplingAsync(void);
// Stores the calibration (origin and scale of each axis and 0x10000000 divided by the scale, 0 for a zero scale) and
// marks the panel calibrated. A null pointer marks it not calibrated.
void TP_SetCalibrateParam(Unk0214e334 *p);
// Reads the eight stored calibration values from the shared block at 0x027ffc80 and computes the calibration into the
// output with TP_CalcCalibrateParam. Zeroes the output when the four raw values are all 0 or the calculation refuses.
// Always returns 1.
u32 TP_GetUserInfo(Unk0214e334 *p);
// Starts the touch panel channel once. Clears the callback, the ring, the calibration flag and the busy and error bits,
// waits for the other processor on PXI tag 6 and installs the receive handler. Later calls return at once.
void TP_Init(void);
// Receive handler of PXI tag 6. An error word sets the error bit of its request and calls the callback with result 4. A
// word for the automatic sampling stores the next ring entry from the shared halfwords at 0x027fffaa and 0x027fffac and
// calls the callback. A final word with result 0 clears the busy bit of its request (the single-sample request also
// stores the sample); results 2, 3 and 4 set the error bit and call the callback with 1, 2 and 3; any other result
// stops in an endless loop with interrupts off.
void ReceiveTouchPanelReply(u32 a, u32 b, u32 c);
