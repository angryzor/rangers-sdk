#pragma once

namespace hh::ui {
    class SurfRideViewerContextListener {
    public:
        virtual void SRVCL_UnkFunc0(void* unk){};
        virtual void SRVCL_UnkFunc1(){};
    };

    class SurfRideViewerWindow : public gindows::Form, SurfRideViewerContextListener {
    public:
        void* qword8B8;
        void* qword8C0;
        int64_t qword8C8;

        virtual void* GetInfo() override;
        virtual Object* UnkFunc(char unk) override;

        virtual void SRVCL_UnkFunc0(void* unk) override;
        virtual void SRVCL_UnkFunc1() override;

        SurfRideViewerWindow();
    };
}
