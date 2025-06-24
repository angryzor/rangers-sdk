#pragma once
#include <ucsl/resources/density-setting/v11.h>

namespace hh::gfx {
    UCSL_NEWTYPE_STRUCT_SIMPLE(DensitySettingData, ucsl::resources::density_setting::v11::DensitySettingData);

    class ResDensitySetting : public fnd::ManagedResource {
    public:
        DensitySettingData* densitySettingData;
        uint64_t unk2;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResDensitySetting)
    };
}
