#pragma once

namespace app_cmn::fsm {
    class GOCHsm2;
    class GOCHsmContext : public hh::fnd::ReferencedObject {
    public:
        GOCHsm2* gocHsm2;
    };

    class GOCHsm2 : public hh::game::GOComponent {
        hh::ut::StateManager* stateManager;
        hh::ut::HsmBase hsm;
        int currentStateIdx;
        int bottomStateIdx;
        bool unk103;
        uint32_t unk104;
        csl::ut::InplaceMoveArray<void*, 1> unk105;
        app_cmn::fsm::GOCHsmContext* hsmContext;
        uint64_t unk107;
    public:
        struct Description {
            void* states;
            unsigned int stateCount;
            unsigned int stateCapacity;
            int stateStart;
            int32_t updatePriority;
            int32_t messageMask;
            bool preAnimUpdate;
            bool postAnimUpdate;
            bool finalUpdate;
            bool unkFlag;
            app_cmn::fsm::GOCHsmContext* hsmContext;
        };

        GOCHsm2(csl::fnd::IAllocator* pAllocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        void Setup(Description& desc);

        int GetBottomStateId();
        bool UnkFunc0(int a2);

        GOCOMPONENT_CLASS_DECLARATION(GOCHsm2)
    };

    template<typename T>
    class GOCStateBase : public hh::ut::StateBase<T>{
    public:
        inline GOCStateBase(csl::fnd::IAllocator* allocator) : hh::ut::StateBase<T>{ allocator } {}

        virtual bool GSB_UnkFunc0(T& context) { return false; }
        virtual bool GSB_UnkFunc1(T& context) { return false; }
        virtual bool GSB_UnkFunc2(T& context) { return false; }
        virtual void GSB_UnkFunc3(T& context, int64_t a3, int64_t a4, char a5) {}
        virtual bool GSB_UnkFunc4(T& context) { return false; }
    };
}
