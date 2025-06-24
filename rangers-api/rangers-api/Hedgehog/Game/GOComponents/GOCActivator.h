#pragma once

namespace hh::game {
    struct GOCActivatorSpawner {
        float m_range;
        float m_distance;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GOCActivatorSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GOCActivatorSpawner* pInstance);
        static void Clean(GOCActivatorSpawner* pInstance);
    };

    inline const hh::fnd::RflTypeInfo GOCActivatorSpawner::typeInfo{
        "GOCActivatorSpawner",
        "GOCActivatorSpawner",
        [](void* instance, csl::fnd::IAllocator* allocator) {
            auto* inst = static_cast<GOCActivatorSpawner*>(instance);
            inst->m_range = 0.0f;
            inst->m_distance = 0.0f;
            return instance;
        },
        [](void* instance) {},
        [](void* instance) {},
        sizeof(GOCActivatorSpawner),
    };

    class GOCActivator : public hh::game::GOComponent, public hh::fnd::HFrame::Listener {
    public:
        float range;
        float distance;
        bool unk101;
        csl::math::Vector3 position;
        float rangePlusDistanceSquared;
        bool enabled;

        struct RangeSpawningConfig {
            float m_distance;
            float m_range;
        };

        struct SetupInfo {
            RangeSpawningConfig rangeSpawningConfig;
            bool unk1;
        };

        GOCActivator(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void LoadReflection(const LoadReflectionInfo& loadReflectionInfo) override;
		virtual void OnGOCEvent(GOCEvent event, GameObject& ownerGameObject, void* data) override;
        virtual void HFrameUpdatedCallback(const fnd::HFrame* frame, bool unkParam) override;
        void Setup(const SetupInfo& setupInfo);

        GOCOMPONENT_CLASS_DECLARATION(GOCActivator)
    };
}
