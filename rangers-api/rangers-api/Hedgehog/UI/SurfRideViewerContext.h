#pragma once

namespace hh::ui {
    class SurfRideViewerContext : public hh::game::ServiceViewerContextBase {
    public:
        csl::ut::MoveArray<void*> unkArray0;
        void* unk1;

        virtual void UnkFunc4() override;
        virtual void UnkFunc5() override;
        virtual void GameServiceAddedCallback(game::GameService* gameService) override;

        VIEWER_CONTEXT_CLASS_DECLARATION(SurfRideViewerContext)
    };
}
