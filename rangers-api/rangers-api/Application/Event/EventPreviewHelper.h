#pragma once

namespace app::evt{
    class EventPreviewHelper : public 
        hh::game::GameService, 
        hh::game::GameStepListener, 
        hh::game::GameManagerListener, 
        hh::dv::DiEventPreviewEventListener, 
        hh::dv::DvSceneControlListener
    {
    public:
        struct UnkStr{
        public:
            long long unk0;
            heur::rfl::ObjMessageTestSpawner unk1;
            csl::math::Matrix34 unk2;
            int dword60;
            char byte64;
        };

        hh::dv::DiEventPreviewManager* diEvtPrMgr;
        void* gindowsWindow;
        void* qwordA0;
        UnkStr unkStr;
        char byte120;
        char gap121[15];
        char byte130;
        char gap131[31];
        char byte150;
        char gap151[31];
        char flags;
        float float174;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
        virtual void GameServiceAddedCallback(hh::game::GameService* gameService) override;
		virtual void GameServiceRemovedCallback(hh::game::GameService* gameService) override;
        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual void DSCL_UnkFunc15() override;
        virtual void DSCL_UnkFunc16() override;

    private:
        static const hh::game::GameServiceClass gameServiceClass;
        EventPreviewHelper(csl::fnd::IAllocator* allocator);
        static hh::game::GameService* Create(csl::fnd::IAllocator* allocator);
    };
}
