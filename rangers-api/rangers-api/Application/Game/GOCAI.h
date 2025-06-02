#pragma once

namespace app::game {
    class GOCAI;
    class AIContext : public hh::fnd::ReferencedObject {
    public:
        GOCAI* gocAI;
    };

    struct ConditionArgumentValue {
        enum class Type : unsigned int {
            FIXED_BOOL,
            FIXED_INT,
            FIXED_FLOAT,
            RANDOM_BOOL,
            RANDOM_INT,
            RANDOM_FLOAT,
            ATTRIBUTE_BOOL,
            ATTRIBUTE_INT,
            ATTRIBUTE_FLOAT,
        };

        union Value {
            bool b;
            int i;
            float f;
        };

        Type type;
        unsigned int pad;
        Value value;
    };

    class ConditionArgument;
    struct ConditionArgumentSpec {
        typedef ConditionArgument* CreateFunc(csl::fnd::IAllocator* allocator, const ConditionData::ArgumentType& type, const char* propertyName);

        const char* name;
        unsigned int nameHash;
        CreateFunc* createFunc;

        ConditionArgumentSpec(const char* name, unsigned int nameHash, CreateFunc* createFunc);
    };

    class ConditionArgument : public hh::fnd::ReferencedObject {
    public:
        virtual ConditionArgumentValue GetValue(AIContext* context) const = 0;

        static ConditionArgumentSpec* conditionArgumentSpecs[14];
        static ConditionArgument* CreateAttribute(csl::fnd::IAllocator* allocator, const ConditionData::ArgumentType& type, unsigned int nameHash, const char* propertyName);

        static ConditionArgument* Create(csl::fnd::IAllocator* allocator, const ConditionData::ArgumentType& type, ConditionData::ArgumentValuePtr value);
    };

    template<typename T>
    class ConditionArgumentFixed : public ConditionArgument {
    public:
        ConditionArgumentValue value;

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentRandomBool : public ConditionArgument {
    public:
        ConditionArgumentValue value;

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentRandomInt : public ConditionArgument {
    public:
        ConditionArgumentValue value;

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentRandomFloat : public ConditionArgument {
    public:
        ConditionArgumentValue value;

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentStateTime : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentStateTime, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentFindTarget : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentFindTarget, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentDistanceToTarget : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentDistanceToTarget, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentInAttackRange : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentInAttackRange, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentTargetInTerritory : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentTargetInTerritory, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentInTerritory : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentInTerritory, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentAttackable : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentAttackable, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentIsAttacker : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentIsAttacker, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentAnyModeChangers : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentAnyModeChangers, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentAttacking : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentAttacking, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentPlayerAttacking : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentPlayerAttacking, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentPlayerDamage : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentPlayerDamage, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentHealthRatio : public ConditionArgument {
    public:
        CREATE_FUNC(ConditionArgumentHealthRatio, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class ConditionArgumentProperty : public ConditionArgument {
    public:
        ConditionData::ArgumentType type;
        unsigned int propertyNameHash;

        CREATE_FUNC(ConditionArgumentProperty, const ConditionData::ArgumentType& type, const char* propertyName);

        virtual ConditionArgumentValue GetValue(AIContext* context) const override;
    };

    class Condition : public hh::fnd::ReferencedObject {
    public:
        hh::fnd::Reference<ConditionArgument> lhs;
        hh::fnd::Reference<ConditionArgument> rhs;
        ConditionData::Operator op;

        CREATE_FUNC(Condition, ConditionData* conditionData);

        bool Test(AIContext* context) const;
    };

    class Reaction : public hh::fnd::ReferencedObject {
    public:
        ReactionData* reactionData;

        CREATE_FUNC(Reaction, ReactionData* reactionData);

        bool HasName(const char* name) const;
        const char* GetTargetState() const;
    };

    class Trigger : public hh::fnd::ReferencedObject {
    public:
        TriggerData* triggerData;
        csl::ut::MoveArray<hh::fnd::Reference<Condition>> conditions;

        CREATE_FUNC(Trigger, TriggerData* triggerData);

        bool TestConditions(AIContext* context, TriggerData::TriggerType triggerType);
    };

    class GOCAI : public hh::game::GOComponent {
    public:
        struct SetupInfo {
            ResAIStateMachine* resource;
            char initialState[64];
            int unk2;
            AIContext* context;
        };

        enum class Flag : unsigned char {
            ENABLED,
            CHANGING_STATE,
            TRANSITION,
            FIRST_TIME,
        };

        SetupInfo setupInfo;
        hh::fnd::Reference<hh::ut::StateManager> hsmStateManager;
        hh::ut::HsmBase hsm;
        int initialState;
        int nextState;
        csl::ut::Bitset<Flag> flags;
        csl::ut::InplaceMoveArray<void*, 1> unk160;
        csl::ut::InplaceMoveArray<Trigger*, 16> triggers;
        csl::ut::InplaceMoveArray<Reaction*, 4> reactions;
        csl::ut::MoveArray<hh::ut::StateDesc*> stateDescs;
        csl::ut::StringMap<unsigned int> stateIdsByName;
        AIContext* context;
        csl::ut::MoveArray<void*> unk2B0;
        uint32_t dword2D0;

        static hh::ut::StateDesc* aiStateDescs[19];

		virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo setupInfo);

        int GetStateIdByName(const char* name) const;
        int GetInitialBottomState(int state) const;
        bool ChangeState(const char* stateName);
        bool IsInState(int stateId) const;
        void TriggerReaction(const char* name, bool unkParam);
        void SetupTriggersAndReactions(int stateId, bool isBottomState);
        void SetEnabled(bool enabled);

        static hh::ut::StateDesc* CreateStateDesc(csl::fnd::IAllocator* allocator, const char* name, const char* type, int superState);

        GOCOMPONENT_CLASS_DECLARATION(GOCAI);
    };
}
