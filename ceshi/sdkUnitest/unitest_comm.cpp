#include "unitest_comm.h"
CommUnitest::CommUnitest(){
	//µÇÂ¼ÕËºÅA
	int retA = g_test[0].loginByIndex(0);
	if (retA) {
		printf("A account Login failed,ret=%d", retA);
	}
	printf("A account Login ,ret=%d", retA);
	int retB = g_test[1].loginByIndex(1);
	if (retB) {
		printf("B account Login failed,ret=%d", retB);
	}
	m_chatService = g_test[0].CHATSERVICE();
	m_fileService = g_test[0].FILESERVICE();
}
int CommUnitest::sendText(){
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = Tools::GBToUTF8(m_config->m_txt100.data());
	msgText.body = text;
	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}

//ÎÄ±¾³¤¶ÈÎª0~200
int CommUnitest::sendTextlength1()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt100+std::to_string(1);
	msgText.body = text;
	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//ÎÄ±¾³¤¶ÈÎª200~500
int CommUnitest::sendTextlength2()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt500 + std::to_string(1);
	msgText.body = text;
	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//²âÊÔÎÄ±¾³¤¶ÈÎª500-2000
int CommUnitest::sendTextlength3()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt2000 + std::to_string(1);
	msgText.body = text;
	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//²âÊÔÎÄ±¾³¤¶ÈÎª2000-6000
int CommUnitest::sendTextlength4()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt6000;
	msgText.body = text;
	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍJPGÍ¼Æ¬
