
==== depth 0: FUN_142b56080 @ 142b56080 (115 bytes)

undefined8 FUN_142b56080(longlong param_1,int param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 auStack_78 [22];
  undefined8 local_20;
  
  puVar2 = auStack_78;
  for (lVar1 = 0x1c; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_20 = 0xfffffffffffffffe;
  if ((param_1 != 0) && (param_2 != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_142923280(0x20,8,param_3);
  }
  return 0;
}


  referenced from 145287948 (DATA) in <no function>
  referenced from 14162595b (UNCONDITIONAL_CALL) in FUN_141625930 @ 141625930
  referenced from 14268d830 (UNCONDITIONAL_JUMP) in thunk_FUN_142b56080 @ 14268d830
  referenced from 144bae148 (DATA) in <no function>
  referenced from 140688a7b (UNCONDITIONAL_CALL) in FUN_1406887c0 @ 1406887c0
  referenced from 1408a7551 (UNCONDITIONAL_CALL) in FUN_1408a74f0 @ 1408a74f0
  referenced from 14092d276 (UNCONDITIONAL_CALL) in FUN_14092d0e5 @ 14092d0e5
  referenced from 1408a1514 (UNCONDITIONAL_CALL) in FUN_1408a14b0 @ 1408a14b0
  referenced from 1408736e0 (UNCONDITIONAL_CALL) in FUN_140873610 @ 140873610
  referenced from 1408eb02d (UNCONDITIONAL_CALL) in FUN_1408eb000 @ 1408eb000
  referenced from 140927e0c (UNCONDITIONAL_CALL) in FUN_140927b60 @ 140927b60
  referenced from 14092ef5b (UNCONDITIONAL_CALL) in FUN_14092ef27 @ 14092ef27
  referenced from 140c51ac5 (UNCONDITIONAL_CALL) in FUN_140c517d0 @ 140c517d0
  referenced from 14137a4d7 (UNCONDITIONAL_CALL) in FUN_14137a3a0 @ 14137a3a0
  referenced from 1408e9344 (UNCONDITIONAL_CALL) in FUN_1408e92c8 @ 1408e92c8
  referenced from 14088f564 (UNCONDITIONAL_CALL) in <no function>
  referenced from 140937ac2 (UNCONDITIONAL_CALL) in FUN_140937aa1 @ 140937aa1
  referenced from 140938803 (UNCONDITIONAL_CALL) in FUN_1409387ee @ 1409387ee
  referenced from 1409284bc (UNCONDITIONAL_CALL) in FUN_140928494 @ 140928494
  referenced from 14092e7cb (UNCONDITIONAL_CALL) in FUN_14092e790 @ 14092e790
  referenced from 14161efec (UNCONDITIONAL_CALL) in FUN_14161ef60 @ 14161ef60
  referenced from 14162290f (UNCONDITIONAL_CALL) in <no function>
  referenced from 14162295c (UNCONDITIONAL_CALL) in <no function>

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

==== depth 1: thunk_FUN_142b56080 @ 14268d830 (5 bytes)

undefined8 thunk_FUN_142b56080(longlong param_1,int param_2,undefined8 param_3)

{
  longlong lVar1;
  undefined4 *puVar2;
  undefined4 auStack_78 [22];
  undefined8 uStack_20;
  
  puVar2 = auStack_78;
  for (lVar1 = 0x1c; lVar1 != 0; lVar1 = lVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  uStack_20 = 0xfffffffffffffffe;
  if ((param_1 != 0) && (param_2 != 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_142923280(0x20,8,param_3);
  }
  return 0;
}


  referenced from 1416282cd (UNCONDITIONAL_CALL) in FUN_141628270 @ 141628270

==== depth 1: FUN_1406887c0 @ 1406887c0 (754 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1406887c0(longlong param_1,int param_2)

{
  float fVar1;
  char cVar2;
  longlong lVar3;
  undefined8 uVar4;
  float fVar6;
  undefined8 extraout_XMM0_Qb;
  float fVar7;
  undefined1 auVar5 [16];
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar14;
  undefined1 auVar12 [16];
  undefined1 auVar13 [16];
  undefined1 auStack_6c8 [32];
  undefined8 *local_6a8;
  undefined8 local_698;
  undefined1 local_688 [16];
  undefined1 local_678 [16];
  undefined1 local_668 [16];
  undefined1 local_658 [48];
  undefined8 local_628;
  undefined8 uStack_620;
  undefined1 local_618 [752];
  undefined1 local_328 [752];
  ulonglong local_38;
  
  local_698 = 0xfffffffffffffffe;
  local_38 = DAT_144d9ff50 ^ (ulonglong)auStack_6c8;
  if (param_2 < 0) {
    if (*(char *)(param_1 + 0xfbb) == '\0') goto LAB_140688a1b;
  }
  else if (*(char *)(param_1 + 0xfbb) == '\0') {
    *(int *)(param_1 + 400) = param_2;
    local_628 = *(undefined8 *)(param_1 + 0x40);
    uStack_620 = *(undefined8 *)(param_1 + 0x48);
    lVar3 = FUN_14069d170();
    if ((*(longlong *)(lVar3 + 8) != 0) && (*(char *)(*(longlong *)(lVar3 + 8) + 0xd0) == '\x01')) {
      fVar11 = *(float *)(param_1 + 0x40);
      fVar6 = *(float *)(param_1 + 0x44);
      fVar7 = *(float *)(param_1 + 0x48);
      fVar1 = *(float *)(param_1 + 0x4c);
      fVar9 = fVar6 + fVar6;
      fVar10 = fVar7 + fVar7;
      fVar8 = fVar11 * (fVar11 + fVar11);
      fVar14 = fVar1 * (fVar11 + fVar11);
      local_688._4_4_ = fVar11 * fVar9 - fVar1 * fVar10;
      local_688._0_4_ = (_DAT_144fc47e0 - fVar6 * fVar9) - fVar7 * fVar10;
      local_688._8_4_ = fVar1 * fVar9 + fVar11 * fVar10;
      local_688._12_4_ = 0;
      local_678._4_4_ = (fRam0000000144fc47e4 - fVar8) - fVar7 * fVar10;
      local_678._0_4_ = fVar1 * fVar10 + fVar11 * fVar9;
      local_678._8_4_ = fVar6 * fVar10 - fVar14;
      local_678._12_4_ = 0;
      local_668._4_4_ = fVar14 + fVar6 * fVar10;
      local_668._0_4_ = fVar11 * fVar10 - fVar1 * fVar9;
      local_668._8_4_ = (fRam0000000144fc47e8 - fVar8) - fVar6 * fVar9;
      local_668._12_4_ = 0;
      FUN_14067ab80(local_658,local_688);
      auVar13._0_8_ = FUN_14037f970();
      auVar13._8_8_ = extraout_XMM0_Qb;
      fVar11 = (float)((ulonglong)auVar13._0_8_ >> 0x20);
      fVar6 = (float)extraout_XMM0_Qb;
      auVar12._8_4_ = fVar6;
      auVar12._0_8_ = auVar13._0_8_;
      fVar7 = (float)((ulonglong)extraout_XMM0_Qb >> 0x20);
      auVar12._12_4_ = fVar7;
      fVar11 = (float)auVar13._0_8_ * (float)auVar13._0_8_ + fVar6 * fVar6 +
               fVar11 * fVar11 + fVar7 * fVar7;
      auVar5._4_4_ = fVar11;
      auVar5._0_4_ = fVar11;
      auVar5._8_4_ = fVar11;
      auVar5._12_4_ = fVar11;
      auVar5 = sqrtps(auVar13,auVar5);
      auVar13 = divps(auVar12,auVar5);
      local_628 = CONCAT44(auVar13._4_4_ & -(uint)(auVar5._4_4_ != 0.0) &
                           -(uint)(fVar11 != _UNK_14421a834) |
                           ~-(uint)(fVar11 != _UNK_14421a834) & _UNK_14421a844,
                           auVar13._0_4_ & -(uint)(auVar5._0_4_ != 0.0) &
                           -(uint)(fVar11 != _DAT_14421a830) |
                           ~-(uint)(fVar11 != _DAT_14421a830) & _DAT_14421a840);
      uStack_620 = CONCAT44(auVar13._12_4_ & -(uint)(auVar5._12_4_ != 0.0) &
                            -(uint)(fVar11 != _UNK_14421a83c) |
                            ~-(uint)(fVar11 != _UNK_14421a83c) & _UNK_14421a84c,
                            auVar13._8_4_ & -(uint)(auVar5._8_4_ != 0.0) &
                            -(uint)(fVar11 != _UNK_14421a838) |
                            ~-(uint)(fVar11 != _UNK_14421a838) & _UNK_14421a848);
    }
    local_6a8 = &local_628;
    uVar4 = FUN_140698380(param_1,local_618,param_2,param_1 + 0x30);
    FUN_140676580(param_1 + 0x400,local_328,uVar4);
    FUN_140675f50(local_328);
    FUN_140675f50(local_618);
    FUN_14268e4a0(param_1 + 0x410,param_1 + 0x70);
    goto LAB_140688a1b;
  }
  FUN_140676580(param_1 + 0x400,local_618,param_1 + 0xfc0);
  FUN_140675f50(local_618);
LAB_140688a1b:
  lVar3 = FUN_14069d170(param_1);
  if (*(longlong *)(lVar3 + 8) == 0) {
    cVar2 = '\0';
  }
  else {
    cVar2 = *(char *)(*(longlong *)(lVar3 + 8) + 0xd2);
  }
  if ((DAT_144e09978 == '\0') && (cVar2 != '\x14')) {
    lVar3 = FUN_14069d170(param_1);
    if (*(longlong *)(lVar3 + 8) == 0) {
      return;
    }
    if (-1 < *(char *)(*(longlong *)(lVar3 + 8) + 0xd1)) {
      return;
    }
  }
  uVar4 = FUN_142b56080(&DAT_1437c1810,3,DAT_144e2e5e8);
  *(undefined8 *)(param_1 + 0x118) = uVar4;
  return;
}


  referenced from 145053ccc (DATA) in <no function>
  referenced from 1443a2448 (DATA) in <no function>
  referenced from 14069f4da (UNCONDITIONAL_CALL) in FUN_14069ecb0 @ 14069ecb0
  referenced from 14069f4ec (UNCONDITIONAL_CALL) in FUN_14069ecb0 @ 14069ecb0
  referenced from 14068d3de (UNCONDITIONAL_CALL) in FUN_14068d340 @ 14068d340
  referenced from 1406b55fe (UNCONDITIONAL_CALL) in FUN_1406b5550 @ 1406b5550
  referenced from 14069a138 (UNCONDITIONAL_CALL) in FUN_14069a080 @ 14069a080
  referenced from 14069bbf9 (UNCONDITIONAL_CALL) in FUN_14069baa0 @ 14069baa0

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

==== depth 1: FUN_14092d0e5 @ 14092d0e5 (429 bytes)

void FUN_14092d0e5(void)

{
  longlong lVar1;
  longlong *plVar2;
  undefined8 uVar3;
  undefined8 unaff_RBP;
  longlong unaff_RDI;
  undefined4 in_stack_00000030;
  byte in_stack_00000050;
  byte in_stack_00000058;
  undefined1 in_stack_00000060;
  int in_stack_00000068;
  undefined4 in_stack_00000070;
  byte in_stack_00000078;
  ushort in_stack_00000080;
  undefined8 *in_stack_00000088;
  undefined4 in_stack_00000090;
  byte in_stack_00000098;
  undefined8 *in_stack_000000a0;
  undefined4 in_stack_000000a8;
  undefined4 in_stack_000000b8;
  
  FUN_14161b480();
  *(ushort *)(unaff_RDI + 0x58) = *(ushort *)(unaff_RDI + 0x58) & 0x1f;
  *(undefined4 *)(unaff_RDI + 0xa4) = in_stack_00000070;
  *(undefined1 *)(unaff_RDI + 0x5a) = in_stack_00000060;
  *(undefined1 *)(unaff_RDI + 0x5b) = in_stack_00000060;
  *(ushort *)(unaff_RDI + 0x58) =
       ((((((((ushort)in_stack_00000098 << 4 | in_stack_00000080 & 3) * 2 |
            (ushort)(in_stack_00000078 & 1)) * 2 | (ushort)(in_stack_00000078 & 1)) * 2 |
          (ushort)(in_stack_00000058 & 1)) * 2 | (ushort)(in_stack_00000058 & 1)) * 2 |
        (ushort)(in_stack_00000050 & 1)) * 2 | (ushort)(in_stack_00000050 & 1)) << 5 |
       (in_stack_00000080 & 3) << 0xd | *(ushort *)(unaff_RDI + 0x58) & 0x7fff;
  *(undefined4 *)(unaff_RDI + 0x50) = in_stack_000000b8;
  *(undefined4 *)(unaff_RDI + 0x54) = in_stack_000000b8;
  uVar3 = *in_stack_00000088;
  *(undefined4 *)(unaff_RDI + 0x48) = in_stack_00000090;
  *(undefined8 *)(unaff_RDI + 0x38) = uVar3;
  uVar3 = *in_stack_000000a0;
  *(undefined4 *)(unaff_RDI + 0x4c) = in_stack_000000a8;
  *(undefined8 *)(unaff_RDI + 0x40) = uVar3;
  *(int *)(unaff_RDI + 0xa0) = in_stack_00000068;
  plVar2 = DAT_144e2e5e8;
  if (in_stack_00000068 != 0) {
    lVar1 = *(longlong *)(unaff_RDI + 0x98);
    if (lVar1 != 0) {
      FUN_142b550a0(lVar1);
      (**(code **)(*plVar2 + 0x68))(plVar2,lVar1);
      *(undefined8 *)(unaff_RDI + 0x98) = unaff_RBP;
    }
    in_stack_00000030 = *(undefined4 *)(unaff_RDI + 0xa0);
    uVar3 = FUN_142b56080(&stack0x00000030,1,DAT_144e2e5e8);
    *(undefined8 *)(unaff_RDI + 0x98) = uVar3;
  }
  return;
}


  referenced from 14649d700 (UNCONDITIONAL_CALL) in FUN_14649d6c6 @ 14649d6c6

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

==== depth 1: FUN_140873610 @ 140873610 (257 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_140873610(undefined8 param_1,longlong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_678 [32];
  undefined8 local_658;
  undefined8 local_650;
  undefined8 local_640;
  undefined8 local_638;
  undefined8 uStack_630;
  undefined8 local_628;
  undefined8 uStack_620;
  undefined4 local_618;
  undefined4 uStack_614;
  undefined4 uStack_610;
  undefined4 uStack_60c;
  undefined4 local_608;
  undefined4 uStack_604;
  undefined4 uStack_600;
  undefined4 uStack_5fc;
  undefined1 local_5f8 [752];
  undefined1 local_308 [752];
  ulonglong local_18;
  
  local_640 = 0xfffffffffffffffe;
  local_18 = DAT_144d9ff50 ^ (ulonglong)auStack_678;
  local_638 = *(undefined8 *)(param_2 + 0x30);
  uStack_630 = *(undefined8 *)(param_2 + 0x38);
  local_628 = *(undefined8 *)(param_2 + 0x40);
  uStack_620 = *(undefined8 *)(param_2 + 0x48);
  local_618 = *(undefined4 *)(param_2 + 0x50);
  uStack_614 = *(undefined4 *)(param_2 + 0x54);
  uStack_610 = *(undefined4 *)(param_2 + 0x58);
  uStack_60c = *(undefined4 *)(param_2 + 0x5c);
  local_608 = *(undefined4 *)(param_2 + 0x60);
  uStack_604 = *(undefined4 *)(param_2 + 100);
  uStack_600 = *(undefined4 *)(param_2 + 0x68);
  uStack_5fc = *(undefined4 *)(param_2 + 0x6c);
  iVar1 = *(int *)(param_2 + 0x70);
  if (-1 < iVar1) {
    uVar2 = FUN_140835a20();
    local_650 = 0;
    local_658 = 0;
    uVar2 = FUN_141626550(local_308,uVar2,iVar1,&local_638);
    FUN_140676580(param_2 + 0x80,local_5f8,uVar2);
    FUN_140675f50(local_5f8);
    FUN_140675f50(local_308);
    uVar2 = FUN_142b56080(&DAT_143813340,3,DAT_144e2e5e8);
    *(undefined8 *)(param_2 + 0x378) = uVar2;
  }
  return;
}


  referenced from 14506d9a0 (DATA) in <no function>
  referenced from 1443f79e8 (DATA) in <no function>
  referenced from 14086cec8 (UNCONDITIONAL_CALL) in FUN_14086c480 @ 14086c480

==== depth 1: FUN_1408eb000 @ 1408eb000 (60 bytes)

void FUN_1408eb000(longlong param_1)

{
  undefined8 uVar1;
  
  *(undefined8 *)(param_1 + 0x38) = *(undefined8 *)(param_1 + 0x30);
  FUN_1408eb990(param_1 + 0x48);
  uVar1 = FUN_142b56080(&DAT_143825154,1,DAT_144e2e5e8);
  *(undefined8 *)(param_1 + 0x60) = uVar1;
  return;
}


  referenced from 145073afc (DATA) in <no function>

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

==== depth 1: FUN_14137a3a0 @ 14137a3a0 (341 bytes)

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_14137a3a0(void)

{
  undefined8 uVar1;
  longlong lVar2;
  longlong lVar3;
  longlong unaff_RBP;
  longlong unaff_RDI;
  undefined8 unaff_R12;
  longlong unaff_R13;
  longlong unaff_R14;
  undefined8 unaff_R15;
  undefined8 in_stack_00000048;
  int in_stack_00000050;
  longlong in_stack_00000060;
  
  do {
    if (-1 < *(int *)(*(longlong *)(unaff_RDI + 8) + 0x100)) {
      lVar2 = *(longlong *)(unaff_RDI + 0x20);
      for (lVar3 = *(longlong *)(unaff_RDI + 0x18); lVar3 != lVar2; lVar3 = lVar3 + 0x40) {
        *(undefined8 *)(unaff_RBP + -0x40) = unaff_R12;
        *(longlong *)(unaff_RBP + -0x78) = unaff_RBP + -0x30;
        FUN_142b4fc60(unaff_RBP + -0x30);
        FUN_14268d710(unaff_RBP + -0x10);
        FUN_1402bd120();
        *(undefined8 *)(unaff_RBP + 0x2b0) = unaff_R15;
        *(undefined4 *)(unaff_RBP + 0x2b8) = 0xffffffff;
        *(longlong *)(unaff_RBP + 0x2b0) = lVar3;
        *(undefined4 *)(unaff_RBP + 0x2b8) = *(undefined4 *)(*(longlong *)(unaff_RDI + 8) + 0x100);
        FUN_14137e0a0(*(longlong *)(unaff_R13 + 0x10) + 0xa80,unaff_RBP + -0x40);
        FUN_140675f50(unaff_RBP + -0x40);
        unaff_R14 = in_stack_00000060;
      }
    }
    unaff_RDI = unaff_RDI + 0x30;
  } while (unaff_RDI != unaff_R14);
  lVar3 = *(longlong *)(unaff_R13 + 0x10);
  if (*(longlong *)(lVar3 + 0xa88) != *(longlong *)(lVar3 + 0xa90)) {
    (**(code **)(*(longlong *)(lVar3 + 0xae8) + 0x20))((longlong *)(lVar3 + 0xae8),0x36);
  }
  lVar2 = *(longlong *)(*(longlong *)(unaff_R13 + 0x10) + 0xa90) -
          *(longlong *)(*(longlong *)(unaff_R13 + 0x10) + 0xa88);
  lVar3 = lVar2 >> 0x3f;
  if (lVar2 / 0x300 + lVar3 != lVar3) {
    uVar1 = FUN_142b56080(&DAT_143a954c4,1,DAT_144e2e5e8);
    *(undefined8 *)(*(longlong *)(unaff_R13 + 0x10) + 0xaa8) = uVar1;
  }
  if (in_stack_00000048._4_4_ != 0) {
    uVar1 = FUN_141446cfe();
    return uVar1;
  }
  *(bool *)(*(longlong *)(unaff_R13 + 0x10) + 0x344) = in_stack_00000050 == 0;
  return 0;
}


  referenced from 14137a45b (CONDITIONAL_JUMP) in FUN_14137a3a0 @ 14137a3a0
  referenced from 14037b551 (UNCONDITIONAL_CALL) in FUN_14037b549 @ 14037b549

==== depth 1: FUN_1408e92c8 @ 1408e92c8 (147 bytes)

void FUN_1408e92c8(void)

{
  longlong *plVar1;
  uint *puVar2;
  undefined8 uVar3;
  undefined8 unaff_RBX;
  longlong unaff_RBP;
  longlong unaff_RSI;
  undefined8 *unaff_R14;
  
  plVar1 = (longlong *)thunk_FUN_14298bd70();
  DAT_144fc4ad8 = plVar1;
  *unaff_R14 = plVar1;
  puVar2 = (uint *)(**(code **)(*plVar1 + 0x18))(plVar1,&stack0x00000070,0);
  if ((*puVar2 >> 5 & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1429213b0(0,0x3e,"Tried to create container with incompatible heap.");
  }
  unaff_R14[1] = unaff_RBX;
  unaff_R14[2] = unaff_RBX;
  uVar3 = FUN_1408eab90();
  unaff_R14[1] = uVar3;
  *(undefined8 *)(unaff_RSI + 0x60) = unaff_RBX;
  *(undefined1 *)(unaff_RSI + 0x68) = 0;
  *(undefined8 *)(unaff_RBP + 0x10) = *(undefined8 *)(unaff_RBP + 8);
  FUN_1408eb990();
  uVar3 = FUN_142b56080(&DAT_143825154,1,DAT_144e2e5e8);
  *(undefined8 *)(unaff_RSI + 0x60) = uVar3;
  return;
}


  referenced from 140d9e9b5 (UNCONDITIONAL_CALL) in FUN_140d9e9a5 @ 140d9e9a5

==== depth 1: FUN_140937aa1 @ 140937aa1 (51 bytes)

void FUN_140937aa1(undefined8 param_1)

{
  undefined8 uVar1;
  longlong unaff_RBX;
  undefined8 *puStack0000000000000048;
  
  puStack0000000000000048 = (undefined8 *)(unaff_RBX + 0x60);
  *puStack0000000000000048 = param_1;
  *(undefined8 *)(unaff_RBX + 0x68) = param_1;
  uVar1 = FUN_142b56080(&DAT_14382ff48,(int)param_1 + 3,DAT_144e2e5e8);
  *(undefined8 *)(unaff_RBX + 0x68) = uVar1;
  return;
}


  referenced from 14441b188 (DATA) in <no function>
  referenced from 1405626c6 (UNCONDITIONAL_CALL) in FUN_140562688 @ 140562688

==== depth 1: FUN_1409387ee @ 1409387ee (39 bytes)

void FUN_1409387ee(undefined8 param_1)

{
  undefined8 uVar1;
  longlong unaff_RBX;
  
  *(undefined8 *)(unaff_RBX + 0x58) = param_1;
  uVar1 = FUN_142b56080(&DAT_143830138,(int)param_1 + 2,DAT_144e2e5e8);
  *(undefined8 *)(unaff_RBX + 0x58) = uVar1;
  return;
}


  referenced from 14441b490 (DATA) in <no function>
  referenced from 1402ce4eb (UNCONDITIONAL_CALL) in FUN_1402ce4e8 @ 1402ce4e8

==== depth 1: FUN_140928494 @ 140928494 (54 bytes)

void FUN_140928494(undefined8 param_1)

{
  undefined8 uVar1;
  longlong unaff_RBX;
  undefined8 *puStack0000000000000048;
  
  puStack0000000000000048 = (undefined8 *)(unaff_RBX + 0x60);
  *puStack0000000000000048 = param_1;
  *(undefined8 *)(unaff_RBX + 0x68) = param_1;
  *(undefined4 *)(unaff_RBX + 0x70) = 3;
  uVar1 = FUN_142b56080(&DAT_14382d6e8,(int)param_1 + 3,DAT_144e2e5e8);
  *(undefined8 *)(unaff_RBX + 0x68) = uVar1;
  FUN_1422f83d4();
  return;
}


  referenced from 1444175a0 (DATA) in <no function>
  referenced from 1464179eb (UNCONDITIONAL_CALL) in FUN_1464179ab @ 1464179ab

==== depth 1: FUN_14092e790 @ 14092e790 (70 bytes)

void FUN_14092e790(void)

{
  int iVar1;
  undefined4 in_stack_00000040;
  undefined4 uStack0000000000000044;
  
  FUN_1406b75f0();
  iVar1 = FUN_14161b560();
  if (iVar1 != 0) {
    in_stack_00000040 = 0x1117a;
    uStack0000000000000044 = 0x1118e;
    FUN_142b56080(&stack0x00000040,2,DAT_144e2e5f0);
    FUN_14631f8dd();
    return;
  }
  return;
}


  referenced from 145b0911d (UNCONDITIONAL_CALL) in FUN_145b0910e @ 145b0910e

==== depth 1: FUN_14161ef60 @ 14161ef60 (166 bytes)

undefined8 *
FUN_14161ef60(undefined8 *param_1,undefined4 *param_2,ulonglong param_3,undefined8 param_4)

{
  undefined8 uVar1;
  undefined4 local_res18 [2];
  
  local_res18[0] = *param_2;
  FUN_14161e2c0(param_1,local_res18,param_3,param_4,0xfffffffffffffffe);
  *param_1 = &DAT_143b10760;
  *(int *)(param_1 + 0x6e) = (int)param_3;
  param_1[0x6f] = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  uVar1 = (**(code **)(*DAT_144e2e5e8 + 0x50))(DAT_144e2e5e8,(param_3 & 0xffffffff) * 0x30,0x10);
  param_1[0x6f] = uVar1;
  uVar1 = FUN_142b56080(&DAT_143b10488,1,DAT_144e2e5e8);
  param_1[0x71] = uVar1;
  return param_1;
}


  referenced from 14514d17c (DATA) in <no function>
  referenced from 144879df0 (DATA) in <no function>
  referenced from 1416289ba (UNCONDITIONAL_CALL) in <no function>
