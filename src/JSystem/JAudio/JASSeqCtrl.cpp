//
// Generated by dtk
// Translation Unit: JASSeqCtrl.cpp
//

#include "JSystem/JAudio/JASSeqCtrl.h"
#include "JSystem/JUtility/JUTAssert.h"

/* 8027E3F8-8027E448       .text init__Q28JASystem8TSeqCtrlFv */
void JASystem::TSeqCtrl::init() {
    field_0x0 = NULL;
    field_0x4 = NULL;
    field_0x8 = 0;
    field_0xc = 0;
    for (int i = 0; i < 8; i++) {
        field_0x10[i] = NULL;
        field_0x30[i] = 0;
    }
    field_0x40 = 0;
    field_0x44 = NULL;
}

/* 8027E448-8027E45C       .text start__Q28JASystem8TSeqCtrlFPvUl */
void JASystem::TSeqCtrl::start(void* param_1, u32 param_2) {
    field_0x0 = (u8*)param_1;
    field_0x4 = field_0x0 + param_2;
}

/* 8027E45C-8027E500       .text loopEnd__Q28JASystem8TSeqCtrlFv */
int JASystem::TSeqCtrl::loopEnd() {
    /* Nonmatching */
    u32 var1 = field_0xc;
    if (var1 == 0) {
        JUT_WARN(45, "%s", "cannot loopE for call-stack is NULL");
        return 0;
    }
    u16 var3 = field_0x30[var1 - 1];
    if (var3) {
        var3--;
    }
    if (var3 == 0) {
        field_0xc--;
        return true;
    }
    field_0x30[var1 - 1] = var3;
    field_0x4 = field_0x10[field_0xc - 1];
    return true;
}

/* 8027E500-8027E530       .text waitCountDown__Q28JASystem8TSeqCtrlFv */
bool JASystem::TSeqCtrl::waitCountDown() {
    if (field_0x8 > 0) {
        field_0x8--;
        if (field_0x8) {
            return false;
        }
    }
    return true;
}

/* 8027E530-8027E568       .text callIntr__Q28JASystem8TSeqCtrlFPv */
bool JASystem::TSeqCtrl::callIntr(void* param_1) {
    if (field_0x44) {
        return false;
    }
    field_0x44 = field_0x4;
    field_0x4 = (u8*)param_1;
    field_0x40 = field_0x8;
    field_0x8 = 0;
    return true;
}

/* 8027E568-8027E59C       .text retIntr__Q28JASystem8TSeqCtrlFv */
bool JASystem::TSeqCtrl::retIntr() {
    if (!field_0x44) {
        return false;
    }
    field_0x8 = field_0x40;
    field_0x4 = field_0x44;
    field_0x44 = NULL;
    return true;
}

/* 8027E59C-8027E5B4       .text get16__Q28JASystem8TSeqCtrlCFUl */
u32 JASystem::TSeqCtrl::get16(u32 param_1) const {
    u32 result = field_0x0[param_1++] << 8;
    result |= field_0x0[param_1++];
    return result;
}

/* 8027E5B4-8027E5DC       .text get24__Q28JASystem8TSeqCtrlCFUl */
u32 JASystem::TSeqCtrl::get24(u32 param_1) const {
    /* Nonmatching */
    u32 result = field_0x0[param_1++] << 8;
    result |= field_0x0[param_1++];
    result <<= 8;
    result |= field_0x0[param_1++];
    return result;
}

/* 8027E5DC-8027E614       .text get32__Q28JASystem8TSeqCtrlCFUl */
u32 JASystem::TSeqCtrl::get32(u32 param_1) const {
    /* Nonmatching */
    u32 result = field_0x0[param_1++] << 8;
    result |= field_0x0[param_1++];
    result <<= 8;
    result |= field_0x0[param_1++];
    result <<= 8;
    result |= field_0x0[param_1++];
    return result;
}

/* 8027E614-8027E63C       .text read16__Q28JASystem8TSeqCtrlFv */
u32 JASystem::TSeqCtrl::read16() {
    u32 result = *(field_0x4++) << 8;
    result |= *(field_0x4++);
    return result;
}

/* 8027E63C-8027E680       .text read24__Q28JASystem8TSeqCtrlFv */
u32 JASystem::TSeqCtrl::read24() {
    u32 result = *(field_0x4++) << 8;
    result |= *(field_0x4++);
    result <<= 8;
    result |= *(field_0x4++);
    return result;
}
