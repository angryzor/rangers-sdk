#pragma once

namespace app::dv{
    class DvTheEndCableObject : public hh::game::GameObject{
    public:
        enum class Flags : unsigned char{
            ENABLED,
            PLUG_ENABLED
        };

        hh::fnd::Handle<hh::gfx::GOCVisualModel> targetVisual;
        hh::gfx::GOCVisualModel* plugVisual;
        hh::gfx::GOCVisualUserModel* cableVisual;
        hh::game::GOComponent* gocLineGeometrize;
        csl::ut::MoveArray<int> effNodeIndices;
        unsigned int visualType;
        csl::ut::Bitset<Flags> flags;

        virtual void* GetRuntimeTypeInfo() const override;
        virtual void AddCallback(hh::game::GameManager* gameManager) override;
        virtual void UpdateAsync(hh::fnd::UpdatingPhase phase, const hh::fnd::SUpdateInfo& updateInfo, void* unkParam) override;

        void Initialize(hh::gfx::GOCVisualModel* targetVisual);

        static const char** plugModelNames[2];
        static const char** plugSkeletonNames[2];
        static const char** cableModelNames[2];

        GAMEOBJECT_CLASS_DECLARATION_INLINE_GET_CLASS(DvTheEndCableObject)
    };
}
