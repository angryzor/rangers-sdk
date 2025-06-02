#pragma once

namespace app::dv{
    class DvElementTheEndCableObject : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            int unk0;
            int unk1;
            float curveData[1024];
        };

        hh::fnd::Reference<hh::game::GameObject> unkHandle;
        bool unk1;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void OnDataUpdated() override;
        virtual void OnDataDeleted() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementTheEndCableObject)
    };
}
