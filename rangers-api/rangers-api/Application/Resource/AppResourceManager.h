#pragma once

namespace app::fnd {
    class AppResourceManagerListener {
    public:
        virtual void ARML_UnkFunc0(int unkParam1) {}
        virtual void ARML_UnkFunc1(int unkParam1) {}
    };

    class AppResourceManager : public hh::game::GameService, public hh::game::GameStepListener{
    public:
        void* packFileListeners[7];
        hh::game::LevelLoader* levelLoaders[7];
        csl::ut::MoveArray<AppResourceManagerListener*> listeners;
        char languageCode[8];
        hh::game::LevelLoader* currentLevelLoader;
        char unk0;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
        virtual void PreStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        void AddListener(AppResourceManagerListener* listener);
        void RemoveListener(AppResourceManagerListener* listener);

        GAMESERVICE_CLASS_DECLARATION(AppResourceManager)
    };
}
