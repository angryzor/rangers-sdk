#pragma once

namespace Cyan::System {
    class FSMContext {
    public:
    };

    class FSMState {
    public:
        unsigned int id;

        virtual void OnEnter(FSMContext* context);
        virtual void OnUpdate(FSMContext* context);
        virtual void OnExit(FSMContext* context);
    };

    class FSM {
    public:
        uint64_t unk1;
        uint64_t unk2;
        uint64_t unk3;

        FSM();
        virtual ~FSM();
        virtual void UnkFunc1() {}
    };
}
