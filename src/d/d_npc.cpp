//
// Generated by dtk
// Translation Unit: d_npc.cpp
//

#include "d/d_npc.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_player.h"
#include "f_op/f_op_actor_mng.h"
#include "f_op/f_op_msg_mng.h"
#include "SSystem/SComponent/c_math.h"
#include "JSystem/JGeometry.h"
#include "m_Do/m_Do_mtx.h"

// Needed for the .data section to match.
static Vec dummy_2100 = {1.0f, 1.0f, 1.0f};
static Vec dummy_2080 = {1.0f, 1.0f, 1.0f};

bool dNpc_JntCtrl_c::angCalcS(s16* out, s16 targetY, s16 speed, s16 maxVel) {
    s16 diff = *out - targetY;
    int origDiff = diff;
    cLib_addCalcAngleS(&diff, 0, speed, maxVel, 0x60);
    if(abs(diff) > speed) {
        *out += diff - origDiff;
    }
    else {
        *out = targetY;
    }

    return (s16)targetY - *out == 0;
}

void dNpc_JntCtrl_c::limitter(s16* targetDiff, s16 maxDiff, s16 minDiff) {
    if(*targetDiff > maxDiff) {
        *targetDiff = maxDiff;
    }
    if(*targetDiff < minDiff) {
        *targetDiff = minDiff;
    }
}

/* 8021A884-8021A97C       .text follow__14dNpc_JntCtrl_cFPsssi */
bool dNpc_JntCtrl_c::follow(s16* outY, s16 targetY, s16 maxVel, int param_4) {
    s16 origY = *outY;
    angCalcS(outY, targetY, 4, maxVel);
    s16 deltaY = *outY - origY;
    
    s16 sVar6 = 0;
    s16 sVar5 = 0;
    s16 sVar1 = targetY - *outY;
    for (int i = 1; i >= 0; i--) {
        sVar5 += mAngles[i][param_4];
        if ((deltaY > 0 && sVar5 > sVar1) || (deltaY < 0 && sVar5 < sVar1)) {
            mAngles[i][param_4] = sVar1 - sVar6;
            limitter(&mAngles[i][param_4], mMaxAngles[i][param_4], mMinAngles[i][param_4]);
        }
        sVar6 += mAngles[i][param_4];
    }
    
    return targetY != *outY;
}

/* 8021A97C-8021AABC       .text move__14dNpc_JntCtrl_cFsi */
void dNpc_JntCtrl_c::move(short, int) {
    /* Nonmatching */
}

/* 8021AABC-8021AC6C       .text lookAtTarget__14dNpc_JntCtrl_cFPsP4cXyz4cXyzssb */
void dNpc_JntCtrl_c::lookAtTarget(short*, cXyz*, cXyz, short, short, bool) {
    /* Nonmatching */
}

void dNpc_JntCtrl_c::setParam(s16 param_1, s16 maxSpineRot, s16 param_3, s16 minSpineRot, s16 param_5, s16 maxHeadRot, s16 param_7, s16 minHeadRot, s16 param_9) {
    mMaxAngles[1][0] = param_1;
    mMaxAngles[1][1] = maxSpineRot;
    mMinAngles[1][0] = param_3;
    mMinAngles[1][1] = minSpineRot;
    mMaxAngles[0][0] = param_5;
    mMaxAngles[0][1] = maxHeadRot;
    mMinAngles[0][0] = param_7;
    mMinAngles[0][1] = minHeadRot;
    field_0x22 = param_9;
    field_0x24 = param_9;
    field_0x1E = param_9;
    field_0x20 = param_9;
}

bool dNpc_PathRun_c::setInfDrct(dPath* pPath) {
    mPath = pPath;
    mCurrPointIndex = 0;

    return true;
}

bool dNpc_PathRun_c::setInf(u8 pathIdx, s8 roomNo, u8 forwards) {
    bool setPath = false;

    mPath = 0;
    mbGoingForwards = forwards;
    if(pathIdx != 0xFF) {
        mPath = dPath_GetRoomPath(pathIdx, roomNo);
        mCurrPointIndex = 0;

        setPath = true;
    }

    return setPath;
}

dPath* dNpc_PathRun_c::nextPath(s8 roomNo) {
    dPath* pPath = 0;

    if(mPath != 0) {
        pPath = dPath_GetNextRoomPath(mPath, roomNo);
    }

    return pPath;
}

