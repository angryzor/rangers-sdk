#pragma once

namespace app::trr {
    class TerrainVisualObject : public hh::game::GameObject {
    public:
        struct Sector {
            struct LightInstance {
                hh::fnd::ResLightParameter lightParameter;
                hh::fnd::Reference<hh::gfx::ResAnimLightContainer> lightAnimationResource;
                hh::fnd::HFrame* hFrame;
                float loadingRange;
                char unk1;
                const char* instanceName;
                int idx;

                void Initialize(hh::gfx::ResMirageLight* light, ucsl::resources::pointcloud::v2::InstanceData& instanceData, hh::gfx::ResAnimLightContainer* lightAnim, hh::fnd::HFrame* hFrame, bool unk1);
                void SetGOCPointLight(hh::gfx::GOCPointLight* gocPointlight, bool enabled);
                static int CreateLight(hh::gfx::GOCPointLight* gocPointLight, LightInstance& lightInstance, hh::fnd::HFrame* hFrame, const char* instanceName);
            };

            csl::ut::MoveArray<void*> unk1;
            csl::ut::MoveArray<void*> unk2;
            csl::ut::MoveArray<LightInstance> lightInstances;
            uint64_t unk4;
            bool enabled;
        };

        TerrainWorld* world;
        hh::game::GOCTransform* gocTransform;
        hh::gfx::GOCPointLight* gocPointLight;
        csl::ut::MoveArray<Sector> sectors;
        uint8_t unk204;
        bool isNonZeroStageIndex;

        TerrainVisualObject(csl::fnd::IAllocator* allocator);

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
        virtual void LoadLight(const char* stageId) = 0;
        virtual void UnkFunc13() = 0;
        virtual bool UnkFunc14() = 0;
        virtual void UnkFunc15() {}

        struct SetupInfo {
            TerrainWorld* world;
            TerrainVisualResourceBinder* resourceBinder;
        };

        void Setup(const SetupInfo& setupInfo);
    };
}
