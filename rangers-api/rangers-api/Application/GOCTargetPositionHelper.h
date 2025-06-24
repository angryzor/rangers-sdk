#pragma once

namespace app{
    class TargetPositionHelperListener {
    public:
        virtual int8_t TPHL_UnkFunc0() { return 0; }
    };

    class GOCTargetPositionHelper : public hh::game::GOComponent {
    public:
        int64_t unk0;
        csl::ut::MoveArray<int64_t> listeners; //unsure
        int unk1;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void Update(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo) override;
		virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        GOCOMPONENT_CLASS_DECLARATION(GOCTargetPositionHelper)
    };
}
