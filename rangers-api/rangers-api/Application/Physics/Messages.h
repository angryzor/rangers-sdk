#pragma once

namespace app::physics{
    class MsgColliderQueryEnter : public fnd::AppMessage<MsgColliderQueryEnter> {
    public:
        hh::fnd::Handle<hh::physics::GOCCollider> gocCollider;
        hh::fnd::Handle<GOCColliderQuery> gocQuery;
        csl::math::Vector3 position;
        csl::math::Vector3 qword40;
        csl::math::Vector4 qword50;
        int dword60;
        int dword64;

        MsgColliderQueryEnter(hh::fnd::Handle<GOCColliderQuery>& gocQuery, void* unk0) : fnd::AppMessage<MsgColliderQueryEnter>{ hh::fnd::MessageID::COLLIDER_QUERY_ENTER } {}
    };
}
