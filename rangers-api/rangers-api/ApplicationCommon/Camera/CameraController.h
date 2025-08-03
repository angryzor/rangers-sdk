#pragma once

namespace app_cmn::camera {
    class CameraFrame;
    class CameraController : public hh::fnd::ReferencedObject {
    public:
        CameraParameter parameter;
        CameraFrame* cameraFrame;
        csl::ut::VariableString name;
        uint8_t unk2;

        virtual const char* GetControllerName() const {}
        virtual bool UnkFunc0() { return false; }
        virtual bool UnkFunc1() { return false; }
        virtual void UnkFunc2(int64_t a2) {}
        virtual int64_t UnkFunc3() { return 0; }
        virtual void UnkFunc4() {}
        virtual void UnkFunc5() {}

        CameraController(csl::fnd::IAllocator* allocator);

        void SetCameraFrame(CameraFrame* cameraFrame);
    };
}
