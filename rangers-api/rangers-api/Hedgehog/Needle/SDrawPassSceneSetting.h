#pragma once

namespace hh::needle {
    struct SDrawPassSceneSetting {
        uint32_t unk1;
        unsigned int unk1a; // participates in draw pass sort order
        unsigned int unk2; // participates in draw pass sort order
        uint32_t pad2a;
        CNameIDObject* name;
        uint32_t unk4;
        uint32_t someType; // see 0x1410D4AFF
        void* unk5;
        uint64_t unk6;
    };
}
