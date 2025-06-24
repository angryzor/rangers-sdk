#pragma once

namespace app::player {
    class Amy : public Player {
    public:
        static constexpr size_t stateDescCount = 217;
        static const GOCPlayerHsm::StateDescRef stateDescs[stateDescCount];

        GAMEOBJECT_CLASS_DECLARATION(Amy)
    };
}
