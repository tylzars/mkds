#pragma once

#include "types.h"

// PxiCommandEnqueue takes an PxiCommand from PxiCommandAlloc, stores its five arguments in mUnk_04 to mUnk_14 and
// passes it to PxiCommandPendingAppend. The functions after it pass a fixed first argument to PxiCommandEnqueue,
// SendTrackFieldCommand or SendPlayerFieldCommand.
void PxiCommandEnqueue(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_02020844(u32 a);
// Enqueues command 7. The first word is the player number with the width in bytes (1, 2 or 4) in bits 24 and up; the
// other words are the track bit mask, the byte offset into the record of each selected track and the value.
void SendTrackFieldCommand(u32 a, u32 b, u32 c, u32 d, u32 e);
// Enqueues command 6 with its four arguments unchanged: the player number, a byte offset into the player's record, the
// value and the width in bytes (1, 2 or 4).
void SendPlayerFieldCommand(u32 a, u32 b, u32 c, u32 d);
// Enqueues command 24 with 0xffffffff and three zeros.
void SND_ResetMasterPan(void);
// Enqueues command 24 with the value and three zeros.
void SND_SetMasterPan(u32 a);
// Enqueues command 25 with its four arguments.
void SND_SetOutputSelector(u32 a, u32 b, u32 c, u32 d);
// Enqueues command 23 with the value and three zeros.
void SND_SetMasterVolume(u32 a);
// Enqueues command 32 with the two pointers. The other processor releases every channel whose wave data pointer lies
// between them.
void SND_InvalidateWaveData(void *a, void *b);
// Enqueues command 31 with the two pointers. The other processor ends every active player whose bank pointer (the
// fourth argument of command 2) lies between them.
void SND_InvalidateBankData(void *a, void *b);
// Enqueues command 30 with the two pointers. The other processor ends every active player that has a track whose read
// pointer lies between them.
void SND_InvalidateSeqData(void *a, void *b);
// Enqueues command 14. First word: the first argument | the ninth argument << 16. Second word: the third argument.
// Third word: the seventh argument << 24 | the eighth argument << 22 | the sixth argument. Fourth word: the fourth
// argument << 26 | the second argument << 24 | the tenth argument << 16 | the fifth argument.
void SND_SetupChannelPcm(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
// Enqueues command 20 with a channel bit mask, a volume and a shift.
void SND_SetChannelVolume(u32 a, u32 b, u32 c);
// Enqueues command 27 with a channel bit mask and a flags word.
void SND_UnlockChannel(u32 a, u32 b);
// Enqueues command 26 with a channel bit mask and a flags word.
void SND_LockChannel(u32 a, u32 b);
// Enqueues command 8 with the player number, the track bit mask and the mode unchanged.
void SND_SetTrackMuteEx(u32 a, u32 b, u32 c);
// Stores the function and its argument in the alarm table entry given by the first argument (PxiCommandCallbackSet,
// which returns the generation byte of that entry), then enqueues command 18 with the alarm number, the second
// argument, the third argument and that byte.
void SND_SetupAlarm(s32 a, u32 b, u32 c, UnkFunc *d, void *e);
// Enqueues command 17 with the third argument, the fourth argument and one word that holds the first, second, fifth,
// sixth and seventh arguments as the bits 31, 30, 29, 28 and 27.
void SND_SetupCapture(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
// For each of the low 8 bits that are set in the third argument calls func_02021764 with the bit number, then enqueues
// command 13 with the four arguments.
void SND_StopTimer(u32 a, u32 b, u32 c, u32 d);
// Enqueues command 12 with a channel bit mask, a capture bit mask, an alarm bit mask and a flags word.
void SND_StartTimer(u32 a, u32 b, u32 c, u32 d);
// Enqueues command 9 with the player number, the track bit mask and the channel bit mask.
void SND_SetTrackAllocatableChannel(u32 a, u32 b, u32 c);
// Calls SendTrackFieldCommand with the player number, the track bit mask, offset 0x19, the value and the width 1.
void SND_SetTrackModSpeed(u32 a, u32 b, u32 c);
// Calls SendTrackFieldCommand with the player number, the track bit mask, offset 9, the value and the width 1.
void SND_SetTrackPan(u32 a, u32 b, u32 c);
// Calls SendTrackFieldCommand with the player number, the track bit mask, offset 0xc, the value and the width 2.
void SND_SetTrackPitch(u32 a, u32 b, u32 c);
// Calls SendTrackFieldCommand with the player number, the track bit mask, offset 0xa, the value and the width 2.
void SND_SetTrackVolume(u32 a, u32 b, u32 c);
// Enqueues command 10 with the player number, the variable index and the value.
void SND_SetPlayerLocalVariable(u32 a, u32 b, u32 c);
// Calls SendPlayerFieldCommand with the player number, offset 4, the value and the width 1.
void SND_SetPlayerChannelPriority(u32 a, u32 b);
// Calls SendPlayerFieldCommand with the player number, offset 6, the value and the width 2.
void SND_SetPlayerVolume(u32 a, u32 b);
// Calls SendPlayerFieldCommand with the player number, offset 0x1a, the value and the width 2.
void SND_SetPlayerTempoRatio(u32 a, u32 b);
// Enqueues command 3 with the player number and three zeros.
void SND_StartPreparedSeq(u32 a);
// Enqueues command 2 with the player number, a data base pointer, an offset and a bank pointer.
void SND_PrepareSeq(u32 a, u32 b, u32 c, u32 d);
// Enqueues command 1 with the player number and three zeros.
void SND_StopSeq(u32 a);
