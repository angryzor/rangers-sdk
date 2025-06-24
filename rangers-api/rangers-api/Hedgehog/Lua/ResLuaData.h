#pragma once

namespace hh::fnd{
    class ResLuaData : public ManagedResource {
    public:
        void* binaryData;

        virtual void Load(void* data, size_t size) override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResLuaData)
    };
}
