#pragma once

namespace app {
    class IslandObjInfo : public hh::game::ObjInfo {
        char pad[0x270];

    public:
        IslandObjInfo(csl::fnd::IAllocator* allocator);

        virtual void Initialize(hh::game::GameManager* gameManager) override;
        virtual const char* GetInfoName() override;
    };
}
