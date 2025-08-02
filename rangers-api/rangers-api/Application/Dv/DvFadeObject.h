#pragma once

namespace app::dv{
    class DvFadeObject : public hh::game::GameObject{
    public:
        hh::ui::LayerController* layerController;
        char renderPriority;

        virtual void AddCallback(hh::game::GameManager* gameManager) override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(DvFadeObject)
    };
}
