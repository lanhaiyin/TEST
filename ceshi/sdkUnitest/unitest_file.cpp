#include "unitest_file.h"
namespace serviceTest {
	FileServiceUnitest::FileServiceUnitest() {
		m_fileService = g_test[0].FILESERVICE();
	}

	int FileServiceUnitest::regProcessCb() {
		//******************注册进度推送**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_fileService->regProcessCb([&](int64 a, int32 b, int32 c, std::string d)
		{

		});

		return 0;
	}

	int FileServiceUnitest::regP2pUserStatusChgCb() {
		//******************注册p2p用户状态改变推送**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_fileService->regP2pUserStatusChgCb([&](int64 a, int8 b, int8 c)
		{

		});

		return 0;
	}

	int FileServiceUnitest::regP2pSendFileReqCb() {
		//******************注册p2p用户发送文件请求推送**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_fileService->regP2pSendFileReqCb([&](P2pSendFileReq json)
		{

		});

		return 0;
	}

	int FileServiceUnitest::regP2pFileTransOpCb() {
		//******************注册p2p用户文件传输操作推送**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_fileService->regP2pFileTransOpCb([&](int8 a, int64 b)
		{

		});


		return 0;
	}

	bool FileServiceUnitest::uploadAvatar() {
		//******************上传头像**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_fileService->uploadAvatar(m_config->m_headImg, [&](service::ErrorInfo code, std::string bigjson, std::string smalljson)
		{
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		bool isTrue = (code == 0 || code == 536);
		return isTrue;
	}

	bool FileServiceUnitest::uploadBackground() {
		//******************上传背景图**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_fileService->uploadBackground(m_config->m_backGroundImg, [&](int code, const std::string& bigjson, const std::string& smalljson)
		{
			reqProm.set_value(code);
		});
		int code = reqFut.get();
		bool isTrue = (code == 0 || code == 536);
		return isTrue;
	}

	bool FileServiceUnitest::uploadFile() {
		//******************上传文件**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		UploadFileProperty fileProperty;
		fileProperty.targetid = m_config->m_testUserTarget;
		fileProperty.localPath = m_config->m_upLoadFilePath;
		fileProperty.localid = time(NULL);

		fileProperty.type = 1;



		m_fileService->uploadFile(fileProperty, [&](int code, int64 a, std::string json)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, std::string njson) {});


		int code = reqFut.get();
		bool isTrue = (code == 0 || code == 536);
		return isTrue;
	}

	int FileServiceUnitest::uploadShareFile() {
		//******************外部上传文件(iOS专用)**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		UploadFileProperty fileProperty;
		std::string loginInfo = "https://vrv.linkdood.cn:10669";
		fileProperty.localid = time(NULL);
		fileProperty.localPath = m_config->m_upLoadFilePath;
		fileProperty.targetid = m_config->m_testFriendUserId;


		m_fileService->uploadShareFile(fileProperty, loginInfo, [&](int code, int64 a, std::string json)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, std::string njson) {});


		int code = reqFut.get();
		return code;
	}

	int FileServiceUnitest::downloadFile() {
		//******************下载文件**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		DownloadFileProperty fileProperty;

		fileProperty.fileName = m_config->m_upLoadFilePath;

		fileProperty.targetId = m_config->m_testUserTarget;

		fileProperty.localId = time(NULL);

		fileProperty.fromUserId = m_config->m_iMyUserId;

		fileProperty.md5Code = "";


		m_fileService->downloadFile(fileProperty, [&](int code,const std::string &json, int64 a)
		{
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

	int FileServiceUnitest::downloadExternalFile() {
		//******************下载外部文件**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string localPath = m_config->m_upLoadFilePath;

		m_fileService->downloadExternalFile(localPath, "http://192.168.139.250/linkdood/SDK/test.rar", 1, [&](int code)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, std::string njson) {});

		int code = reqFut.get();
		return code;
	}

	bool FileServiceUnitest::uploadImage() {
		//******************上传照片**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string thumbimg = m_config->m_upLoadImg;
		std::string srcimg = m_config->m_upLoadImg;
		std::string encryptkey = "";

		m_fileService->uploadImage(m_config->m_testGroupId, 0, thumbimg, srcimg, encryptkey, [&](int code, int64 a, std::string json, std::string mjson)
		{
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		bool isTrue = (code == 0 || code == 536);
		return isTrue;
	}

	bool FileServiceUnitest::uploadShareImage() {
		//******************上传分享图片**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		UploadShareImageProperty imgProp;
		imgProp.srcImg = m_config->m_uploadShareImagePath;
		imgProp.thumbImg = m_config->m_uploadShareImagePath;

		imgProp.encryptkey = "";
		imgProp.loginfoPath = "";

		m_fileService->uploadShareImage(imgProp, [&](int code, std::string json, std::string mjson)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, std::string njson) {});

		int code = reqFut.get();
		bool isTrue = (code == 0 || code == 536);
		return isTrue;
	}

	int FileServiceUnitest::downloadImage() {
		//******************下载图片**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string url = "test";

		//m_fileService->downloadImage(m_config->m_testGroupId, url, [&](int code,const std::string &localpath, int64 facetoID)
		//{
		//	reqProm.set_value(code);
		//});

		//int code = reqFut.get();
		return 0;
	}

	int FileServiceUnitest::downloadNineBoxImage2() {
		//******************下载九宫格图片2 会存fileInfo库的那种**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		DownloadImageParam dip;
		dip.targetID = m_config->m_testFriendUserId;
		dip.nineBoxUrl = { m_config->m_upLoadImg };
		dip.encryptKey = "";
		dip.flag = 1;
		dip.fileType = 5;
		dip.md5Code.push_back("");
		dip.targetID = m_config->m_testGroupTarget;
		std::vector<std::string> nineBoxUrl = { m_config->m_upLoadImg };
		dip.nineBoxUrl = nineBoxUrl;
		m_fileService->downloadNineBoxImage2(dip, [&](int code, int64 faceID,const std::string &localpath, int8 imgindex, int8 imgsum)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, const std::string &njson) {});

		int code = reqFut.get();
		return code;
	}

	int FileServiceUnitest::downloadNineBoxImage() {
		//******************下载九宫格图片**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<std::string> url = { m_config->m_upLoadImg };

		m_fileService->downloadNineBoxImage(m_config->m_testGroupId, url, [&](int code, int64 faceID,const std::string &localpath, int8 imgindex, int8 imgsum)
		{
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

	int FileServiceUnitest::downloadImage2() {
		//******************下载图片2 会存fileInfo库的那种**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		DownloadImageParam dip;
		dip.targetID = m_config->m_testFriendUserId;
		dip.nineBoxUrl = { m_config->m_upLoadImg };
		dip.encryptKey = "";
		dip.flag = 1;
		dip.fileType = 5;
		dip.md5Code.push_back("");
		m_fileService->downloadImage2(dip, [&](int code,const std::string localpath, int64 faceID)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c,const std::string njson) {});

		int code = reqFut.get();
		return code;
	}


	bool FileServiceUnitest::encryptFile() {
		//******************加密文件**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string encryptkey = " ";
		std::string beforeimgpath = m_config->m_upLoadFilePath;
		std::string afterimgpath = m_config->m_encryFilePath;
		int8 flag = 1;
		bool isOK = m_fileService->encryptFile(encryptkey, beforeimgpath, afterimgpath);
		return isOK;
	}

	bool FileServiceUnitest::decryptFile() {
		//******************解密文件**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string encryptkey = " ";
		std::string beforeimgpath = m_config->m_encryFilePath;
		std::string afterimgpath = m_config->m_decryFilePath;


		bool isOK = m_fileService->decryptFile(encryptkey, beforeimgpath, afterimgpath, 1);
		return isOK;
	}

	bool FileServiceUnitest::compress() {
		//******************压缩文件**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string compresspath = m_config->m_compressPath;

		bool isOK = m_fileService->compress(compresspath, 1);
		return isOK;
	}

	bool FileServiceUnitest::uncompress() {
		//******************解压文件**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::string uncompresspath = m_config->m_uncompressPath;

		bool isOK = m_fileService->uncompress(uncompresspath);
		return isOK;
	}

	int FileServiceUnitest::getFileList1() {
		//******************获取文件列表1**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_fileService->getFileList(m_config->m_testFriendUserId, 23155710, 1, 0, [&](int code, std::vector<Fileinfo>& json)
		{
			reqProm.set_value(code);
		});


		int code = reqFut.get();
		return code;
	}

	int FileServiceUnitest::getFileList2() {
		//******************获取文件列表2**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		GetGroupFile par;
		par.targetID = m_config->m_testFriendUserId;
		par.msgBeginID = 23155710;
		par.msgOffset = 0;
		par.offsetFlag = 0;


		std::vector<Fileinfo> josna;

		m_fileService->getFileList(par, [&](int code, std::vector<Fileinfo>& json)
		{
			reqProm.set_value(code);
			josna = json;
		});

		/*int a = 1;
		if (!josna.empty())
		{
		a = josna[0].fileid;
		}*/
		int code = reqFut.get();
		return code;
	}

	int FileServiceUnitest::getFilesInfo() {
		//******************通过文件消息ID得到文件详细信息 同步接口**************
		std::vector<int64> fileMsgIds = {};
		std::map<int64, Fileinfo> files = {};


		m_fileService->getFilesInfo(fileMsgIds, files);
		return 0;
	}

	bool FileServiceUnitest::isTransmitting() {
		//******************判断是否有文件在传输 同步接口**************
		std::vector<int64> fileMsgIds = {};
		std::map<int64, Fileinfo> files = {};


		bool isOK = m_fileService->isTransmitting();
		return isOK;
	}

	bool FileServiceUnitest::isTransmittingInTarget() {
		//******************判断个人或群中是否有文件传输 同步接口**************
		bool isOK = m_fileService->isTransmittingInTarget(m_config->m_testFriendUserId);
		return isOK;
	}

	int FileServiceUnitest::cancelTransfer() {
		//******************取消文件上传或下载**************
		std::promise<int> reqPromset;
		std::future<int> reqFutset = reqPromset.get_future();
		std::promise<int> reqPromget;
		std::future<int> reqFutget = reqPromget.get_future();



		DownloadFileProperty fileProperty;

		fileProperty.fileName = m_config->m_upLoadFilePath;

		fileProperty.targetId = m_config->m_testUserTarget;

		int64 localID = m_fileService->downloadFile(fileProperty, [&](int code,const std::string &json, int64 a)
		{
			
		}, [&](int32 b, int32 c, const std::string &njson) {reqPromset.set_value(b); });


		m_fileService->cancelTransfer(localID, 2, [&](int code)
		{
			reqPromget.set_value(code);
		});

		int code = reqFutget.get();
		return code;
	}

	bool FileServiceUnitest::cancelTargetTransfer() {
		//******************取消个人或群中的所有文件传输 同步接口**************
		bool isOK = m_fileService->cancelTargetTransfer(m_config->m_testGroupTarget);
		return isOK;
	}

	int FileServiceUnitest::cancelAllTransfer() {
		//******************取消所有文件传输**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_fileService->cancelAllTransfer([&](int code)
		{
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

	bool FileServiceUnitest::getAlreadyDownload() {
		//******************获取本地文件已经下载大小 同步接口**************
		std::string localpath = m_config->m_upLoadFilePath;
		downloadFileInfo info;
		info.localPath = m_config->m_upLoadFilePath;
		info.remotePath = m_config->m_upLoadFilePath;

		bool isOK = m_fileService->getAlreadyDownload(localpath, info);
		return isOK;
	}

	int FileServiceUnitest::checkUrlValid() {
		//******************检查URL是否有效**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		m_fileService->checkUrlValid("Https://192.168.1.1:80", [&](int code)
		{
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

	bool FileServiceUnitest::getNameByUrl() {
		//******************通过文件的的服务器路径获取一个本地的唯一文件名**************
		std::string result = m_fileService->getNameByUrl("test");
		bool isOK = 0;
		if (!result.empty())
		{
			isOK = 1;
		}
		return isOK;

	}

	int FileServiceUnitest::delayFiles() {
		//******************检查延期文件的有效时长是否有效**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<std::string> fileUrls = {"test"};
		m_fileService->delayFiles(fileUrls, [&](int code, int32 a, std::vector<std::string>& json)
		{
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

	int FileServiceUnitest::queryFileValid() {
		//******************查询文件是否过期**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();



		std::vector<std::string> fileUrls;



		m_fileService->queryFileValid(fileUrls, [&](int code, int32 a, std::vector<std::string>& json)
		{
			reqProm.set_value(code);
		});

		int code = reqFut.get();
		return code;
	}

	int FileServiceUnitest::reduceImage() {
		//******************将原图压缩尺寸为大图和小图**************
		std::string strImage = m_config->m_uploadShareImagePath;
		std::string smallImage = m_config->m_uploadShareImagePath;
		std::string bigImage = m_config->m_uploadShareImagePath;

		int code = m_fileService->reduceImage(strImage, smallImage, bigImage);
		return code;
	}

	int FileServiceUnitest::putShowMarkOnImage() {
		//******************给图片添加明水印**************
		std::string strImage = m_config->m_markImagepath;
		std::string toImagepath = m_config->m_markImagepath;
		std::string strMark = "vrv";

		int code = m_fileService->putShowMarkOnImage(strImage, toImagepath, strMark);
		return code;
	}

	int FileServiceUnitest::putMarkOnImageSimple() {
		//******************给图片添加id水印**************
		std::string strImage = m_config->m_markImagepath;
		std::string toImagepath = m_config->m_markImagepath;
		int64 strMark = 111;

		int code = m_fileService->putMarkOnImageSimple(strImage, toImagepath, strMark);
		return code;
	}

	int FileServiceUnitest::getMarkFromImageSimple() {
		//******************获取水印图的id水印**************
		std::string strImage = m_config->m_markImagepath;

		int64 code = m_fileService->getMarkFromImageSimple(strImage);
		return code;
	}

	int FileServiceUnitest::putMarkOnImageFFT() {
		//******************给图片添加频谱水印**************
		std::string strImage = m_config->m_markImagepath;
		std::string toImagepath = m_config->m_markImagepath;
		std::string strMark = " ";

		int code = m_fileService->putMarkOnImageFFT(strImage, toImagepath, strMark);
		return code;
	}

	int FileServiceUnitest::getMarkFromImageFFT() {
		//******************获取水印图的频谱水印**************
		std::string strImage = m_config->m_markImagepath;


		int code = m_fileService->getMarkFromImageFFT(strImage);
		return code;
	}

	int FileServiceUnitest::migrateUserData() {
		//******************数据迁移接口 只提供压缩和解压功能，传输需要客户端自行完成，压缩后的数据是加密的**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

#ifdef SDK_UNITEST_DEV
		m_fileService->migrateUserData(".\\userbackup.zip", 1, [&](int code)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, std::string njson) {});

#else
		m_fileService->migrateUserData(".\\userbackup.zip", 1,"",[&](int code)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, std::string njson) {});
#endif
		int code = reqFut.get();
		return code;
	}

	int FileServiceUnitest::migrateUserDataNew() {
		//******************数据迁移接口,设置选择实现部分服务器的迁移 只提供压缩和解压功能，传输需要客户端自行完成，压缩后的数据是加密的**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		std::vector<std::string> dirNameVt = {};

#ifdef SDK_UNITEST_DEV
		m_fileService->migrateUserDataNew(dirNameVt, ".\\userbackup.zip", 1, [&](int code)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, std::string njson) {});
#else
		m_fileService->migrateUserDataNew(dirNameVt, ".\\userbackup.zip", 1,"",[&](int code)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, std::string njson) {});
#endif
		int code = reqFut.get();
		return code;
	}
	int FileServiceUnitest::getP2pUsers() {
		//******************获取局域网可以P2P通讯的用户 同步接口**************
		std::promise<int> reqProm;
		std::future<int> reqFut = reqProm.get_future();

		p2pUser user;
		user.flag = 0x01;
		user.userid = m_config->m_testFriendUserId;
		std::vector<model::p2pUser> p2pUsers = { user };

		int code = m_fileService->getP2pUsers(p2pUsers);
		return code;
	}

	int FileServiceUnitest::p2pTransferCancle() {
		//******************取消正在进行的传输或拒绝尚未开始的p2p传输 同步接口**************
		int64  taskID = 0;

		m_fileService->p2pTransferCancle(taskID);
		return 0;
	}

	int FileServiceUnitest::updateFileLocalPath() {
		//******************更新已下载的文件的保存路径到数据库**************
		std::promise<int> reqProm;

		std::future<int> reqFut = reqProm.get_future();

		DownloadFileProperty fileProperty;

		fileProperty.fileName = m_config->m_upLoadFilePath;

		fileProperty.targetId = m_config->m_testUserTarget;

		fileProperty.localId = time(NULL);

		fileProperty.fromUserId = m_config->m_iMyUserId;

		int64 fileLocalID = m_fileService->downloadFile(fileProperty, [&](int code, std::string json, int64 a)
		{
			reqProm.set_value(code);
		}, [&](int32 b, int32 c, std::string njson) {});
		reqFut.get();

		std::string filepath = m_config->m_upLoadFilePath;
		int code = m_fileService->updateFileLocalPath(23324567, filepath);
		return 0;
	}
}