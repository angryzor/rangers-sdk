#pragma once

namespace app{
    class BossGiantContext : public BossBaseContext {
    public:
        int x;

        virtual uint64_t PPL_UnkFunc0() override;
        virtual int8_t TPHL_UnkFunc0() override { return 0; }
        virtual void PreDealDamage(MsgDamage& message, int damageIn, int& damageOut) override;
        virtual void DamageDealt(MsgDamage& message, int damage, bool stunned, bool staggered) override;

        virtual void Update(hh::fnd::UpdatingPhase phase, hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void SetGameObject(hh::game::GameManager* gameManager, hh::game::GameObject* gameObject) override;
        virtual void SetVisibility(bool visible, char a3) override;
        virtual int64_t BBCtx_UnkFunc5() override;
        virtual bool SetCurrentState(int stateIdx) override;
        virtual bool ExecuteState(int stateIdx) override;
        virtual int64_t SetCurrentPhase(int currentPhase) override;
        virtual int64_t EndFight(char a2, bool shouldClearIsland) override;
        virtual void KillBoss() override;
        virtual int64_t BBCtx_UnkFunc13() override;
        virtual const char* GetBossStateName(int stateIdx) override;
    };
}
