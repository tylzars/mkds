#pragma once

#include "types.h"

typedef struct ThreadLock ThreadLock;

// CallbackListRun calls mCallback with mArg and follows mNext; CallbackListRemove, CallbackListAppend and
// CallbackListPrepend link and unlink objects through mNext.
typedef struct CallbackEntry {
    /* 00 */ void (*mCallback)(void *);
    /* 04 */ void *mArg;
    /* 08 */ struct CallbackEntry *mNext;
} CallbackEntry;

// The one command in flight: mLocked is nonzero from TryLockPowerCommand until FinishPowerCommand; the other members
// belong to that command.
typedef struct PowerCommand {
    // Nonzero while a command is in flight.
    /* 00 */ vu32 mLocked;
    // Called once with the reply result when the command finishes; 0 when there is none.
    /* 04 */ void (*mCallback)(u32 a, u32 *b);
    // Second argument of mCallback.
    /* 08 */ u32 *mCallbackArg;
    // Where the reply byte of the get-LED-pattern command (0x67) is stored.
    /* 0c */ u32 *mLedPatternBuffer;
} PowerCommand;

// One per register number 0 to 3: where a register read puts the reply byte.
typedef struct PowerRegisterSlot {
    // Cleared when a read is requested and set to 1 when its reply arrives; nothing reads it.
    /* 00 */ u16 mReplyReceived;
    // Where the reply byte is stored; 0 when the caller gave none.
    /* 04 */ u16 *mBuffer;
} PowerRegisterSlot;

// Set to 1 by PM_Init; a second call returns at once.
extern u16 gPowerInitialized;
// Cleared before the handshake word is sent in SendPowerSleepRequest, set by ReceivePowerReply when the reply (0x60)
// arrives.
extern vu32 gPowerSleepHandshakeReplyReceived;
extern vu32 data_02180438;
// List of CallbackEntry run first by PM_GoSleepMode.
extern CallbackEntry *gPowerPreSleepCallbacks;
extern u32 data_02180440;
// List of CallbackEntry run last by PM_GoSleepMode.
extern CallbackEntry *gPowerPostSleepCallbacks;
// The command in flight.
extern PowerCommand gPowerCommand;
extern ThreadLock data_02180458;
// The four register slots.
extern PowerRegisterSlot gPowerRegisterSlots[4];

