#pragma once

namespace app_cmn::fsm
{
    class GOCTinyFsmContext : public hh::fnd::ReferencedObject {
        //hh::game::GOCTinyFsm2* fsmComponent;
        int64_t fsmComponent;
    public:
        //GOCTinyFsmContext() : hh::fnd::ReferencedObject(true) {}

        /*hh::game::GOCTinyFsm2* GetFsmComponent() const {
            return fsmComponent;
        }*/
    };
}
