#pragma once

#include "../model/SDKTypes.h"
#include "../model/Packet.h"
#include "IService.h"

#include <string>
#include <vector>
#include <map>

#define VER_FILE INTERFACE_VERSION(1,0)
static const VRVIID IID_IFileService = { 0xc1388c4f, 0x9cb4, 0x4907, 0xa2, 0xee, 0x18, 0xab, 0x98, 0x72, 0x2a, 0x54 };

namespace service
{

class IFileService : public IService
{
public:
	virtual ~IFileService(){}

	/**
	* \brief 注册进度推送
	*@param cb _1 进度对应的文件的localId _2 进度标示 _3进度 _4文件当前传入大小/文件总大小
	*/
	virtual void regProcessCb(SFunction<void(int64, int32, int32, const std::string&)> cb) = 0;
	/**
	* \brief 注册p2p用户状态改变推送
	*@param cb _1 用户Id _2 0x01 PC , 0x02 移动终端 _3 上线 0 ， 下线， 1
	*/
	virtual void regP2pUserStatusChgCb(SFunction<void(int64, int8, int8)> cb) = 0;
	/**
	* \brief 注册p2p用户发送文件请求推送
	*@param cb _1 见Packet.h 中P2pSendFileReq注释
	*/
	virtual void regP2pSendFileReqCb(SFunction<void(P2pSendFileReq&)> cb) = 0;
	/**
	* \brief 注册p2p用户文件传输操作推送
	*@param  cb _1 接收 0,  取消 1 _2 发送标识taskID
	*/
	virtual void regP2pFileTransOpCb(SFunction<void(int8, int64)> cb) = 0;

	/**
	* \brief 上传头像
	* @param[in] path 传入头像本地路径
	* @param[in] cb  传入接收结果回调 _1错误信息  _2大图地址json _3缩略图地址json
	*/
	virtual void uploadAvatar(const std::string &path, SFunction<void(ErrorInfo, const std::string&, const std::string&)> cb) = 0;

	/**
	* \brief 上传背景图
	* @param[in] path 传入背景图本地路径
	* @param[in] cb  传入接收结果回调 _1错误信息  _2大图地址json _3缩略图地址json
	*/
	virtual void uploadBackground(const std::string &path, SFunction<void(ErrorInfo, const std::string&, const std::string&)> cb) = 0;

