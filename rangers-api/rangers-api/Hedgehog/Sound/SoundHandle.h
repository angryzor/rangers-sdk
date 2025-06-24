#pragma once

enum CriAtomExParameterIdTag {
    CRIATOMEX_PARAMETER_ID_VOLUME = 0,
    CRIATOMEX_PARAMETER_ID_PITCH = 1,
    CRIATOMEX_PARAMETER_ID_PAN3D_ANGLE = 2,
    CRIATOMEX_PARAMETER_ID_PAN3D_DISTANCE = 3,
    CRIATOMEX_PARAMETER_ID_PAN3D_VOLUME = 4,
    CRIATOMEX_PARAMETER_ID_PAN_TYPE = 5,
    CRIATOMEX_PARAMETER_ID_PAN_SPEAKER_TYPE = 6,
    CRIATOMEX_PARAMETER_ID_PAN_CH0 = 7,
    CRIATOMEX_PARAMETER_ID_PAN_CH1 = 8,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_0 = 9,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_1 = 10,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_2 = 11,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_3 = 12,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_4 = 13,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_5 = 14,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_6 = 15,
    CRIATOMEX_PARAMETER_ID_BUS_SEND_LEVEL_7 = 16,
    CRIATOMEX_PARAMETER_ID_BANDPASS_FILTER_COF_LOW = 17,
    CRIATOMEX_PARAMETER_ID_BANDPASS_FILTER_COF_HIGH = 18,
    CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_TYPE = 19,
    CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_FREQ = 20,
    CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_Q = 21,
    CRIATOMEX_PARAMETER_ID_BIQUAD_FILTER_GAIN = 22,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_ATTACK_TIME = 23,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_HOLD_TIME = 24,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_DECAY_TIME = 25,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_RELEASE_TIME = 26,
    CRIATOMEX_PARAMETER_ID_ENVELOPE_SUSTAIN_LEVEL = 27,
    CRIATOMEX_PARAMETER_ID_START_TIME = 28,
    CRIATOMEX_PARAMETER_ID_PRIORITY = 31,
    CRIATOMEX_PARAMETER_ID_SILENT_MODE = 32,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_0 = 33,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_1 = 34,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_2 = 35,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_3 = 36,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_4 = 37,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_5 = 38,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_6 = 39,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_7 = 40,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_8 = 41,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_9 = 42,
    CRIATOMEX_PARAMETER_ID_DSP_PARAMETER_10 = 43,
    CRIATOMEX_PARAMETER_ID_DSP_BYPASS_FLAG = 44,
    CRIATOMEX_PARAMETER_ID_ENUM_SIZE_IS_4BYTES = 0x7FFFFFFF
};
#define CRIATOMEX_FORMAT_RAW_PCM 6
struct CriAtomExPlayerParameter{};
typedef CriAtomExPlayerParameter* CriAtomExPlayerParameterHn;

typedef int CriSint32;
typedef unsigned int CriUint32;
typedef unsigned char CriUint8;
typedef unsigned int CriBool;

void criAtomExPlayerParameter_SetParameterValue(CriAtomExPlayerParameterHn player_parameter, unsigned int id, unsigned int value);
void criAtomExPlayerParameter_SetParameterFloat32(CriAtomExPlayerParameterHn player_parameter, unsigned int id, float value);
void criAtomExPlayerParameter_SetParameterUint32(CriAtomExPlayerParameterHn player_parameter, unsigned int id, unsigned int value);
void criAtomExPlayerParameter_SetParameterSint32(CriAtomExPlayerParameterHn player_parameter, unsigned int id, int value);

typedef CriUint32 CriAtomExVoicePoolIdentifier;
typedef CriUint32 CriAtomExFormat;

enum CriAtomPcmFormat {
    CRIATOM_PCM_FORMAT_SINT16,
    CRIATOM_PCM_FORMAT_FLOAT32,
};

