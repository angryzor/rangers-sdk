#pragma once

namespace hh::gfx {
    struct ProbeData;
}

namespace hh::needle {
    class ProbeBVH : public NeedleRefcountObject, public csl::ut::NonCopyable {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            class Node : public NeedleRefcountObject {
            public:
                int dword10;
                int dword14;
                int dword18;
                int index;
                csl::geom::Aabb aabb;
            };

            csl::fnd::IAllocator* allocator;
            csl::ut::MoveArray<intrusive_ptr<Node>> nodes;
            csl::ut::MoveArray<intrusive_ptr<ProbeNode>> probeNodes;
            csl::ut::MoveArray<void*> unk3;
            IBLGGXSamplingTexture ggxSamplingTexture;
            uint32_t dword90;
            uint8_t byte94;

            void ApplyResourceToProbeNode(hh::gfx::ProbeData* probeData, float scale, ProbeNode* node);
            void RebuildNodes();
            void CreateTexture(SupportFXAll* supportFX);
        };

        intrusive_ptr<Impl> implementation;

        ProbeBVH(csl::fnd::IAllocator* allocator);
        void AddProbes(SupportFXAll* supportFX, hh::gfx::ProbeData* probeData, int probeCount, float scale, const char* resourceName);
    };
}
