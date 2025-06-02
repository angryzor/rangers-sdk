#pragma once

namespace app::game {
    class GOCGravity : public hh::game::GOComponent, public hh::fnd::HFrameListener {
    public:
        struct Unk1 {
            uint64_t qword0;
            uint16_t word8;
            uint64_t qword10;
            uint64_t qword18;
            uint64_t qword20;
            uint64_t qword28;
            uint64_t qword30;
            uint32_t dword38;
            csl::math::Vector3 csl__math__vector340;
            csl::math::Vector3 csl__math__vector350;
            uint32_t dword60;
            uint64_t qword68;

            Unk1();
        };

        struct SetupInfo {
            uint8_t unk1;
            float magnitude;
            uint64_t unk2;
            uint8_t unk3;
            csl::math::Vector3 direction;
        };

        csl::math::Vector3 direction;
        Unk1 unk1;
        uint64_t unk2;
        uint8_t unk3;

        GOCGravity(csl::fnd::IAllocator* allocator);

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;

        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCGravity);
    };
}
