#pragma once

namespace hh::physics {
    class GOCCapsuleCollider : public GOCCollider {
    public:
        struct SetupInfo : public GOCCollider::SetupInfo {
            float radius{};
            float halfHeight{};

            inline SetupInfo() : GOCCollider::SetupInfo(ColliShape::Type::CAPSULE) {}
        };

        float radius;
        float halfHeight;

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCCapsuleCollider);
    };
}
