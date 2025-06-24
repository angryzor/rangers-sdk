#pragma once

namespace Cyan {
    class Scene {
    public:
        Graphics::Renderer renderer;
        Graphics::MeshRenderer meshRenderer;
        Graphics::ExternalMeshRenderer externalMeshRenderer;
        ManagerImpl* managerImpl;
        uint64_t unk1_1;
        uint64_t unk1_2;
        uint64_t unk1_3;
        volatile long long unk1_4;
        volatile int unk1_5;

        Scene(ManagerImpl* managerImpl);
    };
}