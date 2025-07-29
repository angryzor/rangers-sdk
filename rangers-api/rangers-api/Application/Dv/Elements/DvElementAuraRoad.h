#pragma once

namespace app::dv{
    class DvElementAuraRoad : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class VisualType{
                FLYER,
                DRAGON
            };

            VisualType visualType;
            float curveData0[32];
            float curveData1[32];
        };

        hh::fnd::Handle<hh::game::GameObject> auraRoadObject;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementAuraRoad)
    };
}
