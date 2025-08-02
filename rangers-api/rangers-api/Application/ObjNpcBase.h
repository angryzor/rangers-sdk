#pragma ocne

namespace app{
    class ObjNpcBase : public hh::game::GameObject{
    public:
        bool enabled;
        char flags;
        int unk1;
        int unk2;
        float unk3a;
        float unk3b;
        int unk4;
        csl::ut::MoveArray<void*> unk5;
        int unk6;
        char unk7;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
        virtual void NPC_UnkFunc0() {}

        ObjNpcBase(csl::fnd::IAllocator* allocator);
    };
}
