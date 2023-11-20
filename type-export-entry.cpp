#include <stdint.h>

#define EXPORTING_TYPES
#define RESOLVE_STATIC_VARIABLE(x) x

typedef size_t HANDLE;
class ID3D11Device;
class ID3D11Texture2D;
class ID3D11ShaderResourceView;
class ID3D11RenderTargetView;
class ID3D11UnorderedAccessView;
class ID3D11DepthStencilView;
class ID3D11Buffer;
typedef struct _RTL_CRITICAL_SECTION {
    void* DebugInfo;
    int LockCount;
    int RecursionCount;
    void* OwningThread;        // from the thread's ClientId->UniqueThread
    void* LockSemaphore;
    void* SpinCount;        // force size on 64-bit systems when packed
} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;
typedef RTL_CRITICAL_SECTION CRITICAL_SECTION;

long InterlockedExchangeAdd(long volatile* Addend, long value);

void* sigScan(const char* signature, const char* mask, size_t sigSize, void* memory, const size_t memorySize);
void* sigScan(const char* signature, const char* mask, void* hint);
int strcmp(const char* x, const char* y);

namespace csl::math 
{
	class Vector2 { public: float x; float y; };
	class alignas(16) Vector3 { public: float x; float y; float z; };
	class alignas(16) Vector4 { public: float x; float y; float z; float w; };
	class Angle3 : Vector3 {};
	class alignas(16) Quaternion  {
	public:
		float x; float y; float z; float w;
		void SetRotationBetweenVectors(const Vector4& a, const Vector4& b, const Vector4& fallback);
		static Vector4 RotateVector(const Quaternion& quaternion, const Vector4& vector);
	};
	class alignas(16) Matrix44 {
		Vector4 t; Vector4 u; Vector4 v; Vector4 w;
	public:
		static Matrix44 CreateViewMatrix(Vector3 position, Vector3 up, Vector3 target);
		static Matrix44 CreateOrthogonalProjectionMatrix(float top, float bottom, float left, float right, float nearClip, float farClip);
		static Matrix44 CreatePerspectiveProjectionMatrix(float fov, float aspectRatio, float nearClip, float farClip);
	};
	class alignas(16) Matrix34 {
		Vector4 t; Vector4 u; Vector4 v; Vector4 w;
	public:
	};

	class Position { public: float x; float y; float z; };

	Matrix34 Matrix34Multiply(const Matrix34& x, const Matrix34& y);
	Matrix34 Matrix34AffineTransformation(const Vector3& position, const Quaternion& rotation);
	void Matrix34Scale(const Matrix34& mat, const Vector3& scale, Matrix34* result);

	class Segment3
	{
	public:
		Vector3 m_Start{};
		Vector3 m_End{};
	};

	class Capsule
	{
	public:
		Segment3 m_Segment{};
		float m_Radius{};
	};

	class Transform
	{
	public:
		Vector3 position;
		Quaternion rotation;
		Vector3 scale;

		Transform(const Transform& parent, const Transform& child);
	};

	class CalculatedTransform
	{
	public:
		Matrix34 m_Mtx;
		Vector3 m_Scale;
		size_t m_Flags;
	};

	template<typename T>
	inline static const T& Clamp(const T& value, const T& min, const T& max)
	{
		if (value < min)
			return min;
		
		if (value > max)
			return max;
		
		return value;
	}

	template<typename T>
	inline static const T& Max(const T& value, const T& max)
	{
		if (value > max)
			return value;

		return max;
	}

	template<typename T>
	inline static const T& Min(const T& value, const T& min)
	{
		if (value < min)
			return value;

		return min;
	}
	
	class Constants
	{
	public:
		inline static const Vector2 Vector2Zero{ 0, 0 };
		inline static const Vector3 Vector3Zero{ 0, 0, 0 };
		inline static const Quaternion QuaternionIdentity{ 0, 0, 0, 1 };
	};
}

