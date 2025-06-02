#pragma once

#define APP_DV_ELEMENT_DECLARATION_BASE(ClassName)public:\
		static app::dv::AppDvElementBase* Create(csl::fnd::IAllocator* allocator);\
        ClassName::Description* GetData() {\
            return reinterpret_cast<ClassName::Description*>(elementBinaryData);\
        }

namespace app::dv{
    class AppDvElementBase : public hh::dv::DvElementBase{
    public:
        enum class Flags : unsigned char {
            HAS_DATA
        };

        long elementBinaryDataSize;
        void* elementBinaryData;
        csl::ut::Bitset<Flags> flags;

        virtual void SetData(void* data) override;
        virtual void DeleteData() override;
        virtual void OnDataUpdated() {};
        virtual void OnDataDeleted() {};
        virtual void AppUnkFunc2() {};
        virtual void* AppUnkFunc3(void* unk0, unsigned int unk1) {};

        const char* GetBinaryData();

        AppDvElementBase(csl::fnd::IAllocator* allocator, hh::dv::DvNodeElement* base);
    };
}
