#pragma once

namespace app::dv{
    class DvElementVignetteParam : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class Flags : unsigned int {
                DEPTH_ENABLED,
                CURVE_ENABLED
            };

            enum class GradationType : unsigned int {
                GRADATION_MODE_CIRCLE,
                GRADATION_MODE_LINE
            };

            enum class BlendMode : unsigned int {
                BLEND_MODE_ALPHA_BLEND,
                BLEND_MODE_ADD,
                BLEND_MODE_MUL,
                BLEND_MODE_SCREEN,
                BLEND_MODE_OVERLAY,
            };

            struct VignetteParam {
            public:
                csl::math::Vector2 position;
                csl::math::Vector2 size;
                float scale;
                csl::math::Vector2 lineDirection;
                int opacity;
                unsigned int color[3];
                float penumbraScale;
                float intensity;
                float rotation;
            };

            struct DepthParam {
            public:
                float minMaxPenumbraScale[2];
                float bokehScale;
                float minMaxDOFOpacityScale[2];
                float minMaxOpacityScale[2];
                float minMaxOpacityDist[2];
            };

            csl::ut::Bitset<Flags> flags;
            GradationType gradationType;
            VignetteParam vignetteParams;
        private:
            int unused0;
        public:
            BlendMode blendMode;
            DepthParam depthParams;
            VignetteParam finishVignetteParams;
            DepthParam finishDepthParams;
            float curveData[32];
        };

        bool jobGenerated;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementVignetteParam)
    };
}
