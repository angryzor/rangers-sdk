#pragma once

namespace gindows{
    class Button;

    class ScrollBar : public Control {
    public:
        csl::ut::MoveArray<void*> qword738;
        Button* decrementButton;
        Button* incrementButton;
        int64_t qword768;
        int dword770;
        int dword774;
        int64_t qword778;
        int8_t byte780;
        int qword784;

        virtual char ContUnkFunc18(void* unk) override;
        virtual char ContUnkFunc19(void* unk) override;
        virtual void* ContUnkFunc20() override; // something with qword320
        virtual void* ContUnkFunc21() override; // something with qword360
        virtual void* ContUnkFunc47() override;
        virtual void* ScrollBarUnkFunc0();
        virtual void* ScrollBarUnkFunc1();
        virtual void* ScrollBarUnkFunc2();
        virtual void SetValue(int& value);

        void AddValue(int value);
        void ClickDecrementButton();
        void ClickIncrementButton();

        ScrollBar();
    };
}
