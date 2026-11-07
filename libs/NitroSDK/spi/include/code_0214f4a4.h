#pragma once

#include "types.h"

typedef struct OSMutex OSMutex;

typedef void (*PMCallback)(u32 result, void *arg);
typedef void (*PMSleepCallback)(void *arg);

// PMi_ExecuteList calls mCallback with mArg and follows mNext; PMi_DeleteList, PMi_AppendList and
// PMi_PrependList link and unlink objects through mNext.
typedef struct PMSleepCallbackInfo {
    /* 00 */ PMSleepCallback mCallback;
    /* 04 */ void *mArg;
    /* 08 */ struct PMSleepCallbackInfo *mNext;
} PMSleepCallbackInfo;

// The one command in flight: mLock is nonzero from PMi_Lock until PMi_CallCallbackAndUnlock; the other members
// belong to that command.
typedef struct PMiWork {
    // Nonzero while a command is in flight.
    /* 00 */ vu32 mLock;
    // Called once with the reply result when the command finishes; 0 when there is none.
    /* 04 */ PMCallback mCallback;
    // Second argument of mCallback.
    /* 08 */ void *mCallbackArg;
    // Where the reply byte of the get-LED-pattern command (0x67) is stored.
    /* 0c */ u32 *mWork;
} PMiWork;

// One per register number 0 to 3: where a register read puts the reply byte.
typedef struct PMData16 {
    // Cleared when a read is requested and set to 1 when its reply arrives; nothing reads it.
    /* 00 */ u16 mFlag;
    // Where the reply byte is stored; 0 when the caller gave none.
    /* 04 */ u16 *mBuffer;
} PMData16;

// Set to 1 by PM_Init; a second call returns at once.
extern u16 gPowerInitialized;
// Cleared before the handshake word is sent in PMi_SendSleepStart, set by PMi_CommonCallback when the reply (0x60)
// arrives.
extern vu32 gPowerSleepHandshakeReplyReceived;
extern vu32 data_02180438;
// List of PMSleepCallbackInfo run first by PM_GoSleepMode.
extern PMSleepCallbackInfo *gPowerPreSleepCallbacks;
extern u32 data_02180440;
// List of PMSleepCallbackInfo run last by PM_GoSleepMode.
extern PMSleepCallbackInfo *gPowerPostSleepCallbacks;
// The command in flight.
extern PMiWork gPowerCommand;
extern OSMutex data_02180458;
// The four register buffers.
extern PMData16 gPMData16s[4];

