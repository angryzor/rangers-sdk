#pragma once

namespace hh::fnd {
    class FileResource : public hh::fnd::ReferencedObject {
    public:
        csl::fnd::IAllocator* fileAllocator;
        csl::ut::VariableString name;
        hh::fnd::Uri uri;
        uint8_t unk1;
        unsigned int alignment;
        size_t bufferSize;
        void* data;
        size_t fileSize;
        size_t headerSize;


        FileResource(csl::fnd::IAllocator* allocator);
        static inline FileResource* Create(csl::fnd::IAllocator* allocator);
    };
}