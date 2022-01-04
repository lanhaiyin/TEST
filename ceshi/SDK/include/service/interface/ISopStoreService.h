#pragma once
#include "../model/SDKTypes.h"
#include "IService.h"
#include "../extModel/sopstorepacket.h"

#include <string>
#include <vector>

#define VER_SOP INTERFACE_VERSION(1,0)
static const VRVIID IID_ISopStoreService = { 0x92dc7e43, 0x4a6c, 0x4426, 0xad, 0x5d, 0x28, 0x1f, 0xe7, 0x65, 0xbc, 0x1 };

namespace service
{
	class ISopStoreService : public IService
	{
	public:

		virtual ~ISopStoreService(){}
        /**
        * \brief Ӧ���̵��ѯ�ӿ�
        * @param[in] type  ��Ϣ���� 
            1.��ѯ�ҵ�Ӧ���б�
            2.��ѯӦ���̵��б�---����Ӧ�÷�����Χ(�û�������֯���ڷ�����Χ�ڵ�)
            3.ģ����ѯ
            4.Ӧ�÷����б�
            5.Ҫ���ȵ��б�
            6.����ҵ�Ӧ��
            7.ɾ���ҵ�Ӧ��
        * @param[in] appStoreQueryParam  Ӧ���̵��ѯ����
        * @param[in] appRelation  �û���Ӧ�ù�ϵ
        * @param[in] value64  �û���Ӧ�ù�ϵ
        * @param[in] stic  Ӧ��ͳ�Ʋ���
        * @param[out] cb  ������ս���ص�  _1������Ϣ _2��ѯ���
        */
		virtual void queryAppStore(int8 type, model::AppStoreQueryParam appStoreQueryParam, model::AppRelationBean appRelation, int64 value64, model::AppStatisticsBean& stic, SFunction<void(ErrorInfo, model::respAppStore)> cb) = 0;
        /**
        * \brief ����֯�ܹ��в�ѯ
        * @param[in] req  ��ѯ����ṹ��  
        * @param[out] cb  ������ս���ص�  _1������Ϣ _2��ѯ��Ӧ���
        */
        virtual void queryEnOS(model::reqEnOS &req, SFunction<void(ErrorInfo, model::respEnOS &resp)> cb) = 0;
        /**
        * \brief ��ȡ�û���Ϣ
        * @param[in] userParam  ��ȡ�û���Ϣ������ֵ��
        * @param[out] cb  ������ս���ص�  _1������Ϣ _2������ _3��ȡ����Json�� _4�û���Ϣ����
        */
        virtual void getUsersByParam(std::map<std::string, std::string> &userParam, SFunction<void(ErrorInfo, int32 code, std::string &what, std::vector<model::UserBean> &bean)> cb) = 0;

	};
}