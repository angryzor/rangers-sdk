#pragma once

namespace app::player{
    class EffectOverlay : public PlayerEffect{
    public:
        struct Timer{
            float target;
            float current;

            Timer();

            void Set(float time);
            void Reset();
            bool Add(float time);
        };

        hh::fnd::Handle<ObjOverlayEffect> obj;
        char flags;
        Timer timer;

        virtual unsigned long long GetNameHash() const override;
        virtual void Update(int64_t a2, float deltaTime) override;

        void SpawnEffect();

        EffectOverlay(csl::fnd::IAllocator* allocator);
    };
}
