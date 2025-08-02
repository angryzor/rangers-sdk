#pragma once

namespace hh::dv{
    class DvParamUpdater : public hh::fnd::ReferencedObject{
    public:
        csl::ut::MoveArray<DvDirectionalLightParamController*> lightParamControllers;

        void Update();
        void Update(int currentFrame);

        DvParamUpdater(csl::fnd::IAllocator* allocator);
    };
}
