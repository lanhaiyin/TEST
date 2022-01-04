#include "Environment.h"
namespace serviceTest {
	class CloudServiceUnitest /*:public testing::Test*/ {
	public:
		CloudServiceUnitest();
		int uploadFile();						//上传文件 
		int queryFloder();						//获取会话列表
		int addFile();							//添加文件
		int delFile();							//删除文件
		int renameFile();						//重命名文件
		int getFileById();						//插入消息
		int getFilesByHash();					//通过文件hash码获取文件
		bool getFilesByHashSync(); 				//通过文件hash码获取文件
		int searchFiles();						//搜索文件
		int createTeam();						//创建团队文件夹
		int teamAddMember();					//添加团队成员
		int teamRemoveMember();					//移除团队成员
		int teamResetMember();					//重置团队成员
		int getTeams();							//获取团队文件夹
		int teamMembers();						//获取团队文件夹所有成员
		int getRoles();							//获取团队成员角色
		int getRoleById();						//通过角色ID获取团队成员角色
		int addRole();							//增加团队成员角色
		int editRole();							//编辑团队成员角色
		int removerRole();						//移除团队成员角色
		int getPermission();					//获取许可信息
		int getCloudFileInfo();					//userId 用户ID
		int createPubDir();						//创建公共文件夹
		int uploadFile_new();					//上传文件new 
		int moveFile();							//移动文件夹
		int copyFile();							//复制文件夹
		int querySubFolders();					//查询文件夹下面的子文件夹
		int queryFolderByParam();				//查询文件夹
		int checkFileExit();					//查询文件夹
		int downloadFile();						//下载文件
		int delFile_new();						//删除文件
		int renameFile_new();					//重命名文件
		int moveFile_new();						//移动文件
		int copyFile_new();						//拷贝文件
		int restoreCloudFile();					//云盘回收站还原
		int clearCloudFile();					//云盘回收站清空
		int syncCloudFile();					//同步文件/文件夹
		int getCloudTrashInfo();				//拉取回收站信息
		int getNewCloudFileInfo();				//获取文件夹下所有的子目录和文件的详细信息
		int getNextLevelInfo();					//获取下一层文件夹的信息
		int getCloudUserInfo();					//查询文件夹下面的子文件夹
		int createShare();						//创建共享目录
		int cloudShareToOther();				//共享给别人的目录
		int cloudShareToMe();					//别人共享给我的
		int cloudChangeSharefolder();			//修改共享目录权限
		int cloudChangeShareuser();				//修改共享人权限
		int getCloudShareInfo();				//获取文件自身的共享信息
		int setUserSetting();					//个人设置信息
		int getUserSetting();					//查询文件夹下面的子文件夹
		int getCloudContactInfo();				//获取用户名
		int getCloudTransferHistory();			//获取云盘上传/下载历史任务
		int delCloudTransferHistory();			//删除云盘上传/下载历史任务
		int clearCloudTransferHistory();		//清空云盘上传/下载历史任务
	protected:
		virtual void TestBody() {}
	private:
		std::shared_ptr<ICloudService> m_cloudService = nullptr;
	};
}