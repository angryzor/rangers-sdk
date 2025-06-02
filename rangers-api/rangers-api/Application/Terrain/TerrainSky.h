#pragma once

namespace app::trr {
    class TerrainSky : public app::trr::TerrainVisualObject {
    public:
        hh::fnd::Reference<TerrainVisualResourceBinder> terrainVisualResourceBinder;
        hh::fnd::Reference<TerrainVisualCreator> terrainVisualCreator;
        csl::math::Matrix34 skyBoxLocation;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
        virtual void LoadLight(const char* stageId) override;
        virtual void UnkFunc13() override;
        virtual bool UnkFunc14() override;

        void Setup(const SetupInfo& setupInfo);

        GAMEOBJECT_CLASS_DECLARATION(TerrainSky)
    };
}
