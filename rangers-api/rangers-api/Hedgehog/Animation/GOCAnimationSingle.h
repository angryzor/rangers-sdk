#pragma once

namespace hh::anim {
    class AnimationManager;
    class GOCAnimationSingle : public GOCAnimation {
        enum class Type : uint8_t {
            UNK0,
            UNK1,
            UNK2,
        };
        enum class Flag : uint8_t {
            UNK2 = 2,
            USE_MODEL_SKELETON = 5,
            CREATE_SKELETAL_MESH_BINDING_ON_MODEL = 6,
        };

        Type unk101;
        uint8_t unk101a;
        csl::ut::Bitset<Flag> flags;
        unsigned int gocVisualModelNameHash;
        AnimationManager* animationManager;
        fnd::Reference<SkeletonBlender> skeletonBlender;
        gfx::GOCVisualModel* visualModel;
        fnd::Reference<ResSkeleton> skeleton;
        fnd::ReferencedObject* unk105;
        void* visualVisibilityHandle;
        uint64_t unk107;
        uint64_t unk108;
        csl::ut::MoveArray<void*> unk109;
        uint64_t unk110;
        csl::ut::LinkListNode linkListNode;
    public:
        struct SetupInfo {
            uint8_t unk1;
            uint8_t unk1a;
            bool setUnk6Flag;
            unsigned int gocVisualModelNameHash;
            uint32_t nameHash;
            anim::ResSkeleton* skeleton;
            fnd::ReferencedObject* unk6;
        };

        GOCAnimationSingle(csl::fnd::IAllocator* allocator);
        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        void Setup(const SetupInfo& setupInfo);
        void SetModel(gfx::GOCVisualModel* model);
        void ReleaseModel();
        void CreateBlender();
        void DestroyBlender();
        void SetBlenderUpdateFlag(bool enabled);
        void SetStateUpdateFlag(bool enabled);
    };
}
