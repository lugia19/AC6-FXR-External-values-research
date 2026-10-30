Slim version of fxr-extvalue-test (Research\FXR external values - writeup): the chart only shows the identified
external values that change during normal play. Based on 1.09.1 files.

regulation.bin: same as fxr-extvalue-test (RF-024 TURNER bullets use FXR 300031 and hang in place for 600 s; the
pulse blade hit0_SfxId edit is also still in it).

sfx/sfxbnd_commoneffects.ffxbnd.dcx: stock bnd with f000300031.fxr replaced by the slim bar chart
(Research\FXR external values\testfx\make_bar_fxr.mjs, preset "slim"). Needs the logger DLL with "* mirror" in
Game\debug-logs\fxr_extvalues_overrides.txt to receive values from other systems.

Chart: 12 m above the bullet, facing the camera, scaled with camera distance. Bars left to right:
  white   2000   camera distance       0-100 m
  orange  40000  booster output        0-100 %
  orange  40001  speed ratio (vertical or horizontal, see writeup)  0-1
  green   60000  grounded speed        0-800 km/h (0 in the air)
  blue    70000  pulse armor radius    0-20 m (9.5 for Pulse Armor = about half)
  purple  70200  scan distance         0-1000
  gold    40002  reference: stepped by the logger (rule "40002 step 0 1000 250 1" in
                 fxr_extvalues_overrides.txt): 0, 250, 500, 750, 1000, one step per second
  pink    900000 made-up ID, not a game value: only the logger provides it (rule "900000 sweep 0 1 4"):
                 rises and falls smoothly over 4 seconds
Bright bar = value, dim wider bar = full range.
