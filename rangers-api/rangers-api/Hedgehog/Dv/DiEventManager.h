#pragma once

namespace hh::dv {
    class DiEventManager : public hh::game::GameService, DvSceneControlListener {
    public:
        class ScenePlaybackInfo : public hh::fnd::ReferencedObject{
        public:
            hh::fnd::Handle<DvSceneControl> dvSceneControl;
        };

        struct Description{
            int64_t unk0; //see 0x1401EE7CD
        };

        csl::ut::MoveArray<ScenePlaybackInfo*> scenePlaybackInfos;
        csl::ut::MoveArray<DvSceneControlListener*> listeners;
        long long unk0;
        int unk1;
        char dvObjectsLayer;
        int unk3;
        int currentScenePlaybackInfoId;
        char unk4;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual bool ReceiveMessage(hh::fnd::Message& message) override;
        virtual void OnAddedToGame() override;
        virtual void OnRemovedFromGame() override;
        virtual void OnCutsceneEnd() override;

        virtual void Setup(Description& desc);
        virtual bool UnkFunc1() { return false; }
        virtual bool HasDvSceneControl();
        virtual bool AnyCutscenePlaying();
        virtual void AddListener(DvSceneControlListener* listener);
        virtual void RemoveListener(DvSceneControlListener* listener);
        virtual DvSceneControl* GetDvSceneControl();

        GAMESERVICE_CLASS_DECLARATION(DiEventManager)
    };
}
