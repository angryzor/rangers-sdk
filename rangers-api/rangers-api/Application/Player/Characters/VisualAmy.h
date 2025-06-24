#pragma once

namespace app::player {
    class VisualAmy : public VisualHuman {
    public:
        uint64_t unk201;

        virtual unsigned int GetNameHash() const override;
        virtual void Initialize(hh::game::GameObject* gameObject, ComponentCollection* componentCollection) override;
        virtual void CreateEffects() override;
        virtual void BindEffects() override;

        PLAYER_VISUAL_CLASS_DECLARATION(VisualAmy);
    };
}
