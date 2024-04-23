#ifndef RES_BDK_H
#define RES_BDK_H

#include "global.h"

enum BDK_RES_FILE_ID { // IDs and indexes are synced
    /* BAS */
    BDK_BAS_ATTACK1=0x7,
    BDK_BAS_BACK1=0x8,
    BDK_BAS_DAMAGE2=0x9,
    BDK_BAS_DEATH1=0xA,
    BDK_BAS_FLY1=0xB,
    BDK_BAS_FLY2=0xC,
    BDK_BAS_FLY3=0xD,
    BDK_BAS_JIDANDA1=0xE,
    BDK_BAS_JUMP1=0xF,
    BDK_BAS_LAST_DAMAGE1=0x10,
    BDK_BAS_LAST_DAMAGE2=0x11,
    BDK_BAS_LAST_DAMAGE3=0x12,
    BDK_BAS_SENKAI_L1=0x13,
    BDK_BAS_SENKAI_R1=0x14,
    BDK_BAS_S_DEMO2=0x15,
    BDK_BAS_TOBITATU1=0x16,
    BDK_BAS_TYAKUTI1=0x17,
    BDK_BAS_TYAKUTI_T1=0x18,
    BDK_BAS_WALK1=0x19,
    
    /* BCK */
    BDK_BCK_ATTACK1=0x1C,
    BDK_BCK_ATTACK_T1=0x1D,
    BDK_BCK_ATTACK_T2=0x1E,
    BDK_BCK_ATTACK_T3=0x1F,
    BDK_BCK_BACK1=0x20,
    BDK_BCK_DAMAGE1=0x21,
    BDK_BCK_DAMAGE2=0x22,
    BDK_BCK_DAMAGE3=0x23,
    BDK_BCK_DAMAGE4=0x24,
    BDK_BCK_DAMAGE_T1=0x25,
    BDK_BCK_DEATH1=0x26,
    BDK_BCK_DEATH2=0x27,
    BDK_BCK_DK_L_AKUBI1=0x28,
    BDK_BCK_DK_L_WAIT1=0x29,
    BDK_BCK_FLY1=0x2A,
    BDK_BCK_FLY2=0x2B,
    BDK_BCK_FLY3=0x2C,
    BDK_BCK_JIDANDA1=0x2D,
    BDK_BCK_JUMP1=0x2E,
    BDK_BCK_KAKKU1=0x2F,
    BDK_BCK_LAST_DAMAGE1=0x30,
    BDK_BCK_LAST_DAMAGE2=0x31,
    BDK_BCK_LAST_DAMAGE3=0x32,
    BDK_BCK_NUKENAI1=0x33,
    BDK_BCK_NUKU1=0x34,
    BDK_BCK_PIKUPIKU1=0x35,
    BDK_BCK_RAKKA_T1=0x36,
    BDK_BCK_SENKAI_L1=0x37,
    BDK_BCK_SENKAI_R1=0x38,
    BDK_BCK_S_DEMO1=0x39,
    BDK_BCK_S_DEMO2=0x3A,
    BDK_BCK_TOBITATU1=0x3B,
    BDK_BCK_TOBITATU_T1=0x3C,
    BDK_BCK_TO_DAMAGE_T1=0x3D,
    BDK_BCK_TYAKUTI1=0x3E,
    BDK_BCK_TYAKUTI_T1=0x3F,
    BDK_BCK_WAIT1=0x40,
    BDK_BCK_WAIT_T1=0x41,
    BDK_BCK_WALK1=0x42,
    
    /* BDL */
    BDK_BDL_BDK_HANE=0x45,
    BDK_BDL_BUHINA=0x46,
    BDK_BDL_BUHINB=0x47,
    BDK_BDL_BUHINC=0x48,
    BDK_BDL_BUHIND=0x49,
    BDK_BDL_DK=0x4A,
    BDK_BDL_DK_KAMEN4=0x4B,
    BDK_BDL_DK_TAIL=0x4C,
    BDK_BDL_GHANE00=0x4D,
    BDK_BDL_GROCK00=0x4E,
    BDK_BDL_SHAHENL=0x4F,
    BDK_BDL_SHAHENS=0x50,
    BDK_BDL_S_TSHUTTER=0x51,
    BDK_BDL_S_TTOGE=0x52,
    
    /* BVA */
    BDK_BVA_HIBIWARE1=0x55,
    
    /* DZB */
    BDK_DZB_S_TSHUTTER=0x58,
    BDK_DZB_S_TTOGE=0x59,
};

#endif /* RES_BDK_H */