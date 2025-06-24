#pragma once

namespace hh::dv {
    class DvResource : public DvResourceBase {
    public:
        fnd::ManagedResource* resource;

        fnd::ManagedResource* GetResource();

        DvResource(csl::fnd::IAllocator* allocator);
    };
}
