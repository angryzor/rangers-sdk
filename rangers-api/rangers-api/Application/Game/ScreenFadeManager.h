#pragma once

namespace app::game{
    class ScreenFadeManager : 
        public hh::game::GameService, 
        public hh::game::GameStepListener, 
        public app::fnd::AppResourceManagerListener
    {
    public:
        hh::fnd::Handle<hh::game::GameObject> handle0;
        hh::fnd::Handle<hh::game::GameObject> handle1;
        hh::fnd::Handle<hh::game::GameObject> handle2;
        hh::fnd::Handle<hh::game::GameObject> handle3;
        int unk0;
        char unk1;
        csl::ut::String unk2; //[None]

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void ARML_UnkFunc0(int unkParam1) override;
        virtual void ARML_UnkFunc1(int unkParam1) override;

        GAMESERVICE_CLASS_DECLARATION(ScreenFadeManager)
    };
}
