#pragma once

namespace gindows{
    class Button : public Control {
    public:
        char byte738;
        int qword73C;
        int qword740;
        int qword744;
        int qword748;
        int int74C; // somekind of type
        int int750; // somekind of type
        int dword754;
        int64_t qword758;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual int OnExecute(double unk) override;
        virtual int OnLocationChanged() override;
        virtual int OnMouseLeave() override;
        virtual int OnMouseEnter() override;
        virtual char ContUnkFunc18(void* unk) override;
        virtual char ContUnkFunc19(void* unk) override;
        virtual void* ContUnkFunc23() override;
        virtual void* ContUnkFunc32() override;
        virtual void* ContUnkFunc47() override;

        void SetStyle(int64_t style);

        Button();
        Button(const char* text);
    };
}