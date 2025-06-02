#pragma once

namespace hh::needle {
    class ShaderMeshMaterialBuilder;

    struct ComputeShaderCreationInfo {
        InstanceParameterContainerData** instanceParameterContainers;
        unsigned int* instanceParameterContainerSizes;
        unsigned int instanceParameterContainerCount;
        unsigned int unk1;
        unsigned int unk2;
        unsigned int unk3;
        unsigned int unk4;
        unsigned int unk5;
    };

    struct ShaderMaterialContainerCreationInfo {
        ShaderMeshMaterialBuilder* meshMaterialBuilder;
        ComputeShaderCreationInfo* computeShaderCreationInfo;
        unsigned int additionalCount;
    };

    class ShaderMaterialContainerObject {
    };

    class ShaderMaterialContainer : public ShaderObject {
    public:
        ShaderMaterialContainerObject* shaderMaterialContainerObject;
    };
}