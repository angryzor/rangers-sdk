#pragma once

namespace Cyan::System {
    template<size_t Len>
    class ArrayAllocator : public IAllocator {
    public:
        const char* name;
        void* mem1;
        size_t size;
        uint32_t unk0;
        void* mem2;
        void* mem3;
        uint64_t unk1;

        virtual void* Alloc(size_t size, size_t alignment) override;
        virtual void* Alloc2(size_t size, size_t alignment) override;
        virtual void Free(void* ptr) override;
        virtual void SetupMemory(void* ptr, size_t size) override;
        virtual void SetName(const char* name) override;
        virtual const char* GetName() const override;
    };
}