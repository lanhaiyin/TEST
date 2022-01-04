#pragma once

/*****************************************************
    NotifyChannel��ʹ�õĽṹ���ڴ��ļ��ж���
        ��������Service���õ��Ľṹ��

    ����������õ��Ľṹ��ֱ��� avpacket.h�� �ж���
    ��ӽṹ���ڲ����Ӧpacket�����  ���ļ���Ҫ�����޸�
******************************************************/

#include "../model/SDKTypes.h"
#include <string>
#include <vector>
#include "../model/Optional.h"
#include <map>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN ///��ֹ�ظ�����
#include <Windows.h>
#else
//
#endif

namespace model
{
    struct YMD {
        int32 year;                 // 0 ����ʹ��
        int8 month;                 // ��1��ʼ
        int8 day;                   // ��1��ʼ
    };

    struct AccountType{
        bool operator == (const AccountType & rhs) const
        {
            return (type == rhs.type) && (accounts == rhs.accounts) && (mark == rhs.mark);

        }
        int8 type;                  // �˺����� 1���绰, 3������, 4��userID, 5:���֤, 6��������, 7:�Զ����ʺ�(��������)
        std::string accounts;       // �˺�
        std::string mark;           // ��ʶ
    };
    struct AVEvent
    {
        AVEvent() :userId(0), type(0), videoType(0), avType(0){}
        int64 userId;
        int8 avType; ///<1������  2����Ƶ

        int8 type;//�¼����� 1,��Ƶ���� 2,�Ҷ���Ϣ 3,���󱻾� 4,æ 5,��ʱ 6,ȡ�� 7,���� 8,�Ͽ�
        std::string channelId;///<����� Ψһ
        int8 videoType;///<��Ƶ�ػ����� 1:���� 2:����
        std::string fileName;///<�ļ���
        int64 fileSize;//<�ļ���С
    };

    struct channelEvent
    {
        channelEvent() :userId(0), type(0), channelId(0), videoType(2){}
        int64 userId;
        int64 targetId;
        bool isGroup;
        int8 type;                      ///< �¼����� 1,���� 2,�Ҷ� 3,���󱻾� 4,�Է�æ 5,��ʱ 6,ȡ��7,���ӳɹ�,8,���ӶϿ�,9,�������ѽ���,10,P2P���,11,�յ�accept ��Ϣ ������Ҫ����createAnswer 12,�յ�responce ��������Ҫ����setRemoteDescrption
        int64 channelId;				///< ����� Ψһ
		int64 sessionId;				///<SessionId
        int8 videoType;                 ///< 1����Ƶ 2����Ƶ��3,����UI���� 4,����UI��Ƶ
        std::string fileName;           ///< P2Pʱ������ļ���
        std::string sdp;                ///<�յ�acceptʱ ��sdp�����ϲ�
        int8 version;					///< ����������rtc  ///< rtc = 0 ���� =1
        std::vector<int64> members;     ///<���з����������û��б�
		std::string extendJson;			///<��չJson
    };



	/// ��֯��Ϣ
	struct OrganizationInfo
	{
		OrganizationInfo() :
		orgID(0),
		enterpriseID(0),
		leaf(0),
		parentOrgID(0),
		orderNum(0),
		branchID(0),
		departLevel(0),
		subOrgNum(0),
		subUserNum(0),
		isHidden(0),
		provinceID(0),
		cityID(0),
		areaID(0) {}

		bool operator == (const OrganizationInfo & rhs) const
		{
			return (orgID == rhs.orgID) && (enterpriseID == rhs.enterpriseID) && (orgName == rhs.orgName) && (orgCode == rhs.orgCode)
				&& (leaf == rhs.leaf) && (parentOrgID == rhs.parentOrgID) && (remark == rhs.remark) && (orderNum == rhs.orderNum)
				&& (branchID == rhs.branchID) && (departID == rhs.departID) && (departLevel == rhs.departLevel) && (subOrgNum == rhs.subOrgNum)
				&& (subUserNum == rhs.subUserNum) && (isHidden == rhs.isHidden) && (provinceID == rhs.provinceID) && (provinceName == rhs.provinceName)
				&& (cityID == rhs.cityID) && (cityName == rhs.cityName) && (areaID == rhs.areaID) && (areaName == rhs.areaName)
				&& (orgNamePinyin == rhs.orgNamePinyin);

		}

		int64 orgID;                ///< ��֯����ID orgID.

		int64 enterpriseID;         ///< ��ҵID enterpriseID.
		std::string orgName;        ///< ��֯�������� orgName.
		std::string orgCode;        ///< ��֯�������� orgCode.
		int8 leaf;                  ///< �Ƿ�Ҷ�ڵ� leaf.
		int64 parentOrgID;          ///< ���ڵ� parentOrgID.
		std::string remark;         ///< ��ע remark.
		int64 orderNum;             ///< ���� orderNum.
		int64 branchID;             ///< �칫��ID branchID.
		std::string departID;       ///< ɾ�� departID.
		int8 departLevel;           ///< ��֯���� departLevel.
		int64 subOrgNum;            ///< �ݹ���������¼���֯�� subOrgNum.
		int64 subUserNum;           ///< �ݹ���������¼���Ա�� subUserNum.
		int8 isHidden;              ///< �Ƿ�����, 1�Ա����Ź��� 2�����в��Ź�����3�Բ��ֲ��Ź��� isHidden.
		int64 provinceID;           ///< ʡ��ID provinceID.
		std::string provinceName;   ///< ʡ������ provinceName.
		int64 cityID;               ///< ��ID cityID.
		std::string cityName;       ///< ������ cityName.
		int64 areaID;               ///< ��ID areaID.
		std::string areaName;       ///< ������ areaName.
		std::string orgNamePinyin;  ///< ƴ�� orgNamePinyin.
	};

