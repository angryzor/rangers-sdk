#pragma once

namespace hh::dv{
    class DvDirectionalLightParamController : public DvParamController{
    public:
        char unk0;
        char unk0b;
        int unk1;
        short unk2;
        int unk3;
        int unk4;
        float unk5;
        float unk6;
        float unk7;
        float unk8;
        float unk9;
        float unk10;
        int64_t unk11;
        int64_t unk12;
        int64_t unk13;

        virtual void PreStepUpdate() override;

        virtual bool Load();
        virtual hh::gfx::RenderingComponent* GetRenderingComponent();
        virtual void* UnkFunc(int curFrame);
    };
}
