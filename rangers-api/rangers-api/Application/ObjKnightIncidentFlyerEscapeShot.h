#pragma once

namespace app {
    class ObjKnightIncidentFlyerEscapeShot : public hh::game::GameObject {
    public:
        struct SetupInfo {
            float vert;
            csl::math::Vector3 unk1;
            csl::math::Vector3 unk2;
            float initSpeed;
            float maxSpeed;
            float acc;
            float lifeTime;
            hh::path::PathComponent* path;
            float distance;
            void* flyerContext;
        };

        SetupInfo setupInfo;
        hh::path::PathEvaluator pathEvaluator;
        float speed;
        float aliveTime;
        hh::eff::EffectHandle bulletEffect;
        void* gocTinyFsm;
        float dword2E0;
        uint16_t word2E4;

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        void Setup(const SetupInfo& setupInfo);
        
        GAMEOBJECT_CLASS_DECLARATION(ObjKnightIncidentFlyerEscapeShot)
    };
}
