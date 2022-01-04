#pragma once

#include "../extModel/packet.h"

namespace model
{
    // �ⲿ��ҵ�ڵ���Ϣ
    struct AppNodeInfo{
        std::string nodeID;                 ///< �ڵ�ID��Ψһ��
        Optional<std::string> nodeName;     ///< �ڵ���
        Optional<std::string> productType;  ///< ��ҵ����
    };

    // ������Ʋ���
    struct ThreeCardOper
    {
        int64 userID;                   ///< �û�ID
        std::string userName;           ///< �û�����
        std::string idcard;             ///< ���֤
        std::string certificateNo;      ///< ֤����
        std::string tfSerialNumber;     ///< tf�����к�
        std::string iccid;              ///< ��SIM��iccid
        std::string equipmentID;        ///< �豸ID
        std::string appID;              ///< Ӧ��ID
        std::string mobileIP;           ///< �ƶ���IP
        std::string mobileMac;          ///< �ƶ��������ַ
        int32 operType;                 ///< ��������  1��¼2�ǳ�
        int32 operResult;               ///< �������   1�ɹ�2ʧ��
        int64 id;                       ///< ����id
        std::string operTime;           ///< ����ʱ��
    };
}