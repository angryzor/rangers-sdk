#pragma once

namespace Cyan {
    class Effect;
    class EffectHandle {
    public:
        int unk1;
        Effect* effect;
        EffectHandle();
        EffectHandle(const EffectHandle& other);

        const csl::math::Vector3& GetScale() const;
        const csl::ut::Color8& GetColor() const;
        uint8_t GetAlpha() const;

        void SetScale(const csl::math::Vector3& scale);
        void SetColor(const csl::ut::Color8& color);
        void SetAlpha(uint8_t alpha);
    };

    class Effect {
    public:
        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual void Pause() = 0;
        virtual void Resume() = 0;
        virtual bool IsPaused() const = 0;
        virtual void Step() = 0;
        virtual void SetMatrix(const csl::math::Matrix34& matrix) = 0;
        virtual csl::math::Matrix34 GetMatrix() const = 0;
        virtual void SetColor(csl::ut::Color8 color) = 0;
        virtual csl::ut::Color8 GetColor() const = 0;
        virtual void SetAlpha(unsigned char alpha) = 0;
        virtual unsigned char GetAlpha() const = 0;
        virtual void SetScale(const csl::math::Vector3& scale) = 0;
        virtual csl::math::Vector3 GetScale() const = 0;
        virtual void SetElementScale(const csl::math::Vector3 scale) = 0;
        virtual csl::math::Vector3 GetElementScale() const = 0;
        virtual void SetEmitRatio(float emitRatio) = 0;
        virtual float GetEmitRatio() const = 0;
        virtual void* GetData() = 0;
        virtual Resource::EffectParam* GetParam() const = 0;
        virtual const char* GetName() const = 0;
        virtual void* GetUnk1() const = 0;
        virtual void SetViewMask(unsigned int viewMask) = 0;
        virtual unsigned int GetViewMask() const = 0;
        virtual void SetUnk2(unsigned int value) = 0;
        virtual unsigned int GetUnk2() const = 0;
        virtual void SetVisibility(bool enabled) = 0;
        virtual bool GetVisibility() const = 0;
        virtual void SetBillboardViewportID(unsigned int viewportId) = 0;
        virtual void* UnkFunc30() = 0;
        virtual void UnkFunc31(void* unkParam1) = 0;
        virtual void SetUnk3(float value) = 0;
        virtual void SetUnk4(float value) = 0;
        virtual bool GetUnk5() const = 0;
        virtual bool GetUnk6() const = 0;
        virtual bool GetUnk7() const = 0;
        virtual ~Effect() = default;
    };

    class EffectImpl : public Effect {
    public:
        char name[128];
        ManagerImpl* manager;
        uint64_t qword90;
        Resource::EffectParam* effectParam;
        uint32_t dwordA0;
        uint32_t dwordA4;
        uint32_t dwordA8;
        uint64_t qwordB0;
        uint64_t qwordB8;
        uint64_t qwordC0;
        uint64_t qwordC8;
        uint64_t qwordD0;
        uint64_t qwordD8;
        uint64_t qwordE0;
        EffectHandle hh__eff__effecthandleE8;
        EffectHandle hh__eff__effecthandleF8;
        uint32_t flags;
        uint64_t qword110;
        hh::needle::NeedleRefcountObject* qword118;
        uint64_t qword120;
        uint32_t dword128;
        uint64_t qword130;
        uint64_t qword138;

        EffectImpl(ManagerImpl* managerImpl, Resource::EffectParam* effectParam, unsigned int unkParam1, void* unkParam2, const InheritChildParam* unkParam3, void* unkParam4, bool unkParam5, int unkParam6);

        virtual void Start() override;
        virtual void Stop() override;
        virtual void Pause() override;
        virtual void Resume() override;
        virtual bool IsPaused() const override;
        virtual void Step() override;
        virtual void SetMatrix(const csl::math::Matrix34& matrix) override;
        virtual csl::math::Matrix34 GetMatrix() const override;
        virtual void SetColor(csl::ut::Color8 color) override;
        virtual csl::ut::Color8 GetColor() const override;
        virtual void SetAlpha(unsigned char alpha) override;
        virtual unsigned char GetAlpha() const override;
        virtual void SetScale(const csl::math::Vector3& scale) override;
        virtual csl::math::Vector3 GetScale() const override;
        virtual void SetElementScale(const csl::math::Vector3 scale) override;
        virtual csl::math::Vector3 GetElementScale() const override;
        virtual void SetEmitRatio(float emitRatio) override;
        virtual float GetEmitRatio() const override;
        virtual void* GetData() override;
        virtual Resource::EffectParam* GetParam() const override;
        virtual const char* GetName() const override;
        virtual void* GetUnk1() const override;
        virtual void SetViewMask(unsigned int viewMask) override;
        virtual unsigned int GetViewMask() const override;
        virtual void SetUnk2(unsigned int value) override;
        virtual unsigned int GetUnk2() const override;
        virtual void SetVisibility(bool enabled) override;
        virtual bool GetVisibility() const override;
        virtual void SetBillboardViewportID(unsigned int viewportId) override;
        virtual void* UnkFunc30() override;
        virtual void UnkFunc31(void* unkParam1) override;
        virtual void SetUnk3(float value) override;
        virtual void SetUnk4(float value) override;
        virtual bool GetUnk5() const override;
        virtual bool GetUnk6() const override;
        virtual bool GetUnk7() const override;
        virtual void SetUnk8(bool enabled);
    };
}
