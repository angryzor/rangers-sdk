#pragma once

namespace app::player {
    class VisualSonic : public VisualHuman {
    public:
        virtual unsigned int GetNameHash() const override;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) override;
        virtual void SetupFacialAnimation() override;
        virtual void CreateEffects() override;
        virtual void BindEffects() override;

        PLAYER_VISUAL_CLASS_DECLARATION(VisualSonic);
    };
}
