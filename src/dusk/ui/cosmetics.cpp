#include "cosmetics.hpp"

#include "dusk/config.hpp"
#include "dusk/cosmetics/midna_hair_color.hpp"
#include "dusk/randomizer/generator/utility/string.hpp"
#include "pane.hpp"
#include "string_button.hpp"

#include <fmt/format.h>

#include <random>

namespace dusk::ui {

static const auto defaultHexColors = std::unordered_map<std::string, std::string>({
    {"ab706e", "Red"},
    {"6382a0", "Blue"},
    {"94749a", "Purple"},
    {"ec8644", "Orange"},
    {"b9ab00", "Yellow"},
    {"ec9fc8", "Pink"},
    {"505154", "Black"},
    {"f8f7f4", "White"},
    {"91723e", "Brown"},
});

static const auto defaultGlowColors = std::unordered_map<std::string, std::string>({
    {"ff0000", "Red"},
    {"f68821", "Orange"},
    {"f6f321", "Yellow"},
    {"00ff00", "Green"},
    {"0000ff", "Blue"},
    {"8000ff", "Purple"},
    {"a0a0a0", "White"},
    {"Rainbow", "Rainbow"},
});

static const auto masterSwordColors = std::unordered_map<std::string, std::string>({
    {"ff0000", "Red"},
    {"f68821", "Orange"},
    {"f6f321", "Yellow"},
    {"00ff00", "Green"},
    {"0000ff", "Blue"},
    {"8000ff", "Purple"},
    {"a0a0a0", "White"},
    {"30d0d0", "Cyan"},
});

// No custom hex colors for now
static const auto midnaHairColors = std::unordered_map<std::string, std::string>({
    {"Default", "Default"},
    {"Pink", "Pink"},
    {"Red", "Red"},
    {"Yellow", "Yellow"},
    {"Green", "Green"},
    {"Blue", "Blue"},
    {"Purple", "Purple"},
    {"Brown", "Brown"},
    {"White", "White"},
});

static const auto chargeRingColors = std::unordered_map<std::string, std::string>({
   {"ff9f9f", "Pink"},
   {"ff0000", "Red"},
   {"ffff00", "Yellow"},
   {"00ff00", "Green"},
   {"0000ff", "Blue"},
   {"ff00ff", "Purple"},
   {"331900", "Brown"},
   {"feffff", "White"},
   {"000000", "Black"},
});

void add_cosmetic_option(Pane& leftPane, Pane& rightPane, const std::string& key, ConfigVar<std::string>& option,
                         const std::unordered_map<std::string, std::string>& colorPresets = defaultHexColors) {
    leftPane.register_control(leftPane.add_select_button({
        .key = key,
        .getValue = [&option, &colorPresets] {
            const auto& curHexStr = option.getValue();
            if (curHexStr.empty()) {
                return Rml::String("Default");
            }
            if (colorPresets.contains(curHexStr)) {
                return colorPresets.at(curHexStr);
            }
            return curHexStr;
        },
    }),
    rightPane, [key, &option, &colorPresets](Pane& pane) {
        pane.clear();
        pane.add_rml(fmt::format("Choose {}. Leave blank for default value. A reload or reboot may be required to see color changes ingame.", key));

        if (!key.starts_with("Midna's Hair")) {
            pane.add_child<StringButton>(StringButton::Props{
                .key = "Edit Hex Color",
                .getValue = [&option] {
                    return option.getValue();
                },
                .setValue = [&option](Rml::String str) {
                    // Make lowercase
                    for (char& c : str) {
                        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
                    }

                    option.setValue(str);
                    config::save();
                },
                .maxLength = 6,
            });

            pane.add_button(ControlledButton::Props{
                .text = "Default",
                .isSelected = [&option] {
                    return option.getValue().empty();
                }
            }).on_pressed([key, &option] {
                option.setValue("");
                if (key.starts_with("Midna's Hair")) {
                    cosmetics::set_all_midna_hair_colors();
                }
                config::save();
            });

            pane.add_button(ControlledButton::Props{
                .text = "Random Color",
            }).on_pressed([&option] {
                std::random_device rd{};
                std::uniform_int_distribution dist(0, 0xFFFFFF);
                std::string hexStr = randomizer::utility::str::intToHex(dist(rd), 6, false);
                option.setValue(hexStr);
                config::save();
            });
        }

        for (const auto& [hexStr, color] : colorPresets) {
            pane.add_button(ControlledButton::Props{
                .text = color,
                .isSelected = [hexStr, &option] {
                    return option.getValue() == hexStr;
                },
            }).on_pressed([key, hexStr, &option] {
                option.setValue(hexStr);
                if (key.starts_with("Midna's Hair")) {
                    cosmetics::set_all_midna_hair_colors();
                }
                config::save();
            });
        }
    });
}

CosmeticsWindow::CosmeticsWindow() {

    auto& cosmetics = getSettings().cosmetics;

    add_tab("Equipment Colors", [this, &cosmetics](Rml::Element* content) {
        auto& leftPane = add_child<Pane>(content, Pane::Type::Controlled);
        auto& rightPane = add_child<Pane>(content, Pane::Type::Controlled);

        add_cosmetic_option(leftPane, rightPane, "Hero's Tunic Cap Color", cosmetics.herosTunicCapColor);
        add_cosmetic_option(leftPane, rightPane, "Hero's Tunic Body Color", cosmetics.herosTunicTorsoColor);
        add_cosmetic_option(leftPane, rightPane, "Hero's Tunic Skirt Color", cosmetics.herosTunicSkirtColor);
        add_cosmetic_option(leftPane, rightPane, "Zora Armor Cap Color", cosmetics.zoraArmorCapColor);
        add_cosmetic_option(leftPane, rightPane, "Zora Armor Helmet Color", cosmetics.zoraArmorHelmetColor);
        add_cosmetic_option(leftPane, rightPane, "Zora Armor Torso Color", cosmetics.zoraArmorTorsoColor);
        add_cosmetic_option(leftPane, rightPane, "Zora Armor Scales Color", cosmetics.zoraArmorScalesColor);
        add_cosmetic_option(leftPane, rightPane, "Zora Armor Flippers Color", cosmetics.zoraArmorFlippersColor);
        add_cosmetic_option(leftPane, rightPane, "Lantern Glow Color", cosmetics.lanternGlowColor, defaultGlowColors);
        add_cosmetic_option(leftPane, rightPane, "Wooden Sword Color", cosmetics.woodenSwordColor);
        add_cosmetic_option(leftPane, rightPane, "Master Sword Blade Color", cosmetics.msBladeColor, masterSwordColors);
        add_cosmetic_option(leftPane, rightPane, "Master Sword Handle Color", cosmetics.msHandleColor, masterSwordColors);
        add_cosmetic_option(leftPane, rightPane, "Light Sword Glow Color", cosmetics.lightSwordGlowColor, defaultGlowColors);
        add_cosmetic_option(leftPane, rightPane, "Boomerang Color", cosmetics.boomerangColor);
        add_cosmetic_option(leftPane, rightPane, "Iron Boots Color", cosmetics.ironBootsColor);
        add_cosmetic_option(leftPane, rightPane, "Spinner Color", cosmetics.spinnerColor);

    });

    add_tab("Misc Colors", [this, &cosmetics](Rml::Element* content) {
        auto& leftPane = add_child<Pane>(content, Pane::Type::Controlled);
        auto& rightPane = add_child<Pane>(content, Pane::Type::Controlled);

        add_cosmetic_option(leftPane, rightPane, "Midna's Hair Base Color", cosmetics.midnaHairBaseColor, midnaHairColors);
        add_cosmetic_option(leftPane, rightPane, "Midna's Hair Tips Color", cosmetics.midnaHairTipsColor, midnaHairColors);
        add_cosmetic_option(leftPane, rightPane, "Midna Charge Ring Color", cosmetics.midnaChargeRingColor, chargeRingColors);
        add_cosmetic_option(leftPane, rightPane, "Link's Hair Color", cosmetics.linkHairColor);
        add_cosmetic_option(leftPane, rightPane, "Wolf Link Color", cosmetics.wolfLinkColor);
        add_cosmetic_option(leftPane, rightPane, "Epona Color", cosmetics.eponaColor);
    });
}
}
