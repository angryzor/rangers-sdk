#pragma once
#include <ucsl/resources/vibration/v21.h>

namespace hh::hid{
    class VibrationManager : public fnd::ReferencedObject {
    public:
        class PresetContainerListener : public fnd::ReferencedObject, fnd::ResourceManager::ResourceListener {
        public:
            VibrationManager* vibMgr;
            int unk0;
            const char* unk1;
            const char* unk2;

            virtual void ResourceLoadedCallback(fnd::ManagedResource* resource) override;
            virtual void ResourceUnloadedCallback(fnd::ManagedResource* resource) override;
        };

        csl::ut::StringMap<ucsl::resources::vibration::v21::Vibration*> vibrations; 
        PresetContainerListener* presetContainerListener;
        char unk0;
        void* vibrationHapticListener;

        VibrationManager(csl::fnd::IAllocator* allocator);

        static void PlayVibration(int deviceId, const char* vibrationName, VibrationContainer::VibrationType vibrationType, VibrationContainer::VibrationObj* obj);
    };
}
