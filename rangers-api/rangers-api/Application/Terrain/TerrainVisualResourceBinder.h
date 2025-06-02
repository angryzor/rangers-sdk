#pragma once

namespace app::trr {
    class TerrainVisualResourceBinder : public hh::fnd::ReferencedObject {
    public:
        csl::ut::InplaceMoveArray<hh::fnd::ManagedResource*, 4> resources;
        csl::ut::StringMap<hh::fnd::ManagedResource*> resourcesByName;
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;

        DEFAULT_CREATE_FUNC(TerrainVisualResourceBinder);
    };
}
