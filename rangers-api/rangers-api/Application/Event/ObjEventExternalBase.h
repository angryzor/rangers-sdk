#pragma once

namespace app::evt{
    class ObjEventExternalBase : public hh::game::GameObject {
    public:
        struct EventCharacter {
            typedef ObjEventExternalBase* CreateFunction(csl::fnd::IAllocator* allocator, hh::game::GameManager* gameManager);

            const char* idName;
            CreateFunction* instantiator;
        };

        int unk0;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual unsigned int GetVisualNameHash() { return 0; }
        virtual bool GetUnkNodeNames0(csl::ut::MoveArray<const char*>& nodeNames) { return true; }
        virtual bool GetUnkNodeNames1(csl::ut::MoveArray<const char*>& nodeNames) { return true; }

        static EventCharacter** eventCharacters[20];
        static ObjEventExternalBase* CreateCharacterObjectByName(const char* name, csl::fnd::IAllocator* allocator, hh::game::GameManager* gameManager);

        ObjEventExternalBase(csl::fnd::IAllocator* allocator);
    };
}
