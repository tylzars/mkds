#pragma once

#include "types.h"

typedef struct WiFiPeerMessage WiFiPeerMessage;
typedef struct Unk0219887c Unk0219887c;

// State of the message being sent to, and the one being received from, one peer (index into WiFiMessageLayer.mPeers),
// 0x30 bytes: send side buffer / total size / sent size, receive side buffer / capacity / total size / received size /
// mReceiveState, plus the kind of the message being received.
typedef struct WiFiPeerMessage {
    /* 00 */ u8 *mSendBuffer;
    /* 04 */ u8 *mReceiveBuffer;
    /* 08 */ s32 mReceiveBufferSize;
    // Bytes of the current message already handed to the socket (0 at start, += chunk).
    /* 0c */ s32 mSentSize;
    // Bytes of the current message received so far (reset when a header arrives, += packet size).
    /* 10 */ s32 mReceivedSize;
    // Total size of the message being sent (the size argument of StartPeerMessageSend); 0 when no send is running.
    /* 14 */ s32 mSendSize;
    // Total size of the message being received, from the header (code_021a2ccc.c:239); 0 after the message is complete.
    /* 18 */ s32 mReceiveSize;
    /* 1c */ u8 mUnk_1c;
    // Receive state, switched on once per received packet in func_ov000_021a2eec (code_021a2ccc.c:181, through the
    // getter func_ov000_021a2fb4): 0 initial (only a control header, kind 2 to 4, is accepted); 1 expecting a header
    // (SetPeerReceiveBuffer, end of a message); 2 header of a data message (kind 1) accepted, body packets are copied
    // into the buffer; 3 control header (kind 2 to 4) taken, the next packet is the control body (state restored from
    // mUnk_1e); 4 data header refused (no buffer or too small): the next packet is dropped and the state returns to 1.
    // Not a per-frame switch.
    /* 1d */ u8 mReceiveState;
    /* 1e */ u8 mUnk_1e;
    /* 1f */ u8 pad_1f[3];
    // Kind from the header of the current message: 1 data, 2 to 4 control (func_ov000_021a2dfc stores it,
    // func_ov000_021a2d38 switches on it and hands 2 to 4 to func_ov000_021a18e0).
    /* 22 */ u16 mMessageKind;
    /* 24 */ u64 mUnk_24;
    /* 2c */ u32 mUnk_2c;
} WiFiPeerMessage;

// Message framing on top of the Gt2 socket, embedded in WiFiConnection at 0x7a0 (0x614 bytes = sizeof, zeroed by
// InitWiFiMessageLayer), reached through gWiFiMessageLayer: one WiFiPeerMessage per peer index (32), an 8-byte header
// (size, kind, 2 more bytes) before each message, bodies cut into chunks of at most mSendChunkSize that
// UpdateWiFiMessageLayer continues every frame in connection state 6; completed messages go to mReceiveCallback.
typedef struct WiFiMessageLayer {
    /* 000 */ WiFiPeerMessage mPeers[32];
    // Called after a send was queued or finished, with (size, index).
    /* 600 */ void (*mSendCallback)(s32 a, u32 b);
    // Called with (index, buffer, size) when a received message is complete.
    /* 604 */ void (*mReceiveCallback)(u32 a, u8 *b, s32 c);
    /* 608 */ void (*mUnk_608)(u32 a);
    /* 60c */ void (*mUnk_60c)(u32 a, u32 b);
    // u16 0x5b9 (1465), set by InitWiFiMessageLayer: the most the layer hands the socket in one call. A message is cut
    // into chunks of at most this size (code_021a3264.c:124, code_021a2ccc.c:114; a size equal to it is
    // allowed, the last chunk is shorter) and a single-packet send above it is refused (code_021a3264.c:152).
    /* 610 */ u16 mSendChunkSize;
    /* 612 */ u8 pad_612[2];
} WiFiMessageLayer;

// Local of func_ov000_021a31e8, filled by a copy of eight bytes.
typedef struct Unk021a31e8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
} Unk021a31e8;

// Points at WiFiConnection.mMessageLayer: set by InitWiFiMessageLayer, set to NULL by func_ov000_021a2fec
// (ReleaseWiFiConnection).
extern WiFiMessageLayer *gWiFiMessageLayer;

BOOL func_ov000_021a2ccc(void);
s32 func_ov000_021a2d18(u32 a);
void func_ov000_021a2d38(u32 a, void *b, s32 c);
void func_ov000_021a2d68(int a, void *b, s32 c);
void func_ov000_021a2dfc(int a, void *b, s32 c);
void func_ov000_021a2e7c(Unk0219887c *a, const void *b, int c);
void func_ov000_021a2eec(Unk0219887c *a, void *b, s32 c);
void func_ov000_021a2f98(u32 a, void *b, u32 c, u32 d);
u8 func_ov000_021a2fb4(int a);
u8 func_ov000_021a2fc8(int a);
WiFiPeerMessage *func_ov000_021a2fdc(int a);
void func_ov000_021a2fec(void);
void func_ov000_021a2ff8(int a);
void UpdateWiFiMessageLayer(void);
void func_ov000_021a314c(Unk0219887c *a, u32 b);
void func_ov000_021a317c(Unk0219887c *a, void *b, s32 c, u32 d);
void InitWiFiMessageLayer(WiFiMessageLayer *state);
s32 func_ov000_021a31d4(s32 value);
u16 func_ov000_021a31e8(const void *a);
void func_ov000_021a321c(Unk021a31e8 *a, u16 b, u32 c);
void func_ov000_021a323c(void (*arg0)(u32, void *, u32));
void func_ov000_021a3250(u32 (*arg0)(void));
