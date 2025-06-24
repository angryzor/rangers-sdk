#pragma once
#include <ucsl/resources/vibration/v21.h>

namespace hh::hid{
    class VibrationData : public fnd::ReferencedObject {
    public:
        int unk0;
        int unk1;
        int unk2;
        int unk3;
        float unk4;
        int unk5;
        int64_t unk6;
    };

    class VibrationDataContainer : public fnd::ReferencedObject{
    public:
        ucsl::resources::vibration::v21::Vibration* vibrationData;
        int unk1;
        float unk2;
        float unk3;
        int unk4;
        csl::ut::MoveArray<void*> unk5;
        int unk6;
        int unk7;
        int unk8;
        int unk9;
        float unk10;
        int unk11;
        int64_t unk12;

        VibrationDataContainer(csl::fnd::IAllocator* allocator);
    };
}
