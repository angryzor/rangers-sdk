#pragma once

namespace hh::cri{
    class CriMana : public fw::AppModule {
    public:
        const char* folderName;
        char unk0;
        int64_t unk1;
        int unk2;
        csl::fnd::IAllocator* unkAllocator;
        csl::ut::VariableString variableFolderName;
        csl::ut::VariableString movieFolderPath;
        int64_t unk3;
        int64_t unk4;
        int64_t unk5;

        virtual void UnkFunc1() override;
        virtual void UnkFunc2() override;

        APPMODULE_CLASS_DECLARATION(CriMana)
    };
}
