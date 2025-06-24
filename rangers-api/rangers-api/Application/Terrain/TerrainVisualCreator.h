#pragma once

namespace app::trr {
    class TerrainVisualCreator : public hh::fnd::ReferencedObject {
    public:
        struct State {
            class Idle : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateModelInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainModelInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                csl::ut::MoveArray<void*> resources;
                unsigned int currentResourceIndex;

                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreatePointcloudModelInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateGrassModelInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainModel : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateModel : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainDensityInstance : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainDensityPointcloud : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class InitTerrainDensityCollision : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class CreateTerrainDensityCollision : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class EndUpdateTerrainDensity : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };

            class Finish : public hh::ut::StateBase<TerrainVisualCreator> {
            public:
                virtual void Enter(TerrainVisualCreator& context, int previousState) override;
                virtual bool Step(TerrainVisualCreator& context, float deltaTime) override;
            };
        };

        typedef void UnkCB(hh::game::GameObject* gameObject, void* unkParam1);

        TerrainVisualObject* object;
        hh::ut::HsmBase hh__ut__hsmbase20;
        hh::fnd::Reference<hh::ut::HsmBase> phh__ut__hsmbase90;
        TerrainVisualResourceBinder* resourceBinder;
        UnkCB* cb1;
        hh::gfnd::ResTexture* noGITexture;
        hh::gfnd::ResTexture* noGIOcclusionTexture;
        uint64_t qwordB8;
        uint64_t qwordC0;
        uint64_t qwordC8;
        uint64_t qwordD0;
        uint64_t qwordD8;
        uint64_t qwordE0;
        uint64_t qwordE8;
        csl::fnd::IAllocator* qwordF0;

        CREATE_FUNC(TerrainVisualCreator, TerrainVisualObject* object, TerrainVisualResourceBinder* resourceBinder, UnkCB* cb1Param);
    };
}
