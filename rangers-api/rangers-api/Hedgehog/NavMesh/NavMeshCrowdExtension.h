#pragma once

namespace hh::navmesh{
    class NavMeshCrowdExtension : public NavMeshManagerExtension {
    public:
        struct UnkStr {
            int maxAreas;
            float unk1;
        };

        UnkStr unk0;
        void* unk2;
        csl::ut::MoveArray<int64_t> unk3;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void UnkFunc2() override;
        virtual void UnkFunc3() override;
        virtual void Update(fnd::SUpdateInfo& updateInfo) override;

        void SetUnkStr(UnkStr& unkStr);

        NavMeshCrowdExtension(csl::fnd::IAllocator* allocator);
    };
}
