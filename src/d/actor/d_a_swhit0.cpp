//
// Generated by dtk
// Translation Unit: d_a_swhit0.cpp
//

#include "d/actor/d_a_swhit0.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "f_op/f_op_actor_mng.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "m_Do/m_Do_mtx.h"

static dCcD_SrcSph l_sph_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt Type     */ 0,
        /* SrcObjAt Atp      */ 0,
        /* SrcObjAt SPrm     */ 0,
        /* SrcObjTg Type     */ ~(AT_TYPE_LIGHT | AT_TYPE_UNK400000 | AT_TYPE_LEAF_WIND | AT_TYPE_UNK20000 | AT_TYPE_WATER), // 0xFF1DFEFF
        /* SrcObjTg SPrm     */ 9,
        /* SrcObjCo SPrm     */ 0,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt GFlag   */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg GFlag   */ 0,
        /* SrcGObjCo GFlag   */ 0,
    },
    // cM3dGSphS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 35.0f,
    },
};

static dCcD_SrcCyl l_cyl_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt Type     */ 0,
        /* SrcObjAt Atp      */ 0,
        /* SrcObjAt SPrm     */ 0,
        /* SrcObjTg Type     */ 0,
        /* SrcObjTg SPrm     */ 0,
        /* SrcObjCo SPrm     */ 0x75,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt GFlag   */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg GFlag   */ 0x00,
        /* SrcGObjCo GFlag   */ 0,
    },
    // cM3dGCylS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 25.0f,
        /* Height */ 100.0f,
    },
};

/* 00000078-00000084       .text getSwNo__10daSwhit0_cFv */
s32 daSwhit0_c::getSwNo() {
    return fopAcM_GetParam(this) & 0xFF;
}

/* 00000084-00000090       .text getEvNo__10daSwhit0_cFv */
u8 daSwhit0_c::getEvNo() {
    return fopAcM_GetParam(this) >> 8;
}

/* 00000090-0000009C       .text getType__10daSwhit0_cFv */
u8 daSwhit0_c::getType() {
    return (fopAcM_GetParam(this) >> 0x10) & 0x0F;
}

/* 0000009C-000000B8       .text getTimer__10daSwhit0_cFv */
s32 daSwhit0_c::getTimer() {
    u8 param = (fopAcM_GetParam(this) >> 0x14);
    s32 timer = param;
   
    if (param == 0xFF) {
        timer = 0;
    }
    return timer;
}

/* 000000B8-000000C4       .text getSwNo2__10daSwhit0_cFv */
s32 daSwhit0_c::getSwNo2() {
    return orig.angle.z & 0xFF;
}

/* 000000C4-00000230       .text CreateHeap__10daSwhit0_cFv */
BOOL daSwhit0_c::CreateHeap() {
    J3DModelData* modelData = (J3DModelData*)dComIfG_getObjectRes("Always", 0x35);
    JUT_ASSERT(0xD5, modelData != 0);

    mpModel = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000202);
    if (mpModel == NULL) {
        return FALSE;
    }

    J3DAnmTransform* anm = (J3DAnmTransform*)dComIfG_getObjectRes("Always", 0x0D);
    if (mAnm.init(modelData, anm, true, 0x02, 1.0f, 0, -1, false) == 0) {
        return FALSE;
    }

    J3DAnmTextureSRTKey* texAnm = (J3DAnmTextureSRTKey*)dComIfG_getObjectRes("Always", 0x58);
    if (mTexAnm.init(modelData, texAnm, true, 0x02, 1.0f, 0, -1, false, 0) == 0) {
        return FALSE;
    }

    return TRUE;
}

/* 00000230-00000270       .text decisionRtType__10daSwhit0_cFv */
void daSwhit0_c::decisionRtType() {
    if (orig.angle.x == 0) {
        mRetType = 0;
    }
    else if (orig.angle.x < -0x4E20 || orig.angle.x > 0x4E20) {
        mRetType = 2;
        return;
    }
    else {
        mRetType = 1;
    }
}

/* 00000270-000004E8       .text CreateInit__10daSwhit0_cFv */
s32 daSwhit0_c::CreateInit() {
    setDrawMtx();
    fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
    decisionRtType();

    mColStatus.Init(0xFF, 0xFF, this);

    mAttentionInfo.mPosition.x += cM_ssin(orig.angle.x) * 65.0f * cM_ssin(orig.angle.y);
    mAttentionInfo.mPosition.y += cM_scos(orig.angle.x) * 65.0f;
    mAttentionInfo.mPosition.z += cM_ssin(orig.angle.x) * 65.0f * cM_scos(orig.angle.y);

    mEyePos = mAttentionInfo.mPosition;

    if (mRetType == 0) {
        mColCyl.Set(l_cyl_src);
        mColCyl.SetStts(&mColStatus);
        mColCyl.SetC(current.pos);

        onFlag(0x02);
    }

    mColSph.Set(l_sph_src);
    mColSph.SetStts(&mColStatus);
    mColSph.SetC(mAttentionInfo.mPosition);
    
    if (dComIfGs_isSwitch(getSwNo(), current.roomNo)) {
        mState = 4;
        onFlag(0x01);
    }
    else {
        mState = 0;
        offFlag(0x01);
    }

    if (getType() == 0x03) {
        mEventIdx = dComIfGp_evmng_getEventIdx("DEFAULT_SWITCH_NOSOUND", getEvNo());
    }
    else {
        mEventIdx = dComIfGp_evmng_getEventIdx("DEFAULT_SWITCH", getEvNo());
    }

    return TRUE;
}

