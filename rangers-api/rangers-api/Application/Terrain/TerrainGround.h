#pragma once

namespace app::trr {
    class TerrainGround : public app::trr::TerrainVisualObject {
    public:
        hh::fnd::Reference<TerrainVisualResourceBinder> terrainVisualResourceBinder;
        hh::fnd::Reference<TerrainVisualCreator> terrainVisualCreator;
        csl::ut::MoveArray<hh::fnd::HFrame*> frames;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void LoadLight(const char* stageId) override;
        virtual void UnkFunc13() override;
        virtual bool UnkFunc14() override;

        void Setup(const SetupInfo& setupInfo);

        void InitializeLight(int sectorId, hh::gfx::ResMirageLight* lightRes, ucsl::resources::pointcloud::v2::InstanceData& instanceData, hh::gfx::ResAnimLightContainer* lightAnim, hh::fnd::HFrame* hFrame, bool unk1);

        GAMEOBJECT_CLASS_DECLARATION(TerrainGround)
    };
}
