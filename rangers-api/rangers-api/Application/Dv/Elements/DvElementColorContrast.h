#pragma once

namespace app::dv{
    class DvElementColorContrast : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class Flags : unsigned int {
                ENABLED,
                CURVE_ENABLED,
                USE_HLS_CORRECTION
            };

            csl::ut::Bitset<Flags> flags;
            float contrast;
            float dynamicRange;
            float crushShadows;
            float crushHighlights;
            float hlsHueOffset;
            float hlsLightnessOffset;
            float hlsSaturationOffset;
            float curveData[32];
        };

        struct UnkData {
        public:
            float unk0;
            float contrast;
            float dynamicRange;
            float crushShadows;
            float crushHighlights;
            float hlsHueOffset;
            float hlsLightnessOffset;
            float hlsSaturationOffset;
            float hlsColorizeRate;
            float hlsColorizeHue;
        };

        UnkData data;
        int framesOnScreen;
        bool jobGenerated;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementColorContrast)
    };
}
