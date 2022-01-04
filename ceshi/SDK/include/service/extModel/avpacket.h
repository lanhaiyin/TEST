#pragma once

#include "../extModel/packet.h"

namespace model
{
    struct AVRequest {
        AVRequest() :targetId(0), type(2), hungUp(false), videoType(1){}
        int64 targetId;//Ŀ��Id

#ifdef _WIN32
        HWND local;
        HWND remote;
#else
        long local;
        long remote;
#endif

        std::string channelId;///<����� Ψһ
        int8 type; ///<1������  2����Ƶ
        bool hungUp;///true �Ҷ�
        int8 videoType;///<��Ƶ�ػ����� 1:���� 2:����
    };

    struct AVRejectOrAccept {
        AVRejectOrAccept() : targetId(0), type(1), videoType(0), local(0), remote(0){}
        int64 targetId;//Ŀ��Id

#ifdef _WIN32
        HWND local;
        HWND remote;
#else
        long local;
        long remote;
#endif

        int8 type;//1,���� 2���ܾ�
        std::string channelId;///<����� Ψһ
        int8 videoType;///<��Ƶ�ػ����� 1:���� 2:����
        std::string path;               ///< P2Pʱ�������Ϊ·��

    };
}