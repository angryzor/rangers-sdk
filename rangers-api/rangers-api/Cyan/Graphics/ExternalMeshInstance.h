#pragma once

namespace Cyan::Graphics {
    template<typename Model, typename ModelInstance>
    class ExternalMeshInstance {
    public:
        class RenderHandler {
        public:
            virtual ModelInstance* CreateModelInstance(Model* model) = 0;
            virtual void SetVisible(ModelInstance* modelInstance, bool visible) = 0;
            virtual void UnkFunc3(void* unkParam1, unsigned int unkParam2) = 0;
            virtual bool UnkFunc4(void* unkParam1) = 0;
            virtual void UnkFunc5() = 0;
            virtual void UnkFunc6(ModelInstance* modelInstance, void* unkParam1, void* unkParam2) = 0;
        };
    };
}
