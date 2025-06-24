#pragma once

namespace app{
    class GOCEnemyAttackSign : public hh::game::GOComponent {
    public:
        csl::ut::MoveArray<hh::gfx::ModelNodeHFrame*> hFrames;
        char unk0;
        float unk1;
        float unk2;
        CRITICAL_SECTION unk3;
        int unk4; //most likely a handle

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void DeleteHFrames();

        GOCOMPONENT_CLASS_DECLARATION(GOCEnemyAttackSign)
    };
}