int CommUnitest::sendImgJpg()
{
	
	model::MsgImg msgImg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgImg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgImg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	//std::string text = std::string("dicnduc[**&^%#@\]8938920");
	//msgImg.body = text;
	msgImg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgImg.thumbPath = Tools::GBToUTF8(m_config->m_imgJpgPath.data());
	msgImg.mainPath= Tools::GBToUTF8(m_config->m_imgJpgPath.data());
	//msgImg.fileName = Tools::GBToUTF8(Tools::getFileNameByPath(m_config->m_imgJpgPath, false));
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgImg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍPngÍ¼Æ¬
int CommUnitest::sendImgPng()
{

	model::MsgImg msgImg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgImg.targetId =m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgImg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ														 
	msgImg.msgType = 5;										         
	msgImg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgImg.thumbPath = Tools::GBToUTF8(m_config->m_imgPngPath.data());
	msgImg.mainPath = Tools::GBToUTF8( m_config->m_imgPngPath.data());
	//msgImg.fileName=Tools::GBToUTF8(Tools::getName)
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgImg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍGifÍ¼Æ¬
int CommUnitest::sendImgGif()
{

	model::MsgImg msgImg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgImg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgImg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
															   //std::string text = std::string("dicnduc[**&^%#@\]8938920");
															   //msgImg.body = text;
	msgImg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgImg.thumbPath = m_config->m_imgGifPath;
	msgImg.mainPath = m_config->m_imgGifPath;
	msgImg.mainUrl = m_config->m_imgGifPath;
	msgImg.thumbUrl = m_config->m_imgGifPath;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgImg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍ(0,100k]
int CommUnitest::sendImgsize1()
{

	model::MsgImg msgImg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgImg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgImg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
															   //std::string text = std::string("dicnduc[**&^%#@\]8938920");
															   //msgImg.body = text;
	msgImg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgImg.thumbPath = Tools::GBToUTF8(m_config->m_imgPngPath.data());
	msgImg.mainPath = Tools::GBToUTF8(m_config->m_imgPngPath.data());
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgImg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍ[100,500k)Í¼Æ¬
int CommUnitest::sendImgsize2()
{

	model::MsgImg msgImg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgImg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgImg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
															   //std::string text = std::string("dicnduc[**&^%#@\]8938920");
															   //msgImg.body = text;
	msgImg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgImg.thumbPath = m_config->m_imgPngPath;
	msgImg.mainPath = m_config->m_imgPngPath;
	msgImg.mainUrl = m_config->m_imgPngPath;
	msgImg.thumbUrl = m_config->m_imgPngPath;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgImg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍ[500k,1M)Í¼Æ¬
int CommUnitest::sendImgsize3()
{

	

	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	MsgImg msg;

	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.mainPath = m_config->m_imgJpgPath;
	msg.thumbPath= "D:\\ceshi\\Bin\\Release\\bxy_21256846270/image/16408722920898467.jpg";
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msg.msgProperties = "";
	msg.msgId = 23134396;
	msg.msgType = 5;
	msg.fileName = Tools::GBToUTF8(Tools::getFileNameByPath(m_config->m_imgJpgPath, true).data());
	msg.size = Tools::getFileSize(m_config->m_imgJpgPath.data());
	msg.encryptKey = "1234567898765432";
	msg.time = 1596624561208;
	msg.isPrivateMsg = 0;
	msg.localId = time(NULL);
	msg.activeType = 0;
	msg.deviceType = 1;
	msg.timeZone = 32;
	msg.noStore = 0;
	msg.deal = false;
	m_chatService->sendAppendixMessage(msg, [&](int code, int64 time, int64 msgid, BadWord badword) {
		reqProm.set_value(code);
	}, [&](int32, int32, const std::string&) {; });
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍÎÄ¼þk¼¶±ð
int CommUnitest::sendFile()
{

	
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	MsgFile msg;
	
	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.filePath = m_config->m_upLoadFilePath;
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msg.msgProperties = "";
	msg.msgId = 23134396;
	msg.msgType = 6;
	msg.fileName = Tools::GBToUTF8(Tools::getFileNameByPath(m_config->m_encryFilePath, true).data());
	msg.size = Tools::getFileSize(m_config->m_encryFilePath.data());
	msg.encryptKey = "1234567898765432";
	msg.time = 1596624561208;
	msg.isPrivateMsg = 0;
	msg.localId = time(NULL);
	msg.activeType = 0;
	msg.deviceType = 1;
	msg.timeZone = 32;
	msg.noStore = 0;
	msg.deal = false;
	
	m_chatService->sendAppendixMessage(msg, [&](int code, int64 time, int64 msgid, BadWord badword) {
		reqProm.set_value(code);
	}, [&](int32, int32, const std::string&) {; });
	
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍÎÄ¼þ¼ÐM¼¶±ðÎÄ¼þ
int CommUnitest::sendFolder()
{

	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	MsgFile msg;

	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.filePath =m_config->m_folderPath.data();
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msg.msgProperties = "";
	msg.msgId = 23134396;
	msg.msgType = 6;
	msg.fileName = Tools::getFileNameByPath(m_config->m_folderPath, true);
	msg.size = Tools::getFileSize(m_config->m_folderPath.data());
	msg.encryptKey = "1234567898765432";
	msg.time = 1596624561208;
	msg.isPrivateMsg = 0;
	msg.localId = time(NULL);
	msg.activeType = 0;
	msg.deviceType = 1;
	msg.timeZone = 32;
	msg.noStore = 0;
	msg.deal = false;

	m_chatService->sendAppendixMessage(msg, [&](int code, int64 time, int64 msgid, BadWord badword) {
		reqProm.set_value(code);
	}, [&](int32, int32, const std::string&) {; });

	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍÖÐÎÄÃûÎÄ¼þ
int CommUnitest:: sendHanziFile()
{

	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	MsgFile msg;

	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.filePath =m_config->m_hanziName;
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msg.msgProperties = "";
	msg.msgId = 23134396;
	msg.msgType = 6;
	msg.fileName = Tools::GBToUTF8(Tools::getFileNameByPath(m_config->m_hanziName, true).data());
	msg.size = Tools::getFileSize(m_config->m_hanziName.data());
	msg.encryptKey = "1234567898765432";
	msg.time = 1596624561208;
	msg.isPrivateMsg = 0;
	msg.localId = time(NULL);
	msg.activeType = 0;
	msg.deviceType = 1;
	msg.timeZone = 32;
	msg.noStore = 0;
	msg.deal = false;

	m_chatService->sendAppendixMessage(msg, [&](int code, int64 time, int64 msgid, BadWord badword) {
		reqProm.set_value(code);
	}, [&](int32, int32, const std::string&) {; });

	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}

//·¢ËÍÈÎÎñÏûÏ¢
int CommUnitest::sendTask() {
	model::MsgTask msgtask;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgtask.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgtask.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = std::string("dicnduc[**&^%#@\]8938920");
	msgtask.body = text;
	msgtask.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgtask.msgType = MSG_TYPE_TASK;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgtask, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendTasklength1() {
	model::MsgTask msgtask;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgtask.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgtask.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt100;
	msgtask.body = text;
	msgtask.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgtask.msgType = MSG_TYPE_TASK;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgtask, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendTasklength2() {
	model::MsgTask msgtask;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgtask.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgtask.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt500;
	msgtask.body = text;
	msgtask.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgtask.msgType = MSG_TYPE_TASK;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgtask, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendTasklength3() {
	model::MsgTask msgtask;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgtask.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgtask.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt2000;
	msgtask.body = text;
	msgtask.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgtask.msgType = MSG_TYPE_TASK;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgtask, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendTextdelay()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	//ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt100 + std::to_string(1);
	msgText.body = text;
	//msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgText.delayTime = 300;
	msgText.isDelay = 1;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		//reqProm.set_value(code);
	});
	//int code = reqFut.get();
	//ABInfo.semer->wait();
	return 0;
}
int CommUnitest::sendTextdelaylen1()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	//ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt500 + std::to_string(1);
	msgText.body = text;
	//msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgText.delayTime = 300;
	msgText.isDelay = 1;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		//reqProm.set_value(code);
	});
	//int code = reqFut.get();
	//ABInfo.semer->wait();
	return 0;
}
int CommUnitest::sendTextdelaylen2()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	//ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt2000 + std::to_string(1);
	msgText.body = text;
	//msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgText.delayTime = 300;
	msgText.isDelay = 1;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		//reqProm.set_value(code);
	});
	//int code = reqFut.get();
	//ABInfo.semer->wait();
	return 0;
}
int CommUnitest::sendTextdelaylen3()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	//ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = m_config->m_txt6000 + std::to_string(1);
	msgText.body = text;
	//msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgText.delayTime = 300;
	msgText.isDelay = 1;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		//reqProm.set_value(code);
	});
	//int code = reqFut.get();
	//ABInfo.semer->wait();
	return 0;
}
int CommUnitest::sendTextdou()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = "&:flash" + m_config->m_txt100;
	msgText.body = Tools::GBToUTF8(text.data());
	msgText.subType = 0;
	msgText.isReceipt = true;
	msgText.isDelay = false;
	//msgText.msgId = 1263231345;
	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);

	
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}

