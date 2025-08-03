#pragma once

namespace app{
    class ObjNpcSonic : 
        public ObjNpcBase, 
        public game::ContactListener, 
        public hh::game::GameStepListener 
    {
    public:
        hh::gfx::GOCVisualModel* gocVisualMdl;
        hh::physics::GOCCapsuleCollider* gocCapsuleColl;
        hh::physics::GOCSphereCollider* gocSphereColl;
        bool hasEventName;
        gfx::ModelAnimationPlayer* mdlAnimPlayer;

        virtual bool ProcessMessage(hh::fnd::Message& message) override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void RemoveCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;

        virtual void OnContact() override;
        virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        GAMEOBJECT_CLASS_DECLARATION(ObjNpcSonic)
    };
}
