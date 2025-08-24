#pragma once

namespace app{
    class MeteorShowerService : public hh::game::GameService, public hh::game::GameStepListener, public app::evt::EventPlayerListener{
    public:
        hh::fnd::ResReflectionT<heur::rfl::MeteorShowerParameter>* reflectionData;
        int64_t unk1;
        game::Timestamp unk2;
        game::Timestamp unk3;
        game::TimeService* timeService;
        csl::ut::MoveArray<int64_t> unk4;
        csl::ut::MoveArray<hh::game::WorldObjectStatus*> objectStatuses;
        csl::ut::MoveArray<hh::game::GameObject*> slotStarObjects;
        int64_t unk7;
        int unk8;
        int unk9;
        char flags;
        int unk10b;
        int64_t unk11;
        int16_t unk12;
        float unkDeltaTime;
        csl::ut::InplaceMoveArray<int64_t, 2> unk14;
        csl::ut::InplaceMoveArray<int64_t, 2> unk15;
        csl::ut::InplaceMoveArray<int64_t, 2> unk16;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void EPL_UnkFunc2() override;
        virtual void EPL_UnkFunc5() override;

        GAMESERVICE_CLASS_DECLARATION(MeteorShowerService)
    };
}
