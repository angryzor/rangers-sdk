#pragma once

namespace app::game{
    class GOCBossCyloopColliderHelper : public hh::game::GOComponent {
    public:
        struct Unk0{
            int unk0;
            int unk1;
            hh::gfx::ModelNodeHFrame* hFrame;
            float unk2;
        };

        csl::ut::MoveArray<Unk0> unks;
        int unk0;

        virtual void* GetRuntimeTypeInfo() const override;

        GOCOMPONENT_CLASS_DECLARATION(GOCBossCyloopColliderHelper)
    };
}
