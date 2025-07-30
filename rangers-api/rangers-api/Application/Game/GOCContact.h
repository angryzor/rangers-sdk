#pragma once

namespace app::game{
    class ContactListener{
    public:
        virtual void OnContact() {}
        virtual void CL_UnkFunc1() {}
        virtual void CL_UnkFunc2() {}
    };

    class GOCContact : public hh::game::GOComponent, public hh::fnd::HFrameListener{
    public:
        struct Description{
            char unk140;
            float unk130;
            float range;
            float visibleRange;
            hh::fnd::HFrame* hFrame;
            csl::math::Transform offsetTransform;
            csl::math::Vector4 preFinalPosition;
            bool byte60;
            bool byte61;
            bool compassVisible;
            bool enable;
            float float64; //usually PI
            bool byte68;
            bool byte69;
            bool byte6A;
            bool byte6B;
            bool portalUI;
            bool byte6D;
        };

        enum class Flags : unsigned short{
            ENABLED,
            DIRTY,
            UNK1,
            UNK2,
            COMPASS_VISIBLE,
            UNK4,
            PORTAL_UI = 10,
        };

        hh::fnd::HFrame* hFrame;
        csl::ut::MoveArray<ContactListener*> listeners;
        csl::math::Transform contactTransform;
        csl::math::Transform offsetTransform;
        csl::math::Vector4 preFinalPosition;
        csl::math::Vector4 finalPosition;
        float unk130;
        float range;
        float visibleRange;
        float distanceBetweenPlayer;
        char unk140;
        bool unk141;
        char unk142;
        int64_t unk148;
        hh::fnd::MemoryRouterAllocator* debugAllocator;
        csl::ut::Bitset<Flags> flags;
        int unk15C;
        float unk160;
        char unk164;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;
		virtual bool ProcessMessage(hh::fnd::Message& msg) override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;

        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;

        void Setup(Description& desc);
        void SetEnabled(bool enabled);
        bool GetEnabled() const;
        void AddListener(ContactListener* listener);
        void SetFrame(hh::fnd::HFrame* hFrame);

        GOCOMPONENT_CLASS_DECLARATION(GOCContact)
    };
}
