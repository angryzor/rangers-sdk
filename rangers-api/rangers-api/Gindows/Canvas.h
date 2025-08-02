#pragma once

namespace gindows{
    class Canvas{
    public:
        void* font;
        void* graphics;
        int64_t qword10;
        int oword18;
        int64_t qword28;
        void* backColor;
        void* foreColor;
        int64_t qword40;
        int64_t qword48;
        int dword50;
        int dword54;
        int dword58;
        int dword5C;
        char gap[160];

        Canvas();
    };
}
