#pragma once

namespace app::ui {
    class UIScrollBarMouseControllerForRangers {
    public:
        uint32_t dword8;
        uint64_t qword10;
        csl::ut::MoveArray<void*> unk18;
        uint16_t word38;
        uint8_t byte3A;
        uint8_t gap3B;
        uint32_t dword3C;
        float float40;
        uint16_t word44;
        uint64_t qword48;
        uint8_t byte50;

        DEFAULT_CREATE_FUNC(UIScrollBarMouseControllerForRangers);
        virtual ~UIScrollBarMouseControllerForRangers() = default;
    };

    class UIVolumeGaugeMouseControllerForRangers {
        virtual ~UIVolumeGaugeMouseControllerForRangers() = default;
    };

    class UIMainMenuContext : public app_cmn::fsm::GOCHsmContext, hh::hid::ActiveDeviceManagerListener {
    public:
        class State {
            csl::ut::MoveArray<csl::ut::Pair<size_t, size_t>> values;
            
        public:
            void SetValue(size_t id, unsigned int value);
            unsigned int GetValue(size_t id) const;
        };

        uint8_t byte28;
        State state;
        app::ut::TransitionValue<csl::math::Vector3> unk50;
        app::ut::TransitionValue<float> unkB0;
        char byteF8;
        char byteF9;
        uint32_t dwordFC;
        uint64_t qword100;
        uint64_t qword108;
        uint64_t qword110;
        uint64_t qword118;
        uint64_t qword120;
        uint64_t qword128;
        uint64_t qword130;
        uint64_t qword138;
        uint64_t qword140;
        uint64_t qword148;
        uint64_t qword150;
        uint64_t qword158;
        csl::ut::MoveArray<void*> unk160;
        csl::ut::MoveArray<void*> unk180;
        csl::ut::MoveArray<void*> unk1A0;
        csl::ut::MoveArray<void*> unk1C0;
        csl::ut::MoveArray<void*> unk1E0;
        UIScrollBarMouseControllerForRangers unk200;
        UIScrollBarMouseControllerForRangers unk258;
        UIScrollBarMouseControllerForRangers unk2B0;
        UIScrollBarMouseControllerForRangers unk308;
        UIScrollBarMouseControllerForRangers unk360;
        uint64_t qword3B8;
        uint64_t qword3C0;
        uint64_t qword3C8;
        uint64_t qword3D0;
        uint64_t qword3D8;
        csl::ut::MoveArray<void*> unk3E0[3];
        uint64_t qword440;
        uint64_t qword448;
        uint64_t qword450;
        hh::gfnd::Renderable *renderable458;
        uint8_t byte460;

        DEFAULT_CREATE_FUNC(UIMainMenuContext);
        virtual void OnDeviceChange() override;
    };

    class UIMainMenu
        : public hh::game::GameObject
        , public hh::ui::UIListener
        , public hh::fw::MouseEventHandler
        , public game::ApplicationDisplayOptionExtension::Listener {
    public:
        GAMEOBJECT_CLASS_DECLARATION(UIMainMenu);

        uint32_t unk201;
        int16_t unk202;
        hh::fnd::Reference<UIMainMenuContext> context;
        uint64_t unk204;
        uint8_t unk205;

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void UIL_UnkFunc1() override;
        virtual bool MEH_Unk1() override;
        virtual bool MEH_Unk2() override;
        virtual bool MEH_Unk3() override;
        virtual bool MEH_Unk4() override;
        virtual void ADOEL_UnkFunc1(void* unkParam1, uint32_t unkParam2) override;
    };
}
