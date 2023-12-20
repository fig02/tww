//
// Generated by dtk
// Translation Unit: d_s_logo.cpp
//

#include "f_op/f_op_scene.h"
#include "f_op/f_op_scene_mng.h"
#include "c/c_dylink.h"
#include "d/d_com_inf_game.h"
#include "d/d_com_lib_game.h"
#include "d/d_procname.h"
#include "d/d_s_play.h"
#include "m_Do/m_Do_audio.h"
#include "m_Do/m_Do_controller_pad.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_graphic.h"
#include "m_Do/m_Do_machine.h"
#include "m_Do/m_Do_MemCard.h"
#include "m_Do/m_Do_Reset.h"
#include "m_Do/m_Do_dvd_thread.h"
#include "JSystem/JKernel/JKRExpHeap.h"
#include "JSystem/JKernel/JKRAram.h"
#include "JSystem/JKernel/JKRAramBlock.h"
#include "JSystem/JKernel/JKRAramHeap.h"
#include "dolphin/vi/vi.h"
#include "dolphin/os/OS.h"
#include "MSL_C/string.h"

class dScnLogo_c : public scene_class {
public:
    /* 0x1C4 */ request_of_phase_process_class mPhs;
    /* 0x1CC */ dDlst_2D_c * nintendoImg;
    /* 0x1D0 */ dDlst_2D_c * dolbyImg;
    /* 0x1D4 */ dDlst_2D_c * progchoiceImg;
    /* 0x1D8 */ dDlst_2D_c * progyesImg;
    /* 0x1DC */ dDlst_2D_c * prognoImg;
    /* 0x1E0 */ dDlst_2D_c * progImg;
    /* 0x1E4 */ dDlst_2D_c * interImg;
    /* 0x1E8 */ u8 mAction;
    /* 0x1E9 */ u8 mInterFlag;
    /* 0x1EA */ u8 field_0x1ea;
    /* 0x1EB */ u8 field_0x1eb;
    /* 0x1EC */ u16 mTimer;
    /* 0x1EE */ u16 field_0x1ee;
    /* 0x1F0 */ u16 field_0x1f0;
    /* 0x1F2 */ u16 field_0x1f2;
    /* 0x1F4 */ u16 field_0x1f4;
    /* 0x1F8 */ void * field_0x1f8;
    /* 0x1FC */ u32 field_0x1fc;
};

#if VERSION == VERSION_PAL
enum LOGO_RES_FILE_ID { // IDs and indexes are synced
    /* DAT */
    LOGO_BTI_NINTENDO_376X104=0x3,
    LOGO_BTI_PROGRESSIVE_CHOICE=0x4,
    LOGO_BTI_PROGRESSIVE_CHOICE_FR=0x5,
    LOGO_BTI_PROGRESSIVE_CHOICE_GM=0x6,
    LOGO_BTI_PROGRESSIVE_CHOICE_IT=0x7,
    LOGO_BTI_PROGRESSIVE_CHOICE_SP=0x8,
    LOGO_BTI_PROGRESSIVE_INTER=0x9,
    LOGO_BTI_PROGRESSIVE_INTER_FR=0xA,
    LOGO_BTI_PROGRESSIVE_INTER_GM=0xB,
    LOGO_BTI_PROGRESSIVE_INTER_IT=0xC,
    LOGO_BTI_PROGRESSIVE_INTER_SP=0xD,
    LOGO_BTI_PROGRESSIVE_NO=0xE,
    LOGO_BTI_PROGRESSIVE_NO_FR=0xF,
    LOGO_BTI_PROGRESSIVE_NO_GM=0x10,
    LOGO_BTI_PROGRESSIVE_NO_IT=0x11,
    LOGO_BTI_PROGRESSIVE_NO_SP=0x12,
    LOGO_BTI_PROGRESSIVE_PRO=0x13,
    LOGO_BTI_PROGRESSIVE_PRO_FR=0x14,
    LOGO_BTI_PROGRESSIVE_PRO_GM=0x15,
    LOGO_BTI_PROGRESSIVE_PRO_IT=0x16,
    LOGO_BTI_PROGRESSIVE_PRO_SP=0x17,
    LOGO_BTI_PROGRESSIVE_YES=0x18,
    LOGO_BTI_PROGRESSIVE_YES_FR=0x19,
    LOGO_BTI_PROGRESSIVE_YES_GM=0x1A,
    LOGO_BTI_PROGRESSIVE_YES_IT=0x1B,
    LOGO_BTI_PROGRESSIVE_YES_SP=0x1C,
    LOGO_BTI_TITLE_DOLBY_MARK=0x1D,
};
#else
enum LOGO_RES_FILE_ID { // IDs and indexes are synced
    /* DAT */
    LOGO_BTI_NINTENDO_376X104=0x3,
    LOGO_BTI_PROGRESSIVE_CHOICE=0x4,
    LOGO_BTI_PROGRESSIVE_INTER=0x5,
    LOGO_BTI_PROGRESSIVE_NO=0x6,
    LOGO_BTI_PROGRESSIVE_PRO=0x7,
    LOGO_BTI_PROGRESSIVE_YES=0x8,
    LOGO_BTI_TITLE_DOLBY_MARK=0x9,
};
#endif

