#pragma once

namespace app {
    class VolumeListener {
    public:
        virtual void VL_UnkFunc1(); // Enter, MsgTriggerEnter&
        virtual void VL_UnkFunc2();
        virtual void VL_UnkFunc3(); // Leave, MsgTriggerLeave&
    };

    class VolumeTrigger : public hh::physics::GOCColliderListener {
    public:
        hh::game::GameObject* gameObject;
        uint32_t unk2;
        bool unk3;
        hh::physics::GOCCollider* collider;
        hh::gfx::GOCVisualDebugDraw* debugVisual;
        csl::ut::MoveArray<VolumeListener*> listeners;
    
    protected:
        void Setup(hh::game::GameObject* object, const heur::rfl::VolumeTriggerSpawner& config);

    public:
        // CollisionFilter changes the collider type
        // 0 = category 25, unk4 0x001000 
        // 1 = category 27, unk4 0x010000 
        // 2 = category 29, unk4 0x018000 
        // 3 = category 29, unk4 0x158000 
        heur::rfl::VolumeTriggerSpawner config;
        uint8_t unk13;
    
        DEFAULT_CREATE_FUNC(VolumeTrigger)

        virtual void GOCCL_UnkFunc1(hh::physics::GOCCollider* collider) override;
        virtual void GOCCL_UnkFunc2(hh::physics::GOCCollider* collider) override;
        virtual void GOCCL_UnkFunc3(hh::physics::GOCCollider* collider) override;

        void Setup(hh::game::GameObject* object, const heur::rfl::VolumeTriggerSpawner& config, uint32_t unkParam1, bool unkParam2);
        void SetupDebugVisual();
        void UpdateConfig(const heur::rfl::VolumeTriggerSpawner& config);
        void UpdateDebugVisual(const heur::rfl::VolumeTriggerSpawner& config);
        void AddListener(VolumeListener* listener);
        void RemoveListener(VolumeListener* listener);

        void StartActiveObjectInEditor();
        void UpdateActiveObjectInEditor();
        void FinishActiveObjectInEditor();
    };
}
