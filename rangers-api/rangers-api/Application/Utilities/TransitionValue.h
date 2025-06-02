#pragma once

namespace app::ut {
    template<typename T>
    class TransitionValue {
    public:
        typedef T InterpolationFunc(T* from, T* to, float ratio);

        struct Unk1 {
            void* qwordF8;
            void* qword100;
            void* qword108;
            void* qword110;
            uint64_t qword118;
            uint64_t qword120;
            InterpolationFunc* qword128;
            T dword130;
        };

        Unk1 unk1;

        virtual ~TransitionValue();
    };
}
