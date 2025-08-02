#pragma once

namespace app::game{
    class Script : public hh::fnd::ReferencedObject {
    public:
        struct LuaWrapper{
        public:
            void* luaState;
            char unk0;
            int unk1;
            int unk2;
            int unk3;
            csl::fnd::IAllocator* allocator;

            LuaWrapper(csl::fnd::IAllocator* allocator);
        };

        LuaWrapper luaWrapper;
        csl::ut::MoveArray<hh::fnd::ResLuaData*> resources;
        int64_t unk0;
        csl::ut::String scriptName;
        csl::ut::String currentLuaFile;
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        char unk3;

        LuaWrapper& GetLuaWrapper() const;
        void SetScriptName(const char* scriptName);

        Script(csl::fnd::IAllocator* allocator);
    };
}
