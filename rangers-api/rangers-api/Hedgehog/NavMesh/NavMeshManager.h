#pragma once

namespace hh::navmesh{
    class NavMeshImpl : public fnd::ReferencedObject {
    public:
        struct Tile {
            ResNavMeshTile* resTile;
            char unk0;
        };

        ResNavMeshConfig* resConfig;
        csl::ut::MoveArray<Tile> tiles;
        void* config;

        NavMeshImpl(csl::fnd::IAllocator* allocator);
    };

    class NavMeshManager : public game::GameService, public game::GameStepListener {
    public:
        struct Agent {
            NavMeshAgent* agent;
            int64_t unk0;
            char unk1;
        };

        struct Description{
            unsigned int unk4Count;
        };

        fnd::Reference<NavMeshImpl> implementation;
        csl::ut::String stageName;
        heur::rfl::NavMeshParameter params;
        csl::ut::MoveArray<NavMeshManagerExtension*> extensions;
        csl::ut::MoveArray<int64_t> unk0;
        csl::ut::MoveArray<Agent> agents;
        fnd::Reference<NavMeshAgent> currentAgent;
        csl::ut::MoveArray<int64_t> unk1;
        char unk2;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void UpdateCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        void Setup(Description& desc);
        void AddAgent(Agent& agent);
        void RemoveAgent(Agent& agent);

        GAMESERVICE_CLASS_DECLARATION(NavMeshManager)
    };
}