	struct multiRtcEvent
	{
		multiRtcEvent() :type(0), groupId(0), onwerId(0) {}
		int64 userId;                   ///< �¼�������ID
		int8 type;						///< �¼�����(1���� 2���� 3���� 4�Ҷ� 5���� 6��ʱ)
		std::string annotation;			///< �¼�ע��
		int64 groupId;					///< ȺID
		int64 onwerId;					///< ��������ID
		std::string	roomId;				///< ����ID
		std::string roomName;			///< ��������
		std::vector<int64> selects;		///< ������Ա(����/����/��ʱ��Ա).
		std::vector<int64> members;		///< ȫ����Ա
		std::string extendJson;			///< ��չJson
	};

    struct tclEvent {
        tclEvent() : userId(0), type(0), channelId(0), ctrlType(0) {}

        int64 userId;                   ///< �Է�Id
        int8 type;                      ///< �¼����� 1,���� 2,�Ҷ� 3,���󱻾� 4,�Է�æ 5,��ʱ 6,ȡ�� 7,���� 8,��Ӧ 9,���� 10,����,11,�л���Ļ���� 12,�л����� 13,�ܾ��л�
        int64 channelId;                ///< ����� Ψһ���ܿط�UserId��
        int8 ctrlType;                  ///< 1-��Ļ���� 2-Զ�̲���
        std::vector<std::string> vecIPAddr;     // �ܿط�IP��ַ�б�
    };

    struct mailFolder{
        mailFolder() :unReadNum(0), totalNum(0), flagNum(0){}
        std::string folderName; ///<�ļ�����
        int64 unReadNum;///<δ���ʼ���Ŀ
        int64 totalNum;///<���ʼ���Ŀ
        int64 flagNum;///<�Ǳ���Ŀ
    };
    struct  mailDate
    {
        mailDate() :year(0), mon(0), day(0), weekDay(0){}
        int year;
        int mon;
        int day;
        int hour;
        int min;
        int sec;
        int weekDay;
        std::string timeZone;
    };
    struct mailSection
    {
        mailSection(){
            sn = 0;
            type = -1;
            format = -1;
            tsfEncode = -1;
            oriEncode = -1;
            isAttach = 0;
            sectionSize = 0;
        }
        int sn;//<���
        int type;//< text image
        int format;//< html jpeg;
        int tsfEncode; //<������뷽ʽ  base64
        int oriEncode; //<���ı��� utf-8
        int8 isAttach;

        std::string sectionName;
        std::string sectionPath;//������
        int64       sectionSize;
    };
    struct mailHeader{
        mailHeader() :status(0x00), time(0){
        }
        std::string UID;
        std::string subject;
        std::string from;
        std::string name;
        std::vector<std::string> cc;
        std::vector<std::string> recv;
        int64 time;
        int8 status;
        std::vector<mailSection> attach;
        mailDate date;
        int64 totalSize;
    };
    struct mail :public mailHeader
    {
        mail() :isNew(true){
        }
        std::string body;
        std::string digst;
        std::string charset;//���ı���
        std::string tsfEncodeType;///<������뷽ʽ
        bool isNew;//����Ƿ������ʼ������Ѿ�ɾ�����ʼ� ����
        std::string floderName;
    };

    struct pushMessage
    {
        pushMessage() :
        previousMsgID(0),
        msgType(0),
        msgID(0),
        createUserID(0),
        fromTeamID(0),
        originalMsgID(0),
        status(0),
        createTime(0),
        operType(0),
        havVaild(0) {}

        int64 previousMsgID;
        /**
        * 11 ���յ�Э������
        * 12 ���յ�Э������ظ�
        * 13 ���յ�ͨ����Ϣ
        * 81 �˲������ģ������ˣ�
        * 82 �˲������ģ�ԭ�����ˣ�
        * 83 ͨ����˽��
        */
        int8  msgType;
        int64 msgID;
        int64 createUserID;
        int64 fromTeamID;
        std::vector<int64>  targetUserIDs;
        std::string title;
        std::string body;
        std::string format;
        int64 originalMsgID;
        int8 status;
        int64 createTime;
        int8 operType;
        std::string maccode;
        int8 havVaild;
    };
	
	struct  GroupInfoOrSettingInfo{

		/**
		 * 25 Ⱥv���û���Ϣ���� 
		 */
		int type;
		int64 groupId;//type = 25 ʱʹ��
		GroupInfoOrSettingInfo() :type(0), groupId(0){}
	};



	struct  GDocUpDownNotice{//groupid  + docid + locapath +status+createat/updateat/deleteat
		GDocUpDownNotice() :docid(0), updateat(0), groupid(0), oper(0){}
		/**
		* Ⱥ�ĵ�֪ͨ��Ϣ �ƶ��ͻ���ר��
		*/
		int64 groupid;
		int8 oper;
		int64 docid;
		std::string locapath;
		int64 updateat;// ����ʱ��

	};

}