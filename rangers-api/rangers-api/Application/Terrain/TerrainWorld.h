#pragma once

namespace app::trr {
    class TerrainWorld;

    class TerrainWorldExtension : public hh::fnd::BaseObject {
    public:
        TerrainWorld* trrWrld;
        
        virtual unsigned int GetNameHash() const;
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void Initialize() {}
        virtual void Deinitialize() {}
        virtual void UnkFunc6() {}
        virtual bool UnkFunc7() { return true; }
    };

    class TerrainWorld : public hh::fnd::ReferencedObject, public TerrainLoadListener {
    public:
        class SvColTree : public hh::fnd::ReferencedObject {
        public:
            hh::fnd::Reference<app::ResSvCol2> resource;
            hh::fnd::Reference<hh::ut::KdTree> kdTree;
            hh::ut::ResKdTreeData* kdTreeResource;

            struct QueryResults {
                unsigned long long skyMask[2];
                unsigned long long groundMask[2];
            };

            bool Query(const csl::ut::MoveArray<csl::math::Vector3>& playerPositions, QueryResults& results);
        };

        enum class Flag : unsigned char {
            LOADED,
            OBJECTS_CREATED,
        };

        struct SetupInfo {
            hh::game::GameManager* gameManager;
            TerrainManager::SetupInfo terrainManagerSetupInfo;
        };

        hh::game::GameManager* gameManager;
        char terrainId[32]; // == stage id
        char terrainName[32]; // == stage name
        csl::ut::Bitset<Flag> flags;
        hh::fnd::Reference<TerrainLoader> terrainLoader;
        hh::fnd::Reference<app::ResSvCol2> svColResource;
        csl::ut::String name2;
        hh::fnd::Reference<TerrainVisualResourceBinder> trrVisResBinders[2];
        hh::fnd::Handle<hh::game::GameObject> objects[2]; // 0 = ground, 1 = sky
        hh::fnd::Reference<SvColTree> svColTree;
        csl::ut::MoveArray<TerrainWorldExtension*> extensions;
        csl::ut::MoveArray<void*> maybeListeners;

        virtual void TLL_UnkFunc1(const char* name) override;
        virtual void TLL_UnkFunc2(void* unkParam1) override;
        virtual void TLL_UnkFunc3(void* unkParam1, uint32_t unkParam2) override;

        void Setup(const SetupInfo& setupInfo);
    };
}
