#!/usr/local/bin/zsh


# Generate the NOMINAL case
# rbplotter draw_eff_3D.xml
# rbplotter draw_eff_costheta.xml
# rbplotter draw_eff_dphi.xml
# rbplotter draw_eff_mass.xml
# rbplotter draw_eff_pt.xml
# rbplotter draw_eff_pt2.xml
# rbplotter draw_eff_rap.xml

# Generate the TIGHT case
# rbplotter draw_eff_3D.xml --cut:nHitsDedx=20 --cut:nHitsFit=25 --ver="TIGHT"
# rbplotter draw_eff_costheta.xml --cut:nHitsDedx=20 --cut:nHitsFit=25 --ver="TIGHT"
# rbplotter draw_eff_dphi.xml --cut:nHitsDedx=20 --cut:nHitsFit=25 --ver="TIGHT"
# rbplotter draw_eff_mass.xml --cut:nHitsDedx=20 --cut:nHitsFit=25 --ver="TIGHT"
# rbplotter draw_eff_pt.xml --cut:nHitsDedx=20 --cut:nHitsFit=25 --ver="TIGHT"
# rbplotter draw_eff_pt2.xml --cut:nHitsDedx=20 --cut:nHitsFit=25 --ver="TIGHT"
# rbplotter draw_eff_rap.xml --cut:nHitsDedx=20 --cut:nHitsFit=25 --ver="TIGHT"


rbplotter draw_eff_mass.xml --cut:nHitsDedx=15 --cut:nHitsFit=25 --ver="SYS0"
rbplotter draw_eff_mass.xml --cut:nHitsDedx=20 --cut:nHitsFit=20 --ver="SYS1"