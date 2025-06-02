#pragma once

namespace gindows{
    class ListViewSubItemCollection : public Object {
    public:
        int64_t qword0;
        int dword8;
        csl::ut::MoveArray<void*> unkArray;

        ListViewSubItemCollection();
    };
}