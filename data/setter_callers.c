
==== depth 0: FUN_142b566d0 @ 142b566d0 (177 bytes)

void FUN_142b566d0(longlong param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  longlong lVar2;
  undefined4 *puVar3;
  int local_res10 [2];
  undefined4 local_res18;
  undefined4 auStack_48 [8];
  longlong local_28;
  int *local_20;
  
  puVar3 = auStack_48;
  for (lVar2 = 0x10; lVar2 != 0; lVar2 = lVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_28 = *(longlong *)(param_1 + 8);
  local_20 = (int *)(local_28 + (ulonglong)*(uint *)(param_1 + 0x18) * 4);
  local_res10[0] = param_2;
  local_res18 = param_3;
  piVar1 = (int *)FUN_142b54990(local_28,local_20,local_res10);
  if ((piVar1 != local_20) && (*piVar1 == local_res10[0])) {
    *(undefined4 *)(*(longlong *)(param_1 + 0x10) + ((longlong)piVar1 - local_28 >> 2) * 4) =
         local_res18;
  }
  return;
}


  referenced from 1452879c0 (DATA) in <no function>
  referenced from 142b566bb (UNCONDITIONAL_CALL) in FUN_142b56630 @ 142b56630
  referenced from 14162598d (UNCONDITIONAL_CALL) in FUN_141625930 @ 141625930
  referenced from 1416283ae (UNCONDITIONAL_CALL) in FUN_141628270 @ 141628270
  referenced from 1406a17e6 (UNCONDITIONAL_CALL) in FUN_1406a16a0 @ 1406a16a0
  referenced from 1408a757e (UNCONDITIONAL_CALL) in FUN_1408a74f0 @ 1408a74f0
  referenced from 1408963c1 (UNCONDITIONAL_CALL) in FUN_140895f90 @ 140895f90
  referenced from 14087adc1 (UNCONDITIONAL_CALL) in FUN_14087aca0 @ 14087aca0
  referenced from 1408a153c (UNCONDITIONAL_CALL) in FUN_1408a14b0 @ 1408a14b0
  referenced from 1408a12b2 (UNCONDITIONAL_CALL) in FUN_1408a11c0 @ 1408a11c0
  referenced from 1408e9f3e (UNCONDITIONAL_CALL) in FUN_1408e9d30 @ 1408e9d30
  referenced from 140928197 (UNCONDITIONAL_CALL) in FUN_140927b60 @ 140927b60
  referenced from 1409281c9 (UNCONDITIONAL_CALL) in FUN_140927b60 @ 140927b60
  referenced from 140928eaf (UNCONDITIONAL_CALL) in FUN_140928eaf @ 140928eaf
  referenced from 14092cc0b (UNCONDITIONAL_CALL) in FUN_14092bcd0 @ 14092bcd0
  referenced from 14092ef74 (UNCONDITIONAL_CALL) in FUN_14092ef27 @ 14092ef27
  referenced from 14092ef85 (UNCONDITIONAL_CALL) in FUN_14092ef27 @ 14092ef27
  referenced from 14093808e (UNCONDITIONAL_CALL) in FUN_140937cc0 @ 140937cc0
  referenced from 140938d4e (UNCONDITIONAL_CALL) in FUN_140938d00 @ 140938d00
  referenced from 140c51b07 (UNCONDITIONAL_CALL) in FUN_140c517d0 @ 140c517d0
  referenced from 140c52401 (UNCONDITIONAL_CALL) in FUN_140c51f10 @ 140c51f10
  referenced from 14137d9b1 (UNCONDITIONAL_CALL) in FUN_14137d953 @ 14137d953
  referenced from 14161fa66 (UNCONDITIONAL_CALL) in FUN_14161f7f7 @ 14161f7f7
  referenced from 14161ffa1 (UNCONDITIONAL_CALL) in FUN_14161ff90 @ 14161ff90
  referenced from 14162ade5 (UNCONDITIONAL_CALL) in FUN_14162aca0 @ 14162aca0
  referenced from 14092e7f3 (UNCONDITIONAL_CALL) in FUN_14092e7d8 @ 14092e7d8
  referenced from 14092e805 (UNCONDITIONAL_CALL) in FUN_14092e7d8 @ 14092e7d8
  referenced from 141622932 (UNCONDITIONAL_CALL) in <no function>
  referenced from 14162297d (UNCONDITIONAL_CALL) in <no function>

==== depth 1: FUN_142b56630 @ 142b56630 (154 bytes)

undefined8 FUN_142b56630(undefined8 param_1,undefined8 param_2)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 auStack_48 [8];
  uint local_28;
  longlong local_20;
  longlong local_18;
  uint local_10;
  
  puVar2 = auStack_48;
  for (lVar1 = 0x10; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_28 = FUN_142b56470(param_2);
  local_20 = FUN_142b56450(param_2);
  local_18 = FUN_142b56570(param_2);
  for (local_10 = 0; local_10 < local_28; local_10 = local_10 + 1) {
    FUN_142b566d0(param_1,*(undefined4 *)(local_20 + (ulonglong)local_10 * 4),
                  *(undefined4 *)(local_18 + (ulonglong)local_10 * 4));
  }
  return CONCAT71((uint7)(uint3)(local_28 >> 8),1);
}


  referenced from 1452879b4 (DATA) in <no function>
  referenced from 142b5cf33 (UNCONDITIONAL_CALL) in FUN_142b5ce00 @ 142b5ce00
  referenced from 142b5cfa9 (UNCONDITIONAL_CALL) in FUN_142b5ce00 @ 142b5ce00
  referenced from 142b5d007 (UNCONDITIONAL_CALL) in FUN_142b5ce00 @ 142b5ce00
  referenced from 142b5c59d (UNCONDITIONAL_CALL) in FUN_142b5c550 @ 142b5c550

==== depth 1: FUN_141625930 @ 141625930 (162 bytes)

/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffffd8 : 0x000141625985 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_141625930(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  longlong *plVar1;
  longlong lVar2;
  undefined4 local_res18 [2];
  
  local_res18[0] = param_3;
  lVar2 = FUN_142b56080(local_res18,1,DAT_144e2e5f0);
  if (lVar2 != 0) {
    FUN_142b566d0(lVar2,local_res18[0],param_4);
    thunk_FUN_142b50b00(param_2,lVar2);
    plVar1 = DAT_144e2e5f0;
    FUN_142b550a0(lVar2);
    (**(code **)(*plVar1 + 0x68))(plVar1,lVar2);
  }
  FUN_145b3f52b();
  return;
}


  referenced from 14514d6e0 (DATA) in <no function>
  referenced from 14487b9d0 (DATA) in <no function>
  referenced from 14487b9e0 (DATA) in <no function>
  referenced from 14162ac66 (UNCONDITIONAL_CALL) in FUN_14162ab10 @ 14162ab10
  referenced from 141627e36 (UNCONDITIONAL_CALL) in FUN_141627db0 @ 141627db0

==== depth 1: FUN_141628270 @ 141628270 (375 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

longlong FUN_141628270(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  undefined1 auStack_98 [32];
  float local_78 [6];
  undefined4 local_60 [6];
  ulonglong local_48;
  
  local_48 = DAT_144d9ff50 ^ (ulonglong)auStack_98;
  uVar3 = 0;
  local_60[1] = 10000;
  local_60[0] = 0;
  local_60[2] = 30000;
  local_60[3] = 0x7531;
  local_60[4] = 3;
  lVar1 = thunk_FUN_142b56080(local_60,5,param_2);
  fVar5 = DAT_144241500;
  if (lVar1 != 0) {
    fVar6 = 0.0;
    if ((DAT_144e03a08 != 0) && (lVar2 = FUN_14047caa0(), lVar2 != 0)) {
      local_78[0] = DAT_1442415bc;
      local_78[1] = 0.0;
      local_78[2] = 1.0;
      fVar6 = local_78[*(byte *)(lVar2 + 0x10)];
    }
    local_78[0] = (float)FUN_141625fd0(param_3);
    local_78[1] = fVar6;
    local_78[2] = *(float *)(param_1 + 0x25c);
    if (*(float *)(param_1 + 0x25c) <= 0.0) {
      local_78[2] = fVar5;
    }
    local_78[3] = *(float *)(param_1 + 0x260);
    if (*(float *)(param_1 + 0x260) <= 0.0) {
      local_78[3] = fVar5;
    }
    if (*(char *)(param_1 + 0xb2) == '\0') {
      fVar5 = 0.0;
    }
    puVar4 = local_60;
    local_78[4] = fVar5;
    do {
      FUN_142b566d0(lVar1,*puVar4,local_78[(int)uVar3]);
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < 5);
  }
  return lVar1;
}


  referenced from 14514d8c0 (DATA) in <no function>
  referenced from 14487b974 (DATA) in <no function>
  referenced from 14487b9a8 (DATA) in <no function>
  referenced from 14162435a (UNCONDITIONAL_CALL) in FUN_1416242c0 @ 1416242c0
  referenced from 14162461a (UNCONDITIONAL_CALL) in FUN_141624580 @ 141624580
  referenced from 141629672 (UNCONDITIONAL_CALL) in FUN_1416295a0 @ 1416295a0
  referenced from 14162a676 (UNCONDITIONAL_CALL) in FUN_14162a650 @ 14162a650
  referenced from 1416248da (UNCONDITIONAL_CALL) in FUN_141624840 @ 141624840

==== depth 1: FUN_1406a16a0 @ 1406a16a0 (426 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1406a16a0(longlong param_1)

{
  longlong lVar1;
  char cVar2;
  undefined8 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 auStack_b8 [32];
  float local_98 [4];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 local_58 [48];
  float local_28 [4];
  ulonglong local_18;
  
  local_18 = DAT_144d9ff50 ^ (ulonglong)auStack_b8;
  puVar3 = (undefined8 *)FUN_1406947e0(local_58,param_1 + 0x30,param_1 + 0x40);
  local_88 = *puVar3;
  uStack_80 = puVar3[1];
  local_78 = *(undefined4 *)(puVar3 + 2);
  uStack_74 = *(undefined4 *)((longlong)puVar3 + 0x14);
  uStack_70 = *(undefined4 *)(puVar3 + 3);
  uStack_6c = *(undefined4 *)((longlong)puVar3 + 0x1c);
  local_68 = *(undefined4 *)(puVar3 + 4);
  uStack_64 = *(undefined4 *)((longlong)puVar3 + 0x24);
  uStack_60 = *(undefined4 *)(puVar3 + 5);
  uStack_5c = *(undefined4 *)((longlong)puVar3 + 0x2c);
  FUN_142b50bf0(param_1 + 0x410,&local_88);
  FUN_142b50bf0(param_1 + 0x700,&local_88);
  cVar2 = FUN_142b501b0(param_1 + 0x410);
  if ((cVar2 != '\0') && (*(longlong *)(param_1 + 0x118) != 0)) {
    local_28[0] = *(float *)(param_1 + 0x1c8);
    local_28[1] = *(float *)(param_1 + 0x1c4) - (local_28[0] + local_28[0]);
    uVar6 = FUN_14307a3ec(*(float *)(param_1 + 0x80) * *(float *)(param_1 + 0x80) +
                          *(float *)(param_1 + 0x84) * *(float *)(param_1 + 0x84) +
                          *(float *)(param_1 + 0x88) * *(float *)(param_1 + 0x88));
    FUN_1416d11d0(local_98,uVar6);
    puVar5 = &DAT_1437c1810;
    uVar4 = 0;
    local_28[2] = (local_98[0] * DAT_14371c6dc * DAT_14371c6dc) / DAT_144241584;
    do {
      FUN_142b566d0(*(undefined8 *)(param_1 + 0x118),*puVar5,local_28[(int)uVar4]);
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar4 < 3);
    lVar1 = *(longlong *)(param_1 + 0x118);
    if (lVar1 != 0) {
      cVar2 = FUN_142b501b0(param_1 + 0x410);
      if (cVar2 != '\0') {
        thunk_FUN_142b50b00(param_1 + 0x410,lVar1);
      }
    }
  }
  return;
}


  referenced from 1450548c0 (DATA) in <no function>
  referenced from 1443a13ec (DATA) in <no function>
  referenced from 1443a13fc (DATA) in <no function>
  referenced from 14069b07f (UNCONDITIONAL_CALL) in FUN_14069a170 @ 14069a170
  referenced from 14069f474 (UNCONDITIONAL_CALL) in FUN_14069ecb0 @ 14069ecb0
  referenced from 14068d5db (UNCONDITIONAL_CALL) in FUN_14068d340 @ 14068d340
  referenced from 14069042b (UNCONDITIONAL_CALL) in FUN_1406903a0 @ 1406903a0
  referenced from 14069fd97 (UNCONDITIONAL_CALL) in FUN_14069f930 @ 14069f930
  referenced from 1406a0cdb (UNCONDITIONAL_CALL) in FUN_1406a0c40 @ 1406a0c40
  referenced from 1406a1548 (UNCONDITIONAL_CALL) in FUN_1406a0e60 @ 1406a0e60
  referenced from 1406a0dd4 (UNCONDITIONAL_CALL) in FUN_1406a0d10 @ 1406a0d10
  referenced from 1406a0e33 (UNCONDITIONAL_CALL) in FUN_1406a0e00 @ 1406a0e00
  referenced from 1406ad5bd (UNCONDITIONAL_CALL) in FUN_1406ad1a0 @ 1406ad1a0

==== depth 1: FUN_1408a74f0 @ 1408a74f0 (343 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1408a74f0(longlong param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  undefined1 auStack_358 [32];
  undefined8 local_338;
  undefined4 local_330;
  undefined4 local_328;
  undefined4 local_318;
  undefined4 local_314;
  undefined8 local_310;
  undefined8 local_308;
  undefined4 *local_300;
  undefined1 local_2f8 [32];
  undefined1 local_2d8 [704];
  ulonglong local_18;
  
  local_310 = 0xfffffffffffffffe;
  local_18 = DAT_144d9ff50 ^ (ulonglong)auStack_358;
  local_314 = 0;
  local_308 = param_2;
  if (*(longlong *)(param_1 + 0x380) == 0) {
    uVar1 = FUN_142b56080(&DAT_14381bb28,1,DAT_144e2e5e8);
    *(undefined8 *)(param_1 + 0x380) = uVar1;
  }
  if (*(longlong *)(param_1 + 0x380) != 0) {
    local_318 = *(undefined4 *)(param_1 + 0x20);
    FUN_142b566d0(*(longlong *)(param_1 + 0x380),70000,local_318);
  }
  local_300 = &local_318;
  local_318 = param_3;
  if (DAT_144e29820 == 0) {
    uVar1 = FUN_14292a3b0(&DAT_144e00bcb);
                    /* WARNING: Subroutine does not return */
    FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                  ,0xb4,&DAT_144234158,uVar1);
  }
  local_328 = 0;
  local_330 = 8;
  local_338 = *(undefined8 *)(param_1 + 0x380);
  uVar1 = FUN_1416246f0(DAT_144e29820,local_2f8,&local_318,param_1 + 0x50);
  FUN_1408a0410(param_2,uVar1);
  local_314 = 1;
  FUN_14268d730(local_2d8);
  FUN_142b4fcb0(local_2f8);
  return param_2;
}


  referenced from 14506ff5c (DATA) in <no function>
  referenced from 1443ffa80 (DATA) in <no function>
  referenced from 1408a7776 (UNCONDITIONAL_CALL) in FUN_1408a7720 @ 1408a7720
  referenced from 1408a6c55 (UNCONDITIONAL_CALL) in FUN_1408a6b40 @ 1408a6b40
  referenced from 1408a6c92 (UNCONDITIONAL_CALL) in FUN_1408a6b40 @ 1408a6b40

==== depth 1: FUN_140895f90 @ 140895f90 (1290 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff18 : 0x0001408963b3 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_140895f90(longlong param_1,longlong param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  ushort uVar5;
  longlong lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  float *pfVar9;
  float *pfVar10;
  longlong lVar11;
  byte bVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined1 auStack_108 [32];
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc [5];
  undefined8 *local_c8;
  undefined4 local_c0;
  ulonglong local_b8;
  
  local_dc[1] = -NAN;
  local_dc[2] = -NAN;
  local_b8 = DAT_144d9ff50 ^ (ulonglong)auStack_108;
  if (*(longlong *)(param_1 + 0x38) != *(longlong *)(param_1 + 0x40)) {
    lVar6 = FUN_140835a20();
    uVar7 = *(undefined8 *)(*(longlong *)(lVar6 + 800) + 0x118);
    if (DAT_144e25d60 == 0) {
      uVar7 = FUN_14292a3b0(&DAT_144e00a05);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar7);
    }
    lVar6 = FUN_1415838d0(DAT_144e25d60,1);
    uVar4 = *(ushort *)(lVar6 + 0x23c);
    if (DAT_144e25d60 == 0) {
      uVar7 = FUN_14292a3b0(&DAT_144e00a05);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar7);
    }
    lVar6 = FUN_1415838d0(DAT_144e25d60,1);
    uVar5 = *(ushort *)(lVar6 + 0x23e);
    uVar8 = FUN_140845b10(uVar7,&local_c8);
    pfVar9 = (float *)FUN_1416d1470(uVar8,&local_e8);
    fVar3 = DAT_144241500;
    local_e8 = 1.0;
    local_dc[0] = 0.0;
    local_e0 = 0.0001;
    local_e4 = (float)uVar5 - (float)uVar4;
    pfVar10 = &local_e4;
    if (local_e4 <= DAT_14371d094) {
      pfVar10 = &local_e0;
    }
    local_e0 = ((*pfVar9 * DAT_14371c6dc * DAT_14371c6dc) / DAT_144241584 - (float)uVar4) / *pfVar10
    ;
    if (0.0 <= local_e0) {
      pfVar10 = &local_e8;
      if (local_e0 <= DAT_144241500) {
        pfVar10 = &local_e0;
      }
    }
    else {
      pfVar10 = local_dc;
    }
    fVar1 = *pfVar10;
    if (DAT_144e25d60 == 0) {
      uVar7 = FUN_14292a3b0(&DAT_144e00a05);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar7);
    }
    lVar6 = FUN_1415838d0(DAT_144e25d60,1);
    fVar16 = *(float *)(lVar6 + 0x238);
    local_c8 = &DAT_1442344c0;
    local_c0 = DAT_1442414e4;
    fVar13 = (float)FUN_14083f490(uVar7,&local_c8);
    local_c8 = (undefined8 *)&DAT_1442344c8;
    local_e8 = fVar13;
    local_dc[0] = (float)FUN_140848910(uVar7);
    local_e4 = 1.0;
    local_e0 = 0.0;
    pfVar10 = &local_e8;
    if (fVar13 <= local_dc[0]) {
      pfVar10 = local_dc;
    }
    if (0.0 <= *pfVar10) {
      pfVar9 = &local_e4;
      if (*pfVar10 <= fVar3) {
        pfVar9 = pfVar10;
      }
    }
    else {
      pfVar9 = &local_e0;
    }
    fVar16 = (fVar3 - fVar16) * *pfVar9 + fVar16;
    if (DAT_144e25d60 == 0) {
      uVar7 = FUN_14292a3b0(&DAT_144e00a05);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar7);
    }
    lVar6 = FUN_1415838d0(DAT_144e25d60,1);
    fVar13 = *(float *)(lVar6 + 0x22c) * DAT_1442414a0 * *(float *)(param_2 + 8);
    if (DAT_144e25d60 == 0) {
      uVar7 = FUN_14292a3b0(&DAT_144e00a05);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar7);
    }
    lVar6 = FUN_1415838d0(DAT_144e25d60,1);
    fVar15 = *(float *)(lVar6 + 0x230);
    fVar2 = *(float *)(param_2 + 8);
    lVar6 = FUN_140835a20(param_1);
    fVar14 = (float)FUN_140703350(*(undefined8 *)(lVar6 + 0x80));
    local_dc[0] = 1.0;
    local_e8 = 0.0;
    local_e0 = fVar15 * DAT_1442414a0 * fVar2 - fVar13;
    local_e4 = ABS(fVar14);
    if (local_e0 <= DAT_14371d094) {
      local_e0 = DAT_14371d094;
    }
    local_e0 = (local_e4 - fVar13) / local_e0;
    if (0.0 <= local_e0) {
      pfVar10 = local_dc;
      if (local_e0 <= fVar3) {
        pfVar10 = &local_e0;
      }
    }
    else {
      pfVar10 = &local_e8;
    }
    fVar3 = *pfVar10;
    fVar15 = fVar16 * fVar1 * fVar3;
    local_e8 = fVar15 * DAT_144241568;
    local_dc[0] = 1.0;
    FUN_142b566d0(*(undefined8 *)(param_1 + 200),DAT_1438178f4,local_e8);
    lVar6 = *(longlong *)(param_1 + 0x40);
    bVar12 = 0;
    lVar11 = *(longlong *)(param_1 + 0x38);
    fVar13 = 0.0;
    if (lVar11 != lVar6) {
      do {
        FUN_1408936b0(lVar11,fVar15,fVar14,param_2);
        bVar12 = bVar12 | *(byte *)(lVar11 + 0xc);
        lVar11 = lVar11 + 0x28;
      } while (lVar11 != lVar6);
      if (bVar12 != 0) {
        fVar13 = fVar15;
      }
    }
    lVar6 = FUN_140835a20(param_1);
    lVar6 = **(longlong **)(lVar6 + 800) + 0x90;
    if (DAT_144cb9770 == '\0') {
      FUN_14072ffb0(lVar6,0xc,(int)fVar13);
    }
    else if (DAT_144cb9770 == '\x01') {
      FUN_140730070(lVar6,0xc,fVar13);
    }
    *(float *)(param_1 + 0x13c) = fVar1;
    *(float *)(param_1 + 0x140) = fVar3;
    *(float *)(param_1 + 0x144) = fVar16;
    *(float *)(param_1 + 0x148) = fVar15;
  }
  return;
}


  referenced from 14506f29c (DATA) in <no function>
  referenced from 1443fc478 (DATA) in <no function>
  referenced from 140893393 (UNCONDITIONAL_CALL) in FUN_140893330 @ 140893330

