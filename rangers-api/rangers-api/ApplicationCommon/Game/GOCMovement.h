#pragma once

namespace app_cmn::game{
    class GOCMovement;

    class MoveController {
    public:
        GOCMovement* gocMovement;
        char unk0;
        char unk1;

        virtual const char* GetName();
        virtual int64_t UnkFunc0() {}
        virtual int64_t UnkFunc1() {}
        virtual int64_t UnkFunc2() {}
        virtual ~MoveController();

        void SetGOC(GOCMovement* goc);

        MoveController(char unk0);
    };

    class GOCMovement : public hh::game::GOComponent{
    public:
        struct Description{
            bool unkFlag;
            hh::fnd::UpdatingPhase updatePhase;
            int updatePriority;
            char unk3;
        };

        csl::ut::MoveArray<MoveController*> controllers;
        char unk0[0xA0];
        csl::ut::InplaceMoveArray<int64_t, 1> unk1;
        char unk2;
        char unk3;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(Description& desc);
        MoveController* GetController(const char* name);
        void AddController(MoveController* controller);

        GOCOMPONENT_CLASS_DECLARATION(GOCMovement)
    };
}
