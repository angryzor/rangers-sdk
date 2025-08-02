#pragma once

namespace app::gfx{
    class GOCVisualGeometryInstance : public hh::game::GOComponent{
    public:
        struct Description{
            hh::gfx::ResModel* resource;
            hh::fnd::HFrame* frame;
            int64_t unk0;
            int64_t unk1;
            csl::ut::InplaceMoveArray<int64_t, 8> unk2;
            csl::math::Transform unk3;
            char unk4;
            csl::ut::MoveArray32<int64_t> unk5;
            float unk6;
        };

        hh::gfx::ResModel* resource;
        hh::fnd::HFrame* hFrame;
        int64_t unk0;
        int64_t unk1;
        csl::ut::InplaceMoveArray<int64_t, 8> unk2;
        csl::math::Transform unk3;
        char unk4;
        csl::ut::MoveArray32<int64_t> unk5;
        float unk6;
        int unk7;
        int unk8;
        int unk9;
        hh::fnd::Handle<GeometryInstance> geometryInstance;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(Description& desc);

        GOCOMPONENT_CLASS_DECLARATION(GOCVisualGeometryInstance)
    };
}