==== depth 1: FUN_14087aca0 @ 14087aca0 (394 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_14087aca0(undefined8 param_1,undefined8 param_2,longlong param_3)

{
  float fVar1;
  longlong lVar2;
  char cVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined1 auStack_88 [32];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  float local_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float local_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float local_28 [4];
  ulonglong local_18;
  
  local_18 = DAT_144d9ff50 ^ (ulonglong)auStack_88;
  local_68 = *(undefined8 *)(param_3 + 0x30);
  uStack_60 = *(undefined8 *)(param_3 + 0x38);
  local_58 = *(undefined8 *)(param_3 + 0x40);
  uStack_50 = *(undefined8 *)(param_3 + 0x48);
  local_48 = *(float *)(param_3 + 0x50);
  fStack_44 = *(float *)(param_3 + 0x54);
  fStack_40 = *(float *)(param_3 + 0x58);
  fStack_3c = *(float *)(param_3 + 0x5c);
  local_38 = *(float *)(param_3 + 0x60);
  fStack_34 = *(float *)(param_3 + 100);
  fStack_30 = *(float *)(param_3 + 0x68);
  fStack_2c = *(float *)(param_3 + 0x6c);
  cVar3 = FUN_142b501b0(param_3 + 0x90);
  if (cVar3 != '\0') {
    if (*(char *)(param_3 + 900) != '\0') {
      fVar1 = *(float *)(param_3 + 0xc);
      local_38 = local_38 + fVar1 * local_48;
      fStack_34 = fStack_34 + fVar1 * fStack_44;
      fStack_30 = fStack_30 + fVar1 * fStack_40;
      fStack_2c = fStack_2c + fVar1 * fStack_3c;
    }
    FUN_142b50c60(param_3 + 0x90,&local_68);
    cVar3 = FUN_142b501b0(param_3 + 0x90);
    if ((cVar3 != '\0') && (*(longlong *)(param_3 + 0x378) != 0)) {
      local_28[0] = *(float *)(param_3 + 0x1c);
      local_28[1] = *(float *)(param_3 + 0xc) - (local_28[0] + local_28[0]);
      local_28[2] = (float)DAT_144241500;
      if (*(char *)(param_3 + 0x385) == '\0') {
        local_28[2] = (float)0;
      }
      puVar5 = &DAT_143813340;
      uVar4 = 0;
      do {
        FUN_142b566d0(*(undefined8 *)(param_3 + 0x378),*puVar5,local_28[(int)uVar4]);
        uVar4 = uVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (uVar4 < 3);
      lVar2 = *(longlong *)(param_3 + 0x378);
      if ((lVar2 != 0) && (cVar3 = FUN_142b501b0(param_3 + 0x90), cVar3 != '\0')) {
        thunk_FUN_142b50b00(param_3 + 0x90,lVar2);
      }
    }
  }
  return;
}


  referenced from 14506dc70 (DATA) in <no function>
  referenced from 1443f797c (DATA) in <no function>
  referenced from 1443f79b0 (DATA) in <no function>
  referenced from 14087184f (UNCONDITIONAL_CALL) in FUN_1408715d0 @ 1408715d0
  referenced from 14086cf1d (UNCONDITIONAL_CALL) in FUN_14086c480 @ 14086c480

==== depth 1: FUN_1408a14b0 @ 1408a14b0 (342 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1408a14b0(longlong param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  undefined1 auStack_378 [32];
  undefined8 local_358;
  undefined4 local_350;
  undefined4 local_348;
  undefined4 local_338;
  undefined4 local_334;
  undefined8 local_330;
  undefined8 local_328;
  undefined4 *local_320;
  undefined1 local_318 [32];
  undefined1 local_2f8 [704];
  ulonglong local_38;
  
  local_330 = 0xfffffffffffffffe;
  local_38 = DAT_144d9ff50 ^ (ulonglong)auStack_378;
  local_334 = 0;
  local_328 = param_2;
  if (*(longlong *)(param_1 + 0x6d0) == 0) {
    uVar1 = FUN_142b56080(&DAT_14381a6ac,1,DAT_144e2e5e8);
    *(undefined8 *)(param_1 + 0x6d0) = uVar1;
  }
  if (*(longlong *)(param_1 + 0x6d0) != 0) {
    local_338 = param_4;
    FUN_142b566d0(*(longlong *)(param_1 + 0x6d0),70000,param_4);
  }
  local_320 = &local_338;
  local_338 = param_3;
  if (DAT_144e29820 == 0) {
    uVar1 = FUN_14292a3b0(&DAT_144e00bcb);
                    /* WARNING: Subroutine does not return */
    FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                  ,0xb4,&DAT_144234158,uVar1);
  }
  local_348 = 0;
  local_350 = 8;
  local_358 = *(undefined8 *)(param_1 + 0x6d0);
  uVar1 = FUN_1416246f0(DAT_144e29820,local_318,&local_338,param_1 + 0xb0);
  FUN_1408a0410(param_2,uVar1);
  local_334 = 1;
  FUN_14268d730(local_2f8);
  FUN_142b4fcb0(local_318);
  return param_2;
}


  referenced from 14506fbcc (DATA) in <no function>
  referenced from 1443fef68 (DATA) in <no function>
  referenced from 1408a1401 (UNCONDITIONAL_CALL) in FUN_1408a1330 @ 1408a1330
  referenced from 1408a17ad (UNCONDITIONAL_CALL) in FUN_1408a16d0 @ 1408a16d0

==== depth 1: FUN_1408a11c0 @ 1408a11c0 (354 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1408a11c0(longlong param_1,undefined8 param_2)

{
  longlong lVar1;
  char cVar2;
  undefined8 uVar3;
  undefined1 auStack_68 [32];
  undefined4 local_48 [2];
  undefined8 local_40;
  undefined4 *local_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  local_40 = 0xfffffffffffffffe;
  local_28 = DAT_144d9ff50 ^ (ulonglong)auStack_68;
  local_38 = local_48;
  local_48[0] = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x70))();
  uVar3 = FUN_140835a20(param_1);
  FUN_14073b020(uVar3,local_48,param_1 + 0xb0);
  local_38 = *(undefined4 **)(param_1 + 0xe0);
  uStack_30 = *(undefined4 *)(param_1 + 0xe8);
  uStack_2c = *(undefined4 *)(param_1 + 0xec);
  FUN_1408a55a0(param_1 + 0x90,&local_38,param_2);
  cVar2 = FUN_142b50270(param_1 + 0x100);
  if (cVar2 != '\0') {
    FUN_142b50c60(param_1 + 0x100,param_1 + 0xb0);
    if (*(longlong *)(param_1 + 0x6d0) != 0) {
      if (*(char *)(param_1 + 0x7c) == '\x02') {
        local_48[0] = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x80))();
      }
      else if (*(char *)(param_1 + 0x7c) == '\x03') {
        local_48[0] = (**(code **)(**(longlong **)(param_1 + 0x10) + 0x78))();
      }
      else {
        local_48[0] = 0;
      }
      FUN_142b566d0(*(undefined8 *)(param_1 + 0x6d0),70000,local_48[0]);
      lVar1 = *(longlong *)(param_1 + 0x6d0);
      if (lVar1 != 0) {
        cVar2 = FUN_142b501b0(param_1 + 0x100);
        if (cVar2 != '\0') {
          thunk_FUN_142b50b00(param_1 + 0x100,lVar1);
        }
      }
    }
  }
  cVar2 = FUN_142b50270(param_1 + 0x3f0);
  if (cVar2 != '\0') {
    FUN_142b50c60(param_1 + 0x3f0,param_1 + 0xb0);
  }
  return;
}


  referenced from 14506fbb4 (DATA) in <no function>
  referenced from 1443fec60 (DATA) in <no function>
  referenced from 140757618 (UNCONDITIONAL_CALL) in FUN_1407575d0 @ 1407575d0

