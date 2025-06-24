#pragma once

namespace hh::snd {
    class SoundSystemListener {
    public:
        virtual ~SoundSystemListener() = default;
        virtual void PostRegisterData(unsigned int index) {}
        virtual void PreUnregisterData(unsigned int index) {}
    };

    class SoundSystem : public fnd::BaseObject, public csl::fnd::Singleton<SoundSystem> {
    public:
        char rootDirectory[64];
        csl::ut::InplaceMoveArray<void*, 6> unk2;

        SoundSystem(csl::fnd::IAllocator* allocator);
        virtual void* GetRuntimeTypeInfo() const;
        virtual void Setup(const char* rootDirectory) {}
        virtual void Update(float timeStep) {}
        virtual void RegisterData(void* data, int size) {}
        virtual void UnregisterData() {}

        void SetRootDirectory(const char* directory);
    };

    class SoundSystemCri : public SoundSystem {
    public:
        csl::ut::MoveArray<void*> unk101;

        CREATE_FUNC(SoundSystemCri, const SoundCueCri::PoolParam* poolParam);
        virtual void* GetRuntimeTypeInfo() const override;
        virtual void Setup(const char* rootDirectory) override {}
        virtual void Update(float timeStep) override {}
        virtual void RegisterData(void* data, int size) override {}
        virtual void UnregisterData() override {}

        void AddListener(SoundSystemListener* listener);
        void RemoveListener(SoundSystemListener* listener);
        void OnPostRegisterData(unsigned int index);
        void OnPreUnregisterData(unsigned int index);
    };
}
