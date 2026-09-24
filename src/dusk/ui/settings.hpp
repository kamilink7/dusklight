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
        s.game.swordMultiplier.setValue(50);
        s.game.bowMultiplier.setValue(100);
        s.game.damageMultiplier.setValue(2);
        s.game.noHeartDrops.setValue(true);
        s.game.loseRupees.setValue(true);
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
        s.game.combinedParry.setValue(true);
        s.game.suppressButtonPrompts.setValue(true);
    }
    void applyPresetDeathwish() {
        auto& s = getSettings();
        s.game.swordMultiplier.setValue(50);
        s.game.bowMultiplier.setValue(50);
        s.game.damageMultiplier.setValue(4);
        s.game.noHeartDrops.setValue(true);
        s.game.loseRupees.setValue(true);
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
        s.game.combinedParry.setValue(true);
        s.game.suppressButtonPrompts.setValue(true);
    }
    void applyPresetVanillaPlus() {
        auto& s = getSettings();
        s.game.swordMultiplier.setValue(50);
        s.game.bowMultiplier.setValue(100);
        s.game.damageMultiplier.setValue(2);
        s.game.noHeartDrops.setValue(true);
        s.game.loseRupees.setValue(false);
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
        s.game.combinedParry.setValue(false);
        s.game.suppressButtonPrompts.setValue(true);
    }

protected:
    bool mPrelaunch;
};

}  // namespace dusk::ui