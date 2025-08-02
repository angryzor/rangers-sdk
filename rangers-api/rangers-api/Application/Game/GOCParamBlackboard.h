#pragma once

namespace app::game{
    class GOCParamBlackboard : public hh::game::GOComponent {
    public:
        struct Unk0{
            int unk0;
            int unk1;
            int unk2;
            int unk3;
        };

        int unk0; //prolly handle
        char unk1;
        int unk2;
        char unk3;
        csl::ut::MoveArray<Unk0> unk4;

		virtual void* GetRuntimeTypeInfo() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCParamBlackboard)
    };
}
