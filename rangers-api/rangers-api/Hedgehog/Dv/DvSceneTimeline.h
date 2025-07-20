#pragma once

namespace hh::dv{
    class DvSceneTimeline : public fnd::ReferencedObject {
    public:
        struct DisableFrame {
        public:
            float start;
            float end;
        };

        int preCurrentFrame;
        int postCurrentFrame;
        int frameStart;
        int frameEnd;
        int currentCut;
        int currentPage;
        bool looping;
        csl::ut::MoveArray<float> cuts;
        csl::ut::MoveArray<DisableFrame> disableFrames;
        csl::ut::MoveArray<DvPage*> pages;
        int cameraFrameProgressionCount;
        float* cameraFrameProgression;
        float* cameraFrameProgressionSpeed;
        int ticksEnabled;

        void Clear();
        void SetFrameStartEnd(float start, float end);
        float GetSpeedByFrame(int currentFrame) const;
        void InitializeCuts(int64_t cutCount, float* cuts);
        void InitializeDisableFrames(int64_t disableFrameCount, DisableFrame* disableFrames);
        void InitializePages(void* pages, int64_t pageCount, hh::dv::DvSceneControl* dvsc);

        DvSceneTimeline(csl::fnd::IAllocator* allocator);
    };
}
