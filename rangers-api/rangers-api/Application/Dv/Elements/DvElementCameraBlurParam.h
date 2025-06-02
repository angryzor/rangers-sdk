#pragma once

namespace app::dv{
    class DvElementCameraBlurParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class Flags : unsigned int {
                ENABLED,
                SINGLE_DIRECTION_OPT,
                CURVE_ENABLED
            };
        
            csl::ut::Bitset<Flags> flags;
            int sampleAmount;
            float blurAmount;
            float finishBlurAmount;
            float curveData[32];
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCameraBlurParam)
    };
}
