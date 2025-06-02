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

        virtual void* GetInfo() override;
        virtual Object* UnkFunc(char unk) override;
        virtual void* ContUnkFunc9(float unk) override;
        virtual void* ContUnkFunc11() override;
        virtual void* ContUnkFunc16() override;
        virtual void* ContUnkFunc17() override;
        virtual char ContUnkFunc18(void* unk) override;
        virtual char ContUnkFunc19(void* unk) override;
        virtual void* ContUnkFunc23() override;
        virtual void* ContUnkFunc32() override;
        virtual void* ContUnkFunc47() override;

        Button();
        Button(const char* text);
    };
}