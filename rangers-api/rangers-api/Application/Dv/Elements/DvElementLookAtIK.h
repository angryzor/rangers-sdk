#pragma once

namespace app::dv{
    class DvElementLookAtIK : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            struct Object {
            public:
                enum class Type : unsigned int {
                    OFFSET,
                    OFFSET_GUID_TARGET,
                    CAMERA,
                    OFFSET_GUID_POSITION
                };

                Type type;
                char guid[16];
                csl::math::Position offset;
            };

            bool curveEnabled;
            Object obj;
            Object finishObj;
            float curveData[64];
        };

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) override;

        csl::math::Vector3 GetTargetPosition(hh::dv::DvStandardCharacter* dvChar);

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementLookAtIK)
    };
}