cXyz dNpc_PathRun_c::getPoint(u8 pointIdx) {
    cXyz point(0.0f, 0.0f, 0.0f);

    if(mPath != 0 && pointIdx < mPath->m_num) {
        point = mPath->mpPnt[pointIdx].mPos;
    }

    return point;
}

/* 8021ADD0-8021AFA8       .text chkPointPass__14dNpc_PathRun_cF4cXyzb */
bool dNpc_PathRun_c::chkPointPass(cXyz currPos, bool goingForwards) {
    bool passed = false;
    if (mPath) {
        cXyz target;
        target.x = mPath->mpPnt[mCurrPointIndex].mPos.x;
        target.z = mPath->mpPnt[mCurrPointIndex].mPos.z;
        f32 deltaX;
        f32 deltaZ;
        if (mCurrPointIndex == 0) {
            deltaX = mPath->mpPnt[1].mPos.x - mPath->mpPnt[0].mPos.x;
            deltaZ = mPath->mpPnt[1].mPos.z - mPath->mpPnt[0].mPos.z;
        } else if (mCurrPointIndex == mPath->m_num - 1) {
            deltaX = mPath->mpPnt[mPath->m_num - 1].mPos.x - mPath->mpPnt[mPath->m_num - 2].mPos.x;
            deltaZ = mPath->mpPnt[mPath->m_num - 1].mPos.z - mPath->mpPnt[mPath->m_num - 2].mPos.z;
        } else {
            deltaX = mPath->mpPnt[mCurrPointIndex + 1].mPos.x - mPath->mpPnt[mCurrPointIndex - 1].mPos.x;
            deltaZ = mPath->mpPnt[mCurrPointIndex + 1].mPos.z - mPath->mpPnt[mCurrPointIndex - 1].mPos.z;
        }
        
        f32 f29 = cM_ssin(cM_atan2s(deltaX, deltaZ)) * (f32)0x7FFF;
        f32 f2 = cM_scos(cM_atan2s(deltaX, deltaZ)) * (f32)0x7FFF;
        f32 f3 = -(f29 * target.x + f2 * target.z);
        
        if (goingForwards) {
            passed = f29 * currPos.x + f2 * currPos.z + f3 > 0.0f;
        } else {
            passed = f29 * currPos.x + f2 * currPos.z + f3 <= 0.0f;
        }
    }
    return passed;
}

bool dNpc_PathRun_c::incIdx() {
    bool ret = true;

    if(mPath != 0) {
        mCurrPointIndex += 1;
        if(mCurrPointIndex >= mPath->m_num) {
            mCurrPointIndex = mPath->m_num - 1;
            ret = false;
        }
    }

    return ret;
}

bool dNpc_PathRun_c::incIdxLoop() {
    bool ret = true;

    if(mPath != 0) {
        mCurrPointIndex += 1;
        if(mCurrPointIndex >= mPath->m_num) {
            mCurrPointIndex = 0;
            ret = false;
        }
    }

    return ret;
}

bool dNpc_PathRun_c::incIdxAuto() {
    bool hitEnd = true;

    if(mPath != 0) {
        if(mPath->mLoops & 1) {
            mCurrPointIndex += 1;
            if(mCurrPointIndex >= mPath->m_num) {
                mCurrPointIndex = 0;
            }
        }
        else {
            mCurrPointIndex += 1;
            if(mCurrPointIndex >= mPath->m_num) {
                mCurrPointIndex = mPath->m_num - 1;
                hitEnd = false;
            }
        }
    }

    return hitEnd;
}

bool dNpc_PathRun_c::decIdx() {
    bool ret = true;

    if(mPath != 0) {
        mCurrPointIndex -= 1;
        if(mCurrPointIndex >= mPath->m_num) {
            mCurrPointIndex = 0;
            ret = false;
        }
    }

    return ret;
}

bool dNpc_PathRun_c::decIdxLoop() {
    bool ret = true;

    if(mPath != 0) {
        mCurrPointIndex -= 1;
        if(mCurrPointIndex >= mPath->m_num) {
            mCurrPointIndex = mPath->m_num - 1;
            ret = false;
        }
    }

    return ret;
}

