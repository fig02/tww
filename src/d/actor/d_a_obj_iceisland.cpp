//
// Generated by dtk
// Translation Unit: d_a_obj_iceisland.cpp
//

#include "d/actor/d_a_obj_iceisland.h"
#include "d/d_procname.h"

/* 00000078-00000098       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 00000098-00000338       .text CreateHeap__16daObjIceisland_cFv */
void daObjIceisland_c::CreateHeap() {
    /* Nonmatching */
}

/* 00000338-00000410       .text daObjIceisland_particle_set__16daObjIceisland_cFv */
void daObjIceisland_c::daObjIceisland_particle_set() {
    /* Nonmatching */
}

/* 00000410-00000588       .text CreateInit__16daObjIceisland_cFv */
void daObjIceisland_c::CreateInit() {
    /* Nonmatching */
}

/* 00000588-00000608       .text set_mtx__16daObjIceisland_cFv */
void daObjIceisland_c::set_mtx() {
    /* Nonmatching */
}

/* 00000608-0000067C       .text daObjIceisland_freeze_main__16daObjIceisland_cFv */
void daObjIceisland_c::daObjIceisland_freeze_main() {
    /* Nonmatching */
}

/* 0000067C-00000774       .text daObjIceisland_melt_demo_wait__16daObjIceisland_cFv */
void daObjIceisland_c::daObjIceisland_melt_demo_wait() {
    /* Nonmatching */
}

/* 00000774-000007DC       .text daObjIceisland_melt_demo__16daObjIceisland_cFv */
void daObjIceisland_c::daObjIceisland_melt_demo() {
    /* Nonmatching */
}

/* 000007DC-00000850       .text daObjIceisland_melt_main__16daObjIceisland_cFv */
void daObjIceisland_c::daObjIceisland_melt_main() {
    /* Nonmatching */
}

/* 00000850-000008C0       .text daObjIceisland_freeze_demo_wait__16daObjIceisland_cFv */
void daObjIceisland_c::daObjIceisland_freeze_demo_wait() {
    /* Nonmatching */
}

/* 000008C0-00000928       .text daObjIceisland_freeze_demo__16daObjIceisland_cFv */
void daObjIceisland_c::daObjIceisland_freeze_demo() {
    /* Nonmatching */
}

/* 00000928-00000994       .text daObjIceisland_fail_demo_wait__16daObjIceisland_cFv */
void daObjIceisland_c::daObjIceisland_fail_demo_wait() {
    /* Nonmatching */
}

/* 00000994-000009B8       .text daObjIceisland_fail_demo_main__16daObjIceisland_cFv */
void daObjIceisland_c::daObjIceisland_fail_demo_main() {
    /* Nonmatching */
}

/* 000009B8-00000B2C       .text daObjIceisland_Create__FPv */
static s32 daObjIceisland_Create(void*) {
    /* Nonmatching */
}

/* 00000C2C-00000C5C       .text daObjIceisland_Delete__FPv */
static BOOL daObjIceisland_Delete(void*) {
    /* Nonmatching */
}

/* 00000C5C-00000D2C       .text daObjIceisland_Draw__FPv */
static BOOL daObjIceisland_Draw(void*) {
    /* Nonmatching */
}

/* 00000D2C-00000EC0       .text daObjIceisland_Execute__FPv */
static BOOL daObjIceisland_Execute(void*) {
    /* Nonmatching */
}

/* 00000EC0-00000EC8       .text daObjIceisland_IsDelete__FPv */
static BOOL daObjIceisland_IsDelete(void*) {
    /* Nonmatching */
}

static actor_method_class daObj_IceislandMethodTable = {
    (process_method_func)daObjIceisland_Create,
    (process_method_func)daObjIceisland_Delete,
    (process_method_func)daObjIceisland_Execute,
    (process_method_func)daObjIceisland_IsDelete,
    (process_method_func)daObjIceisland_Draw,
};

actor_process_profile_definition g_profile_Obj_Iceisland = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0003,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Iceisland,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjIceisland_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0024,
    /* Actor SubMtd */ &daObj_IceislandMethodTable,
    /* Status       */ fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
