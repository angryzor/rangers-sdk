#pragma once

namespace hh::game{
    class VibrationManager : public GameService, GameStepListener {
    public:
        csl::ut::MoveArray<GOCVibration*> gocVibrations;
        csl::ut::MoveArray<void*> unkArray0;
        csl::ut::PointerMap<int, csl::math::Vector3> vibrationDistances;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;
		virtual void PostStepCallback(game::GameManager* gameManager, const game::GameStepInfo& gameStepInfo) override;

        csl::math::Vector3* GetDistanceById(int id) const;
        void AddGOCVibration(GOCVibration* goc);
        void RemoveGOCVibration(GOCVibration* goc);

        GAMESERVICE_CLASS_DECLARATION(VibrationManager)
    };
}
