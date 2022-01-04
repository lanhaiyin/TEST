#include "Environment.h"
namespace serviceTest {
	class FileServiceUnitest /*:public testing::Test*/ {
	public:
		FileServiceUnitest();
		int regProcessCb();					//******************ע���������**************
		int regP2pUserStatusChgCb();		//******************ע��p2p�û�״̬�ı�����**************
		int regP2pSendFileReqCb();			//******************ע��p2p�û������ļ���������**************
		int regP2pFileTransOpCb();			//******************ע��p2p�û��ļ������������**************
		bool uploadAvatar();					//******************�ϴ�ͷ��**************
		bool uploadBackground();				//******************�ϴ�����ͼ**************
		bool uploadFile();					//******************�ϴ��ļ�**************
		int uploadShareFile();				//******************�ⲿ�ϴ��ļ�(iOSר��)**************
		int updateFileLocalPath();		//******************���������ص��ļ��ı���·�������ݿ�**************   dump  fileinfo=nullptr;
		int downloadFile();					//******************�����ļ�**************
		int downloadExternalFile();			//******************�����ⲿ�ļ�**************
		bool uploadImage();					//******************�ϴ���Ƭ**************
		bool uploadShareImage();				//******************�ϴ�����ͼƬ**************
		int downloadImage();				//******************����ͼƬ**************
		int downloadNineBoxImage();			//******************���ؾŹ���ͼƬ**************
		int downloadImage2();				//******************����ͼƬ2 ���fileInfo�������**************
		int downloadNineBoxImage2();		//******************���ؾŹ���ͼƬ2 ���fileInfo�������**************
		bool encryptFile();					//******************�����ļ�**************
		bool decryptFile();					//******************�����ļ�**************
		bool compress();						//******************ѹ���ļ�**************
		bool uncompress();					//******************��ѹ�ļ�**************
		int getFileList1();					//******************��ȡ�ļ��б�1**************
		int getFileList2();					//******************��ȡ�ļ��б�2**************
		int getFilesInfo();					//******************ͨ���ļ���ϢID�õ��ļ���ϸ��Ϣ ͬ���ӿ�**************
		bool isTransmitting();				//******************�ж��Ƿ����ļ��ڴ��� ͬ���ӿ�**************
		bool isTransmittingInTarget();		//******************�жϸ��˻�Ⱥ���Ƿ����ļ����� ͬ���ӿ�**************
		int cancelTransfer();				//******************ȡ���ļ��ϴ�������**************
		bool cancelTargetTransfer();			//******************ȡ�����˻�Ⱥ�е������ļ����� ͬ���ӿ�**************
		int cancelAllTransfer();			//******************ȡ�������ļ�����**************
		int getP2pUsers	();				//******************��ȡ����������P2PͨѶ���û� ͬ���ӿ�**************         errorcode = -858993460
		int p2pTransferCancle	();			//******************ȡ�����ڽ��еĴ����ܾ���δ��ʼ��p2p���� ͬ���ӿ�**************  errorcode = C00005
		bool getAlreadyDownload();			//******************��ȡ�����ļ��Ѿ����ش�С ͬ���ӿ�**************
		int checkUrlValid();				//******************���URL�Ƿ���Ч**************
		bool getNameByUrl();					//******************ͨ���ļ��ĵķ�����·����ȡһ�����ص�Ψһ�ļ���**************
		int delayFiles();					//******************��������ļ�����Чʱ���Ƿ���Ч**************
		int queryFileValid();				//******************��ѯ�ļ��Ƿ����**************
		int reduceImage();					//******************��ԭͼѹ���ߴ�Ϊ��ͼ��Сͼ**************
		int putShowMarkOnImage();			//******************��ͼƬ�����ˮӡ**************
		int putMarkOnImageSimple();			//******************��ͼƬ���idˮӡ**************
		int getMarkFromImageSimple();		//******************��ȡˮӡͼ��idˮӡ**************
		int putMarkOnImageFFT();			//******************��ͼƬ���Ƶ��ˮӡ**************
		int getMarkFromImageFFT();			//******************��ȡˮӡͼ��Ƶ��ˮӡ**************
		int migrateUserData();				//******************����Ǩ�ƽӿ� ֻ�ṩѹ���ͽ�ѹ���ܣ�������Ҫ�ͻ���������ɣ�ѹ����������Ǽ��ܵ�**************�ɽӿ�
		int migrateUserDataNew();			//******************����Ǩ�ƽӿ�,����ѡ��ʵ�ֲ��ַ�������Ǩ�� ֻ�ṩѹ���ͽ�ѹ���ܣ�������Ҫ�ͻ���������ɣ�ѹ����������Ǽ��ܵ�**************
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IFileService> m_fileService = nullptr;
	};
}
