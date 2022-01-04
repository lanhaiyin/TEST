#include "Environment.h"
namespace serviceTest {
	class RtcServiceUnitest /*:public testing::Test*/ {
	public:
		RtcServiceUnitest();
		int createChannel();				//******************�����Ա��������Ƶ����**************      //createoffer  ���� ����  sdp��
		int acceptOrReject();				//******************���ܻ�ܾ�����Ƶ��������**************
		int leaveChannel();					//******************�ر�����Ƶ����**************   
		int joinChannel();					//******************�ر�����Ƶ����**************  
		int setConferenceInfo();			//******************���û�����Ϣ**************
		int getConferenceInfo();			//******************��ȡ������Ϣ**************  
		int switchChannel();				//******************����Ƶ�л�**************	
		int getStunServer();				//******************��ȡ�򶴷����ַ**************    
		int getAgoraFunc();					//******************AGORA������ط���ӿ�**************  
		int getStunServerSync();			//******************��ȡ�򶴷����ַ ͬ���ӿ�**************  
		int getStunServerList();			//******************��ȡ�򶴷����ַ�б� ��ͬ���ӿڣ�**************
		int makePresenter();				//******************�������˻���**************
		int extraEventCall();				//******************ͨ���¼�call**************
		int getCommonInfo();				//******************��ȡͨ����Ϣ**************  
		int regMultiEventCb();				//******************ע�����¼��ص�**************
		int getMultiServerSync();			//******************��ȡ��������Ϣ    ͬ���ӿ�************** 
		int multiTalkRequest();				//******************�������**************  
		int multiExtraRequest();			//******************��չ����************** 	
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IRtcService> m_rtcService = nullptr;
	};
}

