#pragma once

#define REMOTE_PROCESS_CLASS_DECLARATION(ClassName)public:\
		static ClassName* Create(csl::fnd::IAllocator* allocator);
        static const hh::dbg::ViewerContextClass* GetClass();

namespace hh::dbg {
    class RemoteProcess {
    public:
        csl::fnd::IAllocator* allocator;
        int64_t qword8;
        char byte10;
        int dword14;
        const char* name;
        int dword20;
        int64_t qword28;
        int dword30;
        char byte34;

        virtual void UnkFunc0(){}
        virtual void UnkFunc1(){}

        RemoteProcess(csl::fnd::IAllocator* allocator, const char* name);
    };
}
