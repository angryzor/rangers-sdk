#pragma once

namespace app {
    class ObjCamera : public hh::game::GameObject {
    public:
        uint64_t unk201;
        csl::ut::MoveArray<void*> unk205[1];
        uint32_t unk206;
        csl::fnd::Mutex mutex;

		virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;

        GAMEOBJECT_CLASS_DECLARATION(ObjCamera)
    };
}
