#include "TestConfig.h"
#include "tinyxml2.h"
#include <string>
#include "tools.h"
using namespace tinyxml2;
namespace serviceTest
{

	CTestConfig::CTestConfig(const std::string modulePath):m_modulePath(modulePath), m_userType(0)
	{
	
	}

	CTestConfig::~CTestConfig()
	{
	}

	bool CTestConfig::LoadConfig(const char* pcFilePath)
{
	tinyxml2::XMLDocument doc;
	if (doc.LoadFile(pcFilePath))
	{
		cout << pcFilePath << " is not exist!" << endl;
		return false;
	}

	XMLElement *document = doc.RootElement();
	const char* pcContent = NULL;

	//CertPath
	XMLElement *pCertPath = document->FirstChildElement("CertPath");
	if (!pCertPath)
	{
		cout << "CertPath node is not exist!" << endl;
		return false;
	}
	pcContent = pCertPath->GetText();
	if (pcContent)
	{
		this->m_certPath = string(pcContent);
	}

	//读取A账号信息
	//Server
	XMLElement *pserverA = document->FirstChildElement("serverA");
	if (!pserverA)
	{
		cout << "pserverA node is not exist!" << endl;
		return false;
	}
	pcContent = pserverA->GetText();
	if (pcContent)
	{
		m_accoutInfo[0].m_server = string(pcContent);
	}
	//userType
	XMLElement *pUserTypeA = document->FirstChildElement("userTypeA");
	if (!pUserTypeA)
	{
		cout << "pUserTypeA node is not exist!" << endl;
		return false;
	}
	m_accoutInfo[0].m_userType = atoi(pUserTypeA->GetText());

	XMLElement *pAccoutA = document->FirstChildElement("accountA");
	if (!pAccoutA)
	{
		cout << "pFridNum node is not exist!" << endl;
		return false;
	}
	pcContent = pAccoutA->GetText();
	if (pcContent)
	{
		m_accoutInfo[0].m_account = string(pcContent);
	}

	//LoginPassword
	XMLElement *pLoginPasswordA = document->FirstChildElement("LoginPasswordA");
	if (!pLoginPasswordA)
	{
		cout << "pTestPeer node is not exist!" << endl;
		return false;
	}
	pcContent = pLoginPasswordA->GetText();
	if (pcContent)
	{
		m_accoutInfo[0].m_loginPassword = string(pcContent);
	}
	//MyUserId
	XMLElement *pMyuserIdA = document->FirstChildElement("myuserIdA");
	if (!pMyuserIdA)
	{
		cout << "pGroupNum node is not exist!" << endl;
		return false;
	}
	pcContent = pMyuserIdA->GetText();
	if (pcContent)
	{
		m_accoutInfo[0].m_iMyUserId = Tools::strToInt64(pcContent);
	}

	//读取B账号信息
	//Server
	XMLElement *pserverB = document->FirstChildElement("serverB");
	if (!pserverB)
	{
		cout << "server node is not exist!" << endl;
		return false;
	}
	pcContent = pserverB->GetText();
	if (pcContent)
	{
		m_accoutInfo[1].m_server = string(pcContent);
	}
	//userType
	XMLElement *pUserTypeB = document->FirstChildElement("userTypeB");
	if (!pUserTypeB)
	{
		cout << "pUserType node is not exist!" << endl;
		return false;
	}
	m_accoutInfo[1].m_userType = atoi(pUserTypeB->GetText());

	XMLElement *pAccoutB = document->FirstChildElement("accountB");
	if (!pAccoutB)
	{
		cout << "pFridNum node is not exist!" << endl;
		return false;
	}
	pcContent = pAccoutB->GetText();
	if (pcContent)
	{
		m_accoutInfo[1].m_account = string(pcContent);
	}

	//LoginPassword
	XMLElement *pLoginPasswordB = document->FirstChildElement("LoginPasswordB");
	if (!pLoginPasswordB)
	{
		cout << "pTestPeer node is not exist!" << endl;
		return false;
	}
	pcContent = pLoginPasswordB->GetText();
	if (pcContent)
	{
		m_accoutInfo[1].m_loginPassword = string(pcContent);
	}
	//MyUserId
	XMLElement *pMyuserIdB = document->FirstChildElement("myuserIdB");
	if (!pMyuserIdB)
	{
		cout << "pGroupNum node is not exist!" << endl;
		return false;
	}
	pcContent = pMyuserIdB->GetText();
	if (pcContent)
	{
		m_accoutInfo[1].m_iMyUserId = Tools::strToInt64(pcContent);
	}
	//配置中默认取A账号信息
	m_server = m_accoutInfo[0].m_server;
	m_userType = m_accoutInfo[0].m_userType; //账号类型
	m_account = m_accoutInfo[0].m_account;  //账号名
	m_loginPassword = m_accoutInfo[0].m_loginPassword;//登录密码
	m_iMyUserId = m_accoutInfo[0].m_iMyUserId;

	//regcode
	XMLElement *pregcode = document->FirstChildElement("regcode");
	if (!pregcode)
	{
		cout << "pTestFridUserID node is not exist!" << endl;
		return false;
	}
	pcContent = pregcode->GetText();
	if (pcContent)
	{
		this->m_regCode = string(pcContent);
	}

	//ticket
	XMLElement *pticket = document->FirstChildElement("ticket");
	if (!pticket)
	{
		return false;
	}
	pcContent = pticket->GetText();
	if (pcContent)
	{
		this->m_ticket = string(pcContent);
	}

	//TestFriendUserId
	XMLElement *pTestFriendUserId = document->FirstChildElement("TestFriendUserId");
	if (!pTestFriendUserId)
	{
		return false;
	}
	pcContent = pTestFriendUserId->GetText();
	if (pcContent)
	{
		this->m_testFriendUserId = Tools::strToInt64(pcContent);
	}


	//TestFriendUserId2
	XMLElement *pTestFriendUserId2 = document->FirstChildElement("TestFriendUserId2");
	if (!pTestFriendUserId2)
	{
		return false;
	}
	pcContent = pTestFriendUserId2->GetText();
	if (pcContent)
	{
		this->m_testFriendUserId2 = Tools::strToInt64(pcContent);
	}

	//TestUserTarget
	XMLElement *ptestUserTarget = document->FirstChildElement("TestUserTarget");
	if (!ptestUserTarget)
	{
		return false;
	}
	pcContent = ptestUserTarget->GetText();
	if (pcContent)
	{
		this->m_testUserTarget = Tools::strToInt64(pcContent);
	}



	//TestGroupTarget
	XMLElement *ptestGroupTarget = document->FirstChildElement("TestGroupTarget");
	if (!ptestGroupTarget)
	{
		return false;
	}
	pcContent = ptestGroupTarget->GetText();
	if (pcContent)
	{
		this->m_testGroupTarget = Tools::strToInt64(pcContent);
	}

	

	//TestMsgId
	XMLElement *ptestMsgId = document->FirstChildElement("TestMsgId");
	if (!ptestMsgId)
	{
		return false;
	}
	pcContent = ptestMsgId->GetText();
	if (pcContent)
	{
		this->m_testMsgId = Tools::strToInt64(pcContent);
	}





	//TestGroupId
	XMLElement *pTestGroupId = document->FirstChildElement("TestGroupId");
	if (!pTestGroupId)
	{
		cout << "pTestGroupId node is not exist!" << endl;
		return false;
	}
	pcContent = pTestGroupId->GetText();
	if (pcContent)
	{
		this->m_testGroupId = Tools::strToInt64(pcContent);
	}

	//Language
	XMLElement *pTestLanguage = document->FirstChildElement("TestLanguage");
	if (!pTestLanguage)
	{
		cout << "pTestGroupId node is not exist!" << endl;
		return false;
	}
	pcContent = pTestLanguage->GetText();
	if (pcContent)
	{
		this->m_testLanguage = string(pcContent);
	}


	//headImg
	XMLElement *pHeadImg = document->FirstChildElement("headImg");
	if (!pHeadImg)
	{
		cout << "pHeadImg node is not exist!" << endl;
		return false;
	}
	pcContent = pHeadImg->GetText();
	if (pcContent)
	{
		this->m_headImg = m_modulePath+string(pcContent);
	}

	//backGroudImg
	XMLElement *pbackGroundImg = document->FirstChildElement("backGroundImg");
	if (!pbackGroundImg)
	{
		cout << "pBackGroudImg node is not exist!" << endl;
		return false;
	}
	pcContent = pbackGroundImg->GetText();
	if (pcContent)
	{
		this->m_backGroundImg = m_modulePath + string(pcContent);
	}



	//uploadImg
	XMLElement *pUploadImg = document->FirstChildElement("uploadImg");
	if (!pUploadImg)
	{
		cout << "pUploadImg node is not exist!" << endl;
		return false;
	}
	pcContent = pUploadImg->GetText();
	if (pcContent)
	{
		this->m_upLoadImg = m_modulePath + string(pcContent);
	}


	//encryFilePath
	XMLElement *pEncryFilePath = document->FirstChildElement("encryFilePath");
	if (!pEncryFilePath)
	{
		cout << "pEncryFilePath node is not exist!" << endl;
		return false;
	}
	pcContent = pEncryFilePath->GetText();
	if (pcContent)
	{
		this->m_encryFilePath = m_modulePath + string(pcContent);
	}



	//pDecryFilePath
	XMLElement *pDecryFilePath = document->FirstChildElement("decryFilePath");
	if (!pDecryFilePath)
	{
		cout << "pDecryFilePath node is not exist!" << endl;
		return false;
	}
	pcContent = pDecryFilePath->GetText();
	if (pcContent)
	{
		this->m_decryFilePath = m_modulePath + string(pcContent);
	}




	//uploadFilePath
	XMLElement *pUploadFilePath = document->FirstChildElement("uploadFilePath");
	if (!pUploadFilePath)
	{
		cout << "pUploadFilePath node is not exist!" << endl;
		return false;
	}
	pcContent = pUploadFilePath->GetText();
	if (pcContent)
	{
		this->m_upLoadFilePath = m_modulePath + string(pcContent);
	}



	//uploadShareImagePath
	XMLElement *pUploadShareImagePath = document->FirstChildElement("uploadShareImagePath");
	if (!pUploadShareImagePath)
	{
		cout << "pUploadFilePath node is not exist!" << endl;
		return false;
	}
	pcContent = pUploadShareImagePath->GetText();
	if (pcContent)
	{
		this->m_uploadShareImagePath = m_modulePath + string(pcContent);
	}

	//compressPath
	XMLElement *pCompresspath = document->FirstChildElement("compresspath");
	if (!pCompresspath)
	{
		cout << "pUploadFilePath node is not exist!" << endl;
		return false;
	}
	pcContent = pCompresspath->GetText();
	if (pcContent)
	{
		this->m_compressPath = m_modulePath + string(pcContent);
	}

	//uncompressPath
	XMLElement *pUncompresspath = document->FirstChildElement("compresspath");
	if (!pUncompresspath)
	{
		cout << "pUploadFilePath node is not exist!" << endl;
		return false;
	}
	pcContent = pUncompresspath->GetText();
	if (pcContent)
	{
		this->m_uncompressPath = m_modulePath + string(pcContent);
	}


	//MarkImagepath
	XMLElement *pMarkImagepath = document->FirstChildElement("MarkImagepath");
	if (!pMarkImagepath)
	{
		cout << "pUploadFilePath node is not exist!" << endl;
		return false;
	}
	pcContent = pMarkImagepath->GetText();
	if (pcContent)
	{
		this->m_markImagepath = m_modulePath + string(pcContent);
	}

	//文本长度为100
	XMLElement *pSendTxt100 = document->FirstChildElement("SendTxt100");
	if (!pSendTxt100)
	{
		cout << "pSendTxt100 node is not exist!" << endl;
		return false;
	}
	pcContent = pSendTxt100->GetText();
	if (pcContent)
	{
		this->m_txt100 =  string(pcContent);
	}

	//文本长度为500
	XMLElement *pSendTxt500 = document->FirstChildElement("SendTxt500");
	if (!pSendTxt100)
	{
		cout << "pSendTxt500 node is not exist!" << endl;
		return false;
	}
	pcContent = pSendTxt500->GetText();
	if (pcContent)
	{
		this->m_txt500 = string(pcContent);
	}
	//文本长度为2000
	XMLElement *pSendTxt2000 = document->FirstChildElement("SendTxt2000");
	if (!pSendTxt2000)
	{
		cout << "pSendTxt2000 node is not exist!" << endl;
		return false;
	}
	pcContent = pSendTxt2000->GetText();
	if (pcContent)
	{
		this->m_txt2000 =  string(pcContent);
	}
	//文本长度为6000左右
	XMLElement *pSendTxt6000 = document->FirstChildElement("SendTxt6000");
	if (!pSendTxt2000)
	{
		cout << "pSendTxt6000 node is not exist!" << endl;
		return false;
	}
	pcContent = pSendTxt6000->GetText();
	if (pcContent)
	{
		this->m_txt6000 = string(pcContent);
	}

    //SendImgJpgPath
	XMLElement *pSendImgJpgPath = document->FirstChildElement("SendImgJpgPath");
	if (!pSendImgJpgPath)
	{
		cout << "pSendImgJpgPath node is not exist!" << endl;
		return false;
	}
	pcContent = pSendImgJpgPath->GetText();
	if (pcContent)
	{
		this->m_imgJpgPath = m_modulePath + string(pcContent);
	}
	//SendImgPngPath
	XMLElement *pSendImgPngPath = document->FirstChildElement("SendImgPngPath");
	if (!pSendImgPngPath)
	{
		cout << "pSendImgPngPath node is not exist!" << endl;
		return false;
	}
	pcContent = pSendImgPngPath->GetText();
	if (pcContent)
	{
		this->m_imgPngPath = m_modulePath + string(pcContent);
	}

	//SendImgGifPath
	XMLElement *pSendImgGifPath = document->FirstChildElement("SendImgGifPath");
	if (!pSendImgPngPath)
	{
		cout << "pSendImgGifPath node is not exist!" << endl;
		return false;
	}
	pcContent = pSendImgGifPath->GetText();
	if (pcContent)
	{
		this->m_imgGifPath = m_modulePath + string(pcContent);
	}
	//SendFolderPath
	XMLElement *pSendFolderPath = document->FirstChildElement("SendFolderPath");
	if (!pSendFolderPath)
	{
		cout << "pSendFolderPath node is not exist!" << endl;
		return false;
	}
	pcContent = pSendFolderPath->GetText();
	if (pcContent)
	{
		this->m_folderPath= m_modulePath + string(pcContent);
	}
	//SendhanziTxtName
	XMLElement *pSendhanziTxtName = document->FirstChildElement("SendhanziTxtName");
	if (!pSendhanziTxtName)
	{
		cout << "pSendhanziTxtName node is not exist!" << endl;
		return false;
	}
	pcContent = pSendhanziTxtName->GetText();
	if (pcContent)
	{
		this->m_hanziName = m_modulePath +string(pcContent);
	}
	
	//Sendpassword
	XMLElement *pSendpassword = document->FirstChildElement("Sendpassword");
	if (!pSendpassword)
	{
		cout << "pSendpassword node is not exist!" << endl;
		return false;
	}
	pcContent = pSendpassword->GetText();
	if (pcContent)
	{
		this->m_password =string(pcContent);
	}
    //SendpositionName
	XMLElement *pSendpositionName = document->FirstChildElement("SendpositionName");
	if (!pSendpositionName)
	{
		cout << "SendpositionName node is not exist!" << endl;
		return false;
	}
	pcContent = pSendpositionName->GetText();
	if (pcContent)
	{
		this->m_positionName = string(pcContent);
	}

	//Sendlatitude
	XMLElement *pSendlatitude = document->FirstChildElement("Sendlatitude");
	if (!pSendlatitude)
	{
		cout << "Sendlatitudenode is not exist!" << endl;
		return false;
	}
	pcContent = pSendlatitude->GetText();
	if (pcContent)
	{
		this->m_latitude = atof(pcContent);
	}

	//Sendlongitude
	XMLElement *pSendlongitude = document->FirstChildElement("Sendlongitude");
	if (!pSendlatitude)
	{
		cout << "Sendlongitude is not exist!" << endl;
		return false;
	}
	pcContent = pSendlongitude->GetText();
	if (pcContent)
	{
		this->m_longitude = atof(pcContent);
	}
	
	//SendcardId
	XMLElement *pSendcardId = document->FirstChildElement("SendcardId");
	if (!pSendcardId)
	{
		cout << "SendcardId is not exist!" << endl;
		return false;
	}
	pcContent = pSendcardId->GetText();
	if (pcContent)
	{
		this->m_cardId = string(pcContent);
	}
	doc.Clear();


	return true;

}
	
