#pragma once

namespace app::dv{
    class DvElementCaption : public AppDvElementBase{
    public:
        struct Description : hh::dv::DvElementBase::Description {
        public:
            enum class LanguageID : unsigned int {
                ENGLISH,
                FRENCH,
                ITALIAN,
                GERMAN,
                SPANISH,
                POLISH,
                PORTUGUESE,
                RUSSIAN,
                JAPANESE,
                CHINESE,
                CHINESE_SIMPLIFIED,
                KOREAN
            };

            char converseName[16];
            LanguageID languageId;
            int unk0;
        };

        int unk0; // adds +1 whenver it appears

        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) override;
        virtual void RemoveCallback() override;

        APP_DV_ELEMENT_DECLARATION_BASE(DvElementCaption)
    };
}
