#pragma once

namespace app::trr {
    class TerrainVisualObject : public hh::game::GameObject {
    public:
        struct Sector {
            csl::ut::MoveArray<void*> unk1;
            csl::ut::MoveArray<void*> unk2;
            csl::ut::MoveArray<void*> unk3;
            uint64_t unk4;
            bool enabled;
        };

        TerrainWorld* world;
        hh::game::GOCTransform* gocTransform;
        void* gocPointLight;
        csl::ut::MoveArray<Sector> sectors;
        uint8_t unk204;
        bool isNonZeroStageIndex;

        TerrainVisualObject(csl::fnd::IAllocator* allocator);

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
        virtual void LoadLight(const char* stageId) = 0;
        virtual void UnkFunc13() = 0;
        virtual bool UnkFunc14() = 0;
        virtual void UnkFunc15() {}

        struct SetupInfo {
            TerrainWorld* world;
            TerrainVisualResourceBinder* resourceBinder;
        };

        void Setup(const SetupInfo& setupInfo);
    };
}
