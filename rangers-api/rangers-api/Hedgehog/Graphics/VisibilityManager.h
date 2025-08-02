#pragma once

namespace hh::gfx {
    class VisibilityManager : public game::GameService {
    public:
        csl::ut::MoveArray<uint8_t*> visibleObjects;
        void* testFunction;

        virtual void* GetRuntimeTypeInfo() const override;

        void AddObject(uint8_t& visibilityHandle);
        void RemoveObject(uint8_t& visibilityHandle);

        GAMESERVICE_CLASS_DECLARATION(VisibilityManager)
    };
}
