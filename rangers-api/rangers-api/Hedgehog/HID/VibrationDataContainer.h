#pragma once
#include <ucsl/resources/vibration/v21.h>

namespace hh::hid{
    class VibrationData : public fnd::ReferencedObject {
    public:
        int unk0;
        int unk1;
        char vibrationDataId;
        int unk3;
        float unk4;
        int unk5;
        int64_t unk6;
    };

    class VibrationDataContainer : public fnd::ReferencedObject{
    public:
        ucsl::resources::vibration::v21::Vibration* vibrationData;
        int handle;
        float unk2;
        float maxPositionX;
        int unk4;
        csl::ut::MoveArray<VibrationData*> vibrationDatas;
        int unk6;
        int unk7;
        char flags;
        int unk9;
        float unk10;
        int unk11;
        int64_t unk12;

        VibrationDataContainer(csl::fnd::IAllocator* allocator);

        void Initialize(ucsl::resources::vibration::v21::Vibration* vibData);
    };
}