/* 000004E8-00000508       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c* i_actr) {
    return static_cast<daSwhit0_c*>(i_actr)->CreateHeap();
}

/* 00000508-000006C0       .text create__10daSwhit0_cFv */
s32 daSwhit0_c::create() {
    fopAcM_SetupActor(this, daSwhit0_c);

    shape_angle.z = 0;
    current.angle.z = 0;

    if (fopAcM_entrySolidHeap(this, CheckCreateHeap, 0x34A0) == 0) {
        return cPhs_ERROR_e;
    }

    CreateInit();
    return cPhs_COMPLEATE_e;
}

/* 00000AE8-00000B44       .text checkHit__10daSwhit0_cFv */
s32 daSwhit0_c::checkHit() {
    if (cLib_calcTimer(&mHitTimer) == 0 && mColSph.ChkTgHit() != 0) {
        mHitTimer = 8;
        return TRUE;
    }

    return FALSE;
}

/* 00000B44-00000C48       .text DemoProc__10daSwhit0_cFv */
s32 daSwhit0_c::DemoProc() {
    static char* action_table[] = {
        "WAIT",
        "CHANGE"
    };

    if (dComIfGp_evmng_getIsAddvance(mStaffId))
    {
        switch(dComIfGp_evmng_getMyActIdx(mStaffId, action_table, ARRAY_SIZE(action_table), 0, 0)) {
            case 1:
                dComIfGs_onSwitch(getSwNo(), fopAcM_GetRoomNo(this));
                onFlag(0x01);

                fopAcM_seStart(this, JA_SE_SHOCK_SW_ON, 0);
                break;
        }
    }

    dComIfGp_evmng_cutEnd(mStaffId);
    return TRUE;
}

/* 00000C48-00000D8C       .text actionOffWait__10daSwhit0_cFv */
s32 daSwhit0_c::actionOffWait() {
    u32 type = getType();

    if (checkHit() != 0) {
        switch(type) {
            case 1:
                mState = 1;
                mTimer = 5;
                break;
            case 3:
                mState = 2;
                
                fopAcM_orderOtherEventId(this, mEventIdx, getEvNo());
                mEvtInfo.onCondition(0x02);

                break;
            default:
                mState = 4;
                onFlag(0x01);

                dComIfGs_onSwitch(getSwNo(), fopAcM_GetRoomNo(this));
                break;
        }

        fopAcM_seStart(this, JA_SE_OBJ_COL_SWC_NSTONE, 0);
    }

    return TRUE;
}

/* 00000D8C-00000E24       .text actionToOnReady__10daSwhit0_cFv */
s32 daSwhit0_c::actionToOnReady() {
    if (dComIfGp_event_runCheck() != 0) {
        return TRUE;
    }

    if (mTimer != 0) {
        mTimer--;
    }
    else {
        mState = 2;

        fopAcM_orderOtherEventId(this, mEventIdx, getEvNo());
        mEvtInfo.onCondition(0x02);
    }

    return TRUE;
}

/* 00000E24-00000EC8       .text actionToOnOrder__10daSwhit0_cFv */
s32 daSwhit0_c::actionToOnOrder() {
    if (mEvtInfo.checkCommandDemoAccrpt()) {
        mState = 3;
        mStaffId = dComIfGp_evmng_getMyStaffId("SWITCH");
        
        DemoProc();
    }
    else {
        fopAcM_orderOtherEventId(this, mEventIdx, getEvNo());
        mEvtInfo.onCondition(0x02);
    }

    return TRUE;
}

/* 00000EC8-00000F3C       .text actionToOnDemo__10daSwhit0_cFv */
s32 daSwhit0_c::actionToOnDemo() {
    if (dComIfGp_evmng_endCheck(mEventIdx)) {
        mState = 4;
        dComIfGp_event_onEventFlag(0x08);

        return TRUE;
    }
    
    DemoProc();

    return TRUE;
}

/* 00000F3C-0000104C       .text actionOnWait__10daSwhit0_cFv */
s32 daSwhit0_c::actionOnWait() {
    if (checkHit() != 0) {
        fopAcM_seStart(this, JA_SE_OBJ_COL_SWC_NSTONE, 0);
    }

    if (getType() == 0x02) {
        if (!dComIfGs_isSwitch(getSwNo(), current.roomNo)) {
            offFlag(0x01);
            mState = 0;

            return TRUE;
        }
    }

    u8 timer = getTimer();
    if (timer != 0) {
        mOnTimer = (u8)getTimer() * 0x0F;
        mState = 5;
    }

    return TRUE;
}

