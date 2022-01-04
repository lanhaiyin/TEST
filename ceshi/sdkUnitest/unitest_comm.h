#pragma once
#include "Environment.h"
namespace serviceTest {
	class CommUnitest{
	public:
		CommUnitest();
		int clear();
		//发送文本消息
		int sendText();
		//测试文本长度为0-200
		int sendTextlength1();
		//测试文本长度为200-500
		int sendTextlength2();
		//测试文本长度为500-2000
		int sendTextlength3();
		//测试文本长度为2000-6000
		int sendTextlength4();
		int sendImgJpg();
		int sendImgPng();
		int sendImgGif();

		int sendImgsize1();
		int sendImgsize2();
		int sendImgsize3();
		int sendFile();
		int sendFolder();
		int sendHanziFile();
	

		//任务消息
		int sendTask();
		int sendTasklength1();
		int sendTasklength2();
		int sendTasklength3();

		//延时消息
		int sendTextdelay();
		int sendTextdelaylen1();
		int sendTextdelaylen2();
		int sendTextdelaylen3();
		int sendTextdou();

		//单词阅读
		int sendTextburn();
		int sendTextErase();
		//密聊
		int sendTextencry();
		int sendFileEncry();
		int sendCardEncry();
		int sendTextcard();
		int sendTextFeather();
		int sendTextDynExpression();
		int sendPosition();
		//禁转消息
		int sendTextJin();
		int sendFileJin();
		int sendCardJin();
		int sendPositionJin();
	private:
		std::shared_ptr<IChatService> m_chatService = nullptr;
		std::shared_ptr<IFileService> m_fileService = nullptr;
	};
}