int CommUnitest::sendTextburn()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = std::string("danciyuedu");
	msgText.body = text;

	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);

	msgText.time = 1596624561208;
	msgText.isPrivateMsg = 0;
	msgText.localId = time(NULL);
	msgText.activeType = 1;
	msgText.deviceType = 1;
	msgText.timeZone = 32;
	msgText.noStore = 0;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendTextErase()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msgText.body = "&:delete|today";
	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgText.scope = "today";
	msgText.time = Tools::get_mill_sec();
	msgText.isPrivateMsg = 0;
	msgText.localId = time(NULL);
	msgText.subType = 2;
	msgText.deviceType = 1;
	msgText.timeZone = 32;
	msgText.noStore = 0;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	
	int code = reqFut.get();
	//ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendTextFeather()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msgText.body = "hello";
	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgText.isFeather = 1;
	msgText.time = Tools::get_mill_sec();
	msgText.isPrivateMsg = 0;
	msgText.localId = time(NULL);
	msgText.subType = 0;
	msgText.deviceType = 1;
	msgText.timeZone = 32;
	msgText.noStore = 0;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});

	int code = reqFut.get();
	//ABInfo.semer->wait();
	return code;
}

int CommUnitest::sendTextDynExpression()
{
	model::MsgDynExpression msg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ	
	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.time = Tools::get_mill_sec();
	msg.body = "Dynamic_Expression_10.gif";
	msg.msgType = MSG_TYPE_DYNEXPRESSION;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});

	int code = reqFut.get();
	//ABInfo.semer->wait();
	return code;
}

