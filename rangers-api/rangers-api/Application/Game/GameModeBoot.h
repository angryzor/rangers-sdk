#pragma once

namespace app::game{
    class GameModeBoot : public GameMode {
    public:
        hh::fnd::ResourceLoader* resLoader;
        int unk0;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool Initialize() override;
        virtual bool UnkFunc6(bool a2) override;

        GameModeBoot(csl::fnd::IAllocator* allocator);
    };
}