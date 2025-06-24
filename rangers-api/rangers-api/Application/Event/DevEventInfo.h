#pragma once

namespace app::evt {
    class DevEventInfo : public hh::game::GameService, hh::game::GameManagerListener, hh::game::GameStepListener {
    public:
        app::level::LevelInfo* lvlInfo;
        csl::ut::MoveArray<void*> unk0;
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        csl::ut::MoveArray<void*> unk4;
        csl::ut::VariableString unk5;
        csl::ut::VariableString unk6;
        int unk7;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
        virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
        virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        GAMESERVICE_CLASS_DECLARATION(DevEventInfo)
    };
}
