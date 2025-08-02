#pragma once

namespace hh::gfx{
    class ResAnimLightContainer : public hh::fnd::ManagedResource{
    public:
        void* resource;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimLightContainer)
    };
}
