#include "d/dolzel.h" // IWYU pragma: keep

#include "d/d_kantera_icon_meter.h"
#include "JSystem/J2DGraph/J2DGrafContext.h"
#include "JSystem/J2DGraph/J2DScreen.h"
#include "d/d_com_inf_game.h"
#include "d/d_meter_HIO.h"
#include "d/d_pane_class.h"

#if TARGET_PC
#include "d/actor/d_a_alink.h"
#include "dusk/cosmetics/color_utils.hpp"
#endif

dKantera_icon_c::dKantera_icon_c() {
    initiate();
}

dKantera_icon_c::~dKantera_icon_c() {
    JKR_DELETE(mpKanteraIcon->getScreen());
    JKR_DELETE(mpKanteraIcon);
    mpKanteraIcon = NULL;

    JKR_DELETE(mpParent);
    mpParent = NULL;

    JKR_DELETE(mpGauge);
    mpGauge = NULL;
}

void dKantera_icon_c::initiate() {
    mpKanteraIcon = JKR_NEW dDlst_KanteraIcon_c();

    J2DScreen* scrn = JKR_NEW J2DScreen();
    scrn->setPriority("zelda_kantera_icon_mater.blo", 0x20000, dComIfGp_getMain2DArchive());
    dPaneClass_showNullPane(scrn);
    mpKanteraIcon->setScreen(scrn);

    mpParent = JKR_NEW CPaneMgr(scrn, MULTI_CHAR('kan_m_n'), 2, NULL);

    mpGauge = JKR_NEW CPaneMgr(scrn, MULTI_CHAR('yellow_m'), 0, NULL);
}

void dKantera_icon_c::setAlphaRate(f32 alphaRate) {
    mpParent->setAlphaRate(alphaRate);
}

void dKantera_icon_c::setPos(f32 x, f32 y) {
    mpParent->translate(x + g_drawHIO.mLanternIconMeterPosX, y + g_drawHIO.mLanternIconMeterPosY);
}

void dKantera_icon_c::setScale(f32 h, f32 v) {
    mpParent->scale(h * g_drawHIO.mLanternIconMeterSize, v * g_drawHIO.mLanternIconMeterSize);
}

void dKantera_icon_c::setNowGauge(u16 h, u16 v) {
    mpGauge->scale((f32)v / (f32)h, 1.0f);
#if TARGET_PC
    // Apply custom lantern glow if necessary
    const auto& lanternColorStr = dusk::getSettings().cosmetics.lanternGlowColor.getValue();
    if (dusk::cosmetics::is_valid_hex_color_str(lanternColorStr)) {
        auto color = dusk::cosmetics::hex_color_str_to_gx_color(lanternColorStr);
        mpGauge->setBlackWhite(JUtility::TColor(color.r, color.g, color.b, 255),
                                JUtility::TColor(color.r, color.g, color.b, 255));
    } else if (lanternColorStr == "Rainbow") {
        auto lv = &daAlink_getAlinkActorClass()->mpHIO->mItem.mLantern.m;
        mpGauge->setBlackWhite(JUtility::TColor(lv->mColorReg1R, lv->mColorReg1G, lv->mColorReg1B, 255),
                            JUtility::TColor(lv->mColorReg1R, lv->mColorReg1G, lv->mColorReg1B, 255));
    } else {
        // Smaller gauge is just pure yellow
        mpGauge->setBlackWhite(JUtility::TColor(255, 255, 0, 255),
                                    JUtility::TColor(255, 255, 0, 255));
    }
#endif
}

void dDlst_KanteraIcon_c::draw() {
    J2DGrafContext* curGraf = dComIfGp_getCurrentGrafPort();
    curGraf->setup2D();
    mp_scrn->draw(0.0f, 0.0f, curGraf);
}

dDlst_KanteraIcon_c::~dDlst_KanteraIcon_c() {}
