#pragma once

namespace app::game{
    class GOCHitStop : public hh::game::GOComponent {
    public:
        struct SetupInfo {
            int unk0;
        };

        int unk0;
        int unk1;
        csl::ut::MoveArray<int64_t> unk2;
        csl::ut::MoveArray<int64_t> unk3;

        void Setup(SetupInfo& setupInfo);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
        virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCHitStop)
    };
}
