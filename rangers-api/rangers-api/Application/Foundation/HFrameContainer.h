#pragma once

namespace app::fnd{
    class HFrameContainer : public hh::fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<int64_t> hFrames;

        HFrameContainer(csl::fnd::IAllocator* allocator);
    };
};
