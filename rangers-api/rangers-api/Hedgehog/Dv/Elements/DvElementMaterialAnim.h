#pragma once

namespace hh::dv{
    class DvElementMaterialAnim : public DvElementBase {
    public:
        struct Description : DvElementBase::Description {
        public:
            enum class Flags : unsigned int {
                UNK0,
                UNK1, // used in setup
            };

            csl::ut::Bitset<Flags> flags;
            char matAnimName[64];
            int unk1;
            float speed; // perhaps speed
            int unk3;
            int unk4;
        };

        Description binaryData;
        hh::fnd::ManagedResource* matAnimRes; // hasn't been reversed

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void SetData(void* data) override;

        DV_ELEMENT_DECLARATION_BASE(DvElementMaterialAnim)
    };
}
