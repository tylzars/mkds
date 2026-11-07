#pragma once

#include "types.h"
#include "code_0201c528.h"

typedef struct Vec3s16 Vec3s16;
typedef struct Kart Kart;

// 0x88 bytes. The per-Kart set of effect objects that play while the Kart holds a turn (Kart.mTurnDirection is not 0):
// a turn start group, a level 2 group and a level 3 group (started when Kart.mUnk_2fc becomes 2 and when it is 3) and a
// level 4 group (requested at the step from 3 to 4), their counters, ids and the functions that start, stop, hide, show
// and place them; two variants of the function set are installed by InitKartTurnEffects.
typedef struct KartTurnEffects {
    // The two effect objects of the turn start group, one per side, started by StartKartTurnStartEffects and moved by
    // AdvanceKartTurnStartEffects (the level 2 advance also switches their emission); NULL when the group is not
    // present.
    /* 00 */ Unk0201ca6c *mTurnStartEffects[2];
    // The two effect objects, one per side, started when Kart.mUnk_2fc becomes 2 (id 0x7e); released when mLevel2Frames
    // passes 8; NULL when the group is not present.
    /* 08 */ Unk0201ca6c *mLevel2Effects[2];
    // First effect object per side of the level 4 group, started by the restart in AdvanceKartLevel4Effects after the
    // request made when Kart.mUnk_2fc is 3 (so Kart.mUnk_2fc is 4 from then on); NULL when the group is not present.
    /* 10 */ Unk0201ca6c *mLevel4FirstEffects[2];
    // Second effect object per side of the level 4 group; only started by StartKartLevel4EffectsWithSecond, NULL for
    // the other variant.
    /* 18 */ Unk0201ca6c *mLevel4SecondEffects[2];
    // First of the two effect objects per side started when Kart.mUnk_2fc is 3; released when mLevel3Frames passes 10.
    /* 20 */ Unk0201ca6c *mLevel3FirstEffects[2];
    // Second of the two effect objects per side of the level 3 group.
    /* 28 */ Unk0201ca6c *mLevel3SecondEffects[2];
    // Calls of AdvanceKartLevel4Effects since mLevel4StopRequested became TRUE; the group is reset when it passes 10.
    /* 30 */ s16 mLevel4StopFrames;
    // TRUE from StopKartTurnEffects, when the level 4 group was present, until the next reset; AdvanceKartLevel4Effects
    // counts mLevel4StopFrames while it is TRUE and resets the group after 10.
    /* 34 */ BOOL mLevel4StopRequested;
    // 1 while the level 4 group exists (also while mLevel4StopRequested is TRUE).
    /* 38 */ s32 mLevel4Present;
    // 1 while the turn start group exists (mTurnStartEffects valid), else 0.
    /* 3c */ u32 mTurnStartPresent;
    // 1 while the level 3 group exists.
    /* 40 */ s32 mLevel3Present;
    // TRUE while the level 2 group exists.
    /* 44 */ BOOL mLevel2Present;
    // Calls of AdvanceKartLevel3Effects since the level 3 group started; the group is released when it passes 10.
    /* 48 */ s16 mLevel3Frames;
    // Calls of AdvanceKartLevel2Effects since the level 2 group started; the group is released when it passes 8.
    /* 4a */ s16 mLevel2Frames;
    // Id of the effect started for each side of the turn start group: 0x14 for the Kart of the selected entry and for
    // every Kart in time trial or when RaceSetup.mUnk_00c is 5, 0x15 for the others.
    /* 4c */ s32 mTurnStartEffectId;
    // Effect id of mLevel4FirstEffects: 0x11 for the Kart of the selected entry and for every Kart in time trial or
    // when RaceSetup.mUnk_00c is 5, 0x13 for the others.
    /* 50 */ s32 mLevel4FirstEffectId;
    // Effect id of mLevel4SecondEffects: 0x12 for the Karts that use StartKartLevel4EffectsWithSecond, -1 for the
    // others, which never start it.
    /* 54 */ s32 mLevel4SecondEffectId;
    // Effect id of mLevel3FirstEffects (0x16 for every Kart).
    /* 58 */ s32 mLevel3FirstEffectId;
    // Effect id of mLevel3SecondEffects (0x17 for every Kart).
    /* 5c */ s32 mLevel3SecondEffectId;
    // Index of the Kart this record belongs to (the record number); written at init, never read.
    /* 60 */ u16 mIndex;
    // Calls of AdvanceKartLevel4Effects with Kart.mUnk_44 bit 8 set since the restart was requested; the group is
    // restarted when it passes 10.
    /* 62 */ u16 mLevel4RestartFrames;
    // 1 after RequestKartLevel4EffectsRestart (made when Kart.mUnk_2fc is 3), 0 after every reset;
    // AdvanceKartLevel4Effects then restarts the group once mLevel4RestartFrames passes 10.
    /* 64 */ s32 mLevel4RestartRequested;
    // The start function of the level 4 group; set per Kart by InitKartTurnEffects (the variant with the second object
    // or the one with the first only).
    /* 68 */ void (*mStartLevel4Effects)(struct KartTurnEffects *);
    // Stops the level 4 objects emitting (sets the library's emit-stop bit of each); set per Kart by
    // InitKartTurnEffects (the variant with the second object or the one with the first only).
    /* 6c */ void (*mStopLevel4Emission)(struct KartTurnEffects *);
    // Lets the level 4 objects emit again (clears the library's emit-stop bit of each); set per Kart by
    // InitKartTurnEffects (the variant with the second object or the one with the first only).
    /* 70 */ void (*mStartLevel4Emission)(struct KartTurnEffects *);
    // Releases the level 4 objects at once and clears the pointers; set per Kart by InitKartTurnEffects (the variant
    // with the second object or the one with the first only).
    /* 74 */ void (*mReleaseLevel4Effects)(struct KartTurnEffects *);
    // Begins ending the level 4 group when the turn ends: the variant with the second object only stops emission, the
    // other releases the group at once; set per Kart by InitKartTurnEffects (the variant with the second object or the
    // one with the first only).
    /* 78 */ void (*mStopLevel4Effects)(struct KartTurnEffects *);
    // Hides every present effect object of the Kart set (sets the library's skip-drawing bit); set per Kart by
    // InitKartTurnEffects (the variant with the second object or the one with the first only).
    /* 7c */ void (*mHideEffects)(struct KartTurnEffects *);
    // Shows every present effect object of the Kart set again (clears the library's skip-drawing bit); set per Kart by
    // InitKartTurnEffects (the variant with the second object or the one with the first only).
    /* 80 */ void (*mShowEffects)(struct KartTurnEffects *);
    // Places the level 4 objects: sets their direction and position from the two side arrays of KartEffects; set per
    // Kart by InitKartTurnEffects (the variant with the second object or the one with the first only).
    /* 84 */ void (*mPlaceLevel4Effects)(struct KartTurnEffects *, Vec3s16 *, Vec3 *);
} KartTurnEffects;