bool dNpc_PathRun_c::decIdxAuto() {
    bool hitEnd = true;

    if(mPath != 0) {
        if(mPath->mLoops & 1) {
            mCurrPointIndex -= 1;
            if(mCurrPointIndex >= mPath->m_num) {
                mCurrPointIndex = mPath->m_num - 1;
            }
        }
        else {
            mCurrPointIndex -= 1;
            if(mCurrPointIndex >= mPath->m_num) {
                mCurrPointIndex = 0;
                hitEnd = false;
            }
        }
    }

    return hitEnd;
}

bool dNpc_PathRun_c::nextIdx() {
    bool hitEnd;

    if(mbGoingForwards) {
        hitEnd = incIdx();
        if(hitEnd == false) {
            decIdx();
        }
    }
    else {
        hitEnd = decIdx();
        if(hitEnd == false) {
            incIdx();
        }
    }

    return hitEnd;
}

bool dNpc_PathRun_c::nextIdxAuto() {
    bool hitEnd;

    if(mbGoingForwards) {
        hitEnd = incIdxAuto();
        if(hitEnd == 0) {
            decIdx();
        }
    }
    else {
        hitEnd = decIdxAuto();
        if(hitEnd == 0) {
            incIdx();
        }
    }

    return hitEnd;
}

s32 dNpc_PathRun_c::absIdx(u8 startIdx, u8 lastIdx) {
    if(mPath == 0) {
        return 0;
    }
    
    s32 diff_1 = startIdx - lastIdx;
    s32 diff_2 = lastIdx - startIdx;

    if(diff_1 < 0) {
        diff_1 += maxPoint(); 
    }
    if(diff_2 < 0) {
        diff_2 += maxPoint(); 
    }
    if(diff_1 > diff_2) {
        return diff_2;
    }

    return diff_1;
}

u8 dNpc_PathRun_c::maxPoint() {
    u8 max = 0xFF;
    if(mPath != 0) {
        max = mPath->m_num;
    }

    return max;
}

u8 dNpc_PathRun_c::pointArg(u8 idx) {
    u8 arg = 0;
    if(mPath != 0 && idx < (u8)mPath->m_num) {
        arg = mPath->mpPnt[idx].mArg3;
    }

    return arg;
}

bool dNpc_PathRun_c::setNearPathIndx(cXyz* param_1, f32 param_2) {
    bool set = false;
    if(mPath != 0) {
        f32 max_dist = 1000000000.0f;
        u8 pointIdx = 0;
        for(int i = 0; i < maxPoint(); i++) {
            cXyz point = getPoint(i);
    
            cXyz diff = (*param_1 - point);
            f32 xz_mag = diff.getMagXZ();
            f32 y_mag = param_2 * (diff.y * diff.y);
            f32 dist = sqrtf(y_mag + xz_mag);

            if(max_dist > dist) {
                max_dist = dist;
                pointIdx = i;
            }
        }

        mCurrPointIndex = pointIdx;
        set = true;
    }

    return set;
}

f32 dNpc_PathRun_c::setNearPathIndxMk(cXyz* param_1) {
    f32 max_dist;
    if(mPath != 0) {
        max_dist = 1000000000.0f;
        u8 pointIdx = 0;
        for(int i = 0; i < maxPoint(); i++) {
            cXyz point = getPoint(i);
            cXyz diff = (*param_1 - point);
            f32 temp = diff.getSquareMag();
            f32 dist = sqrtf(temp);
            if(max_dist > dist) {
                max_dist = dist;
                pointIdx = i;
            }
        }

        mCurrPointIndex = pointIdx;
    }

    return max_dist;
}

bool dNpc_PathRun_c::setNearPathIndxMk2(cXyz* param_1, u8 param_2, u8 param_3) {
    u8 pointIdx;
    bool set = false;
    if(mPath != 0) {
        f32 max_dist = 1000000000.0f;
        pointIdx = param_2;
        for(int i = 0; i < maxPoint(); i++) {
            cXyz point = getPoint(i);
            cXyz diff = (*param_1 - point);
            f32 temp = diff.getSquareMag();
            f32 dist = sqrtf(temp);
            s32 idx = absIdx(param_2, i);
            if(idx <= param_3 && param_2 != i && max_dist > dist) {
                max_dist = dist;
                pointIdx = i;
                set = true;
            }
        }

        mCurrPointIndex = pointIdx;
    }

    return set;
}