==== depth 1: FUN_1408e9d30 @ 1408e9d30 (681 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Heritage AFTER dead removal. Example location: s0xffffffffffffff58 : 0x0001408e9f39 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_1408e9d30(longlong param_1)

{
  undefined4 uVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  undefined1 auStack_c8 [32];
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined1 local_a0 [8];
  undefined4 local_98 [2];
  longlong local_90;
  undefined4 local_88;
  undefined4 local_80 [2];
  undefined8 local_78;
  undefined4 local_70;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c;
  undefined1 local_58 [64];
  ulonglong local_18;
  
  local_18 = DAT_144d9ff50 ^ (ulonglong)auStack_c8;
  plVar2 = (longlong *)FUN_140835a20();
  lVar3 = (**(code **)(*plVar2 + 0x298))(plVar2);
  if (lVar3 != 0) {
    uVar1 = FUN_1406f5850(lVar3,0);
    local_98[0] = 0xffffffff;
    local_90 = 0;
    local_78 = 0;
    local_88 = 0xffffffff;
    local_80[0] = 0xffffffff;
    FUN_1415c58b0(local_80,0xffffffff);
    local_70 = 0;
    FUN_1415c3190(local_98,uVar1);
    if (local_90 != 0) {
      *(undefined1 *)(param_1 + 0x10) = *(undefined1 *)(local_90 + 0x340);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(local_90 + 0x33c);
      *(uint *)(param_1 + 0x1c) = (uint)*(ushort *)(local_90 + 0x336);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(local_90 + 0x338);
      if (DAT_144e25d60 == 0) {
        uVar4 = FUN_14292a3b0(&DAT_144e00a05);
                    /* WARNING: Subroutine does not return */
        FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                      ,0xb4,&DAT_144234158,uVar4);
      }
      lVar3 = FUN_1415838d0(DAT_144e25d60,1);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(lVar3 + 0x31c);
      if (DAT_144e29cc0 == 0) {
        uVar4 = FUN_14292a3b0(&DAT_144e008eb);
                    /* WARNING: Subroutine does not return */
        FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                      ,0xb4,&DAT_144234158,uVar4);
      }
      FUN_14163b170(DAT_144e29cc0,local_a0,&local_a8,0);
      FUN_1403bfa20(local_a0);
      if (DAT_144e17710 == 0) {
        uVar4 = FUN_14292a3b0(&DAT_144e00869);
                    /* WARNING: Subroutine does not return */
        FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                      ,0xb4,&DAT_144234158,uVar4);
      }
      uVar4 = *(undefined8 *)(DAT_144e17710 + 0x10);
      uVar5 = FUN_140835a20(param_1);
      FUN_1411781b0(uVar4,uVar5);
      local_68 = 8000;
      puVar6 = (undefined4 *)FUN_1404a7b00(&local_a8);
      local_64 = *puVar6;
      _local_a8 = CONCAT44(2,*(undefined4 *)(param_1 + 0x20));
      local_60 = 0x4e2f;
      local_5c = 1;
      local_5c = 1;
      local_60 = 0x4e2f;
      FUN_142b566d0(*(undefined8 *)(param_1 + 0x60),DAT_143825154,*(undefined4 *)(param_1 + 0x20));
      lVar3 = FUN_140835a20(param_1);
      uVar4 = FUN_140931190(local_58,&local_68,*(undefined8 *)(param_1 + 0x60));
      thunk_FUN_14654f42b(lVar3 + 0x40f0,uVar4,0,1);
      if (*(uint *)(param_1 + 0x1c) < 0x5b) {
        lVar3 = FUN_140835a20(param_1);
        uVar4 = 200;
      }
      else {
        lVar3 = FUN_140835a20(param_1);
        uVar4 = 300;
      }
      FUN_14082d6b0(*(undefined8 *)(*(longlong *)(lVar3 + 800) + 0x58),uVar4,
                    *(undefined4 *)(param_1 + 0x20));
      if (*(char *)(param_1 + 0x10) == '\x01') {
        FUN_1408eb350(param_1);
      }
    }
  }
  return;
}


  referenced from 14507397c (DATA) in <no function>
  referenced from 14440a744 (DATA) in <no function>
  referenced from 14440a754 (DATA) in <no function>
  referenced from 1407cbdc7 (UNCONDITIONAL_CALL) in FUN_1407cbd90 @ 1407cbd90

==== depth 1: FUN_140927b60 @ 140927b60 (1388 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140927b60(longlong param_1,undefined8 param_2,longlong *param_3)

{
  ushort uVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  longlong *plVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined4 *puVar11;
  undefined1 auStack_108 [32];
  longlong local_e8;
  longlong local_e0;
  undefined8 local_d8;
  int local_d0 [2];
  int local_c8 [4];
  longlong *local_b8;
  undefined4 local_b0;
  longlong *local_a8;
  undefined8 local_98;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined1 local_60 [32];
  ulonglong local_40;
  
  local_98 = 0xfffffffffffffffe;
  local_40 = DAT_144d9ff50 ^ (ulonglong)auStack_108;
  param_3 = (longlong *)*param_3;
  if ((*(byte *)(param_1 + 0x44) & 4) != 0) {
    iVar7 = FUN_14161b560(param_1 + 0x68);
    if (iVar7 != 0) {
      *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 1;
    }
  }
  if (*(int *)(param_1 + 0x30) < 0) {
    iVar7 = 1;
  }
  else {
    local_a8 = (longlong *)local_d0;
    local_d8 = local_c8;
    local_c8[0] = *(int *)(param_1 + 0x30);
    local_d0[0] = *(int *)(param_1 + 0x30);
    iVar7 = (**(code **)(*param_3 + 0x5a0))(param_3,local_c8,local_d0);
  }
  uVar1 = *(ushort *)(param_1 + 0x44);
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 0x20) != 0) goto LAB_140927e2e;
    iVar8 = *(int *)(param_1 + 0x28);
    if (*(int *)(param_1 + 0x30) < 0) {
      if (-1 < iVar8) {
        local_e8 = DAT_144cbd390 + 0x30;
        local_d8 = (int *)CONCAT44(local_d8._4_4_,iVar8);
        if (DAT_144e29820 == 0) {
          uVar10 = FUN_14292a3b0(&DAT_144e00bcb);
                    /* WARNING: Subroutine does not return */
          FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                        ,0xb4,&DAT_144234158,uVar10);
        }
        uVar10 = FUN_1416263e0(DAT_144e29820,local_c8,param_3,&local_d8);
        FUN_1406b75f0(param_1 + 0x68,uVar10);
        FUN_1406b74d0(local_c8);
        local_b8 = *(longlong **)(param_1 + 0x38);
        local_b0 = *(undefined4 *)(param_1 + 0x40);
        FUN_14161b660(param_1 + 0x68,&local_b8);
        uVar10 = FUN_140742c30(param_3);
        FUN_14161b270(param_1 + 0x68,uVar10);
        *(undefined2 *)(param_1 + 100) = 1;
LAB_140927dc4:
        *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 8;
      }
    }
    else if ((-1 < iVar8) && (0 < iVar7)) {
      local_e0 = DAT_144cbd390 + 0x30;
      local_d8 = (int *)CONCAT44(local_d8._4_4_,iVar8);
      if (DAT_144e29820 == 0) {
        uVar10 = FUN_14292a3b0(&DAT_144e00bcb);
                    /* WARNING: Subroutine does not return */
        FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                      ,0xb4,&DAT_144234158,uVar10);
      }
      local_e8 = CONCAT44(local_e8._4_4_,iVar7);
      uVar10 = FUN_141627560(DAT_144e29820,local_c8,param_3[0xb],&local_d8);
      FUN_1406b75f0(param_1 + 0x68,uVar10);
      FUN_1406b74d0(local_c8);
      local_b8 = *(longlong **)(param_1 + 0x38);
      local_b0 = *(undefined4 *)(param_1 + 0x40);
      FUN_14161b660(param_1 + 0x68,&local_b8);
      local_a8 = (longlong *)local_c8;
      local_d8 = local_d0;
      local_c8[0] = -1;
      local_d0[0] = *(int *)(param_1 + 0x30);
      uVar10 = (**(code **)(*param_3 + 0x550))(param_3,local_d0,local_c8,0xffffffff);
      FUN_14161b270(param_1 + 0x68,uVar10);
      *(short *)(param_1 + 100) = (short)iVar7;
      goto LAB_140927dc4;
    }
    plVar5 = DAT_144e2e5e8;
    lVar2 = *(longlong *)(param_1 + 0x78);
    if (lVar2 != 0) {
      FUN_142b550a0(lVar2);
      (**(code **)(*plVar5 + 0x68))(plVar5,lVar2);
      *(undefined8 *)(param_1 + 0x78) = 0;
    }
    local_d8 = (int *)0x10000ea60;
    uVar10 = FUN_142b56080(&local_d8,2,DAT_144e2e5e8);
    *(undefined8 *)(param_1 + 0x78) = uVar10;
  }
  else if ((uVar1 & 0x20) != 0) {
    if ((uVar1 & 2) != 0) {
      iVar8 = FUN_14161b560(param_1 + 0x68);
      if (iVar8 != 0) goto LAB_140927e32;
    }
LAB_140927e2e:
    *(undefined1 *)(param_1 + 0x18) = 0;
  }
