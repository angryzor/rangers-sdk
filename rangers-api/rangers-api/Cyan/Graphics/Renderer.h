#pragma once

namespace Cyan {
    class ManagerImpl;
}

namespace Cyan::Graphics {
    class Renderer {
    public:
        struct Unk1 {
            uint64_t unk1;
            uint64_t unk2;
            uint64_t unk3;
            Unk1* self;
            uint32_t unk5;

            Unk1();
        };

        ManagerImpl* managerImpl;
        Unk1 unk10[2];
        unsigned int dword60;
        uint64_t qword68;
        unsigned int dword70;
        uint8_t byte74;
        uint64_t qword78;
        uint64_t qword80;
        int dword88;

        Renderer(ManagerImpl* managerImpl);

        virtual ~Renderer();
        virtual void Initialize(const DeviceContainer& deviceContainer);
        virtual void UnkFunc2();
        virtual unsigned int Render(const DeviceContainer& deviceContainer, unsigned int unkParam1, unsigned int unkParam2, unsigned int unkParam3, unsigned int unkParam4, void* unkParam5); 
        virtual void* UnkFunc4(void* unkParam1);
        virtual void UnkFunc5(void* unkParam1);
        virtual void UnkFunc6(void* unkParam1, void* unkParam2, void* unkParam3);
        virtual void UnkFunc7(void* unkParam1, void* unkParam2, void* unkParam3);
        virtual void UnkFunc8(void* unkParam1, void* unkParam2, void* unkParam3, void* unkParam4);
    };
}
