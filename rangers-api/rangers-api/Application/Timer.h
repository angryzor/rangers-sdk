#pragma once

namespace app{
    struct Timer{
        float target;
        float current;

        Timer();

        void Set(float time);
        void Reset();
        bool Add(float time);
        float GetTarget() const;
        float GetCurrent() const;
        bool IsActive() const;
    };
}
