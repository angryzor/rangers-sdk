#pragma once

namespace app::player {
    class MsgAddNotifyPreDeadListener : public fnd::AppMessage<MsgAddNotifyPreDeadListener> {
    public:
        MsgAddNotifyPreDeadListener() : fnd::AppMessage<MsgAddNotifyPreDeadListener>{ hh::fnd::MessageID::ADD_NOTIFY_PRE_DEAD_LISTENER } {}
    };

    class MsgGetHomingTargetInfo : public fnd::AppMessage<MsgGetHomingTargetInfo> {
    public:
        HomingTargetInfo homingTargetInfo{};

        MsgGetHomingTargetInfo() : fnd::AppMessage<MsgGetHomingTargetInfo>{ hh::fnd::MessageID::GET_HOMING_TARGET_INFO } {}
    };

    class MsgDead : public fnd::AppMessage<MsgDead> {
    public:
        uint32_t unk1{};
        float unk2{ -1.0f };
        short unk3{ -1 };

        MsgDead() : fnd::AppMessage<MsgDead>{ hh::fnd::MessageID::DEAD } {}
    };
}