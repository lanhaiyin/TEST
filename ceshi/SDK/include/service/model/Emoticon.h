#pragma once
#include <string>
#include "SDKTypes.h"
namespace model
{
///表情
class Emoticon 
{
public:
	Emoticon() :userID(0), createTime(0), property(0), emoStatus(0), type(0), category(0), bRead(0)
	{}
public:
	std::string mdCode;          ///<整个文件的MD5hashcode码
	std::string depict;          ///<表情描述
	int64 userID;                ///<表情创建人
	int64 createTime;            ///<创建时间
	std::string mainUrl;          ///<表情Url
	int8 property;               ///<表情属性 1：表情包2：自定义表情
	int8 emoStatus;              ///<表情状态 1：服务器记录该文件被下载或收藏 2：服务器记录该文件被卸载或取消收藏
	std::string packageCode;      ///<关联表情包Code
	int8 type;                  ///<表情类型 1：静态表情2：动态表情
	
	int8 category; ///<表情类目 1人物 2情侣 3动物 4食物 5节日 6网络热点 7征稿活动 8其他
	std::string label;///<表情标签  多个标签用分隔符分开，web端自己定义自己解析，服务只做存储
	std::string thumbnailUrl;;///<缩略图url
	std::string meaning;;///<表情含义
	std::string orderNum;;///<排序字段
	std::string extendFiled;;///<拓展字段1
	std::string extendColumn;;///<拓展字段2
	std::string sha256Hash;       ///< 表情sha256
	int8 bRead;                   ///< 是否已读，0表示未读，1表示已读
	std::string domainPort;        ///< 来源域名加端口
	std::string elogo;            ///< 来源elogo
	std::string gifPath;           ///< 动态图片本地路径
	std::string pngPath;           ///< 静态图片本地路径
	std::string emotionSdkPath;    ///< 表情存储在sdk的跟路径
};
struct singleEmoticon
{
	std::string mdCode;               ///< 单个表情MdCode
	std::string thumbnailUrl;
	std::string mainUrl;              ///< 大图地址
	std::string meaning;              ///< 含义	
};
///表情包	 
class EmoticonPackage
{
public:
	EmoticonPackage() :userID(0), createTime(0), property(0), packStatus(0), type(0), category(0), bRead(0)
	{
	}

	std::string mdCode;;///<整个文件的MD5hashcode码
	std::string depict;;///<表情描述
	int64 userID;;///<表情创建人
	int64 createTime;;///<创建时间
	std::string mainUrl;;///<表情Url
	int8 property;;///<表情属性 1：表情包2：自定义表情
	int8 packStatus;;///<表情状态 1：服务器记录该文件被下载或收藏 2：服务器记录该文件被卸载或取消收藏
	std::string name;;///<表情包名称
	std::string bannerUrl;;///<详细页横幅URL
	int8 type;;///<表情类型 1：静态表情2：动态表情
	
	int8 category;;///<表情类目 1人物 2情侣 3动物 4食物 5节日 6网络热点 7征稿活动 8其他
	std::string label;///<表情标签  多个标签用分隔符分开，web端自己定义自己解析，服务只做存储
	std::string iconUrl;             ///<图标url
	std::string coverUrl;            ///<封面URL
	std::string instruction;         ///<表情包说明
	std::string orderNum;            ///<排序字段
	std::string extendFiled;         ///<拓展字段1
	std::string extendColumn;         ///<拓展字段2
	//std::string emoticonListJson;     ///<关联表情 格式json-list<map>
	std::vector<Emoticon> emoticonList;  ///<表情包
	int8 bRead;                   ///< 是否已读，0表示未读，1表示已读
	std::string domainPort;        ///< 来源域名加端口
	std::string elogo;            ///< 来源elogo
	std::string emotionSdkPath;    ///< 表情包存储在sdk的跟路径

};
///单个查询表情
struct querySingleEmoticon 
{
	std::string packMdCode;    ///< 表情包mdCode
	std::string mdCode;        ///< 包内单个表情mdCode
};
///表情页查询结构
struct PageQueryEmoticon 
{
	PageQueryEmoticon():pageNum(0), pageSize(0), totalPage(0), totalItems(0) {}
	void init()
	{
		emotItem.clear();
	}
	int32 pageNum;     ///<请求页码
	int16 pageSize;    ///<每页大小
	int64 totalPage;   ///<总页数
	int64 totalItems;  ///<总条数
	std::vector<EmoticonPackage> emotItem; ///<当前页数据

};
///表情查询结果结构
struct EmoticonResult
{
	EmoticonResult() :resultCode(0), orderNum(0),status(0), type(0){}
	int resultCode;                  ///<结果编码 801:md5Code不存在，802：md5Code文件已存在
	std::string resultMessage;        ///<结果信息
	std::string mdCode;              ///<表情code
	int64 orderNum;                   ///<排序
	std::string mainUrl;        ///<大图
	std::string  thumbnailUrl;  ///<缩略图
	std::string  name;          ///<名称
	std::string  shaHash;       ///<两个图片的hash256值
	int status;        ///<1表示新增，2表示删除
	int type;                   ///<1表示表情包，2表示自定义表情
};


struct  singleEmoticonResult{
	singleEmoticonResult() :type(0){}
	std::string packMdCode;           ///< 表情包MdCode
	std::string mainUrl;              ///< 大图地址
	std::string meaning;              ///< 含义
	std::string mdCode;               ///< 单个表情MdCode
	int8 type;                        ///< 表情类型 1：静态表情2：动态表情
};

}