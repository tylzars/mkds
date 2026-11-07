#include "code_0214a748.h"
#include "code_0214a54c.h"
#include "code_0214a5f0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"
#include "registers.h"

// Builds a perspective projection matrix from the six edge values, scaled by scaleW (0x1000 = 1.0). With draw
// nonzero it sets the projection matrix mode and loads the 16 words with the 4x4 load command; with mtx not null it
// stores them there.
void G3i_FrustumW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                   Unk0214ad4c *mtx) {
    s64 invWidth;
    s64 invHeight;
    s64 invDepth;
    s32 dblNear;
    s32 m00;
    s32 m11;
    s32 m22;
    s32 m32;
    s32 nearFar;
    vu32 *fifo;

    FX_InvAsync(right - left);
    if (draw != 0) {
        reg_G3_MTX_MODE = 0;
        fifo = &reg_G3_MTX_LOAD_4x4;
    }
    if (mtx != 0) {
        mtx->mUnk_04 = 0;
        mtx->mUnk_08 = 0;
        mtx->mUnk_0c = 0;
        mtx->mUnk_10 = 0;
        mtx->mUnk_18 = 0;
        mtx->mUnk_1c = 0;
        mtx->mUnk_2c = -scaleW;
        mtx->mUnk_30 = 0;
        mtx->mUnk_34 = 0;
        mtx->mUnk_3c = 0;
    }
    dblNear = nearPlane << 1;
    invWidth = FX_GetDivResultFx64c();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (top - bottom);
    if (scaleW != 0x1000) {
        invWidth = invWidth * scaleW / 0x1000;
    }
    m00 = (invWidth * dblNear + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = m00;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mUnk_00 = m00;
    }
    invHeight = FX_GetDivResultFx64c();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (nearPlane - farPlane);
    if (scaleW != 0x1000) {
        invHeight = invHeight * scaleW / 0x1000;
    }
    m11 = (invHeight * dblNear + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = 0;
        *fifo = m11;
        *fifo = 0;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mUnk_14 = m11;
    }
    {
        s32 sumLR = right + left;
        s32 sumTB = top + bottom;
        s32 m20 = (invWidth * sumLR + 0x80000000) >> 32;
        s32 m21 = (invHeight * sumTB + 0x80000000) >> 32;
        if (draw != 0) {
            *fifo = m20;
            *fifo = m21;
        }
        if (mtx != 0) {
            mtx->mUnk_20 = m20;
            mtx->mUnk_24 = m21;
        }
    }
    invDepth = FX_GetDivResultFx64c();
    if (scaleW != 0x1000) {
        invDepth = invDepth * scaleW / 0x1000;
    }
    nearFar = ((s64) dblNear * farPlane + 0x800) >> 12;
    m22 = (invDepth * (farPlane + nearPlane) + 0x80000000) >> 32;
    m32 = (invDepth * nearFar + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = m22;
        *fifo = -scaleW;
        *fifo = 0;
        *fifo = 0;
        *fifo = m32;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mUnk_28 = m22;
        mtx->mUnk_38 = m32;
    }
}

