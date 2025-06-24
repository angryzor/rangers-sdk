#pragma once

namespace hh::hid{
    class VibrationContainer : public fnd::ReferencedObject{
    public:
        class VibrationMarge : public VibrationDataContainer{
        public:
        };

        struct VibrationObj{
            hh::hid::VibrationContainer* container;
            int handle;

            VibrationObj();
            void Initialize();
            void UnkFunc0();
            void UnkFunc1();
        };

        enum class VibrationType : unsigned int {
            ONESHOT,
            ALWAYS,
            AUTO
        };

        GamepadSteam* gamepad;
        int unk0;
        short flags;
        csl::ut::MoveArray<VibrationDataContainer*> dataContainers;
        csl::ut::PointerMap<int, VibrationDataContainer*> hashDataContainers;
        csl::ut::MoveArray<void*> unkArray1;
        void* unk1;
        void* unk2;
        VibrationMarge* marge;

        VibrationContainer(csl::fnd::IAllocator* allocator, Gamepad* gamepad);

        void PlayVibration(const char* vibrationName, VibrationType vibrationType, VibrationContainer::VibrationObj* obj);
    };
}
