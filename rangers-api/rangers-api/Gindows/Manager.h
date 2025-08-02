#pragma once

namespace gindows{
    class Control;

    class TaskBar : public Object {
    public:
        void Enter(Control* value);
        void Leave(Control* value);
    };

    class ManagerImpl : public Object {
    public:
        void* unk0;
        void* unk1;
        void* font;
        csl::ut::Color8 backColor;
        csl::ut::Color8 foreColor;
        void* unk2;
        void* unk3;
        void* unk4;
        void* unk5;
        void* unk6;
        void* unk7;
        void* unk8;
        Form* focusedForm;
        void* unk10;

        void SetActiveForm(Form* form);
        void SetFocusControl(Control* control);
    };

    class Manager : public Object {
    public:
        void* unk0;
        void* unk1;
        ManagerImpl* impl;
        WindowManager* windowManager;

        TaskBar* GetTaskBar();
        int64_t GetDefaultFontPointer();
        int64_t GetGraphicsPointer();
        int64_t GetDefaultBackColorPointer();
        int64_t GetDefaultForeColorPointer();

        static Manager* instance;
        static Manager* GetInstance();
    };
}