mDoDvdThd_mountXArchive_c * l_anmCommand;
mDoDvdThd_mountXArchive_c * l_fmapCommand;
mDoDvdThd_mountXArchive_c * l_itemResCommand;
mDoDvdThd_mountXArchive_c * l_fmapResCommand;
mDoDvdThd_mountXArchive_c * l_dmapResCommand;
mDoDvdThd_mountXArchive_c * l_clctResCommand;
mDoDvdThd_mountXArchive_c * l_optResCommand;
mDoDvdThd_mountXArchive_c * l_saveResCommand;
mDoDvdThd_mountXArchive_c * l_clothResCommand;
mDoDvdThd_mountXArchive_c * l_itemiconCommand;
mDoDvdThd_mountXArchive_c * l_actioniconCommand;
mDoDvdThd_mountXArchive_c * l_scopeResCommand;
mDoDvdThd_mountXArchive_c * l_camResCommand;
mDoDvdThd_mountXArchive_c * l_swimResCommand;
mDoDvdThd_mountXArchive_c * l_windResCommand;
mDoDvdThd_mountXArchive_c * l_nameResCommand;
mDoDvdThd_mountXArchive_c * l_tmsgCommand;
mDoDvdThd_mountXArchive_c * l_dmsgCommand;
mDoDvdThd_mountXArchive_c * l_errorResCommand;
mDoDvdThd_mountXArchive_c * l_msgDtCommand;
#if VERSION != VERSION_JPN
mDoDvdThd_mountXArchive_c * l_msgDtCommand2;
#endif
mDoDvdThd_mountXArchive_c * l_msgCommand;
mDoDvdThd_mountXArchive_c * l_menuCommand;
mDoDvdThd_mountXArchive_c * l_fontCommand;
mDoDvdThd_mountXArchive_c * l_rubyCommand;
mDoDvdThd_toMainRam_c * l_particleCommand;
mDoDvdThd_toMainRam_c * l_itemTableCommand;
mDoDvdThd_toMainRam_c * l_ActorDataCommand;
mDoDvdThd_toMainRam_c * l_FmapDataCommand;
mDoDvdThd_mountXArchive_c * l_lodCommand;

enum {
    ACT_nintendoInDraw = 0,
    ACT_nintendoOutDraw = 1,
    ACT_nintendoOut2Draw = 2,
    ACT_dolbyInDraw = 3,
    ACT_dolbyOutDraw = 4,
    ACT_progInDraw = 5,
    ACT_progSelDraw = 6,
    ACT_progOutDraw = 7,
    ACT_progSetDraw = 8,
    ACT_progChangeDraw = 9,
    ACT_dvdWaitDraw = 10,
};

/* 8022C0B4-8022C130       .text checkProgSelect__FP10dScnLogo_c */
void checkProgSelect(dScnLogo_c* i_this) {
#if VERSION == VERSION_PAL
    if (OSGetResetCode() == 0 || OSGetResetCode() == 1) {
        if (OSGetEuRgb60Mode() == 1 || CPad_CHECK_HOLD_B(0)) {
            i_this->field_0x1ea = 1;
            i_this->mInterFlag = 0;
        }
    } else {
        i_this->field_0x1ea = 0;
    }
#else
    if (OSGetResetCode() == 0) {
        if (VIGetDTVStatus() != 0 && (OSGetProgressiveMode() == 1 || CPad_CHECK_HOLD_B(0))) {
            i_this->field_0x1ea = 1;
            i_this->mInterFlag = 0;
        }
    } else {
        i_this->field_0x1ea = 0;
    }
#endif
}

/* 8022C130-8022C1D8       .text nintendoInDraw__FP10dScnLogo_c */
BOOL nintendoInDraw(dScnLogo_c* i_this) {
    dComIfGd_set2DOpa(i_this->nintendoImg);
    if (i_this->mTimer == 0) {
        if (i_this->field_0x1ea != 0) {
            i_this->mAction = ACT_progInDraw;
            i_this->mTimer = 30;
        } else {
            i_this->mAction = ACT_nintendoOutDraw;
            i_this->mTimer = 30;
            mDoGph_gInf_c::startFadeOut(30);
        }
    }

    return TRUE;
}

/* 8022C1D8-8022C2AC       .text nintendoOutDraw__FP10dScnLogo_c */
BOOL nintendoOutDraw(dScnLogo_c* i_this) {
    dComIfGd_set2DOpa(i_this->nintendoImg);

    if (!i_this->mInterFlag)
        dComIfGd_set2DOpa(i_this->progImg);
    else
        dComIfGd_set2DOpa(i_this->interImg);

    if (i_this->mTimer == 0) {
        i_this->mAction = ACT_dolbyInDraw;
        i_this->mTimer = 90;
        mDoGph_gInf_c::startFadeIn(30);
    }

    return TRUE;
}

/* 8022C2AC-8022C35C       .text nintendoOut2Draw__FP10dScnLogo_c */
BOOL nintendoOut2Draw(dScnLogo_c* i_this) {
    dComIfGd_set2DOpa(i_this->nintendoImg);

    if (!i_this->mInterFlag)
        dComIfGd_set2DOpa(i_this->progImg);
    else
        dComIfGd_set2DOpa(i_this->interImg);

    if (i_this->mTimer == 0) {
        i_this->mAction = ACT_progChangeDraw;
        i_this->mTimer = 300;
    }

    return TRUE;
}

/* 8022C35C-8022C484       .text progInDraw__FP10dScnLogo_c */
BOOL progInDraw(dScnLogo_c* i_this) {
    dComIfGd_set2DOpa(i_this->nintendoImg);
    dComIfGd_set2DOpa(i_this->progchoiceImg);
    dComIfGd_set2DOpa(i_this->progyesImg);
    dComIfGd_set2DOpa(i_this->prognoImg);

    u8 alpha = (1.0f - (i_this->mTimer / 30.0f)) * 0xFF;
    i_this->progchoiceImg->setAlpha(alpha);
    i_this->progyesImg->setAlpha(alpha);
    i_this->prognoImg->setAlpha(alpha);

    if (i_this->mTimer == 0) {
        i_this->mAction = ACT_progSelDraw;
#if VERSION == VERSION_JPN
        i_this->mTimer = 300;
#else
        i_this->mTimer = 600;
#endif
        i_this->field_0x1ee = 30;
        i_this->field_0x1f0 = i_this->field_0x1ee;
        i_this->field_0x1f2 = 0;
        i_this->field_0x1eb = 0;
    }

    return TRUE;
}

