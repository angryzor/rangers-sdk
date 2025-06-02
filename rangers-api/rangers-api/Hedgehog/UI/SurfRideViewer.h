#pragma once

namespace hh::ui {
    class SurfRideViewer : public hh::dbg::RemoteProcess {
    public:
        int64_t qword40;
        int64_t qword48;
        int64_t qword50;
        int64_t qword58;
        int64_t qword60;
        int64_t qword68;
        int64_t qword70;
        csl::fnd::IAllocator* allocator0;

        REMOTE_PROCESS_CLASS_DECLARATION(SurfRideViewer);
    };
}
