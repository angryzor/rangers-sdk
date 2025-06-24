#pragma once

namespace Cyan::System {
    class Random {
        unsigned int unk1;
        unsigned int unk2;
    public:
        Random();
        Random(unsigned int);
        float GetFloat();
    };
}
