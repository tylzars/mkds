#include "code_02142eac.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "wm_system.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "Main/Unknown/unk_0216f000.h"

// Starts DCF reception into recvBuf (command 17). Needs state 8 and DCF not running; recvBufSize must be at least 0x10.
s32 WM_StartDCF(Unk021425e8Func callback, void *recvBuf, u16 recvBufSize) {
    Unk02142aa8 *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(1, 8);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mDcfFlag, 4);
    if (work->mStatusArea->mDcfFlag == 1) {
        return 3;
    }
    if (recvBufSize < 0x10) {
        return 6;
    }
    if (recvBuf == 0) {
        return 6;
    }
    DC_StoreRange(recvBuf, recvBufSize);
    WMi_SetCallbackTable(0x11, callback);
    result = WMi_SendCommand(0x11, 2, recvBuf, recvBufSize);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sends sendDataSize bytes (at most 0x5e4) of sendData to the station destAdr (command 18). Needs state 11 and DCF
// running.
s32 WM_SetDCFData(Unk021425e8Func callback, const void *destAdr, void *sendData, u16 sendDataSize) {
    Unk02142aa8 *work;
    s32 result;
    u32 address[2];

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(1, 11);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mDcfFlag, 4);
    if (work->mStatusArea->mDcfFlag == 0) {
        return 3;
    }
    if (sendDataSize > 0x5e4) {
        return 6;
    }
    DC_StoreRange(sendData, sendDataSize);
    WMi_SetCallbackTable(0x12, callback);
    MI_CpuCopy8(destAdr, address, 6);
    result = WMi_SendCommand(0x12, 4, address[0], address[1], sendData, sendDataSize);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Ends DCF (command 19). Needs state 11 and DCF running.
