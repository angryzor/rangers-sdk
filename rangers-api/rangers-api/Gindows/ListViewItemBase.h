#pragma once

namespace gindows{
    class ListViewItemBase : public Object {
    public:
        int64_t unk0;
        ListViewSubItemCollection collection;

        virtual void* GetInfo() override;
        virtual Object* UnkFunc(char unk) override;

        ListViewItemBase();
    };
}