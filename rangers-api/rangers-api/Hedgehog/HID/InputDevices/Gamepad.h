#pragma once

namespace hh::hid {
    class Vibration;
    class VibrationContainer;

    class Gamepad : public InputDevice {
        csl::ut::MoveArray<Vibration*> vibrations;
        csl::ut::StringMap<Vibration*> vibrations1;
        VibrationContainer* vibrationContainer;
        csl::ut::InplaceMoveArray<uint32_t, 32> unk4;
        char unk5[128];
        uint16_t unk6;
        float unk7;
    public:
        Gamepad(csl::fnd::IAllocator* pAllocator);
        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int GetDeviceId() const override;
        virtual float GetInputValue(unsigned int inputId) const override;
        virtual csl::math::Vector4 GetTarget1(unsigned int inputId) const override;
        virtual csl::math::Vector4 GetTarget2(unsigned int inputId) const override;
        virtual void Update(float unkParam) override;
        virtual bool HasUpdated() const override;
        virtual bool UnkFunc7() const override;
        virtual bool UnkFunc8() const;
        virtual bool UnkFunc9() const;
        virtual void* UnkFunc10();
        virtual int UnkFunc11();
        virtual bool UnkFunc12() { return false; }
        virtual bool UnkFunc13() { return false; }
        virtual uint64_t UnkFunc14() = 0;

        VibrationContainer* GetVibrationContainer() const;
    };
}
