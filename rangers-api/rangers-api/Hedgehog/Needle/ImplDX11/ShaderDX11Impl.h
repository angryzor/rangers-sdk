#pragma once

#define NEEDLE_RESOURCE_DX11_VERTEX_SHADER_OBJECT  0x304F535631315844ui64 // '0OSV11XD'
#define NEEDLE_RESOURCE_DX11_PIXEL_SHADER_OBJECT   0x304F535031315844ui64 // '0OSP11XD'
#define NEEDLE_RESOURCE_DX11_COMPUTE_SHADER_OBJECT 0x304f534331315844ui64 // '0OSC11XD'

namespace hh::needle::ImplDX11 {
    struct SShaderOptionsDeclaration {
        CNameIDObject** optionNames;
        uint16_t numOptions;
        uint16_t unk;
        uint16_t optionsBits;
    };

    struct SShaderContextSetup;
    struct Shader2InitializeInfo {
        CScratchMemoryContext* memCtx;
        void* unk1;
        SShaderContextSetup* shaderContextSetup;
        DeviceObjectDX11* deviceObject;
    };

    class SShaderContext2 {
        char filename[256];
        void** parameterDeclarations;
        uint64_t unk0a;
        uint32_t* cachedShaderOffsetToParameterDeclarationMap;
        ShaderPtr* cachedShaders;
        SShaderOptionsDeclaration optionsDeclaration;
        uint16_t* optionHashToCachedShaderOffsetMap;
        uint64_t unk1;
        uint16_t unk2;

        static void MeasureMemory(MemoryLayoutContext* memLayoutCtx, const Shader2InitializeInfo& initializeInfo);
        bool Initialize(MemoryLayoutContext* memLayoutCtx, const Shader2InitializeInfo& initializeInfo);
    };

    struct ShaderDefinition {
        void* data;
        const char* name;
        unsigned int unk1;
    };

    struct ShaderOptionDefinition {
        CNameIDObject* name;
        unsigned int index;
        unsigned int unk1;
    };

    class SShaderContextSetup {
    public:
        void Setup(const Shader2InitializeInfo& shaderInitializeInfo);
        void Setup(SShaderContext2& shaderContext, void* data);
    };

    typedef NeedleResourceContainer<VertexShader, SShaderContext2, NEEDLE_RESOURCE_DX11_VERTEX_SHADER_OBJECT, SQueryTypeSelf, SDupTypeNotSupport> VertexShader;
    typedef NeedleResourceContainer<PixelShader, SShaderContext2, NEEDLE_RESOURCE_DX11_PIXEL_SHADER_OBJECT, SQueryTypeSelf, SDupTypeNotSupport> PixelShader;
    typedef NeedleResourceContainer<ComputeShader, SShaderContext2, NEEDLE_RESOURCE_DX11_COMPUTE_SHADER_OBJECT, SQueryTypeSelf, SDupTypeNotSupport> ComputeShader;
}
