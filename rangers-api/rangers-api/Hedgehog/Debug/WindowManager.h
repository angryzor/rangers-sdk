#pragma once

namespace hh::dbg {
    class WindowManager : public fnd::BaseObject {
    public:
        gindows::Control* control;
        gindows::Form* form;

        inline WindowManager(csl::fnd::IAllocator* allocator) : fnd::BaseObject{ allocator } { }

        void* WM_CreateWindow(const char* windowName);

        static WindowManager* instance;
    };
}
