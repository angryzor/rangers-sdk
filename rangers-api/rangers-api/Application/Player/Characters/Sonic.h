#pragma once

namespace app::player {
    class Sonic : public Player {
    public:
        static constexpr size_t stateDescCount = 211;
        static const GOCPlayerHsm::StateDescRef stateDescs[stateDescCount];

        GAMEOBJECT_CLASS_DECLARATION(Sonic)
    };
}
