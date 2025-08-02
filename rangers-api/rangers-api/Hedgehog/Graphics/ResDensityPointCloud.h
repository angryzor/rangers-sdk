#pragma once
#include <ucsl/resources/density-pointcloud/v4.h>

namespace hh::gfx{
    UCSL_NEWTYPE_STRUCT_SIMPLE(DensityPointCloudData, ucsl::resources::density_pointcloud::v4::DensityPointCloudData);

    class ResDensityPointCloud : public fnd::ManagedResource{
    public:
        DensityPointCloudData* densityPointCloudData;
        uint64_t unk2;

        virtual void Load(void* data, size_t size) override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResDensityPointCloud)
    };
}
