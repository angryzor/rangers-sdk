#pragma once

namespace app::dv{
    class DvElementTime : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            struct Time {
            public:
                int hour;
                int minute;
            };

            bool curveEnabled;
            Time time;
            Time finishTime;
            int unk5;
            int unk6;
            int unk7;
            int unk8;
            float curveData[32];
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementTime)
    };
}
