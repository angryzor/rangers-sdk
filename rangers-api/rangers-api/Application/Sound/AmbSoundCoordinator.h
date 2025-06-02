#pragma once

namespace app::snd {
    class AmbSoundCoordinator : public hh::game::GameObject {
    public:
        uint64_t unk1;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> emitters;
        uint64_t unk3;
        csl::math::Matrix34 unk4;
        uint64_t unk5;
        uint64_t unk6;

		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        GAMEOBJECT_CLASS_DECLARATION(AmbSoundCoordinator);
    };
}