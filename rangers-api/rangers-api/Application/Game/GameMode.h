#pragma once

namespace app::game {
    class GameService;
    class GameModeExtension;
    class GameMode : public hh::fnd::Messenger {
    public:
        hh::game::GameManager* gameManager;
        uint64_t unk2;
        uint16_t unk3;
        uint32_t unk4;
        uint64_t fsm[9]; // tinyfsm
        csl::ut::MoveArray<GameService*> gameServices;
        csl::ut::MoveArray<GameModeExtension*> extensions;
        void* unk7; // created in the constructor, just not bothering right now
        uint32_t unk8;
        bool unk9;

        void SetState(unsigned int stateId);
		virtual void* GetRuntimeTypeInfo() const override;
        virtual bool UnkFunc4() { return true; }
        virtual bool UnkFunc5() {}
        virtual bool UnkFunc6() {}
        virtual bool UnkFunc7() {}
        virtual bool UnkFunc8() {}
        virtual bool UnkFunc9() {}
        virtual bool UnkFunc10() {}
        virtual bool UnkFunc11() {}
        virtual bool UnkFunc12() {}
        virtual bool UnkFunc13() {}

        hh::game::GameService* GetService(hh::game::GameServiceClass* gameServiceClass) const;
        template<typename T>
        T* GetService() const {
            return (T*)GetService(T::GetClass());
        }
        void AddService(hh::game::GameServiceClass* gameServiceClass);
        template<typename T>
        void AddService() {
            GetService(T::GetClass());
        }
        void RegisterService(hh::game::GameService* gameService);

        GameModeExtension* GetExtension(unsigned int name) const;
    };
}
