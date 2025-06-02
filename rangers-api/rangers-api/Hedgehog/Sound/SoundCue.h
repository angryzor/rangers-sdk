#pragma once

namespace hh::snd {
    class SoundCue {};
    class SoundCueCri : public SoundCue {
    public:
        struct PoolParam {

        };

        struct CdataTag {
            int cueId;
            void* cueSheet;
            float minDistance;
            float maxDistance;
            unsigned short numBlocks;
            bool isInfinite;
            bool isStreaming;
        };
    };
}