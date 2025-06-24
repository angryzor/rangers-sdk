#pragma once

namespace Cyan::System {
    class IAllocator {
    public:
        virtual void* Alloc(size_t size, size_t alignment) = 0;
        virtual void* Alloc2(size_t size, size_t alignment) = 0;
        virtual void Free(void* ptr) = 0;
        virtual void SetupMemory(void* ptr, size_t size) = 0;
        virtual void SetName(const char* name) = 0;
        virtual const char* GetName() const = 0;
    };
}