/* 8022C484-8022CAA8       .text progSelDraw__FP10dScnLogo_c */
BOOL progSelDraw(dScnLogo_c* i_this) {
    dComIfGd_set2DOpa(i_this->nintendoImg);
    dComIfGd_set2DOpa(i_this->progchoiceImg);
    dComIfGd_set2DOpa(i_this->progyesImg);
    dComIfGd_set2DOpa(i_this->prognoImg);

    if (i_this->field_0x1eb == 0) {
        if (i_this->mInterFlag == 0) {
            if (CPad_CHECK_HOLD_RIGHT(0) || g_mDoCPd_cpadInfo[0].mMainStickPosX > 0.5f) {
                mDoAud_seStart(JA_SE_TALK_CURSOR);
                i_this->mInterFlag = 1;
                i_this->field_0x1ee = 30;
                i_this->field_0x1f0 = i_this->field_0x1ee;
                i_this->field_0x1f2 = 0;
            }
        } else {
            if (CPad_CHECK_HOLD_LEFT(0) || g_mDoCPd_cpadInfo[0].mMainStickPosX < -0.5f) {
                mDoAud_seStart(JA_SE_TALK_CURSOR);
                i_this->mInterFlag = 0;
                i_this->field_0x1ee = 30;
                i_this->field_0x1f0 = i_this->field_0x1ee;
                i_this->field_0x1f2 = 0;
            }
        }

        if (CPad_CHECK_TRIG_A(0) || i_this->mTimer == 0) {
            if (i_this->mInterFlag == 0)
                mDoAud_seStart(JA_SE_TALK_WIN_CLOSE);
            else
                mDoAud_seStart(JA_SE_TALK_SEL_CANCEL);

            const int temp = VERSION_SELECT(240, 540, 540);
            if (i_this->mTimer > temp) {
                i_this->field_0x1eb = 1;
                i_this->field_0x1f4 = i_this->mTimer - temp;
            } else {
                i_this->mAction = ACT_progOutDraw;
                i_this->mTimer = 30;
                i_this->field_0x1ee = 30;
                i_this->field_0x1f0 = i_this->field_0x1ee;
                i_this->field_0x1f2 = 0;
            }
        }
    } else {
        if (i_this->field_0x1f4 == 0) {
            i_this->mAction = ACT_progOutDraw;
            i_this->mTimer = 30;
            i_this->field_0x1ee = 30;
            i_this->field_0x1f0 = i_this->field_0x1ee;
            i_this->field_0x1f2 = 0;
        } else {
            i_this->field_0x1f4--;
        }
    }

    f32 t = (f32)i_this->field_0x1f0 / (f32)i_this->field_0x1ee;
    if (i_this->field_0x1f2 != 0)
        t = 1.0f - t;
    u8 selR = t * 0xFF;
    u8 selG = t * 0xC8;

    if (i_this->mInterFlag) {
        i_this->progyesImg->getPicture()->setWhite((GXColor){0xA0, 0xA0, 0xA0, 0xFF});
        i_this->progyesImg->getPicture()->setBlack((GXColor){0x00, 0x00, 0x00, 0x00});
        i_this->prognoImg->getPicture()->setWhite((GXColor){0xFF, 0xC8, 0x00, 0xFF});
        i_this->prognoImg->getPicture()->setBlack((GXColor){selR, selG, 0x00, 0x00});
    } else {
        i_this->progyesImg->getPicture()->setWhite((GXColor){0xFF, 0xC8, 0x00, 0xFF});
        i_this->progyesImg->getPicture()->setBlack((GXColor){selR, selG, 0x00, 0x00});
        i_this->prognoImg->getPicture()->setWhite((GXColor){0xA0, 0xA0, 0xA0, 0xFF});
        i_this->prognoImg->getPicture()->setBlack((GXColor){0x00, 0x00, 0x00, 0x00});
    }

    if (i_this->field_0x1f0 == 0) {
        i_this->field_0x1f0 = i_this->field_0x1ee;
        i_this->field_0x1f2 = i_this->field_0x1f2 ^ 1;
    } else {
        i_this->field_0x1f0--;
    }

    return TRUE;
}

