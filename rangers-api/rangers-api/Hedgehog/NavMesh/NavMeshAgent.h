#pragma once
#include <ucsl/resources/navmeshconfig/v1.h>

namespace hh::navmesh{
    class NavMeshAgent : public fnd::ReferencedObject {
    public:
        ucsl::resources::navmeshconfig::v1::Config* config;
        ucsl::resources::navmeshconfig::v1::Config** configs;
        void* queryFilter;
        csl::math::Vector4 unk0;
        int64_t unk1;
        csl::math::Vector3 destination;
        int64_t unk3;
        csl::ut::MoveArray<int64_t> unk4;
        int unk5;
        int unk4Count;
        int unk6;
        char unk7;

        void Setup(ucsl::resources::navmeshconfig::v1::Config* setupInfo);
        void SetIncludeFlag(unsigned char bit);

        NavMeshAgent(csl::fnd::IAllocator* allocator, int unk4Count);
    };
}
