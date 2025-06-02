#pragma once

namespace hh::eff {
    class ResEffect : public fnd::ManagedResource {
    public:
        uint8_t unk101;
        csl::ut::StringMap<fnd::Reference<ResEffect>> childEffectsByName; // something with child effects, see 1.42 0x140215a20
        csl::ut::MoveArray<const char*> childEffectNames;
        uint64_t unk104;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Resolve(fnd::ResourceResolver& resolver) override;
        virtual void Reload(void* data, size_t size) override {}

        MANAGED_RESOURCE_CLASS_DECLARATION(ResEffect)
    };
}
