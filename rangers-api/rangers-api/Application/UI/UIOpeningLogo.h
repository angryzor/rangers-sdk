#pragma once

namespace app::ui{
    class UIOpeningLogo : public hh::game::GameObject {
    public:
        hh::ui::LayerController* layerController;

        virtual void AddCallback(hh::game::GameManager* gameManager) override;

        void Enter();
        void Leave();

        GAMEOBJECT_CLASS_DECLARATION(UIOpeningLogo)
    };
}
