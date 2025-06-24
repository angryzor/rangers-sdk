#pragma once

namespace hh::gfx {
    class ResAnimVis : public fnd::ManagedResource {
    public:
        void* resource;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimVis)
    };
}
