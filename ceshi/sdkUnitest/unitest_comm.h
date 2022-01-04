#pragma once
#include "Environment.h"
namespace serviceTest {
	class CommUnitest{
	public:
		CommUnitest();
		int clear();
		//�����ı���Ϣ
		int sendText();
		//�����ı�����Ϊ0-200
		int sendTextlength1();
		//�����ı�����Ϊ200-500
		int sendTextlength2();
		//�����ı�����Ϊ500-2000
		int sendTextlength3();
		//�����ı�����Ϊ2000-6000
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
	

		//������Ϣ
		int sendTask();
		int sendTasklength1();
		int sendTasklength2();
		int sendTasklength3();

		//��ʱ��Ϣ
		int sendTextdelay();
		int sendTextdelaylen1();
		int sendTextdelaylen2();
		int sendTextdelaylen3();
		int sendTextdou();

		//�����Ķ�
		int sendTextburn();
		int sendTextErase();
		//����
		int sendTextencry();
		int sendFileEncry();
		int sendCardEncry();
		int sendTextcard();
		int sendTextFeather();
		int sendTextDynExpression();
		int sendPosition();
		//��ת��Ϣ
		int sendTextJin();
		int sendFileJin();
		int sendCardJin();
		int sendPositionJin();
	private:
		std::shared_ptr<IChatService> m_chatService = nullptr;
		std::shared_ptr<IFileService> m_fileService = nullptr;
	};
}
