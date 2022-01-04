#pragma once

#include "../extModel/packet.h"

namespace model
{
    /// �û���Ϣ
    struct gaUserBean {
        gaUserBean() :
        userid(0),
        orgid(0),
        policeType(0),
		regType(0) {}

        int64		userid;      ///< �û�id
        int64		orgid;       ///< ��֯id
        int32       policeType;  ///< ����
        int32       regType;     ///< �˲��Ȩ��
        std::string name;        ///< �û���
        std::string orgfullname; ///< ��֯ȫ��
        std::string userHead;    ///< ͷ��
    };

    /// �˲鸽����Ϣ
    struct gaFileBean {
        gaFileBean() :
        filesize(0) {}

        int64       filesize;   ///< �ļ���С
        std::string filename;   ///< �ļ���
        std::string filepath;   ///< �ļ�·��
    };

    /// �˲�ظ�
    struct gaInvestReplyBean{
        gaInvestReplyBean() :
        replytime(0),
        replyid(0),
        investid(0),
        investigationType(2) {
            filelist.clear();
        }

        int64 replytime;			                ///< �ظ�ʱ��
        int64 replyid;				                ///< �ظ���id
        int64 investid;				                ///< �˲�����id
        std::string content;		                ///< ����
        int32 investigationType;                    ///< �˲����� 4.��� 3.�永 2.δ֪ 1.��ͨ
        gaUserBean replier;		                    ///< �ظ�����Ϣ
        gaUserBean promotor;		                ///< �ظ�To����
        std::vector<gaFileBean> filelist;           ///< �ظ��ĸ����б�
    };

    /// �˲�
    struct gaInvestTaskBean {
        gaInvestTaskBean() :
        invalidtime(0),
        investigationType(2),
        status(0),
        replystatus(0),
        replycount(0),
        notreplycount(0),
        commentcount(0),
        investid(0),
        promotetime(0),
        updatetime(0),
        remaintime(0),
        isRead(0) {}

        int64		invalidtime;	                ///< ����ʱ��
        int32       investigationType;              ///< �˲����� 4.��� 3.�永 2.δ֪ 1.��ͨ
        std::string title;			                ///< ����
        std::string content;		                ///< ����

        gaUserBean  investuser;                     ///< �˲���
        gaFileBean  file;	                        ///< ����

        std::string auditIDcard;                    ///< �˲������֤����
        std::string sex;                            ///< �Ա�
        std::string investigated;                   ///< �����
        std::string nation;                         ///< ����
        std::string phone;                          ///< �ֻ���
        std::string address;                        ///< ��ͥסַ
        std::string homePhone;                      ///< סַ�绰
        std::string workUnit;                       ///< ������λ
        std::string occupation;                     ///< ְҵ
        std::string guardian;                       ///< �໤��
        std::string guardianPhone;                  ///< �໤�˵绰

        int32		status;			                ///< ״̬ 1.���� 2.�ѹ���
        int32       replystatus;	                ///< �ظ�״̬ 1��δ�ظ���2���Ѱ�ʱ�ظ���3��δ��ʱ�ظ�
        int32		replycount;		                ///< �ظ���
        int32		notreplycount;                  ///< δ�ظ���
        int32		commentcount;	                ///< ������
        int64	    investid;		                ///< Э������id
        int64		promotetime;	                ///< ����ʱ��
        int64		updatetime;		                ///< ����ʱ��
        int64		remaintime;		                ///< ʣ��ʱ��,0��ʱ���ʾ�Ѿ����ڵ�ʱ��
        int8        isRead;                         ///< 0:δ��  1:�Ѷ�
        gaUserBean	promotor;	                    ///< ��������Ϣ
        std::vector<gaInvestReplyBean> replylist;   ///< �ظ��б�
    };

    /// ���ۺ˲�
    struct gaCommentBean {
        gaCommentBean() :
        commentid(0),
        commentuserid(0),
        investid(0),
        replyid(0) {}

        int64 commentid;		                    ///< ����id
        int64 commentuserid;	                    ///< ������id
        int64 investid;			                    ///< Э��id
        int64 replyid;			                    ///< �ظ�id
    };

    struct investtasklist {
        investtasklist() :
        userid(0),
        type(0) {}

        int64 userid;
        int32 type;			                        ///< 1 (�˲���)��ȡ�˲������б� 2 (������)��ȡ�˲����б�
        int32 pageno;		                        ///< ҳ��
        int32 pagesize;	                            ///< ÿҳ������
        int64 promoterareaid;                       ///< ����������id
        int64 promotorID;                           ///< ������userID
        int64 receiverID;                           ///< ������userID
    };

