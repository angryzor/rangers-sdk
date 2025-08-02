#pragma once

namespace hh::navmesh{
    class GOCNavMeshAgent : public game::GOComponent, public fnd::HFrame::Listener {
    public:
        enum class Flags : unsigned char {
            HAS_HFRAME
        };

        struct Description {
            fnd::HFrame* frame;
            unsigned int unk4Count;
            unsigned int agentCount;
        };

        fnd::HFrame* hFrame;
        csl::ut::MoveArray<NavMeshManager::Agent> agents;
        csl::ut::Bitset<Flags> flags;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(fnd::UpdatingPhase phase, const fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;

        void Setup(Description& desc);
        void SetHFrame(fnd::HFrame* frame);
        void SetIncludeFlag(unsigned char bit, unsigned int idx);
        int64_t GetUnk(unsigned int idx) const;
        char GetUnkChar(unsigned int idx) const;
        char SetDestination(csl::math::Vector3& destination, int64_t unk0, int unk1);

        GOCOMPONENT_CLASS_DECLARATION(GOCNavMeshAgent)
    };
}