extern const Vec3 data_02155fcc;

// Ends the turn effects of this Kart: when the level 4 group is present calls mStopLevel4Effects and sets
// mLevel4StopRequested, otherwise clears it; clears both restart members; sets the remove bit of the turn start objects
// and forgets them. The level 2 and level 3 groups end by their own counters.
void StopKartTurnEffects(KartTurnEffects *p);
// The KartTurnEffects record of the Kart with that index; changes nothing.
KartTurnEffects *GetKartTurnEffects(int v1);
// Releases every effect object of the Kart set at once (turn start, level 4, level 3 and level 2 groups) and clears the
// flags and counters.
void ReleaseKartTurnEffects(KartTurnEffects *p);
// Counts mLevel2Frames and releases the level 2 objects when it passes 8, otherwise places them from the side arrays;
// while the group is present it also stops the turn start objects emitting, and clears that again when it ends.
void AdvanceKartLevel2Effects(KartTurnEffects *p, Vec3s16 *a, Vec3 *b);
// Starts the two level 2 objects (id 0x7e), releasing earlier ones; does nothing when v1 is 0.
void StartKartLevel2Effects(KartTurnEffects *p, int v1);
// Counts mLevel3Frames and releases both level 3 sets when it passes 10, otherwise places all objects from the side
// arrays; does nothing when the group is not present.
void AdvanceKartLevel3Effects(KartTurnEffects *p, Vec3s16 *a, Vec3 *b);
// Starts the level 3 objects, two per side, releasing earlier ones; does nothing when v1 is 0.
void StartKartLevel3Effects(KartTurnEffects *p, int v1);
// Each call: counts mLevel4StopFrames while a stop is requested and resets the group when it passes 10; restarts the
// group after a restart request once Kart.mUnk_44 bit 8 has been set for more than 10 calls; while the group is
// present, places the objects from the side arrays and switches their emission with Kart.mUnk_44 bit 0x10.
void AdvanceKartLevel4Effects(KartTurnEffects *p, Kart *q);
// Releases the level 4 group through mReleaseLevel4Effects when present and clears mLevel4Present, mLevel4StopFrames,
// mLevel4StopRequested and both restart members.
void ResetKartLevel4Effects(KartTurnEffects *p);
void ShowKartEffectsFirstOnly(KartTurnEffects *p);
void ShowKartEffectsWithSecond(KartTurnEffects *p);
void ShowKartNonLevel4Effects(KartTurnEffects *p);
void HideKartEffectsFirstOnly(KartTurnEffects *p);
void HideKartEffectsWithSecond(KartTurnEffects *p);
void HideKartNonLevel4Effects(KartTurnEffects *p);
// Sets the direction and the position of the first level 4 object of each side from the side arrays.
void PlaceKartLevel4EffectsFirstOnly(KartTurnEffects *p, Vec3s16 *a, Vec3 *b);
// Sets the direction and the position of both level 4 objects of each side from the side arrays (the position is the
// side position plus the object origin).
void PlaceKartLevel4EffectsWithSecond(KartTurnEffects *p, Vec3s16 *a, Vec3 *b);
void StopKartLevel4EffectsFirstOnly(KartTurnEffects *p);
void StopKartLevel4EffectsWithSecond(KartTurnEffects *p);
// Releases the first level 4 object of each side and clears the pointers.
void ReleaseKartLevel4EffectsFirstOnly(KartTurnEffects *p);
// Releases the first and second level 4 objects of each side and clears the pointers.
void ReleaseKartLevel4EffectsWithSecond(KartTurnEffects *p);
void StartKartLevel4EmissionFirstOnly(KartTurnEffects *p);
void StartKartLevel4EmissionWithSecond(KartTurnEffects *p);
void StopKartLevel4EmissionFirstOnly(KartTurnEffects *p);
void StopKartLevel4EmissionWithSecond(KartTurnEffects *p);
// Starts only the first level 4 object on each side.
void StartKartLevel4EffectsFirstOnly(KartTurnEffects *p);
// Starts the first and the second level 4 object on each side.
void StartKartLevel4EffectsWithSecond(KartTurnEffects *p);
// Each call, for each side: sets the object velocity from Kart.mEffectVelocity, its position from mSidePositions minus
// that velocity, and its emit-stop bit from Kart.mUnk_44 bit 0x10; does nothing when the group is not present.
void AdvanceKartTurnStartEffects(KartTurnEffects *p, Kart *q);
// Sets the library's remove bit of both turn start objects and forgets them; does nothing when the group is not
// present.
void StopKartTurnStartEffects(KartTurnEffects *p);
// Starts the two effect objects of the turn start group, replacing any earlier ones.
void StartKartTurnStartEffects(KartTurnEffects *p);
// Allocates one KartTurnEffects per counted Kart in the heap a, installs the function set with the second level 4
// object for the selected entry, in time trial and when RaceSetup.mUnk_00c is 5 and the set with the first object
// only for the others, and clears every pointer and counter.
void InitKartTurnEffects(void *a);
