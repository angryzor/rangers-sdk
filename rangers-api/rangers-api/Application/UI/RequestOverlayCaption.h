#pragma once

namespace app::ui {
    struct CaptionCollection {
        struct Caption {
            csl::ut::String label;
            csl::ut::String cue;
            float duration;
            unsigned int unk1;
        };

        struct AddInfo {
            csl::fnd::IAllocator* allocator;
        };

        csl::ut::MoveArray<Caption> items;

        CaptionCollection(csl::fnd::IAllocator* allocator) : items{ allocator } {}
        Caption* Add(const AddInfo& addInfo);
    };

    struct CaptionInfo {
        CaptionCollection captions;
        uint8_t unk202;
        uint8_t unk203;
        uint8_t unk204;
        uint8_t unk205;
        uint8_t unk206;
        uint8_t unk207;
        uint8_t unk208;
        uint8_t unk209;
        uint8_t unk210;
        uint8_t unk211;
    };

    class RequestOverlayCaption : public RequestOverlayBegin, public RequestOverlayTagReplace, public CaptionInfo {
    public:
        CaptionInfo captionInfo;

        DEFAULT_CREATE_FUNC(RequestOverlayCaption);
    };
}
