Test package for FXR external values (Research\FXR external values\notes.md). Based on 1.09.1 files.

regulation.bin (raw .param patches, repacked with WitchyBND 3.0.1):
- Bullet[10110000] (RF-024 TURNER): sfxId_Bullet 6012101 -> 300031, life -1 -> 600 s, dist 629 -> 100000,
  initVellocity/maxVellocity 550 -> 0.01, minVellocity 10 -> 0 (bullets hang in place)
- AtkParam_Pc[20100000], [20100010] (HI-32: BU-TT/A pulse blade attacks 1/2): hit0_SfxId -1 -> 600030

sfx/sfxbnd_commoneffects.ffxbnd.dcx: stock bnd with only f000300031.fxr (the TURNER bullet effect) replaced by
the bar chart test FXR (Research\FXR external values\testfx\make_bar_fxr.mjs). Values from other spawners reach it
through the logger DLL's overrides (Game\debug-logs\fxr_extvalues_overrides.txt, default "* mirror").

Chart: 12 m above the effect, facing the camera. Bars left to right, gaps between color groups:
  white  1, 3, 1000, 2000 (0-100), 10000 (-1..1), 20000 (0-200), 30000, 30001
  orange 40000 (0-100), 40001, 40002 (0-90)
  green  50000 (0-100), 50001 (0-100), 60000 (0-800)
  blue   70000 (0-60), 70010 (0-100), 70020 (0-1000), 70030
  purple 70100 (0-100), 70200 (0-1000)
Ranges not listed are 0-1. Bright bar = value, dim wider bar = full range.
