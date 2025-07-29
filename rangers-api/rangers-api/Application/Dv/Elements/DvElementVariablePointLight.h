#pragma once

namespace app::dv{
    class DvElementVariablePointLight : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            struct Parameters {
            public:
                float attenuationRadius;
                float intensity;
                float radius;
                float rotationMultiplier;
            };

            enum class Type : unsigned int {
                NORMAL,
                CURVE_CONTROLLED,
                TIME_CONTROLLED
            };

            int unk0;
            csl::math::Position position;
            csl::math::Position finishPosition;
            unsigned int color[3];
            unsigned int finishColor[3];
            Parameters params;
            Parameters finishParams;
            Type type;
            int unk5[10];
            float curveData[128];
        };

        hh::fnd::Reference<hh::game::GameObject> lightHandle;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void UnkUpdate(int currentFrame, csl::math::Transform& transform) override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementVariablePointLight)
    };
}