/* 8022CAA8-8022CC54       .text progOutDraw__FP10dScnLogo_c */
BOOL progOutDraw(dScnLogo_c* i_this) {
    u8 alpha = (i_this->mTimer / 30.0f) * 0xFF;
    i_this->progchoiceImg->setAlpha(alpha);
    i_this->progyesImg->setAlpha(alpha);
    i_this->prognoImg->setAlpha(alpha);

    dComIfGd_set2DOpa(i_this->nintendoImg);
    dComIfGd_set2DOpa(i_this->progchoiceImg);
    dComIfGd_set2DOpa(i_this->progyesImg);
    dComIfGd_set2DOpa(i_this->prognoImg);

    if (i_this->mTimer == 0) {
#if VERSION == VERSION_PAL
        if (OSGetEuRgb60Mode() == 1 && !i_this->mInterFlag) {
#else
        if (OSGetProgressiveMode() && !i_this->mInterFlag) {
#endif
            i_this->mAction = ACT_nintendoOut2Draw;
            i_this->mTimer = 30;
            mDoGph_gInf_c::startFadeOut(30);
#if VERSION == VERSION_PAL
        } else if (OSGetEuRgb60Mode() == 0 && i_this->mInterFlag) {
#else
        } else if (!OSGetProgressiveMode() && i_this->mInterFlag) {
#endif
            i_this->mAction = ACT_nintendoOutDraw;
            i_this->mTimer = 30;
            mDoGph_gInf_c::startFadeOut(30);
        } else {
            i_this->mAction = ACT_progSetDraw;
#if VERSION != VERSION_USA
            i_this->mTimer = 300;
#else
            i_this->mTimer = 600;
#endif
            i_this->field_0x1f0 = 30;
        }
    }

    return TRUE;
}

/* 8022CC54-8022CDC8       .text progSetDraw__FP10dScnLogo_c */
BOOL progSetDraw(dScnLogo_c* i_this) {
    u8 alpha;
    if (i_this->field_0x1f0 != 0) {
        alpha = (1.0f - (i_this->field_0x1f0 / 30.0f)) * 0xFF;
        i_this->field_0x1f0--;
    } else {
        alpha = 0xFF;
    }

    i_this->progchoiceImg->setAlpha(alpha);
    i_this->progyesImg->setAlpha(alpha);
    i_this->prognoImg->setAlpha(alpha);

    dComIfGd_set2DOpa(i_this->nintendoImg);

    if (!i_this->mInterFlag) {
        i_this->progImg->setAlpha(alpha);
        dComIfGd_set2DOpa(i_this->progImg);
    } else {
        i_this->interImg->setAlpha(alpha);
        dComIfGd_set2DOpa(i_this->interImg);
    }

    if (i_this->mTimer == 0) {
        if (!i_this->mInterFlag) {
            i_this->mAction = ACT_nintendoOut2Draw;
        } else {
#if VERSION == VERSION_PAL
            OSSetEuRgb60Mode(0);
#else
            OSSetProgressiveMode(0);
#endif
            i_this->mAction = ACT_nintendoOutDraw;
        }

        i_this->mTimer = 30;
        mDoGph_gInf_c::startFadeOut(30);
    }

    return TRUE;
}

/* 8022CDC8-8022CE60       .text progChangeDraw__FP10dScnLogo_c */
BOOL progChangeDraw(dScnLogo_c* i_this) {
    if (i_this->mTimer == 299 && !i_this->mInterFlag) {
        mDoMch_render_c::setProgressiveMode();
#if VERSION == VERSION_PAL
        OSSetEuRgb60Mode(1);
#else
        OSSetProgressiveMode(1);
#endif
    }

    if (i_this->mTimer == 0) {
        i_this->mAction = 3;
        i_this->mTimer = 90;
        mDoGph_gInf_c::startFadeIn(30);
    }

    return TRUE;
}

/* 8022CE60-8022CEE8       .text dolbyInDraw__FP10dScnLogo_c */
BOOL dolbyInDraw(dScnLogo_c* i_this) {
    dComIfGd_set2DOpa(i_this->dolbyImg);

    if (i_this->mTimer == 0) {
        i_this->mAction = 4;
        i_this->mTimer = 30;
        mDoGph_gInf_c::startFadeOut(30);
    }

    return TRUE;
}

/* 8022CEE8-8022CF44       .text dolbyOutDraw__FP10dScnLogo_c */
BOOL dolbyOutDraw(dScnLogo_c* i_this) {
    dComIfGd_set2DOpa(i_this->dolbyImg);

    if (i_this->mTimer == 0) {
        i_this->mAction = 10;
    }

    return TRUE;
}

/* 8022CF44-8022D18C       .text dvdWaitDraw__FP10dScnLogo_c */
BOOL dvdWaitDraw(dScnLogo_c* i_this) {
    if (!dComIfG_syncAllObjectRes()
        && l_anmCommand->sync()
        && l_fmapCommand->sync()
        && l_itemResCommand->sync()
        && l_fmapResCommand->sync()
        && l_dmapResCommand->sync()
        && l_clctResCommand->sync()
        && l_optResCommand->sync()
        && l_saveResCommand->sync()
        && l_clothResCommand->sync()
        && l_itemiconCommand->sync()
        && l_actioniconCommand->sync()
        && l_scopeResCommand->sync()
        && l_camResCommand->sync()
        && l_swimResCommand->sync()
        && l_windResCommand->sync()
        && l_nameResCommand->sync()
        && l_tmsgCommand->sync()
        && l_dmsgCommand->sync()
        && l_errorResCommand->sync()
        && l_msgDtCommand->sync()
#if VERSION != VERSION_JPN
        && l_msgDtCommand2->sync()
#endif
        && l_msgCommand->sync()
        && l_menuCommand->sync()
        && l_fontCommand->sync()
        && l_rubyCommand->sync()
        && l_particleCommand->sync()
        && l_itemTableCommand->sync()
        && l_ActorDataCommand->sync()
        && l_FmapDataCommand->sync()
        && l_lodCommand->sync() && !mDoRst::isReset()) {

        dComIfG_changeOpeningScene(i_this, PROC_OPENING_SCENE);
    }
    return TRUE;
}

typedef BOOL(*drawFunc)(dScnLogo_c* i_this);

/* 8022D18C-8022D1DC       .text dScnLogo_Draw__FP10dScnLogo_c */
BOOL dScnLogo_Draw(dScnLogo_c* i_this) {
    static drawFunc l_execFunc[] = {
        nintendoInDraw,
        nintendoOutDraw,
        nintendoOut2Draw,
        dolbyInDraw,
        dolbyOutDraw,
        progInDraw,
        progSelDraw,
        progOutDraw,
        progSetDraw,
        progChangeDraw,
        dvdWaitDraw,
    };

    cLib_calcTimer(&i_this->mTimer);
    return l_execFunc[i_this->mAction](i_this);
}

/* 8022D1DC-8022D21C       .text dScnLogo_Execute__FP10dScnLogo_c */
BOOL dScnLogo_Execute(dScnLogo_c* i_this) {
    if (mDoRst::isReset())
        fopScnM_ChangeReq(i_this, PROC_LOGO_SCENE, 0, 5);
    return TRUE;
}

/* 8022D21C-8022D224       .text dScnLogo_IsDelete__FP10dScnLogo_c */
BOOL dScnLogo_IsDelete(dScnLogo_c* i_this) {
    return TRUE;
}

/* 8022D224-8022D984       .text dScnLogo_Delete__FP10dScnLogo_c */
BOOL dScnLogo_Delete(dScnLogo_c* i_this) {
    if (mDoRst::isReset())
        mDoRst_reset(0, 0x80000000, 0);

    delete i_this->nintendoImg;
    delete i_this->dolbyImg;
    delete i_this->progchoiceImg;
    delete i_this->progyesImg;
    delete i_this->prognoImg;
    delete i_this->progImg;
    delete i_this->interImg;

    dComIfGp_particle_createCommon(l_particleCommand->getMemAddress());

    dComIfGp_setAnmArchive(l_anmCommand->getArchive());
    dComIfGp_setFmapArchive(l_fmapCommand->getArchive());
    dComIfGp_setItemResArchive(l_itemResCommand->getArchive());
    dComIfGp_setFmapResArchive(l_fmapResCommand->getArchive());
    dComIfGp_setDmapResArchive(l_dmapResCommand->getArchive());
    dComIfGp_setClctResArchive(l_clctResCommand->getArchive());
    dComIfGp_setOptResArchive(l_optResCommand->getArchive());
    dComIfGp_setSaveResArchive(l_saveResCommand->getArchive());
    dComIfGp_setClothResArchive(l_clothResCommand->getArchive());
    dComIfGp_setItemIconArchive(l_itemiconCommand->getArchive());
    dComIfGp_setActionIconArchive(l_actioniconCommand->getArchive());
    dComIfGp_setScopeResArchive(l_scopeResCommand->getArchive());
    dComIfGp_setCamResArchive(l_camResCommand->getArchive());
    dComIfGp_setSwimResArchive(l_swimResCommand->getArchive());
    dComIfGp_setWindResArchive(l_windResCommand->getArchive());
    dComIfGp_setNameResArchive(l_nameResCommand->getArchive());
    dComIfGp_setTmsgArchive(l_tmsgCommand->getArchive());
    dComIfGp_setDmsgArchive(l_dmsgCommand->getArchive());
    dComIfGp_setErrorResArchive(l_errorResCommand->getArchive());
    dComIfGp_setMsgDtArchive(l_msgDtCommand->getArchive());
#if VERSION != VERSION_JPN
    dComIfGp_setMsgDt2Archive(l_msgDtCommand2->getArchive());
#endif
    dComIfGp_setMsgArchive(l_msgCommand->getArchive());
    dComIfGp_setMenuArchive(l_menuCommand->getArchive());
    dComIfGp_setFontArchive(l_fontCommand->getArchive());
    // dComIfGp_setRubyArchive(l_rubyCommand->getArchive());

    delete l_anmCommand;
    delete l_fmapCommand;
    delete l_itemResCommand;
    delete l_fmapResCommand;
    delete l_dmapResCommand;
    delete l_clctResCommand;
    delete l_optResCommand;
    delete l_saveResCommand;
    delete l_clothResCommand;
    delete l_itemiconCommand;
    delete l_actioniconCommand;
    delete l_scopeResCommand;
    delete l_camResCommand;
    delete l_swimResCommand;
    delete l_windResCommand;
    delete l_nameResCommand;
    delete l_tmsgCommand;
    delete l_dmsgCommand;
    delete l_errorResCommand;
    delete l_msgDtCommand;
#if VERSION != VERSION_JPN
    delete l_msgDtCommand2;
#endif
    delete l_msgCommand;
    delete l_menuCommand;
    delete l_fontCommand;
    delete l_rubyCommand;
    delete l_particleCommand;

    mDoExt_getMesgFont();
    mDoExt_getRubyFont();

#if VERSION == VERSION_JPN
    if (g_msgDHIO.field_0x08 == 0 && g_dComIfG_gameInfo.play.mpFont0Archive != NULL) {
        g_dComIfG_gameInfo.play.mpFont0Archive->unmount();
        g_dComIfG_gameInfo.play.mpFont0Archive = NULL;
    }
#endif

    dComIfGp_setItemTable(l_itemTableCommand->getMemAddress());
    delete l_itemTableCommand;

    dComIfGp_setActorData(l_ActorDataCommand->getMemAddress());
    dComIfGp_setFmapData(l_FmapDataCommand->getMemAddress());

    delete l_ActorDataCommand;
    delete l_FmapDataCommand;
    delete l_lodCommand;

    ResTIMG * timg = (ResTIMG *)dComIfG_getObjectRes("Always", ALWAYS_I4_BALL128B);
    g_dComIfG_gameInfo.drawlist.mShadowControl.setSimpleTex(timg);
    dComIfG_deleteObjectRes("Logo");
    dComIfGp_setWindowNum(0);

    for (s32 i = 0; i < 3; i++) {
        g_dComIfG_gameInfo.play.mAramHeap0[i] = JKRAram::getAramHeap()->alloc(0x2000, JKRAramHeap::HEAD);
        u8 mask = (1 << (u8)i);
        g_dComIfG_gameInfo.play.field_0x495b &= ~mask;
    }

    for (s32 i = 0; i < 4; i++) {
        g_dComIfG_gameInfo.play.mAramHeap1[i] = JKRAram::getAramHeap()->alloc(0x70, JKRAramHeap::HEAD);
    }

#if VERSION == VERSION_PAL
    g_dComIfG_gameInfo.play.field_0x4820 = JKRAram::getAramHeap()->alloc(0xB000, JKRAramHeap::HEAD);
#endif

    mDoExt_setSafeGameHeapSize();
    mDoExt_setSafeZeldaHeapSize();
    mDoExt_setSafeCommandHeapSize();
    mDoExt_setSafeArchiveHeapSize();

    return TRUE;
}

/* 8022D984-8022DB20       .text phase_0__FP10dScnLogo_c */
s32 phase_0(dScnLogo_c* i_this) {
#if VERSION != VERSION_PAL
    if (!OSGetResetCode()) {
        if (!VIGetDTVStatus())
            OSSetProgressiveMode(0);
    } else {
        if (OSGetProgressiveMode() == 1)
            mDoMch_render_c::setProgressiveMode();
    }
#endif

    if (!cDyl_InitAsyncIsDone())
        return cPhs_INIT_e;

    if (mDoAud_zelAudio_c::isInitFlag() && JAIZelBasic::getInterface()->checkFirstWaves())
        return cPhs_INIT_e;

#if VERSION == VERSION_PAL
    if (mDoDvdThd::SyncWidthSound == 0)
        return cPhs_INIT_e;
#endif

    s32 rt;
    
    rt = dComIfG_setObjectRes("System", JKRArchive::UNKNOWN_MOUNT_DIRECTION, NULL);

    JUT_ASSERT(VERSION_SELECT(1169, 1350, 1378), rt == 1);

    rt = dComIfG_setObjectRes("Logo", JKRArchive::MOUNT_DIRECTION_TAIL, NULL);
    JUT_ASSERT(VERSION_SELECT(1173, 1354, 1382), rt == 1);

#if VERSION == VERSION_PAL
    g_mDoMemCd_control.load2();
#endif

    i_this->field_0x1ea = 0;
    archiveHeap->dump_sort();
    return cPhs_NEXT_e;
}

/* 8022DB20-8022DC58       .text phase_1__FP10dScnLogo_c */
s32 phase_1(dScnLogo_c* i_this) {
    if (dComIfG_syncAllObjectRes() != 0)
        return cPhs_INIT_e;

#if VERSION == VERSION_PAL
    s32 rt = g_mDoMemCd_control.LoadSync2();
    if (rt == 0) {
        return cPhs_INIT_e;
    } else if (rt == 1) {
        if (g_mDoMemCd_control.field_0x165B >= 5) {
            g_mDoMemCd_control.field_0x165B = 0;
        }
        g_dComIfG_gameInfo.play.mGameLanguage = g_mDoMemCd_control.field_0x165B;
    } else {
        u8 language = OSGetLanguage();
        if (language >= 5) {
            language = 0;
        }
        g_dComIfG_gameInfo.play.mGameLanguage = language;
        g_mDoMemCd_control.field_0x165B = language;
    }
#endif

    ResTIMG * toonImage;

    toonImage = (ResTIMG *)dComIfG_getObjectRes("System", 3);

    JUT_ASSERT(VERSION_SELECT(1208, 1426, 1466), toonImage != 0);
    dDlst_list_c::mToonImage = toonImage;

    toonImage = (ResTIMG *)dComIfG_getObjectRes("System", 4);
    JUT_ASSERT(VERSION_SELECT(1213, 1431, 1471), toonImage != 0);
    dDlst_list_c::mToonExImage = toonImage;

    i_this->field_0x1f8 = mDoExt_getGameHeap()->alloc(0x3c8a0, 4);
    return cPhs_NEXT_e;
}

/* 8022DC58-8022DC80       .text aramMount__FPCc */
mDoDvdThd_mountXArchive_c * aramMount(const char* pArc) {
    return mDoDvdThd_mountXArchive_c::create(pArc, JKRArchive::UNKNOWN_MOUNT_DIRECTION, JKRArchive::MOUNT_ARAM);
}

/* 8022DC80-8022DCA8       .text onMemMount__FPCc */
mDoDvdThd_mountXArchive_c * onMemMount(const char* pArc) {
    return mDoDvdThd_mountXArchive_c::create(pArc, JKRArchive::UNKNOWN_MOUNT_DIRECTION, JKRArchive::MOUNT_MEM);
}

/* 8022DCA8-8022E9B4       .text phase_2__FP10dScnLogo_c */
s32 phase_2(dScnLogo_c* i_this) {
    s32 rt;
    
    rt = dComIfG_syncObjectRes("Logo");
    JUT_ASSERT(VERSION_SELECT(1251, 1469, 1509), rt >= 0);

    if (rt != 0)
        return cPhs_INIT_e;

    g_dComIfG_gameInfo.play.createParticle();

    ResTIMG * timg;
    
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", LOGO_BTI_NINTENDO_376X104);
    JUT_ASSERT(VERSION_SELECT(1264, 1482, 1522), timg != 0);
    i_this->nintendoImg = new dDlst_2D_c(timg, 133, 170, 0);
    JUT_ASSERT(VERSION_SELECT(1267, 1485, 1525), i_this->nintendoImg != 0);
    i_this->nintendoImg->setAlpha(0xFF);
#if VERSION == VERSION_JPN
    // Blue Nintendo logo for JPN.
    i_this->nintendoImg->getPicture()->setWhite((GXColor){0x00, 0x46, 0xFF, 0xFF});
#else
    // Red Nintendo logo for other regions.
    i_this->nintendoImg->getPicture()->setWhite((GXColor){0xDC, 0x00, 0x00, 0xFF});
#endif

    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", LOGO_BTI_TITLE_DOLBY_MARK);
    JUT_ASSERT(VERSION_SELECT(1276, 1498, 1538), timg != 0);
    i_this->dolbyImg = new dDlst_2D_c(timg, 218, 166, 0);
    JUT_ASSERT(VERSION_SELECT(1280, 1502, 1542), i_this->dolbyImg != 0);
    i_this->dolbyImg->setAlpha(0xFF);

#if VERSION == VERSION_PAL
    static const u8 choice[] = {
        LOGO_BTI_PROGRESSIVE_CHOICE,
        LOGO_BTI_PROGRESSIVE_CHOICE_GM,
        LOGO_BTI_PROGRESSIVE_CHOICE_FR,
        LOGO_BTI_PROGRESSIVE_CHOICE_SP,
        LOGO_BTI_PROGRESSIVE_CHOICE_IT,
    };
    static const u8 yes[] = {
        LOGO_BTI_PROGRESSIVE_YES,
        LOGO_BTI_PROGRESSIVE_YES_GM,
        LOGO_BTI_PROGRESSIVE_YES_FR,
        LOGO_BTI_PROGRESSIVE_YES_SP,
        LOGO_BTI_PROGRESSIVE_YES_IT,
    };
    static const u8 no[] = {
        LOGO_BTI_PROGRESSIVE_NO,
        LOGO_BTI_PROGRESSIVE_NO_GM,
        LOGO_BTI_PROGRESSIVE_NO_FR,
        LOGO_BTI_PROGRESSIVE_NO_SP,
        LOGO_BTI_PROGRESSIVE_NO_IT,
    };
    static const u8 prog[] = {
        LOGO_BTI_PROGRESSIVE_PRO,
        LOGO_BTI_PROGRESSIVE_PRO_GM,
        LOGO_BTI_PROGRESSIVE_PRO_FR,
        LOGO_BTI_PROGRESSIVE_PRO_SP,
        LOGO_BTI_PROGRESSIVE_PRO_IT,
    };
    static const u8 intr[] = {
        LOGO_BTI_PROGRESSIVE_INTER,
        LOGO_BTI_PROGRESSIVE_INTER_GM,
        LOGO_BTI_PROGRESSIVE_INTER_FR,
        LOGO_BTI_PROGRESSIVE_INTER_SP,
        LOGO_BTI_PROGRESSIVE_INTER_IT,
    };
#endif

#if VERSION == VERSION_PAL
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", choice[g_dComIfG_gameInfo.play.mGameLanguage]);
#else
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", LOGO_BTI_PROGRESSIVE_CHOICE);
#endif
    JUT_ASSERT(VERSION_SELECT(1286, 1565, 1605), timg != 0);
    i_this->progchoiceImg = new dDlst_2D_c(timg, 113, 281, 0);
    JUT_ASSERT(VERSION_SELECT(1288, 1567, 1607), i_this->progchoiceImg != 0);
    i_this->progchoiceImg->setAlpha(0x00);

#if VERSION == VERSION_PAL
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", yes[g_dComIfG_gameInfo.play.mGameLanguage]);
#else
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", LOGO_BTI_PROGRESSIVE_YES);
#endif
    JUT_ASSERT(VERSION_SELECT(1295, 1579, 1619), timg != 0);
    i_this->progyesImg = new dDlst_2D_c(timg, 211, 372, 0);
    JUT_ASSERT(VERSION_SELECT(1297, 1581, 1621), i_this->progyesImg != 0);
    i_this->progyesImg->getPicture()->setWhite((GXColor){0xFF, 0xC8, 0x00, 0xFF});
    i_this->progyesImg->setAlpha(0x00);

#if VERSION == VERSION_PAL
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", no[g_dComIfG_gameInfo.play.mGameLanguage]);
#else
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", LOGO_BTI_PROGRESSIVE_NO);
#endif
    JUT_ASSERT(VERSION_SELECT(1305, 1594, 1634), timg != 0);
    i_this->prognoImg = new dDlst_2D_c(timg, 350, 372, 0);
    JUT_ASSERT(VERSION_SELECT(1307, 1596, 1636), i_this->prognoImg != 0);
    i_this->prognoImg->getPicture()->setWhite((GXColor){0xA0, 0xA0, 0xA0, 0xFF});
    i_this->prognoImg->setAlpha(0x00);

#if VERSION == VERSION_PAL
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", prog[g_dComIfG_gameInfo.play.mGameLanguage]);
#else
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", LOGO_BTI_PROGRESSIVE_PRO);
#endif
    JUT_ASSERT(VERSION_SELECT(1315, 1609, 1649), timg != 0);
    i_this->progImg = new dDlst_2D_c(timg, 153, 309, 0);
    JUT_ASSERT(VERSION_SELECT(1317, 1611, 1651), i_this->progImg != 0);
    i_this->progImg->setAlpha(0x00);

#if VERSION == VERSION_PAL
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", intr[g_dComIfG_gameInfo.play.mGameLanguage]);
#else
    timg = (ResTIMG *)dComIfG_getObjectRes("Logo", LOGO_BTI_PROGRESSIVE_INTER);
#endif
    JUT_ASSERT(VERSION_SELECT(1324, 1623, 1663), timg != 0);
    i_this->interImg = new dDlst_2D_c(timg, 153, 309, 0);
    JUT_ASSERT(VERSION_SELECT(1326, 1625, 1665), i_this->interImg != 0);
    i_this->interImg->setAlpha(0x00);

    JKRHeap::free(i_this->field_0x1f8, NULL);

    l_lodCommand = aramMount("/res/Stage/sea/LODALL.arc");
    JUT_ASSERT(VERSION_SELECT(1346, 1645, 1685), l_lodCommand != 0);
    
    rt = dComIfG_setObjectRes("Always", JKRArchive::UNKNOWN_MOUNT_DIRECTION, NULL);
    JUT_ASSERT(VERSION_SELECT(1351, 1650, 1690), rt == 1);

    archiveHeap->dump_sort();

    rt = dComIfG_setObjectRes("Link", JKRArchive::UNKNOWN_MOUNT_DIRECTION, NULL);
    JUT_ASSERT(VERSION_SELECT(1356, 1655, 1695), rt == 1);

    rt = dComIfG_setObjectRes("Agb", JKRArchive::UNKNOWN_MOUNT_DIRECTION, NULL);
    JUT_ASSERT(VERSION_SELECT(1360, 1659, 1699), rt == 1);

    l_anmCommand = aramMount("/res/Object/LkAnm.arc");
    l_fmapCommand = aramMount("/res/Fmap/Fmap.arc");
    l_itemResCommand = aramMount("/res/Msg/itemres.arc");
    l_fmapResCommand = aramMount("/res/Msg/fmapres.arc");
    l_dmapResCommand = aramMount("/res/Msg/dmapres.arc");
    l_clctResCommand = aramMount("/res/Msg/clctres.arc");
    l_optResCommand = aramMount("/res/Msg/optres.arc");
    l_clothResCommand = aramMount("/res/Msg/clothres.arc");
    l_itemiconCommand = aramMount("/res/Msg/itemicon.arc");

#if VERSION == VERSION_PAL
    delete g_dComIfG_gameInfo.play.field_0x4820;
    char buf[40];
    sprintf(buf, "/res/Msg/data%d/acticon.arc", g_dComIfG_gameInfo.play.mGameLanguage);
    l_actioniconCommand = aramMount(buf);
#else
    l_actioniconCommand = aramMount("/res/Msg/acticon.arc");
#endif

    l_scopeResCommand = aramMount("/res/Msg/scoperes.arc");
    l_camResCommand = aramMount("/res/Msg/camres.arc");
    l_swimResCommand = onMemMount("/res/Msg/swimres.arc");
    l_windResCommand = aramMount("/res/Msg/windres.arc");
    l_nameResCommand = aramMount("/res/Msg/nameres.arc");
    l_tmsgCommand = aramMount("/res/Msg/tmsgres.arc");
    l_dmsgCommand = aramMount("/res/Msg/dmsgres.arc");
    l_errorResCommand = aramMount("/res/Msg/errorres.arc");
    l_saveResCommand = aramMount("/res/Msg/saveres.arc");

#if VERSION == VERSION_PAL
    sprintf(buf, "/res/Msg/data%d/bmgres.arc", g_dComIfG_gameInfo.play.mGameLanguage);
    l_msgDtCommand = onMemMount(buf);
#else
    l_msgDtCommand = onMemMount("/res/Msg/bmgres.arc");
#endif

#if VERSION != VERSION_JPN
    l_msgDtCommand2 = onMemMount("/res/Msg/bmgresh.arc");
#endif
    l_msgCommand = aramMount("/res/Msg/msgres.arc");
    l_menuCommand = onMemMount("/res/Msg/menures.arc");
#if VERSION == VERSION_JPN
    l_fontCommand = mDoDvdThd_mountXArchive_c::create("/res/Msg/fontres.arc", JKRArchive::MOUNT_DIRECTION_HEAD, JKRArchive::MOUNT_MEM);
#else
    l_fontCommand = onMemMount("/res/Msg/fontres.arc");
#endif
    l_rubyCommand = onMemMount("/res/Msg/rubyres.arc");
    l_particleCommand = mDoDvdThd_toMainRam_c::create("/res/Particle/common.jpc", JKRArchive::UNKNOWN_MOUNT_DIRECTION, g_dComIfG_gameInfo.play.getParticle()->getHeap());
    l_itemTableCommand = mDoDvdThd_toMainRam_c::create("/res/ItemTable/item_table.bin", JKRArchive::UNKNOWN_MOUNT_DIRECTION, NULL);
    JUT_ASSERT(VERSION_SELECT(1418, 1743, 1783), l_itemTableCommand != 0);
    l_ActorDataCommand = mDoDvdThd_toMainRam_c::create("/res/ActorDat/ActorDat.bin", JKRArchive::UNKNOWN_MOUNT_DIRECTION, NULL);
    JUT_ASSERT(VERSION_SELECT(1422, 1747, 1787), l_ActorDataCommand != 0);
    l_FmapDataCommand = mDoDvdThd_toMainRam_c::create("/res/FmapDat/FmapDat.bin", JKRArchive::UNKNOWN_MOUNT_DIRECTION, NULL);
    JUT_ASSERT(VERSION_SELECT(1426, 1751, 1791), l_FmapDataCommand != 0);

    JAIZelBasic::getInterface()->loadStaticWaves();
    mDoGph_gInf_c::setTickRate((OS_BUS_CLOCK / 4) / 60);
    mDoGph_gInf_c::waitBlanking(0);
    mDoGph_gInf_c::startFadeIn(30);
    i_this->mTimer = 90;

#if VERSION != VERSION_JPN
    mDoRst::offReset();
    mDoRst::offResetPrepare();
#endif

    JUTGamePad::clearResetOccurred();
    JUTGamePad::setResetCallback(mDoRst_resetCallBack, NULL);
    return cPhs_COMPLEATE_e;
}

/* 8022E9B4-8022E9F4       .text dScnLogo_Create__FP11scene_class */
s32 dScnLogo_Create(scene_class* i_scn) {
    static cPhs__Handler l_method[] = {
        (cPhs__Handler)phase_0,
        (cPhs__Handler)phase_1,
        (cPhs__Handler)phase_2,
    };

    dScnLogo_c * i_this = (dScnLogo_c *)i_scn;
    checkProgSelect(i_this);
    return dComLbG_PhaseHandler(&i_this->mPhs, l_method, i_this);
}

scene_method_class l_dScnLogo_Method = {
    (process_method_func)dScnLogo_Create,
    (process_method_func)dScnLogo_Delete,
    (process_method_func)dScnLogo_Execute,
    (process_method_func)dScnLogo_IsDelete,
    (process_method_func)dScnLogo_Draw,
};

scene_process_profile_definition g_profile_LOGO_SCENE = {
    fpcLy_ROOT_e,
    1,
    fpcPi_CURRENT_e,
    PROC_LOGO_SCENE,
    &g_fpcNd_Method.mBase,
    sizeof(dScnLogo_c),
    0,
    0,
    &g_fopScn_Method.mBase,
    &l_dScnLogo_Method,
    NULL,
};
