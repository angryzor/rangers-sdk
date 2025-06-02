#pragma once

namespace app::player {
    class Knuckles : public Player {
    public:
        static constexpr size_t stateDescCount = 216;
        static const GOCPlayerHsm::StateDescRef stateDescs[stateDescCount];

        GAMEOBJECT_CLASS_DECLARATION(Knuckles)
    };
}
