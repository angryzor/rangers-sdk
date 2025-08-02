#pragma once

namespace gindows{
    class String {
    public:
        char* value;
        char gap1[8];
        int64_t qword10;
        int64_t qword18;
        char byte20;
        char gap21[15];
        int64_t qword30;
        int64_t qword38;
        int dword40;

        int compare(const char* other) const;
        const char* c_str() const;

        String();
    };
}
