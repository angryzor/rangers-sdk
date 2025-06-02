#pragma once
#include <ucsl/resources/shader-list/v2.h>

namespace hh::gfx {
    using ucsl::resources::shader_list::v2::ShaderListParameterData;
    using ucsl::resources::shader_list::v2::ShaderListShaderData;
    using ucsl::resources::shader_list::v2::ShaderListTableData;
    using ucsl::resources::shader_list::v2::ShaderListData;

    class ResShaderList : public fnd::ManagedResource {
        void LoadResource();

    public:
        ShaderListTableData* shaderListData;
        void* reloadedData;
        csl::ut::StringMap<const char*> shadersByType;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override {}
        virtual void Reload(void* data, size_t size) override;
        
        MANAGED_RESOURCE_CLASS_DECLARATION(ResShaderList);
    };
}
