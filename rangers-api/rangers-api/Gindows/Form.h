#pragma once

namespace gindows{
    class Form : public ContainerControl {
    public:
        csl::ut::MoveArray<void*> qword7A0;
        csl::ut::MoveArray<void*> qword7C0;
        csl::ut::MoveArray<void*> qword7E0;
        csl::ut::MoveArray<void*> qword800;
        csl::ut::MoveArray<void*> qword820;
        csl::ut::MoveArray<void*> qword840;
        int flags860;
        int dword864;
        int dword868;
        int dword86C;
        int dword870;
        int dword874;
        int64_t qword878;
        int dword880;
        int64_t qword888;
        int64_t qword890;
        int64_t qword898;
        int64_t qword8A0;
        int64_t qword8A8;
        csl::fnd::IAllocator* qword8B0;

        virtual void* GetRuntimeTypeInfo() const override;

        virtual void ContUnkFuncNull() override;
        virtual void ContUnkFunc0(int* unk) override;
        virtual void* ContUnkFunc2() override;
        virtual void ContSetQWORD688(void* value) override;
        virtual int SaveProperty(void* propertyNode) override;
        virtual int LoadProperty(void* propertyNode) override;
        virtual char Render() override;
        virtual int OnLocationChanged() override;
        virtual int OnGotFocus() override;
        virtual int OnMouseLeave() override;
        virtual char ContUnkFunc18(void* unk) override;
        virtual char ContUnkFunc19(void* unk) override;
        virtual void* ContUnkFunc20() override;
        virtual void* ContUnkFunc22() override;
        virtual void* ContUnkFunc23() override;
        virtual void* ContUnkFunc31() override;
        virtual char ContUnkFunc36() override;
        virtual void ContUnkFunc46() override;
        virtual void* ContUnkFunc48() override;

        virtual void* FormUnkFunc0(void* unk); // something with qword7A0
        virtual void* FormUnkFunc1(void* unk); // something with qword7C0
        virtual void* FormUnkFunc2(void* unk); // something ver2 with qword7E0
        virtual void* FormUnkFunc3(void* unk); // something with qword800
        virtual void* FormUnkFunc4(void* unk); // something with qword820
        virtual void* FormUnkFunc5(void* unk); // something with qword840

        void SetMinimized(int unk);

        Form();
    };
}