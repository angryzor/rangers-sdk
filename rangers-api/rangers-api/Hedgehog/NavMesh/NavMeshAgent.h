#pragma once

namespace hh::navmesh{
    class NavMeshAgent : public fnd::ReferencedObject {
    public:
        void* config;
        void* unk0a;
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

        void Setup(void* setupInfo); //setupInfo being a direct pointer to ResNavMeshConfig data
        void SetIncludeFlag(unsigned char bit);

        NavMeshAgent(csl::fnd::IAllocator* allocator, int unk4Count);
    };
}
