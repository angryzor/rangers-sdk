#pragma once

#define MANAGED_RESOURCE_CLASS_DECLARATION(ClassName) private:\
		static const hh::fnd::ResourceTypeInfo typeInfo;\
		ClassName(csl::fnd::IAllocator* allocator);\
		static hh::fnd::ManagedResource* Create(csl::fnd::IAllocator* allocator);\
	public:\
		static const hh::fnd::ResourceTypeInfo* GetTypeInfo();

namespace hh::fnd {
    class ManagedResource;

    struct ResourceTypeInfo {
        const char *pName;
        const char *pScopedName;
        uint32_t objectSize;
        bool isInBinaContainer;
        ManagedResource* (*instantiator)(csl::fnd::IAllocator* pAllocator);
    };

    class ResourceResolver;
    class StaticResourceContainer;
    class ManagedResource : public ReferencedObject, private csl::ut::NonCopyable {
    public:
        csl::ut::VariableString name;
        csl::ut::VariableString unkStrPrefix; // before hyphen
        csl::ut::VariableString unkStrPostfix; // after hyphen
        const ResourceTypeInfo* resourceTypeInfo;
        csl::fnd::IAllocator* resourceAllocator;
        void* originalBinaryData;
        void* unpackedBinaryData;
        size_t size;
        FileResource* file;

        ManagedResource(csl::fnd::IAllocator* pAllocator);

        inline const char* GetName() const;

        inline const ResourceTypeInfo& GetClass() const {
            return *resourceTypeInfo;
        }

        inline size_t GetSize() const {
            return size;
        }

        inline csl::fnd::IAllocator* GetResourceAllocator() {
            return resourceAllocator;
        }

        static ManagedResource* Create(csl::fnd::IAllocator* allocator, FileResource* file, const char* name, ResourceTypeInfo* resourceTypeInfo);
        static ManagedResource* Create(csl::fnd::IAllocator* allocator, csl::fnd::IAllocator* resourceAllocator, const char* unkStrParam, const char* name, void* data, size_t size, ResourceTypeInfo* resourceTypeInfo);

        // This is only guessed from a similar function in rio, but there this and the following function are swapped.
        // I haven't actually seen this be overridden anywhere.
        virtual void LoadFromStaticResourceContainer(void* data, size_t size, StaticResourceContainer* container);
        virtual void Load(void* data, size_t size) = 0;
        virtual void Unload() = 0;
        virtual void Resolve(ResourceResolver& resolver) {}
        virtual void Reload(void* data, size_t size) {}
    };
}
