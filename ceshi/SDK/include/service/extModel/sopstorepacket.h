#pragma once

#include "../extModel/packet.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN ///��ֹ�ظ�����
#include <Windows.h>
#else
//
#endif

namespace model
{

    /// ���
    struct Result {
        int32	    code;           ///< �Ƿ���ɹ�
        std::string message;        ///< ʧ��ԭ��
        int64       result;         ///< ����Ľ��
    };

    /// Ӧ��ʵ��
    struct AppInfoBean {
        int64       id;             ///< Ӧ������
        std::string name;           ///< Ӧ������
        std::string	icon;           ///< Ӧ��ͼ��(ͼƬ·��)
        int32	    classify;       ///< Ӧ�÷���(����ID)
        int32       type;           ///< ���Ӧ������(1:ԭ��APK,2:H5)
        std::string homeUrl;        ///< h5��ҳ���ʵ�ַ
        std::string version;        ///< �汾��
        std::string packageName;    ///< ����
        std::string downloadUrl;    ///< ���ص�ַ
        std::string activityName;   ///< ��׿��ȡ����Ӧ������
        std::string orgIds;         ///< ������Χ(���orgID�ԡ�����ƴ��)
        int32       status;         ///< ״̬(1:����,2:ͣ�ã�3��ɾ��)
        std::string key;            ///< app_key
        std::string secret;         ///< app_secret
        int64       createUserID;   ///< ������userID
        std::string createTime;     ///< ����ʱ��
        std::string updateTime;     ///< ����ʱ��-�½�����ʱ��ʼֵ�봴��ʱ��һ��
        int32	    sort;           ///< �����ֶ�-δ��������ֵʱĬ��Ϊ1
        std::string column1;        ///< Ԥ���ֶ�1
        std::string column2;        ///< Ԥ���ֶ�2
        std::string column3;        ///< Ԥ���ֶ�3
        int64 createUnitID;
    };

    /// Ӧ�÷���ʵ��
    struct AppClassifyBean {
        int32       classifyID;     ///< ��������
        std::string classifyName;   ///< ��������
        int64       createUserID;   ///< ������userID
        int32       classifyStatus; ///< ����״̬ 1������ 2����ɾ��
        std::string createTime;     ///< ����ʱ��
        std::string updateTime;     ///< ����ʱ��-�½�����ʱ��ʼֵ�봴��ʱ��һ��
        int32       classifySort;   ///< �����ֶ�-δ��������ֵʱĬ��Ϊ1
        std::string classifyColumn1;///< Ԥ���ֶ�1
        std::string classifyColumn2;///< Ԥ���ֶ�2
        std::string classifyColumn3;///< Ԥ���ֶ�3
        int32 classifyType;
    };

    /// Ҫ���ȵ�ʵ��
    struct HotNewsBean {
        int32       id;             ///< Ҫ������
        std::string newsTitle;      ///< Ҫ�ű���
        std::string newsCover;      ///< ����ͼƬ·��
        std::string newsContent;    ///< ��������
        int64       createUserID;   ///< ������Id
        std::string createTime;     ///< ����ʱ��
        std::string updateTime;     ///< ����ʱ��
        int32       newsSort;       ///< �����ֶ�
        std::string newsColumn1;    ///< Ԥ���ֶ�1
        std::string newsColumn2;    ///< Ԥ���ֶ�2
        std::string newsColumn3;    ///< Ԥ���ֶ�3
    };

    /// �û���Ӧ�ù�ϵ
    struct AppRelationBean {
        int32       id;             ///< ��ϵid
        int64       userID;         ///< �û�id
        int64       appID;          ///< Ӧ��id
        int32       classifyID;     ///< Ӧ������id
        int32       relationStatus; ///< ��ϵ״̬ 1������ 2����ɾ��
        std::string createTime;     ///< ����ʱ��
        std::string updateTime;     ///< ����ʱ��
        int32       sort;           ///< �����ֶ�
        std::string relationColumn1;///< Ԥ���ֶ�1
        std::string relationColumn2;///< Ԥ���ֶ�2
        std::string relationColumn3;///< Ԥ���ֶ�3
    };

    /// �ҵ�Ӧ����Ϣ
    struct MyAppInfo {
        AppClassifyBean appClassify;            ///< Ӧ�÷���
        std::vector<AppInfoBean> appInfoList;   ///< Ӧ�ü���
        int64 code;                             ///< ��Ӧ��
        std::string msg;                        ///< ��Ӧ��������
    };

    /// Ӧ���̵�
    struct AppStore {
        std::vector<AppInfoBean> appInfoList;   ///< Ӧ�ü���
        int64       pageSize;                   ///< ÿҳ��ʾ������
        int64       pageNum;                    ///< ��ǰҳ��
        int64       totalCount;                 ///< ������
        int64       totalPage;                  ///< ��ҳ��
        int64       code;                       ///< ��Ӧ��
        std::string msg;                        ///< ��Ӧ��������
    };

    /// Ӧ���̵��ѯ����
    struct AppStoreQueryParam {
        std::string appName;                    ///< Ӧ������
        int64       userId;                     ///< Ӧ������
        int64       appClassifyId;              ///< id
        int64       pageSize;                   ///< ÿҳ��ʾ������
        int64       pageNum;                    ///< ��ǰҳ��
        int32       searchType;
    };

