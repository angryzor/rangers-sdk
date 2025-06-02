#pragma once

namespace hh::dv{
    class DvElementSpotlight : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            bool curveEnabled;
            csl::math::Position position;
            csl::math::Position finishPosition;
            csl::math::Position rotation;
            unsigned int color[3];
            float range;
            float intensity;
            float falloff;
            float angle;
            float unk1[6];
            float curveData[64];
        };

        Description binaryData;
        hh::fnd::Reference<hh::game::GameObject> light;
        
        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void SetData(void* data) override;
        virtual void DeleteData() override;
        virtual void UnkFunc6(int currentFrame, csl::math::Transform transform) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementSpotlight)
    };
}