	/**
	* \brief 上传文件  ///若断点上传,key必须一致
	* @param[in] targetId 人或群的id
	* @param[in] cb  传入接收结果回调 _1错误信息 _2目标Id _3服务器返回的json
	* @param[in] pro  进度回调 _1 extra_req  _2process 
	* @return 每个文件对应的唯一localID
	*/
	virtual int64 uploadFile(UploadFileProperty &fileProperty, SFunction<void(ErrorInfo, int64, const std::string&)> cb,
		SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;
    /**
    * \brief 外部上传文件(iOS专用)
    * @param[in] fileProperty 上传文件参数
    * @param[in] loginInfo 插件登录信息
    * @param[in] cb  传入接收结果回调 _1错误信息 _2目标Id _3服务器返回的json
    * @param[in] pro  进度回调 _1 extra_req  _2process
    * @return 每个文件对应的唯一localID
    */
    virtual int64 uploadShareFile(UploadFileProperty &fileProperty, const std::string& loginInfo, SFunction<void(ErrorInfo, int64, const std::string&)> cb,
        SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;

	/**
	* \brief 更新已下载的文件的保存路径到数据库
	* @param[in] fileMsgId 文件消息的msgID
	* @param[in] path 传入需要更新的路径
	* @return  0成功 非0失败 错误码待定
	*/
	virtual int64 updateFileLocalPath(int64 fileMsgId, const std::string newPath) = 0;

	/**
	* \brief 下载文件
	* @param[in] targetId 发送者的targetId
	* @param[in] fileMsgId 文件消息的msgID
	* @param[in] path 传入下载路径
	* @param[in] url 传入url
	* @param[in] 群文档上传 DownloadFileProperty 需要添加isGroupDoc赋值为1,docid赋值为文档docid
	* @param[in] cb  传入接收结果回调 _1错误信息  _2接收成功后文件路径 localPath _3发送者ID
	* @param[in] pro  进度回调
	* @return 每个文件对应的唯一localID,
	*/
	virtual int64 downloadFile(DownloadFileProperty &fileProperty, SFunction<void(ErrorInfo, const std::string&, int64)> cb, 
		SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;

	/**
	* \brief 下载外部文件
	* @param[in] localPath 文件本地保存路径 
	* @param[in] url  flag = 0时为远程路径完整的URL路径  flag = 1时为远程路径,从消息JSON中解析出来的路径,或上0xF0，代表只判断文件有效性，不下载 remotePath
	* @param[in] cb  传入接收结果回调 _1错误信息 
	* @param[in] pro  进度回调
	* @return 每个文件对应的唯一localID
	*/
	virtual int64 downloadExternalFile(const std::string &localPath, const std::string &url, int8 flag, SFunction<void(ErrorInfo)> cb,
		SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;

	/**
	* \brief 上传照片
	* @param[in] targetId 人或群的id
	* @param[in] localId  localId,失败重发时必须传上次的localId
	* @param[in] thumbimg 传入缩略图
	* @param[in] srcimg 传入原图
	* @param[in] encryptkey 传入解密密码
	* @param[in] cb  传入接收结果回调 _1错误信息 _2目标ID， _3原图JSON， _4缩略图JSON
	*/
	virtual void uploadImage(int64 targetId, int64 localId, const std::string &thumbimg, const std::string &srcimg, const std::string &encryptkey,
							SFunction<void(ErrorInfo, int64, const std::string&, const std::string&)> cb,
							SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;

	/**
	* \brief 上传分享图片
	* @param[in] thumbimg 传入缩略图
	* @param[in] srcimg 传入原图
	* @param[in] encryptkey 传入解密密码
	* @param[in] cb  传入接收结果回调 _1错误信息， _2原图完整地址， _3缩略图完整地址
	*/
	virtual void uploadShareImage(UploadShareImageProperty &imgProp,
							SFunction<void(ErrorInfo, const std::string&, const std::string&)> cb,
							SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;

	/**
	* \brief 下载图片
	* @param[in] targetId 人或群的id 分享图片时传0
	* @param[in] url 传入图片url
	* @param[in] cb  传入接收结果回调 _1错误信息  _2本地文件路径 imgName  _3对方ID
	*/                                       
	virtual void downloadImage(int64 targetId, const std::string &url, SFunction<void(ErrorInfo, const std::string&, int64)> cb,
		SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;

	

	/**
	* \brief 下载九宫格图片
	* @param[in] targetId 人或群的id
	* @param[in] url 传入所有图片url
	* @param[in] cb  传入接收结果回调 回调的次数和上传图片的次数一致  _1错误信息  _2对方ID _3本地文件路径 imgName _4图片索引 0-8 _5图片总数
	*/                                       
	virtual void downloadNineBoxImage(int64 targetId, std::vector<std::string> &url, SFunction<void(ErrorInfo, int64, const std::string&, int8, int8)> cb,
		SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;
	/**
	* \brief 下载图片2 会存fileInfo库的那种
	* @param[in] dip 下载参数，见packet.h
	* @param[in] cb  传入接收结果回调 _1错误信息  _2本地文件路径 imgName  _3对方ID
	*/
	virtual void downloadImage2(DownloadImageParam &dip, SFunction<void(ErrorInfo, const std::string&, int64)> cb,
		SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;
	/**
	* \brief 下载九宫格图片2 会存fileInfo库的那种
	* @param[in] dip 下载参数，见packet.h
	* @param[in] cb  传入接收结果回调 回调的次数和上传图片的次数一致  _1错误信息  _2对方ID _3本地文件路径 imgName _4图片索引 0-8 _5图片总数
	*/
	virtual void downloadNineBoxImage2(DownloadImageParam &dip, SFunction<void(ErrorInfo, int64, const std::string&, int8, int8)> cb,
		SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;

	/**
	* \brief 解密文件
	* @param[in] encryptkey 传入解密密码
	* @param[in] srcpath 传入原图路径
	* @param[in] destpath 传入解密后图片路径
	* @param[in] flag 解密出的文件属性 1、读写 2、只读
	*/
	virtual bool decryptFile(const std::string &encryptkey, const std::string &srcpath, const std::string &destpath, int8 flag=1) = 0;
	/**
	* \brief 加密文件
	* @param[in] encryptkey 传入加密密码
	* @param[in] srcpath 传入原图路径
	* @param[in] destpath 传入加密后图片路径
	*/
	virtual bool encryptFile(const std::string &encryptkey, const std::string &srcpath, const std::string &destpath) = 0;

	/**
	* \brief 压缩文件
	* @param[in] filePath 文件完整路径
	* @param[in] level 压缩等级1-9,等级越高，压缩比例越大
	*/
	virtual bool compress(const std::string &filePath, int level) = 0;
	/**
	* \brief 解压文件
	* @param[in] filePath 文件完整路径
	*/
	virtual bool uncompress(const std::string &filePath) = 0;

	/**
	* \brief 获取文件列表
	* @param[in] targetid 传入查询对象id
	* @param[in] fileid 传入起始文件id
	* @param[in] count 传入数量
	* @param[in] flag 传入偏移标志0为向上1为向下
	* @param[in] cb  传入接收结果回调 _1错误信息  _2文件信息集合
	* 备注：移动端我的文件需求，文件类型展示的时候分为办公和其它的，客户端需要分别传6和-1
	*/
	virtual void getFileList(int64 targetid, int64 fileid, int count, int flag, SFunction<void(ErrorInfo, std::vector<Fileinfo>&)> cb) = 0;
	virtual void getFileList(GetGroupFile par, SFunction<void(ErrorInfo, std::vector<Fileinfo>&)> cb) = 0;

	/**
	* \brief 通过文件消息ID得到文件详细信息 同步接口
	* @param[in] fileMsgIds  文件消息ID集合
	* @param[in] files 返回文件信息
	*/
	virtual void getFilesInfo(std::vector<int64> &fileMsgIds, std::map<int64, Fileinfo> &files) = 0;

	/**
	* \brief 判断是否有文件在传输
	* @param[in] localId  文件的local, 0代表判断是否存在任意文件在上传状态
	*/
	virtual bool isTransmitting(int64 localId = 0) = 0;

	/**
	* \brief 判断个人或群中是否有文件传输
	* @param[in] targetId  个人或群Id
	*/
	virtual bool isTransmittingInTarget(int64 targetId) = 0;

	/**
	* \brief 取消文件上传或下载
	* @param[in] localId 文件的localId
	* @param[in] type  1.上传 2.下载 3.外部下载
	*/
	virtual void cancelTransfer(int64 localId, int type, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	* \brief 取消个人或群中的所有文件传输
	* @param[in] targetId人或群Id
	* @param[in] cb  _1 错误码
	*/
	virtual bool cancelTargetTransfer(int64 targetId) = 0;

	/**
	* \brief 取消所有文件传输
	*/
	virtual void cancelAllTransfer(SFunction<void(ErrorInfo)> cb) = 0;
	/**
	*\brief 获取局域网可以P2P通讯的用户
	*@param[in] p2pUsers 用来接收获取的p2p用户 
	*@return 返回值 见errorExport.h p2p项
	*/
	virtual int  getP2pUsers(std::vector<model::p2pUser>& p2pUsers) = 0;
	/**
	* \brief 取消正在进行的传输或拒绝尚未开始的p2p传输
	* @param[in] cb  传入接受结果回掉 _1 错误信息 _2见packet.h
	*/
	virtual void  p2pTransferCancle(int64  taskID) = 0;
	/**
	 *\brief 获取本地文件已经下载大小
	 *@Param[in] localPath 本地文件路径
	 */
	virtual bool getAlreadyDownload(std::string&, downloadFileInfo&) = 0;

	/**
	*\brief 获取文件分片信息
	*@Param[in] Path 本地文件路径
	*@Param[in] isEncrypt 是否加密
	*@Param[in] burstSize 分片大小
	*@Param[out] cb 传入接口结果回调，_1错误信息  _2文件总分片数量 _3加密秘钥(isEncrypt为false时返回空)等信息
	*/
	virtual void getFileFragmentationInfo(const std::string& path, bool isEncrypt, int32 burstSize, SFunction<void(ErrorInfo, fileFragmentationInfo&)> cb) = 0;

	/**
	*\brief 文件分片内容获取
	*@Param[in] fileid 文件ID
	*@Param[in] fileIndex 片索引值数组
	*@Param[in] burstSize 分片大小，单位字节
	*@Param[out] cb 传入接口结果回调，_1错误信息  _2文件分片内容
	*/
	virtual void getFileContentByFragmentIndex(std::string fileSrcpath, std::vector<int32>& fileIndex, int32 burstSize, SFunction<void(ErrorInfo , std::vector<std::string>&)> cb) = 0;

	/**
	*\brief 检查URL是否有效
	*@Param[in] url 要检查的url，如果为相对路径，下层会自己拼接为完整路径
	*/
	virtual void checkUrlValid(const std::string &url, SFunction<void(ErrorInfo)> cb) = 0;

	/**
	*\brief //通过文件的的服务器路径获取一个本地的唯一文件名 
	*@Param[in] url 服务器相对路径
	*/
	virtual std::string getNameByUrl(const std::string &url) = 0;

    /**
    * \brief 延期文件的有效时长
    *@Param[in] fileUrls    文件的服务器路径地址
    *@Param[out] cb 传入接口结果回调，_1错误信息  _2操作结果(0.全部成功 1.部分成功 -1.链接地址错误) _3过期文件url
    */
    virtual void delayFiles(std::vector<std::string>& fileUrls, SFunction<void(ErrorInfo, int32, std::vector<std::string>&)> cb) = 0;

    /**
    * \brief 查询文件是否过期
    *@Param[in] fileUrls    文件的服务器路径地址
    *@Param[out] cb 传入接口结果回调，_1错误信息  _2查询结果(0.全部未过期 1.部分过期 -1.链接地址错误) _3过期文件url
    */
    virtual void queryFileValid(std::vector<std::string>& fileUrls, SFunction<void(ErrorInfo, int32, std::vector<std::string>&)> cb) = 0;

	/**
	* \brief 查询单聊/群聊中文件的有效期天数 
	*@Param[in]    无入参，服务器配置信息，所有文件有效期都是一样
	*@Param[out] cb 传入接口结果回调，_1错误信息  _2单聊文件有效期 _3群聊文件有效期
	*/
	virtual void queryServerFileValidDays(SFunction<void(ErrorInfo, int32, int32)> cb) = 0;

	/**
	* \brief 获取未下载即将过期文件列表
	* @param[in] targetID  群或人id
	* @param[out] cb  传入接收结果回调  _1 错误信息 _2查询结果
	*	zhuohc
	*/
	virtual void getFileExpirySoonLists(std::vector<int64> targetIDs, SFunction<void(ErrorInfo, std::map<int64, std::vector<FileExpiryAttribute>>&)> cb) = 0;

	/**
	* \brief 获取是否有新未下载即将过期文件提醒，targetID传0时根据im_FileExpiry表中所有targetID去查msg，targetID指定时查询特定的群/人
	* @param[in] 无，查最近所有联系人
	* @param[out] cb  传入接收结果回调  _1 错误信息 _2查询结果
	*	zhuohc
	*/
	virtual void getFileExpirySoonResult(int64 targetID, SFunction<void(ErrorInfo, std::vector<FileExpiryResult>&)> cb) = 0;
	/**
	* \brief 存储未下载即将过期文件信息，三个字段targetID_msgID_isSwitchOn
	* @param[in] targetID  群或人id
	* @param[out] cb  传入接收结果回调  -1 错误 0 成功
	*	zhuohc
	*/
	virtual void fileExpirySoonInfoStore(FileExpiryInfoStore fileInfo, SFunction<void(ErrorInfo)> cb) = 0;
	
	/**
	* \brief 获取存储的未下载即将过期文件信息，三个字段targetID_msgID_isSwitchOn
	* @param[in] targetID  群或人id
	* @param[out] cb  传入接收结果回调  _1 错误信息 _2查询结果
	*	zhuohc
	*/
	virtual void fileExpirySoonInfoAsk(std::vector<int64> targetIDs, SFunction<void(ErrorInfo, std::vector<FileExpiryInfoStore>&)> cb) = 0;
	
	/**
	* \brief 将原图压缩尺寸为大图和小图
	* 支持 bmp, png, jpg, jpeg, jpe, jfif, jif 格式
	*@Param[in] strImage:   原图的路径
	*@Param[in] smallImage: 压缩小图的路径
	*@Param[in] bigImage:   压缩大图的路径
	*@return 返回值 0：成功 1：文件不存在 2：图片格式错误 3：图片错误
	*/
	virtual int reduceImage(const std::string& strImage, const std::string& smallImage, const std::string& bigImage) = 0;

	/**
	* \brief 给图片添加明水印
	*@Param[in] strImage: 原图的路径
	*@Param[in] toImage:  添加明水印后的图片路径
	*@Param[in] strMark:      水印内容
	*@return 返回值 0：成功 1：文件不存在 2：图片格式错误 3：图片错误 4：水印为空
	*/
	virtual int putShowMarkOnImage(const std::string& strImage, const std::string& toImage, const std::string& strMark) = 0;

	/**
	* \brief 给图片添加id水印
	* 此方法生成的水印图片不能抵抗截图等攻击手段，生成的水印图片质量和原图一样
	*@Param[in] strImage: 原图的路径
	*@Param[in] toImage:  添加暗水印后的图片路径
	*@Param[in] idMark:       水印id
	*@return  返回值 0:成功 1:文件不存在 2:图片格式错误 3:图片错误
	*/
	virtual int putMarkOnImageSimple(const std::string& strImage, const std::string& toImage, int64 idMark) = 0;

	/**
	* \brief 获取水印图的id水印
	*@Param[in] strImage: 水印图的路径
	*@return 返回值： >0：  水印id  -1:文件不存在  -2:图片格式错误 -3:图片错误
	*/
	virtual int64 getMarkFromImageSimple(const std::string& strImage) = 0;

	/**
	* \brief 给图片添加频谱水印
	* 此方法生成的水印图片可以抵抗截图，涂抹等攻击手段，但是生成的水印图片质量比原图有所降低
	*@Param[in] strImage: 原图的路径
	*@Param[in] toImage:  添加暗水印后的图片路径
	*@Param[in] strMark:      水印内容
	*@return 返回值  0:成功 1:文件不存在 2:图片格式错误 3:图片错误 4:水印为空
	*/
	virtual int putMarkOnImageFFT(const std::string& strImage, const std::string& toImage, const std::string& strMark) = 0;

	/**
	* \brief 获取水印图的频谱水印
	*@Param[in] strImage: 水印图路径
	*@return 返回值 0:成功 在同级目录下生成 原名+_mark.bmp水印图片 1:文件不存在 2:图片格式错误 3:图片错误
	*/
	virtual int getMarkFromImageFFT(const std::string& strImage) = 0;

	/**
	* \brief 数据迁移接口
	* 只提供压缩和解压功能，传输需要客户端自行完成，压缩后的数据是加密的
	*@Param[in] zipPath: 数据压缩文件路径
	*@Param[in] type:      功能选择 1.压缩 2.解压缩
	*@Param[in] passwd:  压缩密码，客户端传入加解密密码，为空则使用SDK默认密码
	*@Param[out] cb 传入接口结果回调，_1错误信息
	*@Param[out] pro 进度条回调 _1ext信息(1.压缩root 2.压缩rc，3,解压root,2,解压rc) _2进度 _3提示信息
	*/
	virtual void migrateUserData(const std::string& zipPath, int type, std::string passwd, SFunction<void(ErrorInfo)> cb, SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;


	/**
	* \brief 数据迁移接口,设置选择实现部分服务器的迁移
	* 只提供压缩和解压功能，传输需要客户端自行完成，压缩后的数据是加密的
	*@param[in] dirNameVt 需要压缩的目录名列表，比如bxy_3001(userID)，解压缩时不需要内容，传空vector即可
	*@Param[in] zipPath: 数据压缩文件路径
	*@Param[in] type:      功能选择 1.压缩 2.解压缩
	*@Param[in] passwd:  压缩密码，客户端传入加解密密码，为空则使用SDK默认密码
	*@Param[out] cb 传入接口结果回调，_1错误信息
	*@Param[out] pro 进度条回调 _1ext信息(1.压缩root 2.压缩rc，3,解压root,2,解压rc) _2进度 _3提示信息
	*/
	virtual void migrateUserDataNew(std::vector<std::string>& dirNameVt, const std::string& zipPath, int type, std::string passwd, SFunction<void(ErrorInfo)> cb, SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;

	/**
	* \brief 删除文件信息列表
	* @param[in] fileType 需要删除的文件类型(6文档 5图片(九宫格存储是5) 89视频 3音频)
	* @param[in] files 需要删除的文件集合
	* @param[in] cb  传入接收结果回调 错误信息
	*/
	virtual void delFileInfoList(int8 fileType, std::vector<delFileinfoList>& files, SFunction<void(ErrorInfo)> cb) = 0;


	/**
	* \brief 数据迁移接口,为大容量的数据迁移提供优先级选择
	* 只提供压缩和解压功能，传输需要客户端自行完成，压缩后的数据是加密的
	*@Param[in] hasDb: 数据迁移是否带数据库目录,解压缩时不需要 
	*@Param[in] hasFile: 数据迁移是否带文件目录,解压缩时不需要 
	*@Param[in] hasCollect: 数据迁移是否带客户的collect目录,解压缩时不需要 
	*@Param[in] spareSpace: 客户端剩余的可用空间，sdk通过剩余空间判断是否允许迁移
	*@param[in] dirNameVt 需要压缩的目录名列表，比如bxy_3001(userID)，解压缩时不需要内容，传空vector即可
	*@Param[in] zipPath: 数据压缩文件路径
	*@Param[in] type:      功能选择 1.压缩 2.解压缩
	*@Param[in] passwd:  压缩密码，客户端传入加解密密码，为空则使用SDK默认密码
	*@Param[out] cb 传入接口结果回调，_1错误信息 -16777113表示压缩使用的空间不足
	*@Param[out] pro 进度条回调 _1ext信息(1.压缩root 2.压缩rc，3,解压root,2,解压rc) _2进度 _3提示信息
	*/
	virtual void migrateUserDataOptional(int8 hasDb, int8 hasFile, int8 hasCollect, int64 spareSpace, std::vector<std::string>& dirNameVt, const std::string& zipPath, int type, std::string passwd, SFunction<void(ErrorInfo)> cb, SFunction<void(int32, int32, const std::string&)> pro = SNull) = 0;
};
	
} /*namespace service*/