    struct investPageBean {
        investPageBean() :
        pageno(0),
        pagesize(0),
        totalpage(0),
        totalcount(0) {
            tasklist.clear();
        }

        int32		pageno;		                    ///< ҳ��
        int32		pagesize;	                    ///< ÿҳ����
        int64		totalpage;	                    ///< ��ҳ��
        int64		totalcount;                     ///< ������
        std::vector<gaInvestTaskBean> tasklist;     ///< Э�������б�
    };

    /// ��ע
    struct attentionQueryParam {
        attentionQueryParam() :
        pageNo(0),
        pageSize(0),
        userID(0) {}

        int32 pageNo;	                            ///< ҳ��
        int32 pageSize;		                        ///< ÿҳ����
        int64 userID;		                        ///< �û�ID
        std::string keyword;                        ///< ������
    };

    /// ͨ��������Ϣ
    struct gaReportBean {
        gaReportBean() :
        status(2),
        reportid(0),
        promotetime(0),
        updatetime(0),
        auditTimeStamp(0),
        isRead(0),
        reportType(0) {
            allOrgIDList.clear();
            allClassIDList.clear();
        }

        int8		        status;		            ///< ״ֵ̬ 1��δ��� 2����ͨ����� 3��δͨ�����
        int64		        reportid;		        ///< ͨ��ID	
        int64		        promotetime;	        ///< ����ʱ��
        int64		        updatetime;	            ///< �޸�ʱ��
        std::string         title;		            ///< ͨ������
        std::string         content;		        ///< ͨ������
        gaUserBean          promotor;		        ///< ��������Ϣ
        int64               auditTimeStamp;         ///< ���ʱ���
        int8                reportType;             ///< ͨ������ 1:׷��ͨ�� 2 : Э��ͨ�� 3 : ���ͨ�� 4 : ֪ͨͨ��
        std::vector<int64>  allOrgIDList;           ///< ��ѡ��֯��Χ����֯id����
        std::vector<int32>  allClassIDList;         ///< ��ѡ���ַ�Χ������id����
        std::string         picURL;                 ///< ͼƬURL
        int8                isRead;                 ///< 0:δ��  1:�Ѷ�
    };

    /// ͨ����ҳ��Ϣ
    struct gaReportPageBean {
        gaReportPageBean() :
        pageno(0),
        pagesize(0),
        totalpage(0),
        totalcount(0) {
            reports.clear();
        }

        int32                       pageno;		     ///< ҳ��
        int32                       pagesize;		 ///< ÿҳ����
        int64                       totalpage;	     ///< ��ҳ��
        int64                       totalcount;	     ///< ������
        std::vector<gaReportBean>   reports;	     ///< ͨ���б�
    };

    /// ͨ����ѯ����
    struct gaReportQueryParamBean {
        gaReportQueryParamBean() :
        status(0),
        pageno(0),
        pagesize(0),
        begintime(0),
        endtime(0),
        promotorid(0),
        promotorproviceid(0) {}

        int8 status;	                            ///< ״ֵ̬��1:δ��� 2�����ͨ����3�����δͨ��
        int32 pageno;	                            ///< ҳ��
        int32 pagesize;	                            ///< ÿҳ����
        int64 begintime;	                        ///< ��ʼʱ��
        int64 endtime;		                        ///< ����ʱ��
        int64 promotorid;	                        ///< ������ID
        int64 promotorproviceid;	                ///< ����ʡ��ID
        std::string title;			                ///< ����
        std::string promotorname;	                ///< ����������
        std::string	fromorg;		                ///< ����ص�	
    };

    /// ��ҵ��Ա��Ϣ
    struct gaEntpriseUserInfo
    {
        gaEntpriseUserInfo() :
        userID(0),
        orgID(0) {}

        int64 userID;               ///< �û�ID userID.
        int64 orgID;                ///< ��֯����ID orgID.
        std::string enName;         ///< ��ҵ���û����� enName.
        std::string orgName;        ///< ��֯�� orgName.
        std::string extend;         ///< ��չ��Ϣ extend.
        std::string userHead;       ///< ͷ��
    };

    /// ��֯��Ϣ
    struct gaOrganizationInfo
    {
        gaOrganizationInfo() :
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
    };
    
}