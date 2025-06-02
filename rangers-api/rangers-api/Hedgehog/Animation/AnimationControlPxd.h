#pragma once

namespace hh::anim {
    class AnimationControlPxd : public AnimationControl, public fnd::ReloaderListener {
    public:
        bool looping;
        float localTime;
        float playbackSpeed;
        float startPadding;
        float endPadding;
        int cyclesLeft;
        float weight;
        float unk107;
        csl::ut::MoveArray<void*> unk108;
        uint64_t unk109;

        DEFAULT_CREATE_FUNC(AnimationControlPxd);
        virtual void Update(float time) override;
        virtual void SetWeight(float weight) override;
        virtual float GetWeight() const override;
        virtual void SetLocalTime(float time) override;
        virtual float GetLocalTime() const override;
        virtual void UnkFunc6() override;
        virtual void SetPlaybackSpeed(float speed) override;
        virtual float GetPlaybackSpeed() const override;
        virtual void SetStartTime(float time) override;
        virtual float GetStartTime() const override;
        virtual void SetEndTime(float time) override;
        virtual float GetEndTime() const override;
        virtual void UnkFunc14(uint8_t* unkParam1) override;
        virtual void UnkFunc15(float unkParam1) override;
        virtual bool UnkFunc16() const override;
        virtual bool IsPlaying() const override;
        virtual void Play(bool enabled) override;
        virtual void PostResourceReloadCallback(fnd::ManagedResource* resource) override;
    };
}
