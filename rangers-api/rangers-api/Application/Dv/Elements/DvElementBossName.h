#pragma once

namespace app::dv{
    class DvElementBossName : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class BossID : unsigned int {
                GIANT,
                DRAGON,
                KNIGHT,
                RIFLE,
                THEEND,
                RIFLEBEAST
            };

            int unk0;
            BossID bossId;
        };

        hh::fnd::Reference<hh::game::GameObject> uiBossNameObject;

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementBossName)
    };
}
