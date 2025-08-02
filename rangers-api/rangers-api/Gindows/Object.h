#pragma once

namespace gindows{
    class Object : public csl::ut::NonCopyable {
    public:
        virtual void* GetRuntimeTypeInfo() const;
        virtual ~Object() = default;

        static void* operator new(unsigned long long size);

        Object();
    };
}