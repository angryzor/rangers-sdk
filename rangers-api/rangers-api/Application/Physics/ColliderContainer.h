#pragma once

namespace app::physics{
    class ColliderContainer : public hh::fnd::ReferencedObject {
    public:
        struct Element{
            hh::fnd::Handle<hh::physics::GOCCollider> handle;
            int flags;
            int unk0;
        };

        csl::ut::MoveArray<Element> colliders;

        void GetCollidersBasedOnUnk(int unk, csl::ut::MoveArray<hh::physics::GOCCollider*>& value);

        ColliderContainer(csl::fnd::IAllocator* allocator);
    };
};