bool dNpc_PathRun_c::chkInside(cXyz* param_1) {
    cXyz point, point2, point3;

    setNearPathIndx(param_1, 0.0f);
    point2 = getPoint(mCurrPointIndex);
    decIdxLoop();
    point = getPoint(mCurrPointIndex);
    incIdxLoop();
    incIdxLoop();
    point3 = getPoint(mCurrPointIndex);

    s16 angle1 = cLib_targetAngleY(&point2, &point);
    s16 angle2 = cLib_targetAngleY(&point2, param_1);
    s16 angle3 = cLib_targetAngleY(&point2, &point3);

    s16 diff1 = angle2 - angle3;
    s16 diff2 = angle1 - angle3;
    if(diff1 > 0) {
        if(diff2 < 0 || diff1 < diff2) {
            return true;
        }
    }
    else if(diff2 < 0 && diff1 < diff2) {
        return true;
    }

    return false;
}

#include "d/d_npc_event_cut.inc"

void dNpc_EventCut_c::setActorInfo(char* staffName, fopAc_ac_c* pActor) {
    mpEvtStaffName = staffName;
    mpActor = pActor;
    mTargetActorPos.set(0.0f, 0.0f, 0.0f);
    mOffsetPos.set(0.0f, 0.0f, 0.0f);
    mPos.set(0.0f, 0.0f, 0.0f);
    mCurActIdx = -1;
}

void dNpc_EventCut_c::setActorInfo2(char* staffName, fopNpc_npc_c* pActor) {
    mpEvtStaffName = staffName;
    mpActor = pActor;
    mpTalkActor = pActor;
    mTargetActorPos.set(0.0f, 0.0f, 0.0f);
    mOffsetPos.set(0.0f, 0.0f, 0.0f);
    mPos.set(0.0f, 0.0f, 0.0f);
    mCurActIdx = -1;
}

bool dNpc_setAnmIDRes(mDoExt_McaMorf* pMorf, int loopMode, float morf, float speed, int animResId, int soundResId, const char* arcName) {
    void* pSoundAnimRes = 0;
    bool ret = false;

    if(pMorf != 0) {
        if(0 <= soundResId) {
            pSoundAnimRes = dComIfG_getObjectIDRes(arcName, soundResId);
        }

        void* pAnimRes = dComIfG_getObjectIDRes(arcName, animResId);
        pMorf->setAnm((J3DAnmTransform*)pAnimRes, loopMode, morf, speed, 0.0f, -1.0f, pSoundAnimRes);
        
        ret = true;
    }

    return ret;
}

bool dNpc_setAnmFNDirect(mDoExt_McaMorf* pMorf, int loopMode, f32 morf, f32 speed, char* animFilename, char* soundFilename, const char* arcName) {
    bool ret = false;

    if(pMorf != 0 && animFilename != 0 && arcName != 0) {
        void* pAnimRes = dComIfG_getObjectRes(arcName, animFilename);

        void* pSoundAnimRes = 0;
        if(soundFilename != 0) {
            pSoundAnimRes = dComIfG_getObjectRes(arcName, soundFilename);
        }

        pMorf->setAnm((J3DAnmTransform*)pAnimRes, loopMode, morf, speed, 0.0f, -1.0f, pSoundAnimRes);
        
        ret = true;
    }

    return ret;
}

bool dNpc_setAnm(mDoExt_McaMorf* pMorf, int loopMode, f32 morf, f32 speed, int animFileIdx, int soundFileIdx, const char* arcName) {
    void* pSoundAnimRes = 0;
    bool ret = false;

    if(pMorf != 0) {
        if(0 <= soundFileIdx) {
            pSoundAnimRes = dComIfG_getObjectRes(arcName, soundFileIdx);
        }

        void* pAnimRes = dComIfG_getObjectRes(arcName, animFileIdx);
        pMorf->setAnm((J3DAnmTransform*)pAnimRes, loopMode, morf, speed, 0.0f, -1.0f, pSoundAnimRes);
        
        ret = true;
    }

    return ret;
}

void dNpc_setShadowModel(J3DModel* param_1, J3DModelData* param_2, J3DModel* param_3) {
    for(int i = 0; i < param_2->getWEvlpMtxNum(); i++) {
        mDoMtx_copy(param_3->mpWeightEnvMtx[i], param_1->mpWeightEnvMtx[i]);
    }
    for(int i = 0; i < param_2->getJointNum(); i++) {
        mDoMtx_copy(param_3->mpNodeMtx[i], param_1->mpNodeMtx[i]);
    }
}