// Builds an orthographic projection matrix from the six edge values, scaled by scaleW. With draw nonzero it sets the
// projection matrix mode and loads the 16 words with the 4x4 load command; with mtx not null it stores them there.
void G3i_OrthoW_(s32 top, s32 bottom, s32 left, s32 right, s32 nearPlane, s32 farPlane, s32 scaleW, int draw,
                 Unk0214ad4c *mtx) {
    s64 invWidth;
    s64 invHeight;
    s64 invDepth;
    s32 m00;
    s32 m11;
    s32 m22;
    vu32 *fifo;

    FX_InvAsync(right - left);
    if (draw != 0) {
        reg_G3_MTX_MODE = 0;
        fifo = &reg_G3_MTX_LOAD_4x4;
    }
    if (mtx != 0) {
        mtx->mUnk_04 = 0;
        mtx->mUnk_08 = 0;
        mtx->mUnk_0c = 0;
        mtx->mUnk_10 = 0;
        mtx->mUnk_18 = 0;
        mtx->mUnk_1c = 0;
        mtx->mUnk_20 = 0;
        mtx->mUnk_24 = 0;
        mtx->mUnk_2c = 0;
        mtx->mUnk_3c = scaleW;
    }
    invWidth = FX_GetDivResultFx64c();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (top - bottom);
    if (scaleW != 0x1000) {
        invWidth = invWidth * scaleW / 0x1000;
    }
    m00 = ((invWidth << 13) + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = m00;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mUnk_00 = m00;
    }
    invHeight = FX_GetDivResultFx64c();
    reg_CP_DIV_NUMER = 0x100000000000ULL;
    reg_CP_DIV_DENOM = (u32) (nearPlane - farPlane);
    if (scaleW != 0x1000) {
        invHeight = invHeight * scaleW / 0x1000;
    }
    m11 = ((invHeight << 13) + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = m11;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mUnk_14 = m11;
    }
    invDepth = FX_GetDivResultFx64c();
    if (scaleW != 0x1000) {
        invDepth = invDepth * scaleW / 0x1000;
    }
    m22 = ((invDepth << 13) + 0x80000000) >> 32;
    if (draw != 0) {
        *fifo = m22;
        *fifo = 0;
    }
    if (mtx != 0) {
        mtx->mUnk_28 = m22;
    }
    {
        s32 negSumLR = -(right + left);
        s32 negSumTB = -(top + bottom);
        s32 sumNF = farPlane + nearPlane;
        s32 m30 = (invWidth * negSumLR + 0x80000000) >> 32;
        s32 m31 = (invHeight * negSumTB + 0x80000000) >> 32;
        s32 m32 = (invDepth * sumNF + 0x80000000) >> 32;
        if (draw != 0) {
            *fifo = m30;
            *fifo = m31;
            *fifo = m32;
            *fifo = scaleW;
        }
        if (mtx != 0) {
            mtx->mUnk_30 = m30;
            mtx->mUnk_34 = m31;
            mtx->mUnk_38 = m32;
        }
    }
}

// Builds a view matrix from the camera position, the up vector and the target. With draw nonzero it sets the position
// vector matrix mode and loads the 12 words with the 4x3 load command; with mtx not null it stores them there.
void G3i_LookAt_(const Vec3 *camPos, const Vec3 *camUp, const Vec3 *target, int draw, MtxFx43 *mtx) {
    Vec3 look;
    Vec3 right;
    Vec3 up;
    s32 transX;
    s32 transY;
    s32 transZ;
    vu32 *fifo;

    look.x = camPos->x - target->x;
    look.y = camPos->y - target->y;
    look.z = camPos->z - target->z;
    VEC_Normalize(&look, &look);
    VEC_CrossProduct(camUp, &look, &right);
    VEC_Normalize(&right, &right);
    VEC_CrossProduct(&look, &right, &up);
    if (draw != 0) {
        reg_G3_MTX_MODE = 2;
        fifo = &reg_G3_MTX_LOAD_4x3;
        *fifo = right.x;
        *fifo = up.x;
        *fifo = look.x;
        *fifo = right.y;
        *fifo = up.y;
        *fifo = look.y;
        *fifo = right.z;
        *fifo = up.z;
        *fifo = look.z;
    }
    transX = -VEC_DotProduct(camPos, &right);
    transY = -VEC_DotProduct(camPos, &up);
    transZ = -VEC_DotProduct(camPos, &look);
    if (draw != 0) {
        *fifo = transX;
        *fifo = transY;
        *fifo = transZ;
    }
    if (mtx != 0) {
        mtx->mUnk_00[0].x = right.x;
        mtx->mUnk_00[0].y = up.x;
        mtx->mUnk_00[0].z = look.x;
        mtx->mUnk_00[1].x = right.y;
        mtx->mUnk_00[1].y = up.y;
        mtx->mUnk_00[1].z = look.y;
        mtx->mUnk_00[2].x = right.z;
        mtx->mUnk_00[2].y = up.z;
        mtx->mUnk_00[2].z = look.z;
        mtx->mUnk_00[3].x = transX;
        mtx->mUnk_00[3].y = transY;
        mtx->mUnk_00[3].z = transZ;
    }
}

