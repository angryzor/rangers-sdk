#pragma once

namespace app {
    class MeteorShowerEffect : public hh::game::GameObject {
    public:
        struct SetupInfo {
            float moveTime;
            float fadeTime;
            float length;
            float width;
            float speed;
            float angle;
            csl::math::Vector3 color;
        };
        
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        void Setup(const SetupInfo& setupInfo);

        GAMEOBJECT_CLASS_DECLARATION(MeteorShowerEffect);
    };
}
