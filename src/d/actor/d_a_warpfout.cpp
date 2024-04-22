//
// Generated by dtk
// Translation Unit: d_a_warpfout.cpp
//

#include "d/actor/d_a_warpfout.h"
#include "d/d_camera.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"

static Vec unkVecs[] = {{1, 1, 1}, {1, 1, 1}};
static int unkInt[] = {0x02000201, 0x00000000};
static f64 unkf64[] = {3, 0.5};

static daWarpfout_c::EventActionInitFunc event_init_tbl[] = {
    &daWarpfout_c::initWarp1, &daWarpfout_c::initWarp2, &daWarpfout_c::initWarp3,
    &daWarpfout_c::initWarp4, &daWarpfout_c::initEnd,
};

static daWarpfout_c::EventActionFunc event_action_tbl[] = {
    &daWarpfout_c::actWarp1, &daWarpfout_c::actWarp2, &daWarpfout_c::actWarp3,
    &daWarpfout_c::actWarp4, &daWarpfout_c::actEnd,
};

static char* action_table[] = {
    "WARP1", "WARP2", "WARP3", "WARP4", "END",
};

/* 00000078-00000080       .text _delete__12daWarpfout_cFv */
bool daWarpfout_c::_delete() {
    return true;
}

/* 00000080-0000008C       .text CreateInit__12daWarpfout_cFv */
void daWarpfout_c::CreateInit() {
    unknownInitFlag = -0x1;
}

/* 0000008C-000000E4       .text _create__12daWarpfout_cFv */
s32 daWarpfout_c::_create() {
    fopAcM_SetupActor(this, daWarpfout_c);
    CreateInit();

    return cPhs_COMPLEATE_e;
}

/* 000000E4-00000124       .text _execute__12daWarpfout_cFv */
bool daWarpfout_c::_execute() {
    checkOrder();
    demo_proc();
    eventOrder();
    return true;
}

/* 00000124-00000128       .text checkOrder__12daWarpfout_cFv */
void daWarpfout_c::checkOrder() {}

/* 00000128-0000012C       .text eventOrder__12daWarpfout_cFv */
void daWarpfout_c::eventOrder() {}

/* 0000012C-00000248       .text demo_proc__12daWarpfout_cFv */
void daWarpfout_c::demo_proc() {
    mStaffId = dComIfGp_evmng_getMyStaffId("Warpfo");

    if (dComIfGp_event_runCheck() && !eventInfo.checkCommandTalk() && mStaffId != -1) {
        int actIdx =
            dComIfGp_evmng_getMyActIdx(mStaffId, action_table, ARRAY_SIZE(action_table), FALSE, 0);

        if (actIdx == -1) {
            dComIfGp_evmng_cutEnd(mStaffId);
            return;
        }

        if (dComIfGp_evmng_getIsAddvance(mStaffId)) {
            (this->*event_init_tbl[actIdx])(mStaffId);
        }
        if ((this->*event_action_tbl[actIdx])(mStaffId)) {
            dComIfGp_evmng_cutEnd(mStaffId);
        }
    }
}

/* 00000248-000002A8       .text initWarp1__12daWarpfout_cFi */
void daWarpfout_c::initWarp1(int) {
    mTimer = 5;
    mDoAud_seStart(JA_SE_LK_BOSS_WARP_EFF_ED);
}

/* 000002A8-00000344       .text actWarp1__12daWarpfout_cFi */
BOOL daWarpfout_c::actWarp1(int) {
    if (mTimer == 0x4) {
        cXyz effectPos = dComIfGp_getLinkPlayer()->current.pos;
        effectPos.y += 40.0f;

        set_effect_wind01(effectPos, 0);
    }

    if (cLib_calcTimer(&mTimer) == 0) {
        return TRUE;
    } else {
        return FALSE;
    };
}

/* 00000344-000003C0       .text initWarp2__12daWarpfout_cFi */
void daWarpfout_c::initWarp2(int) {
    cXyz effectPos = dComIfGp_getLinkPlayer()->current.pos;
    effectPos.y += 60.0f;

    set_effect_wind01(effectPos, 0x38e);
    mTimer = 5;
}

