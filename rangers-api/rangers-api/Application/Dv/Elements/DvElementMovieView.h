#pragma once

namespace app::dv{
    class DvElementMovieView : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {};

        char unk0;

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementMovieView)
    };
}
