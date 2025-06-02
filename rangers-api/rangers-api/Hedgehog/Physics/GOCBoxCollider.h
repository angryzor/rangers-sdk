#pragma once

namespace hh::physics {
    class GOCBoxCollider : public GOCCollider {
    public:
        struct SetupInfo : public GOCCollider::SetupInfo {
            csl::math::Vector3 dimensions;

            inline SetupInfo() : GOCCollider::SetupInfo(ColliShape::Type::BOX) {}
        };

        csl::math::Vector3 dimensions;

		virtual void* GetRuntimeTypeInfo() const override;
        virtual void GetShape(ColliShape& shape) const override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCBoxCollider);
    };
}
