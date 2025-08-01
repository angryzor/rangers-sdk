#pragma once

namespace app::gfx{
    class MultiNodeContainer : public hh::fnd::ReferencedObject {
    public:
        csl::ut::MoveArray<hh::fnd::Reference<ModelNodeContainer>> nodes;

        void AddNode(hh::gfx::GOCVisualModel* visualModel, const char* nodeName);
        ModelNodeContainer* GetNode(hh::gfx::GOCVisualModel* visualModel) const;

        MultiNodeContainer(csl::fnd::IAllocator* allocator);
    };
};
