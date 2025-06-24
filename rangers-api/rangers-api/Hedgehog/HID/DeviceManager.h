#pragma once

namespace hh::hid {
    class DeviceManager : public fnd::BaseObject {
    public:
        csl::ut::MoveArray<InputDevice*> inputDevices;
        csl::ut::MoveArray<void*> unk2;
        csl::ut::MoveArray<void*> unk3;
        uint32_t unk4; // 8 nibbles with initial values going from 0 to 7
        Keyboard* keyboard;
        Mouse* mouse;
        VibrationManager* vibrationManager;
        ActiveDeviceManager* activeDeviceManager;
        InputDeviceFactory inputDeviceFactory;

        DeviceManager(csl::fnd::IAllocator* pAllocator);
        ActiveDeviceManager* GetActiveDeviceManager();

        VibrationManager* GetVibrationManager() const;
        static VibrationManager* GetVibration();

        Gamepad* GetGamepadByID(unsigned id);
        static Gamepad* GetGamepad(unsigned id);
    };
}
