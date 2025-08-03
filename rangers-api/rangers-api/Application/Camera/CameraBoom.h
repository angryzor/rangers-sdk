#pragma once

namespace app::camera{
    class CameraBoom : public hh::fnd::ReferencedObject {
    public:
        app_cmn::camera::CameraFrame* cameraFrame;
        csl::ut::MoveArray<int64_t> unk0;
        csl::ut::MoveArray<CameraBehavior*> camBehaviors;
        csl::math::Matrix34 matrix;
        float unk1[4];
        int unk2;

        CameraBoom(csl::fnd::IAllocator* allocator, app_cmn::camera::CameraFrame* cameraFrame);
    };
}
