#pragma once

namespace app::dv{
    class DvElementWeather : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            save::WeatherBlockData::Type weatherType;
            float curveData[32];
        };

        bool weatherSet;

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementWeather)
    };
}
