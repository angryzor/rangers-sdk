#pragma once

namespace app::dv{
    class DvElementSun : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            bool curveEnabled;
            csl::math::Position rotation;
            csl::math::Position finishRotation;
            float curveData[32];
        };

        hh::needle::FxAtmosphereParameter* fxAtmosphereParam;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementSun)
    };
}
