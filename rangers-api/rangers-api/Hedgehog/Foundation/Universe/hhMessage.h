#pragma once

namespace hh::fnd
{
	enum class MessageID : uint32_t {
		TRIGGER_ENTER = 512,
		TRIGGER_LEAVE = 513,
		TRIGGER_STAY = 514,
		UPDATE_SET_EDITOR = 768,
		UPDATE_ACTIVE_OBJECT_IN_EDITOR = 769,
		START_ACTIVE_OBJECT_IN_EDITOR = 770,
		FINISH_ACTIVE_OBJECT_IN_EDITOR = 771,
		PARAM_CHANGED_IN_EDITOR = 772,
		GET_DEBUG_COMMENT_IN_EDITOR = 773,
		PUSH_CAMERA_CONTROLLER = 4097,
		POP_CAMERA_CONTROLLER = 4098,
		ACTION_MODE_END = 8194,
		ACTION_MODE_START = 8195,
		ACTIVATE_CY_ACTION = 8196,
		ACTIVATE_CY_BLASTER = 8197,
		ACTIVATE_CYLOOP_ACTION = 8198,
		ADD_ACTION_CHAIN_SCORE = 8199,
		ADD_GAME_TIME = 8200,
		ADD_NOTIFY_PRE_DEAD_LISTENER = 8201,
		ADD_QUICK_CYLOOP_GAUGE = 8202,
		ADD_SCORE_VISIBLE = 8203,
		ADVANCE_SEQUENCE = 8205,
		ALIVE_ENEMY_NUM = 8206,
		ALLOW_PUZZLE_BLOCK_ACTION_ON_CYLOOP = 8207,
		ALL_REMOVE_SILVER_MOON_RING = 8208,
		ANOTHER_QUEST_START = 8209,
		AQUABALL_CAPTURE_END = 8210,
		AQUABALL_CAPTURE_START = 8211,
		AQUABALL_DEAD = 8212,
		ATTACK_GROUND_BULLET = 8213,
		AUTO_SEQUENCE = 8216,
		BAKE_NAV_MESH = 8219,
		BATTLE_RUSH_DEFEAT_ENEMY = 8222,
		BEE_DAMAGE = 8223,
		BEGIN_AURA_EFFECT = 8225,
		BEGIN_BATTER_BOX = 8230,
		BEGIN_BATTLE = 8231,
		BEGIN_BATTLE_MINI_BOSS = 8232,
		BEGIN_BLOCKAGE = 8233,
		BEGIN_BOSS_BATTLE = 8234,
		BEGIN_BOSS_BATTLE_CLIMB = 8235,
		BEGIN_BOSS_BIT = 8236,
		BEGIN_BOSS_BIT_WAVE = 8237,
		BEGIN_BOSS_EVENT = 8239,
		BEGIN_BOSS_QTE = 8240,
		BEGIN_BOSS_RING_SUPPLY = 8241,
		BEGIN_CARRY_ANIMAL = 8242,
		BEGIN_CY_BLASTER_LIFT_INFO = 8244,
		BEGINED_BOSS_BATTLE = 8247,
		BEGIN_EVENT_GIMMICK_PREVIEW = 8248,
		BEGIN_HIT_STOP = 8253,
		BEGIN_HIT_STOP_BY_NAME = 8254,
		BEGIN_PAUSE_GAME = 8258,
		BEGIN_PRACTICE_COMBO = 8260,
		BEGIN_PRACTICE_GUIDE = 8261,
		BEGIN_PRACTICE_TIMER = 8263,
		BEGIN_REFLEXES_PANEL = 8266,
		BEGIN_STORM = 8270,
		BEGIN_WATER_FALL = 8274,
		BOMB_BOX_DAMAGE = 8279,
		BOOST_LIMITED_2D_MOVE = 8281,
		BOSS_ARENA_COLLISION_ENABLE = 8282,
		BOSS_BIT_ACTIVE = 8284,
		BOSS_BIT_BEGIN_FLY_MOVE = 8285,
		BOSS_BIT_BEGIN_OVERLOOKING = 8286,
		BOSS_BIT_BEGIN_WAVE_AREA_ROTATION = 8287,
		BOSS_BIT_BREAKED = 8288,
		BOSS_BIT_DEBUG_DRAW = 8289,
		BOSS_BIT_END_FLY_MOVE = 8290,
		BOSS_BIT_END_OVERLOOKING = 8291,
		BOSS_BIT_END_WAVE_AREA_ROTATION = 8292,
		BOSS_BIT_FORMATION_CHANGE = 8293,
		BOSS_BIT_INFO = 8294,
		BOSS_BIT_LASER_DISABLE = 8295,
		BOSS_BIT_LASER_RESET = 8296,
		BOSS_BIT_VISIBLE = 8297,
		BOSS_RIFLEBEAST_GET_CABLE_STATUS = 8337,
		CAMERA_OFF = 8353,
		CAMERA_ON = 8354,
		CAMERA_ZOOM_END = 8366,
		CHALLENGE_GET_CLEAR = 8380,
		CHALLENGE_SET_CLEAR = 8381,
		CHANGE_GLOBAL_TIME_SCALE = 8387,
		CHANGE_LAYER_TIME_SCALE = 8388,
		CHANGE_PLAYER_CHARACTER = 8392,
		CHARACTER_RESET_LOOK_AT = 8401,
		CHARACTER_SET_LOOK_AT = 8402,
		CLEAR_ISLAND = 8404,
		DAMAGE = 8428,
		DEAD = 8429,
		DEAD_TUTORIAL_ENEMY = 8430,
		DEBUG_NOTIFY_WARP = 8441,
		DEBUG_SET_PLAYER_POSITION = 8443,
		DEV_MENU_RESULT = 8453,
		DV_GENERAL_TRIGGER = 8462,
		DV_QTE = 8463,
		EARN_EXP_POINT = 8464,
		END_BOSS_EVENT = 8485,
		BEGIN_BOSS_SUBRING = 8487,
		END_EVENT_GIMMICK_PREVIEW = 8495,
		END_FREE_CAMERA = 8499,
		END_HIT_STOP = 8502,
		END_OUT_OF_CONTROL = 8509,
		END_PAUSE_GAME = 8510,
		END_PRACTICE_COMBO = 8511,
		END_PRACTICE_GUIDE = 8512,
		END_PRACTICE_NOTIFIER = 8513,
		END_PRACTICE_TIMER = 8514,
		END_TIME_GIMMICK = 8529,
		ENEMY_RESUME = 8537,
		EVENT_MENU = 8548,
		EXIT_EVENT_MENU = 8554,
		GET_CYLOOP_POINT = 8587,
		GET_HOMING_TARGET_INFO = 8592,
		GET_PRACTICE_TIMER = 8606,
		GET_SLIDER_INFO = 8612,
		GOAL = 8640,
		GOTO_BATTLE_RUSH_ALL = 8642,
		GOTO_BOSS_RUSH = 8643,
		GOTO_CYBER_STAGE_CHALLENGE = 8644,
		GOTO_STAGE = 8645,
		HOLD_ON = 8666,
		HOLD_RELEASE = 8667,
		IS_TAKE_RED_RING = 8676,
		LOSS_RING = 8704,
		LOST_EXP_POINT = 8706,
		NOTIFY_ACTION = 8748,
		NOTIFY_EARN_EXP_POINT = 8760,
		NOTIFY_EARN_EXP_POINT_ANIMATION = 8763,
		NOTIFY_END_FALL_CYBERSPACE = 8765,
		NOTIFY_END_HIT_STOP = 8767,
		NOTIFY_LEVEL_STATUS = 8779,
		NOTIFY_PAUSE_ACTION_CHAIN = 8783,
		NOTIFY_RETRY = 8788,
		NOTIFY_TUTORIAL_PRACTICE_NOTIFIER = 8802,
		NOTIFY_UPDATE_DESTINATION_MARKER = 8803,
		NOTIFY_UPDATE_DISPLAY_INFO = 8804,
		NOTIFY_UPDATE_OPTION = 8805,
		NOTIFY_UPDATE_SKILL = 8806,
		NOTIFY_UPDATE_STATUS = 8807,
		NOTIFY_USE_SKILL_POINT = 8809,
		OBJECT_LAYER_ENABLED = 8811,
		PASS_POINT_MARKER = 8823,
		PAUSE_ENEMY = 8825,
		PHOTO_MODE_END = 8827,
		PHOTO_MODE_START = 8828,
		PLAYER_PAUSE_SE = 8836,
		PLAYER_VISIBILITY = 8838,
		PLAY_STAFF_ROLL = 8841,
		PREPARE_PRACTICE_TIMER = 8845,
		PREVIEW_EVENT = 8847,
		RELEASE_MAP = 8872,
		RESET_DESTINATION_MARKER_INVISIBLE = 8899,
		RESET_LAYER_TIME_SCALE = 8901,
		RESTART_SHUTDOWN = 8909,
		RESUME_WORLD = 8911,
		RETURN_TO_TITLE = 8914,
		REVERT_GLOBAL_TIME_SCALE = 8915,
		REVERT_LAYER_TIME_SCALE = 8916,
		SCRIPT_CHANGE_MOTION = 8929,
		SCRIPT_EXIT = 8930,
		SCRIPT_SELECT_BOX_RESULT = 8931,
		SET_BATTLE_RUSH_PAUSED = 8934,
		SET_DEADLINE_IGNORE_TIME = 8940,
		SET_DEADLINE_LATER = 8941,
		SET_DESTINATION_MARKER_INVISIBLE = 8942,
		SET_MAP_FAST_TRAVEL_ENABLED = 8946,
		SET_MENU_ENABLED = 8947,
		SET_MENU_LIMITED_ENABLED = 8948,
		START_FREE_CAMERA = 9001,
		START_TIME_GIMMICK = 9014,
		SUSPEND_WORLD = 9042,
		TIME_UP = 9072,
		TRANSIT_BOSS_RUSH_STAGE = 9079,
		TRANSIT_CYBER_STAGE = 9080,
		TRANSIT_EXTRA_ISLAND_STAGE = 9081,
		TRANSIT_HACKING_STAGE = 9083,
		TRANSIT_ISLAND_STAGE = 9084,
		TRANSIT_MASTER_TRIAL_STAGE = 9085,
		TRANSIT_MENU = 9086,
		TRANSIT_PRACTICE_SPACE = 9087,
		UI_CAMERA_INFO = 9117,
		UI_CAUTION_NAVIGATION_IN = 9118,
		UI_CHANGE_PLAYER_CHARACTER = 9120,
		UI_EVENT_PAUSED = 9132,
		UI_NOTIFY_CAMERA_CONTROL = 9186,
		UI_PAUSE_RESULT = 9198,
		UI_SET_GAME_COCKPIT_VISIBILITY = 9223,
		UI_TIMING_GAUGE_BEGIN = 9224,
		UI_TIMING_GAUGE_END = 9245,
		UI_TIMING_GAUGE_RESET = 9246,
		UI_TIMING_GAUGE_RESUME = 9248,
		UI_TIMING_GAUGE_STOP = 9249,
		UPDATE_PRACTICE_COMBO = 9256,
		UPDATE_PRACTICE_GUIDE = 9257,
		UPDATE_PRACTICE_TIMER = 9258,
		WIND_VOLUME = 9278,
	};

