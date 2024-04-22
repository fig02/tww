//
// Generated by dtk
// Translation Unit: d_a_obj_wood.cpp
//

#include "d/actor/d_a_obj_wood.h"
#include "d/d_wood.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "f_op/f_op_actor_mng.h"

s32 daObjWood::Act_c::_create() {
    fopAcM_SetupActor(this, Act_c);
    if (dComIfGp_createWood() != NULL)
        dComIfGp_getWood()->put_unit(current.pos, fopAcM_GetRoomNo(this));
    return cPhs_ERROR_e;
}

bool daObjWood::Act_c::_delete() {
    return true;
}

bool daObjWood::Act_c::_execute() {
    mCyl.SetC(current.pos);
    return true;
}

bool daObjWood::Act_c::_draw() {
    return true;
}

/* 00000078-00000190       .text Create__Q29daObjWood6MethodFPv */
s32 daObjWood::Method::Create(void* i_this) {
    return ((Act_c*)i_this)->_create();
}

/* 00000348-00000350       .text Delete__Q29daObjWood6MethodFPv */
BOOL daObjWood::Method::Delete(void* i_this) {
    return ((Act_c*)i_this)->_delete();
}

/* 00000350-00000380       .text Execute__Q29daObjWood6MethodFPv */
BOOL daObjWood::Method::Execute(void* i_this) {
    return ((Act_c*)i_this)->_execute();
}

/* 00000380-00000388       .text Draw__Q29daObjWood6MethodFPv */
BOOL daObjWood::Method::Draw(void* i_this) {
    return ((Act_c*)i_this)->_draw();
}

/* 00000388-00000390       .text IsDelete__Q29daObjWood6MethodFPv */
BOOL daObjWood::Method::IsDelete(void* i_this) {
    return TRUE;
}

namespace daObjWood {
    namespace Method {
        actor_method_class Table = {
            (process_method_func)Create,
            (process_method_func)Delete,
            (process_method_func)Execute,
            (process_method_func)IsDelete,
            (process_method_func)Draw,
        };
    }
}

actor_process_profile_definition g_profile_Obj_Wood = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 0x0007,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Wood,
    /* Proc SubMtd  */ &g_fpcLf_Method.base,
    /* Size         */ sizeof(daObjWood::Act_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0110,
    /* Actor SubMtd */ &daObjWood::Method::Table,
    /* Status       */ fopAcStts_NOCULLEXEC_e | fopAcStts_CULL_e | fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
