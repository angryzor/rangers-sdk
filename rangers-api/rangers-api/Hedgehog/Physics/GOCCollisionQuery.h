#pragma once

namespace hh::physics{
    class GOCCollisionQuery : public game::GOComponent {
    public:
        int64_t unk0; //not mentioned in ctor
        PhysicsWorldBullet* physWrldBullet;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCCollisionQuery)
    };
}
