#pragma once

#include <iostream>
#include <vector>
#include "model/SDKTypes.h"
using namespace std;
namespace serviceTest
{
	struct AccountConfigInfo
	{
		AccountConfigInfo():m_userType(0), m_iMyUserId(0),m_server(""), m_account(""), m_loginPassword(""){
		}
		int32  m_userType; //ÕËºÅÀàÐÍ
		int64  m_iMyUserId;//ÕËºÅID
		string m_server;   //·þÎñÆ÷
		string m_account;  //ÕËºÅÃû
		string m_loginPassword;//µÇÂ¼ÃÜÂë
	};
	class CTestConfig
	{
	private:
		CTestConfig(const std::string modulePath);
	public:
		virtual ~CTestConfig();
		static CTestConfig* GetInstance(const std::string modulePath)
		{
			static CTestConfig instance(modulePath);
			return &instance;
		}
		bool LoadConfig(const char* pcFilePath);
		AccountConfigInfo getAccountInfo(int index) {
			AccountConfigInfo temp;
			if (index > 2 || index < 0) return temp;
			temp = m_accoutInfo[index];
			return temp;
		}
	public:
		AccountConfigInfo m_accoutInfo[2];
		int32  m_userType; //ÕËºÅÀàÐÍ
		string m_server;   //·þÎñÆ÷
		string m_account;  //ÕËºÅÃû
		string m_loginPassword;//µÇÂ¼ÃÜÂë
		int64 m_iMyUserId;
		string m_modulePath;
		string m_certPath;
		string m_regCode;
		string m_ticket;
		int64 m_testFriendUserId;
		int64 m_testGroupId;
		string m_headImg;
		string m_backGroundImg;
		string m_upLoadImg;
		string m_encryFilePath;
		string m_decryFilePath;
		string m_upLoadFilePath;
		int64 m_testFriendUserId2;
		int64 m_testUserTarget;
		int64 m_testGroupTarget;
		int64 m_testMsgId;
		string m_testLanguage;
		string m_uploadShareImagePath;
		string m_compressPath;
		string m_uncompressPath;
		string m_markImagepath;
		int64 sdkId;
		string m_txt100;
		string m_txt500;
		string m_txt2000;
		string m_txt6000;

		//image
		string m_imgJpgPath;
		string m_imgPngPath;
		string m_imgGifPath;
		//folder
		string m_folderPath;
		string m_hanziName;
		string m_password;
		string m_positionName;
		double m_latitude;
		double m_longitude;
		string m_cardId;
	};

}  //namespace imtest
