#pragma once

namespace hh::physics{
    class GOCHeightFieldCollider : public GOCCollider {
    public:
        class Listener {
        public:
            virtual void HFCL_UnkFunc0() {}
            virtual void HFCL_UnkFunc1() {}
            virtual void HFCL_UnkFunc2() {}
            virtual void HFCL_UnkFunc3() {}
        };

        struct SetupInfo : public GOCCollider::SetupInfo {
            ResHeightField* resource;

            inline SetupInfo() : GOCCollider::SetupInfo(ColliShape::Type::HEIGHTFIELD) {}
        };

        fnd::Reference<ResHeightField> resource;
        csl::ut::MoveArray<Listener*> listeners;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(fnd::Message& msg) override;
		virtual bool fUnk5() override;
        virtual void GetShape(ColliShape& shape) const override;

        void AddListener(Listener* listener);
        void RemoveListener(Listener* listener);
        
        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCHeightFieldCollider)
    };
}
