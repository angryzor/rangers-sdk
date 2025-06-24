#pragma once

namespace hh::gfx{
    class GOCPointLight : public hh::game::GOComponent {
    public:
        struct Description{
            unsigned int lightsSize;
            const char* sceneContextManagerName;
        };

        struct Light{
            enum class LightType : unsigned int{
                UNK,
                POINT,
                DIRECTIONAL
            };

            struct PointProperties{
                float radius;
                float attenuationRadius;
                bool shadowEnabled;
            };

            struct DirectionalProperties{
                float innerConeAngle;
                float outerConeAngle;
                float attenuationRadius;
                bool shadowEnabled;
            };

            csl::math::Vector3 position;
            csl::math::Quaternion rotation;
            float intensity;
            float color[3];
            int idx;
            hh::fnd::HFrame* hFrame;
            LightType type;
            float computedColor[3];
            csl::math::Position position1;
            csl::math::Position rotation1;
            union{
                PointProperties pointProps;
                DirectionalProperties directionalProps;
            };
        };

        struct LightSetupInfo{
            Light::LightType type;
            csl::math::Vector3 position;
            float radius;
            float unk4;
            float attenuationRadius;
            float innerConeAngle;
            float outerConeAngle;
            hh::fnd::HFrame* hFrame;
            float intensity;
            float color[3];
            bool enableShadow;
        };

        csl::ut::MoveArray<Light> lights;
        hh::fnd::HFrame* hFrame;
        const char* sceneContextManagerName;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void Setup(Description& desc);
        void SetLightIntensity(unsigned int lightIdx, float intensity);
        void SetLightProperties(unsigned int lightIdx, float* colorARGB, float radius, float rotationMultiplier, float attenuationRadius, float innerConeAngle, float outerConeAngle, bool enableShadow);
        void SetLightProperties(unsigned int lightIdx, float* colorARGB, float radius, float rotationMultiplier, float attenuationRadius, float innerConeAngle, float outerConeAngle, csl::math::Vector3& position, csl::math::Quaternion& rotation);
        void CopyProperties(unsigned int lightIdx);
        int CreateLight(LightSetupInfo& info);
        int CreateLight(ResMirageLight* resource, hh::fnd::HFrame* hFrame);

        GOCOMPONENT_CLASS_DECLARATION(GOCPointLight)
    };
}
