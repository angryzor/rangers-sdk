#pragma once

namespace hh::needle {
    class SCRenderable : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCRenderable& sceneContext;
        public:
            csl::ut::MoveArray<intrusive_ptr<Renderable>> renderables[10];

            Impl(SCRenderable& sceneContext);

            void AddRenderable(intrusive_ptr<Renderable>& renderable, RenderTextureHandle::RenderStage renderStage);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCRenderable);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();

        void AddRenderable(intrusive_ptr<Renderable>& renderable, RenderTextureHandle::RenderStage renderStage);
        csl::ut::MoveArray<intrusive_ptr<Renderable>>& GetRenderables(RenderTextureHandle::RenderStage renderStage) const;
    };
}