	/*const string CTestConfig::GetCertPath()
	{
		return this->m_certPath;
	}

	const string CTestConfig::GetAccount()
	{
		return this->m_account;
	}

	const int64 CTestConfig::GetMyUserId()
	{
		return this->m_iMyUserId;
	}

	const string CTestConfig::GetLoginPassword()
	{
		return this->m_loginPassword;
	}

	const string CTestConfig::GetRegCode()
	{
		return this->m_regCode;
	}

	const string CTestConfig::GetTicket()
	{
		return this->m_ticket;
	}

	const string CTestConfig::GetServer()
	{
		return this->m_server;
	}


	const int64 CTestConfig::GetTestFriendUserId()
	{
		return this->m_testFriendUserId;
	}

	const int64 CTestConfig::GetTestGroupId()
	{
		return this->m_testGroupId;
	}


	const string CTestConfig::GetHeadImg()
	{
		return this->m_headImg;
	}

	const string CTestConfig::GetBackGroundImg()
	{
		return this->m_backGroundImg;
	}

	const string CTestConfig::GetUpLoadImg()
	{
		return this->m_upLoadImg;
	}

	const string CTestConfig::GetEncryFilePath()
	{
		return this->m_encryFilePath;
	}

	const string CTestConfig::GetDecryFilePath()
	{
		return this->m_decryFilePath;
	}

	const string CTestConfig::GetUpLoadFilePath()
	{
		return this->m_upLoadFilePath;
	}*/



}  //namespace imtest
