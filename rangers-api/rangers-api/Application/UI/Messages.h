#pragma once

namespace app::ui {
    class MsgUIChangePlayerCharacter : public fnd::AppMessage<MsgUIChangePlayerCharacter> {
    public:
        player::CharacterIdU8 characterId;
        
        MsgUIChangePlayerCharacter(player::CharacterIdU8 characterId) : fnd::AppMessage<MsgUIChangePlayerCharacter>{ hh::fnd::MessageID::UI_CHANGE_PLAYER_CHARACTER }, characterId{ characterId } {}
    };

    class MsgUISetGameCockpitVisibility : public fnd::AppMessage<MsgUISetGameCockpitVisibility> {
    public:
        size_t uiMask;
        bool visible;

        MsgUISetGameCockpitVisibility(size_t uiMask, bool visible) : fnd::AppMessage<MsgUISetGameCockpitVisibility>{ hh::fnd::MessageID::UI_SET_GAME_COCKPIT_VISIBILITY }, uiMask{ uiMask }, visible{ visible } {}
    };
}