LAB_140927e32:
  if ((-1 < *(int *)(param_1 + 0x2c)) && (0 < iVar7)) {
    uVar1 = *(ushort *)(param_1 + 0x44);
    if (((uVar1 & 0x20) == 0) && ((uVar1 & 2) != 0)) {
      if ((uVar1 & 0x10) == 0) {
        local_d8 = (int *)CONCAT44(5,*(int *)(param_1 + 0x2c));
        if (DAT_144e29cc0 == 0) {
          uVar10 = FUN_14292a3b0(&DAT_144e008eb);
                    /* WARNING: Subroutine does not return */
          FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                        ,0xb4,&DAT_144234158,uVar10);
        }
        uVar10 = FUN_14163aa70(DAT_144e29cc0,local_c8,&local_d8,0);
        FUN_1404fb950(param_1 + 0x70,uVar10);
        FUN_1403bfa20(local_c8);
        if (-1 < *(int *)(param_1 + 0x30)) {
          local_a8 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
          FUN_142923280(0xb0,8);
        }
        uVar10 = FUN_140742c30(param_3);
        FUN_141632360(param_1 + 0x70,uVar10);
        *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x10;
      }
    }
    else if ((uVar1 & 0x10) != 0) {
      FUN_141632740(param_1 + 0x70);
      *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) & 0xffef;
    }
  }
  if ((*(ushort *)(param_1 + 0x44) & 1) == 0) {
    if ((*(ushort *)(param_1 + 0x44) & 0x20) == 0) {
      FUN_14161b570(param_1 + 0x68);
      if ((*(byte *)(param_1 + 0x44) & 0x10) != 0) {
        FUN_141632740(param_1 + 0x70);
        *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) & 0xffef;
      }
      if ((-1 < *(int *)(param_1 + 0x48)) || (-1 < *(int *)(param_1 + 0x4c))) {
        *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) & 0xfffb;
        local_b8 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
        FUN_142923280(0x80);
      }
      *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x20;
    }
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
  }
  *(ushort *)(param_1 + 0x44) =
       (*(ushort *)(param_1 + 0x44) & 1) << 6 | *(ushort *)(param_1 + 0x44) & 0xffbe;
  local_80 = DAT_144e11fb0;
  uStack_7c = DAT_144e11fb4;
  uStack_78 = DAT_144e11fb8;
  uStack_74 = DAT_144e11fbc;
  local_70 = CONCAT44(DAT_144e11fc4,DAT_144e11fc0);
  uStack_68 = CONCAT44(DAT_144e11fcc,DAT_144e11fc8);
  if ((*(byte *)((longlong)param_3 + 0x365) & 0x10) != 0) {
    cVar6 = FUN_14073fd30(param_3);
    if (cVar6 == '\0') {
      cVar6 = FUN_140751fe0(param_3);
      if ((cVar6 != '\0') && ((*(byte *)((longlong)param_3 + 0x364) & 8) != 0)) {
        bVar3 = true;
        goto LAB_140928126;
      }
    }
  }
  bVar3 = false;
LAB_140928126:
  if (((*(byte *)(param_1 + 0x44) & 0x80) == 0) ||
     (*(char *)(*(longlong *)(param_3[100] + 0xc0) + 0x49) == '\0')) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (((bVar3) && (!bVar4)) && (param_3[0xb] != 0)) {
    puVar11 = (undefined4 *)FUN_1410f5150(param_3[0xb],local_60);
    local_80 = *puVar11;
    uStack_7c = puVar11[1];
    uStack_78 = puVar11[2];
    uStack_74 = puVar11[3];
    local_70 = *(undefined8 *)(puVar11 + 4);
    uStack_68 = *(undefined8 *)(puVar11 + 6);
  }
  FUN_14161b600(param_1 + 0x68,&local_80);
  if (*(longlong *)(param_1 + 0x78) != 0) {
    uVar9 = FUN_14162c210(param_3);
    FUN_142b566d0(*(undefined8 *)(param_1 + 0x78),60000,uVar9);
    local_d8._0_4_ = DAT_144241500;
    if (param_3[0xb] != 0) {
      local_d8._0_4_ = FUN_1410f50f0();
    }
    FUN_142b566d0(*(undefined8 *)(param_1 + 0x78),1,(undefined4)local_d8);
    FUN_14161b610(param_1 + 0x68,*(undefined8 *)(param_1 + 0x78));
  }
  return 0;
}


  referenced from 145078188 (DATA) in <no function>
  referenced from 144417410 (DATA) in <no function>

==== depth 1: FUN_140928eaf @ 140928eaf (35 bytes)

void FUN_140928eaf(void)

{
  int unaff_EBX;
  longlong unaff_RSI;
  longlong unaff_RDI;
  undefined4 auStackX_20 [2];
  
  FUN_142b566d0();
  if (2 < unaff_EBX + 1U) {
    FUN_14161b610(unaff_RSI + 0x60,*(undefined8 *)(unaff_RSI + 0x68));
    FUN_1402ab1a1();
    return;
  }
  FUN_140928eaf(*(undefined8 *)(unaff_RSI + 0x68),*(undefined4 *)(unaff_RDI + 4),
                auStackX_20[(int)(unaff_EBX + 1U)]);
  return;
}


  referenced from 1465cae1a (UNCONDITIONAL_CALL) in FUN_1465cae0c @ 1465cae0c

==== depth 1: FUN_14092bcd0 @ 14092bcd0 (1955 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14092bcd0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  undefined1 auStack_158 [32];
  longlong local_138;
  longlong *local_c8;
  int local_c0 [2];
  int local_b8 [2];
  int local_b0 [2];
  int *local_a8;
  undefined8 local_a0;
  int *local_98;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  int local_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 local_60 [32];
  ulonglong local_40;
  
  local_88 = 0xfffffffffffffffe;
  local_40 = DAT_144d9ff50 ^ (ulonglong)auStack_158;
  local_c8 = (longlong *)*param_3;
  if (local_c8 == (longlong *)0x0) {
    return 0;
  }
  if (((*(byte *)(param_1 + 0x58) & 0x14) != 0) && (*(int *)(param_1 + 0x2c) < 0)) {
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x50);
  }
  local_a8 = local_b0;
  local_b0[0] = *(int *)(param_1 + 0x34);
  if (local_b0[0] == -1) {
    iVar7 = 1;
  }
  else {
    local_a8 = local_b8;
    local_98 = local_c0;
    local_c0[0] = local_b0[0];
    local_b8[0] = local_b0[0];
    iVar7 = (**(code **)(*local_c8 + 0x5a0))(local_c8,local_c0,local_b8);
  }
  uVar4 = *(ushort *)(param_1 + 0x58);
  if ((uVar4 & 8) == 0) {
    iVar6 = *(int *)(param_1 + 0x2c);
    if (*(int *)(param_1 + 8) < 0) {
      if (-1 < iVar6) {
        if (*(int *)(param_1 + 0x34) == -1) {
          local_138 = DAT_144cbd390 + 0x30;
          if (DAT_144e29820 != 0) {
            local_c0[0] = iVar6;
            FUN_1416263e0(DAT_144e29820,local_b8,local_c8,local_c0);
            local_98 = (int *)DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0xc0,0x10);
          }
          local_c0[0] = iVar6;
          uVar8 = FUN_14292a3b0(&DAT_144e00bcb);
                    /* WARNING: Subroutine does not return */
          FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                        ,0xb4,&DAT_144234158,uVar8);
        }
        uStack_78 = &local_c8;
        if ((uVar4 & 0x1000) == 0) {
          local_80 = param_1;
          local_70 = iVar7;
          cVar3 = FUN_14132d870(param_1 + 0x34);
          if (cVar3 == '\0') {
            local_a0 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0x140,0x10);
          }
          lVar1 = *local_c8;
          uVar5 = FUN_14132ddb0(param_1 + 0x34);
          (**(code **)(lVar1 + 0x560))(local_c8,local_c0,uVar5);
          if (local_c0[0] != -1) {
            local_98 = (int *)DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0x140,0x10);
          }
        }
        else {
          local_80 = param_1;
          local_70 = iVar7;
          cVar3 = FUN_14132d870(param_1 + 0x34);
          if (cVar3 == '\0') {
            local_a0 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0xc0,0x10);
          }
          lVar1 = *local_c8;
          uVar5 = FUN_14132ddb0(param_1 + 0x34);
          (**(code **)(lVar1 + 0x560))(local_c8,local_c0,uVar5);
          if (local_c0[0] != -1) {
            local_a0 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0xc0,0x10);
          }
        }
      }
      thunk_FUN_1458ef75a();
    }
    else {
      if (-1 < iVar6) {
        if (0 < iVar7) {
          *(short *)(param_1 + 0x66) = (short)iVar7;
        }
        if (*(int *)(param_1 + 0x34) == -1) {
          local_138 = DAT_144cbd390 + 0x30;
          if (DAT_144e29820 != 0) {
            local_c0[0] = iVar6;
            uVar8 = FUN_1416263e0(DAT_144e29820,&local_a8,local_c8,local_c0);
            FUN_1406b75f0(param_1 + 0x70,uVar8);
            FUN_1406b74d0(&local_a8);
            local_a0 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0xc0,0x10);
          }
          local_c0[0] = iVar6;
          uVar8 = FUN_14292a3b0(&DAT_144e00bcb);
                    /* WARNING: Subroutine does not return */
          FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                        ,0xb4,&DAT_144234158,uVar8);
        }
        uStack_78 = &local_c8;
        if ((uVar4 & 0x1000) == 0) {
          local_80 = param_1;
          local_70 = iVar7;
          cVar3 = FUN_14132d870(param_1 + 0x34);
          if (cVar3 == '\0') {
            local_a0 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0x140,0x10);
          }
          lVar1 = *local_c8;
          uVar5 = FUN_14132ddb0(param_1 + 0x34);
          (**(code **)(lVar1 + 0x560))(local_c8,local_c0,uVar5);
          if (local_c0[0] != -1) {
            local_a0 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0x140,0x10);
          }
        }
        else {
          local_80 = param_1;
          local_70 = iVar7;
          cVar3 = FUN_14132d870(param_1 + 0x34);
          if (cVar3 == '\0') {
            local_a0 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0xc0,0x10);
          }
          lVar1 = *local_c8;
          uVar5 = FUN_14132ddb0(param_1 + 0x34);
          (**(code **)(lVar1 + 0x560))(local_c8,local_c0,uVar5);
          if (local_c0[0] != -1) {
            local_a0 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0xc0,0x10);
          }
        }
      }
      *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x34);
      *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
      uVar4 = *(ushort *)(param_1 + 0x58);
      *(ushort *)(param_1 + 0x58) = (uVar4 >> 1 ^ uVar4) & 2 ^ uVar4;
      uVar4 = FUN_14161b560(param_1 + 0x70);
      *(ushort *)(param_1 + 0x58) = *(ushort *)(param_1 + 0x58) & 0xfff7;
      *(ushort *)(param_1 + 0x58) = *(ushort *)(param_1 + 0x58) | (uVar4 & 1) << 3;
      *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x54);
      *(undefined4 *)(param_1 + 0x54) = 0x3f800000;
    }
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x30);
  }
  else {
    if (((char)((byte)(uVar4 >> 1) ^ (byte)uVar4) < '\0') &&
       (uVar4 = (uVar4 >> 1 ^ uVar4) & 0x80 ^ uVar4, *(ushort *)(param_1 + 0x58) = uVar4,
       -1 < (char)uVar4)) {
      puVar9 = *(undefined8 **)(param_1 + 0x68);
      if (puVar9 != (undefined8 *)0x0) {
        iVar6 = FUN_1429235b0(puVar9 + 1);
        if (iVar6 == 1) {
          (**(code **)*puVar9)(puVar9);
        }
        else if (iVar6 < 1) {
                    /* WARNING: Subroutine does not return */
          FUN_1429213b0(0,0x3e,
                        "DLReferenceCountObject: Invalid Unref() call. m_nRefCount is 0 or less");
        }
        *(undefined8 *)(param_1 + 0x68) = 0;
      }
      FUN_14161b270(param_1 + 0x70,0);
    }
    uVar4 = *(ushort *)(param_1 + 0x58);
    if ((((byte)uVar4 >> 1 ^ (byte)uVar4) & 0x20) != 0) {
      uVar4 = (uVar4 >> 1 ^ uVar4) & 0x20 ^ uVar4;
      *(ushort *)(param_1 + 0x58) = uVar4;
      if (*(longlong *)(param_1 + 0x68) != 0) {
        FUN_1412ffe50(*(longlong *)(param_1 + 0x68),(byte)uVar4 >> 5 & 1);
      }
    }
    uVar4 = *(ushort *)(param_1 + 0x58);
    if (((uVar4 >> 1 ^ uVar4) & 0x200) != 0) {
      uVar4 = (uVar4 >> 1 ^ uVar4) & 0x200 ^ uVar4;
      *(ushort *)(param_1 + 0x58) = uVar4;
      if (*(longlong *)(param_1 + 0x68) != 0) {
        FUN_1412ffe90(*(longlong *)(param_1 + 0x68),(byte)(uVar4 >> 9) & 1);
      }
    }
    if (((*(ushort *)(param_1 + 0x58) & 0x200) != 0) && (*(longlong *)(param_1 + 0x68) != 0)) {
      FUN_1412ffe60(*(longlong *)(param_1 + 0x68),(int)local_c8[0x81c]);
    }
    if (((*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x2c)) &&
        (*(int *)(param_1 + 0x30) == *(int *)(param_1 + 0x34))) &&
       (*(short *)(param_1 + 0x66) == iVar7)) {
      bVar2 = false;
      if (*(float *)(param_1 + 0x50) != *(float *)(param_1 + 0x54)) {
        *(float *)(param_1 + 0x50) = *(float *)(param_1 + 0x54);
        FUN_14161b650(param_1 + 0x70);
      }
    }
    else {
      bVar2 = true;
    }
    if ((*(byte *)(param_1 + 0x58) & 0x12) == 0) {
      if (bVar2) {
        if (0 < *(int *)(param_1 + 0x2c)) {
          local_a0 = DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
          FUN_142923280(0xa8,8);
        }
        FUN_14161b570(param_1 + 0x70);
        *(ushort *)(param_1 + 0x58) = *(ushort *)(param_1 + 0x58) | 0x10;
        *(undefined4 *)(param_1 + 8) = 0xffffffff;
      }
    }
    else {
      iVar7 = FUN_14161b540(param_1 + 0x70);
      if (iVar7 != 0) {
        thunk_FUN_1458ef75a(param_1);
      }
    }
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x34) = 0xffffffff;
    uVar4 = *(ushort *)(param_1 + 0x58);
    *(ushort *)(param_1 + 0x58) = (uVar4 >> 1 ^ uVar4) & 2 ^ uVar4;
    *(undefined4 *)(param_1 + 0x54) = 0x3f800000;
  }
  if ((((*(byte *)((longlong)local_c8 + 0x365) & 0x10) == 0) ||
      (cVar3 = FUN_14073fd30(), cVar3 != '\0')) ||
     ((cVar3 = FUN_140751fe0(), cVar3 == '\0' || ((*(byte *)((longlong)local_c8 + 0x364) & 8) == 0))
     )) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  *(ushort *)(param_1 + 0x58) = *(ushort *)(param_1 + 0x58) & 0xfffe;
  *(ushort *)(param_1 + 0x58) = *(ushort *)(param_1 + 0x58) | uVar4;
  local_80 = CONCAT44(DAT_144e11fb4,DAT_144e11fb0);
  uStack_78 = (longlong **)CONCAT44(DAT_144e11fbc,DAT_144e11fb8);
  local_70 = DAT_144e11fc0;
  uStack_6c = DAT_144e11fc4;
  uStack_68 = DAT_144e11fc8;
  uStack_64 = DAT_144e11fcc;
  if (((char)uVar4 != '\0') && (local_c8[0xb] != 0)) {
    puVar9 = (undefined8 *)FUN_1410f5150(local_c8[0xb],local_60);
    local_80 = *puVar9;
    uStack_78 = (longlong **)puVar9[1];
    local_70 = *(int *)(puVar9 + 2);
    uStack_6c = *(undefined4 *)((longlong)puVar9 + 0x14);
    uStack_68 = *(undefined4 *)(puVar9 + 3);
    uStack_64 = *(undefined4 *)((longlong)puVar9 + 0x1c);
  }
  FUN_14161b600(param_1 + 0x70,&local_80);
  if (*(longlong *)(param_1 + 0x98) == 0) goto LAB_14092cc20;
  if (*(int *)(param_1 + 0xa0) == 1) {
    local_c0[0] = DAT_144241500;
    iVar7 = DAT_144241500;
    if (local_c8[0xb] != 0) {
      iVar7 = FUN_1410f50f0();
      local_c0[0] = iVar7;
    }
LAB_14092cbfe:
    FUN_142b566d0(*(undefined8 *)(param_1 + 0x98),*(undefined4 *)(param_1 + 0xa0),iVar7);
  }
  else if (*(int *)(param_1 + 0xa0) == 60000) {
    iVar7 = FUN_14162c210(local_c8);
    goto LAB_14092cbfe;
  }
  FUN_14161b610(param_1 + 0x70,*(undefined8 *)(param_1 + 0x98));
