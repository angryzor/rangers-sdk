#pragma once

namespace gindows{
    static csl::fnd::IAllocator* gindowsAllocator;
    
    static csl::fnd::IAllocator* GetMemoryAllocator();

    static void SetMemoryAllocator(csl::fnd::IAllocator* allocator){
        gindowsAllocator = allocator;
    }

    class DelegateAllocator {
    public:

    };
}
