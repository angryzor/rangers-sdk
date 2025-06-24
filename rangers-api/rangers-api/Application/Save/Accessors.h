#pragma once

namespace app::save {
    class ActionChainLogAc : public SaveDataAccessor<ActionChainStruct> {
    public:

    };

    class CyberStageAc : public SaveDataAccessor<CyberStageData> {
    public:
        // Might be a specific flag accessor. It adds 2 to the index.
        bool GetFlag(unsigned char idx) const;
    };

    class CyberStageContainerAc : public SaveDataAccessor<CyberStageContainerData> {
    public:
        CyberStageAc GetCyberStageAc(unsigned int stageNo);
    };

    class ArcadeDataAc : public SaveDataAccessor<ArcadeData> {
    public:
        CyberStageContainerAc GetCyberStageContainerAc();
    };

    class ChallengeBattleRushContainerDataAc : public SaveDataAccessor<ChallengeBattleRushContainerData> {
    public:

    };

    class ChallengeBattleRushDataAc : public SaveDataAccessor<ChallengeBattleRushData> {
    public:

    };

    class ChallengeCyberStageContainerDataAc : public SaveDataAccessor<ChallengeCyberStageContainerData> {
    public:

    };

    class ChallengeCyberStageDataAc : public SaveDataAccessor<ChallengeCyberStageData> {
    public:

    };

    class ChallengeDataAc : public SaveDataAccessor<ChallengeData> {
    public:

    };

    class CharacterAc : public SaveDataAccessor<CharacterData> {
    public:

    };

    class ExtraCharacterAc : public SaveDataAccessor<ExtraCharacterData> {
    public:

    };

    class ExtraCharacterContainerAc : public SaveDataAccessor<ExtraCharacterContainerData> {
    public:

    };

    class ExtraCyberStageContainerAc : public SaveDataAccessor<ExtraCyberStageContainerData> {
    public:

    };

    class ExtraFlagAc : public SaveDataAccessor<ExtraFlagData> {
    public:

    };

    class ExtraFlagContainerAc : public SaveDataAccessor<ExtraFlagContainerData> {
    public:

    };

    class ExtraIslandStageContainerAc : public SaveDataAccessor<ExtraIslandStageContainerData> {
    public:

    };

    class FlagContainerAc : public SaveDataAccessor<FlagContainerData> {
    public:

    };

    class GameDataAc : public SaveDataAccessor<GameData> {
    public:
        FlagContainerAc GetFlagContainerAc();
    };

    class GamePlayAc : public SaveDataAccessor<GamePlayData> {
    public:

    };

    class HeaderAc : public SaveDataAccessor<HeaderData> {
    public:

    };

    class IslandStageAc : public SaveDataAccessor<IslandStageData> {
    public:

    };

    class IslandStageContainerAc : public SaveDataAccessor<IslandStageContainerData> {
    public:

    };

    class OptionAudioAc : public SaveDataAccessor<OptionAudioData> {
    public:
        unsigned char GetMasterVolume() const;
        unsigned char GetSfxVolume() const;
        unsigned char GetMusicVolume() const;
        unsigned char GetVoiceVolume() const;
        app::save::OptionAudioData::MusicSelect GetMusicSelectEnable() const;
        app::save::OptionAudioData::MusicSelectType GetMusicSelectType() const;
        bool GetBoostAisac() const; // == flag 0
    };

    class OptionCameraAc : public SaveDataAccessor<OptionCameraData> {
    public:

    };

    class OptionControlsAc : public SaveDataAccessor<OptionControlsData> {
    public:

    };

    class OptionGamePlayAc : public SaveDataAccessor<OptionGamePlayData> {
    public:

    };

    class OptionGraphicsAc : public SaveDataAccessor<OptionGraphicsData> {
    public:

    };

    class OptionAc : public SaveDataAccessor<OptionData> {
    public:
        OptionAudioAc GetOptionAudioAc();
        OptionCameraAc GetOptionCameraAc();
        OptionControlsAc GetOptionControlsAc();
        OptionGamePlayAc GetOptionGamePlayAc();
        OptionGraphicsAc GetOptionGraphicsAc();
    };

    class PlayLogAc : public SaveDataAccessor<PlayLogData> {
    public:

    };

    class WeatherAc : public SaveDataAccessor<WeatherData> {
    public:

    };

    class WorldFlagAc : public SaveDataAccessor<WorldFlagData> {
    public:

    };

    class WorldFlagContainerAc : public SaveDataAccessor<WorldFlagContainerData> {
    public:

    };

}
