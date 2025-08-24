#pragma once

namespace hh::navmesh{
    class ResNavMeshConfig : public fnd::ManagedResource {
    public:
        void* data;
        int unk0;

        virtual void Load(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResNavMeshConfig)
    };
}
