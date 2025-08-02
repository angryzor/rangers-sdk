#pragma once

namespace app::player {
    class StatePluginBoost : public PlayerStatePlugin, public app::evt::EventPlayerListener {
    public:
        static constexpr const char* name = "StatePluginBoost";
        void SetNitroMode();
        void SetBoostType(uint8_t type);
        void SetUnk1(uint8_t type);

        virtual void EPL_UnkFunc4() override;
        virtual void EPL_UnkFunc5() override;

        int unk0; //some handle perhaps?
        int unk1;
        int unk2;
        float boostCapacity;
        float boostAmount;
        int unk4;
        float unk5;
        float unk6;
        float unk7; //counter of some sort
        float unk8;
        float unk9; //counter of some sort
        int unk10;
        float infiniteBoostTimer;
        int64_t unk11[5];
        csl::ut::MoveArray<int64_t> unk12;
        csl::ut::MoveArray<int64_t> unk13;
        int flags;
    };
}
