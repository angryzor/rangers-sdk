#pragma once

namespace hh::needle{
    class ClipMapRenderer : public hh::needle::NeedleRefcountObject {
    public:
        class Listener {
        public:
            virtual void CMRL_UnkFunc0() = 0;
        };

        struct UnkStr0{
            void* unk0;
            void* unk1;
            int unk2;
            int unk3;
        };

        csl::fnd::IAllocator* allocator;
        int dword18;
        int dword1C;
        float smallestCellSize; //0.010
        int dword24;
        int dword28;
        float float2C;
        float heightScale; //0.100
        float heightPrecision; //1000
        float worldSize; //4096
        char byte38; //heightMapTexelDensity?
        csl::math::Vector3 aabbMin;
        csl::math::Vector3 aabbMax;
        UnkStr0 unkStr60[10];
        void* qword150;
        void* qword158[10];
        SupportFXAll* supportFx;
        int dword1B0;
        csl::math::Vector4 oword1C0;
        char byte1D0;
        int64_t qword1D8;
    };
}
