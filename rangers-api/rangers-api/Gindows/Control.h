#pragma once

namespace gindows{
    class Control;
    class Form;

    class ControlCollection {
    public:
        Control* self;
        csl::ut::MoveArray<Control*> values;

        void Add(Control* newChild);

        ControlCollection(csl::fnd::IAllocator* allocator);
    };

    class Control : public Component {
    public:
        struct UnkStr3 {
        public:
            int64_t unk0;
            int64_t unk1;
            int64_t unk2;
            csl::fnd::IAllocator* unk3;
        };

        csl::ut::MoveArray<void*> onRenderDelegate;
        csl::ut::MoveArray<void*> onLocationChangedDelegate;
        csl::ut::MoveArray<void*> qword80;
        csl::ut::MoveArray<void*> qwordA0;
        csl::ut::MoveArray<void*> qwordC0;
        csl::ut::MoveArray<void*> qwordE0;
        csl::ut::MoveArray<void*> qword100;
        csl::ut::MoveArray<void*> onClickDelegate;
        csl::ut::MoveArray<void*> qword140;
        csl::ut::MoveArray<void*> qword160;
        csl::ut::MoveArray<void*> qword180;
        csl::ut::MoveArray<void*> qword1A0;
        csl::ut::MoveArray<void*> qword1C0;
        csl::ut::MoveArray<void*> qword1E0;
        csl::ut::MoveArray<void*> qword200;
        csl::ut::MoveArray<void*> onSizeChangedDelegate;
        csl::ut::MoveArray<void*> onGotFocusDelegate;
        csl::ut::MoveArray<void*> qword260;
        csl::ut::MoveArray<void*> qword280;
        csl::ut::MoveArray<void*> qword2A0;
        csl::ut::MoveArray<void*> qword2C0;
        csl::ut::MoveArray<void*> onMouseEnterDelegate;
        csl::ut::MoveArray<void*> onMouseLeaveDelegate;
        csl::ut::MoveArray<void*> qword320;
        csl::ut::MoveArray<void*> qword340;
        csl::ut::MoveArray<void*> qword360;
        csl::ut::MoveArray<void*> qword380;
        csl::ut::MoveArray<void*> qword3A0;
        csl::ut::MoveArray<void*> qword3C0;
        csl::ut::MoveArray<void*> qword3E0;
        csl::ut::MoveArray<void*> qword400;
        csl::ut::MoveArray<void*> onDestroyDelegate;
        csl::ut::MoveArray<void*> onExecuteDelegate;
        csl::ut::MoveArray<void*> qword460;
        csl::ut::MoveArray<void*> qword480;
        csl::ut::MoveArray<void*> qword4A0;
        csl::ut::MoveArray<void*> qword4C0;
        int64_t flags4E0; // flags, see ctor
        Control* qword4E8; // see sub_14114c860, sub_14114e0e0
        ControlCollection children;
        String name;
        Canvas canvas0;
        int64_t qword658;
        int64_t qword660;
        int64_t oword668;
        int64_t oword670;
        int64_t qword678;
        int* preferredClientSize;
        int64_t qword688;
        int dword690;
        int64_t qword694;
        int displayLocation;
        int64_t qword6A0;
        int64_t qword6A8;
        int dword6B0;
        String string6B8;
        int dword708;
        char byte70C;
        void* qword710;
        csl::ut::MoveArray<void*> unkArray0;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void CompUnkFunc() override;

        virtual void ContUnkFuncNull() {};
        virtual void ContUnkFunc0(int* unk);
        virtual void ContUnkFunc1();
        virtual void* ContUnkFunc2();
        virtual void ContUnkFunc3();
        virtual void SetSize(int& size); // const csl::ut::Size2&
        virtual void GetDisplayLocation(int* value);
        virtual void GetLocalPreferredClientSize(int* value);
        virtual void SetLocalPreferredClientSize(int* value);
        virtual void ContGetQWORD688(void* value);
        virtual void ContSetQWORD688(void* value);
        virtual void* ContUnkFunc5(void* unk);
        virtual void GetPreferredClientSize(int* value);
        virtual int SaveProperty(void* propertyNode);
        virtual int LoadProperty(void* propertyNode);
        virtual char Render();
        virtual int OnDestroy();
        virtual int OnExecute(double unk);
        virtual int OnRender(); // something with qword40
        virtual int OnLocationChanged(); // something with qword60
        virtual int OnSizeChanged(); // something with qword220
        virtual int OnGotFocus(); // something with qword240
        virtual int OnClick(); // something with qword120
        virtual int OnMouseLeave(); // something with qword300
        virtual int OnMouseEnter(); // something with qword2E0
        virtual char ContUnkFunc18(void* unk);
        virtual char ContUnkFunc19(void* unk);
        virtual void* ContUnkFunc20(); // something with qword320
        virtual void* ContUnkFunc21(); // something with qword360
        virtual void* ContUnkFunc22(); // something with qword260
        virtual void* ContUnkFunc23(); // something with qword2A0
        virtual void* ContUnkFunc24(void* unk); // something ver2 with qword280
        virtual void* ContUnkFunc25(void* unk); // something ver2 with qword3C0
        virtual void* ContUnkFunc26(void* unk); // something ver2 with qword3E0
        virtual void* ContUnkFunc27(void* unk); // something ver2 with qword400
        virtual void* ContUnkFunc28(); // something with qword480
        virtual void* ContUnkFunc29(); // something with qword380
        virtual void* ContUnkFunc30(); // something with qword3A0
        virtual void* ContUnkFunc31(); // something with qwordC0
        virtual void* ContUnkFunc32(); // something with qwordA0
        virtual void* ContUnkFunc33(); // something with qword4A0
        virtual void* ContUnkFunc34(); // something with qword4C0
        virtual void ContUnkFunc35() {};
        virtual char ContUnkFunc36(); // something ver3 with qword4E0
        virtual bool ContUnkFunc37() { return false; }
        virtual void* ContUnkFunc38(); // something with qword1E0
        virtual void* ContUnkFunc39(); // something with qword200
        virtual void* ContUnkFunc40(); // something with qword80
        virtual void* ContUnkFunc41(); // something with qword160
        virtual void* ContUnkFunc42(); // something with qword180
        virtual void* ContUnkFunc43(); // something with qword1A0
        virtual void* ContUnkFunc44(); // something with qword1C0
        virtual void* ContUnkFunc45(); // extended something with qword100
        virtual void ContUnkFunc46() {};
        virtual void* ContUnkFunc47(); // something ver2 with qword140
        virtual void* ContUnkFunc48(); // something with qwordE0
        
        void Select();
        void SetPauseExecute(bool paused);
        void SetName(const char* name);
        int GetFontHeight();
        int AddSavePropertyEnabled(const char* name, int value);
        Form* FindForm();

        Control();
    };
}