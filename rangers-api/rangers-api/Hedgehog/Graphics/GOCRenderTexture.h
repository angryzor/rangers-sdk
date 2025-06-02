#pragma once

namespace hh::gfx {
    class GOCRenderTexture : public game::GOComponent {
    public:
        // enum class Flag {
        // };

        struct CameraSettings {
            float width{ 1024.0f };
            float height{ 1024.0f };
            csl::math::Vector3 globalLightUnk1{ 0.0f, 0.0f, 0.0f };
            csl::math::Vector3 globalLightUnk2{ 1.0f, 1.0f, 1.0f };
            csl::math::Vector3 m12860{ 0.0f, 0.0f, 0.0f };
            csl::math::Vector3 cameraPosition{ 0.0f, 0.0f, 0.0f };
            csl::math::Vector3 cameraUp{ 0.0f, 1.0f, 0.0f };
            csl::math::Vector3 cameraTargetPos{ 0.0f, 0.0f, 1.0f };
            float fov{ 0.78539819f };
            float nearClip{ 10.0f };
            float farClip{ 5000.0f };
        };

        struct ShaderSettings {
            fnd::Reference<hh::needle::NeedleRefcountObject> *needlerefcountobject88{};
            uint64_t qword90{};
            uint64_t qword98{};
            uint8_t byteA0{};
        };

        struct SetupInfo {
            CameraSettings cameraSettings{};
            bool byte80{};
            bool byte81{};
            bool byte82{};
            bool byte83{};
            ShaderSettings shaderSettings{};
        };

        needle::RenderTextureHandle* renderTextureHandle;
        float width;
        float height;
        gfnd::ViewportData viewportData;
        csl::math::Vector3 m12840;
        csl::math::Vector3 m12850;
        csl::math::Vector3 m12860;
        uint32_t dword1E0;
        uint8_t byte1E4;
        uint64_t qword1E8;
        uint64_t copyColor;
        ShaderSettings shaderSettings;
        csl::ut::String name;
        uint64_t unk230[16];

        GOCRenderTexture(csl::fnd::IAllocator* allocator);
		virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnGOCEvent(GOCEvent event, game::GameObject& ownerGameObject, void* data) override;

        void Setup(const SetupInfo& setupInfo);
        void SetViewportData(const gfnd::ViewportData& viewportData);
        needle::Texture* GetTexture(unsigned int id) const;

        GOCOMPONENT_CLASS_DECLARATION(GOCRenderTexture);
    };
}
