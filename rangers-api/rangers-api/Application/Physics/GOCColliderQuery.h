#pragma once

namespace app::physics {
    class GOCColliderQuery : public hh::game::GOComponent, public hh::fnd::HFrameListener, public hh::game::GameStepListener {
    public:
        uint64_t qword80;
        csl::ut::MoveArray<void*> unk88;
        csl::ut::MoveArray<void*> unkA8;
        uint64_t qwordC8;
        csl::math::Transform localTransform;
        csl::math::Transform worldTransform;
        uint8_t byte140;
        uint32_t qword144;
        uint32_t qword148;
        uint64_t qword150;
        uint64_t qword158;
        uint16_t word160;

        GOCColliderQuery(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, hh::game::GameObject& ownerGameObject, void* data) override;
        virtual bool UnkFunc101(void* unkParam1, void* unkParam2);
        virtual void HFrameUpdatedCallback(const hh::fnd::HFrame* frame, bool unkParam) override;
		virtual void PostStepCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;
		virtual void UpdateCallback(hh::game::GameManager* gameManager, const hh::game::GameStepInfo& gameStepInfo) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCColliderQuery);
    };
}