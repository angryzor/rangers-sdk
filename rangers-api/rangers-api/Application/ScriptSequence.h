#pragma once

namespace app{
    class ScriptSequenceManager;

    class ScriptSequence : public hh::fnd::Messenger, public hh::game::GameStepListener {
    public:
        struct Description{
            char scriptName[64];
            int unk0;
            hh::fnd::Handle<hh::game::GameObject> scriptObject;
            hh::fnd::Handle<hh::game::GameObject> unk1;
            bool isEndKill;
            int unk3;
            char unk4;
        };

        ScriptSequenceManager* sequenceMgr;
        char unk1;
        hh::fnd::Reference<game::Script> orderScript;
        hh::fnd::Reference<game::Script> clearedScript;
        hh::fnd::Reference<game::Script> script2;
        hh::fnd::Reference<game::Script> activateScript;
        hh::fnd::Reference<game::Script> script4;
        int unk2;
        char scriptName[0x40];
        hh::fnd::Handle<hh::game::GameObject> scriptObject;
        hh::fnd::Handle<hh::game::GameObject> unk3;
        int unk4;
        bool isEndKill;
        int unk6;
        int unk7;
        int unk8;
        int unk9;
        int unk10;
        int unk11;
        int unk12;
        int unk13;
        int unk14;
        int unk15;
        int unk16;
        int unk17;
        int unk18;
        char unk19;
        int unk20;
        int unk21;
        char unk23;
        char unk23b;
        char unk24;
        int unk25;
        int unk25b;
        int unk25c;
        float unk25d;
        char unk26[0x40];
        char unk27[0x40];
        int64_t unk28;
        int unk29;
        short unk30;
        csl::ut::MoveArray<void*> unk31;
        csl::ut::MoveArray<void*> unk32;
        int unkHandle1;
        csl::ut::MoveArray<void*> unk33;
        int unk34;
        int unk35;
        char unk36;
        int unk37;
        hh::fnd::Reference<hh::game::LevelLoader> levelLoader;
        csl::ut::MoveArray<void*> unk38;
        char unk39;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;

        void SetManager(ScriptSequenceManager* mgr);
        void InitializeScript(game::Script* script);
        hh::game::GameService* GetService(const hh::game::GameServiceClass* serviceClass) const;
        template<typename T>
        inline T* GetService(){
            return static_cast<T*>(GetService(T::GetClass()));
        }
        hh::game::GameManager* GetGameManager() const;

        void Setup(Description& desc);
        bool IsUnk6Zero() const;

        ScriptSequence(csl::fnd::IAllocator* allocator);
    };
}
