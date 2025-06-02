#pragma once

namespace Cyan::Graphics {
    // class MeshRendererNeedle : public hh::needle::ModelInstanceRenderer {

    // };
    class MeshRendererNeedle;

    class MeshRenderer : public Renderer {
    public:
        MeshRendererNeedle* meshRendererNeedle;

        MeshRenderer(ManagerImpl* managerImpl);

        virtual void Initialize(const DeviceContainer& deviceContainer) {}
        virtual unsigned int Render(const DeviceContainer& deviceContainer, unsigned int unkParam1, unsigned int unkParam2, unsigned int unkParam3, unsigned int unkParam4, void* unkParam5);
        virtual void* UnkFunc4(void* unkParam1);
        virtual void UnkFunc5(void* unkParam1);
        virtual void UnkFunc6(void* unkParam1, void* unkParam2, void* unkParam3);
        virtual void UnkFunc7(void* unkParam1, void* unkParam2, void* unkParam3);
        virtual void UnkFunc9();
    };
}
