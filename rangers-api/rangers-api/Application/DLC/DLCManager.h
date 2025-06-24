#pragma once

namespace app::dlc {
    enum class DLCType : unsigned char {
        KOCOTOY = 3,
    };

    class DLCManagerSteam {
    public:
        bool IsDLCAvailable(DLCType dlcType);
    };

    bool IsDLCAvailable(hh::game::GameManager* gameManager, DLCType dlcType);
}
