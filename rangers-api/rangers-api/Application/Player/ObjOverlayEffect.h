#pragma once

namespace app::player{
    class ObjOverlayEffect : public hh::game::GameObject{
    public:
        int unk0;
        hh::game::CameraManager* cameraMgr;
        hh::eff::EffectHandle speedLinesEffect;
        float zOffset;
        
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        void StopSpeedLines();
        void ResetSpeedLines();

        GAMEOBJECT_CLASS_DECLARATION(ObjOverlayEffect)
    };
}
