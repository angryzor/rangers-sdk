#pragma once

namespace app::gfx{
    class MultiNodeContainer : public hh::fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<int64_t> nodes;

        MultiNodeContainer(csl::fnd::IAllocator* allocator);
    };
};
