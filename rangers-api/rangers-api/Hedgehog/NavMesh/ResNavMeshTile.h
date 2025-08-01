#pragma once

namespace hh::navmesh{
    class ResNavMeshTile : public fnd::ManagedResource {
    public:
        void* headerData;
        void* subData;
        int unk0;
        
        virtual void Load(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResNavMeshTile)
    };
}
