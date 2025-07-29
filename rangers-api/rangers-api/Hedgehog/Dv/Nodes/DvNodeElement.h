#pragma once

#define DV_ELEMENT_DECLARATION_BASE(ClassName)public:\
        ClassName(csl::fnd::IAllocator* allocator);\
		static hh::dv::DvElementBase* Create(hh::dv::DvNodeElement* baseNode, csl::fnd::IAllocator* allocator);

namespace hh::dv{
    class DvNodeElement;
    class DvStandardCharacter;

    class DvElementBase : public hh::fnd::ReferencedObject {
    public:
        struct Description {};

        DvNodeElement* baseNode;

        DvElementBase(csl::fnd::IAllocator* allocator);

        virtual void Update(int currentFrame, csl::math::Transform& transform) {};
        virtual bool AddCallback(int currentFrame, csl::math::Transform& transform) { return true; };
        virtual void RemoveCallback() {};
        virtual void SetData(void* data) {};
        virtual void DeleteData() {};
        virtual bool IsInitialized() { return true; };
        virtual void UnkUpdate(int currentFrame, csl::math::Transform& transform) {};

        game::GameService* GetService(const game::GameServiceClass* gameServiceClass);
        template<typename T>
		T* GetService() {
			return static_cast<T*>(GetService(T::GetClass()));
		}
        DvSceneControl* GetDvSceneControl();
        float CalculateCurrentCurve(int dataSize, int currentFrame, float* data);
        float CalculateCurrentCurve(int dataSize, int currentFrame, float* data, int unk);
        DvStandardCharacter* GetParentCharacterObject() const;
        game::GameManager* GetGameManager() const;
    };

    class DvNodeElement : public DvNodeBase {
    public:
        enum class ElementID : unsigned int {
            CAMERA_PARAMS = 1,
            // 2 = Empty, nothing
            DRAW_OFF = 3,
            // 4 = Empty, nothing
            PATH_OFFSET = 5,
            CAMERA_SHAKE = 6,
            CAMERA_SHAKE_LOOP = 7,
            EFFECT = 8,
            DIRECTIONAL_LIGHT = 9,
            PATH_INTERPOLATION = 10,
            CULLING_DISABLE = 11,
            CAMERA_NEAR_FAR = 12,
            UV_ANIM = 13,
            VISIBILITY_ANIM = 14,
            MATERIAL_ANIM = 15,
            MULTIPLE_ANIM = 16,
            CAMERA_OFFSET = 17,
            MODEL_FADE = 18,
            DEBUG_MOTION = 19,
            CAMERA_HEDGEHOG = 20,
            CAMERA_IN_GAME = 21,
            POINT_LIGHT = 22,
            VERTEX_ANIMATION_TEXTURE = 23,
            SPOTLIGHT = 24,
            CONTROLLER_VIBRATION = 25,
            SPOTLIGHT_MODEL = 26,
        
            BLOOM_PARAM = 1000,
            DOF_PARAM = 1001,
            COLOR_CONTRAST = 1002,
            CAMERA_CONTROL_PARAM = 1003,
            SHADOW_RESOLUTION = 1004,
            GODRAY_PARAM = 1005,
            ATMOSPHERE_GODRAY_PARAM = 1006,
            ATMOSPHERE_HEIGHT_FOG_PARAM = 1007,
            CHROMATIC_ABERRATION_FILTER_PARAM = 1008,
            VIGNETTE_PARAM = 1009,
            FADE = 1010,
            LETTER_BOX = 1011,
            MODEL_CLIPPING = 1012,
            PBA_RESET = 1013,
            BOSS_NAME = 1014,
            CAPTION = 1015,
            SOUND = 1016,
            TIME = 1017,
            SUN = 1018,
            LOOK_AT_IK = 1019,
            CAMERA_BLUR_PARAM = 1020,
            GENERAL_TRIGGER = 1021,
            FOOT_IK = 1022,
            DITHER_PARAM = 1023,
            QTE = 1024,
            FACIAL_ANIMATION = 1025,
            OVERRIDE_ASM = 1026,
            AURA = 1027,
            CHANGE_TIME_SCALE = 1028,
            CYBER_SPACE_NOISE = 1029,
            LIP_ANIMATION = 1030,
            AURA_ROAD = 1031,
            MOVIE_VIEW = 1032,
            CROSS_FADE = 1033,
            WEATHER = 1034,
            SHADOW_MAP_PARAM = 1035,
            VARIABLE_POINT_LIGHT = 1036,
            OPENING_LOGO = 1037,
            DENSITY_SECTOR_POINT = 1038,
            FX_COL_UPDATE = 1039,
            VAT = 1040,
            QTE_ACCEL = 1041,
            THE_END_CABLE_OBJECT = 1042,
            RIFLE_BEAST_LIGHTING = 1043
        };

        enum class PlayType : uint32_t{
            NORMAL,
            ONESHOT,
            ALWAYS
        };

        enum class UpdateTiming : uint32_t{
            ON_EXEC_PATH,
            ON_PRE_UPDATE,
            CHARACTER_FIX_POSTURE,
            ON_POST_UPDATE_CHARACTER,
            ON_UPDATE_POS,
            ON_FIX_BONE_POSTURE,
            ON_EVALUATE_DETAIL_MOTION,
            CHARACTER_JOB_UPDATE,
            MODIFY_POSE_AFTER,
            JOB_REGISTER,
            MOTION_UPDATE
        };

        struct DescriptionBase : DvNodeBase::Description {
            enum class Flags : unsigned char {
                UNK0,
                LOOSE_LENGTH
            };

            ElementID elementId;
            float start;
            float end;
            int unk1;
            csl::ut::Bitset<Flags> flags;
            PlayType playType;
            UpdateTiming updateTiming;
            int padding;
        };

        template<typename ElementDesc = DvElementBase::Description>
        struct Description : DescriptionBase {
            ElementDesc elementDescription;
        };

        int isActive;
        DescriptionBase binaryData;
        int unk0;
        hh::fnd::Reference<DvElementBase> element;
        int start;
        int end;

        virtual void Setup(DvNodeBase::Description& description) override;
        virtual void Start() override;
        virtual void Update(int currentFrame) override;
        virtual void PreStepUpdate(int currentFrame) override;
        virtual bool IsInitialized() override;
        virtual int GetUpdateTiming() override;
        virtual void UnkUpdate(int currentFrame, csl::math::Transform& transform) override;

        static const void** elementBaseCreateFuncs[27];

        DV_NODE_DECLARATION_BASE(DvNodeElement)
    };
}