int CommUnitest::sendTextencry()
{
	model::MsgText msgText;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msgText.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msgText.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	std::string text = std::string("dicnduc[**&^%#@\]8938920");
	msgText.body = text;
	msgText.msgType = 2;
	msgText.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msgText.isPrivateMsg = 1;
	
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->setPrivateKey(msgText.targetId, "123456", [&](int code) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	reqFut.get();
	std::promise<int> reqProm2;
	std::future<int> reqFut2 = reqProm2.get_future();
	m_chatService->sendMessage(msgText, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm2.set_value(code);
	});
	int code = reqFut2.get();
	ABInfo.semer->wait();
	return code;
}
//¼ÓÃÜ·¢ËÍÎÄ¼þ

int CommUnitest::sendFileEncry()
{


	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	MsgFile msg;

	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.filePath = m_config->m_upLoadFilePath;
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msg.msgProperties = "";
	msg.msgId = 23134396;
	msg.msgType = 6;
	msg.fileName = Tools::GBToUTF8(Tools::getFileNameByPath(m_config->m_encryFilePath, true).data());
	msg.size = Tools::getFileSize(m_config->m_encryFilePath.data());
	msg.encryptKey = "1234567898765432";
	msg.time = 1596624561208;
	msg.localId = time(NULL);
	msg.activeType = 0;
	msg.deviceType = 1;
	msg.timeZone = 32;
	msg.noStore = 0;
	msg.isPrivateMsg = 1;
	msg.deal = false;
	std::promise<int> reqProm1;
	std::future<int> reqFut1 = reqProm1.get_future();
	m_chatService->setPrivateKey(msg.targetId, "123456", [&](int code) {
		std::cout << "send code" << std::endl;
		reqProm1.set_value(code);
	});
	reqFut1.get();
	m_chatService->sendAppendixMessage(msg, [&](int code, int64 time, int64 msgid, BadWord badword) {
		reqProm.set_value(code);
	}, [&](int32, int32, const std::string&) {; });

	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
//¼ÓÃÜ·¢ËÍÃûÆ¬
int CommUnitest::sendCardEncry()
{
	model::MsgCard msg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
															//std::string text = std::string("dicnduc[**&^%#@\]8938920");
															//msg.body = text;
	msg.msgType = 7;
	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.isPrivateMsg = 0;
	msg.mediaUrl = m_config->m_cardId;
	msg.isPrivateMsg = 1;
	std::promise<int> reqProm1;
	std::future<int> reqFut1 = reqProm1.get_future();
	m_chatService->setPrivateKey(msg.targetId, "123456", [&](int code) {
		std::cout << "send code" << std::endl;
		reqProm1.set_value(code);
	});
	reqFut1.get();
	std::promise<int> reqProm2;
	std::future<int> reqFut2 = reqProm2.get_future();
	m_chatService->sendMessage(msg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm2.set_value(code);
	});
	int code = reqFut2.get();
	ABInfo.semer->wait();
	return code;
}
//·¢ËÍÃûÆ¬ÏûÏ¢
int CommUnitest::sendTextcard()
{
	model::MsgCard msg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	//std::string text = std::string("dicnduc[**&^%#@\]8938920");
	//msg.body = text;
	msg.msgType = 7;
	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.isPrivateMsg = 0;
	msg.mediaUrl= m_config->m_cardId;
	std::promise<int> reqProm2;
	std::future<int> reqFut2 = reqProm2.get_future();
	m_chatService->sendMessage(msg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm2.set_value(code);
	});
	int code = reqFut2.get();
	ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendPosition()
{

	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	MsgPosition msg;

	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msg.msgProperties = "";
	msg.msgType = 4;
	msg.time = 1596624561208;
	msg.name = Tools::GBToUTF8(m_config->m_positionName.data());
	msg.latitude = m_config->m_latitude;
	msg.longitude = m_config->m_longitude;
	m_chatService->sendMessage(msg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}

int CommUnitest::sendTextJin()
{
	model::MsgText msg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ														//std::string text = std::string("dicnduc[**&^%#@\]8938920")														//msg.body = text;
	msg.msgType = 2;
	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.isPrivateMsg = 0;
	msg.body = "jinzhuan";
	msg.activeType = 2;
	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	m_chatService->sendMessage(msg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendFileJin()
{


	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	MsgFile msg;

	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.filePath = m_config->m_upLoadFilePath;
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msg.msgProperties = "";
	msg.msgId = 23134396;
	msg.msgType = 6;
	msg.fileName = Tools::GBToUTF8(Tools::getFileNameByPath(m_config->m_encryFilePath, true).data());
	msg.size = Tools::getFileSize(m_config->m_encryFilePath.data());
	msg.encryptKey = "1234567898765432";
	msg.time = 1596624561208;
	msg.isPrivateMsg = 0;
	msg.localId = time(NULL);
	msg.activeType = 2;
	msg.deviceType = 1;
	msg.timeZone = 32;
	msg.noStore = 0;
	msg.deal = false;

	m_chatService->sendAppendixMessage(msg, [&](int code, int64 time, int64 msgid, BadWord badword) {
		reqProm.set_value(code);
	}, [&](int32, int32, const std::string&) {; });

	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendCardJin()
{
	model::MsgCard msg;
	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
															//std::string text = std::string("dicnduc[**&^%#@\]8938920");
	msg.activeType = 2;														//msg.body = text;
	msg.msgType = 7;
	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.isPrivateMsg = 0;
	msg.mediaUrl = m_config->m_cardId;
	std::promise<int> reqProm2;
	std::future<int> reqFut2 = reqProm2.get_future();
	m_chatService->sendMessage(msg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm2.set_value(code);
	});
	int code = reqFut2.get();
	ABInfo.semer->wait();
	return code;
}
int CommUnitest::sendPositionJin()
{

	CommABInfo ABInfo;

	ABInfo = sdkUniTest::makeSemperUuid();

	std::promise<int> reqProm;
	std::future<int> reqFut = reqProm.get_future();
	MsgPosition msg;

	msg.preDefined = Tools::getGUIDJson(ABInfo.uuid);
	msg.targetId = m_config->getAccountInfo(1).m_iMyUserId; //BÕËºÅ
	msg.fromId = m_config->getAccountInfo(0).m_iMyUserId;   //AÕËºÅ
	msg.msgProperties = "";
	msg.msgType = 4;
	msg.time = 1596624561208;
	msg.name = Tools::GBToUTF8(m_config->m_positionName.data());
	msg.activeType = 2;
	msg.latitude = m_config->m_latitude;
	msg.longitude =m_config->m_longitude;
	m_chatService->sendMessage(msg, [&](int code, int64 time, int64 msgid, BadWord& badword) {
		std::cout << "send code" << std::endl;
		reqProm.set_value(code);
	});
	int code = reqFut.get();
	ABInfo.semer->wait();
	return code;
}

int CommUnitest::clear() {
	int retA = g_test[0].loginOutByIndex(0);
	if (retA) {
		printf("A account Logout failed,ret=%d", retA);
	}
	int retB = g_test[1].loginOutByIndex(1);
	if (retB) {
		printf("B account Logout failed,ret=%d", retB);
	}
	g_test[0].clearCllBack();
	g_test[1].clearCllBack();
	return 0;
}