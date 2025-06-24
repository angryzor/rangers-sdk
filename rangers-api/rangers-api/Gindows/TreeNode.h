#pragma once

namespace gindows{
    class TreeNode : public Object {
    public:
        struct UnkStr0 {
        public:
            TreeNode* self;
            csl::ut::MoveArray<void*> unk1;
        };

        struct UnkStr1 {
        public:
            char byte0;
            char gap1[15];
            int64_t qword10;
            int64_t qword18;
            char byte20;
            char gap21[15];
            int64_t qword30;
            int64_t qword38;
            int dword40;
        };

        int64_t qword0;
        int dword8;
        int64_t qword10;
        int64_t qword18;
        int dword20;
        UnkStr1 gindows__control__unkstr128;
        UnkStr0 gap78;
        char byteA0;
        int dwordA4;
        int64_t qwordA8;
        csl::fnd::IAllocator* allocator;

        virtual void* GetInfo() override;
        virtual Object* UnkFunc(char unk) override;

        TreeNode();
    };
}