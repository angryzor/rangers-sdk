#pragma once

namespace hh::gfx {
    class ResAnimCameraContainer : public fnd::ManagedResource {
    public:
        void* binaryData;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimCameraContainer)
    };
}
