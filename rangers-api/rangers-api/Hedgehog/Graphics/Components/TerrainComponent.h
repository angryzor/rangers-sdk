#pragma once
#include <ucsl/resources/terrain-material/v1.h>

namespace hh::gfx{
    class TerrainComponent : public RenderingComponent{
    public:
        struct NameSetupInfo{
            csl::fnd::IAllocator* allocator;
            const char* unkName0;
            const char* unkName1;
            const char* unkName2;
            const char* trrName;
        };

        class Impl : public fnd::ReferencedObject{
        public:
            ucsl::resources::terrain_material::v1::Material* trrMaterials;
            unsigned long long trrMaterialCount;
            int unkIds0[128];
            int unkIds1[128];
            int unk0;
            int unk1;
            csl::ut::VariableString unkName0; //says environment
            csl::ut::VariableString unkName1; //says height
            csl::ut::VariableString unkName2; //says decal
            const char* trrName;
            csl::ut::MoveArray<game::GameObject*> relatedGameObjects;
            char unk2;
        };
        fnd::Reference<Impl> implementation;

        TerrainComponent(csl::fnd::IAllocator* allocator);
        virtual int GetNameHash() override;
        virtual const char* GetName() override;

        void SetupNames(NameSetupInfo& setupinfo);
    };
}
