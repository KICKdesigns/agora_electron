/*
* Copyright (c) 2017 Agora.io
* All rights reserved.
* Proprietry and Confidential -- Agora.io
*/

/*
*  Created by Wang Yongli, 2017
*/

#ifndef AGORA_NODE_EVENT_HANDLER_H
#define AGORA_NODE_EVENT_HANDLER_H

#include "IAgoraRtcEngine.h"
#include "agora_node_ext.h"
#include <unordered_map>
#include <string>
#include <uv.h>
#include "node_napi_api.h"
#include "agora_video_source.h"
namespace agora {
    namespace rtc {
#define RTC_EVENT_JOIN_CHANNEL "joinchannel"
#define RTC_EVENT_REJOIN_CHANNEL "rejoinchannel"
#define RTC_EVENT_WARNING "warning"
#define RTC_EVENT_ERROR "error"
#define RTC_EVENT_AUDIO_QUALITY "audioquality"
#define RTC_EVENT_AUDIO_VOLUME_INDICATION "audiovolumeindication"
#define RTC_EVENT_LEAVE_CHANNEL "leavechannel"
#define RTC_EVENT_RTC_STATS "rtcstats"
#define RTC_EVENT_AUDIO_DEVICE_STATE_CHANGED "audiodevicestatechanged"
#define RTC_EVENT_AUDIO_MIXING_FINISHED "audiomixingfinished"
#define RTC_EVENT_REMOTE_AUDIO_MIXING_BEGIN "remoteaudiomixingbegin"
#define RTC_EVENT_REMOTE_AUDIO_MIXING_END "remoteaudiomixingend"
#define RTC_EVENT_AUDIO_EFFECT_FINISHED "audioeffectfinished"
#define RTC_EVENT_VIDEO_DEVICE_STATE_CHANGED "videodevicestatechagned"
#define RTC_EVENT_NETWORK_QUALITY "networkquality"
#define RTC_EVENT_LASTMILE_QUALITY "lastmilequality"
#define RTC_EVENT_FIRST_LOCAL_VIDEO_FRAME "firstlocalvideoframe"
#define RTC_EVENT_FIRST_REMOTE_VIDEO_DECODED "firstremotevideodecoded"
#define RTC_EVENT_VIDEO_SIZE_CHANGED "videosizechanged"
#define RTC_EVENT_FIRST_REMOTE_VIDEO_FRAME "firstremotevideoframe"
#define RTC_EVENT_USER_JOINED "userjoined"
#define RTC_EVENT_USER_OFFLINE "useroffline"
#define RTC_EVENT_USER_MUTE_AUDIO "usermuteaudio"
#define RTC_EVENT_USER_MUTE_VIDEO "usermutevideo"
#define RTC_EVENT_USER_ENABLE_VIDEO "userenablevideo"
#define RTC_EVENT_USER_ENABLE_LOCAL_VIDEO "userenablelocalvideo"
#define RTC_EVENT_APICALL_EXECUTED "apicallexecuted"
#define RTC_EVENT_LOCAL_VIDEO_STATS "localvideostats"
#define RTC_EVENT_REMOTE_VIDEO_STATS "remotevideostats"
#define RTC_EVENT_CAMERA_READY "cameraready"
#define RTC_EVENT_VIDEO_STOPPED "videostopped"
#define RTC_EVENT_CONNECTION_LOST "connectionlost"
#define RTC_EVENT_CONNECTION_INTERRUPTED "connectioninterrupted"
#define RTC_EVENT_CONNECTION_BANNED "connectionbanned"
#define RTC_EVENT_REFRESH_RECORDING_SERVICE_STATUS "refreshrecordingservicestatus"
#define RTC_EVENT_STREAM_MESSAGE "streammessage"
#define RTC_EVENT_STREAM_MESSAGE_ERROR "streammessageerror"
#define RTC_EVENT_MEDIA_ENGINE_LOAD_SUCCESS "mediaengineloadsuccess"
#define RTC_EVENT_MEDIA_ENGINE_STARTCALL_SUCCESS "mediaenginestartcallsuccess"
#define RTC_EVENT_REQUEST_CHANNEL_KEY "requestchannelkey"
#define RTC_EVENT_FIRST_LOCAL_AUDIO_FRAME "firstlocalaudioframe"
#define RTC_EVENT_FIRST_REMOTE_AUDIO_FRAME "firstremoteaudioframe"
#define RTC_EVENT_ACTIVE_SPEAKER "activespeaker"
#define RTC_EVENT_CLIENT_ROLE_CHANGED "clientrolechanged"
#define RTC_EVENT_AUDIO_DEVICE_VOLUME_CHANGED "audiodevicevolumechanged"
#define RTC_EVENT_VIDEO_SOURCE_JOIN_SUCCESS "videosourcejoinsuccess"
#define RTC_EVENT_VIDEO_SOURCE_REQUEST_NEW_TOKEN "videosourcerequestnewtoken"
#define RTC_EVENT_VIDEO_SOURCE_LEAVE_CHANNEL "videosourceleavechannel"
        class NodeRtcEngine;
        class NodeUid;
        class NodeEventHandler : public IRtcEngineEventHandler, public IAgoraVideoSourceEventHandler
        {
        public:
            struct NodeEventCallback
            {
                Persistent<Function> callback;
                Persistent<Object> js_this;
            };
        public:
            NodeEventHandler(NodeRtcEngine* pEngine);
            ~NodeEventHandler();
            virtual void onJoinChannelSuccess(const char* channel, uid_t uid, int elapsed) override;
            virtual void onRejoinChannelSuccess(const char* channel, uid_t uid, int elapsed) override;
            virtual void onWarning(int warn, const char* msg) override;
            virtual void onError(int err, const char* msg) override;
            virtual void onAudioQuality(uid_t uid, int quality, unsigned short delay, unsigned short lost) override;
            virtual void onAudioVolumeIndication(const AudioVolumeInfo* sperkers, unsigned int speakerNumber, int totalVolume) override;
            virtual void onLeaveChannel(const RtcStats& stats) override;
            virtual void onRtcStats(const RtcStats& stats) override;
            virtual void onAudioDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) override;
            virtual void onAudioMixingFinished() override;
            virtual void onRemoteAudioMixingBegin() override;
            virtual void onRemoteAudioMixingEnd() override;
            virtual void onAudioEffectFinished(int soundId) override;
            virtual void onVideoDeviceStateChanged(const char* deviceId, int deviceType, int deviceState) override;
            virtual void onNetworkQuality(uid_t uid, int txQuality, int rxQuality) override;
            virtual void onLastmileQuality(int quality) override;
            virtual void onFirstLocalVideoFrame(int width, int height, int elapsed) override;
            virtual void onFirstRemoteVideoDecoded(uid_t uid, int width, int height, int elapsed) override;
            virtual void onVideoSizeChanged(uid_t uid, int width, int height, int rotation) override;
            virtual void onFirstRemoteVideoFrame(uid_t uid, int width, int height, int elapsed) override;
            virtual void onUserJoined(uid_t uid, int elapsed) override;
            virtual void onUserOffline(uid_t uid, USER_OFFLINE_REASON_TYPE reason) override;
            virtual void onUserMuteAudio(uid_t uid, bool muted) override;
            virtual void onUserMuteVideo(uid_t uid, bool muted) override;
            virtual void onUserEnableVideo(uid_t uid, bool enabled) override;
            virtual void onUserEnableLocalVideo(uid_t uid, bool enabled) override;
            virtual void onApiCallExecuted(int err, const char* api, const char* result) override;
            virtual void onLocalVideoStats(const LocalVideoStats& stats) override;
            virtual void onRemoteVideoStats(const RemoteVideoStats& stats) override;
            virtual void onCameraReady() override;
            virtual void onVideoStopped() override;
            virtual void onConnectionLost() override;
            virtual void onConnectionInterrupted() override;
            virtual void onConnectionBanned() override;
            virtual void onRefreshRecordingServiceStatus(int status) override;
            virtual void onStreamMessage(uid_t uid, int streamId, const char* data, size_t length) override;
            virtual void onStreamMessageError(uid_t uid, int streamId, int code, int missed, int cached) override;
            virtual void onMediaEngineLoadSuccess() override;
            virtual void onMediaEngineStartCallSuccess() override;
            virtual void onRequestToken() override;
            virtual void onFirstLocalAudioFrame(int elapsed) override;
            virtual void onFirstRemoteAudioFrame(uid_t uid, int elapsed) override;
            virtual void onActiveSpeaker(uid_t uid) override;
            virtual void onClientRoleChanged(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole) override;
            virtual void onAudioDeviceVolumeChanged(MEDIA_DEVICE_TYPE deviceType, int volume, bool muted) override;
            virtual void onVideoSourceJoinedChannel(agora::rtc::uid_t uid) override;
            virtual void onVideoSourceRequestNewToken() override;
            virtual void onVideoSourceLeaveChannel() override;
            virtual void onVideoSourceExit() override;
            
