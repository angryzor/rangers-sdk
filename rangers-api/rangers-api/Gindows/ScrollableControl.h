#pragma once

namespace gindows{
    class ScrollableControl : public Control {
    public:
        struct SCUnkStr0 {
            csl::ut::MoveArray<void*> qword0;
            int64_t qword20;
            void* pint6428;
            void* pint6430;
        };

        csl::ut::MoveArray<void*> qword738;
        short word758;
        char byte75A;
        SCUnkStr0 scUnkStr0;

        virtual void GetDisplayLocation(int* value) override;
        virtual void GetPreferredClientSize(int* value) override;
        virtual void* ContUnkFunc20() override; // something with qword320
        virtual void* ContUnkFunc21() override; // something with qword320
        virtual void* ContUnkFunc38() override; // something with qword1E0
        virtual void* ContUnkFunc39() override; // something with qword200
        virtual void* ContUnkFunc40() override; // something with qword80
        virtual void* ScolContUnkFunc0(); // something ver2 with qword738;

        void AdjustFormScrollbars();

        ScrollableControl();
    };
}