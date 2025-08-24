#pragma once

namespace gindows{
    class ListViewItemBase : public Object {
    public:
        int64_t unk0;
        ListViewSubItemCollection collection;

        virtual void* GetRuntimeTypeInfo() const override;

        ListViewItemBase();
    };
}