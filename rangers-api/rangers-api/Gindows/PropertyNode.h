#pragma once

namespace gindows{
    class PropertyNode : public Object{
    public:
        int GetValue(const char* name, int* value);
        int SetName(const char* name);
    };
}
