#pragma once

namespace hh::ui {
    class SurfRideHandleBase : public fnd::RefByHandleObject {
    public:
        void* surfRideObject;

        typedef fnd::HandleManager<SurfRideHandleBase> HandleManager;
        SurfRideHandleBase(csl::fnd::IAllocator* pAllocator, void* surfRideObject);

        virtual void PreReload(SurfRide::Project* project) = 0;
        virtual void PostReload(SurfRide::Project* project) = 0;
    };

    class SurfRideLayerHandle : public SurfRideHandleBase {
    public:
        csl::ut::String key;

        SurfRideLayerHandle(csl::fnd::IAllocator* pAllocator, SurfRide::Layer* layer);

        inline SurfRide::Layer* GetLayer() const { return surfRideObject == nullptr ? nullptr : reinterpret_cast<SurfRide::Layer*>(reinterpret_cast<size_t>(surfRideObject) - 8); }
        inline void SetLayer(SurfRide::Layer* layer) { surfRideObject = layer == nullptr ? nullptr : reinterpret_cast<void*>(reinterpret_cast<size_t>(layer) + 8); }

        virtual void PreReload(SurfRide::Project* project) override;
        virtual void PostReload(SurfRide::Project* project) override;
    };

    class GOCSprite;
    class SurfRideCastHandle : public SurfRideHandleBase {
    public:
        GOCSprite* gocSprite;
        csl::ut::String key;

        SurfRideCastHandle(csl::fnd::IAllocator* pAllocator, GOCSprite* gocSprite, SurfRide::Cast* cast);

        inline SurfRide::Cast* GetCast() const { return surfRideObject == nullptr ? nullptr : reinterpret_cast<SurfRide::Cast*>(reinterpret_cast<size_t>(surfRideObject) - 8); }
        inline void SetCast(SurfRide::Cast* cast) { surfRideObject = cast == nullptr ? nullptr : reinterpret_cast<void*>(reinterpret_cast<size_t>(cast) + 8); }

        virtual void PreReload(SurfRide::Project* project) override;
        virtual void PostReload(SurfRide::Project* project) override;
    };
}
