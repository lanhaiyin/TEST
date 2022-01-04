#include "Environment.h"
namespace serviceTest {
	class FileServiceUnitest /*:public testing::Test*/ {
	public:
		FileServiceUnitest();
		int regProcessCb();					//******************注册进度推送**************
		int regP2pUserStatusChgCb();		//******************注册p2p用户状态改变推送**************
		int regP2pSendFileReqCb();			//******************注册p2p用户发送文件请求推送**************
		int regP2pFileTransOpCb();			//******************注册p2p用户文件传输操作推送**************
		bool uploadAvatar();					//******************上传头像**************
		bool uploadBackground();				//******************上传背景图**************
		bool uploadFile();					//******************上传文件**************
		int uploadShareFile();				//******************外部上传文件(iOS专用)**************
		int updateFileLocalPath();		//******************更新已下载的文件的保存路径到数据库**************   dump  fileinfo=nullptr;
		int downloadFile();					//******************下载文件**************
		int downloadExternalFile();			//******************下载外部文件**************
		bool uploadImage();					//******************上传照片**************
		bool uploadShareImage();				//******************上传分享图片**************
		int downloadImage();				//******************下载图片**************
		int downloadNineBoxImage();			//******************下载九宫格图片**************
		int downloadImage2();				//******************下载图片2 会存fileInfo库的那种**************
		int downloadNineBoxImage2();		//******************下载九宫格图片2 会存fileInfo库的那种**************
		bool encryptFile();					//******************加密文件**************
		bool decryptFile();					//******************解密文件**************
		bool compress();						//******************压缩文件**************
		bool uncompress();					//******************解压文件**************
		int getFileList1();					//******************获取文件列表1**************
		int getFileList2();					//******************获取文件列表2**************
		int getFilesInfo();					//******************通过文件消息ID得到文件详细信息 同步接口**************
		bool isTransmitting();				//******************判断是否有文件在传输 同步接口**************
		bool isTransmittingInTarget();		//******************判断个人或群中是否有文件传输 同步接口**************
		int cancelTransfer();				//******************取消文件上传或下载**************
		bool cancelTargetTransfer();			//******************取消个人或群中的所有文件传输 同步接口**************
		int cancelAllTransfer();			//******************取消所有文件传输**************
		int getP2pUsers	();				//******************获取局域网可以P2P通讯的用户 同步接口**************         errorcode = -858993460
		int p2pTransferCancle	();			//******************取消正在进行的传输或拒绝尚未开始的p2p传输 同步接口**************  errorcode = C00005
		bool getAlreadyDownload();			//******************获取本地文件已经下载大小 同步接口**************
		int checkUrlValid();				//******************检查URL是否有效**************
		bool getNameByUrl();					//******************通过文件的的服务器路径获取一个本地的唯一文件名**************
		int delayFiles();					//******************检查延期文件的有效时长是否有效**************
		int queryFileValid();				//******************查询文件是否过期**************
		int reduceImage();					//******************将原图压缩尺寸为大图和小图**************
		int putShowMarkOnImage();			//******************给图片添加明水印**************
		int putMarkOnImageSimple();			//******************给图片添加id水印**************
		int getMarkFromImageSimple();		//******************获取水印图的id水印**************
		int putMarkOnImageFFT();			//******************给图片添加频谱水印**************
		int getMarkFromImageFFT();			//******************获取水印图的频谱水印**************
		int migrateUserData();				//******************数据迁移接口 只提供压缩和解压功能，传输需要客户端自行完成，压缩后的数据是加密的**************旧接口
		int migrateUserDataNew();			//******************数据迁移接口,设置选择实现部分服务器的迁移 只提供压缩和解压功能，传输需要客户端自行完成，压缩后的数据是加密的**************
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<IFileService> m_fileService = nullptr;
	};
}