    struct reqAppStore {
        int8 type;
        AppStoreQueryParam appStoreQueryParam;
        AppRelationBean appRelation;
        int64 value64;
    };
    /**
    * Ӧ��ͳ�ƽ��ʵ��
    * zhaorujia
    */
    struct AppStatisticsResult{
        /* ������� */
        std::string msg;
        /* ����� */
        std::string code;
    };

    struct EnterpriseUserBean {
        int64 userID;                           /// �û�ID
        int64 enterpriseID;                     /// ��ҵID
        int64 orgID;                            /// ��֯����ID
        int64 roleID;                           /// ��ɫID
        std::string Enname;                     /// ��ҵ���û�����
        std::string duty;                       /// ��ҵ���û�ְλ
        std::string Enmail;                     /// ��ҵ���û�email
        std::string Enmobile;                   /// ��ҵ���û��ֻ���
        int8 status;                            /// ��ҵ�˺��Ƿ�ͣ�� 1������ 2��ͣ��
        int64 orderNum;                         /// ��Ա����
        int64 newOrgID;
        std::string orgName;                    /// ��֯��
        std::string extend;                     /// ��չ��Ϣ
        std::string accountName;                /// �˺�����
        int8 bizStatus;                         /// ҵ��״̬��1����ʼ״̬��2���ڸ߹�Ⱥ
        std::string userHead;                   /// ͷ��
        std::string userExtend;
    };

    struct OrganizationBean {
        OrganizationBean() :
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
        std::string extend;         ///< ��չ�ֶ�
        int32 resCode;              ///< ������֯����ʱ,���صĴ�����
        int32 exlRow;
    };

    struct UserBean {
        int64 userID;               ///<�û�ID
        //std::string phoneNum;       //<����ɾ��
        //std::string email;          ///<����ɾ��
        int16 userType;             ///<Ŀǰû������
        std::string name;           ///<�û���
        std::string pwd;            ///<�û�����
        int8 sex;                   ///<�Ա�
        std::string area;           ///<����
        YMD birthday;               ///<����
        std::string school;         ///<��ҵѧУ
        //int64 qqNum;                ///<����ɾ��
        std::string maccode;        ///<Ŀǰ������
        int8 status;                ///<�û�״̬ 1������ 2��ͣ�� 3: ע������4: Ӱ���û���5:������6:����
        std::string portraitURL;    ///<ͷ���ַ
        std::string sign;           ///<ǩ��
        int8 timeZone;              ///<ʱ��
        std::vector<std::string> phoneNums; ///<�绰�����嵥
        std::vector<std::string> emails;    ///<�����嵥
        std::string oriPortraitURL;        ///<ԭʼͷ���ַ
        std::string idcard;                 ///<����ɾ��
        std::string accountName;            ///<�˺�����
        std::string extend;                 ///<��չ��Ϣ
        int64 lockDeadline;                 ///<������ֹʱ�䣬����
        int64 remainLockDuration;           ///<ʣ������ʱ��������
        int64 SDKID;                        ///<SDKID
        std::string entExtend;              ///<��ҵ��չ��Ϣ
        std::vector<model::AccountType> accounts;  ///<��ϵ��ʽ����
        int8 regFlag;                       ///<ע���ʶ0Ϊ����1Ϊע��
        int8 pwdStrength;                   ///<����ǿ��:1:��,2:��,3:ǿ
        std::string orgID;                  ///<��֯�ṹid,����ö��ŷָ�
        int64 roleID;                       ///<��ɫID
        int8 bizStatus;                     ///<ҵ��״̬��1����ʼĬ�ϣ�2���ڸ߹ܲ�
        int8 uploadFlag;                    ///<�ϴ���ʶ, 1:δ�ϴ�,2:���ϴ�,3:�Ѻ���
        int8 oldStatus;                     ///<���涳��֮ǰ�û�״̬status��ֵ
    };
    struct OrgUserAndChildNodes {
        int32 code;
        std::string what;
        std::vector<EnterpriseUserBean> users;
        std::vector<OrganizationBean> obeans;
        std::string oPower;
    };

    struct OrgSearchUserRet {
        EnterpriseUserBean ub;
        std::string power;
    };

    struct OrgSearchResult {
        std::vector<EnterpriseUserBean> uBeans;
        std::string resultFlag;
    };
    struct respAppStore{
        int32 code;
        std::string what;
        std::vector<MyAppInfo> appInfos;
        AppStore appStore;
        std::vector<AppInfoBean> appBeans;
        std::vector<AppClassifyBean> classifyBeans;
        std::vector<HotNewsBean> hotNewsBeans;
        Result ret;
        AppStatisticsResult statResult;
    };

    struct reqEnOS{
        int8 type;
        int64 value64;
        int64 value64_2;
        int64 value64_3;
        std::string valuestr;
        std::vector<int64> list_i64;
        std::map<std::string, std::string> params;
    };

    struct respEnOS{
        int32 code;
        std::string what;
        OrgUserAndChildNodes nodes;
        std::vector<OrgSearchUserRet> orgSearchUsers;
        OrgSearchResult searchRet;
        std::vector<EnterpriseUserBean> entUsers;
        std::vector<OrganizationBean> depts;
    };
    ///�ͻ���ͳ�ƽӿ�
    struct AppStatisticsBean{
        /* Ӧ�����ͣ�
        * 1���Ż�Ӧ������ 2.��ͨӦ������
        */
        std::string appType;
        /* Ӧ��ID */
        std::string appID;
        /* �û�ID */
        std::string userID;
        /* ��֯����ID*/
        std::string orgID;
        /* ��֯����CODE */
        std::string orgCode;
        /* ��֯����CODE */
        std::string unitID;
    };
}