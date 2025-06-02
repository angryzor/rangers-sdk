#pragma once

namespace Cyan {
    class AnimCtrl {
        struct CurveStatus {

        };

        void Update(float time);
        unsigned int GetValues(float* values, int count) const;
        float GetKeyValue(const CurveStatus* curveStatus, int key);
    };
}
