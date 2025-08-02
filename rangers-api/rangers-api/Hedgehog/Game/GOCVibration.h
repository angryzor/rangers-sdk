#pragma once

namespace hh::game{
    class GOCVibration : public GOComponent {
    public:
        struct VibrationInfo {
            enum class VibrationType : unsigned int {
                AUTO,
                ONESHOT,
                LOOP,
                COUNT
            };

            int deviceId;
            const char* name;
            VibrationType type;
            float duration;
            bool timeAttentuation;
            hh::fnd::WorldPosition position;
            int id;
            float distance;
            bool distAttentuation;

            VibrationInfo();
        };

        struct VibrationObj : public hh::hid::VibrationContainer::VibrationObj{
            enum class Flags : unsigned char {
                TIME_ATTENTUATION,
                DISTANCE_ATTENTUATION,
                EASEOUT
            };

            csl::math::Matrix44 worldMatrix;
            float duration;
            float timer;
            float easeoutTime;
            float easeoutTimer;
            int id;
            float distance;
            csl::ut::Bitset<Flags> flags;
        };

        csl::ut::MoveArray<VibrationObj> vibrationObjs;  
        fnd::HFrame* hFrame;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) override;

        hh::hid::VibrationContainer::VibrationObj PlayVibration(const char* vibrationName, int deviceId);
        hh::hid::VibrationContainer::VibrationObj PlayVibration(VibrationInfo& info);
        void SetEaseoutTime(VibrationObj& obj, float easeoutTime);

        GOCOMPONENT_CLASS_DECLARATION(GOCVibration)
    };
}
