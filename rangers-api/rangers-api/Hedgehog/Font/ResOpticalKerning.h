#pragma once
#include <ucsl/resources/okern/v1.h>

namespace hh::font{
    using ucsl::resources::okern::v1::OkernData;

    class ResOpticalKerning : public fnd::ManagedResource{
    public:
        OkernData* okernData;    

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        MANAGED_RESOURCE_CLASS_DECLARATION(ResOpticalKerning)
    };
}
