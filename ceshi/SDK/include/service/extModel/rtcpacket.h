#pragma once

#include "../extModel/packet.h"

namespace model
{
    struct channelRequest {
        channelRequest() : reject(false), videoType(2){}
        int64 targetId;//Ŀ��Ids
        int operType;                 ///< 0����ͨ���� 1��innercall,2,��������
        bool reject;  ///< true  �������ھܾ�����������
        int8 videoType;                 ///< 1������  2����Ƶ 3,����UI���� 4,����UI��Ƶ
        std::string firstSdp;
        bool isGroup;
        std::vector<int64> members;
    };

    struct joinChl{
        joinChl() :channelId(0){}
        int64 channelId; ///�������ķ����
        std::string  addition;///������Ϣ
    };
    struct setConfer{
        int64 m_vtMembers;///<��Ҫ�������û��б� ��ɾ����
    };
    struct p2pServerInfo{

		p2pServerInfo(){}
		p2pServerInfo(std::string saddr, std::string sport, std::string acot, std::string pw) {
			stunAddr = saddr;
			stunPort = sport;
			account = acot;
			password = pw;
		}

        std::string stunAddr;
        std::string stunPort;
        std::string turnAddr;
        std::string turnPort;
        std::string account;
        std::string password;
    };
    struct getConfer{
        std::string m_strTheme;///<��������
        p2pServerInfo info;///<�򶴷�������Ϣ
        std::vector<int64> m_vtMembers;///<��Ա
    };
    struct rejectOrAccept {

        rejectOrAccept() : targetId(0), type(0), channelId(0), videoType(2){}

        int64 targetId;                 ///< Ŀ��Id
        int8 type;                      ///< 1,���� 2���ܾ�,3,�������� 4,�����ܾ�
        int64 channelId;          ///< ����� Ψһ
        int8 videoType;                 ///< ��Ƶ���� 1:��Ƶ 2:��Ƶ
        //std::string path;               ///< P2Pʱ�������Ϊ·��(����ΪĬ��·��)
        std::string  sdps;///<��Զ������Ƶ�������sdp useid�Դ�����
    };

}