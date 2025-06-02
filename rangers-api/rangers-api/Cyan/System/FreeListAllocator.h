#pragma once

namespace Cyan::System {
    class FreeListAllocator : public IAllocator {
    public:
        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;
        csl::fnd::OptimizedFreeListHeapTemplate<csl::fnd::Mutex> heap;

        FreeListAllocator();

        virtual void* Alloc(size_t size, size_t alignment) override;
        virtual void* Alloc2(size_t size, size_t alignment) override;
        virtual void Free(void* ptr) override;
        virtual void SetupMemory(void* ptr, size_t size) override;
        virtual void SetName(const char* name) override;
        virtual const char* GetName() const override;
        virtual uint64_t UnkFunc7();
        virtual uint64_t UnkFunc8();
        virtual uint64_t UnkFunc9();
    };
}
