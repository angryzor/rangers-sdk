#pragma once

namespace hh::navmesh{
    class NavMeshManager;

    class NavMeshManagerExtension : public fnd::ReferencedObject {
    public:
        NavMeshManager* manager;

        virtual void* GetRuntimeTypeInfo() const;
        virtual void AddCallback() {}
        virtual void RemoveCallback() {}
        virtual void UnkFunc2() {}
        virtual void UnkFunc3() {}
        virtual void Update(fnd::SUpdateInfo& updateInfo) {}

        NavMeshManagerExtension(csl::fnd::IAllocator* allocator);
    };
}