LAB_14092cc20:
  *(longlong **)(param_1 + 0x78) = local_c8;
  *(undefined8 *)(param_1 + 0x80) = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  uVar8 = FUN_141360700();
  FUN_14161b620(param_1 + 0x70,uVar8);
  return 0;
}


  referenced from 145078458 (DATA) in <no function>
  referenced from 144418000 (DATA) in <no function>

==== depth 1: FUN_14092ef27 @ 14092ef27 (186 bytes)

void FUN_14092ef27(void)

{
  longlong *plVar1;
  int iVar2;
  longlong lVar3;
  longlong unaff_RBP;
  longlong unaff_RDI;
  undefined4 uStack0000000000000060;
  undefined4 uStack0000000000000064;
  
  iVar2 = FUN_14161b560(unaff_RDI + 0x100);
  if (iVar2 != 0) {
    uStack0000000000000060 = 0x1117a;
    uStack0000000000000064 = 0x1118e;
    lVar3 = FUN_142b56080(&stack0x00000060,2,DAT_144e2e5f0);
    if (lVar3 != 0) {
      FUN_142b566d0(lVar3,0x1117a,*(undefined4 *)(unaff_RBP + 0x40));
      FUN_142b566d0(lVar3,0x1118e,*(undefined4 *)(unaff_RBP + 0x48));
      FUN_14161b610(unaff_RDI + 0x100,lVar3);
      plVar1 = DAT_144e2e5f0;
      FUN_142b550a0(lVar3);
      (**(code **)(*plVar1 + 0x68))(plVar1,lVar3);
    }
  }
  FUN_14295c210(&stack0x00000068);
  FUN_14295c1c0(&stack0x00000068);
  return;
}


  referenced from 14092eec7 (CONDITIONAL_JUMP) in <no function>
  referenced from 145b0de3b (UNCONDITIONAL_CALL) in FUN_145b0de0c @ 145b0de0c

==== depth 1: FUN_140937cc0 @ 140937cc0 (938 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_140937cc0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  undefined8 *puVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined1 auStack_e8 [64];
  int local_a8 [2];
  int local_a0 [2];
  int *local_98;
  undefined8 local_90;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 local_68 [32];
  undefined8 local_48;
  undefined4 local_40;
  ulonglong local_38;
  
  local_90 = 0xfffffffffffffffe;
  local_38 = DAT_144d9ff50 ^ (ulonglong)auStack_e8;
  uVar8 = 0;
  param_3 = (longlong *)*param_3;
  if ((param_3 != (longlong *)0x0) &&
     (((*(uint *)(*(longlong *)(param_3[100] + 8) + 0x148) >> 0x1a & 1) == 0 ||
      ((*(byte *)(param_1 + 0x40) & 8) != 0)))) {
    if (((*(byte *)(param_1 + 0x40) & 0x14) != 0) && (*(int *)(param_1 + 0x2c) < 0)) {
      *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(param_1 + 0x30);
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x48);
    }
    iVar7 = *(int *)(param_1 + 0x34);
    if (iVar7 == -1) {
      iVar7 = 1;
    }
    else {
      local_48 = local_a8;
      local_98 = local_a0;
      local_a8[0] = iVar7;
      local_a0[0] = iVar7;
      iVar7 = (**(code **)(*param_3 + 0x5a0))(param_3,local_a0,local_a8);
    }
    iVar7 = *(short *)(param_1 + 0x54) * iVar7;
    if ((*(byte *)(param_1 + 0x40) & 8) == 0) {
      thunk_FUN_141189888(param_1,param_3,iVar7);
    }
    else {
      if (*(short *)(param_1 + 0x52) != iVar7) {
        FUN_1409384c0(param_1);
      }
      if (*(char *)((longlong)param_3 + 0x47d9) == '\0') {
        FUN_1409384c0(param_1);
      }
      uVar4 = *(ushort *)(param_1 + 0x40);
      if (((char)((byte)(uVar4 >> 1) ^ (byte)uVar4) < '\0') &&
         (uVar4 = (uVar4 >> 1 ^ uVar4) & 0x80 ^ uVar4, *(ushort *)(param_1 + 0x40) = uVar4,
         -1 < (char)uVar4)) {
        puVar1 = *(undefined8 **)(param_1 + 0x58);
        if (puVar1 != (undefined8 *)0x0) {
          iVar7 = FUN_1429235b0(puVar1 + 1);
          if (iVar7 == 1) {
            (**(code **)*puVar1)(puVar1);
          }
          else if (iVar7 < 1) {
                    /* WARNING: Subroutine does not return */
            FUN_1429213b0(0,0x3e,
                          "DLReferenceCountObject: Invalid Unref() call. m_nRefCount is 0 or less");
          }
          *(undefined8 *)(param_1 + 0x58) = 0;
        }
        FUN_14161b270(param_1 + 0x60,0);
      }
      uVar4 = *(ushort *)(param_1 + 0x40);
      if ((((byte)uVar4 >> 1 ^ (byte)uVar4) & 0x20) != 0) {
        uVar4 = (uVar4 >> 1 ^ uVar4) & 0x20 ^ uVar4;
        *(ushort *)(param_1 + 0x40) = uVar4;
        if (*(longlong *)(param_1 + 0x58) != 0) {
          FUN_1412ffe50(*(longlong *)(param_1 + 0x58),(byte)uVar4 >> 5 & 1);
        }
      }
      if (((*(int *)(param_1 + 0x28) == *(int *)(param_1 + 0x2c)) &&
          (*(int *)(param_1 + 0x30) == *(int *)(param_1 + 0x38))) &&
         (*(int *)(param_1 + 0x34) == *(int *)(param_1 + 0x3c))) {
        bVar2 = false;
        if (*(float *)(param_1 + 0x48) != *(float *)(param_1 + 0x4c)) {
          *(float *)(param_1 + 0x48) = *(float *)(param_1 + 0x4c);
          FUN_14161b650(param_1 + 0x60);
        }
      }
      else {
        bVar2 = true;
      }
      if ((*(byte *)(param_1 + 0x40) & 0x12) == 0) {
        if (bVar2) {
          if (0 < *(int *)(param_1 + 0x2c)) {
            local_98 = (int *)DAT_144e2e5e8;
                    /* WARNING: Subroutine does not return */
            FUN_142923280(0x70);
          }
          FUN_14161b570(param_1 + 0x60);
          *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) | 0x10;
          *(undefined4 *)(param_1 + 8) = 0xffffffff;
        }
      }
      else {
        iVar7 = FUN_14161b540(param_1 + 0x60);
        if (iVar7 != 0) {
          *(undefined1 *)(param_1 + 0x18) = 0;
        }
      }
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x38) = 0xffffffff;
      uVar4 = *(ushort *)(param_1 + 0x40);
      *(ushort *)(param_1 + 0x40) = (uVar4 >> 1 ^ uVar4) & 2 ^ uVar4;
      *(undefined4 *)(param_1 + 0x4c) = 0x3f800000;
    }
    if ((((*(byte *)((longlong)param_3 + 0x365) & 0x10) == 0) ||
        (cVar3 = FUN_14073fd30(), cVar3 != '\0')) ||
       ((cVar3 = FUN_140751fe0(), cVar3 == '\0' || ((*(byte *)((longlong)param_3 + 0x364) & 8) == 0)
        ))) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
    *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) & 0xfffe;
    *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) | uVar4;
    local_88 = DAT_144e11fb0;
    uStack_84 = DAT_144e11fb4;
    uStack_80 = DAT_144e11fb8;
    uStack_7c = DAT_144e11fbc;
    local_78 = DAT_144e11fc0;
    uStack_74 = DAT_144e11fc4;
    uStack_70 = DAT_144e11fc8;
    uStack_6c = DAT_144e11fcc;
    if (((char)uVar4 != '\0') && (param_3[0xb] != 0)) {
      puVar6 = (undefined4 *)FUN_1410f5150(param_3[0xb],local_68);
      local_88 = *puVar6;
      uStack_84 = puVar6[1];
      uStack_80 = puVar6[2];
      uStack_7c = puVar6[3];
      local_78 = puVar6[4];
      uStack_74 = puVar6[5];
      uStack_70 = puVar6[6];
      uStack_6c = puVar6[7];
    }
    FUN_14161b600(param_1 + 0x60,&local_88);
    iVar7 = *(int *)(param_1 + 0x3c);
    if ((iVar7 == -1) && (*(int *)(param_1 + 0x34) != -1)) {
      iVar7 = *(int *)(param_1 + 0x34);
    }
    uVar5 = FUN_14162bd10(param_3);
    local_48 = (int *)CONCAT44(local_48._4_4_,uVar5);
    uVar5 = FUN_14162bd50(param_3);
    local_48 = (int *)CONCAT44(uVar5,(undefined4)local_48);
    local_98 = local_a0;
    local_a0[0] = iVar7;
    local_40 = FUN_14162bd80(param_3,local_a0);
    puVar6 = &DAT_14382ff48;
    do {
      FUN_142b566d0(*(undefined8 *)(param_1 + 0x68),*puVar6,
                    *(undefined4 *)((longlong)&local_48 + (longlong)(int)uVar8 * 4));
      uVar8 = uVar8 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar8 < 3);
    FUN_14161b610(param_1 + 0x60,*(undefined8 *)(param_1 + 0x68));
  }
  return 0;
}


  referenced from 145078d88 (DATA) in <no function>
  referenced from 14441b290 (DATA) in <no function>

