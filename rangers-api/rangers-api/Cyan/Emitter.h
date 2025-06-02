#pragma once

namespace Cyan {
    class Emitter : public System::Job {
    public:
        class FSMEmitter : public System::FSM {
        public:
            FSMEmitter();
        };

        class WaitingState : public System::FSMState {
        public:
            WaitingState();

            virtual ~WaitingState();
            virtual void OnUpdate(System::FSMContext* context) override;
        };

        class AliveState : public System::FSMState {
        public:
            unsigned short unk1;

            AliveState();

            virtual ~AliveState();
            virtual void OnEnter(System::FSMContext* context) override;
            virtual void OnUpdate(System::FSMContext* context) override;
            virtual void OnExit(System::FSMContext* context) override;
            virtual void UnkFunc1();
        };

        class DeadState : public System::FSMState {
        public:
            DeadState();

            virtual ~DeadState();
            virtual void OnEnter(System::FSMContext* context) override;
        };

        uint32_t dword28;
        const Resource::EmitterParam* param;
        EffectImpl* effect;
        uint64_t qword40;
        uint64_t qword48;
        uint64_t qword50;
        uint64_t qword58;
        uint32_t dword60;
        uint8_t gap64[764];
        System::Random random;
        uint64_t pad0;
        uint64_t qword370;
        uint64_t pad1;
        uint64_t qword380;
        uint64_t qword388;
        uint64_t qword390;
        uint64_t qword398;
        uint64_t qword3A0;
        uint64_t qword3A8;
        uint64_t qword3B0;
        uint64_t qword3B8;
        csl::math::Vector4 csl__math__vector43C0;
        uint32_t dword3D0;
        uint8_t gap3D4[160];
        uint32_t dword474;
        uint64_t qword478;
        uint64_t qword480;
        uint64_t qword488;
        uint64_t qword490;
        uint64_t qword498;
        uint64_t qword4A0;
        uint64_t qword4A8;
        uint64_t qword4B0;
        uint8_t gap4B8[176];
        uint64_t qword568;
        uint64_t qword570;
        uint64_t qword578;
        uint64_t qword580;
        uint64_t qword588;
        uint32_t dword590;
        uint64_t qword598;
        uint8_t gap5A0[160];
        uint64_t qword640;
        uint64_t qword648;
        uint64_t qword650;
        uint32_t dword658;
        uint8_t gap65C[12];
        FSMEmitter fsm;
        uint64_t qword688;
        WaitingState waitingState;
        AliveState aliveState;
        DeadState deadState;
        uint8_t gap6C8[368];
        uint64_t qword838;
        uint64_t qword840;
        uint8_t gap848[576];
        uint8_t byteA88;
        uint8_t gapA89[127];
        uint64_t qwordB08;
        uint64_t qwordB10;
        uint64_t qwordB18;
        uint8_t gapB20[2304];
        uint8_t byte1420;
        uint8_t gap1421[127];
        uint64_t qword14A0;
        uint64_t qword14A8;
        uint64_t qword14B0;
        uint32_t dword14B8;
        uint64_t qword14C0;
        uint8_t byte14C8;
        uint8_t gap14C9[127];
        uint64_t qword1548;
        uint64_t qword1550;
        uint8_t byte1558;
        uint8_t gap1559[127];
        uint64_t qword15D8;
        uint64_t qword15E0;
        uint8_t gap15E8[1360];
        uint64_t qword1B38;
        uint64_t qword1B40;
        uint64_t qword1B48;
        csl::math::Vector3 m1281B50;
        csl::math::Vector3 oword1B60;
        csl::math::Vector3 oword1B70;
        csl::math::Vector3 oword1B80;
        csl::math::Vector3 oword1B90;
        csl::math::Vector3 oword1BA0;
        csl::math::Vector3 oword1BB0;

        Emitter(Effect* effect, const Resource::EmitterParam* param);

        virtual uint64_t UnkFunc1(void* unkParam1) override;
        virtual uint64_t UnkFunc2(float unkParam1) override;
        virtual uint64_t UnkFunc3(void* unkParam1) override;
        virtual void UnkFunc4(void* unkParam1);
        virtual void UnkFunc5(const Resource::EmitterParam* param);
        virtual void UnkFunc6(void* unkParam1);
        virtual void UnkFunc7(unsigned int unkParam1);
        virtual void UnkFunc8();
        virtual void UnkFunc9(void* unkParam1);
        virtual void InitEmitter(bool unkParam1);
        virtual void ProcessEmitter(float time);
        virtual void UpdateEmitter(float time);
        virtual void EmitElements(float time);
        virtual void EmitElements2(float time);
    };
}
