#pragma once

namespace app::game{
    class FadeObject : public hh::game::GameObject {
    public:
        struct Description {
            char renderPriority;
            const char* name;
            char layer;
        };

        hh::ui::LayerController* layerController;
        int64_t unk1;
        char renderPriority;
        float unk3;

        virtual void AddCallback(hh::game::GameManager* gameManager) override;

        void Setup(Description& desc);

        GAMEOBJECT_CLASS_DECLARATION(FadeObject)
    };
}
