//
// Generated by dtk
// Translation Unit: d_a_obj_apzl.cpp
//

#include "d/actor/d_a_obj_apzl.h"
#include "d/d_procname.h"

/* 00000078-0000025C       .text move_piece__11daObjApzl_cFv */
void daObjApzl_c::move_piece() {
    /* Nonmatching */
}

/* 0000025C-00000310       .text check_arrow_draw__11daObjApzl_cFv */
void daObjApzl_c::check_arrow_draw() {
    /* Nonmatching */
}

/* 00000310-0000033C       .text search_piece__11daObjApzl_cFUc */
void daObjApzl_c::search_piece(unsigned char) {
    /* Nonmatching */
}

/* 0000033C-00000360       .text swap_piece__11daObjApzl_cFUcUc */
void daObjApzl_c::swap_piece(unsigned char, unsigned char) {
    /* Nonmatching */
}

/* 00000360-00000598       .text randamize_piece__11daObjApzl_cFv */
void daObjApzl_c::randamize_piece() {
    /* Nonmatching */
}

/* 00000598-000005CC       .text save_piece__11daObjApzl_cFv */
void daObjApzl_c::save_piece() {
    /* Nonmatching */
}

/* 000005CC-00000604       .text check_clear__11daObjApzl_cFv */
void daObjApzl_c::check_clear() {
    /* Nonmatching */
}

/* 00000604-00000748       .text next_msgStatus__11daObjApzl_cFPUl */
void daObjApzl_c::next_msgStatus(unsigned long*) {
    /* Nonmatching */
}

/* 00000748-0000079C       .text getMsg__11daObjApzl_cFv */
void daObjApzl_c::getMsg() {
    /* Nonmatching */
}

/* 0000079C-0000087C       .text talk__11daObjApzl_cFi */
void daObjApzl_c::talk(int) {
    /* Nonmatching */
}

/* 0000087C-00000D08       .text privateCut__11daObjApzl_cFv */
void daObjApzl_c::privateCut() {
    /* Nonmatching */
}

/* 00000D08-00000D28       .text CheckCreateHeap__FP10fopAc_ac_c */
static BOOL CheckCreateHeap(fopAc_ac_c*) {
    /* Nonmatching */
}

/* 00000D28-00001088       .text CreateHeap__11daObjApzl_cFv */
void daObjApzl_c::CreateHeap() {
    /* Nonmatching */
}

/* 00001088-000012BC       .text CreateInit__11daObjApzl_cFv */
void daObjApzl_c::CreateInit() {
    /* Nonmatching */
}

/* 000012BC-000016B8       .text set_mtx__11daObjApzl_cFv */
void daObjApzl_c::set_mtx() {
    /* Nonmatching */
}

/* 000016B8-00001780       .text daObjApzl_Create__FPv */
static s32 daObjApzl_Create(void*) {
    /* Nonmatching */
}

/* 0000184C-00001894       .text daObjApzl_Delete__FPv */
static BOOL daObjApzl_Delete(void*) {
    /* Nonmatching */
}

/* 00001894-000018B8       .text daObjApzl_Draw__FPv */
static BOOL daObjApzl_Draw(void*) {
    /* Nonmatching */
}

/* 000018B8-00001B00       .text _draw__11daObjApzl_cFv */
BOOL daObjApzl_c::_draw() {
    /* Nonmatching */
}

/* 00001B00-00001B24       .text daObjApzl_Execute__FPv */
static BOOL daObjApzl_Execute(void*) {
    /* Nonmatching */
}

/* 00001B24-00001E8C       .text _execute__11daObjApzl_cFv */
BOOL daObjApzl_c::_execute() {
    /* Nonmatching */
}

/* 00001E8C-00001E94       .text daObjApzl_IsDelete__FPv */
static BOOL daObjApzl_IsDelete(void*) {
    /* Nonmatching */
}

static actor_method_class daObj_ApzlMethodTable = {
    (process_method_func)daObjApzl_Create,
    (process_method_func)daObjApzl_Delete,
    (process_method_func)daObjApzl_Execute,
    (process_method_func)daObjApzl_IsDelete,
    (process_method_func)daObjApzl_Draw,
};

actor_process_profile_definition g_profile_Obj_Apzl = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0007,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Apzl,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjApzl_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x007D,
    /* Actor SubMtd */ &daObj_ApzlMethodTable,
    /* Status       */ fopAcStts_NOCULLEXEC_e | fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
