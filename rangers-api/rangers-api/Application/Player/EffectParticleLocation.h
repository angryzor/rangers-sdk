#pragma once

namespace app::player {
    class EffectParticleLocation : public PlayerEffect, public hh::animeff::ParticleLocatorListener {
    public:
        csl::ut::MoveArray<void*> unk201;
        short word70;
        csl::ut::MoveArray<void*> unk202;
        uint8_t flags;

        CREATE_FUNC(EffectParticleLocation, hh::game::GameObject* playerObject, PlayerVisual* playerVisual);
        virtual uint64_t UnkFunc1() override;
        virtual void UnkFunc2() override;
        virtual void PreCreateParticle(hh::animeff::GOCParticleLocator* gocParticleLocator, PreCreateParticleInfo& preCreateParticleInfo) override;
    };
}
