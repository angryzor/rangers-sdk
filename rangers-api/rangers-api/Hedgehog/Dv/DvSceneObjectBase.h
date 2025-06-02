#pragma once

namespace hh::dv {
    class DvSceneObjectBase : public fnd::ReferencedObject {
    public:
        fnd::Handle<DvStandardCharacter> dvStandardChar;
        void* unk0;
        int visualModelNameHash;
        int unk2;

        virtual void* ReturnA2(void* a2);
        virtual void SetModelResource(hh::gfx::ResModel* resource) {};
        virtual void* VisualModelRelated0(gfx::ResVertexAnimationTexture* resVAT, void* a3, bool a4);
        virtual void* VisualModelRelated1(void* a2, float a3, bool a4);
        virtual void* VisualModelRelated2(void* a2, float a3, bool a4);
        virtual void* VisualModelRelated3(void* a2, float a3, bool a4);
        virtual void* VisualModelRelated4(void* a2);
        virtual void* VisualModelRelated5(void* a2);
        virtual void* VisualModelRelated6(void* a2);
        virtual void* VisualModelRelated7(void* a2);
        virtual void SetTransform(const csl::math::Transform transform);
        virtual void SetVisibility0(bool visible, bool unk);
        virtual void SetVisibility1(bool visible);
        virtual void SetVisualModelUnk0(double unk);
        virtual anim::GOCAnimator* GetGOCAnimator();
        virtual bool UnkTransform(void* a2, float a3, char a4, csl::math::Transform* transform);
        virtual void SetAnimatorState(const char* floatVarName, const char* stateName);
        virtual void* GetUnkGOCAnimator0(void* a2, void* a3, void* a4, int a5); // only a5 is used
        virtual bool SetUnkGOCAnimator1(const char* unkname, int a3);
        virtual void* GetGOCAnimatorUnk0(void* a2);
        virtual bool VisualModelIsAcceptingMessages();
        virtual void ShowDebugDraw();
        virtual void HideDebugDraw();

        DvSceneObjectBase(csl::fnd::IAllocator* allocator, hh::dv::DvStandardCharacter* character);
    };
}
