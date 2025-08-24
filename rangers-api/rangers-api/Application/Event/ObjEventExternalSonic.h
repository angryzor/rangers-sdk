#pragma once

namespace app::evt{
    class ObjEventExternalSonic : public ObjEventExternalBase {
    public:
        hh::fnd::Reference<gfx::MultiNodeContainer> nodeContainer;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual bool ProcessMessage(hh::fnd::Message& message) override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
        virtual unsigned int GetVisualNameHash() override;
        virtual bool GetUnkNodeNames0(csl::ut::MoveArray<const char*>& nodeNames) override;
        virtual bool GetUnkNodeNames1(csl::ut::MoveArray<const char*>& nodeNames) override;

        GAMEOBJECT_CLASS_DECLARATION(ObjEventExternalSonic)
    };
}
