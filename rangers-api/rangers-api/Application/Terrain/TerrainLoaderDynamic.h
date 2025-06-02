#pragma once

namespace app::trr {
    class TerrainLoadListener {
    public:
        virtual void TLL_UnkFunc1(const char* name) {}
        virtual void TLL_UnkFunc2(void* unkParam1) {}
        virtual void TLL_UnkFunc3(void* unkParam1, uint32_t unkParam2) {}
    };

    class TerrainLoader : public hh::fnd::ReferencedObject {
    public:
        TerrainLoadListener* listener;
        char terrainId[64];
        char terrainName[64];
        csl::ut::InplaceMoveArray<uint8_t, 100> staticSectors;
        csl::ut::InplaceMoveArray<uint8_t, 100> dynamicSectors;
        bool initialized;
        hh::fnd::Reference<hh::game::LevelLoader> levelLoader;
        uint8_t byte1C0;

        TerrainLoader(csl::fnd::IAllocator* allocator);

        virtual void UnkFunc1() {}
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() = 0;
        virtual bool UnkFunc4() { return true; }
        virtual bool UnkFunc5() { return true; }
        virtual bool UnkFunc6() = 0;
        virtual void UnkFunc7() {}
        virtual void UnkFunc8() {}
        virtual void UnkFunc9() {}
    };

    class TerrainLoaderDynamic : public TerrainLoader {
    public:
        level::StageInfo* stageInfo;
        hh::ut::TinyFsm<TerrainLoaderDynamic> fsm;
        uint8_t unk202;
        unsigned int currentDynamicSector;
        uint64_t loadedDynamicSectorsBitmask[2];
        uint8_t unk205;

        struct SetupInfo {
            const char* terrainId;
            const char* terrainName;
            uint8_t* staticSectors;
            uint8_t* dynamicSectors;
            unsigned int staticSectorCount;
            unsigned int dynamicSectorCount;
        };

        CREATE_FUNC(TerrainLoaderDynamic, level::StageInfo* stageInfo);

        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual bool UnkFunc4() override;
        virtual bool UnkFunc5() override;
        virtual bool UnkFunc6() override;
        virtual void UnkFunc7() override;
        virtual void UnkFunc9() override;

        void Setup(const SetupInfo& setupInfo);
    };
}
