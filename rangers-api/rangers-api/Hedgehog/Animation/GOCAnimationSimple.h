#pragma once

namespace hh::anim {
    enum class PlayPolicy : unsigned char {
        NORMAL,
        REPEAT,
    };

    struct GOCSimpleAnimationSpawner {
        csl::ut::VariableString resSkeleton;
        csl::ut::VariableString resAnimation;

        static const hh::fnd::RflTypeInfo typeInfo;
        static const hh::fnd::RflClass rflClass;
    private:
        static void Construct(GOCSimpleAnimationSpawner* pInstance, csl::fnd::IAllocator* pAllocator);
        static void Finish(GOCSimpleAnimationSpawner* pInstance);
        static void Clean(GOCSimpleAnimationSpawner* pInstance);
    };

    inline const hh::fnd::RflTypeInfo GOCSimpleAnimationSpawner::typeInfo{
        "GOCSimpleAnimationSpawner",
        "GOCSimpleAnimationSpawner",
        [](void* instance, csl::fnd::IAllocator* allocator) {
            auto* inst = static_cast<GOCSimpleAnimationSpawner*>(instance);
            new (&inst->resAnimation) csl::ut::VariableString{ allocator };
            new (&inst->resSkeleton) csl::ut::VariableString{ allocator };
            return instance;
        },
        [](void* instance) {},
        [](void* instance) {
            auto* inst = static_cast<GOCSimpleAnimationSpawner*>(instance);
            inst->resAnimation.~VariableString();
            inst->resSkeleton.~VariableString();
        },
        sizeof(GOCSimpleAnimationSpawner),
    };

    class GOCAnimationSimple;
    class GOCSimpleAnimationListener {
    public:
        virtual ~GOCSimpleAnimationListener() = default;
        virtual void AnimationAddedCallback(GOCAnimationSimple* gocAnimationSimple, const char* animationName) {}
        virtual void StateChangedCallback(GOCAnimationSimple* gocAnimationSimple) {}
        virtual void PostStepCallback(GOCAnimationSimple* gocAnimationSimple) {}
    };

    class GOCAnimationSimple : public GOCAnimationSingle {
    public:
        struct SimpleAnimationState {
            PlayPolicy playPolicy;
            uint8_t unk1;
            float speed;
            csl::ut::VariableString name;
            AnimationControl* animationControl;

            CREATE_FUNC(SimpleAnimationState, uint8_t unk1Param, char const* animationName, ResAnimation* resource, PlayPolicy playPolicy);
            bool IsPlaying() const;
            float GetLocalTime() const;
            void SetLocalTime(float time);
            float GetDuration() const;
            float GetSpeed() const;
            void SetSpeed(float speed);
            float GetWeight() const;
            void SetWeight(float weight);
            void ResetTime();
        };

        struct SetupInfo : GOCAnimationSingle::SetupInfo {
            unsigned int unkCount;
        };

        csl::ut::InplaceMoveArray<SimpleAnimationState, 1> animations;
        csl::ut::MoveArray<GOCSimpleAnimationListener*> listeners;
        csl::ut::StringMap<unsigned int> animationIndicesByName;
        csl::ut::InplaceMoveArray<uint32_t, 2> playingAnimations;
        csl::ut::MoveArray<void*> unk306;
        csl::ut::MoveArray<void*> unk307;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void LoadReflection(const LoadReflectionInfo& loadReflectionInfo) override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;
        virtual void UnkFunc3() override;
        virtual uint64_t UnkFunc4() override;

        void Setup(const SetupInfo& setupInfo);
        void Initialize();
        void IndexOf(const char* animationName);
        void Add(const char* animationName, ResAnimation* resource, PlayPolicy playPolicy);
        void Add(uint8_t unk1Param, const char* animationName, ResAnimation* resource, PlayPolicy playPolicy);
        bool IsFinished() const;
        void Play(const char* animationName, float weight, float localTime, float speed);
        void Play(const char* animationName);
        bool IsPlaying(const char* animationName) const;
        bool IsPlaying() const;
        void Stop();
        float GetLocalTime() const;
        void SetLocalTime(float time);
        float GetLocalTime(const char* animationName) const;
        bool SetLocalTime(const char* animationName, float time);
        float GetDuration(const char* animationName) const;
        float GetSpeed() const;
        void SetSpeed(float speed);
        float GetSpeed(const char* animationName) const;
        bool SetSpeed(const char* animationName, float speed);
        float GetWeight(const char* animationName) const;
        bool SetWeight(const char* animationName, float weight);
        bool IsCurrentAnimation(const char* animationName);
        void SetAnimation(const char* animationName);
        float GetFrame() const;
        void SetFrame(float frame);
        float GetEndFrame(const char* animationName) const;
        SimpleAnimationState* GetAnimationState(const char* animationName) const;
        bool IsExistingAnimation(const char* animationName) const;

        void AddListener(GOCSimpleAnimationListener* listener);
        void RemoveListener(GOCSimpleAnimationListener* listener);

        GOCOMPONENT_CLASS_DECLARATION(GOCAnimationSimple);
    
    private:
        void SetActiveAnimation(unsigned int index);
    };
}
