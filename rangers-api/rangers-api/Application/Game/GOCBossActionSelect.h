#pragma once

namespace app{
    class BossBaseContext;
}

namespace app::game{
    class GOCBossActionSelect;

    class BossActionPluginBase : public hh::fnd::ReferencedObject{
    public:
        struct StateInfo{
            int stateId;
            float timeSinceLastChange;
        };

        short unk0;
        short unk1;
        int unk2;
        app::BossBaseContext* context;

        virtual int GetNameHash() const { return 0; }
        virtual int64_t UnkFunc0() { return 0; }
        virtual void UnkFunc1() {}
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual bool UnkFunc4() { return false; }
        virtual bool UnkFunc5() { return false; }
        virtual bool UpdateState(int a2, float deltaTime) { return false; } //maybe some sort of update when state?
        virtual bool UnkFunc7() { return false; }
        virtual bool ProcessMessage(hh::fnd::Message& msg) { return false; }
        virtual bool UnkFunc9(int64_t a2) { return false; }
        virtual bool UnkFunc10(csl::ut::MoveArray<int64_t>& a2) { return false; }
        virtual bool UnkFunc11(int64_t a2) { return false; }
        virtual bool UnkFunc12(int64_t a2, csl::ut::String& a3) { return false; }
        virtual void UnkFunc13(int64_t a2, int64_t a3) {}
        virtual void ExecuteState0(int stateIdx) {}
        virtual void ExecuteState1(StateInfo& stateInfo) {}

        inline BossActionPluginBase(csl::fnd::IAllocator* allocator) : ReferencedObject{ allocator, true } {}
    };

    template<typename T>
    class BossActionPluginManager : public hh::fnd::BaseObject{
    public:
        csl::ut::MoveArray<GOCBossActionSelect*> gocs;
        T* context;
        csl::ut::MoveArray<BossActionPluginBase*> plugins;
        void* unk1;
    };

    class GOCBossActionSelect : public hh::game::GOComponent {
    public:
        struct Unk0{
            float unk0;
            int unk1;
            int unk2;
            char unk3;
            float unk4;
            int unk5;
            int unk6;
            int unk7;
            int unk8;
        };

        struct Description{
            app::BossBaseContext* context;
            bool postAnimUpdate;
            bool finalUpdate;
        };

        int64_t vftable;
        csl::ut::MoveArray<void*> states;
        app::BossBaseContext* context;
        BossActionPluginManager<app::BossBaseContext>* bossActionPluginMgr;
        int unk0;
        int unk1;
        float timeSinceLastAction;
        csl::ut::InplaceMoveArray<Unk0, 4> unk3;
        int unk4;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(Description& desc);

        GOCOMPONENT_CLASS_DECLARATION(GOCBossActionSelect)
    };
}