            void addEventHandler(const std::string& eventName, Persistent<Object>& obj, Persistent<Function>& callback);

        private:
            void onJoinChannelSuccess_node(const char* channel, uid_t uid, int elapsed) ;
            void onRejoinChannelSuccess_node(const char* channel, uid_t uid, int elapsed) ;
            void onWarning_node(int warn, const char* msg) ;
            void onError_node(int err, const char* msg) ;
            void onAudioQuality_node(uid_t uid, int quality, unsigned short delay, unsigned short lost) ;
            void onAudioVolumeIndication_node(const AudioVolumeInfo* sperkers, unsigned int speakerNumber, int totalVolume) ;
            void onLeaveChannel_node(const RtcStats& stats) ;
            void onRtcStats_node(const RtcStats& stats) ;
            void onAudioDeviceStateChanged_node(const char* deviceId, int deviceType, int deviceState) ;
            void onAudioMixingFinished_node() ;
            void onRemoteAudioMixingBegin_node() ;
            void onRemoteAudioMixingEnd_node() ;
            void onAudioEffectFinished_node(int soundId) ;
            void onVideoDeviceStateChanged_node(const char* deviceId, int deviceType, int deviceState) ;
            void onNetworkQuality_node(uid_t uid, int txQuality, int rxQuality) ;
            void onLastmileQuality_node(int quality);
            void onFirstLocalVideoFrame_node(int width, int height, int elapsed) ;
            void onFirstRemoteVideoDecoded_node(uid_t uid, int width, int height, int elapsed) ;
            void onVideoSizeChanged_node(uid_t uid, int width, int height, int rotation) ;
            void onFirstRemoteVideoFrame_node(uid_t uid, int width, int height, int elapsed) ;
            void onUserJoined_node(uid_t uid, int elapsed) ;
            void onUserOffline_node(uid_t uid, USER_OFFLINE_REASON_TYPE reason) ;
            void onUserMuteAudio_node(uid_t uid, bool muted) ;
            void onUserMuteVideo_node(uid_t uid, bool muted) ;
            void onUserEnableVideo_node(uid_t uid, bool enabled) ;
            void onUserEnableLocalVideo_node(uid_t uid, bool enabled) ;
            void onApiCallExecuted_node(const char* api, int error) ;
            void onLocalVideoStats_node(const LocalVideoStats& stats) ;
            void onRemoteVideoStats_node(const RemoteVideoStats& stats);
            void onCameraReady_node();
            void onVideoStopped_node();
            void onConnectionLost_node();
            void onConnectionInterrupted_node();
            void onConnectionBanned_node();
            void onRefreshRecordingServiceStatus_node(int status);
            void onStreamMessage_node(uid_t uid, int streamId, const char* data, size_t length);
            void onStreamMessageError_node(uid_t uid, int streamId, int code, int missed, int cached);
            void onMediaEngineLoadSuccess_node();
            void onMediaEngineStartCallSuccess_node();
            void onRequestChannelKey_node();
            void onFirstLocalAudioFrame_node(int elapsed);
            void onFirstRemoteAudioFrame_node(uid_t uid, int elapsed);
            void onActiveSpeaker_node(uid_t uid);
            void onClientRoleChanged_node(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole);
            void onAudioDeviceVolumeChanged_node(MEDIA_DEVICE_TYPE deviceType, int volume, bool muted); 
            void onVideoSourceJoinedChannel_node(agora::rtc::uid_t uid);
            void onVideoSourceRequestNewToken_node();
            void onVideoSourceLeaveChannel_node();
        private:
            std::unordered_map<std::string, NodeEventCallback*> m_callbacks;
            NodeRtcEngine* m_engine;
        };
    }
}

#endif
