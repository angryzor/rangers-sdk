#pragma once

namespace gindows{
    class TreeNode;

    class TreeNodeCollection {
    public:
        TreeNode* self;
        csl::ut::MoveArray<void*> unk1;

        TreeNodeCollection(TreeNode* owner);
    };

    class TreeNode : public Object {
    public:
        int64_t qword0;
        int dword8;
        int64_t qword10;
        int64_t qword18;
        String name;
        int64_t dword40;
        TreeNodeCollection treeNodeCollection;
        char byteA0;
        int dwordA4;
        int64_t qwordA8;
        csl::fnd::IAllocator* allocator;

        virtual void* GetRuntimeTypeInfo() const override;

        TreeNode();
    };
}