// Removes p from the post-sleep list.
void PM_DeletePostSleepCallback(CallbackEntry *p);
// Removes p from the pre-sleep list.
void PM_DeletePreSleepCallback(CallbackEntry *p);
// Appends p to the list PM_GoSleepMode runs after the wake.
void PM_AppendPostSleepCallback(CallbackEntry *p);
// Puts p first in the list PM_GoSleepMode runs before the sleep sequence.
void PM_PrependPreSleepCallback(CallbackEntry *p);
// Appends p to the list PM_GoSleepMode runs before the sleep sequence.
void PM_AppendPreSleepCallback(CallbackEntry *p);
void CallbackListRun(CallbackEntry *p);
void CallbackListRemove(CallbackEntry **pp, CallbackEntry *p);
void CallbackListAppend(CallbackEntry **pp, CallbackEntry *p);
void CallbackListPrepend(CallbackEntry **pp, CallbackEntry *p);
// PM_GetLEDPatternAsync, then waits for the reply; *p receives the pattern.
int PM_GetLEDPattern(u32 *p);
// Sends command 0x67; the reply byte is stored through p and fn is called with the result.
int PM_GetLEDPatternAsync(u32 *p, void (*fn)(u32 a, u32 *b), u32 *arg);
// SendPowerLedPatternAsync, then waits; returns the result.
int SendPowerLedPattern(u32 a);
// Sends command 0x66 with pattern byte a; fn is called with the result.
int SendPowerLedPatternAsync(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg);
// Returns bit 0 of reg_GX_POWCNT: 1 while the screens are powered.
int PM_GetLCDPower(void);
// Anything but 1 counts as 0. Switches the screens on or off with no LED change; returns 0 when the turn-on guard of
// TrySetLcdPowerAndLed refuses.
int PM_SetLCDPower(u32 a);
// a = 1 turns the screens on, a = 0 off. On: returns 0 and changes nothing when fewer than 8 counts of the shared
// counter at 0x27ffc3c have passed since the last turn-off, unless c is nonzero. b != 0 also sets that LED (waiting for
// it when d is nonzero). Off: stores the counter for that guard. Returns 1 when done.
int TrySetLcdPowerAndLed(u32 a, u32 b, u32 c, u32 d);
// Runs the pre-sleep callbacks, switches both backlights and the screens off, asks the other processor to sleep (wake
// triggers a, key data b | c), halts, then restores the screens and runs the post-sleep callbacks. When bit 0x8 of a is
// set and IRQ request bit 0x100000 is pending after the wake, it powers off instead of restoring.
void PM_GoSleepMode(u32 a, u32 b, u32 c);
// Sends one word on tag 8, retrying until the FIFO accepts it.
void SendPowerFifoWord(u32 a);
// Reads register 0 and stores bit 0x8 through a and bit 0x4 through b as 0 or 1. Returns the read result.
int PM_GetBackLight(u32 *a, u32 *b);
// Writes register 3 and waits for the reply; the microphone set-up passes 3.
int PM_SetAmpGain(u32 a);
// Writes register 2 and waits for the reply; start-up code passes 1 after initialising the microphone.
int PM_SetAmp(u32 a);
// Sends the power-off utility command (14) and waits for the reply.
int PM_ForceToPowerOff(void);
// Sends the power-off utility command (14) and returns.
int PM_ForceToPowerOffAsync(void (*fn)(u32 a, u32 *b), u32 *arg);
// PM_SetBackLightAsync, then waits for the reply and returns it.
int PM_SetBackLight(u32 a, u32 b);
// a picks the screen (0, 1, or 2 for both), b is 1 for on and 0 for off; sends utility command 6/7, 4/5 or 8/9. Returns
// 0xffff for any other pair.
int PM_SetBackLightAsync(u32 a, u32 b, void (*fn)(u32 a, u32 *b), u32 *arg);
// SetPowerLedAsync, then waits; returns the result.
int SetPowerLed(u32 a);
// a = 1, 2, 3 sends utility command 1, 3, 2; any other value returns 0xffff.
int SetPowerLedAsync(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg);
// WritePowerRegisterAsync, then waits; returns the result.
int WritePowerRegister(u32 a, u16 b);
// Writes b to register a; fn is called with the result.
int WritePowerRegisterAsync(u32 a, u16 b, void (*fn)(u32 a, u32 *b), u32 *arg);
// ReadPowerRegisterAsync, then waits; returns the result.
int ReadPowerRegister(u32 a, u16 *p);
// Requests register a (0 to 3, not range-checked) into *p; fn is called with the result.
int ReadPowerRegisterAsync(u32 a, u16 *p, void (*fn)(u32 a, u32 *b), u32 *arg);
// Sends utility command number a and calls fn with the reply; returns 1 when another command is in flight.
int PM_SendUtilityCommandAsync(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg);
// Locks the command, sends the handshake word and waits for its reply, switches the screens off with the LED set to 2,
// then sends the sleep word (a) and the key word (b). Returns 1 when busy.
int SendPowerSleepRequest(u32 a, u16 b);
// Receive handler of the tag-8 channel. An error finishes the command with 2. Replies 0x70-0x73 store their byte
// through the register slot buffer (result 0); 0x60 sets gPowerSleepHandshakeReplyReceived; 0x67 stores through
// mLedPatternBuffer (result 0). Then finishes the command with the result.
void ReceivePowerReply(u32 a, u32 b, u32 c);
// Runs once: opens the power-management channel (PXI tag 8), waits for the other processor, installs ReceivePowerReply
// as its handler and clears the register slots.
void PM_Init(void);
// Clears the in-flight mark, then calls the stored callback once with a and mCallbackArg.
void FinishPowerCommand(u32 a);
void WordStore(u32 a, u32 *p);
// Spins until no command is in flight.
void WaitPowerCommandDone(void);
// Marks a command as in flight and returns 1; returns 0 when one already is.
int TryLockPowerCommand(void);
