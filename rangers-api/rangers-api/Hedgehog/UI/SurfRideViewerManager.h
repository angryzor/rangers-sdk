#pragma once

namespace hh::ui {
    class SurfRideViewerManager : public game::GameService {
    public:
        class UnkStr0 {
        public:
            void* vftable;
            fnd::ResourceLoader* resLoader;
        };

        fnd::ResourceLoader* resLoader;
        UnkStr0 resLoaderResolver;
        csl::ut::MoveArray<void*> unkArray0;
        void* unk1;
        char unk2;

        virtual void* GetRuntimeTypeInfo() const override;

        GAMESERVICE_CLASS_DECLARATION(SurfRideViewerManager)
    };
}
