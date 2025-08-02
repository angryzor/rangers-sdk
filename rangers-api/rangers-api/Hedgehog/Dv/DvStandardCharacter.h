#pragma once

namespace hh::dv{
    class DvStandardCharacter : public hh::game::GameObject {
    public:
        struct Description{
            hh::gfx::ResModel* modelResource;
            hh::anim::ResSkeletonPxd* skelResource;
            hh::anim::ResAnimator* asmResource;
            csl::ut::Bitset<hh::gfx::GOCVisualModelDescription::Flag> flags;
            DvNodeCharacter* node;
            char unk0;
        };

        hh::gfx::ResModel* modelResource;
        hh::anim::ResSkeletonPxd* skelResource;
        hh::anim::ResAnimator* asmResource;
        csl::ut::Bitset<hh::gfx::GOCVisualModelDescription::Flag> flags;
        DvNodeCharacter* node;
        void* unk0;
        int unk1;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        void Setup(Description& desc);
        void Initialize(bool unk0);

        GAMEOBJECT_CLASS_DECLARATION(DvStandardCharacter)
    };
}
