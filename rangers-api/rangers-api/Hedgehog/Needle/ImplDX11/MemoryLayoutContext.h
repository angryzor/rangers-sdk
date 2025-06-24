#pragma once

namespace hh::needle::ImplDX11 {
    class DeviceObjectDX11;
    class MemoryLayoutContext {
    public:
        size_t size;
        uint64_t unk2;
        uint64_t unk3;
        uint64_t unk4;
        uint64_t unk5;
        uint64_t unk6;
        DeviceObjectDX11* deviceObject;
    };
}
