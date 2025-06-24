#pragma once

namespace app::dv{
    class DvElementQTE : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class QTEType : unsigned int {
                PRESS_PROMPT,
                MASH,
                RED_CIRCLE,
                THE_END_VARIANT,
                NONE
            };

            enum class QTEButton : unsigned int {
                A,
                B,
                X,
                Y,
                LB_RB,
                LB,
                RB,
                MASH_A,
                MASH_B,
                MASH_X,
                MASH_Y,
                MASH_LB_RB,
                MASH_LB,
                MASH_RB,
                X_LEFTRIGHT,
                X_LEFTRIGHT_ALT,
                RB_ALT
            };

            QTEType qteType;
            QTEButton qteButton;
            float redCircleSize;
            float redCircleThickness;
            float whiteLineThickness;
            float whiteLineSpeed;
            float multiplier;
            float redCircleOutlineThickness;
            float whiteLineOutlineThickness;
            int failCount;
            int mashCount;
            char asmVarName[64];
            float start;
            float end;
            float speedMultiplier;
            csl::math::Vector2 offset;
            float unk5;
            char unk6[192];
            char soundCueName[64];
        };

        char unk0[256];
        int currentFrame;
        int unk2;

        virtual void Update(int currentFrame, csl::math::Transform& transform) override;
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementQTE)
    };
}
