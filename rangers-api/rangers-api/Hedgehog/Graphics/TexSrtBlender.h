#pragma once

namespace hh::gfx {
    struct TexSrtBlenderDesc {
        unsigned int animationCount;
    };

    typedef TexSrtDesc TexSrtControlDesc;

    class TexSrtBlenderBase : public fnd::ReferencedObject {
    public:
        virtual void Initialize(TexSrtBlenderDesc& description) = 0;
        virtual void Deinitialize() = 0;
        virtual void UnkFunc3() = 0;
        virtual TexSrtControlBase* CreateControl(const hh::gfx::TexSrtControlDesc& description) = 0;
        virtual void DestroyAllControl() = 0;
    };

    class GOCVisualModel;
    class TexSrtBlenderHH : public TexSrtBlenderBase {
    public:
        GOCVisualModel* model;
        csl::ut::MoveArray<fnd::Reference<TexSrtControlHH>> animations;
        uint64_t unk2;

        virtual void Initialize(TexSrtBlenderDesc& description) override;
        virtual void Deinitialize() override;
        virtual void UnkFunc3() override;
        virtual TexSrtControlBase* CreateControl(const hh::gfx::TexSrtControlDesc& description) override;
        virtual void DestroyAllControl() override;

        DEFAULT_CREATE_FUNC(TexSrtBlenderHH);
    };

    class TexSrtBlender : public TexSrtBlenderHH {
    public:
        DEFAULT_CREATE_FUNC(TexSrtBlender);
    };
}
