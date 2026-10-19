#pragma once
#include "window.hpp"

namespace dusk::ui {

class SettingsWindow : public Window {
public:
    SettingsWindow(bool prelaunch = false);

    void update() override;
    void hide(bool close) override;
    void applyPresetBattaglia() {
        auto& s = getSettings();
        s.game.swordMultiplier.setValue(40);
        s.game.bowMultiplier.setValue(100);
        s.game.wolfMultiplier.setValue(50);
        s.game.damageMultiplier.setValue(2);
        s.game.noHeartDrops.setValue(false);
        s.game.heartDropRate.setValue(0);
        s.game.noArrowDrops.setValue(false);
        s.game.noRupeeDrops.setValue(false);
        s.game.halfMyShitIsGone.setValue(false);
        s.game.quarterDeathTax.setValue(true);
        s.game.insulatedZoraArmor.setValue(true);
        s.game.sturdierWolfLink.setValue(true);
        s.game.progressiveDefense.setValue(true);
        s.game.enableSkillMeter.setValue(true);
        s.game.shieldUsesMeter.setValue(true);
        s.game.meterSpin.setValue(true);
        s.game.noHitstop.setValue(true);
        s.game.noBattleMusic.setValue(true);
        s.game.wolfGear.setValue(true);
        s.game.alwaysLightSword.setValue(LightSwordMode::VISUALS_ONLY);
        s.game.swordTrail.setValue(true);
        s.game.fastSpinner.setValue(true);
        s.game.enableFastIronBoots.setValue(true);
        s.game.armorRupeeDrain.setValue(MagicArmorMode::ON_DAMAGE);
        s.game.alternateParry.setValue(false);
        s.game.combinedParry.setValue(true);
        s.game.suppressButtonPrompts.setValue(true);
        s.game.noWolfJumpMeter.setValue(false);
        s.game.noMidnaChargeMeter.setValue(false);
        s.game.dodgeCancel.setValue(true);
        s.game.jumpStrikeCancel.setValue(true);
        s.game.progressiveCombos.setValue(true);
        s.game.enableCrouchShield.setValue(true);
        s.game.enableManualShield.setValue(true);
    }
    void applyPresetDeathwish() {
        auto& s = getSettings();
        s.game.swordMultiplier.setValue(30);
        s.game.bowMultiplier.setValue(100);
        s.game.wolfMultiplier.setValue(50);
        s.game.damageMultiplier.setValue(4);
        s.game.noHeartDrops.setValue(false);
        s.game.heartDropRate.setValue(0);
        s.game.noArrowDrops.setValue(true);
        s.game.noRupeeDrops.setValue(false);
        s.game.halfMyShitIsGone.setValue(true);
        s.game.insulatedZoraArmor.setValue(true);
        s.game.sturdierWolfLink.setValue(true);
        s.game.progressiveDefense.setValue(true);
        s.game.enableSkillMeter.setValue(true);
        s.game.shieldUsesMeter.setValue(true);
        s.game.meterSpin.setValue(true);
        s.game.noHitstop.setValue(true);
        s.game.noBattleMusic.setValue(true);
        s.game.wolfGear.setValue(true);
        s.game.alwaysLightSword.setValue(LightSwordMode::VISUALS_ONLY);
        s.game.swordTrail.setValue(true);
        s.game.fastSpinner.setValue(true);
        s.game.enableFastIronBoots.setValue(true);
        s.game.armorRupeeDrain.setValue(MagicArmorMode::NORMAL);
        s.game.alternateParry.setValue(false);
        s.game.combinedParry.setValue(true);
        s.game.suppressButtonPrompts.setValue(true);
        s.game.noWolfJumpMeter.setValue(false);
        s.game.noMidnaChargeMeter.setValue(false);
        s.game.dodgeCancel.setValue(true);
        s.game.progressiveCombos.setValue(true);
        s.game.jumpStrikeCancel.setValue(true);
        s.game.enableCrouchShield.setValue(true);
        s.game.enableManualShield.setValue(true);
    }
    void applyPresetVanillaPlus() {
        auto& s = getSettings();
        s.game.swordMultiplier.setValue(50);
        s.game.bowMultiplier.setValue(100);
        s.game.wolfMultiplier.setValue(50);
        s.game.damageMultiplier.setValue(2);
        s.game.noHeartDrops.setValue(false);
        s.game.heartDropRate.setValue(0);
        s.game.noArrowDrops.setValue(false);
        s.game.noRupeeDrops.setValue(false);
        s.game.halfMyShitIsGone.setValue(false);
        s.game.insulatedZoraArmor.setValue(false);
        s.game.sturdierWolfLink.setValue(false);
        s.game.progressiveDefense.setValue(true);
        s.game.enableSkillMeter.setValue(false);
        s.game.shieldUsesMeter.setValue(false);
        s.game.meterSpin.setValue(false);
        s.game.noHitstop.setValue(true);
        s.game.noBattleMusic.setValue(false);
        s.game.wolfGear.setValue(false);
        s.game.alwaysLightSword.setValue(LightSwordMode::VISUALS_ONLY);
        s.game.swordTrail.setValue(true);
        s.game.fastSpinner.setValue(true);
        s.game.enableFastIronBoots.setValue(true);
        s.game.armorRupeeDrain.setValue(MagicArmorMode::NORMAL);
        s.game.alternateParry.setValue(false);
        s.game.combinedParry.setValue(false);
        s.game.suppressButtonPrompts.setValue(true);
        s.game.dodgeCancel.setValue(false);
        s.game.progressiveCombos.setValue(false);
        s.game.jumpStrikeCancel.setValue(false);
        s.game.enableCrouchShield.setValue(true);
        s.game.enableManualShield.setValue(true);
    }
    void applyPresetKamilight() {
        auto& s = getSettings();
        s.game.swordMultiplier.setValue(30);
        s.game.bowMultiplier.setValue(100);
        s.game.wolfMultiplier.setValue(50);
        s.game.damageMultiplier.setValue(4);
        s.game.noHeartDrops.setValue(false);
        s.game.heartDropRate.setValue(50);
        s.game.noArrowDrops.setValue(true);
        s.game.noRupeeDrops.setValue(false);
        s.game.halfMyShitIsGone.setValue(false);
        s.game.quarterDeathTax.setValue(true);
        s.game.insulatedZoraArmor.setValue(true);
        s.game.sturdierWolfLink.setValue(true);
        s.game.progressiveDefense.setValue(false);
        s.game.enableSkillMeter.setValue(true);
        s.game.shieldUsesMeter.setValue(true);
        s.game.meterSpin.setValue(true);
        s.game.noHitstop.setValue(true);
        s.game.noBattleMusic.setValue(true);
        s.game.wolfGear.setValue(true);
        s.game.alwaysLightSword.setValue(LightSwordMode::VISUALS_ONLY);
        s.game.swordTrail.setValue(true);
        s.game.fastSpinner.setValue(true);
        s.game.enableFastIronBoots.setValue(true);
        s.game.armorRupeeDrain.setValue(MagicArmorMode::ON_DAMAGE);
        s.game.alternateParry.setValue(false);
        s.game.combinedParry.setValue(true);
        s.game.suppressButtonPrompts.setValue(true);
        s.game.noWolfJumpMeter.setValue(false);
        s.game.noMidnaChargeMeter.setValue(false);
        s.game.dodgeCancel.setValue(true);
        s.game.jumpStrikeCancel.setValue(true);
        s.game.progressiveCombos.setValue(true);
        s.game.enableCrouchShield.setValue(true);
        s.game.enableManualShield.setValue(true);
    }

protected:
    bool mPrelaunch;
};

}  // namespace dusk::ui