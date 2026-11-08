#pragma once

#include "types.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_0202a340.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02174000.h"

typedef struct SceneNumbersView SceneNumbersView;

// Object behind gResultsGp, allocated by InitResultsGp.
typedef struct ResultsGp {
    /* 00 */ CellFileSet mCellFileSets[2];
    /* 38 */ void *mOamLists[2];
    /* 40 */ s32 mCupIndex;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mCupRankIndex;
    /* 4c */ Bmg *mCommonMessages;
    /* 50 */ Bmg *mSecretMessages;
    /* 54 */ s32 mState;
    /* 58 */ u32 mSecretMessageMask;
    /* 5c */ s32 mState0Frames;
} ResultsGp;

extern ResultsGp *gResultsGp;

extern const char data_usa_02162138[];
extern const char gSecretBmgName[];
extern const char gResultsGpMBNcgrName[];
extern const char gResultsGpMBNclrName[];
extern const char gResultsGpM1NscrName[];
extern const char gResultsGpM2NscrName[];
extern const char gResultsGpMNcgrName[];
extern const char gResultsGpMNcerName[];
extern const char gResultsGpMONclrName[];
extern const char gResultsGpMBnclName[];
extern const char gResultsGpMBnllName[];
extern const char gResultsGpSBNcgrName[];
extern const char gResultsGpSBNclrName[];
extern const char gResultsGpSNscrName[];
extern const char gResultsGpSNcgrName[];
extern const char gResultsGpSNcerName[];
extern const char gResultsGpSONclrName[];
extern const char gResultsGpSBnclName[];
extern const char gResultsGpSBnllName[];
extern const char gCupNameLeftNcgrName[];
extern const char gCupNameLeftNcerName[];
extern const char gCupNameLeftBnclName[];
extern u16 gEngineMessageIndexTable[];
extern u16 data_usa_02153868[];
extern u16 gCupRankCellIndexTable[];
extern u16 data_usa_02153888[];
extern u32 data_usa_02153898[][4];
extern Unk02153918 data_usa_02153918[];

void AdvanceResultsGp(SceneNumbersView *sceneNumbers);
void InitResultsGp(void *heap, void *firstOamList, void *secondOamList);
