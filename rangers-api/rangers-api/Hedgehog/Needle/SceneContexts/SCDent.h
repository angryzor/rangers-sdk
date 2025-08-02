#pragma once

namespace hh::needle {
    class DensityContainer : public NeedleRefcountObject {
    public:
        struct UnkStr0 {
            struct UnkStr1{
                int64_t unk0; // 0x143A19418
                hh::needle::Texture* unk1; //hh::needle::ImplDX11::NeedleTextureResourceContainer* 0x143A1AA98
                int64_t unk2; // not mentioned in ctor
            };

            UnkStr1 unk0[5];
            int unk1;
            int unk2;
            int64_t unk3;
            int unk4; // not mentioned in ctor
            int unk5;
            hh::needle::SupportFX::SFXAllocator* unkAllocator;
            int64_t unk6;
            int64_t unk7;
            int64_t qwordA0;
            int64_t qwordA8;
            int64_t qwordB0;
            int64_t qwordB8;
            int64_t qwordC0;
            int64_t qwordC8;
            int64_t qwordD0;
            int64_t qwordD8;
            int64_t qwordE0;
            int64_t qwordE8;
            int64_t qwordF0;
            int64_t qwordF8;
            int64_t qword100;
            int64_t qword108;
            int64_t qword110;
            int64_t qword118;
            int64_t qword120;
            int64_t qword128;
            int64_t qword130;
            int64_t qword138;
            int64_t qword140;
            int64_t qword148;
            int64_t qword150;
            int64_t qword158;
            int64_t qword160;
            int64_t qword168;
            int64_t qword170;
            int64_t qword178;
            int64_t qword180;
            int64_t qword188;
            int64_t qword190;
            int dword198;
            int dword19C;
            int dword1A0;
            int dword1A4;
            int dword1A8;
            int dword1AC;
            int dword1B0;
            int dword1B4;
            int dword1B8;
            int dword1BC;
            int dword1C0;
            int dword1C4;
            int dword1C8;
            int dword1CC;
            int dword1D0;
            int dword1D4;
            int dword1D8;
            int dword1DC;
            int dword1E0;
            int dword1E4;
            int dword1E8;
            int dword1EC;
            int dword1F0;
            int dword1F4;
            int dword1F8;
            int dword1FC;
            int dword200;
            int dword204;
            int dword208;
            int dword20C;
            int dword210;
            int dword214;
            int64_t qword218;
            int64_t qword220;
            int64_t qword228;
            int64_t qword230;
            int64_t qword238;
            int64_t qword240;
            int64_t qword248;
            int64_t qword250;
            int64_t qword258;
            int64_t qword260;
            int64_t qword268;
            int64_t qword270;
            int64_t qword278;
            int64_t qword280;
            int64_t qword288;
            int64_t qword290;
            int64_t qword298;
            int64_t qword2A0;
            int64_t qword2A8;
            int64_t qword2B0;
            int64_t qword2B8;
            int64_t qword2C0;
            int64_t qword2C8;
            int64_t qword2D0;
            int64_t qword2D8;
            int64_t qword2E0;
            int64_t qword2E8;
            int64_t qword2F0;
            int64_t qword2F8;
            int64_t qword300;
            int64_t qword308;
            int64_t qword310;
            float size[2];

            UnkStr0();
        };

        struct UnkStr1{
            int dword0;
            int64_t qword8;
            int64_t qword10;
            int64_t gap18;
            int64_t qword20;
            int64_t qword28;
            int64_t gap30;
            int64_t qword38;
            int64_t qword40;
            int64_t gap48;
            int dword50;
            int64_t qword54;
            int64_t qword5C;
            int dword64;
            int64_t qword68;
            int dword70;

            UnkStr1();
        };

        struct UnkStr2{
            int64_t qword0;
            int64_t qword8;
            int64_t gap10;
            int64_t qword18;
            int64_t qword20;
            int64_t gap28;
            int64_t qword30;

            UnkStr2();
        };

