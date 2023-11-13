//
// Generated by dtk
// Translation Unit: d_a_obj_AjavW.cpp
//

#include "f_op/f_op_actor_mng.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_bg_w.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"

class daObjAjavW_c : public fopAc_ac_c {
public:
    s32 _create();
    bool _execute();
    bool _draw();
    bool _delete();
    bool create_heap();
    static BOOL solidHeapCB(fopAc_ac_c *i_this);

public:
    /* 0x290 */ request_of_phase_process_class mPhs;
    /* 0x298 */ J3DModel * mpModel;
    /* 0x29C */ mDoExt_btkAnm mBtkAnm;
    /* 0x2B0 */ dBgW * mpBgW;
};

namespace {
    static const char l_arcname[] = "AjavW";
};

/* 00000078-0000009C       .text solidHeapCB__12daObjAjavW_cFP10fopAc_ac_c */
BOOL daObjAjavW_c::solidHeapCB(fopAc_ac_c* i_this) {
    return ((daObjAjavW_c*)i_this)->create_heap();
}

/* 0000009C-00000208       .text create_heap__12daObjAjavW_cFv */
bool daObjAjavW_c::create_heap() {
    bool ret = true;

    J3DModelData* pModelData = static_cast<J3DModelData*>(dComIfG_getObjectRes(l_arcname, 0x05));
    J3DAnmTextureSRTKey * pBtk = (J3DAnmTextureSRTKey *)dComIfG_getObjectRes(l_arcname, 0x08);

    if (!pModelData || !pBtk) {
        JUT_ASSERT(0xa7, 0);
        ret = false;
    } else {
        mpModel = mDoExt_J3DModel__create(pModelData, 0x80000, 0x11000222);
        s32 btkRet = mBtkAnm.init(pModelData, pBtk, 1, J3DFrameCtrl::LOOP_REPEAT_e, 1.0f, 0, -1, false, 0);
        mpBgW = dBgW_NewSet((cBgD_t*)dComIfG_getObjectRes(l_arcname, 0x0B), cBgW::MOVE_BG_e, &mpModel->getBaseTRMtx());

        if (!mpModel || !btkRet || !mpBgW)
            ret = false;
    }

    return ret;
}

/* 00000208-00000350       .text _create__12daObjAjavW_cFv */
s32 daObjAjavW_c::_create() {
    fopAcM_SetupActor(this, daObjAjavW_c);

    s32 ret = dComIfG_resLoad(&mPhs, l_arcname);

    if (ret == cPhs_COMPLEATE_e) {
        if (fopAcM_entrySolidHeap(this, (heapCallbackFunc)solidHeapCB, 0x8c0) == 1) {
            if (dComIfG_Bgsp()->Regist(mpBgW, this)) {
                ret = cPhs_ERROR_e;
            } else {
                fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
                mpModel->setBaseScale(mScale);
                mDoMtx_stack_c::transS(getPosition());
                mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
                fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
            }
        } else {
            ret = cPhs_ERROR_e;
        }
    }

    return ret;
}

/* 000003F4-00000488       .text _delete__12daObjAjavW_cFv */
bool daObjAjavW_c::_delete() {
    dComIfG_resDelete(&mPhs, l_arcname);

    if (heap != NULL && mpBgW != NULL) {
        if (mpBgW->ChkUsed()) {
            dComIfG_Bgsp()->Release(mpBgW);
        }

        mpBgW = NULL;
    }

    return true;
}

/* 00000488-000004F4       .text _execute__12daObjAjavW_cFv */
bool daObjAjavW_c::_execute() {
    mBtkAnm.play();
    if (mpBgW != NULL && mpBgW->ChkUsed())
        mpBgW->Move();
    return true;
}

/* 000004F4-0000056C       .text _draw__12daObjAjavW_cFv */
bool daObjAjavW_c::_draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG1, getPositionP(), &mTevStr);
    g_env_light.setLightTevColorType(mpModel, &mTevStr);
    mBtkAnm.entry(mpModel->getModelData());
    mDoExt_modelUpdateDL(mpModel);
    return true;
}

/* 0000056C-0000058C       .text daObjAjavW_Create__FP12daObjAjavW_c */
s32 daObjAjavW_Create(daObjAjavW_c* i_this) {
    return i_this->_create();
}

/* 0000058C-000005B0       .text daObjAjavW_Delete__FP12daObjAjavW_c */
BOOL daObjAjavW_Delete(daObjAjavW_c* i_this) {
    return i_this->_delete();
}

/* 000005B0-000005D4       .text daObjAjavW_Execute__FP12daObjAjavW_c */
BOOL daObjAjavW_Execute(daObjAjavW_c* i_this) {
    return i_this->_execute();
}

/* 000005D4-000005F8       .text daObjAjavW_Draw__FP12daObjAjavW_c */
BOOL daObjAjavW_Draw(daObjAjavW_c* i_this) {
    return i_this->_draw();
}

/* 000005F8-00000600       .text daObjAjavW_IsDelete__FP12daObjAjavW_c */
BOOL daObjAjavW_IsDelete(daObjAjavW_c* i_this) {
    return TRUE;
}

static actor_method_class l_daObjAjavW_Method = {
    (process_method_func)daObjAjavW_Create,
    (process_method_func)daObjAjavW_Delete,
    (process_method_func)daObjAjavW_Execute,
    (process_method_func)daObjAjavW_IsDelete,
    (process_method_func)daObjAjavW_Draw,
};

actor_process_profile_definition g_profile_Obj_AjavW = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 3,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_AjavW,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(daObjAjavW_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0056,
    /* Actor SubMtd */ &l_daObjAjavW_Method,
    /* Status       */ fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
