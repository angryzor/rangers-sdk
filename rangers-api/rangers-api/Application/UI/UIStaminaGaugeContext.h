#pragma once

namespace app::ui{
    class UIStaminaGaugeContext : public app_cmn::fsm::GOCTinyFsmContext {
    public:
        hh::ui::LayerController* layControl;
        hh::ui::LayerController* circleGaugeController;
        hh::ui::LayerController* infiniteController;
        hh::ui::LayerController* circleGaugePlusController;
        hh::ui::LayerController* circleGaugePlusBgController;
        hh::ui::LayerController* staminaNitroController;
        hh::ui::LayerController* nitroCircleGaugeController;
        hh::ui::LayerController* nitroInfiniteController;
        hh::ui::LayerController* nitroCircleGaugePlusController;
        hh::ui::LayerController* nitroCircleGaugePlusBgController;
        hh::ui::LayerController* extraStaminaControllers[3];
        hh::ui::LayerController* nitroExtraStaminaControllers[3];
        float unk0;
        short flags;
        char unk1;

        UIStaminaGaugeContext(csl::fnd::IAllocator* allocator);
    };
}
