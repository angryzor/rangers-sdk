#pragma once

namespace app{
    class ResGismoConfigPlan : public hh::fnd::ManagedResource {
    public:
        int64_t unk0;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResGismoConfigPlan)

        virtual void Load(void* data, size_t size) override;
    };
}
