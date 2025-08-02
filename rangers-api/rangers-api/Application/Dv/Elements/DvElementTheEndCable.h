#pragma once

namespace app::dv{
    class DvElementTheEndCable : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class VisualType : unsigned int{
                BOSS_RIFLEBEAST_PLUG,
                BOSS_EGGPLUG
            };

            enum class Flags : unsigned int{
                ENABLED,
                PLUG_ENABLED
            };

            csl::ut::Bitset<Flags> flags;
            VisualType visualType;
            float curveData[1024];
        };

        hh::fnd::Handle<DvTheEndCableObject> cableObject;
        bool enabled;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementTheEndCable)
    };
}
