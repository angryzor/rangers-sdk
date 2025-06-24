#pragma once

#ifdef SYNCHRONIZE
#undef SYNCHRONIZE
#endif

#include <ucsl/resources/asm/v103-rangers.h>

namespace hh::anim {
    using ucsl::resources::animation_state_machine::v103_rangers::ClipData;
    using ucsl::resources::animation_state_machine::v103_rangers::TransitionEasingType;
    using ucsl::resources::animation_state_machine::v103_rangers::TransitionType;
    using ucsl::resources::animation_state_machine::v103_rangers::TransitionData;
    using ucsl::resources::animation_state_machine::v103_rangers::StateType;
    using ucsl::resources::animation_state_machine::v103_rangers::StateData;
    using ucsl::resources::animation_state_machine::v103_rangers::BlendNodeType;
    using ucsl::resources::animation_state_machine::v103_rangers::BlendNodeData;
    using ucsl::resources::animation_state_machine::v103_rangers::TransitionArrayData;
    using ucsl::resources::animation_state_machine::v103_rangers::EventData;
    using ucsl::resources::animation_state_machine::v103_rangers::LayerData;
    using ucsl::resources::animation_state_machine::v103_rangers::BlendMaskData;
    using ucsl::resources::animation_state_machine::v103_rangers::TriggerType;
    using ucsl::resources::animation_state_machine::v103_rangers::TriggerData;
    using ucsl::resources::animation_state_machine::v103_rangers::BlendSpaceData;
    UCSL_NEWTYPE_STRUCT_SIMPLE(AsmData, ucsl::resources::animation_state_machine::v103_rangers::AsmData);

    class EventArray {
    public:
        csl::ut::StringMap<EventData*> eventsByName;

        EventData* GetEventData(const char* name);
    };

    // A map of state id -> TransitionData
    class TransitionArray : public csl::ut::PointerMap<size_t, TransitionData> {
    public:
        const TransitionData& GetTransitionData(int stateId) const;
    };

    class ResAnimator : public fnd::ManagedResource {
    public:
        AsmData* binaryData;
        void* unk2;
        csl::ut::StringMap<int> stateIdsByName;
        csl::ut::StringMap<int> variableIdsByName;
        csl::ut::MoveArray<EventArray> eventArrays;
        csl::ut::MoveArray<TransitionArray> transitionArrays;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAnimator)

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;
        virtual void Reload(void* data, size_t size) override;

        void LoadBinaryImage(AsmData* binaryData);

        int GetStateId(const char* stateName);
        int GetVariableId(const char* variableName);
        int GetLayerId(const char* layerName);
        int GetTriggerId(const char* triggerName);
    };
}
