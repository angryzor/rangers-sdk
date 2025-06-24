#pragma once

namespace hh::physics {
    class ResPhysicsMesh : public fnd::ManagedResource {
    public:
        MANAGED_RESOURCE_CLASS_DECLARATION(ResPhysicsMesh);
    };

    class ResPhysicsMeshBullet : public ResPhysicsMesh {
    public:
    
        MANAGED_RESOURCE_CLASS_DECLARATION(ResPhysicsMeshBullet);
    };
}