namespace csl::geom {
	class Aabb
	{
	public:
		math::Vector3 m_Min{};
		math::Vector3 m_Max{};
		static Aabb Transform(const math::Matrix34& matrix, const Aabb& aabb);
	};
}

#include "include/rangers-api/rangers-api/rangers-api.h"

// template class csl::ut::MoveArray<csl::fnd::IAllocator*>;
template class csl::fnd::Delegate<void ()>;
template class csl::fnd::Delegate<void (hh::ui::UIListViewElement*, bool)>;
template class csl::fnd::Delegate<void (hh::ui::UIListViewElement*, hh::ui::ListViewEventArg&)>;
template class csl::fnd::Delegate<void (hh::ui::GOCSprite*)>;
template class csl::fnd::Delegate<void (hh::ui::GOCUIComposition*)>;
template class csl::ut::Pair<app::ui::UIMusicSelect*, void (app::ui::UIMusicSelect::*)(hh::ui::UIListViewElement*, hh::ui::ListViewEventArg&)>;
template class hh::game::InputComponent::InputMonitor<uint16_t>;
template class hh::game::InputComponent::InputMonitor<uint32_t>;
template class hh::game::InputComponent::InputMonitor<csl::math::Vector4>;
template class csl::ut::InplaceMoveArray<const char*, 32>;
template class csl::ut::Pair<SurfRide::ReferenceCast*, hh::ui::UIListViewElement::Cursor*>;
template class hh::fnd::Reference<hh::ui::UIListViewElement::Cursor>;
template class hh::fnd::Reference<hh::ui::UIElement>;
template class hh::fnd::Reference<hh::ui::UIElementBase>;
template class hh::fnd::ResReflection<app::player::GOCPlayerParameter::CharacterParameters>;
template class hh::fnd::ResReflection<app::rfl::PlayerCameraSetParameters>;
template class hh::needle::ImplDX11::NeedleResourceContainer<hh::needle::Texture, hh::needle::ImplDX11::TextureDX11Impl<hh::needle::ImplDX11::SBufferTexture2D, hh::needle::ImplDX11::SViewTexture2D, NEEDLE_RESOURCE_DX11_TEXTURE_VIEW>, NEEDLE_RESOURCE_CONTAINER, hh::needle::ImplDX11::SQueryTypeOwn, hh::needle::ImplDX11::SDupTypeSupport>;
template class hh::needle::ImplDX11::NeedleResourceContainer<hh::needle::RenderTarget, hh::needle::ImplDX11::TextureDX11Impl<hh::needle::ImplDX11::SBufferTexture2D, hh::needle::ImplDX11::SViewRenderTarget, NEEDLE_RESOURCE_DX11_RENDER_TARGET_VIEW>, NEEDLE_RESOURCE_CONTAINER, hh::needle::ImplDX11::SQueryTypeOwn, hh::needle::ImplDX11::SDupTypeNotSupport>;
template class hh::needle::ImplDX11::NeedleResourceContainer<hh::needle::UnorderedAccessView, hh::needle::ImplDX11::TextureDX11Impl<hh::needle::ImplDX11::SBufferTexture2D, hh::needle::ImplDX11::SViewUnorderedAccess, NEEDLE_RESOURCE_DX11_UNORDERED_ACCESS_VIEW>, NEEDLE_RESOURCE_CONTAINER, hh::needle::ImplDX11::SQueryTypeOwn, hh::needle::ImplDX11::SDupTypeNotSupport>;
template class hh::needle::ImplDX11::NeedleResourceContainer<hh::needle::DepthStencil, hh::needle::ImplDX11::TextureDX11Impl<hh::needle::ImplDX11::SBufferTexture2D, hh::needle::ImplDX11::SViewDepthStencil, NEEDLE_RESOURCE_DX11_DEPTH_STENCIL_VIEW>, NEEDLE_RESOURCE_CONTAINER, hh::needle::ImplDX11::SQueryTypeOwn, hh::needle::ImplDX11::SDupTypeNotSupport>;
template class hh::needle::ImplDX11::NeedleResourceContainer<hh::needle::VertexShader, hh::needle::ImplDX11::SShaderContext2, NEEDLE_RESOURCE_DX11_VERTEX_SHADER_OBJECT, hh::needle::ImplDX11::SQueryTypeSelf, hh::needle::ImplDX11::SDupTypeNotSupport>;
template class hh::needle::ImplDX11::NeedleResourceContainer<hh::needle::PixelShader, hh::needle::ImplDX11::SShaderContext2, NEEDLE_RESOURCE_DX11_PIXEL_SHADER_OBJECT, hh::needle::ImplDX11::SQueryTypeSelf, hh::needle::ImplDX11::SDupTypeNotSupport>;
template class hh::needle::ImplDX11::NeedleResourceContainer<hh::needle::ComputeShader, hh::needle::ImplDX11::SShaderContext2, NEEDLE_RESOURCE_DX11_COMPUTE_SHADER_OBJECT, hh::needle::ImplDX11::SQueryTypeSelf, hh::needle::ImplDX11::SDupTypeNotSupport>;
template class hh::needle::ImplDX11::NeedleResourceContainer<hh::needle::Buffer, hh::needle::ImplDX11::BufferDX11Impl<hh::needle::ImplDX11::SBufferObject, NEEDLE_RESOURCE_DX11_CONSTANT_BUFFER_OBJECT>, NEEDLE_RESOURCE_CONTAINER, hh::needle::ImplDX11::SQueryTypeOwn, hh::needle::ImplDX11::SDupTypeNotSupport>;
template class hh::needle::ImplDX11::NeedleResourceContainer<hh::needle::Buffer, hh::needle::ImplDX11::BufferDX11Impl<hh::needle::ImplDX11::SBufferObject, NEEDLE_RESOURCE_DX11_VERTEX_BUFFER_OBJECT>, NEEDLE_RESOURCE_CONTAINER, hh::needle::ImplDX11::SQueryTypeOwn, hh::needle::ImplDX11::SDupTypeNotSupport>;
template class csl::ut::MoveArray<const hh::fnd::ResourceTypeInfo*>;
template class csl::ut::Pair<hh::fnd::HFrame*, bool>;
template class csl::ut::InplaceMoveArray<csl::ut::Pair<hh::fnd::HFrame*, bool>, 10>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxBloomParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxDOFParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxColorContrastParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxToneMapParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxCameraControlParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxShadowMapParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxShadowHeightMapParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxVolumetricShadowParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxScreenBlurParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxSSAOParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxSHLightFieldParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxLightScatteringParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxRLRParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxSSGIParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxPlanarReflectionParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxOcclusionCapsuleParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxGodrayParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxScreenSpaceGodrayParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxHeatHazeParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxSceneEnvironmentParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxRenderOption>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxSGGIParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxTAAParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxEffectParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxAtmosphereParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxDensityParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxWindComputeParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxGpuEnvironmentParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxInteractiveWaveParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxChromaticAberrationParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxVignetteParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxTerrainMaterialBlendingParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxWeatherParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxColorAccessibilityFilterParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxCyberNoiseEffectParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxCyberSpaceStartNoiseParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxCyberNPCSSEffectRenderParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxDentParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxFieldScanEffectRenderParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxSeparableSSSParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxRenderTargetSetting>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxAntiAliasing>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::StageCommonAtmosphereParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxLODParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxDetailParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::FxDynamicResolutionParameter>;
template class app::gfx::FxParamManager::Interpolator<app::rfl::StageCommonTimeProgressParameter>;
template class csl::ut::PointerMap<hh::game::GameObjectClass*, csl::ut::MoveArray<hh::game::GameObject*>*>;
template class csl::ut::StringMap<hh::game::ObjectWorldChunkLayer*>;
template class csl::ut::HashMap<const char*, hh::game::ObjectWorldChunkLayer*, csl::ut::StringMapOperation>;
template class csl::ut::InplaceMoveArray<hh::game::GOComponentConfiguration, 5>;
