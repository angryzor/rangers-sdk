#pragma once

namespace app::gfx{
    class GeometryInstanceManager : public hh::game::GameService {
    public:
        struct UnkStr{
            hh::gfx::ResModel* resource;
            int64_t unk0;
            char gap10[120];
            const char* name;
            bool useCustomName;
        };

        csl::ut::MoveArray<int64_t> unk0; //unsure

        virtual void* GetRuntimeTypeInfo() const override;
		virtual void OnAddedToGame() override;
		virtual void OnRemovedFromGame() override;

        void UnkFunc(UnkStr& unkStr, hh::fnd::Handle<GeometryInstance>& geometryInstance);

        GAMESERVICE_CLASS_DECLARATION(GeometryInstanceManager)
    };
}
