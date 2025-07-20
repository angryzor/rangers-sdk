#pragma once

namespace hh::dv{
    class DvElementSpotlightModel : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            enum class Flags : unsigned int {
                UNK0,
                COLOR_CURVE_ENABLED,
                USE_TARGET,
                LIGHT_PROPERTIES_CURVE_ENABLED
            };

            struct Cone {
                float innerAngle;
                float outerAngle;
            };

            struct LightProperties {
                csl::math::Position scale;
                float attenuationRadius;
                float intensity;
            };

            csl::ut::Bitset<Flags> flags;
            char targetGuid[16];
            float unk0[2];
            csl::math::Position targetPosition;
            csl::math::Position position;
            csl::math::Position finishPosition;
            float modelLuminance;
            LightProperties lightProperties;
            LightProperties finishLightProperties;
            float color[4];
            bool unk2;
            Cone cone;
            Cone finishCone;
            float unk3[3];
            float curveData[16]; //reads as float[64]
            float colorCurveData[16]; //reads as float[64]
            float intensityCurveData[16]; //reads as float[64]
        };

        Description binaryData;
        hh::fnd::Handle<hh::game::GameObject> lightObject;
        int unk1;
        csl::math::Vector3 targetPosition;
        csl::math::Vector4 unk3;
        int64_t unk4;
        
        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void SetData(void* data) override;
        virtual void DeleteData() override;
        virtual void UnkFunc6(int currentFrame, csl::math::Transform transform) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementSpotlightModel)
    };
}
