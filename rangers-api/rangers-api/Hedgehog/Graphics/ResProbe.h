#pragma once
#include <ucsl/resources/probe/v2.h>

namespace hh::gfx {
    UCSL_NEWTYPE_SIMPLE(ProbeData, ucsl::resources::probe::v2::ProbeData);
    UCSL_NEWTYPE_SIMPLE(ResProbeData, ucsl::resources::probe::v2::ResProbeData);

    class ResProbe : public fnd::ManagedResource {
    public:
        ResProbeData* probeData;
        void* reloadedPackedBinaryData;

        virtual void Load(void* data, size_t size) override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResProbe)
    };
}
