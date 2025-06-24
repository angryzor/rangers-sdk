#pragma once

namespace app::game{
    class Script : public hh::fnd::ReferencedObject {
    public:
        /*struct UnkStr1{
        public:
            int64_t unk0;
            char unk1; //flags
            char unk2; //flags
            char unk3; //prolly bool
            char unk4; //prolly bool
            char unk5; //prolly bool
            char unk6; //prolly bool
            short unk7; //flags
            void** luaCall0;
            void** unkStr1AllocFunc0;
            void* unk8; //points to a later point in the struct
            void* unk9;
            void* unk10;
            void* unk11;
            void* unk12;
            UnkStr1* unk13; //points back to itself
            void* unk14;
            void* unk15;
            void* unk16;
            void* unk17;
            void* unk18;
            float unk19; //could be flags or sumthin
            float unk20; //could be flags or sumthin
            float unk21; //could be flags or sumthin
            float unk22; //could be flags or sumthin
            float unk23; //could be flags or sumthin
            short unk24;
            short unk25;
            int unk26[4];
            char unk27;
            char unk28;
            char unk29; //prolly a bool
            char unk30;
            int unk31;
            int unk32;
            int unk33[3];
            void* unkStr1AllocFunc1;
            Script* script;
            int64_t unk34;
            int64_t unk35;
            int64_t unk36;
            int64_t unk37;
            void* unk38;
            int unkSize;
            int unkCapacity;
            void* ptrToUnk38;
            int64_t unk39;
            int64_t unk40;
            char unk41;
            int unk42;
            int unk43;
            char unk44;
            char unk45;
            char unk46;
            char unk47;
            short unk48; //prolly flags
            short unk49; //prolly flags
            short unk50; //prolly flags
            short unk51; //prolly flags
            void* ptrToLuaFunc0;
            int64_t unk52[8];
            void* ptrToLuaFunc1;
            int64_t unk53[8];

        };*/

        struct UnkStr0{
        public:
            void* unkStr1;
            char unk0;
            int unk1;
            int unk2;
            int unk3;
            csl::fnd::IAllocator* allocator;

            UnkStr0(csl::fnd::IAllocator* allocator);
        };

        UnkStr0 unkStr0;
        csl::ut::MoveArray<hh::fnd::ResLuaData*> resources;
        int64_t unk0;
        csl::ut::String scriptName;
        csl::ut::String currentLuaFile;
        csl::ut::MoveArray<void*> unk1;
        csl::ut::MoveArray<void*> unk2;
        char unk3;

        UnkStr0* GetUnkStr0();
        void SetScriptName(const char* scriptName);

        Script(csl::fnd::IAllocator* allocator);
    };
}
