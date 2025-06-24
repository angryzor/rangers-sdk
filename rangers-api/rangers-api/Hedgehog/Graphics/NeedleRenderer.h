#pragma once

namespace hh::gfx {
    class NeedleRenderer : public needle::Renderable {
        fnd::Reference<gfnd::RenderableContainer> renderableContainer;
    public:
        DEFAULT_CREATE_FUNC(NeedleRenderer);

        virtual unsigned int UnkFunc1(void* unkParam1, void* unkParam2) override;
        virtual void Render(const RenderInfo& renderInfo) override;

        void AddRenderable(hh::gfnd::Renderable* renderable);
    };
}
