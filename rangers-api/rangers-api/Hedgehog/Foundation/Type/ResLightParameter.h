#pragma once

namespace hh::fnd {
    struct ResLightParameter {
        int lightType;
        float color[3];
        csl::math::Position lightPosition;
        float unk107;
        float unk108;
        float unk109;
        float unk110;
        float unk111;
        char unk112;
        uint32_t unk113;
        uint32_t unk114;
    };
}
