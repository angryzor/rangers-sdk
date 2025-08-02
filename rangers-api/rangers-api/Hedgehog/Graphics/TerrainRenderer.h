#pragma once

namespace hh::gfx{
    class TerrainRenderer : public hh::fnd::ReferencedObject {
    public:
        class Listener : public hh::needle::ClipMapRenderer::Listener{
        public:
            virtual void CMRL_UnkFunc0() override {}
        };

        class RenderManagerListener : public hh::needle::NeedleRefcountObject, public hh::needle::RenderManager::Listener{
        public:
            virtual void RML_UnkFunc0() override {}
            virtual void RML_UnkFunc1() override {}
        };

        struct UnkStr0{
            int64_t unk0;
            int64_t unk1;
            int64_t unk2;
            int64_t unk3;
            int64_t unk4;
            int64_t unk5;
        };

        hh::needle::ParameterValueObject* unk0;
        void* unk1; //shadercontainer
        void* unk2; //shadercontainer
        void* unk3;
        hh::needle::ClipMapRenderer clipMapRenderer; // 0x143a1ab10
        VirtualTexture* unk4;
        PageIndexer* unk5;
        csl::ut::MoveArray<int> unk6;
        void* unkFuncPtr0;
        void* unkFuncPtr1;
        void* unkFuncPtr2;
        char unk7;
        RenderManagerListener* unk8;
        UnkStr0 unk9[3];
        int64_t unk10;
        int64_t unk11;
        csl::math::Vector3 cameraPosition;
        Listener listener;
        int64_t unk12;
        int unk13;
    };
}