	class Messenger;
	class MessageAsyncHandler;
	class Message
	{
	public:
		MessageID ID{};
		Handle<Messenger> Sender{};
		Handle<Messenger> Receiver{};
		char Handled{};
		bool Broadcasted{};
		uint32_t Mask{ (uint32_t)-1 };

		Message(MessageID in_id);

		virtual MessageAsyncHandler* CreateAsyncHandler(csl::fnd::IAllocator* allocator);
		virtual ~Message() = default;

		inline static void* operator new(size_t count) {
			return AllocateObjectGlobalMemory(count);
		}
		
		inline static void operator delete(void* ptr) noexcept {
			FreeObjectGlobalMemory(ptr);
		}
	};

	class MessageAsyncHandler : public ReferencedObject
	{
		Message& message;
		uint8_t unk1{};

	public:
		MessageAsyncHandler(csl::fnd::IAllocator* allocator, Message& message) : ReferencedObject{ allocator, true }, message{ message } {}

		inline Message& GetMessage() const {
			return message;
		}

		template<typename T>
		T& GetMessage() const {
			return static_cast<T&>(GetMessage());
		}
	};

	template <typename T>
	class MessageAsyncHandlerInplace : public MessageAsyncHandler
	{
		T messageInPlace;

	public:
		inline MessageAsyncHandlerInplace(csl::fnd::IAllocator* allocator, const T& message) : messageInPlace{ message }, MessageAsyncHandler { allocator, messageInPlace } {}
	};
}
