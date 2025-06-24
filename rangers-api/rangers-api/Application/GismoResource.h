#pragma once

namespace app{
    class GismoResource : public hh::fnd::ReferencedObject {
    public:
        hh::fnd::Reference<hh::gfx::ResModel> modelResource;
        hh::fnd::Reference<hh::anim::ResSkeletonPxd> skeletonResource;
        hh::fnd::Reference<hh::gfnd::ResTexture> giTextureResource;
        hh::fnd::Reference<hh::gfnd::ResTexture> giOcclusionTextureResource;
        hh::fnd::Reference<hh::physics::ResPhysicsMeshBullet> physicsMeshResource;

        GismoResource(csl::fnd::IAllocator* allocator);
    };
}
