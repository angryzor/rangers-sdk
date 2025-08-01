#pragma once
#include <ucsl/resources/navmeshconfig/v1.h>

namespace hh::navmesh{
    class ResNavMeshConfig : public fnd::ManagedResource {
    public:
        ucsl::resources::navmeshconfig::v1::NavMeshConfigData* data;
        int unk0;

        virtual void Load(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResNavMeshConfig)
    };
}
