#pragma once

namespace gindows{
    class ContainerControl : public ScrollableControl {
    public:
        ContainerControl* containerControl798;

        virtual void* GetInfo() override;
        virtual Object* UnkFunc(char unk) override;

        ContainerControl();
    };
}