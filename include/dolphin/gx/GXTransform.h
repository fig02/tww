#ifndef GXTRANSFORM_H
#define GXTRANSFORM_H

#include "dolphin/gx/GXEnum.h"
#include "dolphin/mtx/mtx.h"

#ifdef __cplusplus
extern "C" {
#endif

void GXProject(f32 model_x, f32 model_y, f32 model_z, Mtx model_mtx, f32* proj, f32* viewpoint, f32* screen_x, f32* screen_y, f32* screen_z);
void GXSetProjection(const Mtx44 proj, GXProjectionType type);
void GXSetProjectionv(f32* p);
void GXGetProjectionv(f32* p);
void GXLoadPosMtxImm(Mtx mtx, u32 id);
void GXLoadNrmMtxImm(Mtx mtx, u32 id);
void GXSetCurrentMtx(u32 id);
void GXLoadTexMtxImm(const Mtx mtx, u32 id, GXTexMtxType type);
void GXSetViewport(f32 x_orig, f32 y_orig, f32 width, f32 height, f32 near_z, f32 far_z);
void GXGetViewportv(f32* p);
void GXSetScissor(u32 left, u32 top, u32 width, u32 height);
void GXGetScissor(u32* left, u32* top, u32* width, u32* height);
void GXSetScissorBoxOffset(s32 x, s32 y);
void GXSetClipMode(GXClipMode mode);

void __GXSetMatrixIndex(GXAttr index);

#ifdef __cplusplus
};
#endif

#endif /* GXTRANSFORM_H */
