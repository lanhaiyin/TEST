#include "gtest/gtest.h"
#include "unitest_auth.h"
#include "unitest_config.h"
#include "unitest_chat.h"
#include "unitest_sysmsg.h"
#include "unitest_ext.h"
#include "unitest_cloud.h"
#include "unitest_file.h"
#include "unitest_contact.h"
#include "unitest_group.h"
#include "unitest_search.h"
#include "unitest_user.h"
#include "unitest_gainter.h"
#include "unitest_rtc.h"
#include "UnusedService.h"
#include "unitest_comm.h"
#include "Environment.h"
#include "sdk_unitest.h"
sdkUniTest g_test[2];
namespace serviceTest {

	/*************************************************
	CommUnitest start
	***************************************************/
	CommUnitest commUnitest;
	/*TEST(CommUnitest, sendText1) {
		EXPECT_EQ(0,commUnitest.sendText());
	}
	TEST(CommUnitest, sendTextLength1) {
		EXPECT_EQ(0, commUnitest.sendTextlength1());  
	}
	TEST(CommUnitest, sendTextLength2) {
		EXPECT_EQ(0, commUnitest.sendTextlength2());
	}
	TEST(CommUnitest, sendTextLength3) {
		EXPECT_EQ(0, commUnitest.sendTextlength3());
	}
	TEST(CommUnitest, sendTextLength4) {
		EXPECT_EQ(0, commUnitest.sendTextlength4());
	}
	
	TEST(CommUnitest, sendImgJpg) {
		EXPECT_EQ(0, commUnitest.sendImgJpg());
	}
	TEST(CommUnitest, sendImgPng) {
		EXPECT_EQ(0, commUnitest.sendImgPng());
	}
	TEST(CommUnitest, sendImgGif) {
		EXPECT_EQ(0, commUnitest.sendImgGif());
	}

	TEST(CommUnitest, sendImgsize1) {
		EXPECT_EQ(0, commUnitest.sendImgsize1());
	}
	TEST(CommUnitest, sendImgsize2) {
		EXPECT_EQ(0, commUnitest.sendImgsize2());
	}
	
	/*TEST(CommUnitest, sendImgsize3) {
		EXPECT_EQ(0, commUnitest.sendImgsize3());
	}

	
	
	TEST(CommUnitest, sendFile) {
		EXPECT_EQ(0, commUnitest.sendFile());
	}
	
	
	TEST(CommUnitest, sendHanziFile) {
		EXPECT_EQ(0, commUnitest.sendHanziFile());
	}
	TEST(CommUnitest, sendFolder) {
		EXPECT_EQ(0, commUnitest.sendFolder());
	}
	
	
	TEST(CommUnitest, sendTask) {
		EXPECT_EQ(0, commUnitest.sendTask());
	}
	TEST(CommUnitest, sendTasklength1) {
		EXPECT_EQ(0, commUnitest.sendTasklength1());
	}
	TEST(CommUnitest, sendTasklength2) {
		EXPECT_EQ(0, commUnitest.sendTasklength2());
	}
	TEST(CommUnitest, sendTasklength3) {
		EXPECT_EQ(0, commUnitest.sendTasklength3());
	}
	
	
	TEST(CommUnitest, sendTextdelay) {
		EXPECT_EQ(0, commUnitest.sendTextdelay());
	}

	
	TEST(CommUnitest, sendTextdelaylen1) {
		EXPECT_EQ(0, commUnitest.sendTextdelaylen1());
	}
	TEST(CommUnitest, sendTextdelaylen2) {
		EXPECT_EQ(0, commUnitest.sendTextdelaylen2());
	}
	TEST(CommUnitest, sendTextdelaylen3) {
		EXPECT_EQ(0, commUnitest.sendTextdelaylen3());
	}
	
	TEST(CommUnitest, sendTextdou) {
		EXPECT_EQ(0, commUnitest.sendTextdou());
	}
	TEST(CommUnitest, sendTextburn) {
		EXPECT_EQ(0, commUnitest.sendTextburn());
	}
	
	TEST(CommUnitest, sendTextencry) {
		EXPECT_EQ(0, commUnitest.sendTextencry());
	}
	*/
	TEST(CommUnitest, sendFileEncry) {
		EXPECT_EQ(0, commUnitest.sendFileEncry());
	}
	/*
	TEST(CommUnitest, sendCardEncry) {
		EXPECT_EQ(0, commUnitest.sendCardEncry());
	}
	
	
	TEST(CommUnitest, sendTextErase) {
		EXPECT_EQ(0, commUnitest.sendTextErase());
	}
	TEST(CommUnitest, sendTextcard) {
		EXPECT_EQ(0, commUnitest.sendTextcard());
	}
	TEST(CommUnitest, sendTextFeather) {
		EXPECT_EQ(0, commUnitest.sendTextFeather());
	}
	
	TEST(CommUnitest, sendTextDynExpression) {
		EXPECT_EQ(0, commUnitest.sendTextDynExpression());
	}
	TEST(CommUnitest, sendPosition) {
		EXPECT_EQ(0, commUnitest.sendPosition());
	}
	TEST(CommUnitest, sendTextJin) {
		EXPECT_EQ(0, commUnitest.sendTextJin());
	}
	
    TEST(CommUnitest, sendFileJin) {
	EXPECT_EQ(0, commUnitest.sendFileJin());
	}
	TEST(CommUnitest, sendCardJin) {
		EXPECT_EQ(0, commUnitest.sendCardJin());
	}
	TEST(CommUnitest, sendPositionJin) {
		EXPECT_EQ(0, commUnitest.sendPositionJin());
	}
	*/
	TEST(CommUnitest, clear) {
		EXPECT_EQ(0, commUnitest.clear());
	}
	/*************************************************
	beforeConfigServiceUnitest start
	***************************************************/
//	beforeConfigServiceUnitest beforeconfig;
//	TEST(beforeConfigServiceUnitest, rootPath) {
//		EXPECT_TRUE(beforeconfig.rootPath());
//	}
//	TEST(beforeConfigServiceUnitest, setLogLevel) {
//		EXPECT_TRUE(beforeconfig.setLogLevel());
//	}
//	TEST(beforeConfigServiceUnitest, setInterConnect) {
//		EXPECT_TRUE(beforeconfig.setInterConnect());
//	}
//	TEST(beforeConfigServiceUnitest, setNotifyStatus) {
//		EXPECT_FALSE(beforeconfig.setNotifyStatus());
//	}
//	TEST(beforeConfigServiceUnitest, setCertificatePath) {
//		EXPECT_TRUE(beforeconfig.setCertificatePath());
//	}
//	TEST(beforeConfigServiceUnitest, setLanguage) {
//		EXPECT_TRUE(beforeconfig.setLanguage());
//	}
//	TEST(beforeConfigServiceUnitest, setLanguageType) {
//		EXPECT_TRUE(beforeconfig.setLanguageType());
//	}
//	TEST(beforeConfigServiceUnitest, setMsgParserMode) {
//		EXPECT_TRUE(beforeconfig.setMsgParserMode());
//	}
//	TEST(beforeConfigServiceUnitest, setIsRoming) {
//		EXPECT_TRUE(beforeconfig.setIsRoming());
//	}
//	TEST(beforeConfigServiceUnitest, setPwIsCrypt) {
//		EXPECT_TRUE(beforeconfig.setPwIsCrypt());
//	}
//	TEST(beforeConfigServiceUnitest, setHttpsLogin) {
//		EXPECT_FALSE(beforeconfig.setHttpsLogin());
//	}
//	TEST(beforeConfigServiceUnitest, setMac) {
//		EXPECT_TRUE(beforeconfig.setMac());
//	}
//	TEST(beforeConfigServiceUnitest, setIsOpenSecPlugin) {
//		EXPECT_TRUE(beforeconfig.setIsOpenSecPlugin());
//	}
//	TEST(beforeConfigServiceUnitest, setLogOutLevel) {
//		EXPECT_TRUE(beforeconfig.setLogOutLevel());
//	}
//	//暂时禁用，该接口调用可能会引发死锁
//	TEST(beforeConfigServiceUnitest, setRootPath) {
//		EXPECT_TRUE(beforeconfig.setRootPath());
//	}
//	/*************************************************
//	AuthServiceUnitest start
//	***************************************************/
//	AuthServiceUnitest auth;
//
//	TEST(AuthServiceUnitest, prelogin) {
//		EXPECT_EQ(0, auth.prelogin());
//	}
//	TEST(DISABLED_Interface, abortLogin) {
//		EXPECT_EQ(0, auth.abortLogin());
//	}
//	/*TEST(AuthServiceUnitest, quickRegister) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, auth.quickRegister());
//		}
//		else
//		{
//			EXPECT_EQ(506, auth.quickRegister());
//		}	
//	}*/
//	TEST(AuthServiceUnitest, signup) {
//		EXPECT_EQ(0, auth.signup());
//	}
//	TEST(AuthServiceUnitest, signupEx) {
//		EXPECT_EQ(0, auth.signupEx());
//	}
//	TEST(AuthServiceUnitest, beforeLogin) {
//		if (m_config->m_server == "vrv")
//			EXPECT_EQ(100, auth.beforeLogin());
//		else if (m_config->m_server == "bxy") {
//			int code = auth.beforeLogin();
//			bool isOk = (code == 200 || code == 100 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "im")
//			EXPECT_EQ(100, auth.beforeLogin());
//	}
//	TEST(AuthServiceUnitest, getRegCode) {
//		EXPECT_EQ(0, auth.getRegCode());
//	}
//	TEST(AuthServiceUnitest, verifyImgCode) {
//		EXPECT_TRUE(auth.verifyImgCode());
//	}
//	TEST(AuthServiceUnitest, loginSpecial) {
//		EXPECT_EQ(112, auth.loginSpecial());
//	}
//	TEST(AuthServiceUnitest, offlineLogin) {
//		EXPECT_EQ(0, auth.offlineLogin());
//	}
//	TEST(AuthServiceUnitest, offLineToLogin) {
//		EXPECT_EQ(0, auth.offLineToLogin());
//	}
//	TEST(AuthServiceUnitest, autoLogin) {
//		
//		EXPECT_EQ(113, auth.autoLogin());
//	}
//	//TEST(AuthServiceUnitest, logoutLocal) {
//	//	EXPECT_EQ(-16777171, auth.logoutLocal());
//	//}
//	TEST(AuthServiceUnitest, loginEx) {
//		int retryCnt = 3;
//		int code = 0;
//		
//		do
//		{
//	      code = auth.loginEx();
//		  if (!code || 113 ==code || 112 == code){
//			  break;
//		  }
//		  else {
//			  FILE *fp = NULL;
//			  fp = fopen("./TestResult/error.txt", "w");
//			  if (fp != NULL)
//			  {
//				  fprintf(fp, "%s,login return code=%d", m_config->m_server.c_str(), code);
//				  fclose(fp);
//			  }
//		  }
//		  ///重试等待时间，随着重试次数增加5秒
//		  Tools::sleep(((5 - retryCnt) * 5 - 4)*1000);
//		} while (retryCnt--);
//		if (code && code != 113) {
//			printf("\n login code =%d \n ", code);
//			exit(0);
//		}
//		EXPECT_EQ(0, code);
//	}
//
//	TEST(AuthServiceUnitest, getSecUrl) {
//		EXPECT_EQ(0, auth.getSecUrl());
//	}
//	TEST(AuthServiceUnitest, getClientKey) {
//		EXPECT_EQ(0, auth.getClientKey());
//	}
//	TEST(AuthServiceUnitest, setNameAndPasswd) {
//		EXPECT_EQ(0, auth.setNameAndPasswd());
//	}
//	TEST(AuthServiceUnitest, changePassword) {
//		EXPECT_EQ(543, auth.changePassword());
//	}
//	TEST(AuthServiceUnitest, getResetPwCode) {
//		EXPECT_EQ(0, auth.getResetPwCode());
//	}
//	TEST(AuthServiceUnitest, resetPasswd) {
//		EXPECT_EQ(120, auth.resetPasswd());
//	}
//	TEST(AuthServiceUnitest, getPasswordRule) {
//		EXPECT_EQ(0, auth.getPasswordRule());
//	}
//	TEST(DISABLED_Interface, getBindPhoneCode) {
//		EXPECT_EQ(0, auth.getBindPhoneCode());
//	}
//	TEST(DISABLED_Interface, bindPhone) {
//		EXPECT_EQ(0, auth.bindPhone());
//	}
//	TEST(AuthServiceUnitest, bindMail) {
//		EXPECT_TRUE(auth.bindMail());
//	}
//	TEST(AuthServiceUnitest, getVerifyMailOrPhoneCode) {
//		EXPECT_EQ(0, auth.getVerifyMailOrPhoneCode());
//	}
//	TEST(AuthServiceUnitest, getLoginInfo) {
//		EXPECT_EQ(0, auth.getLoginInfo());
//	}
//	TEST(AuthServiceUnitest, getLoginAuthCode) {
//		EXPECT_EQ(100008008, auth.getLoginAuthCode());
//	}
//	TEST(AuthServiceUnitest, getAuthAccessToken) {
//		EXPECT_EQ(10002, auth.getAuthAccessToken());
//	}
//	TEST(AuthServiceUnitest, checkOrRefreshAccessToken) {
//		EXPECT_EQ(10004, auth.checkOrRefreshAccessToken());
//	}
//	TEST(AuthServiceUnitest, getAuthUserBean) {
//		EXPECT_EQ(0, auth.getAuthUserBean());
//	}
//	TEST(AuthServiceUnitest, getWebSiteAuth) {
//		EXPECT_EQ(10002, auth.getWebSiteAuth());
//	}
//	TEST(AuthServiceUnitest, verifyPKSign) {
//		EXPECT_EQ(0, auth.verifyPKSign());
//	}
//	TEST(AuthServiceUnitest, getCertOutDate) {
//		EXPECT_TRUE(auth.getCertOutDate());
//	}
//	TEST(AuthServiceUnitest, getCertOrgName) {
//		EXPECT_EQ(1, auth.getCertOrgName());
//	}
//	TEST(AuthServiceUnitest, signupOld) {
//		EXPECT_EQ(120, auth.signupOld());
//	}
//	TEST(AuthServiceUnitest, scanCodeLogin) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(100011004, auth.scanCodeLogin());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(-1, auth.scanCodeLogin());
//		}
//		else
//		{
//			EXPECT_EQ(-1, auth.scanCodeLogin());
//		}
//	}
//	TEST(AuthServiceUnitest, getLastHBTime) {
//		EXPECT_EQ(1, auth.getLastHBTime());
//	}
//	TEST(AuthServiceUnitest, getPCLoginQrcode) {
//		EXPECT_EQ(100008011, auth.getPCLoginQrcode());
//	}
//	TEST(AuthServiceUnitest, getQrLoginStatus) {
//		if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(100008021, auth.getQrLoginStatus());
//		}
//		else if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100008022, auth.getQrLoginStatus());
//		}
//		else
//		{
//			EXPECT_EQ(100008021, auth.getQrLoginStatus());
//		}
//	}
//	TEST(AuthServiceUnitest, scanPCLoginQrCode) {
//		if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(100008012, auth.scanPCLoginQrCode());
//		}
//		else if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100008011, auth.scanPCLoginQrCode());
//		}
//		else 
//		{
//			EXPECT_EQ(100008012, auth.scanPCLoginQrCode());
//		}
//	}
//	TEST(AuthServiceUnitest, confirmPCLogin) {
//		if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(100008017, auth.confirmPCLogin());
//		}
//		else if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100008017, auth.confirmPCLogin());
//		}
//		else
//		{
//			EXPECT_EQ(100008017, auth.confirmPCLogin());
//		}
//	}
//	TEST(AuthServiceUnitest, checkQrLoginDevice) {
//		if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(100008028, auth.checkQrLoginDevice());
//		}
//		else if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100008028, auth.checkQrLoginDevice());
//		}
//		else 
//		{
//			EXPECT_EQ(100008028, auth.checkQrLoginDevice());
//		}
//	}
//	TEST(AuthServiceUnitest, pcQuickLogin) {
//		if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, auth.pcQuickLogin());
//		}
//		else if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, auth.pcQuickLogin());
//		}
//		else 
//		{
//			EXPECT_EQ(0, auth.pcQuickLogin());
//		}
//	}
//	//放开测试，修改中
//	TEST(AuthServiceUnitest, getLogoutCode) {
//		if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(100004527, auth.getLogoutCode());
//		}
//		else if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100004527, auth.getLogoutCode());
//		}
//		else
//		{
//			EXPECT_EQ(100004527, auth.getLogoutCode());
//		}
//	}
//	TEST(AuthServiceUnitest, setLogoutAccount) {
//		EXPECT_EQ(0, auth.setLogoutAccount());
//	}
//
//	TEST(AuthServiceUnitest, authPcBrowserLoginTokenCheck) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100, auth.authPcBrowserLoginTokenCheck());
//		}
//		else if(m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(100013076, auth.authPcBrowserLoginTokenCheck());
//		}
//		else
//		{
//			EXPECT_EQ(100, auth.authPcBrowserLoginTokenCheck());
//		}
//		
//	}
//
//	TEST(AuthServiceUnitest, configJssdkAuthLocal) {
//		EXPECT_EQ(100, auth.configJssdkAuthLocal());
//	}
//
//	TEST(AuthServiceUnitest, checkJssdkAuthLocal) {
//		EXPECT_EQ(-16777121, auth.checkJssdkAuthLocal());
//	}
//
//	TEST(AuthServiceUnitest, checkJssdkAuthLocalByAppId) {
//		EXPECT_EQ(-16777121, auth.checkJssdkAuthLocalByAppId());
//	}
//
//	TEST(AuthServiceUnitest, thirdPartyAuthbyToken) {
//		EXPECT_EQ(100, auth.thirdPartyAuthbyToken());
//	}
//
//	TEST(AuthServiceUnitest, SetBifactorLogin) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100, auth.SetBifactorLogin());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(100008032, auth.SetBifactorLogin());
//		}
//		else
//		{
//			EXPECT_EQ(100, auth.SetBifactorLogin());
//		}
//		
//	}
//
//	TEST(AuthServiceUnitest, MQrCodeQuery) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100, auth.MQrCodeQuery());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, auth.MQrCodeQuery());
//		}
//		else
//		{
//			EXPECT_EQ(100, auth.MQrCodeQuery());
//		}
//		
//	}
//
//	TEST(AuthServiceUnitest, getMCircleQrCode) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100, auth.getMCircleQrCode());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(11020003, auth.getMCircleQrCode());
//		}
//		else
//		{
//			EXPECT_EQ(100, auth.getMCircleQrCode());
//		}
//		
//	}
//	
//	TEST(AuthServiceUnitest, showVerifyUserPassword) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100004527, auth.showVerifyUserPassword());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(100004523, auth.showVerifyUserPassword());
//		}
//		else
//		{
//			EXPECT_EQ(100004527, auth.showVerifyUserPassword());
//		}
//		
//	}
//
//	/*******************************************************
//
//		ContactServiceUnitest  start
//
//	********************************************************/
//
//	ContactServiceUnitest contact;
//	TEST(ContactServiceUnitest, addContact) {
//		EXPECT_EQ(134, contact.addContact());
//	}
//	TEST(ContactServiceUnitest, addContactNoVerify) {
//		EXPECT_EQ(0, contact.addContactNoVerify());
//	}
//	TEST(ContactServiceUnitest, getVerifyType) {
//		EXPECT_EQ(0, contact.getVerifyType());
//	}
//	TEST(ContactServiceUnitest, removeContact) {
//		EXPECT_EQ(40002, contact.removeContact());
//	}
//	TEST(ContactServiceUnitest, updateContactInfo) {
//		EXPECT_EQ(138, contact.updateContactInfo());
//	}
//	TEST(ContactServiceUnitest, getContactList) {
//		EXPECT_TRUE(contact.getContactList());
//	}
//	TEST(ContactServiceUnitest, regContactOnline) {
//		EXPECT_FALSE(contact.regContactOnline());
//	}
//	TEST(ContactServiceUnitest, getContactOnline) {
//		EXPECT_EQ(0, contact.getContactOnline());
//	}
//	TEST(ContactServiceUnitest, getContactInfo) {
//		EXPECT_FALSE(contact.getContactInfo());
//	}
//	TEST(ContactServiceUnitest, contactIsBuddy) {
//		EXPECT_FALSE(contact.contactIsBuddy());
//	}
//	TEST(ContactServiceUnitest, getBlackList) {
//		EXPECT_EQ(0, contact.getBlackList());
//	}
//	TEST(ContactServiceUnitest, addBlackList) {
//		EXPECT_EQ(672, contact.addBlackList());
//	}
//	TEST(ContactServiceUnitest, removeBlackList) {
//		EXPECT_EQ(0, contact.removeBlackList());
//	}
//	TEST(ContactServiceUnitest, queryExtendedField) {
//		EXPECT_EQ(0, contact.queryExtendedField());
//	}
//	TEST(ContactServiceUnitest, queryExtendedFieldSync) {
//		EXPECT_TRUE(contact.queryExtendedFieldSync());
//	}
//	TEST(ContactServiceUnitest, postContact) {
//		EXPECT_EQ(0, contact.postContact());
//	}
//	TEST(ContactServiceUnitest, getLocalPhoneBook) {
//		EXPECT_TRUE(contact.getLocalPhoneBook());
//	}
//	TEST(ContactServiceUnitest, addLocalPhoneBook) {
//		EXPECT_TRUE(contact.addLocalPhoneBook());
//	}
//	TEST(ContactServiceUnitest, deleteLocalPhoneBook) {
//		EXPECT_TRUE(contact.deleteLocalPhoneBook());
//	}
//	TEST(ContactServiceUnitest, updateLocalPhoneBook) {
//		EXPECT_TRUE(contact.updateLocalPhoneBook());
//	}
//	TEST(ContactServiceUnitest, getBuddyInfoFromNet) {
//		EXPECT_EQ(0, contact.getBuddyInfoFromNet());
//	}
//	TEST(ContactServiceUnitest, oneWayBuddy) {
//		EXPECT_EQ(0, contact.oneWayBuddy());
//	}
//	TEST(ContactServiceUnitest, makeVerifyCode) {
//
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, contact.makeVerifyCode());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(100001717, contact.makeVerifyCode());
//		}
//		else
//		{
//			EXPECT_EQ(100001717, contact.makeVerifyCode());
//		}
//	}
//#ifndef SDK_FOR_ANDROID
//	TEST(ContactServiceUnitest, isInviteCode) {
//		EXPECT_TRUE(contact.isInviteCode());
//	}
//#endif
//	TEST(ContactServiceUnitest, canMakeVerifyCode) {
//
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, contact.canMakeVerifyCode());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(100001717, contact.canMakeVerifyCode());
//		}
//		else
//		{
//			EXPECT_EQ(100001717, contact.canMakeVerifyCode());
//		}
//	}
//	TEST(ContactServiceUnitest, verifyCodeValid) {
//		EXPECT_EQ(100001715, contact.verifyCodeValid());
//	}
//	TEST(ContactServiceUnitest, getUserIdByInviteCode) {
//		EXPECT_EQ(100001715, contact.getUserIdByInviteCode());
//	}
//	TEST(ContactServiceUnitest, devKickOff) {
//
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, contact.devKickOff());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(100008003, contact.devKickOff());
//		}
//		else
//		{
//			EXPECT_EQ(100008003, contact.devKickOff());
//		}
//	}
//	TEST(ContactServiceUnitest, getDeviceOnline) {
//		EXPECT_EQ(0, contact.getDeviceOnline());
//	}
//	TEST(ContactServiceUnitest, verifyUserInfoField) {
//
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(100008005, contact.verifyUserInfoField());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(100008004, contact.verifyUserInfoField());
//		}
//		else
//		{
//			EXPECT_EQ(100008005, contact.verifyUserInfoField());
//		}
//	}
//	TEST(ContactServiceUnitest, getBuddySetting) {
//		EXPECT_EQ(0, contact.getBuddySetting());
//	}
//
//	/*TEST(ContactServiceUnitest, setServerAlias) {
//		EXPECT_EQ(0, contact.setServerAlias());
//	}
//	TEST(ContactServiceUnitest, getServerAlias) {
//		EXPECT_EQ(0, contact.getServerAlias());
//	}
//	TEST(ContactServiceUnitest, saveElevatorAuthority) {
//		EXPECT_EQ(0, contact.saveElevatorAuthority());
//	}
//	TEST(ContactServiceUnitest, deleteElevator) {
//		EXPECT_EQ(0, contact.deleteElevator());
//	}
//	TEST(ContactServiceUnitest, selectElevatorAuthorityAll) {
//		EXPECT_EQ(0, contact.selectElevatorAuthorityAll());
//	}
//	TEST(ContactServiceUnitest, queryElevatorAuthorityReal) {
//		EXPECT_EQ(0, contact.queryElevatorAuthorityReal());
//	}
//	TEST(ContactServiceUnitest, listElevatorRecord) {
//		EXPECT_EQ(0, contact.listElevatorRecord());
//	}
//	TEST(ContactServiceUnitest, getTagStrategyFromNet) {
//		EXPECT_EQ(0, contact.getTagStrategyFromNet());
//	}
//	TEST(ContactServiceUnitest, selectElevatorAuthority) {
//		EXPECT_EQ(0, contact.selectElevatorAuthority());
//	}
//	*/
//	/*************************************************
//
//	//	ConfigServiceUnitest start
//
//	***************************************************/
//	ConfigServiceUnitest config;
//	TEST(ConfigServiceUnitest, init) {
//		bool isOk;
//		if (config.init() > 0) {
//			isOk = true;
//		}
//		EXPECT_TRUE(isOk);
//	}
//	TEST(ConfigServiceUnitest, uninit) {
//		EXPECT_TRUE(config.uninit());
//	}
//	TEST(ConfigServiceUnitest, setUserRcPath) {
//		EXPECT_TRUE(config.setUserRcPath());
//	}
//	TEST(ConfigServiceUnitest, setLoginInfo) {
//		EXPECT_TRUE(config.setLoginInfo());
//	}
//	TEST(ConfigServiceUnitest, getLoginInfos) {
//		EXPECT_TRUE(config.getLoginInfos());
//	}
//	TEST(ConfigServiceUnitest, delLoginInfo) {
//		EXPECT_FALSE(config.delLoginInfo());
//	}
//	TEST(ConfigServiceUnitest, setNetProxy) {
//		EXPECT_TRUE(config.setNetProxy());
//	}
//	TEST(ConfigServiceUnitest, getNetProxy) {
//		EXPECT_TRUE(config.getNetProxy());
//	}
//	TEST(ConfigServiceUnitest, setPlugPower) {
//		EXPECT_FALSE(config.setPlugPower());
//	}
//	TEST(ConfigServiceUnitest, setNetStatus) {
//		EXPECT_TRUE(config.setNetStatus());
//	}
//	TEST(ConfigServiceUnitest, getSdkVersion) {
//		EXPECT_TRUE(config.getSdkVersion());
//	}
//	TEST(ConfigServiceUnitest, setAppVersion) {
//		EXPECT_TRUE(config.setAppVersion());
//	}
//	TEST(ConfigServiceUnitest, setTextCoding) {
//		EXPECT_TRUE(config.setTextCoding());
//	}
//	TEST(ConfigServiceUnitest, setAppName) {
//		EXPECT_TRUE(config.setAppName());
//	}
//	TEST(ConfigServiceUnitest, headImgPath) {
//		EXPECT_TRUE(config.headImgPath());
//	}
//#ifndef SDK_FOR_ANDROID
//	TEST(ConfigServiceUnitest, getUserRcPath) {
//		EXPECT_FALSE(config.getUserRcPath());
//	}
//#endif
//	TEST(ConfigServiceUnitest, userImgPath) {
//		EXPECT_TRUE(config.userImgPath());
//	}
//	TEST(ConfigServiceUnitest, userAudioPath) {
//		EXPECT_TRUE(config.userAudioPath());
//	}
//	TEST(ConfigServiceUnitest, userVideoPath) {
//		EXPECT_TRUE(config.userVideoPath());
//	}
//	TEST(ConfigServiceUnitest, userCachePath) {
//		EXPECT_TRUE(config.userCachePath());
//	}
//	TEST(ConfigServiceUnitest, userFilePath) {
//		EXPECT_TRUE(config.userFilePath());
//	}
//	TEST(ConfigServiceUnitest, userEmotionPath) {
//		EXPECT_TRUE(config.userEmotionPath());
//	}
//	TEST(ConfigServiceUnitest, getMsgParserMode) {
//		EXPECT_TRUE(config.getMsgParserMode());
//	}
//	TEST(ConfigServiceUnitest, getLoginExData) {
//		EXPECT_TRUE(config.getLoginExData());
//	}
//	TEST(ConfigServiceUnitest, setScreenStatus) {
//		EXPECT_TRUE(config.setScreenStatus());
//	}
//	TEST(ConfigServiceUnitest, getSubServerInfo) {
//		EXPECT_TRUE(config.getSubServerInfo());
//	}
//	TEST(ConfigServiceUnitest, setSubServerInfo) {
//		EXPECT_TRUE(config.setSubServerInfo());
//	}
//	//TEST(ConfigServiceUnitest, getLastPreLoginData) {
//		//EXPECT_TRUE(beforeconfig.getLastPreLoginData());
//	//}
//	TEST(ConfigServiceUnitest, reNotifyData) {
//		EXPECT_TRUE(config.reNotifyData());
//	}
//	TEST(ConfigServiceUnitest, getIsRoming) {
//		EXPECT_FALSE(config.getIsRoming());
//	}
//	TEST(ConfigServiceUnitest, setTicket) {
//		EXPECT_TRUE(config.setTicket());
//	}
//	//TEST(DISABLED_Interface, getLastPreLogin) {
//		//EXPECT_TRUE(beforeconfig.getLastPreLogin());
//	//}
//	TEST(ConfigServiceUnitest, setMultichannel) {
//		EXPECT_FALSE(config.setMultichannel());
//	}
//	TEST(ConfigServiceUnitest, getPreloginInfoEx) {
//		EXPECT_TRUE(config.getPreloginInfoEx());
//	}
//	TEST(ConfigServiceUnitest, setOffloginSwitch) {
//		EXPECT_TRUE(config.setOffloginSwitch());
//	}
//	TEST(ConfigServiceUnitest, getOffloginStatus) {
//		EXPECT_TRUE(config.getOffloginStatus());
//	}
//	TEST(ConfigServiceUnitest, getIsOpenSecPlugin) {
//		EXPECT_FALSE(config.getIsOpenSecPlugin());
//	}
//	TEST(ConfigServiceUnitest, setHideBuddySwitch) {
//		EXPECT_TRUE(config.setHideBuddySwitch());
//	}
//	TEST(ConfigServiceUnitest, setCloudAddr) {
//		EXPECT_TRUE(config.setCloudAddr());
//	}
//	TEST(ConfigServiceUnitest, setCloudUploadSpeed) {
//		EXPECT_TRUE(config.setCloudUploadSpeed());
//	}
//	TEST(ConfigServiceUnitest, setCloudDownloadSpeed) {
//		EXPECT_TRUE(config.setCloudDownloadSpeed());
//	}
//	TEST(ConfigServiceUnitest, setDevelopmentMode) {
//		EXPECT_TRUE(config.setDevelopmentMode());
//	}
//
//
//	/*************************************************
//	
//	//	ChatServiceUnitest start
//
//	***************************************************/
//
//
//	ChatServiceUnitest chat;
//	TEST(ChatServiceUnitest, getChatList) {
//		EXPECT_TRUE(chat.getChatList());
//	}
//	TEST(ChatServiceUnitest, removeChat) {
//		EXPECT_EQ(0, chat.removeChat());
//	}
//	/*TEST(ChatServiceUnitest, sendAppendixMessage) {
//		if (m_config->m_server == "im") {
//			int code = chat.sendAppendixMessage();
//			bool isOk = (code == 0 || code == 536);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, chat.sendAppendixMessage());
//		}
//	}*/
//	TEST(DISABLED_Interface, insertMessage) {
//		EXPECT_EQ(0, chat.insertMessage());
//	}
//	TEST(ChatServiceUnitest, transferMessage) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, chat.transferMessage());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(451, chat.transferMessage());
//		}
//		else
//		{
//			EXPECT_EQ(451, chat.transferMessage());
//		}
//	}
//	TEST(ChatServiceUnitest, forwardMessage) {
//		EXPECT_TRUE(chat.forwardMessage());
//	}
//	TEST(ChatServiceUnitest, deleteAllMessage) {
//		EXPECT_EQ(0, chat.deleteAllMessage());
//	}
//	TEST(ChatServiceUnitest, deleteMessageById) {
//		EXPECT_EQ(0, chat.deleteMessageById());
//	}
//	TEST(ChatServiceUnitest, deleteMessageByTime) {
//		EXPECT_EQ(0, chat.deleteMessageByTime());
//	}
//	TEST(ChatServiceUnitest, setMessageRead) {
//		EXPECT_TRUE(chat.setMessageRead());
//	}
//	TEST(ChatServiceUnitest, setMessageUnRead) {
//		EXPECT_EQ(0, chat.setMessageUnRead());
//	}
//	TEST(ChatServiceUnitest, getMessages) {
//		EXPECT_TRUE(chat.getMessages());
//	}
//	TEST(ChatServiceUnitest, chatTop) {
//		EXPECT_EQ(0, chat.chatTop());
//	}
//	TEST(ChatServiceUnitest, getImgMsg) {
//		EXPECT_EQ(0, chat.getImgMsg());
//	}
//	TEST(ChatServiceUnitest, getUrlInfo) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(100001801, chat.getUrlInfo());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(170, chat.getUrlInfo());
//		}
//		else
//		{
//			EXPECT_EQ(170, chat.getUrlInfo());
//		}
//	}
//	TEST(ChatServiceUnitest, setPrivateKey) {
//		EXPECT_EQ(0, chat.setPrivateKey());
//	}
//	TEST(ChatServiceUnitest, decryptMsg) {
//		EXPECT_EQ(0, chat.decryptMsg());
//	}
//	TEST(ChatServiceUnitest, updateMsg) {
//		EXPECT_EQ(0, chat.updateMsg());
//	}
//	TEST(ChatServiceUnitest, addRecontact) {
//		EXPECT_EQ(0, chat.addRecontact());
//	}
//	TEST(ChatServiceUnitest, getMsgDays) {
//		EXPECT_EQ(0, chat.getMsgDays());
//	}
//	TEST(ChatServiceUnitest, getMsgFromDay) {
//		EXPECT_EQ(0, chat.getMsgFromDay());
//	}
//	TEST(ChatServiceUnitest, getAllMsgCount) {
//		EXPECT_EQ(0, chat.getAllMsgCount());
//	}
//	TEST(DISABLED_Interface, sendShortMessage) {
//		EXPECT_TRUE(chat.sendShortMessage());
//	}
//	TEST(ChatServiceUnitest, getGroupMsgReadState) {
//		EXPECT_TRUE(chat.getGroupMsgReadState());
//	}
//	TEST(ChatServiceUnitest, getGroupMsgUnreadCounter) {
//		EXPECT_TRUE(chat.getGroupMsgUnreadCounter());
//	}
//	TEST(ChatServiceUnitest, getGroupMsgUnreadInfo) {
//		EXPECT_EQ(0, chat.getGroupMsgUnreadInfo());
//	}
//	TEST(ChatServiceUnitest, getGroupDivers) {
//		EXPECT_EQ(0, chat.getGroupDivers());
//
//	}
//	TEST(ChatServiceUnitest, getContractMaxReadId) {
//		EXPECT_EQ(0, chat.getContractMaxReadId());
//	}
//	TEST(ChatServiceUnitest, getUnReadMsgCountByType) {
//		EXPECT_TRUE(chat.getUnReadMsgCountByType());
//	}
//	TEST(ChatServiceUnitest, sendMsgInputState) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, chat.sendMsgInputState());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(0, chat.sendMsgInputState());
//		}
//		else
//		{
//			EXPECT_EQ(451, chat.sendMsgInputState());
//		}
//	}
//	TEST(ChatServiceUnitest, getAtMessage) {
//		EXPECT_EQ(0, chat.getAtMessage());
//	}
//	TEST(ChatServiceUnitest, setMsgReads) {
//		EXPECT_EQ(0, chat.setMsgReads());
//	}
//	TEST(ChatServiceUnitest, getBadWordList) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_FALSE(chat.getBadWordList());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_FALSE(chat.getBadWordList());
//		}
//		else
//		{
//			EXPECT_TRUE(chat.getBadWordList());
//		}
//	}
//	TEST(ChatServiceUnitest, getIssueById) {
//		EXPECT_EQ(0, chat.getIssueById());
//	}
//	TEST(ChatServiceUnitest, searchIssueLocal) {
//		EXPECT_EQ(0, chat.searchIssueLocal());
//	}
//	TEST(ChatServiceUnitest, getIssueMessages) {
//		EXPECT_EQ(0, chat.getIssueMessages());
//	}
//	TEST(ChatServiceUnitest, deleteIssueLocal) {
//		EXPECT_EQ(0, chat.deleteIssueLocal());
//	}
//	TEST(ChatServiceUnitest, setGroupAnnouncementMsgReaded) {
//		EXPECT_EQ(0, chat.setGroupAnnouncementMsgReaded());
//	}
//	TEST(ChatServiceUnitest, getMsgByType) {
//		EXPECT_EQ(0, chat.getMsgByType());
//	}
//	TEST(ChatServiceUnitest, getTaskMsg) {
//		EXPECT_EQ(0, chat.getTaskMsg());
//	}
//	TEST(ChatServiceUnitest, MakeCombineMsg) {
//		EXPECT_TRUE(chat.MakeCombineMsg());
//	}
//	TEST(DISABLED_Interface, ParseCombineMsg) {
//		EXPECT_TRUE(chat.ParseCombineMsg());
//	}
//	TEST(DISABLED_Interface, toCombineMsg) {
//		EXPECT_TRUE(chat.toCombineMsg());
//	}
//	TEST(DISABLED_Interface, toNotebookMsg) {
//		EXPECT_TRUE(chat.toNotebookMsg());
//	}
//	TEST(ChatServiceUnitest, setGroupTopMsg) {
//		EXPECT_TRUE(chat.setGroupTopMsg());
//	}
//	TEST(ChatServiceUnitest, getGroupTopMsgById) {
//		EXPECT_EQ(0, chat.getGroupTopMsgById());
//	}
//	TEST(ChatServiceUnitest, isGroupTopMsgSync) {
//		EXPECT_FALSE(chat.isGroupTopMsgSync());
//	}
//	TEST(ChatServiceUnitest, createReminderMsg) {
//		EXPECT_EQ(0, chat.createReminderMsg());
//	}
//	TEST(ChatServiceUnitest, getReminderMsgByPage) {
//		EXPECT_EQ(0, chat.getReminderMsgByPage());
//	}
//	TEST(ChatServiceUnitest, deleteReminderMsg) {
//		EXPECT_EQ(100013003, chat.deleteReminderMsg());
//	}
//	TEST(ChatServiceUnitest, upMsgCount) {
//		EXPECT_EQ(0, chat.upMsgCount());
//	}
//
//
//	/*************************************************
//
//	//	SysmsgServiceUnitest start
//
//	***************************************************/
//
//
//	SysmsgServiceUnitest sysmsg;
//	TEST(ChatServiceUnitest, respToAddBuddy) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(100, sysmsg.respToAddBuddy());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(170, sysmsg.respToAddBuddy());
//		}
//		else
//		{
//			EXPECT_EQ(170, sysmsg.respToAddBuddy());
//		}
//	}
//	TEST(ChatServiceUnitest, adminRespToEnterGroup) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(100, sysmsg.adminRespToEnterGroup());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(320, sysmsg.adminRespToEnterGroup());
//		}
//		else
//		{
//			EXPECT_EQ(320, sysmsg.adminRespToEnterGroup());
//		}
//	}
//	TEST(ChatServiceUnitest, adminRespToEnterGroupEx) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(100, sysmsg.adminRespToEnterGroupEx());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(320, sysmsg.adminRespToEnterGroupEx());
//		}
//		else
//		{
//			EXPECT_EQ(320, sysmsg.adminRespToEnterGroupEx());
//		}
//	}
//	TEST(ChatServiceUnitest, userRespToEnterGroup) {
//		EXPECT_EQ(320, sysmsg.userRespToEnterGroup());
//	}
//	TEST(ChatServiceUnitest, userRespToEnterGroupEx) {
//		if (m_config->m_server == "vrv") {
//			int code = sysmsg.userRespToEnterGroupEx();
//			bool isOk = (code == 100 || code == 320);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(320, sysmsg.userRespToEnterGroupEx());
//		}
//		else
//		{
//			EXPECT_EQ(320, sysmsg.userRespToEnterGroupEx());
//		}
//	}
//	TEST(ChatServiceUnitest, userRespToEnterGroupforHL) {
//		EXPECT_EQ(320, sysmsg.userRespToEnterGroupforHL());
//	}
//	TEST(ChatServiceUnitest, userRespToEnterGroupforHLEx) {
//		EXPECT_EQ(320, sysmsg.userRespToEnterGroupforHLEx());
//	}
//	TEST(ChatServiceUnitest, deleteMessageByType) {
//		EXPECT_EQ(0, sysmsg.deleteMessageByType());
//	}
//	TEST(ChatServiceUnitest, setMessagRead) {
//		EXPECT_EQ(0, sysmsg.setMessagRead());
//	}
//
//	/*******************************************************
//
//		FileServiceUnitest  start
//
//	//********************************************************/
//
//	FileServiceUnitest file;
//
//	TEST(FileServiceUnitest, regProcessCb) {
//		EXPECT_EQ(0, file.regProcessCb());
//	}
//	TEST(FileServiceUnitest, regP2pUserStatusChgCb) {
//		EXPECT_EQ(0, file.regP2pUserStatusChgCb());
//	}
//
//	TEST(FileServiceUnitest, regP2pSendFileReqCb) {
//		EXPECT_EQ(0, file.regP2pSendFileReqCb());
//	}
//	TEST(FileServiceUnitest, regP2pFileTransOpCb) {
//		EXPECT_EQ(0, file.regP2pFileTransOpCb());
//	}
//#ifndef SDK_FOR_ANDROID
//	TEST(FileServiceUnitest, uploadAvatar) {
//		EXPECT_TRUE(file.uploadAvatar());
//	}
//	TEST(FileServiceUnitest, uploadBackground) {
//		EXPECT_TRUE(file.uploadBackground());
//	}
//	TEST(FileServiceUnitest, uploadFile) {
//		EXPECT_TRUE(file.uploadFile());
//	}
//	TEST(FileServiceUnitest, uploadShareFile) {
//		int code = file.uploadShareFile();
//		bool isOk;
//		if (m_config->m_server == "bxy") {
//			isOk = (code == -16777169 || code == -16777161);
//			EXPECT_TRUE(isOk);
//		}
//		else
//		EXPECT_EQ(-16777161, file.uploadShareFile());
//	}
//	TEST(FileServiceUnitest, uploadImage) {
//		EXPECT_TRUE(file.uploadImage());
//	}
//	TEST(FileServiceUnitest, uploadShareImage) {
//		EXPECT_TRUE(file.uploadShareImage());
//	}
//#endif
//	TEST(FileServiceUnitest, downloadFile) {
//		if (m_config->m_server == "im")
//		{
//			int temp = file.downloadFile();
//			bool code = (temp == -1 || temp == 0);
//			EXPECT_TRUE(code);
//		}else
//		{
//			EXPECT_EQ(0, file.downloadFile());
//		}
//		
//	}
//	TEST(FileServiceUnitest, downloadExternalFile) {
//		EXPECT_EQ(0, file.downloadExternalFile());
//	}
//	TEST(FileServiceUnitest, downloadImage) {
//		EXPECT_EQ(0, file.downloadImage());
//	}
//	TEST(FileServiceUnitest, downloadNineBoxImage2) {
//		EXPECT_EQ(0, file.downloadNineBoxImage2());
//	}
//	TEST(FileServiceUnitest, downloadNineBoxImage) {
//		EXPECT_EQ(0, file.downloadNineBoxImage());
//	}
//	TEST(FileServiceUnitest, downloadImage2) {
//		EXPECT_EQ(0, file.downloadImage2());
//	}
//	TEST(FileServiceUnitest, encryptFile) {
//		EXPECT_TRUE(file.encryptFile());
//	}
//	TEST(FileServiceUnitest, decryptFile) {
//		EXPECT_TRUE(file.decryptFile());
//	}
//	TEST(FileServiceUnitest, compress) {
//		EXPECT_TRUE(file.compress());
//	}
//	TEST(FileServiceUnitest, uncompress) {
//		EXPECT_TRUE(file.uncompress());
//	}
//	TEST(FileServiceUnitest, getFileList1) {
//		EXPECT_EQ(0, file.getFileList1());
//
//	}
//	TEST(DISABLED_Interface, getFileList2) {
//		EXPECT_EQ(0, file.getFileList2());
//	}
//	TEST(FileServiceUnitest, getFilesInfo) {
//		EXPECT_EQ(0, file.getFilesInfo());
//	}
//	TEST(FileServiceUnitest, isTransmitting) {
//		EXPECT_FALSE(file.isTransmitting());
//	}
//	TEST(FileServiceUnitest, isTransmittingInTarget) {
//		EXPECT_FALSE(file.isTransmittingInTarget());
//	}
//
//	TEST(FileServiceUnitest, getAlreadyDownload) {
//		EXPECT_FALSE(file.getAlreadyDownload());
//
//	}
//	TEST(FileServiceUnitest, checkUrlValid) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(-16777206, file.checkUrlValid());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(-16777206, file.checkUrlValid());
//		}
//		else
//		{
//			EXPECT_EQ(-16777206, file.checkUrlValid());
//		}
//	}
//
//
//
//	TEST(FileServiceUnitest, queryFileValid) {
//		if (m_config->m_server == "im") {
//			int code = file.queryFileValid();
//			bool isOk = (code == 0 || code == 11100);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, file.queryFileValid());
//		}
//
//	}
//	TEST(FileServiceUnitest, reduceImage) {
//		EXPECT_EQ(0, file.reduceImage());
//	}
//	TEST(FileServiceUnitest, putShowMarkOnImage) {
//		EXPECT_EQ(0, file.putShowMarkOnImage());
//	}
//	TEST(FileServiceUnitest, putMarkOnImageSimple) {
//		EXPECT_EQ(0, file.putMarkOnImageSimple());
//	}
//	TEST(FileServiceUnitest, getMarkFromImageSimple) {
//		int code = file.getMarkFromImageSimple();
//		if (code > 0)
//		{
//			EXPECT_EQ(0, 0);
//		}
//		else
//		{
//			EXPECT_EQ(0, code);
//		}
//	}
//	TEST(FileServiceUnitest, putMarkOnImageFFT) {
//		EXPECT_EQ(0, file.putMarkOnImageFFT());
//	}
//	TEST(FileServiceUnitest, getMarkFromImageFFT) {
//		EXPECT_EQ(0, file.getMarkFromImageFFT());
//
//	}
//	TEST(FileServiceUnitest, delayFiles) {
//		if (m_config->m_server == "im") {
//			int code = file.delayFiles();
//			bool isOk = (code == 0 || code == 11100);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, file.delayFiles());
//		}
//
//	}
//	TEST(FileServiceUnitest, getNameByUrl) {
//		EXPECT_TRUE(file.getNameByUrl());
//
//	}
//	TEST(FileServiceUnitest, migrateUserData) {
//	EXPECT_EQ(0, file.migrateUserData());
//	}
//	TEST(FileServiceUnitest, migrateUserDataNew) {
//	EXPECT_EQ(0, file.migrateUserDataNew());
//	}
//
//
//
//	/*******************************************************
//
//	//	UserServiceUnitest  start
//
//	********************************************************/
//
//	UserServiceUnitest user;
//#ifndef SDK_FOR_ANDROID
//	TEST(UserServiceUnitest, getAccountInfo) {
//		EXPECT_EQ(0, user.getAccountInfo());
//	}
//#endif
//	TEST(UserServiceUnitest, updateAccountInfo) {
//		EXPECT_EQ(0, user.updateAccountInfo());
//	}
//	TEST(UserServiceUnitest, setSetting) {
//		EXPECT_EQ(0, user.setSetting());
//	}
//	TEST(UserServiceUnitest, getSetting) {
//		EXPECT_EQ(0, user.getSetting());
//	}
//	TEST(UserServiceUnitest, getHiddenTarget) {
//		EXPECT_EQ(0, user.getHiddenTarget());
//	}
//	TEST(UserServiceUnitest, setHiddenTarget) {
//		EXPECT_EQ(0, user.setHiddenTarget());
//	}
//	TEST(UserServiceUnitest, delHiddenTarget) {
//		EXPECT_EQ(0, user.delHiddenTarget());
//	}
//	TEST(UserServiceUnitest, changeHiddenPasswd) {
//		EXPECT_TRUE(user.changeHiddenPasswd());
//	}
//	TEST(UserServiceUnitest, getGlobalNoDisturbMode) {
//		EXPECT_EQ(0, user.getGlobalNoDisturbMode());
//	}
//	TEST(UserServiceUnitest, setGolbalNoDisturbMode) {
//		EXPECT_EQ(0, user.setGolbalNoDisturbMode());
//	}
//	TEST(UserServiceUnitest, getGlobalNoDisturbListMode) {
//		EXPECT_EQ(0, user.getGlobalNoDisturbListMode());
//	}
//	TEST(UserServiceUnitest, setGolbalNoDisturbListMode) {
//		EXPECT_EQ(0, user.setGolbalNoDisturbListMode());
//	}
//	TEST(UserServiceUnitest, getUserNoDisturbMode) {
//		EXPECT_EQ(0, user.getUserNoDisturbMode());
//	}
//	TEST(UserServiceUnitest, setUserNoDisturbMode) {
//		if (m_config->m_server == "im") {
//			EXPECT_EQ(98, user.setUserNoDisturbMode());
//		}
//		else {
//			EXPECT_EQ(0, user.setUserNoDisturbMode());
//		}
//
//	}
//	TEST(UserServiceUnitest, getMsgNotifyMode) {
//		EXPECT_EQ(0, user.getMsgNotifyMode());
//	}
//	TEST(UserServiceUnitest, setMsgNotifyMode) {
//		if (m_config->m_server == "im") {
//			EXPECT_EQ(98, user.setMsgNotifyMode());
//		}
//		else {
//			EXPECT_EQ(0, user.setMsgNotifyMode());
//		}
//	}
//	TEST(UserServiceUnitest, getServerTime) {
//		EXPECT_EQ(0, user.getServerTime());
//	}
//	TEST(UserServiceUnitest, getServerTimeSync) {
//		EXPECT_TRUE(user.getServerTimeSync());
//	}
//	TEST(UserServiceUnitest, addLocalSetting) {
//		EXPECT_TRUE(user.addLocalSetting());
//	}
//	TEST(UserServiceUnitest, addLocalSettingSync) {
//		EXPECT_TRUE(user.addLocalSettingSync());
//	}
//	TEST(UserServiceUnitest, getLocalSetting) {
//		EXPECT_EQ(0, user.getLocalSetting());
//	}
//	TEST(UserServiceUnitest, getLocalSettingSync) {
//		EXPECT_TRUE(user.getLocalSettingSync());
//	}
//	TEST(UserServiceUnitest, updateLocalSetting) {
//		EXPECT_EQ(0, user.updateLocalSetting());
//	}
//	TEST(UserServiceUnitest, updateLocalSettingSync) {
//		EXPECT_TRUE(user.updateLocalSettingSync());
//	}
//	TEST(UserServiceUnitest, setLocalSetting) {
//		EXPECT_EQ(0, user.setLocalSetting());
//	}
//	TEST(UserServiceUnitest, setLocalSettingSync) {
//		EXPECT_TRUE(user.setLocalSettingSync());
//	}
//	TEST(UserServiceUnitest, deleteLocalSetting) {
//		EXPECT_EQ(0, user.deleteLocalSetting());
//	}
//	TEST(DISABLED_Interface, setPersonalData) {
//		EXPECT_EQ(0, user.setPersonalData());
//	}
//	TEST(DISABLED_Interface, getPersonalData) {
//		EXPECT_EQ(0, user.getPersonalData());
//	}
//	TEST(UserServiceUnitest, getAppInfo) {
//		EXPECT_EQ(0, user.getAppInfo());
//	}
//	TEST(UserServiceUnitest, queryMarketApplication) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, user.queryMarketApplication());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, user.queryMarketApplication());
//		}
//		else {
//			EXPECT_EQ(11100, user.queryMarketApplication());
//		}
//	}
//	TEST(UserServiceUnitest, sendTrackInfo) {
//
//		if (m_config->m_server == "im") {
//			EXPECT_TRUE(1);
//		}
//		else if(m_config->m_server == "bxy") {
//			EXPECT_EQ(0, user.sendTrackInfo());
//		}
//		else {
//			EXPECT_EQ(100, user.sendTrackInfo());
//		}
//	}
//	TEST(UserServiceUnitest, addOrDeleteApplication) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, user.addOrDeleteApplication());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(-2, user.addOrDeleteApplication());
//		}
//		else
//		{
//			EXPECT_EQ(-2, user.addOrDeleteApplication());
//		}
//
//	}
//	TEST(UserServiceUnitest, getInstalledApplication) {
//		EXPECT_EQ(0, user.getInstalledApplication());
//	}
//	TEST(UserServiceUnitest, QueryEmoticonPackageByLabel) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, user.QueryEmoticonPackageByLabel());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.QueryEmoticonPackageByLabel());
//		}
//		else
//		{
//			EXPECT_EQ(0, user.QueryEmoticonPackageByLabel());
//		}
//	
//	}
//	TEST(UserServiceUnitest, queryEmoticon) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100, user.queryEmoticon());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.queryEmoticon());
//		}
//		else
//		{
//			EXPECT_EQ(0, user.queryEmoticon());
//		}
//	}
//	TEST(UserServiceUnitest, singleQueryEmoticonPackage) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, user.singleQueryEmoticonPackage());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.singleQueryEmoticonPackage());
//		}
//		else
//		{
//			EXPECT_EQ(0, user.singleQueryEmoticonPackage());
//		}
//	}
//	TEST(UserServiceUnitest, pageQueryEmoticon) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, user.pageQueryEmoticon());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.pageQueryEmoticon());
//		}
//		else 
//		{
//			EXPECT_EQ(0, user.pageQueryEmoticon());
//		}
//
//	}
//	TEST(UserServiceUnitest, addOrDeleteCustomEmoticon) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100, user.addOrDeleteCustomEmoticon());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.addOrDeleteCustomEmoticon());
//		}
//		else 
//		{
//			EXPECT_EQ(0, user.addOrDeleteCustomEmoticon());
//		}
//
//	}
//	TEST(DISABLED_Interface,transLocalData) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, user.transLocalData());
//		}
//		else
//			EXPECT_EQ(-16777186, user.transLocalData());
//	}
//	TEST(UserServiceUnitest, setUserDefineVoice) {
//		EXPECT_EQ(0, user.setUserDefineVoice());
//	}
//	TEST(UserServiceUnitest, getUserDefineVoice) {
//		EXPECT_EQ(0, user.getUserDefineVoice());
//	}
//	TEST(UserServiceUnitest, getIdByAccount) {
//		EXPECT_EQ(0, user.getIdByAccount());
//	}
//	TEST(UserServiceUnitest, setOnlineState) {
//		EXPECT_EQ(0, user.setOnlineState());
//	}
//	TEST(UserServiceUnitest, setToken) {
//		EXPECT_EQ(0, user.setToken());
//	}
//	TEST(UserServiceUnitest, setOnlineStatus) {
//		EXPECT_EQ(0, user.setOnlineStatus());
//	}
//	TEST(UserServiceUnitest, setSessionPeerId) {
//		EXPECT_EQ(100, user.setSessionPeerId());
//	}
//	TEST(UserServiceUnitest, setTokens) {
//		EXPECT_EQ(0, user.setTokens());
//	}
//	TEST(UserServiceUnitest, setPushSwitch) {
//		EXPECT_EQ(0, user.setPushSwitch());
//	}
//	TEST(UserServiceUnitest, setUnReadCount) {
//		EXPECT_EQ(0, user.setUnReadCount());
//	}
//	TEST(UserServiceUnitest, getInstallDays) {
//		EXPECT_EQ(0, user.getInstallDays());
//	}
//	TEST(UserServiceUnitest, getEntAppInfo) {
//		EXPECT_EQ(0, user.getEntAppInfo());
//	}
//	TEST(UserServiceUnitest, circleOfFriend) {
//		EXPECT_EQ(-16777161, user.circleOfFriend());
//	}
//	TEST(UserServiceUnitest, queryUserIDByAccount) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100001801, user.queryUserIDByAccount());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.queryUserIDByAccount());
//		}
//		else
//		{
//			EXPECT_EQ(0, user.queryUserIDByAccount());
//		}
//	}
//	TEST(UserServiceUnitest, operOnlineExt) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100, user.operOnlineExt());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.operOnlineExt());
//		}
//		else
//		{
//			EXPECT_EQ(0, user.operOnlineExt());
//		}
//	}
//	TEST(UserServiceUnitest, queryOnlineExt) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100, user.queryOnlineExt());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.queryOnlineExt());
//		}
//		else
//		{
//			EXPECT_EQ(0, user.queryOnlineExt());
//		}
//	}
//	TEST(UserServiceUnitest, queryJson) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, user.queryJson());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(11100, user.queryJson());
//		}
//		else
//		{
//			EXPECT_EQ(11100, user.queryJson());
//		}
//	}
//	TEST(UserServiceUnitest, feedBack) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, user.feedBack());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(100021508, user.feedBack());
//		}
//		else {
//			EXPECT_EQ(100021508, user.feedBack());
//		}
//	}
//	TEST(UserServiceUnitest, getWorkBenchBanners) {
//		EXPECT_EQ(0, user.getWorkBenchBanners());
//	}
//	TEST(UserServiceUnitest, deleteLocalSettingSync) {
//		EXPECT_TRUE(user.deleteLocalSettingSync());
//	}
//	TEST(UserServiceUnitest, getHelpSystemInfo) {
//		EXPECT_EQ(0, user.getHelpSystemInfo());
//	}
//	TEST(UserServiceUnitest, updateExtendInfo) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, user.updateExtendInfo());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(181, user.updateExtendInfo());
//		}
//		else
//		{
//			EXPECT_EQ(0, user.updateExtendInfo());
//		}
//	}
//	TEST(UserServiceUnitest, queryUserIsExistList) {
//		EXPECT_EQ(0, user.queryUserIsExistList());
//	}
//	TEST(UserServiceUnitest, getOauthCode) {
//		EXPECT_EQ(100008003, user.getOauthCode());
//	}
//	TEST(UserServiceUnitest, createAppRoom) {
//		EXPECT_EQ(0, user.createAppRoom());
//	}
//	TEST(UserServiceUnitest, updateAppRoomInfo) {
//		EXPECT_EQ(0, user.updateAppRoomInfo());
//	}
//	TEST(UserServiceUnitest, updateAppRoomMem) {
//		EXPECT_EQ(0, user.updateAppRoomMem());
//	}
//	TEST(UserServiceUnitest, setAppOrder) {
//		EXPECT_EQ(0, user.setAppOrder());
//	}
//	TEST(UserServiceUnitest, getInstalledApplicationSorted) {
//		EXPECT_EQ(0, user.getInstalledApplicationSorted());
//	}
//	TEST(UserServiceUnitest, addLocalApp) {
//		EXPECT_TRUE(user.addLocalApp());
//	}
//	TEST(UserServiceUnitest, deleteLocalApp) {
//		EXPECT_EQ(0, user.deleteLocalApp());
//	}
//	TEST(UserServiceUnitest, getLocalAppList) {
//		EXPECT_EQ(0, user.getLocalAppList());
//	}
//	TEST(UserServiceUnitest, getDeviceLoginRecord) {
//		EXPECT_EQ(0, user.getDeviceLoginRecord());
//	}
//	TEST(UserServiceUnitest, deleteDeviceLoginRecord) {
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, user.deleteDeviceLoginRecord());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(100008007, user.deleteDeviceLoginRecord());
//		}
//		else
//		{
//			EXPECT_EQ(100008007, user.deleteDeviceLoginRecord());
//		}
//
//	}
//	TEST(UserServiceUnitest, getMarketAppSort) {
//		EXPECT_EQ(0, user.getMarketAppSort());
//	}
//	TEST(UserServiceUnitest, wakeUp) {
//		EXPECT_EQ(0, user.wakeUp());
//	}
//	TEST(UserServiceUnitest, getAgencyList) {
//		if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.getAgencyList());
//		}
//		else if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, user.getAgencyList());
//		}
//		else 
//		{
//			EXPECT_EQ(0, user.getAgencyList());
//		}
//
//	}
//	TEST(UserServiceUnitest, getLoginClientRecord) {
//		if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(0, user.getLoginClientRecord());
//		}
//		else if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(0, user.getLoginClientRecord());
//		}
//		else
//		{
//			EXPECT_EQ(0, user.getLoginClientRecord());
//		}
//
//	}
//	TEST(UserServiceUnitest, getSmallAppHelpFlagValue) {
//		if (m_config->m_server == "im")
//		{
//			EXPECT_EQ(0, user.getSmallAppHelpFlagValue());
//		}
//		else
//		EXPECT_EQ(0, user.getSmallAppHelpFlagValue());
//	}
//	TEST(UserServiceUnitest, getSmallAppHelpList) {
//		if (m_config->m_server == "im")
//		{
//			EXPECT_EQ(0, user.getSmallAppHelpList());
//		}
//		else
//		EXPECT_EQ(0, user.getSmallAppHelpList());
//	}
//	TEST(UserServiceUnitest, backupDB) {
//		EXPECT_TRUE(user.backupDB());
//	}
//
//	/*******************************************************
//
//	//  GroupServiceUnitest  start
//
//	********************************************************/
//	GroupServiceUnitest group;
//	TEST(GroupServiceUnitest, createGroup) {
//		int code = group.createGroup();
//		bool isOk;
//		if (m_config->m_server == "vrv") {
//			isOk = (code == 0 || code == 100011091);
//			EXPECT_TRUE(isOk);
//		}
//		else
//			EXPECT_EQ(0, group.createGroup());
//	}
//	TEST(GroupServiceUnitest, createGroupEx) {
//		int code = group.createGroupEx();
//		bool isOk;
//		if (m_config->m_server == "vrv") {
//			isOk = (code == 0 || code == 100011091);
//			EXPECT_TRUE(isOk);
//		}
//		else
//			EXPECT_EQ(0, group.createGroupEx());
//	}
//	TEST(GroupServiceUnitest, addGroup) {
//		EXPECT_EQ(333, group.addGroup());
//	}
//	TEST(GroupServiceUnitest, transferGroup) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(331, group.transferGroup());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(0, group.transferGroup());
//		}
//		else {
//			EXPECT_EQ(0, group.transferGroup());
//		}
//	}
//	TEST(GroupServiceUnitest, getGroupSet) {
//		EXPECT_EQ(0, group.getGroupSet());
//	}
//	TEST(GroupServiceUnitest, setGroupSet) {
//		EXPECT_EQ(304, group.setGroupSet());
//	}
//#ifndef SDK_FOR_ANDROID
//	TEST(GroupServiceUnitest, getGroupInfo) {
//		EXPECT_TRUE(group.getGroupInfo());
//	}
//	TEST(GroupServiceUnitest, setGroupInfo) {
//		EXPECT_EQ(304, group.setGroupInfo());
//	}
//#endif
//	TEST(GroupServiceUnitest, getGroupList) {
//		EXPECT_EQ(0, group.getGroupList());
//	}
//	TEST(GroupServiceUnitest, inviteMember) {
//		EXPECT_EQ(0, group.inviteMember());
//	}
//	TEST(GroupServiceUnitest, inviteMemberEx) {
//		EXPECT_EQ(0, group.inviteMemberEx());
//	}
//	TEST(GroupServiceUnitest, removeMember) {
//		EXPECT_EQ(313, group.removeMember());
//	}
//	TEST(GroupServiceUnitest, removeMembers) {
//		EXPECT_EQ(313, group.removeMembers());
//	}
//	TEST(GroupServiceUnitest, setMemberInfo) {
//		EXPECT_EQ(329, group.setMemberInfo());
//	}
//#ifndef SDK_FOR_ANDROID
//	TEST(GroupServiceUnitest, isInGroup) {
//		EXPECT_EQ(1, group.isInGroup());
//	}
//	TEST(GroupServiceUnitest, getMemberInfo) {
//		EXPECT_EQ(1, group.getMemberInfo());
//	}
//	TEST(GroupServiceUnitest, getMemberDetailInfo) {
//		EXPECT_EQ(0, group.getMemberDetailInfo());
//	}
//	TEST(GroupServiceUnitest, getMemberList) {
//		EXPECT_EQ(0, group.getMemberList());
//	}
//	TEST(GroupServiceUnitest, getMemberListNoDlHeadImg) {
//		EXPECT_EQ(0, group.getMemberListNoDlHeadImg());
//	}
//	TEST(GroupServiceUnitest, getGroupFileList_1) {
//		EXPECT_EQ(0, group.getGroupFileList_1());
//	}
//	TEST(GroupServiceUnitest, getGroupFileList_2) {
//		EXPECT_EQ(0, group.getGroupFileList_2());
//	}
//#endif
//	TEST(GroupServiceUnitest, deleteGroupFile) {
//		EXPECT_EQ(-16777199, group.deleteGroupFile());
//	}
//	TEST(GroupServiceUnitest, getPersonalGroupImg) {
//		EXPECT_EQ(0, group.getPersonalGroupImg());
//	}
//	TEST(GroupServiceUnitest, setPersonalGroupImg) {
//		EXPECT_EQ(0, group.setPersonalGroupImg());
//	}
//	TEST(GroupServiceUnitest, setGroupMsgRemindType) {
//		EXPECT_EQ(0, group.setGroupMsgRemindType());
//	}
//	TEST(GroupServiceUnitest, getGroupMsgRemindType) {
//		EXPECT_EQ(0, group.getGroupMsgRemindType());
//	}
//	TEST(GroupServiceUnitest, setGroupExtraInfo) {
//		int code = group.setGroupExtraInfo();
//		bool isOk;
//		if (m_config->m_server == "vrv") {
//			isOk = (code == 0 || code == 40002);
//			EXPECT_TRUE(isOk);
//		}
//		else
//			EXPECT_EQ(0, group.setGroupExtraInfo());
//	}
//	TEST(GroupServiceUnitest, getGroupOnlineStatus) {
//		EXPECT_TRUE(group.getGroupOnlineStatus());
//	}
//	TEST(GroupServiceUnitest, setGroupFileTerm) {
//
//		if (m_config->m_server == "vrv")
//		{
//			EXPECT_EQ(100008008, group.setGroupFileTerm());
//		}
//		else if (m_config->m_server == "bxy")
//		{
//			EXPECT_EQ(341, group.setGroupFileTerm());
//		}
//		else
//		{
//			EXPECT_EQ(341, group.setGroupFileTerm());
//		}
//	}
//	TEST(GroupServiceUnitest, addGroupAnnouncement) {
//		EXPECT_EQ(100011014, group.addGroupAnnouncement());
//	}
//	TEST(GroupServiceUnitest, delGroupAnnouncement) {
//		EXPECT_EQ(100011014, group.delGroupAnnouncement());
//	}
//	TEST(GroupServiceUnitest, checkGroupAnnouncementExist) {
//		EXPECT_EQ(0, group.checkGroupAnnouncementExist());
//	}
//	TEST(GroupServiceUnitest, getGroupAnnouncementList) {
//		EXPECT_EQ(0, group.getGroupAnnouncementList());
//	}
//	TEST(GroupServiceUnitest, setGroupBeepTone) {
//		EXPECT_EQ(0, group.setGroupBeepTone());
//	}
//	TEST(GroupServiceUnitest, getGroupBeepTone) {
//		EXPECT_EQ(0, group.getGroupBeepTone());
//	}
//	TEST(GroupServiceUnitest, setGroupChatForbid) {
//		EXPECT_EQ(100011022, group.setGroupChatForbid());
//	}
//	TEST(GroupServiceUnitest, isGroupMember) {
//		EXPECT_EQ(0, group.isGroupMember());
//	}
//	TEST(GroupServiceUnitest, removeGroup) {
//		int code = group.removeGroup();
//		bool isOk;
//		if (m_config->m_server == "vrv") {
//			isOk = (code == 0 || code == 307);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			isOk = (code == 0 || code == 307 || code == 50001);
//			EXPECT_TRUE(isOk);
//		}
//	}
//	TEST(GroupServiceUnitest, removeGroupEx) {
//		int code = group.removeGroupEx();
//		bool isOk;
//		if (m_config->m_server == "vrv") {
//			isOk = (code == 0 || code == 307);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			isOk = (code == 0 || code == 307||code == 50001);
//			EXPECT_TRUE(isOk);
//		}
//	}
//	/*************************************************
//
//		ExtService start
//
//	***************************************************/
//#ifndef SDK_FOR_ANDROID 
//	ExtServiceUnitest ext;
//	TEST(ExtServiceUnitest, sendTaskMsg) {
//		EXPECT_EQ(0, ext.sendTaskMsg());
//	}
//	TEST(ExtServiceUnitest, getApTask) {
//		EXPECT_EQ(0, ext.getApTask());
//	}
//	TEST(ExtServiceUnitest, getRecvTask) {
//		EXPECT_EQ(0, ext.getRecvTask());
//	}
//	TEST(ExtServiceUnitest, getHistoryTask) {
//		EXPECT_EQ(0, ext.getHistoryTask());
//	}
//	TEST(ExtServiceUnitest, getBodyTask) {
//		EXPECT_EQ(0, ext.getBodyTask());
//	}
//	TEST(ExtServiceUnitest, recoveryTask) {
//		EXPECT_EQ(0, ext.recoveryTask());
//	}
//	TEST(ExtServiceUnitest, finishTask) {
//		EXPECT_EQ(0, ext.finishTask());
//	}
//	TEST(ExtServiceUnitest, setReadTask) {
//		EXPECT_EQ(0, ext.setReadTask());
//	}
//	TEST(ExtServiceUnitest, getRecvMsg) {
//		EXPECT_EQ(0, ext.getRecvMsg());
//	}
//	TEST(ExtServiceUnitest, getTaskState) {
//		EXPECT_TRUE(ext.getTaskState());
//	}
//	TEST(ExtServiceUnitest, createRoom) {
//		int code = ext.createRoom();
//		bool isOk = (code == 0 || code == 110);
//		EXPECT_TRUE(isOk);
//	}
//	TEST(ExtServiceUnitest, changRoomName) {
//		EXPECT_EQ(0, ext.changRoomName());
//	}
//	TEST(ExtServiceUnitest, changRoomIcon) {
//		EXPECT_EQ(0, ext.changRoomIcon());
//	}
//	TEST(ExtServiceUnitest, deleRoom) {
//		EXPECT_EQ(0, ext.deleRoom());
//	}
//	TEST(ExtServiceUnitest, getRoom) {
//
//		EXPECT_EQ(0, ext.getRoom());
//	}
//	TEST(ExtServiceUnitest, getAllRoomSync) {
//		EXPECT_TRUE(ext.getAllRoomSync());
//	}
//	TEST(ExtServiceUnitest, topRoom) {
//		EXPECT_EQ(0, ext.topRoom());
//	}
//	TEST(ExtServiceUnitest, addRoomMember) {
//		EXPECT_EQ(0, ext.addRoomMember());
//	}
//	TEST(ExtServiceUnitest, delRoomMember) {
//		EXPECT_EQ(0, ext.delRoomMember());
//	}
//	TEST(ExtServiceUnitest, getVisibleOrgUsers) {
//		if (m_config->m_server == "vrv") {
//			int code = ext.getVisibleOrgUsers();
//			bool isOk = (code == -16777214 || code == 16004 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(0, ext.getVisibleOrgUsers());
//		}
//		else
//		{
//			int code = ext.getVisibleOrgUsers();
//			bool isOk = (code == -16777214 || code == 16004 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//	}
//	TEST(ExtServiceUnitest, getVisibleOrgUsersSync) {
//		EXPECT_TRUE(ext.getVisibleOrgUsersSync());
//	}
//	TEST(ExtServiceUnitest, queryEnterpriseUserlist) {
//		if (m_config->m_server == "vrv") {
//			int code = ext.queryEnterpriseUserlist();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(0, ext.queryEnterpriseUserlist());
//		}
//		else
//		{
//			int code = ext.queryEnterpriseUserlist();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//	}
//	TEST(ExtServiceUnitest, queryEntUserOneById) {
//		if (m_config->m_server == "vrv") {
//			int code = ext.queryEntUserOneById();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(0, ext.queryEntUserOneById());
//		}
//		else
//		{
//			int code = ext.queryEntUserOneById();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//	}
//	TEST(ExtServiceUnitest, queryEntUserOneByName) {
//		if (m_config->m_server == "vrv") {
//			int code = ext.queryEntUserOneByName();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(0, ext.queryEntUserOneByName());
//		}
//		else
//		{
//			int code = ext.queryEntUserOneByName();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//	}
//	TEST(ExtServiceUnitest, getOrgInfo) {
//		if (m_config->m_server == "vrv") {
//			int code = ext.getOrgInfo();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(0, ext.getOrgInfo());
//		}
//		else
//		{
//			int code = ext.getOrgInfo();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//	}
//	TEST(ExtServiceUnitest, getCustomChatList) {
//		EXPECT_EQ(0, ext.getCustomChatList());
//	}
//	TEST(ExtServiceUnitest, getOrgInfoSync) {
//		EXPECT_TRUE(ext.getOrgInfoSync());
//	}
//	TEST(ExtServiceUnitest, orgAndUserSearch) {
//		if (m_config->m_server == "vrv") {
//			int code = ext.orgAndUserSearch();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(0, ext.orgAndUserSearch());
//		}
//		else
//		{
//			int code = ext.orgAndUserSearch();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//	}
//	TEST(ExtServiceUnitest, getMsgCountByTargetID) {
//		EXPECT_EQ(0, ext.getMsgCountByTargetID());
//	}
//	TEST(ExtServiceUnitest, getMsgTopNGroup) {
//		EXPECT_EQ(0, ext.getMsgTopNGroup());
//	}
//	TEST(ExtServiceUnitest, getMsgTopNSession) {
//		EXPECT_EQ(0, ext.getMsgTopNSession());
//	}
//	TEST(ExtServiceUnitest, getMsgTopNAtGroup) {
//		EXPECT_EQ(0, ext.getMsgTopNAtGroup());
//	}
//	TEST(ExtServiceUnitest, addNote) {
//		EXPECT_EQ(0, ext.addNote());
//	}
//	TEST(ExtServiceUnitest, getNote) {
//		EXPECT_EQ(0, ext.getNote());
//	}
//	TEST(ExtServiceUnitest, delNote) {
//		EXPECT_EQ(0, ext.delNote());
//	}
//	TEST(ExtServiceUnitest, editNote) {
//		int code = ext.editNote();
//		bool isOk = (code == 100022001 || code == 100022004);
//		EXPECT_TRUE(isOk);
//	}
//	TEST(ExtServiceUnitest, archiveNote) {
//		EXPECT_EQ(0, ext.archiveNote());
//	}
//	TEST(ExtServiceUnitest, topNote) {
//		EXPECT_EQ(0, ext.topNote());
//	}
//	TEST(ExtServiceUnitest, searchNote) {
//		EXPECT_EQ(0, ext.searchNote());
//	}
//	TEST(ExtServiceUnitest, isCustomer) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.isCustomer());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.isCustomer());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.isCustomer());
//		}
//	}
//	TEST(ExtServiceUnitest, getUserByAppIdAndCustomId) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.getUserByAppIdAndCustomId());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.getUserByAppIdAndCustomId());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.getUserByAppIdAndCustomId());
//		}
//	}
//	TEST(ExtServiceUnitest, getCustomerPoolByAppID) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.getCustomerPoolByAppID());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.getCustomerPoolByAppID());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.getCustomerPoolByAppID());
//		}
//	}
//	TEST(ExtServiceUnitest, closeConversation) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.closeConversation());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.closeConversation());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.closeConversation());
//		}
//	}
//	TEST(ExtServiceUnitest, accessCustom) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.accessCustom());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.accessCustom());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.accessCustom());
//		}
//	}
//	TEST(ExtServiceUnitest, getLastMessage) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.getLastMessage());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.getLastMessage());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.getLastMessage());
//		}
//	}
//	TEST(ExtServiceUnitest, getCustomPoolCount) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.getCustomPoolCount());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.getCustomPoolCount());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.getCustomPoolCount());
//		}
//	}
//	TEST(ExtServiceUnitest, updateCustomerService) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.updateCustomerService());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.updateCustomerService());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.updateCustomerService());
//		}
//	}
//	TEST(ExtServiceUnitest, getAppListByUserID) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.getAppListByUserID());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.getAppListByUserID());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.getAppListByUserID());
//		}
//	}
//	TEST(ExtServiceUnitest, getCustomMessages) {
//		EXPECT_EQ(0, ext.getCustomMessages());
//	}
//	TEST(ExtServiceUnitest, getAppCustomerInfo) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, ext.getAppCustomerInfo());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(11100, ext.getAppCustomerInfo());
//		}
//		else
//		{
//			EXPECT_EQ(11100, ext.getAppCustomerInfo());
//		}
//	}
//	TEST(ExtServiceUnitest, getCustomerLastMessageByDB) {
//		EXPECT_EQ(0, ext.getCustomerLastMessageByDB());
//	}
//	TEST(ExtServiceUnitest, setCustomMsgReaded) {
//		EXPECT_EQ(0, ext.setCustomMsgReaded());
//	}
//	TEST(ExtServiceUnitest, addNotebook) {
//		EXPECT_EQ(0, ext.addNotebook());
//	}
//	TEST(ExtServiceUnitest, getNotebook) {
//		EXPECT_EQ(0, ext.getNotebook());
//	}
//	TEST(ExtServiceUnitest, delNotebook) {
//		EXPECT_EQ(0, ext.delNotebook());
//	}
//	TEST(ExtServiceUnitest, editNotebook) {
//		EXPECT_EQ(0, ext.editNotebook());
//	}
//	TEST(ExtServiceUnitest, encryptNotebook) {
//		EXPECT_EQ(0, ext.encryptNotebook());
//	}
//	TEST(ExtServiceUnitest, decryptNotebook) {
//		EXPECT_EQ(0, ext.decryptNotebook());
//	}
//	TEST(ExtServiceUnitest, checkNoteEnkey) {
//		EXPECT_EQ(0, ext.checkNoteEnkey());
//	}
//	TEST(ExtServiceUnitest, hideNotebook) {
//		EXPECT_EQ(0, ext.hideNotebook());
//	}
//	TEST(ExtServiceUnitest, checkHiddenKey) {
//		EXPECT_EQ(0, ext.checkHiddenKey());
//	}
//	TEST(ExtServiceUnitest, addNoteEntry) {
//		EXPECT_EQ(0, ext.addNoteEntry());
//	}
//	TEST(ExtServiceUnitest, getNoteEntry) {
//		EXPECT_EQ(0, ext.getNoteEntry());
//	}
//	TEST(ExtServiceUnitest, delNoteEntry) {
//		EXPECT_EQ(0, ext.delNoteEntry());
//	}
//	TEST(ExtServiceUnitest, editNoteEntry) {
//		EXPECT_EQ(0, ext.editNoteEntry());
//	}
//	TEST(ExtServiceUnitest, searchNoteEntry) {
//		EXPECT_EQ(0, ext.searchNoteEntry());
//	}
//	TEST(ExtServiceUnitest, setSecSessionOnOff) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(100, ext.setSecSessionOnOff());
//		}
//		else {
//			int code = ext.setSecSessionOnOff();
//			bool isOk = (code == 100010053 || code == 100 || code == -16777134);
//			EXPECT_TRUE(isOk);
//		}
//		
//	}
//	TEST(ExtServiceUnitest, getSecSessionOnOff) {
//		int res = ext.getSecSessionOnOff();
//		bool isOk = (res == -16777134 || res == 11100);
//		EXPECT_TRUE(isOk);
//	}
//	TEST(ExtServiceUnitest, checkSecSession) {
//		EXPECT_EQ(0, ext.checkSecSession());
//	}
//	TEST(ExtServiceUnitest, orgAndUserSearchEx) {
//		if (m_config->m_server == "vrv") {
//			int code = ext.orgAndUserSearchEx();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(0, ext.orgAndUserSearchEx());
//		}
//		else
//		{
//			int code = ext.orgAndUserSearchEx();
//			bool isOk = (code == -16777214 || code == 16004);
//			EXPECT_TRUE(isOk);
//		}
//	}
//	TEST(ExtServiceUnitest, getUserShieldByAccount) {
//		EXPECT_EQ(0, ext.getUserShieldByAccount());
//	}
//	TEST(ExtServiceUnitest, delNotebookById) {
//		EXPECT_EQ(0, ext.delNotebookById());
//	}
//	TEST(ExtServiceUnitest, getAllRoom) {
//		EXPECT_EQ(0, ext.getAllRoom());
//	}
//	TEST(DISABLED_Interface, meessageSecurityCheck) {
//		EXPECT_EQ(0, ext.meessageSecurityCheck());
//	}
//
//	TEST(DISABLED_Interface, fileSecurityCheck) {
//		EXPECT_EQ(0, ext.fileSecurityCheck());
//	}
//
//	TEST(DISABLED_Interface, setFileOrMsgRule) {
//		EXPECT_EQ(0, ext.setFileOrMsgRule());
//	}
//#endif
//	/*******************************************************
//
//		SearchServiceUnitest  start
//
//	********************************************************/
//	SearchServiceUnitest searchserviceunitest;
//	TEST(SearchServiceUnitest, searchFromNet) {
//		EXPECT_EQ(0, searchserviceunitest.searchFromNet());
//	}
//	TEST(SearchServiceUnitest, searchFromLocal) {
//		EXPECT_EQ(0, searchserviceunitest.searchFromLocal());
//	}
//	TEST(SearchServiceUnitest, searchFromLocalWithType) {
//		EXPECT_EQ(0, searchserviceunitest.searchFromLocalWithType());
//	}
//	TEST(SearchServiceUnitest, searchFromLocalWithMTypes) {
//		EXPECT_EQ(0, searchserviceunitest.searchFromLocalWithMTypes());
//	}
//	TEST(SearchServiceUnitest, groupSearchMember) {
//		EXPECT_EQ(0, searchserviceunitest.groupSearchMember());
//	}
//	TEST(SearchServiceUnitest, getUserInfo) {
//		EXPECT_EQ(0, searchserviceunitest.getUserInfo());
//	}
//	TEST(SearchServiceUnitest, getUserInfoEx) {
//		EXPECT_EQ(0, searchserviceunitest.getUserInfoEx());
//	}
//	TEST(SearchServiceUnitest, getUserInfoWithoutDlHeadImg) {
//		EXPECT_EQ(0, searchserviceunitest.getUserInfoWithoutDlHeadImg());
//	}
//	TEST(DISABLED_Interface, getUserInfoSync) {
//		EXPECT_EQ(0, searchserviceunitest.getUserInfoSync());
//	}
//	TEST(SearchServiceUnitest, getUserInfoByScene) {
//		EXPECT_EQ(0, searchserviceunitest.getUserInfoByScene());
//	}
//	TEST(SearchServiceUnitest, getGroupInfo) {
//		EXPECT_EQ(0, searchserviceunitest.getGroupInfo());
//	}
//	TEST(SearchServiceUnitest, searchMessage) {
//		EXPECT_EQ(0, searchserviceunitest.searchMessage());
//	}
//	TEST(SearchServiceUnitest, searchDetailMessage) {
//		EXPECT_EQ(0, searchserviceunitest.searchDetailMessage());
//	}
//	TEST(SearchServiceUnitest, getOutEntNodeInfo) {
//		EXPECT_EQ(0, searchserviceunitest.getOutEntNodeInfo());
//	}
//	/*************************************************
//
//		CloudServiceUnitest start
//
//	***************************************************/
//	CloudServiceUnitest cloud;
//	TEST(DISABLED_Interface, uploadFile) {
//		int code = cloud.uploadFile();
//		bool isOk = (code == 536 || code == 551);
//		EXPECT_TRUE(isOk);
//	}
//	TEST(DISABLED_Interface, queryFloder) {
//		if (m_config->m_server == "im") {
//			int code = cloud.queryFloder();
//			bool isOk = (code == 0 || code == 110);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, cloud.queryFloder());
//		}
//	}
//	TEST(DISABLED_Interface, addFile) {
//		int code = cloud.addFile();
//		bool isOk;
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(100022502,cloud.addFile());
//		}
//		else if (m_config->m_server == "bxy") {
//			isOk = (code == 110 || code == 9);
//			EXPECT_TRUE(isOk);
//		}
//		else
//		{
//			EXPECT_EQ(100022502, cloud.addFile());
//		}
//	}
//	TEST(DISABLED_Interface, delFile) {
//		if (m_config->m_server == "im") {
//			int code = cloud.delFile();
//			bool isOk = (code == 9 || code == 110 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(9, cloud.delFile());
//		}
//	}
//	TEST(DISABLED_Interface, renameFile) {
//		EXPECT_EQ(0, cloud.renameFile());
//	}
//	TEST(DISABLED_Interface, getFileById) {
//		if (m_config->m_server == "im") {
//			int code = cloud.getFileById();
//			bool isOk = (code == 9 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(9, cloud.getFileById());
//		}
//	}
//	TEST(DISABLED_Interface, getFilesByHash) {
//		if (m_config->m_server == "im") {
//			int code = cloud.getFilesByHash();
//			bool isOk = (code == 110 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, cloud.getFilesByHash());
//		}
//	}
//	TEST(DISABLED_Interface, getFilesByHashSync) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_TRUE(!cloud.getFilesByHashSync());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_TRUE(cloud.getFilesByHashSync());
//		}
//		else
//		{
//			EXPECT_TRUE(cloud.getFilesByHashSync());
//
//		}
//	}
//	TEST(DISABLED_Interface, searchFiles) {
//		EXPECT_EQ(0, cloud.searchFiles());
//	}
//	TEST(DISABLED_Interface, createTeam) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, cloud.createTeam());
//		}
//		else if (m_config->m_server == "bxy") {
//			int code = cloud.createTeam();
//			bool isOk = (code == 0 || code == 110);
//			EXPECT_TRUE(isOk);
//		}
//		else
//		{
//			EXPECT_EQ(0, cloud.createTeam());
//		}
//	}
//	TEST(DISABLED_Interface, teamAddMember) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, cloud.teamAddMember());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(110, cloud.teamAddMember());
//		}
//		else
//		{
//			EXPECT_EQ(110, cloud.teamAddMember());
//		}
//	}
//	TEST(DISABLED_Interface, teamRemoveMember) {
//		if (m_config->m_server == "im") {
//			int code = cloud.teamRemoveMember();
//			bool isOk = (code == 110 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, cloud.teamRemoveMember());
//		}
//	}
//	TEST(DISABLED_Interface, teamResetMember) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, cloud.teamResetMember());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(110, cloud.teamResetMember());
//		}
//		else
//		{
//			EXPECT_EQ(110, cloud.teamResetMember());
//		}
//	}
//	TEST(DISABLED_Interface, getTeams) {
//		if (m_config->m_server == "im") {
//			int code = cloud.getTeams();
//			bool isOk = (code == 110 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, cloud.getTeams());
//		}
//	}
//	TEST(DISABLED_Interface, teamMembers) {
//		if (m_config->m_server == "im") {
//			int code = cloud.teamMembers();
//			bool isOk = (code == 110 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, cloud.teamMembers());
//		}
//	}
//	TEST(DISABLED_Interface, getRoles) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, cloud.getRoles());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(110, cloud.getRoles());
//		}
//		else
//		{
//			EXPECT_EQ(110, cloud.getRoles());
//		}
//	}
//	TEST(DISABLED_Interface, getRoleById) {
//		if (m_config->m_server == "im") {
//			int code = cloud.getRoleById();
//			bool isOk = (code == 110 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, cloud.getRoleById());
//		}
//	}
//	TEST(DISABLED_Interface, addRole) {
//		int code = cloud.addRole();
//		bool isOk = (code == 8 || code == 0);
//		EXPECT_TRUE(isOk);
//	}
//	TEST(DISABLED_Interface, editRole) {
//		int code = cloud.editRole();
//		bool isOk;
//		if (m_config->m_server == "vrv") {
//			isOk = (code == 0 || code == 99);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(8, cloud.editRole());
//		}
//		else
//		{
//			EXPECT_EQ(8, cloud.editRole());
//		}
//	}
//	TEST(DISABLED_Interface, removerRole) {
//		EXPECT_EQ(0, cloud.removerRole());
//	}
//	TEST(DISABLED_Interface, getPermission) {
//		EXPECT_EQ(0, cloud.getPermission());
//	}
//	TEST(DISABLED_Interface, getCloudFileInfo) {
//		EXPECT_EQ(0, cloud.getCloudFileInfo());
//	}
//	TEST(DISABLED_Interface, createPubDir) {
//		int code = cloud.createPubDir();
//		bool isOk;
//		if (m_config->m_server == "vrv") {
//			isOk = (code == 0 || code == 100022503);
//			EXPECT_TRUE(isOk);
//		}
//		else if (m_config->m_server == "bxy") {
//			int code = cloud.createPubDir();
//			bool isOk = (code == 0 || code == 110);
//			EXPECT_TRUE(isOk);
//		}
//		else
//		{
//			int code = cloud.createPubDir();
//			bool isOk = (code == 0 || code == 110);
//			EXPECT_TRUE(isOk);
//
//		}
//	}
//	TEST(DISABLED_Interface, moveFile) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, cloud.moveFile());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(14, cloud.moveFile());
//		}
//		else
//		{
//			EXPECT_EQ(14, cloud.moveFile());
//		}
//	}
//	TEST(DISABLED_Interface, copyFile) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, cloud.copyFile());
//		}
//		else if (m_config->m_server == "bxy") {
//			EXPECT_EQ(13, cloud.copyFile());
//		}
//		else
//		{
//			EXPECT_EQ(13, cloud.copyFile());
//		}
//	}
//	TEST(DISABLED_Interface, querySubFolders) {
//		if (m_config->m_server == "im") {
//			int code = cloud.querySubFolders();
//			bool isOk = (code == 110 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else {
//			EXPECT_EQ(0, cloud.querySubFolders());
//		}
//	}
//	TEST(DISABLED_Interface, queryFolderByParam) {
//		if (m_config->m_server == "vrv") {
//			EXPECT_EQ(0, cloud.queryFolderByParam());
//		}
//		else if (m_config->m_server == "bxy") {
//			int code = cloud.queryFolderByParam();
//			bool isOk = (code == 110 || code == 0);
//			EXPECT_TRUE(isOk);
//		}
//		else
//		{
//			EXPECT_EQ(0, cloud.queryFolderByParam());
//		}
//	}
//	TEST(DISABLED_Interface, checkFileExit) {
//		EXPECT_EQ(0, cloud.checkFileExit());
//	}
//	TEST(DISABLED_Interface, uploadFile_new) {
//		EXPECT_EQ(0, cloud.uploadFile_new());
//	}
//	TEST(DISABLED_Interface, downloadFile) {
//		EXPECT_TRUE(cloud.downloadFile());
//	}
//	TEST(DISABLED_Interface, delFile_new) {
//		EXPECT_EQ(0, cloud.delFile_new());
//	}
//	TEST(DISABLED_Interface, renameFile_new) {
//		EXPECT_EQ(0, cloud.renameFile_new());
//	}
//	TEST(DISABLED_Interface, moveFile_new) {
//		EXPECT_EQ(0, cloud.moveFile_new());
//	}
//	TEST(DISABLED_Interface, copyFile_new) {
//		EXPECT_EQ(0, cloud.copyFile_new());
//	}
//	TEST(DISABLED_Interface, restoreCloudFile) {
//		EXPECT_EQ(0, cloud.restoreCloudFile());
//	}
//	TEST(DISABLED_Interface, clearCloudFile) {
//		EXPECT_EQ(0, cloud.clearCloudFile());
//	}
//	TEST(DISABLED_Interface, syncCloudFile) {
//		EXPECT_TRUE(cloud.syncCloudFile());
//	}
//	TEST(DISABLED_Interface, getCloudTrashInfo) {
//		EXPECT_EQ(0, cloud.getCloudTrashInfo());
//	}
//	TEST(DISABLED_Interface, getNewCloudFileInfo) {
//		EXPECT_TRUE(cloud.getNewCloudFileInfo());
//	}
//	TEST(DISABLED_Interface, getNextLevelInfo) {
//		EXPECT_TRUE(cloud.getNextLevelInfo());
//	}
//	TEST(DISABLED_Interface, getCloudUserInfo) {
//		EXPECT_EQ(0, cloud.getCloudUserInfo());
//	}
//	TEST(DISABLED_Interface, createShare) {
//		EXPECT_EQ(0, cloud.createShare());
//	}
//	TEST(DISABLED_Interface, cloudShareToOther) {
//		EXPECT_EQ(0, cloud.cloudShareToOther());
//	}
//	TEST(DISABLED_Interface, cloudShareToMe) {
//		EXPECT_EQ(0, cloud.cloudShareToMe());
//	}
//	TEST(DISABLED_Interface, cloudChangeSharefolder) {
//		EXPECT_EQ(0, cloud.cloudChangeSharefolder());
//	}
//	TEST(DISABLED_Interface, cloudChangeShareuser) {
//		EXPECT_EQ(0, cloud.cloudChangeShareuser());
//	}
//	TEST(DISABLED_Interface, getCloudShareInfo) {
//		EXPECT_EQ(0, cloud.getCloudShareInfo());
//	}
//	TEST(DISABLED_Interface, setUserSetting) {
//		EXPECT_EQ(0, cloud.setUserSetting());
//	}
//	TEST(DISABLED_Interface, getUserSetting) {
//		EXPECT_EQ(0, cloud.getUserSetting());
//	}
//	TEST(DISABLED_Interface, getCloudContactInfo) {
//		EXPECT_EQ(0, cloud.getCloudContactInfo());
//	}
//	TEST(DISABLED_Interface, delCloudTransferHistory) {
//		EXPECT_EQ(0, cloud.delCloudTransferHistory());
//	}
//	TEST(DISABLED_Interface, getCloudTransferHistory) {
//		EXPECT_EQ(0, cloud.getCloudTransferHistory());
//	}
//	TEST(DISABLED_Interface, clearCloudTransferHistory) {
//		EXPECT_EQ(0, cloud.clearCloudTransferHistory());
//	}
//	TEST(DISABLED_Interface, cancelTransfer) {
//		EXPECT_EQ(0, file.cancelTransfer());
//	}
//	TEST(DISABLED_Interface, cancelTargetTransfer) {
//		EXPECT_TRUE(file.cancelTargetTransfer());
//	}
//	TEST(DISABLED_Interface, cancelAllTransfer) {
//		EXPECT_EQ(0, file.cancelAllTransfer());
//	}
//	/*******************************************************
//
//		RtcServiceUnitest  start
//
//	********************************************************/
//	RtcServiceUnitest rtc;
//	TEST(DISABLED_Interface, createChannel) {
//		EXPECT_EQ(0, rtc.createChannel());
//	}
//	TEST(DISABLED_Interface, acceptOrReject) {
//		EXPECT_EQ(0, rtc.acceptOrReject());
//	}
//	TEST(DISABLED_Interface, leaveChannel) {
//		EXPECT_EQ(0, rtc.leaveChannel());
//	}
//	TEST(DISABLED_Interface, joinChannel) {
//		EXPECT_EQ(0, rtc.joinChannel());
//	}
//	TEST(DISABLED_Interface, setConferenceInfo) {
//		EXPECT_EQ(0, rtc.setConferenceInfo());
//	}
//	TEST(DISABLED_Interface, getConferenceInfo) {
//		EXPECT_EQ(0, rtc.getConferenceInfo());
//	}
//	TEST(DISABLED_Interface, switchChannel) {
//		EXPECT_EQ(0, rtc.switchChannel());
//	}
//	TEST(DISABLED_Interface, getStunServer) {
//		EXPECT_EQ(0, rtc.getStunServer());
//	}
//	TEST(DISABLED_Interface, getAgoraFunc) {
//		EXPECT_EQ(0, rtc.getAgoraFunc());
//	}
//	TEST(DISABLED_Interface, getStunServerSync) {
//		EXPECT_EQ(0, rtc.getStunServerSync());
//	}
//	TEST(DISABLED_Interface, getStunServerList) {
//		EXPECT_EQ(0, rtc.getStunServerList());
//	}
//	TEST(DISABLED_Interface, makePresenter) {
//		EXPECT_EQ(0, rtc.makePresenter());
//	}
//	TEST(DISABLED_Interface, extraEventCall) {
//		EXPECT_EQ(0, rtc.extraEventCall());
//	}
//	TEST(DISABLED_Interface, getCommonInfo) {
//		EXPECT_EQ(0, rtc.getCommonInfo());
//	}
//	TEST(DISABLED_Interface, regMultiEventCb) {
//		EXPECT_EQ(0, rtc.regMultiEventCb());
//	}
//	TEST(DISABLED_Interface, getMultiServerSync) {
//		EXPECT_EQ(0, rtc.getMultiServerSync());
//	}
//	TEST(DISABLED_Interface, multiTalkRequest) {
//		EXPECT_EQ(0, rtc.multiTalkRequest());
//	}
//	TEST(DISABLED_Interface, multiExtraRequest) {
//		EXPECT_EQ(0, rtc.multiExtraRequest());
//	}
//
//	/*******************************************************
//
//		GainterServiceUnitest  start
//
//	********************************************************/
//	GainterServiceUnitest gainter;
//	TEST(DISABLED_Interface, getAppNodeServers) {
//	EXPECT_EQ(0, gainter.getAppNodeServers());
//	}
//	TEST(DISABLED_Interface, addThreeCardOper) {
//	EXPECT_EQ(0, gainter.addThreeCardOper());
//	}
//	TEST(DISABLED_Interface, getAuthCode) {
//	EXPECT_EQ(0, gainter.getAuthCode());
//	}
	
}