/* 000003C0-000003EC       .text actWarp2__12daWarpfout_cFi */
BOOL daWarpfout_c::actWarp2(int) {
    if (cLib_calcTimer(&mTimer) == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* 000003EC-00000468       .text initWarp3__12daWarpfout_cFi */
void daWarpfout_c::initWarp3(int) {
    cXyz effectPos = dComIfGp_getLinkPlayer()->current.pos;
    effectPos.y += 80.0f;

    set_effect_wind01(effectPos, 0x71c);
    mTimer = 5;
}

/* 00000468-00000494       .text actWarp3__12daWarpfout_cFi */
BOOL daWarpfout_c::actWarp3(int) {
    if (cLib_calcTimer(&mTimer) == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* 00000494-0000051C       .text initWarp4__12daWarpfout_cFi */
void daWarpfout_c::initWarp4(int) {
    fopAc_ac_c* link = dComIfGp_getLinkPlayer();

    for (int i = 0; i < 6; i++) {
        dComIfGp_particle_set(dPa_name::ID_WARPFOUT_WARP4, &link->current.pos);
    }
}

/* 0000051C-00000524       .text actWarp4__12daWarpfout_cFi */
BOOL daWarpfout_c::actWarp4(int) {
    return TRUE;
}

/* 00000524-00000528       .text initEnd__12daWarpfout_cFi */
void daWarpfout_c::initEnd(int) {}

/* 00000528-0000054C       .text actEnd__12daWarpfout_cFi */
BOOL daWarpfout_c::actEnd(int) {
    fopAcM_delete(this);
    return TRUE;
}

/* 0000054C-000005F4       .text set_effect_wind01__12daWarpfout_cF4cXyzs */
void daWarpfout_c::set_effect_wind01(cXyz effectPos, s16 effectAngleZOffset) {
    csXyz effectAngle = get_effect_angle();
    effectAngle.z += effectAngleZOffset;

    dComIfGp_particle_set(0x830f, &effectPos, &effectAngle);
}

/* 000005F4-00000670       .text get_effect_angle__12daWarpfout_cFv */
csXyz daWarpfout_c::get_effect_angle() {
    csXyz angle = current.angle;

    angle.x = dCam_getAngleX(dComIfGp_getCamera(0));
    angle.y = dCam_getAngleY(dComIfGp_getCamera(0)) + 0x8000;
    angle.z = 0;

    return angle;
}

/* 00000670-00000690       .text daWarpfout_Create__FPv */
static s32 daWarpfout_Create(void* i) {
    daWarpfout_c* i_this = static_cast<daWarpfout_c*>(i);

    return i_this->_create();
}

/* 00000690-000006B4       .text daWarpfout_Delete__FPv */
static BOOL daWarpfout_Delete(void* i) {
    daWarpfout_c* i_this = static_cast<daWarpfout_c*>(i);

    return i_this->_delete();
}

/* 000006B4-000006BC       .text daWarpfout_Draw__FPv */
static BOOL daWarpfout_Draw(void*) {
    return TRUE;
}

/* 000006BC-000006E0       .text daWarpfout_Execute__FPv */
static BOOL daWarpfout_Execute(void* i) {
    daWarpfout_c* i_this = static_cast<daWarpfout_c*>(i);

    return i_this->_execute();
}

/* 000006E0-000006E8       .text daWarpfout_IsDelete__FPv */
static BOOL daWarpfout_IsDelete(void*) {
    return TRUE;
}

static actor_method_class daWarpfoutMethodTable = {
    (process_method_func)daWarpfout_Create,
    (process_method_func)daWarpfout_Delete,
    (process_method_func)daWarpfout_Execute,
    (process_method_func)daWarpfout_IsDelete,
    (process_method_func)daWarpfout_Draw,
};

actor_process_profile_definition g_profile_WARPFOUT = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0003,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_WARPFOUT,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daWarpfout_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x01A3,
    /* Actor SubMtd */ &daWarpfoutMethodTable,
    /* Status       */ fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
