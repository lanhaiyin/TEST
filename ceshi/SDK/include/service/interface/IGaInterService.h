
#pragma once

#include "../model/SDKTypes.h"
#include "../extModel/gaInterpacket.h"
#include "IService.h"


// {888D0CC8-B73E-4411-9B08-008A40C023F3}
#define VER_GAINTER INTERFACE_VERSION(1,0)
static const VRVIID IID_IGaInterService = { 0x888d0cc8, 0xb73e, 0x4411, 0x9b, 0x8, 0x0, 0x8a, 0x40, 0xc0, 0x23, 0xf3};

namespace service
{

    class IGaInterService : public IService
    {
    public:

        virtual ~IGaInterService() {}

        /**
        * @brief ��ȡ�ⲿ�ڵ���Ϣ
        * @param[out] cb  ������ս���ص� _1 ����� _2�ⲿ��ҵ�ڵ���Ϣ
        */
        virtual void getAppNodeServers(SFunction<void(ErrorInfo, std::vector<AppNodeInfo>&)> cb) = 0;

        /**
        * @brief ���������Ʋ���
        * @param[in] oper  ������Ʋ���
        * @param[out] cb  ������ս���ص� _1 �����
        */
        virtual void addThreeCardOper(ThreeCardOper& oper, SFunction<void(ErrorInfo)> cb) = 0;

        /**
        * @brief ��ȡ��Ȩ��
        * @param[in] appID  Ӧ��ID��
        * @param[in] clientKey  ��ʱƱ��
        * @param[out] cb  ������ս���ص� _1 ����� _2��Ȩ��
        */
        virtual void getAuthCode(int64 appId, const std::string& clientKey, SFunction<void(ErrorInfo, const std::string&)> cb) = 0;
    };

} /*namespace service*/
