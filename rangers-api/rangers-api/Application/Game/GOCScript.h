#pragma once

namespace app::game{
    class GOCScript : public hh::game::GOComponent{
    public:
        hh::fnd::Handle<ScriptSequence> scriptSequence;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        void ExecuteScript(const char* name, bool isEndKill);
        bool IsUnk6Zero() const;

        GOCOMPONENT_CLASS_DECLARATION(GOCScript)
    };
}
