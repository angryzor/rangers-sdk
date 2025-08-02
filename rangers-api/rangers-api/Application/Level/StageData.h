#pragma once

namespace app::level {
    class StageData : hh::fnd::ReferencedObject {
    public:
        enum class ChunkType : uint8_t {
            INITIAL = 0,
            AFTER = 1,
        };

        enum class AttributeFlags : uint64_t
        {
            CYBER = 1,
            MINIGAME = 2,
            HACKING = 3,
            LAST_BOSS = 4,
            MASTER_TRIAL = 5,
            TUTORIAL = 6,
            NAVMESH = 8,
            HEIGHT_FIELD = 9,
            POINT_CLOUD = 10,
            AUTOSAVE = 11,
            DIVING = 13,
            SIDE_STEP = 14,
            ATHLETIC = 15,
            BOARDING = 16,
            DRIFT = 17,
            SIDE_VIEW = 18,
            LAVA = 19,
            SONIC = 20,
            TAILS = 21,
            AMY = 22,
            KNUCKLES = 23,
            BATTLE_RUSH = 24,
            BOSS_RUSH = 25,
            EXTRA = 26,
            DELETE_FALL_DEAD_COLLISION = 27,
            DELETE_AIR_WALL_COLLISION = 28,
            DELETE_GRIND_RAIL = 29,
            CHANGE_NEW_COLLISION = 30,
            RESTRICT_DEBRIS = 31,
            SPECIAL_PARRY_EFFECT = 32,
        };

        enum class CyberMode : uint8_t
        {
            UNKNOWN = 0,
            LOW_GRAVITY = 1,
            TIME_EXTEND = 2,
            SPEED_SCALE = 3,
            NITRO = 4,
            MAX_SPEED_CHALLENGE = 5,
        };

        enum class MissionFlags : uint64_t
        {
            GOAL = 1,
            RANK = 2,
            RING = 4,
            RED_RING = 5,
            NUMBER_RING = 6,
            SILVER_MOON_RING = 7,
            HIDE_GOAL = 8,
            SHADOW_TAILS = 9,
            MINE = 10,
            ANIMAL = 11,
        };

        csl::ut::String name;
        csl::ut::String stage;
        csl::ut::String sceneParamName;
        csl::ut::String sceneParamStage;
        csl::ut::String geditResourceName;
        csl::ut::String cyberName;
		int stageIndex;
		int cyberStageIndex;
		int worldIndex;
		unsigned int defaultSceneParamIndex;
		csl::ut::Bitset<AttributeFlags> attributeFlags;
		csl::ut::Bitset<MissionFlags> missionFlags;
		csl::ut::MoveArray<uint8_t> staticSectors;
		csl::ut::MoveArray<uint8_t> dynamicSectors;
		ChunkType chunkType;
		float timeLimit;
		float deathPlaneHeight;
		float noiseTime;
		uint32_t unk6;
		uint8_t redRingMissionThreshold[4];
		uint8_t unk7;
        uint32_t ringMissionThreshold;
        CyberMode cyberMode;
		unsigned int rankTimes[4];
		unsigned int rankTimesVeryHard[4];
		unsigned int rankTimesChallenge[4];
		unsigned int rankTimesChallengeAll[4];
    
        static StageData* Create(csl::fnd::IAllocator* allocator);
        StageData(csl::fnd::IAllocator* allocator);

        // returns value of `stage` if cyber stage, `name` if other stage
        const char* GetStageName() const;

        inline const char* GetName() const {
            return name.c_str();
        }

        bool IsNonBossStage() const;

        unsigned int GetStageIndex() const;
    };
}
