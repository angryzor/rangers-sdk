#pragma once

namespace gindows {
    class Form;

    class WindowManager : public hh::fnd::BaseObject {
    public:
        struct UnkStr0 {
        public:
            struct UnkStr4 {
            public:
                int dword0;
                int dword4;
                int dword8;
            };

            int64_t qword00;
            int64_t qword08;
            int64_t qword10;
            int64_t qword18;
            int64_t qword20;
            int64_t qword28;
            int64_t qword30;
            UnkStr4* qword38;
            int int40;
            char gap44[28];
            Form* form;

            void* UnkFunc0(Form* unk);
        };

        struct UnkStr1 {
        public:
            struct UnkStr2 {
            public:
                int64_t qword00;
                int64_t qword08;
                int64_t qword10;
                char gap18[1800];
                int64_t qword720;
                int64_t qword728;
                int64_t qword730;
                int64_t qword738; // sub_14116470 suggests that this is a csl::ut::movearray? not sure
                int64_t qword740;
                int64_t qword748;
                int64_t qword750;
                int64_t qword758;
                int dword760;
                int dword764;
                int dword768;
            };

            struct UnkStr3 {
            public:
            
            };

            int64_t qword00;
            int64_t qword08;
            int64_t qword10;
            int64_t qword18;
            int64_t qword20;
            int64_t qword28;
            int64_t qword30;
            int64_t qword38;
            int64_t qword40;
            int64_t qword48;
            int64_t qword50;
            int64_t qword58;
            int64_t qword60;
            UnkStr3* qword68;
            int64_t qword70;
            int64_t qword78;
            UnkStr2* qword80;
            char gap0[136];
            Form* qword110;
            Form* qword118;
            int64_t qword120;

            void* UnkFunc0(Form* unk);
        };

        UnkStr1* qword00;
        UnkStr0* qword08;
        void* qword10;
        void* qword18;

        UnkStr1::UnkStr2* GetUnkStr1UnkStr2();
        UnkStr1::UnkStr3* GetUnkStr1UnkStr3();

        static WindowManager* instance;
        static WindowManager* GetInstance();
    };
}