==== depth 1: FUN_140938d00 @ 140938d00 (122 bytes)

void FUN_140938d00(longlong param_1,undefined8 param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 local_res8 [2];
  
  local_res8[0] = FUN_14162c0c0(param_2);
  local_res8[1] = FUN_14162be40(param_2);
  puVar2 = &DAT_143830138;
  uVar1 = 0;
  do {
    FUN_142b566d0(*(undefined8 *)(param_1 + 0x58),*puVar2,local_res8[(int)uVar1]);
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 2);
  FUN_14161b610(param_1 + 0x50,*(undefined8 *)(param_1 + 0x58));
  return;
}


  referenced from 145078e6c (DATA) in <no function>
  referenced from 140938cdb (UNCONDITIONAL_CALL) in FUN_140938ba0 @ 140938ba0

==== depth 1: FUN_140c517d0 @ 140c517d0 (951 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140c517d0(longlong param_1,undefined8 param_2)

{
  undefined8 uVar1;
  ulonglong uVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  longlong lVar6;
  uint uVar7;
  undefined1 auStack_9b8 [32];
  undefined8 local_998;
  undefined4 local_990;
  undefined4 local_988;
  undefined4 local_978 [6];
  undefined4 *local_960;
  undefined8 local_958;
  undefined8 local_948;
  ulonglong uStack_940;
  undefined4 local_938;
  undefined4 uStack_934;
  undefined4 uStack_930;
  undefined4 uStack_92c;
  undefined4 local_928;
  undefined4 uStack_924;
  undefined4 uStack_920;
  undefined4 uStack_91c;
  undefined8 local_918;
  undefined8 uStack_910;
  undefined8 local_908;
  undefined4 uStack_900;
  undefined4 uStack_8fc;
  undefined8 local_8f8;
  ulonglong uStack_8f0;
  undefined1 local_8d8 [32];
  undefined1 local_8b8 [704];
  undefined1 local_5f8 [752];
  undefined1 local_308 [752];
  ulonglong local_18;
  
  local_958 = 0xfffffffffffffffe;
  local_18 = DAT_144d9ff50 ^ (ulonglong)auStack_9b8;
  if (*(longlong *)(*(longlong *)(param_1 + 0x18) + 0x28) != 0) {
    local_978[3] = DAT_144cb9f5c;
    local_978[2] = DAT_144cb9f58;
    puVar4 = (undefined4 *)FUN_14073c0a0(param_2,local_978);
    local_978[2] = *puVar4;
    uVar7 = 0;
    local_978[3] = 0;
    local_918 = _DAT_144041970;
    local_908 = _DAT_144041980;
    uVar5 = local_908;
    local_8f8 = _DAT_144041990;
    uVar1 = local_8f8;
    uStack_910 = _UNK_144041978 & 0xffffffff;
    uStack_900 = (undefined4)_UNK_144041988;
    _uStack_900 = CONCAT44(DAT_1438da1e0,uStack_900);
    uStack_8f0 = _UNK_144041998 & 0xffffffff;
    uVar2 = uStack_8f0;
    local_948 = _DAT_144041970;
    uStack_940 = uStack_910;
    local_908._0_4_ = (undefined4)_DAT_144041980;
    local_908._4_4_ = (undefined4)((ulonglong)_DAT_144041980 >> 0x20);
    local_938 = (undefined4)local_908;
    uStack_934 = local_908._4_4_;
    uStack_930 = uStack_900;
    uStack_92c = DAT_1438da1e0;
    local_8f8._0_4_ = (undefined4)_DAT_144041990;
    local_8f8._4_4_ = (undefined4)((ulonglong)_DAT_144041990 >> 0x20);
    uStack_8f0._0_4_ = (undefined4)_UNK_144041998;
    local_928 = (undefined4)local_8f8;
    uStack_924 = local_8f8._4_4_;
    uStack_920 = (undefined4)uStack_8f0;
    uStack_91c = 0;
    local_960 = local_978;
    local_978[0] = 0xc3578;
    local_908 = uVar5;
    local_8f8 = uVar1;
    uStack_8f0 = uVar2;
    if (DAT_144e29820 == 0) {
      uVar5 = FUN_14292a3b0(&DAT_144e00bcb);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar5);
    }
    local_988 = 0;
    local_990 = 2;
    local_998 = 0;
    uVar5 = thunk_FUN_14625ae3b(DAT_144e29820,local_8d8,local_978,&local_948);
    FUN_1408a0410(local_5f8,uVar5);
    FUN_140676580(param_1 + 0xb0,local_308,local_5f8);
    FUN_140675f50(local_308);
    FUN_140675f50(local_5f8);
    FUN_14268d730(local_8b8);
    FUN_142b4fcb0(local_8d8);
    local_918 = CONCAT44(uRam0000000144e11fd4,_DAT_144e11fd0);
    uStack_910 = CONCAT44(uRam0000000144e11fdc,uRam0000000144e11fd8);
    local_908 = CONCAT44(uRam0000000144e11fe4,_DAT_144e11fe0);
    _uStack_900 = CONCAT44(uRam0000000144e11fec,uRam0000000144e11fe8);
    local_998 = 0;
    FUN_1416258a0(param_1 + 0xb0,&local_918,local_978 + 2,0);
    FUN_142b513a0(param_1 + 0xc0,0,0);
    local_960 = local_978;
    local_978[0] = 0xc3579;
    if (DAT_144e29820 == 0) {
      uVar5 = FUN_14292a3b0(&DAT_144e00bcb);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar5);
    }
    local_988 = 0;
    local_990 = 2;
    local_998 = 0;
    uVar5 = thunk_FUN_14625ae3b(DAT_144e29820,local_8d8,local_978,&local_948);
    FUN_1408a0410(local_5f8,uVar5);
    FUN_140676580(param_1 + 0x3a0,local_308,local_5f8);
    FUN_140675f50(local_308);
    FUN_140675f50(local_5f8);
    FUN_14268d730(local_8b8);
    FUN_142b4fcb0(local_8d8);
    local_918 = CONCAT44(uRam0000000144e11fd4,_DAT_144e11fd0);
    uStack_910 = CONCAT44(uRam0000000144e11fdc,uRam0000000144e11fd8);
    local_908 = CONCAT44(uRam0000000144e11fe4,_DAT_144e11fe0);
    _uStack_900 = CONCAT44(uRam0000000144e11fec,uRam0000000144e11fe8);
    local_998 = 0;
    FUN_1416258a0(param_1 + 0x3a0,&local_918,local_978 + 2,0);
    FUN_142b513a0(param_1 + 0x3b0,0,0);
    puVar4 = &DAT_1438da058;
    lVar6 = FUN_142b56080(&DAT_1438da058,2,DAT_144e2e5b0);
    *(longlong *)(param_1 + 0x690) = lVar6;
    if (lVar6 != 0) {
      local_978[0] = *(undefined4 *)(param_1 + 0x698);
      local_978[1] = *(undefined4 *)(param_1 + 0x69c);
      do {
        FUN_142b566d0(*(undefined8 *)(param_1 + 0x690),*puVar4,local_978[(int)uVar7]);
        uVar7 = uVar7 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar7 < 2);
      lVar6 = *(longlong *)(param_1 + 0x690);
      if (lVar6 != 0) {
        cVar3 = FUN_142b501b0(param_1 + 0xc0);
        if (cVar3 != '\0') {
          thunk_FUN_142b50b00(param_1 + 0xc0,lVar6);
        }
      }
      lVar6 = *(longlong *)(param_1 + 0x690);
      if (lVar6 != 0) {
        cVar3 = FUN_142b501b0(param_1 + 0x3b0);
        if (cVar3 != '\0') {
          thunk_FUN_142b50b00(param_1 + 0x3b0,lVar6);
        }
      }
    }
  }
  return;
}


  referenced from 1450a81f4 (DATA) in <no function>
  referenced from 1444dea30 (DATA) in <no function>

