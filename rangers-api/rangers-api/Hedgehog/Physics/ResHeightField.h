#pragma once

namespace hh::physics{
    class ResHeightField : public fnd::ManagedResource {
    public:
        class MaterialDataList : public fnd::BaseObject {
        public:
            csl::ut::MoveArray<void*> unk0;
            csl::ut::MoveArray<void*> unk1;
            csl::ut::MoveArray<uint8_t> materialData;
            uint32_t terrainSize[2];
            int64_t unk2;
            char unk3;

            static MaterialDataList* Create(csl::fnd::IAllocator* allocator);
        };

        bool sizeInBytes;
        uint32_t terrainSize[2];
        float unk0;
        float texelDensity;
        float heightPrecision;
        float heightRange;
        char unk1;
        uint16_t* heightData;
        uint64_t heightDataInBytes;
        MaterialDataList* matDataList;

        virtual void Load(void* data, size_t size) override;
        virtual void Unload() override;

        MANAGED_RESOURCE_CLASS_DECLARATION(ResHeightField)
    };
}