// Removes info from the post-sleep list.
void PM_DeletePostSleepCallback(PMSleepCallbackInfo *info);
// Removes info from the pre-sleep list.
void PM_DeletePreSleepCallback(PMSleepCallbackInfo *info);
// Appends info to the list PM_GoSleepMode runs after the wake.
void PM_AppendPostSleepCallback(PMSleepCallbackInfo *info);
// Puts info first in the list PM_GoSleepMode runs before the sleep sequence.
void PM_PrependPreSleepCallback(PMSleepCallbackInfo *info);
// Appends info to the list PM_GoSleepMode runs before the sleep sequence.
void PM_AppendPreSleepCallback(PMSleepCallbackInfo *info);
// Calls PMSleepCallbackInfo.mCallback with mArg for each entry of the list.
void PMi_ExecuteList(PMSleepCallbackInfo *list);
// Unlinks info from *listp.
void PMi_DeleteList(PMSleepCallbackInfo **listp, PMSleepCallbackInfo *info);
// Puts info last in *listp.
void PMi_AppendList(PMSleepCallbackInfo **listp, PMSleepCallbackInfo *info);
// Puts info first in *listp.
void PMi_PrependList(PMSleepCallbackInfo **listp, PMSleepCallbackInfo *info);
// PM_GetLEDPatternAsync, then waits for the reply; *patternBuf receives the pattern.
u32 PM_GetLEDPattern(u32 *patternBuf);
// Sends command 0x67; the reply byte is stored through patternBuf and callback is called with the result.
u32 PM_GetLEDPatternAsync(u32 *patternBuf, PMCallback callback, void *arg);
// PMi_SendLEDPatternCommandAsync, then waits; returns the result.
u32 PMi_SendLEDPatternCommand(u32 pattern);
// Sends command 0x66 with pattern byte pattern; callback is called with the result.
u32 PMi_SendLEDPatternCommandAsync(u32 pattern, PMCallback callback, void *arg);
// Returns bit 0 of reg_GX_POWCNT: 1 while the screens are powered.
int PM_GetLCDPower(void);
// Anything but 1 counts as 0. Switches the screens on or off with no LED change; returns 0 when the turn-on guard of
// PMi_SetLCDPower refuses.
BOOL PM_SetLCDPower(u32 sw);
// sw = 1 turns the screens on, sw = 0 off. On: returns 0 and changes nothing when fewer than 8 counts of the shared
// counter at 0x27ffc3c have passed since the last turn-off, unless skip is nonzero. led != 0 also sets that LED
// (waiting for it when isSync is nonzero). Off: stores the counter for that guard. Returns 1 when done.
BOOL PMi_SetLCDPower(u32 sw, u32 led, u32 skip, u32 isSync);
// Runs the pre-sleep callbacks, switches both backlights and the screens off, asks the other processor to sleep (wake
// triggers trigger, key data logic | keyPattern), halts, then restores the screens and runs the post-sleep callbacks.
// When bit 0x8 of trigger is set and IRQ request bit 0x100000 is pending after the wake, it powers off instead of
// restoring.
void PM_GoSleepMode(u32 trigger, u32 logic, u32 keyPattern);
// Sends one word on tag 8, retrying until the FIFO accepts it.
void PMi_SendPxiData(u32 data);
// Reads register 0 and stores bit 0x8 through top and bit 0x4 through bottom as 0 or 1. Returns the read result.
u32 PM_GetBackLight(u32 *top, u32 *bottom);
// Writes register 3 and waits for the reply; the microphone set-up passes 3.
u32 PM_SetAmpGain(u32 gain);
// Writes register 2 and waits for the reply; start-up code passes 1 after initialising the microphone.
u32 PM_SetAmp(u32 status);
// Sends the power-off utility command (14) and waits for the reply.
u32 PM_ForceToPowerOff(void);
// Sends the power-off utility command (14) and returns.
u32 PM_ForceToPowerOffAsync(PMCallback callback, void *arg);
// PM_SetBackLightAsync, then waits for the reply and returns it.
u32 PM_SetBackLight(u32 target, u32 sw);
// target picks the screen (0, 1, or 2 for both), sw is 1 for on and 0 for off; sends utility command 6/7, 4/5 or 8/9.
// Returns 0xffff for any other pair.
u32 PM_SetBackLightAsync(u32 target, u32 sw, PMCallback callback, void *arg);
// PMi_SetLEDAsync, then waits; returns the result.
u32 PMi_SetLED(u32 status);
// status 1, 2, 3 sends utility command 1, 3, 2; any other value returns 0xffff.
u32 PMi_SetLEDAsync(u32 status, PMCallback callback, void *arg);
// PMi_WriteRegisterAsync, then waits; returns the result.
u32 PMi_WriteRegister(u16 registerAddr, u16 data);
// Writes data to register registerAddr; callback is called with the result.
u32 PMi_WriteRegisterAsync(u16 registerAddr, u16 data, PMCallback callback, void *arg);
// PMi_ReadRegisterAsync, then waits; returns the result.
u32 PMi_ReadRegister(u16 registerAddr, u16 *buffer);
// Requests register registerAddr (0 to 3, not range-checked) into *buffer; callback is called with the result.
u32 PMi_ReadRegisterAsync(u16 registerAddr, u16 *buffer, PMCallback callback, void *arg);
// Sends utility command number and calls callback with the reply; returns 1 when another command is in flight.
u32 PM_SendUtilityCommandAsync(u32 number, PMCallback callback, void *arg);
// Locks the command, sends the handshake word and waits for its reply, switches the screens off with the LED set to 2,
// then sends the sleep word (trigger) and the key word (keyIntrData). Returns 1 when busy.
u32 PMi_SendSleepStart(u16 trigger, u16 keyIntrData);
// Receive handler of the tag-8 channel. An error finishes the command with 2. Replies 0x70-0x73 store their byte
// through PMData16.mBuffer (result 0); 0x60 sets gPowerSleepHandshakeReplyReceived; 0x62 sets data_02180438; 0x67
// stores through PMiWork.mWork (result 0). Then finishes the command with the result.
void PMi_CommonCallback(u32 tag, u32 data, u32 err);
// Runs once: opens the power-management channel (PXI tag 8), waits for the other processor, installs
// PMi_CommonCallback as its handler and clears the register buffers.
void PM_Init(void);
// Clears the in-flight mark, then calls the stored callback once with the result and PMiWork.mCallbackArg.
void PMi_CallCallbackAndUnlock(u32 result);
// Callback of the blocking commands: stores the result through arg.
void PMi_DummyCallback(u32 result, void *arg);
// Spins until no command is in flight.
void PMi_WaitBusy(void);
// Marks a command as in flight and returns 1; returns 0 when one already is.
BOOL PMi_Lock(void);
