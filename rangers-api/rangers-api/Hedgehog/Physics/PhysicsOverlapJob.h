#pragma once

namespace hh::physics{
    class PhysicsOverlapJob : public PhysicsQueryJob{
    public:
        csl::ut::InplaceMoveArray<csl::math::Vector4, 10> unk0; 
        int64_t qwordE0;
        csl::math::Matrix44 unk1[10];

        PhysicsOverlapJob(csl::fnd::IAllocator* allocator);
    };
}