==== depth 1: FUN_140c51f10 @ 140c51f10 (1403 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_140c51f10(longlong param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined8 uVar5;
  longlong lVar6;
  float *pfVar7;
  undefined4 *puVar8;
  uint uVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  bool bVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined1 auStack_128 [32];
  float local_108;
  uint local_104;
  float local_f8 [4];
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  float local_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  ulonglong local_98;
  
  fVar2 = DAT_144241500;
  local_98 = DAT_144d9ff50 ^ (ulonglong)auStack_128;
  uVar10 = 0;
  bVar12 = DAT_144e0f598 != 0;
  uVar11 = uVar10;
  if (bVar12) {
    uVar11 = *(ulonglong *)(DAT_144e0f598 + 0xa5a0);
  }
  local_104 = (uint)bVar12;
  if (bVar12) {
    local_104 = 0;
  }
  if (uVar11 != 0) {
    FUN_14073d4f0(uVar11,&local_e8);
    lVar6 = DAT_144f71c70;
    uVar5 = FUN_140665ba0(*(undefined8 *)(param_1 + 0x18),&local_108);
    local_a8 = (float)FUN_141324470(uVar5);
    local_a4 = 0.0;
    lVar6 = FUN_14235ef90(*(undefined8 *)(lVar6 + 0xc6b8),&local_a8);
    local_f8[0] = *(float *)(lVar6 + 0x40);
    local_f8[1] = *(float *)(lVar6 + 0x44);
    local_f8[2] = *(float *)(lVar6 + 0x48);
    local_f8[3] = *(float *)(lVar6 + 0x4c);
    if (DAT_144e13db0 == 0) {
      uVar5 = FUN_14292a3b0(&DAT_144e08ec5);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar5);
    }
    fVar13 = (float)FUN_140b5a580();
    FUN_14073ca10(uVar11,&local_a8);
    local_b8 = local_a8 + local_f8[0] * fVar13;
    fStack_b4 = local_a4 + local_f8[1] * fVar13;
    fStack_b0 = local_a0 + local_f8[2] * fVar13;
    local_e8 = _DAT_1442383a0;
    uStack_e0 = _UNK_1442383a8;
    local_d8 = _DAT_1442389c0;
    uStack_d0 = _DAT_1442389c8;
    local_c8 = _DAT_1442389d0;
    uStack_c0 = _UNK_1442389d8;
    fStack_ac = fVar2;
    FUN_142b50c60(param_1 + 0xc0,&local_e8);
    FUN_142b50c60(param_1 + 0x3b0,&local_e8);
  }
  if (DAT_144e13db0 == 0) {
    uVar5 = FUN_14292a3b0(&DAT_144e08ec5);
                    /* WARNING: Subroutine does not return */
    FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                  ,0xb4,&DAT_144234158,uVar5);
  }
  FUN_142940b20();
  if (DAT_144e13db0 == 0) {
    uVar5 = FUN_14292a3b0(&DAT_144e08ec5);
                    /* WARNING: Subroutine does not return */
    FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                  ,0xb4,&DAT_144234158,uVar5);
  }
  FUN_142940b20();
  fVar13 = (float)thunk_FUN_1401a7607();
  if (DAT_144e13db0 != 0) {
    fVar14 = (float)FUN_140b5a4c0();
    fVar15 = (float)thunk_FUN_1404dc1bb();
    fVar16 = (float)thunk_FUN_145912e87();
    fVar3 = DAT_144241554;
    fVar1 = DAT_143760d34;
    if (fVar16 < fVar15) {
      if (fVar14 < DAT_144241554) {
        fVar14 = fVar14 + DAT_143760d34;
      }
      fVar16 = fVar16 + DAT_143760d34;
    }
    if ((fVar14 < fVar15) || (fVar16 <= fVar14)) {
      cVar4 = '\0';
    }
    else {
      cVar4 = '\x01';
    }
    FUN_142b513a0(param_1 + 0xc0,cVar4,0);
    if (cVar4 == '\0') {
      *(undefined4 *)(param_1 + 0x698) = 0;
    }
    else if ((fVar14 < fVar15) || (fVar15 + fVar13 <= fVar14)) {
      if ((fVar14 < fVar16 - fVar13) || (fVar16 <= fVar14)) {
        *(undefined4 *)(param_1 + 0x698) = 0x3f800000;
      }
      else {
        *(float *)(param_1 + 0x698) = fVar2 - (fVar14 - (fVar16 - fVar13)) / fVar13;
      }
    }
    else {
      *(float *)(param_1 + 0x698) = (fVar14 - fVar15) / fVar13;
    }
    if (DAT_144e13db0 != 0) {
      fVar14 = (float)FUN_140b5a4c0();
      fVar15 = (float)thunk_FUN_14142c7ef();
      fVar16 = (float)thunk_FUN_140dc5b66();
      if (fVar16 < fVar15) {
        if (fVar14 < fVar3) {
          fVar14 = fVar14 + fVar1;
        }
        fVar16 = fVar16 + fVar1;
      }
      if ((fVar14 < fVar15) || (fVar16 <= fVar14)) {
        cVar4 = '\0';
      }
      else {
        cVar4 = '\x01';
      }
      FUN_142b513a0(param_1 + 0x3b0,cVar4,0);
      if (cVar4 == '\0') {
        *(undefined4 *)(param_1 + 0x69c) = 0;
      }
      else if ((fVar14 < fVar15) || (fVar15 + fVar13 <= fVar14)) {
        if ((fVar14 < fVar16 - fVar13) || (fVar16 <= fVar14)) {
          *(undefined4 *)(param_1 + 0x69c) = 0x3f800000;
        }
        else {
          *(float *)(param_1 + 0x69c) = fVar2 - (fVar14 - (fVar16 - fVar13)) / fVar13;
        }
      }
      else {
        *(float *)(param_1 + 0x69c) = (fVar14 - fVar15) / fVar13;
      }
      if (*(longlong *)(param_1 + 0x690) != 0) {
        fVar13 = *(float *)(param_1 + 0x698);
        local_a8 = 0.0;
        if (0.0 <= fVar13) {
          pfVar7 = &local_108;
          if (fVar13 <= fVar2) {
            pfVar7 = (float *)(param_1 + 0x698);
          }
        }
        else {
          pfVar7 = &local_a8;
        }
        local_f8[0] = *pfVar7;
        fVar13 = *(float *)(param_1 + 0x69c);
        local_a8 = 1.0;
        local_108 = 0.0;
        if (0.0 <= fVar13) {
          pfVar7 = &local_a8;
          if (fVar13 <= fVar2) {
            pfVar7 = (float *)(param_1 + 0x69c);
          }
        }
        else {
          pfVar7 = &local_108;
        }
        puVar8 = &DAT_1438da058;
        local_f8[1] = *pfVar7;
        do {
          FUN_142b566d0(*(undefined8 *)(param_1 + 0x690),*puVar8,local_f8[(int)uVar10]);
          uVar9 = (int)uVar10 + 1;
          uVar10 = (ulonglong)uVar9;
          puVar8 = puVar8 + 1;
        } while (uVar9 < 2);
        lVar6 = *(longlong *)(param_1 + 0x690);
        if ((lVar6 != 0) && (cVar4 = FUN_142b501b0(param_1 + 0xc0), cVar4 != '\0')) {
          thunk_FUN_142b50b00(param_1 + 0xc0,lVar6);
        }
        lVar6 = *(longlong *)(param_1 + 0x690);
        if ((lVar6 != 0) && (cVar4 = FUN_142b501b0(param_1 + 0x3b0), cVar4 != '\0')) {
          thunk_FUN_142b50b00(param_1 + 0x3b0,lVar6);
        }
      }
      return;
    }
    uVar5 = FUN_14292a3b0(&DAT_144e08ec5);
                    /* WARNING: Subroutine does not return */
    FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                  ,0xb4,&DAT_144234158,uVar5);
  }
  uVar5 = FUN_14292a3b0(&DAT_144e08ec5);
                    /* WARNING: Subroutine does not return */
  FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                ,0xb4,&DAT_144234158,uVar5);
}


  referenced from 1450a8278 (DATA) in <no function>

