#pragma once

namespace app::evt{
    class EventEnvironmentPause : public EventEnvironment{
    public:
        hh::fnd::Handle<hh::game::GameObject> uiEventPauseGuide;

        virtual int64_t GetID() const override;
        virtual void AddCallback() override;
        virtual void RemoveCallback() override;
        virtual void EE_UnkFunc12() override; 
        virtual void EE_UnkFunc16() override;

        EventEnvironmentPause(csl::fnd::IAllocator* allocator);
    };
}
