#pragma once

namespace app{
    class PerceivePartsListener{
    public:
        virtual uint64_t PPL_UnkFunc0() {}
    };

    class BossBaseContext : public app_cmn::fsm::GOCHsmContext, public PerceivePartsListener, public TargetPositionHelperListener, public game::HealthListener {
    public:
        struct CameraUnk{
            app_cmn::camera::CameraController* camera;
            int unk0;
            int unk1;
        };

        enum class Flags : int64_t{
            UNK0 = 0x8,
            CAMERA_TIMER_ACTIVE0 = 0x14,
            CAMERA_TIMER_ACTIVE1 = 0x15,
            VISIBILITY0 = 0x1D,
            VISIBILITY1 = 0x1E,
            BOSS_EVENT = 0x21
        };

        app_cmn::rfl::GOCRflParameter* gocRfl;
        GOCTargetPositionHelper* gocTargetPositionHelper;
        fnd::HFrameContainer* hFrameContainer;
        gfx::MultiNodeContainer* multiNodeContainer;
        physics::ColliderContainer* colliderContainer;
        csl::ut::MoveArray<int64_t> qword60;
        csl::ut::MoveArray<int64_t> qword80;
        csl::ut::MoveArray<int64_t> qwordA0;
        csl::ut::MoveArray<int64_t> qwordC0;
        csl::ut::MoveArray<int64_t> qwordE0;
        csl::ut::MoveArray<int64_t> qword100;
        csl::ut::MoveArray<CameraUnk> cameras;
        heur::rfl::BossLockOnCameraParam cameraParams;
        float bossEventTime;
        float bossEventLength;
        float bossEventRelated1;
        float bossEventRelated2;
        float cameraEventTimeRemaining;
        float cameraEventTimeElapsed;
        csl::math::Transform startObjectBossTransform;
        float dword200;
        csl::math::Vector3 lastHitPosition;
        csl::math::Vector4 csl__math__vector4220;
        csl::math::Vector4 relatedToLastHit;
        csl::math::Vector4 qword240;
        csl::math::Vector4 qword250;
        app_cmn::camera::CameraController* currentCamera;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> qword268; //giganto has HeroSagePoint here
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> qword288;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> qword2A8;
        csl::ut::MoveArray<int64_t> qword2C8;
        csl::ut::MoveArray<hh::fnd::Handle<hh::game::GameObject>> qword2E8; //giganto has ObjBossClosedArea here
        csl::ut::MoveArray<gfx::ModelAnimationPlayer*> modelAnimationPlayers;
        csl::ut::Bitset<Flags> flags;
        int currentPhase; 
        int dword334; 
        int dword338;
        csl::ut::MoveArray<int64_t> qword340;
        csl::ut::MoveArray<int64_t> states;
        hh::fnd::WorldPosition hh__fnd__worldposition380;
        int16_t word3A0; //prolly flags
        csl::ut::MoveArray<int64_t> qword3A8;
        
        virtual uint64_t PPL_UnkFunc0() override;
        virtual int8_t TPHL_UnkFunc0() override { return 0; }
        virtual void DamageDealt(MsgDamage& message, int damage, bool stunned, bool staggered) override;

        virtual void Update(hh::fnd::UpdatingPhase phase, hh::fnd::SUpdateInfo& updateInfo);
        virtual void SetGameObject(hh::game::GameManager* gameManager, hh::game::GameObject* gameObject);
        virtual void SetVisibility(bool visible, char a3);
        virtual bool GetUnkFlag0();
        virtual void SetUnkFlag0(bool enabled);
        virtual int64_t BBCtx_UnkFunc5() { return 0; }
        virtual bool SetCurrentState(int stateIdx) { return 0; } //not sure
        virtual bool ExecuteState(int stateIdx);
        virtual int64_t SetCurrentPhase(int currentPhase);
        virtual int64_t EndFight(char a2, bool shouldClearIsland); //a2 is related to clearisland msg
        virtual int64_t StartBossEvent();
        virtual int64_t EndBossEvent();
        virtual void KillBoss();
        virtual int64_t BBCtx_UnkFunc13();
        virtual void HandleDamage(app::MsgDamage& msg); //unsure
        virtual const char* GetBossStateName(int stateIdx);

        void AddCameraController(app_cmn::camera::CameraController* cam, int unk);
        void AddModelAnimationPlayer(hh::gfx::GOCVisualModel* gocVisualModel);
        app_cmn::fsm::GOCHsm2* GetGOCHsm2();
        app_cmn::rfl::GOCRflParameter* GetGOCRflParameter();

        BossBaseContext(csl::fnd::IAllocator* allocator);
    };
}