==== depth 1: FUN_14137d953 @ 14137d953 (312 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000028 : 0x00014137d9ac */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_14137d953(float param_1)

{
  longlong lVar1;
  longlong lVar2;
  char cVar3;
  undefined8 uVar4;
  longlong lVar5;
  longlong unaff_RBP;
  longlong lVar6;
  float fVar7;
  float in_stack_00000028;
  
  fVar7 = DAT_144d72d30;
  if ((((uint)in_stack_00000028 & 0x7f800000) != 0x7f800000 ||
       ((uint)in_stack_00000028 & 0x7fffff) == 0) && (fVar7 = param_1, param_1 <= in_stack_00000028)
     ) {
    fVar7 = in_stack_00000028;
  }
  FUN_142b566d0(*(undefined8 *)(unaff_RBP + 0xaa8),DAT_143a954c4,fVar7);
  lVar1 = *(longlong *)(unaff_RBP + 0xa90);
  lVar5 = *(longlong *)(unaff_RBP + 0xa88);
  if (lVar5 != lVar1) {
    lVar6 = lVar5 + 0x10;
    do {
      if (*(longlong *)(lVar6 + 0x2e0) != 0) {
        uVar4 = FUN_14137efe0(*(undefined8 *)(unaff_RBP + 8),&stack0x00000060);
        FUN_14137aa60(&stack0x00000030,*(undefined8 *)(lVar6 + 0x2e0),uVar4);
        lVar2 = *(longlong *)(unaff_RBP + 0xaa8);
        if ((lVar2 != 0) && (cVar3 = FUN_142b501b0(lVar6), cVar3 != '\0')) {
          thunk_FUN_142b50b00(lVar6,lVar2);
        }
      }
      lVar5 = lVar5 + 0x300;
      lVar6 = lVar6 + 0x300;
    } while (lVar5 != lVar1);
  }
  return;
}


  referenced from 145995123 (UNCONDITIONAL_CALL) in FUN_1459950b5 @ 1459950b5

==== depth 1: FUN_14161f7f7 @ 14161f7f7 (1045 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Heritage AFTER dead removal. Example location: s0x00000050 : 0x00014161fa58 */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_14161f7f7(void)

{
  float fVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float fVar11;
  char cVar12;
  undefined1 uVar13;
  int iVar14;
  longlong *plVar15;
  uint *puVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  undefined4 *puVar19;
  longlong lVar20;
  longlong lVar21;
  longlong unaff_RBP;
  longlong unaff_RSI;
  float fVar22;
  undefined4 uVar23;
  undefined1 auVar24 [16];
  undefined4 uVar25;
  undefined4 in_stack_00000050;
  float fStack0000000000000060;
  float fStack0000000000000064;
  float fStack0000000000000068;
  float fStack000000000000006c;
  undefined4 uStack0000000000000070;
  undefined4 uStack0000000000000074;
  undefined4 uStack0000000000000078;
  
  iVar14 = FUN_1412fefa0();
  if (iVar14 == *(int *)(unaff_RSI + 0x370)) {
    plVar15 = (longlong *)FUN_142923d10();
    *(longlong **)(unaff_RBP + -0x80) = plVar15;
    puVar16 = (uint *)(**(code **)(*plVar15 + 0x18))(plVar15,&stack0x00000050,0);
    if ((*puVar16 >> 5 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0(0,0x3e,"Tried to create container with incompatible heap.");
    }
    *(undefined8 *)(unaff_RBP + -0x78) = 0;
    *(undefined8 *)(unaff_RBP + -0x70) = 0;
    *(undefined8 *)(unaff_RBP + -0x68) = 0;
    FUN_140bdb930(unaff_RBP + -0x80,8);
    fVar11 = DAT_144241500;
    lVar21 = *(longlong *)(unaff_RSI + 0x378);
    fStack0000000000000068 = *(float *)(lVar21 + 0x2c);
    fStack0000000000000064 = *(float *)(lVar21 + 0x1c);
    fStack0000000000000060 = *(float *)(lVar21 + 0xc);
    fStack000000000000006c = DAT_144241500;
    uVar17 = (ulonglong)(*(int *)(unaff_RSI + 0x370) - 1);
    fVar3 = *(float *)(lVar21 + uVar17 * 0x30 + 0x2c);
    fVar4 = *(float *)(lVar21 + uVar17 * 0x30 + 0x1c);
    fVar1 = *(float *)(lVar21 + 0xc + uVar17 * 0x30);
    _uStack0000000000000070 = 0;
    _uStack0000000000000078 = 0;
    if (DAT_144e210f8 == 0) {
      uVar18 = FUN_14292a3b0(&DAT_144e0088a);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar18);
    }
    lVar20 = *(longlong *)(DAT_144e210f8 + 0x78);
    if (lVar20 != 0) {
      fVar22 = DAT_144241500 - DAT_144241500;
      *(float *)(unaff_RBP + -0x50) = fVar1 - *(float *)(lVar21 + 0xc);
      *(float *)(unaff_RBP + -0x4c) = fVar4 - fStack0000000000000064;
      *(float *)(unaff_RBP + -0x48) = fVar3 - fStack0000000000000068;
      *(float *)(unaff_RBP + -0x44) = fVar22;
      cVar12 = FUN_1414abbe0(lVar20,0x48,&stack0x00000060,unaff_RBP + -0x50,&stack0x00000070);
      if (cVar12 == '\0') {
        _uStack0000000000000070 = CONCAT44(fVar4,fVar1);
        _uStack0000000000000078 = CONCAT44(fVar11,fVar3);
      }
    }
    puVar2 = *(undefined4 **)(unaff_RBP + -0x78);
    lVar21 = 4;
    puVar19 = puVar2;
    do {
      uVar9 = puVar2[1];
      uVar10 = puVar2[2];
      uVar7 = puVar2[4];
      uVar25 = puVar2[5];
      uVar8 = puVar2[6];
      uVar23 = puVar2[8];
      uVar5 = puVar2[9];
      uVar6 = puVar2[10];
      *puVar19 = *puVar2;
      puVar19[1] = uVar9;
      puVar19[2] = uVar10;
      puVar19[3] = fStack0000000000000060;
      puVar19[4] = uVar7;
      puVar19[5] = uVar25;
      puVar19[6] = uVar8;
      puVar19[7] = fStack0000000000000064;
      puVar19[8] = uVar23;
      puVar19[9] = uVar5;
      puVar19[10] = uVar6;
      puVar19[0xb] = fStack0000000000000068;
      uVar9 = puVar2[0xd];
      uVar10 = puVar2[0xe];
      uVar7 = puVar2[0x10];
      uVar25 = puVar2[0x11];
      uVar8 = puVar2[0x12];
      uVar23 = puVar2[0x14];
      uVar5 = puVar2[0x15];
      uVar6 = puVar2[0x16];
      puVar19[0xc] = puVar2[0xc];
      puVar19[0xd] = uVar9;
      puVar19[0xe] = uVar10;
      puVar19[0xf] = uStack0000000000000070;
      puVar19[0x10] = uVar7;
      puVar19[0x11] = uVar25;
      puVar19[0x12] = uVar8;
      puVar19[0x13] = uStack0000000000000074;
      puVar19[0x14] = uVar23;
      puVar19[0x15] = uVar5;
      puVar19[0x16] = uVar6;
      puVar19[0x17] = uStack0000000000000078;
      puVar19 = puVar19 + 0x18;
      lVar21 = lVar21 + -1;
    } while (lVar21 != 0);
    auVar24._0_4_ =
         (fVar1 - fStack0000000000000060) * (fVar1 - fStack0000000000000060) +
         (fVar3 - fStack0000000000000068) * (fVar3 - fStack0000000000000068) +
         (fVar4 - fStack0000000000000064) * (fVar4 - fStack0000000000000064);
    auVar24._4_4_ = auVar24._0_4_;
    auVar24._8_4_ = auVar24._0_4_;
    auVar24._12_4_ = auVar24._0_4_;
    auVar24 = sqrtps(auVar24,auVar24);
    uVar23 = auVar24._0_4_;
    in_stack_00000050 = uVar23;
    FUN_142b566d0(*(undefined8 *)(unaff_RSI + 0x388),DAT_143b10488,uVar23);
    *(undefined4 **)(unaff_RBP + -0x50) = &stack0x00000050;
    lVar21 = DAT_144e29820;
    in_stack_00000050 = *(undefined4 *)(unaff_RSI + 0x70);
    if (DAT_144e29820 == 0) {
      uVar18 = FUN_14292a3b0(&DAT_144e00bcb);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar18);
    }
    FUN_14162bd00(unaff_RSI + 0x28);
    uVar18 = *(undefined8 *)(unaff_RSI + 0x388);
    lVar20 = thunk_FUN_14625ae3b(lVar21,unaff_RBP + -0x40,&stack0x00000050,
                                 *(undefined8 *)(unaff_RSI + 0x378),uVar18);
    uVar25 = (undefined4)((ulonglong)uVar18 >> 0x20);
    lVar21 = unaff_RSI + 0x90;
    FUN_142b4fd10(lVar21,lVar20);
    uVar5 = *(undefined4 *)(lVar20 + 0x24);
    uVar6 = *(undefined4 *)(lVar20 + 0x28);
    uVar7 = *(undefined4 *)(lVar20 + 0x2c);
    *(undefined4 *)(unaff_RSI + 0xb0) = *(undefined4 *)(lVar20 + 0x20);
    *(undefined4 *)(unaff_RSI + 0xb4) = uVar5;
    *(undefined4 *)(unaff_RSI + 0xb8) = uVar6;
    *(undefined4 *)(unaff_RSI + 0xbc) = uVar7;
    thunk_FUN_1459abb11(unaff_RSI + 0xc0,lVar20 + 0x30);
    FUN_14268d730(unaff_RBP + -0x20);
    FUN_142b4fcb0(unaff_RBP + -0x40);
    *(undefined4 *)(unaff_RBP + -0x4c) = *(undefined4 *)(unaff_RSI + 0x5c);
    *(undefined4 *)(unaff_RBP + -0x50) = *(undefined4 *)(unaff_RSI + 0x58);
    FUN_14268dfd0(lVar21,unaff_RBP + -0x50);
    uVar13 = FUN_14161bb00();
    FUN_142b513a0(lVar21,uVar13,0);
    FUN_14268d860(lVar21,puVar2,2,8,CONCAT44(uVar25,uVar23));
    *(undefined8 *)(unaff_RBP + -0x50) = *(undefined8 *)(unaff_RSI + 0x60);
    *(undefined4 *)(unaff_RBP + -0x48) = *(undefined4 *)(unaff_RSI + 0x68);
    FUN_142b510d0(lVar21,unaff_RBP + -0x50);
    thunk_FUN_142b50b00(lVar21,*(undefined8 *)(unaff_RSI + 0x388));
    (**(code **)(**(longlong **)(unaff_RBP + -0x80) + 0x68))
              (*(longlong **)(unaff_RBP + -0x80),puVar2);
    *(undefined8 *)(unaff_RBP + -0x78) = 0;
    *(undefined8 *)(unaff_RBP + -0x70) = 0;
    *(undefined8 *)(unaff_RBP + -0x68) = 0;
  }
  cVar12 = FUN_142b501b0(unaff_RSI + 0x90);
  if (cVar12 == '\0') {
    FUN_14161ba30();
  }
  return 1;
}


  referenced from 145ab3a5c (UNCONDITIONAL_CALL) in FUN_145ab3a05 @ 145ab3a05

==== depth 1: FUN_14161ff90 @ 14161ff90 (420 bytes)

void FUN_14161ff90(void)

{
  undefined4 uVar1;
  longlong lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint *puVar5;
  ulonglong uVar6;
  undefined8 uVar7;
  int unaff_EBX;
  longlong unaff_RBP;
  undefined4 *unaff_RSI;
  longlong unaff_RDI;
  bool bVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float unaff_XMM6_Dd;
  float unaff_XMM7_Dd;
  float unaff_XMM8_Dd;
  float unaff_XMM12_Da;
  longlong *in_stack_00000058;
  undefined8 in_stack_00000060;
  undefined8 in_stack_00000068;
  
  do {
    FUN_142b566d0(*(undefined8 *)(unaff_RDI + 0x388),*unaff_RSI,
                  *(undefined4 *)(&stack0x00000050 + (longlong)unaff_EBX * 4));
    unaff_RSI = unaff_RSI + 1;
    bVar8 = unaff_EBX == -1;
    unaff_EBX = 0;
  } while (bVar8);
  in_stack_00000058 = (longlong *)FUN_142923d10();
  puVar5 = (uint *)(**(code **)(*in_stack_00000058 + 0x18))(in_stack_00000058,&stack0x00000050,0);
  if ((*puVar5 >> 5 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1429213b0(0,0x3e,"Tried to create container with incompatible heap.");
  }
  in_stack_00000060 = 0;
  in_stack_00000068 = 0;
  FUN_140bdb930(&stack0x00000058,8);
  lVar2 = *(longlong *)(unaff_RDI + 0x378);
  fVar9 = (*(float *)(lVar2 + 0x1c) - unaff_XMM7_Dd) * DAT_1442414d8;
  fVar10 = (*(float *)(lVar2 + 0x2c) - unaff_XMM6_Dd) * DAT_1442414d8;
  fVar11 = (unaff_XMM12_Da - unaff_XMM12_Da) * DAT_1442414d8;
  *(float *)(unaff_RBP + -0x50) =
       (*(float *)(lVar2 + 0xc) - unaff_XMM8_Dd) * DAT_1442414d8 + unaff_XMM8_Dd;
  *(float *)(unaff_RBP + -0x4c) = fVar9 + unaff_XMM7_Dd;
  *(float *)(unaff_RBP + -0x48) = fVar10 + unaff_XMM6_Dd;
  *(float *)(unaff_RBP + -0x44) = fVar11 + unaff_XMM12_Da;
  uVar6 = (ulonglong)(*(int *)(unaff_RDI + 0x370) - 1);
  uVar3 = *(undefined4 *)(lVar2 + uVar6 * 0x30 + 0x2c);
  uVar4 = *(undefined4 *)(lVar2 + uVar6 * 0x30 + 0x1c);
  uVar1 = *(undefined4 *)(lVar2 + 0xc + uVar6 * 0x30);
  *(undefined8 *)(unaff_RBP + -0x80) = 0;
  *(undefined8 *)(unaff_RBP + -0x78) = 0;
  if (DAT_144e210f8 == 0) {
    uVar7 = FUN_14292a3b0(&DAT_144e0088a);
                    /* WARNING: Subroutine does not return */
    FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                  ,0xb4,&DAT_144234158,uVar7);
  }
  if (*(longlong *)(DAT_144e210f8 + 0x78) != 0) {
    FUN_145ff457f();
    return;
  }
  FUN_1465c86df(uVar3,lVar2,uVar4,uVar1);
  return;
}


  referenced from 14161ffaf (CONDITIONAL_JUMP) in FUN_14161ff90 @ 14161ff90
  referenced from 1413fee1f (UNCONDITIONAL_CALL) in FUN_1413fed8a @ 1413fed8a

==== depth 1: FUN_14162aca0 @ 14162aca0 (497 bytes)

void FUN_14162aca0(longlong param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong *plVar1;
  undefined4 uVar2;
  char cVar3;
  undefined8 uVar4;
  longlong *plVar5;
  longlong *plVar6;
  float fVar7;
  
  if (*(longlong *)(param_1 + 0xa8) == 0) {
    return;
  }
  if (*(char *)(param_1 + 0xb2) == '\0') {
    if (DAT_144f30f38 == 0) {
      uVar4 = FUN_14292a3b0(&DAT_144e062c1,param_2,param_3,param_4,0xfffffffffffffffe);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar4);
    }
    *(bool *)(param_1 + 0xb2) =
         *(float *)(DAT_144f30f38 + 0x2d8) <= DAT_144e29828 &&
         DAT_144e29828 != *(float *)(DAT_144f30f38 + 0x2d8);
  }
  else {
    if (DAT_144f30f38 == 0) {
      uVar4 = FUN_14292a3b0(&DAT_144e062c1,param_2,param_3,param_4,0xfffffffffffffffe);
                    /* WARNING: Subroutine does not return */
      FUN_1429213b0("w:\\fnr\\source\\library\\fd4\\dist_win64_vc2015\\include\\Core/Singleton/FD4Singleton.h"
                    ,0xb4,&DAT_144234158,uVar4);
    }
    if (DAT_144e29828 + DAT_144241518 < *(float *)(DAT_144f30f38 + 0x2d8)) {
      fVar7 = *(float *)(param_1 + 0xb4) - *(float *)(param_2 + 8);
      *(float *)(param_1 + 0xb4) = fVar7;
      if (fVar7 < 0.0) {
        *(undefined1 *)(param_1 + 0xb2) = 0;
      }
      goto LAB_14162adb3;
    }
  }
  *(undefined4 *)(param_1 + 0xb4) = 0x3f800000;
LAB_14162adb3:
  uVar2 = DAT_144241500;
  if (*(char *)(param_1 + 0xb2) == '\0') {
    uVar2 = 0;
  }
  FUN_142b566d0(*(undefined8 *)(param_1 + 0xa8),3,uVar2);
  FUN_14295c330(param_1 + 0x170,0xffffffff);
  plVar5 = (longlong *)**(longlong **)(param_1 + 0x60);
  if (plVar5 != *(longlong **)(param_1 + 0x60)) {
    do {
      plVar1 = plVar5 + 2;
      cVar3 = FUN_142b501b0(plVar1);
      if (cVar3 == '\0') {
        plVar6 = (longlong *)*plVar5;
        *(longlong **)plVar5[1] = plVar6;
        *(longlong *)(*plVar5 + 8) = plVar5[1];
        *(longlong *)(param_1 + 0x68) = *(longlong *)(param_1 + 0x68) + -1;
        FUN_14268d730(plVar5 + 6);
        FUN_142b4fcb0(plVar1);
        (**(code **)(**(longlong **)(param_1 + 0x58) + 0x68))(*(longlong **)(param_1 + 0x58),plVar5)
        ;
      }
      else {
        thunk_FUN_142b50b00(plVar1,*(undefined8 *)(param_1 + 0xa8));
        plVar6 = (longlong *)*plVar5;
      }
      plVar5 = plVar6;
    } while (plVar6 != *(longlong **)(param_1 + 0x60));
  }
  FUN_14295c430(param_1 + 0x170);
  return;
}


  referenced from 14514dae8 (DATA) in <no function>
  referenced from 14487bfe0 (DATA) in <no function>
  referenced from 14162207e (DATA) in <no function>
  referenced from 141622085 (DATA) in <no function>

==== depth 1: FUN_14092e7d8 @ 14092e7d8 (104 bytes)

void FUN_14092e7d8(void)

{
  longlong *plVar1;
  undefined4 uVar2;
  undefined4 uStack0000000000000030;
  
  uStack0000000000000030 = 0;
  uVar2 = FUN_142b566d0(0,0x1117a,0);
  FUN_142b566d0(uVar2,0x1118e,uStack0000000000000030);
  FUN_14161b610();
  plVar1 = DAT_144e2e5f0;
  FUN_142b550a0();
  (**(code **)(*plVar1 + 0x68))(plVar1);
  return;
}


  referenced from 14631f8e9 (UNCONDITIONAL_CALL) in FUN_14631f8dd @ 14631f8dd
