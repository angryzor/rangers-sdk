#pragma once

namespace app::ui{
    class UIMapMenu : 
        public hh::game::GameObject, 
        public hh::hid::ActiveDeviceManagerListener, 
        public hh::fw::MouseEventHandler 
    {
    public:
        struct MapElement{
            hh::ui::LayerController* layerController;
            int id; //or handle? idrk
            csl::math::Vector3 position;
            float scaleMin;
            float scaleMax;
            float scale;
            int unk0;
        };
        
        struct PortalElement{
            int unk0;
            int unk1;
            int unk2;
            int unk3;
            const char* gateName;
            csl::math::Vector3 position;
            csl::math::Vector4 crop; //unsure
        };

        struct UnkStr0{
            int64_t unk0;
            csl::math::Vector3 position;
            int unk1;
            float unk2;
        };

        float unk0a;
        float unk0b;
        char unk0;
        int unk1;
        int64_t unk2;
        int64_t unk3;
        csl::math::Vector4 unk4;
        csl::ut::MoveArray<int64_t> unk5;
        short flags;
        csl::math::Vector3 unk6; //contains zoom
        csl::math::Vector4 unk7;
        csl::ut::MoveArray<MapElement> mapElements;
        csl::ut::MoveArray<int64_t> unk8;
        csl::ut::MoveArray<int64_t> unk9;
        hh::ui::LayerController** unk10;
        int* unk11;
        hh::ui::LayerController** unk12;
        hh::ui::LayerController** unk13;
        int64_t unk14;
        csl::fnd::IAllocator* unk15;
        csl::ut::MoveArray<hh::ui::LayerController*> layerControllers;
        hh::ui::LayerController* unk16;
        csl::math::Vector3 waypointPosition;
        csl::math::Vector4 unk17;
        hh::ui::LayerController* unk18;
        csl::math::Vector3 relatedToWaypointPosition;
        csl::math::Vector4 unk19;
        csl::math::Vector4 pointPosition;
        int unk20;
        int unk21;
        int unk22;
        int unk23;
        int unk24;
        int unk25;
        int unk26;
        char unk27;
        csl::ut::MoveArray<PortalElement> portalElements;
        csl::ut::MoveArray<MapElement> portalMapElements;
        csl::ut::MoveArray<UnkStr0> unk28;
        csl::ut::MoveArray<int64_t> unk29;
        csl::ut::MoveArray<UnkStr0> unk30;
        csl::ut::MoveArray<UnkStr0> unk31;
        csl::ut::MoveArray<UnkStr0> unk32;
        csl::ut::MoveArray<int64_t> unk33;
        csl::ut::MoveArray<int64_t> unk34;
        csl::ut::MoveArray<int64_t> unk35;
        csl::ut::MoveArray<int64_t> unk36;
        csl::ut::MoveArray<int64_t> unk37;
        csl::ut::MoveArray<int64_t> unk38;
        int unk39;
        int stageIdx;
        int unk40;
        int unk40b;
        csl::ut::MoveArray<int> unk41;
        int unk42;
        char unk43;
        int64_t unk44;
        int unk45;
        csl::math::Vector4 unk47;
        int unk48;
        char unk49;
        int64_t unk50;
        int unk51;
        int unk51b;
        int unk52;
        int unk53;
        int unk54;
        char unk55[0xB4];
        int64_t unk56[6];
        int64_t unk57;
        float unk58;
        int unk59;
        app::player::CharacterIdU8 playerId;

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void OnDeviceChange() override;
        virtual bool MEH_Unk1() override;
        virtual bool MEH_Unk2() override;
        virtual bool MEH_Unk4() override;

        GAMEOBJECT_CLASS_DECLARATION(UIMapMenu)
    };
}
