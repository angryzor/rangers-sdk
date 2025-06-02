#pragma once

namespace gindows{
    class Object : public csl::ut::NonCopyable {
    public:
        virtual void* GetInfo();
        virtual Object* UnkFunc(char unk);

        Object();
    };
}