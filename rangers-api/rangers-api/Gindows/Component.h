#pragma once

namespace gindows{
    class Component : public Object {
    public:
        int64_t qword0;
        int dword8;
        csl::ut::MoveArray<void*> unkArray;
        void* winMgr;

        virtual void* GetInfo() override;
        virtual Object* UnkFunc(char unk) override;
        virtual void CompUnkFunc();

        Component();
    };
}