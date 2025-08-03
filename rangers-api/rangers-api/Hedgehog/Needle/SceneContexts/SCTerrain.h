#pragma once

namespace hh::needle {
    class SCTerrain : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
        public:
            SCTerrain& sceneContext;
            uint32_t halfSize; //2048
            uint8_t byte1C;
            uint32_t heightmapTexelDensity;
            heur::rfl::StageTerrainPrecisionParameter trrPrecisionParam;
            float heightScale;
            uint8_t byte2C;
            heur::rfl::StageTerrainMaterialParameter trrMaterialParam;
            uint32_t qword40;
            uint32_t qword44;
            uint32_t qword48;
            uint32_t dword4C;
            intrusive_ptr<hh::needle::Texture> unkTexture0;
            intrusive_ptr<hh::needle::Texture> unkTexture1;
            intrusive_ptr<hh::needle::Texture> unkTexture2;
            intrusive_ptr<hh::needle::Texture> unkTexture3;
            intrusive_ptr<hh::needle::Texture> unkTexture4;
            uint64_t qword78;
            uint64_t qword80;
            uint64_t qword88;
            uint64_t qword90;
            intrusive_ptr<NeedleRefcountObject> qword98[6];
            intrusive_ptr<NeedleRefcountObject> qwordC8[6];
            uint64_t qwordF8;
            uint64_t qword100;
            uint64_t qword108;
            csl::ut::MoveArray<hh::needle::Texture*> brushes;
            intrusive_ptr<hh::needle::Texture> qword130[6];

            Impl(SCTerrain& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCTerrain);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
    };
}
