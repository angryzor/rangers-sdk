#pragma once

namespace app::trr{
    class TerrainWorldHeightMapExtension : public TerrainWorldExtension{
    public:
        virtual unsigned int GetNameHash() const override;
        virtual void Initialize() override;
        virtual void Deinitialize() override;

        TerrainWorldHeightMapExtension(csl::fnd::IAllocator* allocator);
    };
}