enum CriAtomExVoiceAllocationMethod {
    CRIATOMEX_ALLOCATE_VOICE_ONCE,
    CRIATOMEX_RETRY_VOICE_ALLOCATION,
};

enum CriAtomSoundRendererType {
    CRIATOM_SOUND_RENDERER_NATIVE,
    CRIATOM_SOUND_RENDERER_ASR,
    CRIATOM_SOUND_RENDERER_SPATIAL,
    CRIATOM_SOUND_RENDERER_HW1,
    CRIATOM_SOUND_RENDERER_HW2,
    CRIATOM_SOUND_RENDERER_HW3,
    CRIATOM_SOUND_RENDERER_HW4,
    CRIATOM_SOUND_RENDERER_HAPTIC,
    CRIATOM_SOUND_RENDERER_PSEUDO,
    CRIATOM_SOUND_RENDERER_SPATIAL_CHANNELS,
    CRIATOM_SOUND_RENDERER_AMBISONICS,
    CRIATOM_SOUND_RENDERER_PASSTHROUGH,
    CRIATOM_SOUND_RENDERER_OBJECT,
    CRIATOM_SOUND_RENDERER_ANY,
};

struct CriAtomExPlayerConfig {
    CriAtomExVoiceAllocationMethod voice_allocation_method;
    CriSint32 max_path_strings;
    CriSint32 max_path;
    CriUint8 max_aisacs;
    CriBool updates_time;
    CriBool enable_audio_synced_timer;
};

struct CriAtomRawPcmPlayerConfig {
    CriAtomPcmFormat pcm_format;
    CriSint32 max_channels;
    CriSint32 max_sampling_rate;
    CriAtomSoundRendererType sound_renderer_type;
    CriSint32 decode_latency;
    void* context;
};

struct CriAtomExRawPcmVoicePoolConfig {
    CriAtomExVoicePoolIdentifier identifier;
    CriSint32 num_voices;
    CriAtomRawPcmPlayerConfig player_config;
};

struct CriAtomExPlayer;
typedef CriAtomExPlayer* CriAtomExPlayerHn;
typedef CriAtomExPlayer* CriAtomPlayerHn;
typedef CriUint32 CriAtomExPlaybackId;
typedef void (*CriAtomExPlayerDataRequestCbFunc) (void *obj, CriAtomExPlaybackId id, CriAtomPlayerHn player);
struct CriAtomExPlayer{
    char pad1[200];
    CriAtomExFormat format;
    char pad1a[8];
    CriSint32 num_channels;
    char pad1b[4];
    CriSint32 sampling_rate;
    char pad1c[96];
    CriAtomExPlayerParameterHn parameter;
    char pad2[0x38];
    CriAtomExPlayerDataRequestCbFunc data_request_callback;
    void* data_request_callback_user_data;
};

//CriAtomExPlayerHn criAtomExPlayer_Create(const CriAtomExPlayerConfig* config, void* work, CriSint32 work_size);	
//inline void criAtomExPlayer_SetFormat(CriAtomExPlayerHn player, CriAtomExFormat format) {
//    criAtomEx_Lock();
//    player->format = format;
//    criAtomEx_Unlock();
//}
//
//inline void criAtomExPlayer_SetNumChannels(CriAtomExPlayerHn player, CriSint32 num_channels) {
//    criAtomEx_Lock();
//    player->num_channels = num_channels;
//    criAtomEx_Unlock();
//}
//
//inline void criAtomExPlayer_SetSamplingRate(CriAtomExPlayerHn player, CriSint32 sampling_rate) {
//    criAtomEx_Lock();
//    player->sampling_rate = sampling_rate;
//    criAtomEx_Unlock();
//}
//
//void criAtomExPlayer_SetVoicePoolIdentifier(CriAtomExPlayerHn player, CriAtomExVoicePoolIdentifier identifier);
//unsigned int criAtomExPlayer_GetParameterId(CriAtomExParameterIdTag id);
//inline void criAtomExPlayer_SetDataRequestCallback(CriAtomExPlayerHn player, CriAtomExPlayerDataRequestCbFunc func, void* obj) {
//    criAtomEx_Lock();
//    player->data_request_callback = func;
//    player->data_request_callback_user_data = obj;
//    criAtomEx_Unlock();
//}
//
//void criatomplayer_SetData(CriAtomExPlayerHn player, void* data, int buffer_size, int start, int end);
//
//inline void criAtomExPlayer_SetDataUnsafe(CriAtomExPlayerHn player, void* data, int buffer_size) {
//    criatomplayer_SetData(player, data, buffer_size, 0, buffer_size);
//}
//
//inline void criAtomExPlayer_SetData(CriAtomExPlayerHn player, void* data, int buffer_size) {
//    criAtomEx_Lock();
//    criAtomExPlayer_SetDataUnsafe(player, data, buffer_size);
//    criAtomEx_Unlock();
//}
//
//inline void criAtomPlayer_SetData(CriAtomPlayerHn player, void* data, int buffer_size) {
//    criAtomEx_Lock();
//    criAtomExPlayer_SetDataUnsafe(player, data, buffer_size);
//    criAtomEx_Unlock();
//}

