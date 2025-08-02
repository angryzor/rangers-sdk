#pragma once

namespace hh::hid{
    class VibrationPlayer : public hh::fnd::ReferencedObject{
    public:
        VibrationWin32* vibration;
        csl::ut::VariableString vibrationName;

        virtual void MuteSound(bool unmuted) {}
        virtual void PlaySound() {}
        virtual void StopSound() {}
        virtual bool IsSoundPlaying() {}
        virtual void PauseSound(bool paused) {}
        virtual int64_t UnkFunc5() {}
        virtual void SetSoundVolume(float volume) {}

        VibrationPlayer(csl::fnd::IAllocator* allocator, VibrationWin32* vibration, const char* name);
        const char* GetVibrationName() const;
    };
}
