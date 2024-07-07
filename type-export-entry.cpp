#define EXPORTING_TYPES
#define RESOLVE_STATIC_VARIABLE(x) x

namespace std {
	typedef size_t align_val_t;
}

namespace csl::geom {
	class Aabb;
	class Obb;
	class Segment3;
	class Line3;
	class Ray3;
	class Sphere;
	class Cylinder;
}

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
	class Rotation { public: float x; float y; float z; float w; };

	class Plane {
	public:
		Vector3 point;
		Vector3 normal;

		static Plane FromPointNormal(const Vector3 point, const Vector3 normal);
		Vector3 ProjectOnNormal(const Vector3& point, float* signedDistance) const;
	};

	Vector3 Vector3Cross(const Vector3 x, const Vector3 y);
	float Vector3Distance(const Vector3 x, const Vector3 y);
	float Vector3DistanceSq(const Vector3 x, const Vector3 y);
	float Vector3DistanceNormalized(const Vector3 x, const Vector3 y);
	float Vector3Dot(const Vector3 x, const Vector3 y);
	Vector3 Vector3NormalBetween(const Vector3 x, const Vector3 y);
	Matrix34 Matrix34Multiply(const Matrix34& x, const Matrix34& y);
	Matrix34 Matrix34AffineTransformation(const Vector3& position, const Quaternion& rotation);
	void Matrix34Scale(const Matrix34& mat, const Vector3& scale, Matrix34* result);
	Matrix34 Matrix34Rotation(const Quaternion& rotation);

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

	bool Intersection(const geom::Line3& line, const Plane& plane, Vector3 intersectionPoint, float* unkParam);
	bool Intersection(const geom::Ray3& line, const geom::Aabb& aabb, float* unkParam);
	bool Intersection(const geom::Ray3& line, const Plane& plane, Vector3 intersectionPoint, float* unkParam);
	bool Intersection(const geom::Segment3& line, const Plane& plane, Vector3 intersectionPoint, float* unkParam);
	bool Intersection(const geom::Sphere& sphere, const geom::Aabb& aabb);
	bool Intersection(const geom::Sphere& sphere, const geom::Obb& obb);
	bool Intersection(const Vector3& point, const geom::Aabb& aabb);
	bool Intersection(const Vector3& point, const geom::Obb& obb);
	bool Intersection(const Vector3& point, const geom::Sphere& sphere);
	bool Intersection(const Vector3& point, const geom::Cylinder& sphere);

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
		math::Vector3 Center() const;
		bool Intersect(const Aabb& aabb) const;
		math::Vector3 Extent() const;
		float DistanceSq(const math::Vector3& point, math::Vector3* distanceByAxis) const;
	};

	class Obb
	{
	public:
		math::Vector3 min{};
		math::Vector3 extentX{};
		math::Vector3 extentY{};
		math::Vector3 extentZ{};

		void Set(const math::Vector3& position, const math::Vector3& halfExtents, const math::Quaternion& rotation);
		float DistanceSq(const math::Vector3& point, math::Vector3* distanceByAxis) const;
	};
	
	class Segment3
	{
	public:
		math::Vector3 start{};
		math::Vector3 end{};
	};

	class Sphere
	{
	public:
		math::Vector3 position{};
		float radius;
	};

	class Cylinder
	{
		Segment3 segment;
		float radius;

		void Set(float radius, float halfHeight, const math::Vector3& center, const math::Quaternion& rotation);
		float DistanceSq(const math::Vector3& point, float* scaledHeightFromBase) const;
	};
}

#include "rangers-api/rangers-api/rangers-api.h"

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
template class hh::fnd::ResReflectionT<app::player::GOCPlayerParameter::CharacterParameters>;
template class hh::fnd::ResReflectionT<heur::rfl::PlayerCameraSetParameters>;
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
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxBloomParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxDOFParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxColorContrastParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxToneMapParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxCameraControlParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxShadowMapParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxShadowHeightMapParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxVolumetricShadowParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxScreenBlurParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxSSAOParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxSHLightFieldParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxLightScatteringParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxRLRParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxSSGIParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxPlanarReflectionParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxOcclusionCapsuleParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxGodrayParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxScreenSpaceGodrayParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxHeatHazeParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxSceneEnvironmentParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxRenderOption>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxSGGIParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxTAAParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxEffectParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxAtmosphereParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxDensityParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxWindComputeParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxGpuEnvironmentParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxInteractiveWaveParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxChromaticAberrationParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxVignetteParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxTerrainMaterialBlendingParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxWeatherParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxColorAccessibilityFilterParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxCyberNoiseEffectParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxCyberSpaceStartNoiseParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxCyberNPCSSEffectRenderParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::gfx::FxDentParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxFieldScanEffectRenderParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxSeparableSSSParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::gfx::FxRenderTargetSetting>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxAntiAliasing>;
template class app::gfx::FxParamManager::Interpolator<hh::gfx::StageCommonAtmosphereParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxLODParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxDetailParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::needle::FxDynamicResolutionParameter>;
template class app::gfx::FxParamManager::Interpolator<hh::gfx::StageCommonTimeProgressParameter>;
template class csl::ut::PointerMap<hh::game::GameObjectClass*, csl::ut::MoveArray<hh::game::GameObject*>*>;
template class csl::ut::StringMap<hh::game::ObjectWorldChunkLayer*>;
template class csl::ut::HashMap<const char*, hh::game::ObjectWorldChunkLayer*, csl::ut::StringMapOperation>;
template class csl::ut::InplaceMoveArray<hh::game::GOComponentConfiguration, 5>;
template class hh::fnd::Handle<hh::game::GameObject>;
template class hh::fnd::Handle<hh::physics::GOCCollider>;
template class csl::ut::InplaceMoveArray<hh::anim::BlendNodeBase*, 2>;
template class hh::fnd::Reference<app::level::StageData>;
template class hh::fnd::Reference<app::game::GameModeResourceModule>;
template class hh::needle::MaterialParamData<float>;
template class hh::needle::MaterialParamData<int>;
template class hh::needle::MaterialParamData<bool>;
template class app::player::StatePluginManager<app::player::PlayerHsmContext>;
template class csl::ut::MoveArray<csl::ut::MoveArray<void*>>;
template class csl::fnd::Delegate<void (uint64_t, const float&)>;
template class csl::ut::MoveArray<app_cmn::camera::CameraFrame::BlendNode*>;
template class csl::ut::MoveArray<hh::needle::intrusive_ptr<hh::needle::SceneContextManager>>;
template class csl::ut::MoveArray32<hh::ut::BvWorldHandle>;
template class csl::ut::MoveArray<hh::ut::KdTreeBuilder::InternalObject>;
