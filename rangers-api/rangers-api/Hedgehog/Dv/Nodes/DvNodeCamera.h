#pragma once

namespace hh::dv{
    class DvNodeCamera : public DvNodeBase {
    public:
        struct Description : DvNodeBase::Description {
            int flags;
            int frameProgressionCount;
            int captionCount;
            int field0c;
        };

        struct CameraData {
            csl::math::Vector3 position;
            csl::math::Vector3 target;
            float unk0;
            float unk1;
            float unk2;
            float unk3;
            hh::gfnd::ViewportData::FovProjectionParameters fovProjectionParams;
        };

        Description binaryData;
        hh::game::CameraComponent* camComponent;
        int unk3;
        int unk4;
        CameraData data;
        csl::math::Vector4 unk5;
        csl::math::Vector4 unk6;
        float nearClip;
        float farClip;
        int64_t unk7;
        csl::math::Vector3 unk8;
        int unk9;
        int unk10;
        int64_t unk11;

        virtual void Setup(DvNodeBase::Description& description) override;
        virtual void Start() override;
        virtual void Update(int currentFrame) override;
        virtual void PostStepUpdate(int currentFrame) override;
        virtual int GetUpdateTiming() override;

        DV_NODE_DECLARATION_BASE(DvNodeCamera)
    };
}