/* 0000104C-0000115C       .text actionOnTimer__10daSwhit0_cFv */
s32 daSwhit0_c::actionOnTimer() {
    if (checkHit() != 0) {
        fopAcM_seStart(this, JA_SE_OBJ_COL_SWC_NSTONE, 0);
    }

    if (dComIfGs_isSwitch(getSwNo2(), current.roomNo)) {
        mState = 4;
    }
    else if (mOnTimer > 0) {
        mOnTimer--;
    }
    else {
        offFlag(0x01);
        mState = 0;

        dComIfGs_offSwitch(getSwNo(), current.roomNo);
    }

    return TRUE;
}

/* 0000115C-000011E4       .text setDrawMtx__10daSwhit0_cFv */
void daSwhit0_c::setDrawMtx() {
    mpModel->setBaseScale(mScale);

    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::XYZrotM(current.angle);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
}

s32 daSwhit0_c::draw() {
    static GXColorS10 l_color[] = {
        { 0xF0, 0xF5, 0xFF, 0x6E },
        { 0xB4, 0xC8, 0xD2, 0x64 },
        
        { 0xE6, 0xC8, 0x00, 0x6E },
        { 0x78, 0x64, 0x32, 0x64 }
    };

    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &mTevStr);
    g_env_light.setLightTevColorType(mpModel, &mTevStr);

    J3DModelData* modelData = mpModel->getModelData();
    s32 flag = checkFlag(0x01);

    GXColorS10* colors = l_color;
    if (flag) {
        colors = l_color + 2;
    }

    for (u16 i = 0; i < modelData->getMaterialNum(); i++) {
        J3DMaterial* mat = modelData->getMaterialNodePointer(i);

        if (mat->getTevColor(1) != NULL) {
            mat->setTevColor(1, (J3DGXColorS10*)&colors[0]);
        }

        if (mat->getTevColor(2) != NULL) {
            mat->setTevColor(2, (J3DGXColorS10*)&colors[1]);
        }
    }
    
    mAnm.entry(modelData);
    mTexAnm.entry(modelData);

    mDoExt_modelUpdateDL(mpModel);

    return TRUE;
}

/* 000011E4-00001334       .text daSwhit0_Draw__FP10daSwhit0_c */
static s32 daSwhit0_Draw(daSwhit0_c* i_swhit) {
    return i_swhit->draw();
}

/* 00001334-00001420       .text daSwhit0_Execute__FP10daSwhit0_c */
static s32 daSwhit0_Execute(daSwhit0_c* i_swhit) {
    i_swhit->mAnm.play();
    i_swhit->mTexAnm.play();

    switch (i_swhit->mState) {
        case 0:
            i_swhit->actionOffWait();
            break;
        case 1:
            i_swhit->actionToOnReady();
            break;
        case 2:
            i_swhit->actionToOnOrder();
            break;
        case 3:
            i_swhit->actionToOnDemo();
            break;
        case 4:
            i_swhit->actionOnWait();
            break;
        case 5:
            i_swhit->actionOnTimer();
            break;
    }

    if (i_swhit->checkFlag(0x02)) {
        g_dComIfG_gameInfo.play.mCcS.Set(&i_swhit->mColCyl);
    }

    g_dComIfG_gameInfo.play.mCcS.Set(&i_swhit->mColSph);
    return TRUE;
}

/* 00001420-00001428       .text daSwhit0_IsDelete__FP10daSwhit0_c */
static s32 daSwhit0_IsDelete(daSwhit0_c* i_swhit) {
    return TRUE;
}

/* 00001428-00001450       .text daSwhit0_Delete__FP10daSwhit0_c */
static s32 daSwhit0_Delete(daSwhit0_c* i_swhit) {
    i_swhit->~daSwhit0_c();
    return TRUE;
}

/* 00001450-00001470       .text daSwhit0_Create__FP10fopAc_ac_c */
static s32 daSwhit0_Create(fopAc_ac_c* i_swhit) {
    return static_cast<daSwhit0_c*>(i_swhit)->create();
}

static actor_method_class l_daSwhit0_Method = {
    (process_method_func)daSwhit0_Create,
    (process_method_func)daSwhit0_Delete,
    (process_method_func)daSwhit0_Execute,
    (process_method_func)daSwhit0_IsDelete,
    (process_method_func)daSwhit0_Draw,
};

actor_process_profile_definition g_profile_SWHIT0 = {
    fpcLy_CURRENT_e,
    8,
    fpcPi_CURRENT_e,
    PROC_SWHIT0,
    &g_fpcLf_Method.mBase,
    sizeof(daSwhit0_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x0119,
    &l_daSwhit0_Method,
    fopAcStts_UNK40000_e | fopAcStts_UNK4000_e | fopAcStts_CULL_e,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_0_e,
};