cXyz dNpc_playerEyePos(f32 param_1) {
    daPy_py_c* pPlayer = daPy_getPlayerActorClass();
    cXyz pos = pPlayer->getHeadTopPos();
    cXyz out;

    MtxTrans(pos.x, pos.y, pos.z, false);
    pos.set(0.0f, param_1, 0.0f);
    MtxPosition(&pos, &out);
    
    out.x = pPlayer->current.pos.x;
    out.z = pPlayer->current.pos.z;

    return out;
}

void dNpc_calc_DisXZ_AngY(cXyz param_1, cXyz param_2, float* param_3, short* param_4) {
    cXyz diff;
    diff.x = param_2.x - param_1.x;
    diff.z = param_2.z - param_1.z;

    if(param_3 != 0) {
        f32 dist = sqrtf(diff.x * diff.x + diff.z * diff.z);
        *param_3 = dist;
    }

    if(param_4 != 0) {
        *param_4 = cM_atan2s(diff.x, diff.z);
    }
}

bool dNpc_chkArasoi() {
    return dComIfGs_isEventBit(0x1220) && !dComIfGs_isEventBit(0x1808);
}

BOOL dNpc_chkLetterPassed() {
    BOOL ret = false;
    if(dComIfGs_isGetItemReserve(0xC)) {
        ret = dComIfGs_checkReserveItem(0x98) ? 0 : 1;
    }

    return ret;
}

void fopNpc_npc_c::setCollision(f32 radius, f32 height) {
    mCyl.SetC(current.pos);
    mCyl.SetR(radius);
    mCyl.SetH(height);
    dComIfG_Ccsp()->Set(&mCyl);
}

u16 fopNpc_npc_c::talk(int param_1) {
    u16 mode = 0xFF;

    if(mCurrMsgBsPcId == 0xFFFFFFFF) {
        if(param_1 == 1) {
            mCurrMsgID = getMsg();
        }

        mCurrMsgBsPcId = fopMsgM_messageSet(mCurrMsgID, this);
        mpCurrMsg = 0;
    }
    else {
        if(mpCurrMsg) {
            mode = mpCurrMsg->mMode;
            if(mode == dNpcMsgStts_MSG_DISPLAYED_e) {
                mpCurrMsg->mMode = next_msgStatus(&mCurrMsgID);
                if(mpCurrMsg->mMode == dNpcMsgStts_MSG_CONTINUES_e) {
                    fopMsgM_messageSet(mCurrMsgID);
                }
            }
            else if (mode == dNpcMsgStts_BOX_CLOSED_e) {
                mpCurrMsg->mMode = dNpcMsgStts_MSG_DESTROYED_e;
                mCurrMsgBsPcId = -1;
            }

            anmAtr(mode);
        }
        else {
            mpCurrMsg = fopMsgM_SearchByID(mCurrMsgBsPcId);
        }
    }

    return mode;
}

bool dNpc_setAnm_2(mDoExt_McaMorf* pMorf, int loopMode, f32 morf, f32 speed, int animFileIdx, int soundFileIdx, const char* arcName) {
    if(0 <= soundFileIdx) {
        void* pSoundAnimRes = dComIfG_getObjectRes(arcName, soundFileIdx);
        void* pAnimRes = dComIfG_getObjectRes(arcName, animFileIdx);
        
        pMorf->setAnm((J3DAnmTransform*)pAnimRes, loopMode, morf, speed, 0.0f, -1.0f, pSoundAnimRes);
    }
    else {
        void* pAnimRes = dComIfG_getObjectRes(arcName, animFileIdx);

        pMorf->setAnm((J3DAnmTransform*)pAnimRes, loopMode, morf, speed, 0.0f, -1.0f, 0);
    }


    return true;
}

void dNpc_HeadAnm_c::swing_vertical_init(s16 param_1, s16 param_2, s16 param_3, int param_4) {
    if(param_4 == 0 || mFunc != &swing_horizone) {
        field_0x1C = 0;
        field_0x20 = param_1;
        field_0x1E = param_2;
        field_0x14 = param_3;
        mFunc = &swing_vertical;
    }
}

/* 8021C2E8-8021C3C8       .text swing_vertical__14dNpc_HeadAnm_cFv */
void dNpc_HeadAnm_c::swing_vertical() {
    /* Nonmatching */
}

