//
// Generated by dtk
// Translation Unit: d_a_obj_otble.cpp
//

#include "d/actor/d_a_obj_otble.h"
#include "d/d_procname.h"

/* 00000078-00000098       .text createHeap_CB__FP10fopAc_ac_c */
static BOOL createHeap_CB(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 00000098-00000168       .text set_mtx__Q211daObj_Otble5Act_cFv */
void daObj_Otble::Act_c::set_mtx() {
    /* Nonmatching */
}

/* 00000168-000001BC       .text _execute__Q211daObj_Otble5Act_cFv */
BOOL daObj_Otble::Act_c::_execute() {
    /* Nonmatching */
}

/* 000001BC-000002E8       .text _draw__Q211daObj_Otble5Act_cFv */
BOOL daObj_Otble::Act_c::_draw() {
    /* Nonmatching */
}

/* 000002E8-00000470       .text _createHeap__Q211daObj_Otble5Act_cFv */
void daObj_Otble::Act_c::_createHeap() {
    /* Nonmatching */
}

/* 00000470-000005A0       .text CreateInit__Q211daObj_Otble5Act_cFv */
void daObj_Otble::Act_c::CreateInit() {
    /* Nonmatching */
}

/* 000005A0-000006AC       .text Create__Q211daObj_Otble4MthdFPv */
s32 daObj_Otble::Mthd::Create(void*) {
    /* Nonmatching */
}

/* 0000071C-0000079C       .text Delete__Q211daObj_Otble4MthdFPv */
BOOL daObj_Otble::Mthd::Delete(void*) {
    /* Nonmatching */
}

/* 0000079C-000007BC       .text Execute__Q211daObj_Otble4MthdFPv */
BOOL daObj_Otble::Mthd::Execute(void*) {
    /* Nonmatching */
}

/* 000007BC-000007DC       .text Draw__Q211daObj_Otble4MthdFPv */
BOOL daObj_Otble::Mthd::Draw(void*) {
    /* Nonmatching */
}

/* 000007DC-000007E4       .text IsDelete__Q211daObj_Otble4MthdFPv */
BOOL daObj_Otble::Mthd::IsDelete(void*) {
    /* Nonmatching */
}

static actor_method_class daObj_Otble::Mthd::Table = {
    (process_method_func)daObj_Otble::Mthd::Create,
    (process_method_func)daObj_Otble::Mthd::Delete,
    (process_method_func)daObj_Otble::Mthd::Execute,
    (process_method_func)daObj_Otble::Mthd::IsDelete,
    (process_method_func)daObj_Otble::Mthd::Draw,
};

actor_process_profile_definition g_profile_OBJ_OTBLE = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0003,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_OBJ_OTBLE,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObj_Otble::Act_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x01B0,
    /* Actor SubMtd */ &daObj_Otble::Mthd::Table,
    /* Status       */ fopAcStts_NOCULLEXEC_e | fopAcStts_CULL_e | fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
