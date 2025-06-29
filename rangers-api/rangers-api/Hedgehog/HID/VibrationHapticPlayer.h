#pragma once

namespace hh::hid{
    class VibrationHapticPlayerListener { 
    public:
        virtual ~VibrationHapticPlayerListener() = 0;
        virtual bool IsLoop() = 0;
        virtual hh::fnd::ReferencedObject* CreateHandle(csl::fnd::IAllocator* allocator) = 0;
        virtual bool DestoryHandle(hh::fnd::ReferencedObject* handleObj) = 0;
        virtual void PlaySound(hh::fnd::HandleBase* handle, unsigned int category, int unk2, const char* name, float volume, char unk8) = 0;
        virtual void StopSound(hh::fnd::HandleBase* handle) = 0;
        virtual bool IsSoundPlaying(hh::fnd::HandleBase* handle) = 0;
        virtual void PauseSound(hh::fnd::HandleBase* handle, bool paused) = 0;
        virtual void SetSoundVolume(hh::fnd::HandleBase* handle, int unk0, float volume) = 0;
    };

    class VibrationHapticPlayer : public VibrationPlayer{
    public:
        hh::fnd::ReferencedObject* vibHandle;
        int gamepadUnk102;
        char unk0;
        float volume;
        float volumeMultiplier;
        bool unk3;

        virtual void MuteSound(bool unmuted) override;
        virtual void PlaySound() override;
        virtual void StopSound() override;
        virtual bool IsSoundPlaying() override;
        virtual void PauseSound(bool paused) override;
        virtual void SetSoundVolume(float volume) override;
        virtual void* GetTypeInfo() const;

        VibrationHapticPlayer(csl::fnd::IAllocator* allocator, VibrationWin32* vibration, int gamepadUnk102, char unk0, const char* name, bool unk1);
    };
}