s32 WM_EndDCF(Unk021425e8Func callback) {
    Unk02142aa8 *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(1, 11);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mDcfFlag, 4);
    if (work->mStatusArea->mDcfFlag == 0) {
        return 3;
    }
    WMi_SetCallbackTable(0x13, callback);
    result = WMi_SendCommand(0x13, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Starts the MP protocol (command 14). Needs state 7 or 8 and MP not running; the buffer sizes are checked against
// WM_GetMPReceiveBufferSize and WM_GetMPSendBufferSize.
s32 WM_StartMPEx(Unk021425e8Func callback, void *recvBuf, u16 recvBufSize, void *sendBuf, u16 sendBufSize, u16 mpFreq,
                 u16 defaultRetryCount, BOOL minPollBmpMode, BOOL singlePacketMode, BOOL fixFreqMode,
                 BOOL ignoreFatalError) {
    Unk02142aa8 *work;
    s32 result;
    s32 sendSize;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(2, 7, 8);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mOwnMemberIndex, 2);
    DC_InvalidateRange(&work->mStatusArea->mPwrMgtMode, 2);
    if (work->mStatusArea->mOwnMemberIndex != 0) {
        if (work->mStatusArea->mPwrMgtMode != 1) {
            return 3;
        }
    }
    DC_InvalidateRange(&work->mStatusArea->mMpFlag, 4);
    if (work->mStatusArea->mMpFlag == 1) {
        return 3;
    }
    if (recvBufSize < WM_GetMPReceiveBufferSize()) {
        return 6;
    }
    if ((recvBufSize & 0x3f) != 0) {
        return 6;
    }
    sendSize = sendBufSize;
    if (sendSize < WM_GetMPSendBufferSize()) {
        return 6;
    }
    if ((sendSize & 0x1f) != 0) {
        return 6;
    }
    WMi_SetCallbackTable(0xe, callback);
    result = WMi_SendCommand(0xe, 10, recvBuf, (u32) recvBufSize >> 1, sendBuf, sendBufSize, mpFreq, defaultRetryCount,
                             minPollBmpMode, singlePacketMode, fixFreqMode, ignoreFatalError);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sets the MP frequency (command 35). Needs state 9.
s32 WM_SetMPFrequency(Unk021425e8Func callback, u32 mpFreq) {
    s32 result;

    WMi_GetSystemWork();
    result = WMi_CheckStateEx(1, 9);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(0x23, callback);
    result = WMi_SendCommand(0x23, 1, mpFreq);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Queues sendDataSize bytes of sendData for the stations in destBitmap on port with priority prio (command 15).
// Needs state 9 or 10; returns 7 when a parent has no child connected. callback is called with arg when it is sent.
s32 WM_SetMPDataToPortEx(UnkFunc *callback, void *arg, void *sendData, s32 sendDataSize, u16 destBitmap, u16 port,
                         u16 prio) {
    u16 limit;
    u32 children;
    Unk02142988 *status;
    s32 result;
    s32 parent;

    children = 1;
    status = WMi_GetSystemWork()->mStatusArea;
    result = WMi_CheckStateEx(2, 9, 10);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&status->mMpMaxSendSize, 2);
    limit = status->mMpMaxSendSize;
    DC_InvalidateRange(&status->mOwnMemberIndex, 2);
    parent = status->mOwnMemberIndex == 0 ? children : 0;
    if (parent == 1) {
        DC_InvalidateRange(&status->mConnectedChildren, 2);
        children = status->mConnectedChildren;
        DC_InvalidateRange(&status->mMpReadyBitmap, 2);
    }
    if (sendData == 0) {
        return 6;
    }
    if (children == 0) {
        return 7;
    }
    DC_InvalidateRange(&status->mMpSendBuf, 2);
    if (sendData == status->mMpSendBuf) {
        return 6;
    }
    if (sendDataSize + (parent != 0 ? 4 : 2) > limit) {
        return 6;
    }
    if (sendDataSize == 0) {
        return 6;
    }
    DC_StoreRange(sendData, sendDataSize);
    result = WMi_SendCommand(0xf, 7, sendData, sendDataSize, destBitmap, port, prio, callback, arg);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Ends the MP protocol (command 16). Needs state 9 or 10 and MP running.
s32 WM_EndMP(Unk021425e8Func callback) {
    Unk02142aa8 *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(2, 9, 10);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpFlag, 4);
    if (work->mStatusArea->mMpFlag == 0) {
        return 3;
    }
    WMi_SetCallbackTable(0x10, callback);
    result = WMi_SendCommand(0x10, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Enables the wireless hardware (command 3). Needs state 0.
s32 WM_Enable(Unk021425e8Func callback) {
    Unk02142aa8 *work;
    s32 result;

    result = WMi_CheckStateEx(1, 0);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(3, callback);
    work = WMi_GetSystemWork();
    result = WMi_SendCommand(3, 3, work->mWM7, work->mStatusArea, work->mMessageArea);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Disables the wireless hardware (command 4). Needs state 1.
s32 WM_Disable(Unk021425e8Func callback) {
    s32 result;

    result = WMi_CheckStateEx(1, 1);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(4, callback);
    result = WMi_SendCommand(4, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Powers the wireless hardware on (command 5). Needs state 1.
s32 WM_PowerOn(Unk021425e8Func callback) {
    s32 result;

    result = WMi_CheckStateEx(1, 1);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(5, callback);
    result = WMi_SendCommand(5, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Powers the wireless hardware off (command 6). Needs state 2.
s32 WM_PowerOff(Unk021425e8Func callback) {
    s32 result;

    result = WMi_CheckStateEx(1, 2);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(6, callback);
    result = WMi_SendCommand(6, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sets up the system buffer with WM_Init, then starts the wireless hardware (command 0).
s32 WM_Initialize(void *wmSysBuf, Unk021425e8Func callback, u16 dmaNo) {
    Unk02142aa8 *work;
    s32 result;

    result = WM_Init(wmSysBuf, dmaNo);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(0, callback);
    work = WMi_GetSystemWork();
    result = WMi_SendCommand(0, 3, work->mWM7, work->mStatusArea, work->mMessageArea);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Resets the wireless state back to idle (command 1). Needs state 2 or later.
s32 WM_Reset(Unk021425e8Func callback) {
    s32 result;

    result = WMi_CheckIdle();
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(1, callback);
    result = WMi_SendCommand(1, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Shuts the wireless hardware down (command 2). Needs state 2.
s32 WM_End(Unk021425e8Func callback) {
    s32 result;

    result = WMi_CheckStateEx(1, 2);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(2, callback);
    result = WMi_SendCommand(2, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sets the parent parameters (command 7). Needs state 2; game info and beacon data sizes are limited to 0x200 bytes.
s32 WM_SetParentParameter(Unk021425e8Func callback, Unk02143c30 *pparaBuf) {
    s32 result;

    result = WMi_CheckStateEx(1, 2);
    if (result != 0) {
        return result;
    }
    if (pparaBuf == 0) {
        return 6;
    }
    if (pparaBuf->mUnk_04 != 0) {
        if (pparaBuf->mUnk_00 == 0) {
            return 6;
        }
    }
    if (pparaBuf->mUnk_34 + (pparaBuf->mUnk_14 != 0 ? 0x2a : 0) > 0x200 ||
        pparaBuf->mUnk_36 + (pparaBuf->mUnk_14 != 0 ? 6 : 0) > 0x200) {
        return 6;
    }
    WmCheckParentParameter(pparaBuf);
    WMi_SetCallbackTable(7, callback);
    DC_StoreRange(pparaBuf, 0x40);
    if (pparaBuf->mUnk_04 != 0) {
        DC_StoreRange(pparaBuf->mUnk_00, pparaBuf->mUnk_04);
    }
    result = WMi_SendCommand(7, 1, pparaBuf);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Returns 1 when the game info length, beacon period and channel of param are in range, otherwise 0.
u32 WmCheckParentParameter(const Unk02143c30 *param) {
    if (param->mUnk_04 > 0x70) {
        return 0;
    }
    if (param->mUnk_18 < 10 || param->mUnk_18 > 0x3e8) {
        return 0;
    }
    if (param->mUnk_32 < 1 || param->mUnk_32 > 0xe) {
        return 0;
    }
    return 1;
}

// Starts the parent (command 8). Needs state 2.
s32 WMi_StartParentEx(Unk021425e8Func callback, BOOL powerSave) {
    s32 result;

    result = WMi_CheckStateEx(1, 2);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(8, callback);
    result = WMi_SendCommand(8, 1, powerSave);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Starts the parent with power save on.
s32 WM_StartParent(Unk021425e8Func callback) {
    return WMi_StartParentEx(callback, 1);
}

// Ends the parent (command 9). Needs state 7.
s32 WM_EndParent(Unk021425e8Func callback) {
    s32 result;

    result = WMi_CheckStateEx(1, 7);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(9, callback);
    result = WMi_SendCommand(9, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Starts a scan (command 10). Needs state 2, 3 or 5; the channel must be 1 to 14.
s32 WM_StartScan(Unk021425e8Func callback, Unk02143a78 *param) {
    Unk02143a78_0c *request;
    s32 result;

    result = WMi_CheckStateEx(3, 2, 3, 5);
    if (result != 0) {
        return result;
    }
    if (param == 0) {
        return 6;
    }
    if (param->mUnk_00 == 0) {
        return 6;
    }
    if (param->mUnk_04 < 1 || param->mUnk_04 > 0xe) {
        return 6;
    }
    WMi_SetCallbackTable(0xa, callback);
    request = (Unk02143a78_0c *) WMi_GetSystemWork()->mRequestArea;
    request->mApiid = 0xa;
    request->mChannel = param->mUnk_04;
    request->mScanBuf = param->mUnk_00;
    request->mMaxChannelTime = param->mUnk_06;
    request->mBssid[0] = param->mUnk_08[0];
    request->mBssid[1] = param->mUnk_08[1];
    request->mBssid[2] = param->mUnk_08[2];
    request->mBssid[3] = param->mUnk_08[3];
    request->mBssid[4] = param->mUnk_08[4];
    request->mBssid[5] = param->mUnk_08[5];
    result = WMi_SendCommand(0xa, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Starts a scan with a scan type and SSID (command 38). Needs state 2, 3 or 5.
s32 WM_StartScanEx(Unk021425e8Func callback, Unk021438f0 *param) {
    Unk021438f0_0c *request;
    s32 result;
    u16 scanType;

    result = WMi_CheckStateEx(3, 2, 3, 5);
    if (result != 0) {
        return result;
    }
    if (param == 0) {
        return 6;
    }
    if (param->mUnk_00 == 0) {
        return 6;
    }
    if (param->mUnk_04 > 0x400) {
        return 6;
    }
    if (param->mUnk_12 > 0x20) {
        return 6;
    }
    scanType = param->mUnk_10;
    if (scanType != 0 && scanType != 1 && scanType != 2 && scanType != 3) {
        return 6;
    }
    if ((u16) (scanType + 0xfffe) <= 1) {
        if (param->mUnk_34 > 0x20) {
            return 6;
        }
    }
    WMi_SetCallbackTable(0x26, callback);
    request = (Unk021438f0_0c *) WMi_GetSystemWork()->mRequestArea;
    request->mApiid = 0x26;
    request->mChannelList = param->mUnk_06;
    request->mScanBuf = param->mUnk_00;
    request->mScanBufSize = param->mUnk_04;
    request->mMaxChannelTime = param->mUnk_08;
    MI_CpuCopy8(param->mUnk_0a, request->mBssid, 6);
    request->mScanType = param->mUnk_10;
    request->mSsidMatchLength = param->mUnk_34;
    request->mSsidLength = param->mUnk_12;
    MI_CpuCopy8(param->mUnk_14, request->mSsid, 0x20);
    result = WMi_SendCommand(0x26, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Ends the scan (command 11). Needs state 5.
s32 WM_EndScan(Unk021425e8Func callback) {
    s32 result;

    result = WMi_CheckStateEx(1, 5);
    if (result != 0) {
        return result;
    }
    WMi_SetCallbackTable(0xb, callback);
    result = WMi_SendCommand(0xb, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Connects to the parent described by pInfo (command 12). Needs state 2.
s32 WM_StartConnectEx(Unk021425e8Func callback, u16 *pInfo, void *ssid, BOOL powerSave, u16 authMode) {
    Unk021437d8 *request;
    s32 result;

    result = WMi_CheckStateEx(1, 2);
    if (result != 0) {
        return result;
    }
    if (pInfo == 0) {
        return 6;
    }
    DC_StoreRange(pInfo, pInfo[0] * 2);
    WMi_SetCallbackTable(0xc, callback);
    request = (Unk021437d8 *) WMi_GetSystemWork()->mRequestArea;
    request->mApiid = 0xc;
    request->mPInfo = pInfo;
    if (ssid != 0) {
        MI_CpuCopy8(ssid, request->mSsid, 0x18);
    } else {
        MI_CpuFill8(request->mSsid, 0, 0x18);
    }
    request->mPowerSave = powerSave;
    request->mAuthMode = authMode;
    result = WMi_SendCommand(0xc, 0);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Disconnects the station aid (command 13): a child from a parent, or the parent itself when aid is 0 on a child.
s32 WM_Disconnect(Unk021425e8Func callback, u32 aid) {
    Unk02142aa8 *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(5, 7, 9, 8, 10, 11);
    if (result != 0) {
        return result;
    }
    if (work->mStatusArea->mState == 7 || work->mStatusArea->mState == 9) {
        if (aid < 1 || aid > 0xf) {
            return 6;
        }
        DC_InvalidateRange(&work->mStatusArea->mConnectedChildren, 2);
        if ((work->mStatusArea->mConnectedChildren & (1 << aid)) == 0) {
            return 7;
        }
    } else if (aid != 0) {
        return 6;
    }
    WMi_SetCallbackTable(0xd, callback);
    result = WMi_SendCommand(0xd, 1, 1 << aid);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Disconnects the children in aidBitmap (command 13). Needs state 7 or 9; returns 7 when none of them is connected.
s32 WM_DisconnectChildren(Unk021425e8Func callback, u32 aidBitmap) {
    Unk02142aa8 *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(2, 7, 9);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&work->mStatusArea->mConnectedChildren, 2);
    if ((work->mStatusArea->mConnectedChildren & aidBitmap & 0xfffe) == 0) {
        return 7;
    }
    WMi_SetCallbackTable(0xd, callback);
    result = WMi_SendCommand(0xd, 1, aidBitmap);
    if (result == 0) {
        return 2;
    }
    return result;
}

// Sets the callback for indications.
s32 WM_SetIndCallback(Unk021425e8Func callback) {
    u32 enabled;
    s32 result;

    enabled = OS_DisableInterrupts();
    result = WMi_CheckInitialized();
    if (result != 0) {
        OS_RestoreInterrupts(enabled);
        return result;
    }
    WMi_GetSystemWork()->mIndicationCallback = callback;
    OS_RestoreInterrupts(enabled);
    return 0;
}

// Sets the callback and argument for data received on port (stored in Unk02142aa8.mPortCallbacks and
// Unk02142aa8.mPortCallbackArgs).
s32 WM_SetPortCallback(u16 port, UnkFunc *callback, void *arg) {
    u32 enabled;
    s32 result;
    Unk02142aa8 *work;

    enabled = OS_DisableInterrupts();
    result = WMi_CheckInitialized();
    if (result != 0) {
        OS_RestoreInterrupts(enabled);
        return result;
    }
    work = WMi_GetSystemWork();
    work->mPortCallbacks[port] = callback;
    work->mPortCallbackArgs[port] = arg;
    OS_RestoreInterrupts(enabled);
    return 0;
}

// Copies the status area into statusBuf.
s32 WM_ReadStatus(void *statusBuf) {
    Unk02142aa8 *work;
    s32 result;

    work = WMi_GetSystemWork();
    result = WMi_CheckInitialized();
    if (result != 0) {
        return result;
    }
    if (statusBuf == 0) {
        return 6;
    }
    DC_InvalidateRange(work->mStatusArea, 0x7bc);
    MIi_CpuCopyFast(work->mStatusArea, statusBuf, 0x7bc);
    return 0;
}

// Returns the send buffer size WM_StartMPEx needs, or 0 when the state does not allow it.
s32 WM_GetMPSendBufferSize(void) {
    Unk02142aa8 *work;

    work = WMi_GetSystemWork();
    if (WMi_CheckStateEx(2, 7, 8) != 0) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpFlag, 4);
    if (work->mStatusArea->mMpFlag == 1) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpMaxSendSize, 4);
    return (work->mStatusArea->mMpMaxSendSize + 0x1f) & ~0x1f;
}

// Returns the receive buffer size WM_StartMPEx needs, or 0 when the state does not allow it.
s32 WM_GetMPReceiveBufferSize(void) {
    Unk02142aa8 *work;
    s32 isHost;
    u16 maxRecvSize;

    work = WMi_GetSystemWork();
    if (WMi_CheckStateEx(2, 7, 8) != 0) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpFlag, 4);
    if (work->mStatusArea->mMpFlag == 1) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mOwnMemberIndex, 2);
    if (work->mStatusArea->mOwnMemberIndex == 0) {
        isHost = 1;
    } else {
        isHost = 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mMpMaxRecvSize, 2);
    maxRecvSize = work->mStatusArea->mMpMaxRecvSize;
    if (isHost != 1) {
        return ((maxRecvSize + 0x51) & ~0x1f) << 1;
    }
    DC_InvalidateRange(&work->mStatusArea->mUnk_0f4, 2);
    return (((maxRecvSize + 0xc) * work->mStatusArea->mUnk_0f4 + 0x29) & ~0x1f) << 1;
}

// Returns the record of station aid in the MP receive data header, or NULL when there is none.
void *WM_ReadMPData(const Unk021432ac *header, u16 aid) {
    Unk02142aa8 *work;
    u32 records[16];
    s32 i;

    work = WMi_GetSystemWork();
    if (WMi_CheckInitialized() != 0) {
        return 0;
    }
    if (aid < 1 || aid > 0xf) {
        return 0;
    }
    DC_InvalidateRange(&work->mStatusArea->mConnectedChildren, 2);
    if ((work->mStatusArea->mConnectedChildren & (1 << aid)) == 0) {
        return 0;
    }
    if (header->mUnk_04 == 0) {
        return 0;
    }
    records[0] = (u32) header->mUnk_0a;
    i = 0;
    do {
        if (aid == *(u16 *) (records[i] + 4)) {
            return (void *) records[i];
        }
        i++;
        records[i] = header->mUnk_06 + records[i - 1];
    } while (i < header->mUnk_04);
    return 0;
}

// Returns the bitmap of allowed channels, or 0x8000 when the library is not set up.
u16 WM_GetAllowedChannel(void) {
    if (WMi_CheckInitialized() != 0) {
        return 0x8000;
    }
    return *(u16 *) 0x27ffcfa;
}

// Returns the signal strength of the link, 0 when there is no link.
u16 WM_GetLinkLevel(void) {
    Unk02142aa8 *work;

    work = WMi_GetSystemWork();
    if (WMi_CheckInitialized() != 0) {
        return 0;
    }
    DC_InvalidateRange(work->mStatusArea, 2);
    switch (work->mStatusArea->mState) {
        case 9:
            DC_InvalidateRange(&work->mStatusArea->mConnectedChildren, 2);
            if (work->mStatusArea->mConnectedChildren == 0) {
                return 0;
            }
        case 10:
        case 11:
            DC_InvalidateRange(&work->mStatusArea->mLinkLevel, 2);
            return work->mStatusArea->mLinkLevel;
        default:
            return 0;
    }
}

// Returns a beacon period from 200 that depends on the MAC address and the system work value at 0x027ffc3c.
u16 WM_GetDispersionBeaconPeriod(void) {
    u8 address[6];
    s32 i;
    u16 sum;

    OS_GetMacAddress(address);
    for (i = 0, sum = 0; i < 6; i++) {
        sum = sum + address[i];
    }
    sum = sum + *(u32 *) 0x27ffc3c;
    sum = sum * 7;
    return sum % 20 + 200;
}

// Returns a scan period from 30 that depends on the MAC address and the system work value at 0x027ffc3c.
u16 WM_GetDispersionScanPeriod(void) {
    u8 address[6];
    s32 i;
    u16 sum;

    OS_GetMacAddress(address);
    for (i = 0, sum = 0; i < 6; i++) {
        sum = sum + address[i];
    }
    sum = sum + *(u32 *) 0x27ffc3c;
    sum = sum * 13;
    return sum % 10 + 30;
}

// Collects the extra information elements that follow the game info of a scanned parent.
WMOtherElements WM_GetOtherElements(const u16 *bssDesc) {
    WMOtherElements elements;
    const u8 *body;
    s32 i;
    u8 bodyLength;
    u8 total;
    u8 size;

    if (bssDesc[0x1e] != 0) {
        elements.mUnk_00 = 0;
        return elements;
    }
    elements.mUnk_00 = bssDesc[0x1f];
    if (elements.mUnk_00 == 0) {
        return elements;
    }
    if (elements.mUnk_00 > 0x10) {
        elements.mUnk_00 = 0x10;
    }
    body = (const u8 *) bssDesc + 0x40;
    bodyLength = bssDesc[0] * 2 - 0x40;
    total = 0;
    for (i = 0; i < elements.mUnk_00; i++) {
        elements.mUnk_04[i].mUnk_00 = body[0];
        elements.mUnk_04[i].mUnk_01 = body[1];
        elements.mUnk_04[i].mUnk_04 = body + 2;
        size = elements.mUnk_04[i].mUnk_01 + 2;
        total = total + size;
        if (total > bodyLength) {
            elements.mUnk_00 = 0;
            return elements;
        }
        body = body + size;
    }
    return elements;
}

// Returns the next TGID, starting from the RTC time the first time.
u16 WM_GetNextTgid(void) {
    RTCTime time;

    if (data_0216f06c == 0x10000) {
        RTC_Init();
        if (RTC_GetTime(&time) == 0) {
            data_0216f06c = (u16) (time.mSecond + (time.mMinute << 8));
        }
    }
    data_0216f06c = (u16) (data_0216f06c + 1);
    return data_0216f06c;
}