void dNpc_HeadAnm_c::swing_horizone_init(s16 param_1, s16 param_2, s16 param_3, int param_4) {
    if(param_4 == 0 || mFunc != &swing_vertical) {
        field_0x1C = 0;
        field_0x20 = param_1;
        field_0x1E = param_2;
        field_0x18 = param_3;
        mFunc = &swing_horizone;
    }
}

/* 8021C478-8021C55C       .text swing_horizone__14dNpc_HeadAnm_cFv */
void dNpc_HeadAnm_c::swing_horizone() {
    /* Nonmatching */
}

void dNpc_HeadAnm_c::move() {
    if(mFunc) {
        (this->*mFunc)();
    }
    else {
        cLib_addCalcAngleS(&field_0x00, 0, 4, 0x1000, 0x100);
        cLib_addCalcAngleS(&field_0x02, 0, 4, 0x1000, 0x100);
    }
}

/* 8021C5D8-8021C620       .text chkLim__14dNpc_JntCtrl_cFsii */
s32 dNpc_JntCtrl_c::chkLim(s16 param_1, int param_2, int param_3) {
    param_1 = cLib_maxLimit(param_1, mMaxAngles[param_2][param_3]);
    param_1 = cLib_minLimit(param_1, mMinAngles[param_2][param_3]);

    return param_1;
}

void dNpc_JntCtrl_c::turn_fromBackbone2Head(s16 param_1, s16* param_2, s16* param_3, bool param_4) {
    *param_3 = 0;
    if(field_0x0C == 0) {
        *param_3 = chkLim(param_1, 1, 1);
        if(field_0x32 && *param_3 < 0) {
            *param_3 = 0;
        }
    }
    
    *param_2 = 0;
    if(field_0x0B == 0) {
        *param_2 = param_1 - *param_3;
        *param_2 = chkLim(*param_2, 0, 1);
    }
}

void dNpc_JntCtrl_c::turn_fromHead2Backbone(s16 param_1, s16* param_2, s16* param_3) {
    *param_2 = 0;
    if(field_0x0B == 0) {
        *param_2 = param_1 - field_0x32;
        *param_2 = chkLim(*param_2, 0, 1);
    }

    *param_3 = 0;
    if(field_0x0C == 0) {
        *param_3 = param_1 - *param_2;
        *param_3 = chkLim(*param_3, 1, 1);
    }
}

s16 dNpc_JntCtrl_c::follow_current(s16* orig, s16 diff) {
    s16 angle = *orig;
    *orig -= diff;

    s16 ret = 0;
    if((angle > 0 && *orig < 0) || (angle < 0 && *orig > 0)) {
        ret = -*orig;
        *orig = 0;
    }
    
    return ret;
}

/* 8021C7D0-8021CAB8       .text lookAtTarget_2__14dNpc_JntCtrl_cFPsP4cXyz4cXyzssb */
void dNpc_JntCtrl_c::lookAtTarget_2(short*, cXyz*, cXyz, short, short, bool) {
    /* Nonmatching */
}

bool dNpc_chkAttn(fopAc_ac_c* i_this, cXyz destPos, float param_3, float param_4, float param_5, bool param_6) {
    s16 angle = cLib_targetAngleY(&i_this->current.pos, &destPos);
    f32 dist = sqrtf((i_this->current.pos - destPos).getMagXZ()); //this is gross but I haven't found a better way (temp destroys stack)
    s16 angle_diff = angle - i_this->current.angle.y;

    if(param_5 > 359.0f) {
        param_5 = 359.0f;
    }
    if (param_5 < 0.0f) {
        param_5 = 0.0f;
    }
    if(param_6) {
        param_3 += param_4;
    }

    bool ret = false;
    if(dist <= param_3 && abs(angle_diff) <= cM_deg2s(param_5)) {
        ret = true;
    }

    return ret;
}

dCcD_SrcCyl dNpc_cyl_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt Type     */ 0,
        /* SrcObjAt Atp      */ 0,
        /* SrcObjAt SPrm     */ 0,
        /* SrcObjTg Type     */ ~(AT_TYPE_BOOMERANG),
        /* SrcObjTg SPrm     */ 0x03,
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
        /* SrcGObjTg GFlag   */ 0x04,
        /* SrcGObjCo GFlag   */ 0,
    },
    // cM3dGCylS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 0.0f,
        /* Height */ 0.0f,
    },
};