// Resets the geometry engine and its registers to the start state: clears the FIFO and the matrix stacks, sets the
// clear color, depth, fog and BG0 registers, clears the tables and sets the default polygon attributes.
void G3X_Init(void) {
    G3X_ClearFifo();
    reg_G3_END_VTXS = 0;
    while (reg_G3X_GXSTAT & 0x8000000) {
    }
    reg_G3X_DISP3DCNT = 0;
    reg_G3X_GXSTAT = 0;
    reg_G2_BG0OFS = 0;
    reg_G3X_DISP3DCNT |= 0x2000;
    reg_G3X_DISP3DCNT |= 0x1000;
    reg_G3X_DISP3DCNT &= 0xffffcffd;
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 0x10;
    reg_G3X_DISP3DCNT &= 0xcffb;
    reg_G3X_GXSTAT |= 0x8000;
    reg_G3X_GXSTAT = (reg_G3X_GXSTAT & ~0xc0000000) | 0x80000000;
    G3X_InitMtxStack();
    reg_G3X_CLEAR_COLOR = 0;
    reg_G3X_CLEAR_DEPTH = 0x7fff;
    reg_G3X_CLRIMAGE_OFFSET = 0;
    reg_G3X_FOG_COLOR = 0;
    reg_G3X_FOG_OFFSET = 0;
    reg_G2_BG0CNT &= ~3;
    G3X_InitTable();
    reg_G3_POLYGON_ATTR = 0x1f0080;
    reg_G3_TEXIMAGE_PARAM = 0;
    reg_G3_PLTT_BASE = 0;
}

// Waits for the geometry engine, resets the matrix stacks and sets the default polygon attributes, texture
// parameters and palette base.
void G3X_Reset(void) {
    while (reg_G3X_GXSTAT & 0x8000000) {
    }
    reg_G3X_GXSTAT |= 0x8000;
    reg_G3X_DISP3DCNT |= 0x2000;
    reg_G3X_DISP3DCNT |= 0x1000;
    G3X_ResetMtxStack();
    reg_G3_POLYGON_ATTR = 0x1f0080;
    reg_G3_TEXIMAGE_PARAM = 0;
    reg_G3_PLTT_BASE = 0;
}

// Writes 128 zero words to the geometry FIFO, then waits for the geometry engine.
void G3X_ClearFifo(void) {
    GXi_NopClearFifo128_((void *) &reg_G3X_GXFIFO);
    while (reg_G3X_GXSTAT & 0x8000000) {
    }
}

// Pops the projection and position vector stacks to their bottom and loads the identity matrix into the texture,
// projection and position vector matrices.
void G3X_InitMtxStack(void) {
    s32 positionLevel;
    s32 projectionLevel;

    reg_G3X_GXSTAT |= 0x8000;
    while (G3X_GetMtxStackLevelPV(&positionLevel) != 0) {
    }
    while (G3X_GetMtxStackLevelPJ(&projectionLevel) != 0) {
    }
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 0;
    if (projectionLevel != 0) {
        reg_G3_MTX_POP = projectionLevel;
    }
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_POP = positionLevel;
    reg_G3_MTX_IDENTITY = 0;
}

// As G3X_InitMtxStack, except that the projection matrix does not get the identity matrix.
void G3X_ResetMtxStack(void) {
    s32 positionLevel;
    s32 projectionLevel;

    reg_G3X_GXSTAT |= 0x8000;
    while (G3X_GetMtxStackLevelPV(&positionLevel) != 0) {
    }
    while (G3X_GetMtxStackLevelPJ(&projectionLevel) != 0) {
    }
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 0;
    if (projectionLevel != 0) {
        reg_G3_MTX_POP = projectionLevel;
    }
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_POP = positionLevel;
    reg_G3_MTX_IDENTITY = 0;
}

// With enable nonzero, sets the fog offset and the fog mode and slope bits of DISP3DCNT and turns the fog on;
// otherwise clears the fog bits.
void G3X_SetFog(s32 enable, u32 fogMode, u32 fogSlope, u32 fogOffset) {
    if (enable != 0) {
        reg_G3X_FOG_OFFSET = fogOffset;
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3f40) | ((fogSlope << 8) | (fogMode << 6) | 0x80);
    } else {
        reg_G3X_DISP3DCNT = reg_G3X_DISP3DCNT & 0xcf7f;
    }
}

// Copies the 16 words of the clip matrix to m. Returns -1 while the geometry engine is busy, 0 otherwise.
s32 G3X_GetClipMtx(void *m) {
    if (reg_G3X_GXSTAT & 0x8000000) {
        return -1;
    }
    MI_Copy64B((const void *) 0x4000640, m);
    return 0;
}

// Copies the 9 words of the vector matrix to m. Returns -1 while the geometry engine is busy, 0 otherwise.
s32 G3X_GetVectorMtx(void *m) {
    if (reg_G3X_GXSTAT & 0x8000000) {
        return -1;
    }
    MI_Copy36B((const void *) 0x4000680, m);
    return 0;
}

// Copies the 8 words of fogTable to the fog table registers.
void G3X_SetFogTable(const void *fogTable) {
    MI_Copy32B(fogTable, (void *) 0x4000360);
}
