#pragma once

namespace app::gfx{
    class ModelNodeContainer : public hh::fnd::ReferencedObject {
    public:
        hh::fnd::Handle<hh::gfx::GOCVisualModel> visualModel;
        csl::ut::MoveArray<hh::fnd::Reference<hh::gfx::ModelNodeHFrame>> nodeHFrames;

        void AddNode(const char* nodeName);
        hh::gfx::ModelNodeHFrame* GetNode(int nodeIndex) const;
        hh::gfx::ModelNodeHFrame* GetNode(const char* nodeName) const;

        ModelNodeContainer(csl::fnd::IAllocator* allocator, hh::gfx::GOCVisualModel* visualModel);
    };
}
