#pragma once

namespace app::physics {
    class GOCMoveSphereColliderQuery : public GOCColliderQuery {
    public:
        csl::math::Vector3 unk201;
        csl::math::Vector3 unk202;
        uint32_t unk203;
        uint8_t unk204;

        GOCMoveSphereColliderQuery(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc101(void* unkParam1, void* unkParam2) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCMoveSphereColliderQuery);
    };
}
