#pragma once

namespace app::gfx{
    class GeometryInstance : public hh::fnd::RefByHandleObject, public hh::fnd::HFrameListener{
    public:
        typedef hh::fnd::HandleManager<GeometryInstance> HandleManager;

        hh::fnd::HFrame* hFrame;
        csl::math::Transform unk0;
        csl::math::Vector4 csl__math__vector460;
        csl::math::Vector4 csl__math__vector470;
        csl::math::Vector4 csl__math__vector480;
        csl::math::Matrix34 csl__math__matrix3490;
        float dwordD0;
        char flags;

        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;

        void SetFrame(hh::fnd::HFrame* hFrame);
        void SetUnkFlag();
        void SetTransform(csl::math::Transform& transform);

        GeometryInstance(csl::fnd::IAllocator* allocator, int64_t unk);
    };
}
