#pragma once

namespace hh::needle {
    struct ShaderObjectCreationInfo {
        VertexLayout* vertexLayout;
        VertexShader* vertexShader;
        PixelShader* pixelShader;
        ComputeShader* computeShader;
        InstanceParameterContainerData* vertexShaderInstanceParameterContainerData; // tt
        InstanceParameterContainerData* pixelShaderInstanceParameterContainerData; // tt
        InstanceParameterContainerData* computeShaderInstanceParameterContainersData[4];
        unsigned int computeShaderParameterContainerSizes[4]; //tt, maybe container type
        unsigned int computeShaderParameterContainerCount;
    };

    class ShaderObject : public NeedleRefcountResource {
    public:
    };
}