namespace hh::snd {
    class SoundPlayer;

    struct HandleTag3d {
        float position[3];
        float velocity[3];
        float float48;
    };

    struct HandleTag {
        uint64_t qword0;
        CriAtomExPlayerHn* player;

        SoundCueCri::CdataTag cueData;
        HandleTag3d tag3d;
        uint32_t dword4C;
        uint32_t dword50;
        uint64_t qword58;
        uint64_t qword60;
        uint32_t dword68;
        uint32_t dword6C;
        uint32_t dword70;
        uint32_t dword74;
        SoundTween hh__snd__soundtween78;
        uint32_t qword90;
        uint32_t qword94;
    };

    void HandleTagInit(HandleTag* tag);

    class SoundObjectBase : public fnd::RefByHandleObject {
    public:
        HandleTag* tag;
        uint32_t id;

        SoundObjectBase();
    };

    class SoundListenerObject : public SoundObjectBase {
    public:
        typedef fnd::HandleManager<SoundListenerObject> HandleManager;
        SoundListenerObject();
    };

    class SoundPlaybackObject : public SoundObjectBase {
    public:
        typedef fnd::HandleManager<SoundPlaybackObject> HandleManager;
    
        csl::ut::MoveArray<void*> unk101;
        uint64_t unk102;

        SoundPlaybackObject();
    };

    class SoundListenerHandle {
    public:
        fnd::Handle<SoundListenerObject> handle;
        SoundPlayer* soundPlayer;

        SoundListenerHandle(const SoundListenerObject* handle);
        SoundListenerHandle();
    };

    class SoundHandle {
    public:
        fnd::Handle<SoundPlaybackObject> handle;

        void Stop(float time);
        void StopImm();
        void Pause(bool enabled, float time);
        void SetVolume(float volume);
        void SetBlockIdx(int idx);
        void SetBlockIdxByName(char const* name);
        unsigned int GetStatus() const;
        bool IsPlay() const;
        bool IsPause() const;
        bool IsLoop() const;
        const char* GetCueName() const;
        csl::math::Vector3 GetPosition() const;
        void SetPosition(const csl::math::Vector3& position);
        void SetVelocity(const csl::math::Vector3& velocity);
        float GetDistance(const SoundListenerHandle& listener);
        float GetPlayTime() const;
        bool IsAisac() const;
        void SetAisac(const char* id, float value);
        void AttachAisac(const char* id);
        void DetachAisac(const char* id);
        void DetachAisacAll();
        void SetMultiTrackMode(bool unkParam);
        void SetTrackVolume(int track, float volume);
        void SetMaxDistance(float maxDistance);
        void SetMinDistance(float minDistance);
        void SetMinMaxDistance(float minDistance, float maxDistance);
    };
}
