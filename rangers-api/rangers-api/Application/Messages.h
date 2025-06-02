#pragma once

namespace app {
    class MsgDamage : public fnd::AppMessage<MsgDamage> {
    public:
        uint32_t dword20;
        size_t qword28;
        uint32_t dword30;
        csl::math::Vector3 csl__math__vector440;
        csl::math::Vector3 csl__math__vector450;
        csl::math::Vector3 csl__math__vector460;
        float dword70;
        uint32_t dword74;
        csl::math::Vector3 csl__math__vector480;
        csl::math::Vector3 csl__math__vector490;
        csl::math::Vector3 csl__math__vector4A0;
        uint64_t qwordB0;
        uint64_t qwordB8;
        float qwordC0;
        uint32_t qwordC4;
        short wordC8;
        csl::math::Vector3 csl__math__vector4D0;
        csl::math::Vector3 csl__math__vector4E0;
        csl::math::Vector3 csl__math__vector4F0;
        csl::math::Quaternion csl__math__vector4100;
        uint32_t dword110;

        MsgDamage(unsigned int dword20Param, size_t qword28Param) : fnd::AppMessage<MsgDamage>{ hh::fnd::MessageID::DAMAGE } {}
    };

    class MsgGetCyloopPoint : public fnd::AppMessage<MsgGetCyloopPoint> {
    public:
        hh::fnd::Handle<hh::game::GOComponent> unk1{};
        csl::math::Vector3 position{ 0.0f, 0.0f, 0.0f };
        csl::math::Vector3 normal{ 0.0f, 0.0f, 0.0f };
        float radius{};
        uint32_t unk2{};
        uint32_t unk3{};
        uint8_t unk4{};

        MsgGetCyloopPoint() : fnd::AppMessage<MsgGetCyloopPoint>{ hh::fnd::MessageID::GET_CYLOOP_POINT } {}
    };

    class MsgLossRing : public fnd::AppMessage<MsgLossRing> {
    public:
        enum class Type : unsigned int {
            NORMAL,
            TRACKER_TENTACLE,
            TRACKER_BLACKHOLE,
        };

        int amount{};
        bool all{};
        Type type{};
        int ringsLostAmount{};
        bool ringsLost{};

        MsgLossRing() : fnd::AppMessage<MsgLossRing>{ hh::fnd::MessageID::LOSS_RING } {}
    };
}
