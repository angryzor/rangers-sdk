#pragma once
#include <ucsl/resources/aism/v0.h>

namespace app::game {
    UCSL_NEWTYPE_STRUCT(ConditionData, ucsl::resources::aism::v0::ConditionData, ConditionData);
    UCSL_NEWTYPE_STRUCT(ReactionData, ucsl::resources::aism::v0::ReactionData, ReactionData);
    UCSL_NEWTYPE_STRUCT(StateData, ucsl::resources::aism::v0::StateData, StateData);
    UCSL_NEWTYPE_STRUCT(TriggerData, ucsl::resources::aism::v0::TriggerData, TriggerData);

    class ResAIStateMachine : public hh::fnd::ManagedResource {
    public:
        virtual void Load(void* data, size_t size) {}
        virtual void Unload() {}

        unsigned int GetStateCount() const;
        StateData* GetState(unsigned int idx) const;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResAIStateMachine);
    };
}