        csl::ut::MoveArray<int64_t> unk0;
        csl::ut::MoveArray<int64_t> unk1;
        csl::ut::MoveArray32<int64_t> unk2; //unsure
        int64_t placementTexStreamCompute; //hh::needle::PlacementTextureStreamingCompute* 0x141D23EC0
        UnkStr0 unkStr0;
        UnkStr1 unkStr1;
        UnkStr2 unkStr2;
        csl::ut::MoveArray<int64_t> unk3;
        int64_t qword460;
        int64_t qword468;
        int64_t qword470;
        int64_t qword478;
        int64_t qword480;
        int64_t qword488;
        int64_t qword490;
        int64_t qword498;
        int64_t qword4A0;
        int64_t qword4A8;
        int64_t qword4B0;
        int64_t qword4B8;
        int64_t qword4C0;
        int64_t qword4C8;
        int64_t qword4D0;
        int64_t qword4D8;
        int64_t qword4E0;
        int64_t qword4E8;
        int64_t qword4F0;
        int64_t qword4F8;
        int64_t qword500;
        hh::needle::NeedleRefcountObject *phh__needle__needlerefcountobject508;
        int8_t gap510[16];
        int64_t qword520;
        int64_t qword528;
        int64_t qword530;
        int64_t qword538;
        int64_t qword540;
        int64_t qword548;
        int64_t qword550;
        int64_t qword558;
        int8_t gap560[8];
        int64_t qword568;
        int64_t qword570;
        int64_t qword578;
        int64_t qword580;
        int64_t qword588;
        int64_t qword590;
        int32_t dword598;
        int8_t gap59C[4];
        int64_t qword5A0;
        int64_t qword5A8;
        int32_t dword5B0;
        int8_t gap5B4[4];
        int64_t qword5B8;
        int8_t gap5C0[32];
        int64_t qword5E0;
        int64_t qword5E8;
        int64_t qword5F0;
        int64_t qword5F8;
        int64_t qword600;
        int64_t qword608;
        int64_t qword610;
        int64_t qword618;
        int64_t qword620;
        int64_t qword628;
        int16_t word630;
        int8_t byte632;
        __declspec(align(2)) int32_t dword634;
        int8_t gap638[8];
        int64_t qword640;
        int64_t qword648;
        int64_t qword650;
        int64_t qword658;
        int32_t dword660;
        int64_t qword664;
        int32_t dword66C;
        int32_t dword670;
        int8_t gap674[4];
        int64_t qword678;
        int64_t qword680;
        int64_t qword688;
        hh::needle::NeedleRefcountObject *phh__needle__needlerefcountobject690;
        int8_t gap698[16];
        int64_t qword6A8;
        int64_t qword6B0;
        int64_t qword6B8;
        int64_t qword6C0;
        int64_t qword6C8;
        int32_t dword6D0;
        csl::ut::MoveArray<int64_t> qword6D8;
        int64_t qword6F8;
        int32_t dword700;
        int32_t dword704;
        int16_t word708;
        int8_t gap70A[6];
        csl::ut::MoveArray<int64_t> qword710;
        csl::ut::MoveArray<int64_t> qword730;
        int64_t qword750;
        int64_t qword758;
        int8_t gap760[240];
        int64_t qword850;
        int64_t qword858;
        int64_t qword860;
        int64_t qword868;
        int64_t qword870;
        int64_t qword878;
        int32_t dword880;

        //virtual ~NeedleRefcountObject() override;
        //DensityContainer(csl::fnd::IAllocator* allocator, )
    };

    class SCDent : public SceneContext {
    public:
        class Impl : public NeedleRefcountObject {
            SCDent& sceneContext;
            DensityContainer* densityContainer;
            uint64_t qword20;
            csl::math::Vector4 qword30;
            uint64_t qword40;
            uint64_t qword48;
            uint64_t qword50;
            uint64_t qword58;
            uint64_t qword60;
            uint64_t qword68;
            uint64_t qword70;
            uint32_t dword78;

        public:
            Impl(SCDent& sceneContext);
        };

        intrusive_ptr<Impl> implementation;

        SCENECONTEXT_CLASS_DECLARATION(SCDent);

        virtual void Initialize(const InitializeInfo& initializeInfo);
        virtual void UnkFunc1();
        virtual unsigned int GetNameHash();
        virtual const char* GetName();
        virtual uint64_t UnkFunc7();
        virtual DensityContainer* GetDensityContainer();
        virtual uint64_t UnkFunc9();
        virtual uint64_t UnkFunc10();
        virtual uint64_t UnkFunc11();
        virtual uint64_t UnkFunc12();
    };
}
