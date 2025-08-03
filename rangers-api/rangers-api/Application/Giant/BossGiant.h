#pragma once

namespace app{
    class BossGiant : public hh::game::GameObject, public game::ReactiveListener {
    public:
        BossGiantContext* context;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        virtual int64_t RL_UnkFunc0() override;

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(BossGiant)
    };
}
