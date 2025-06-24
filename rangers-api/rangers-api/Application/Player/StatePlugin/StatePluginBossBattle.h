#pragma once

namespace app::player {
    class StatePluginBossBattle : public PlayerStatePlugin {
    public:
        uint32_t dword28;
        uint64_t qword30;
        uint64_t qword38;
        hh::eff::EffectHandle hh__eff__effecthandle40;
        uint8_t byte50;
        csl::math::Vector3 csl__math__vector360;
        csl::math::Vector3 csl__math__vector370;
        csl::math::Vector3 csl__math__vector380;
        csl::math::Vector3 csl__math__vector390;
        float floatA0;
        float floatA4;
        float floatA8;
        float floatAC;
        float floatB0;
        uint32_t qwordB4;
        uint32_t qwordB8;
        uint32_t dwordBC;
        uint8_t byteC0;

        DEFAULT_CREATE_FUNC(StatePluginBossBattle);
    };
}
