#pragma once

namespace app::ui {
    enum class OverlayType {
        TOAST,
        WINDOW,
        CAPTION,
        CAPTION_SELECT_BOX,
        OBJECTIVE,
        OPERATION_GUIDE,
        PRACTICE_NOTIFIER,
        CELEBRATION,
    };

    class RequestOverlayBegin : public hh::fnd::ReferencedObject {
    public:
        OverlayType type;
        bool block;
        uint8_t unk3;

        RequestOverlayBegin(csl::fnd::IAllocator* allocator);
    };
}
