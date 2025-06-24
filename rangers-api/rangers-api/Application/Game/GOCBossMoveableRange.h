#pragma once

namespace app::game{
    class GOCBossMoveableRange : public hh::game::GOComponent {
    public:
        hh::fnd::HFrame* objectHFrame;
        csl::math::Transform objectTransform;
        csl::ut::String unkNodeName;
        float unkParams0[13];
        hh::game::GOCTransform* objectGOCTransform;
        float unkParams1[12];
        int64_t unk1;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCBossMoveableRange)
    };
}
