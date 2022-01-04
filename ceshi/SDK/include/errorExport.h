﻿/*
 * errorExport.h
 *  错误号定义, 外部根据错误号进行具体错误提示及逻辑
 *  Created on: 2015年8月4日
 *      Author: sharp
 */

#ifndef PROTOCOL_ERROREXPORT_H_
#define PROTOCOL_ERROREXPORT_H_

/**
 * \brief -1  代表网络错误，
 *  -2　代表没有执行权限
	说明 :
	1. code = 0 代表函数执行成功

	2. 不等于0 通常意味着失败，但有些例外
		比如 :   142	添加好友成功
				143	关注成功
		这些需要仔细分辨，ap.thrift 后续会将每个函数可能的返回值加上，但目前没有

		建议客户端使用 map<code,string> 这种存储方式，便于查找

	3.	下面这个函数没有错误码
	    返回 -1 表示错误，其余的数字表示 当前sessionID 还没有被推送的消息数量
		getNotifyMsgSize

	4. what 返回说明, 小于10000 的错误码 what 通常不返回值
	   一旦返回,what 存储的是图片信息,需要用base64解码


	以下是目前可能返回给客户端的错误码

	100  参数错误 接口类型的参数 
	101  没有此用户 此用户不存在 
	102  没有访问权限,可能对方黑名单等 您没有权限访问 
	103  验证码不符  
	104  下一个校验图片  
	112  帐号密码错误 帐号密码不匹配 
	113  帐号已经登录  
	114  登陆mac地址为空  
	115  登陆验证票不正确  
	116  禁止登陆(3分钟)  
	117  需要验证 之前的验证没有通过,但放弃了验证，需要10分钟解除验证 
	120  该账号不存在,请重新验证  
	121  未发现绑定此手机/邮箱的账号  
	131  请求添加关注时,对方不允许陌生人关注 对方设置了隐私权限不允许加关注 
	132  请求加好友时,对方不允许陌生人加好友 对方设置了隐私权限不接收好友请求 
	133  问题回答错误,系统否决你的申请  
	134  已经是好友关系，不能重复添加  
	135  已经关注该用户  
	136  请求已发出,等待对方处理  
	137  该群组已不存在  
	138  操作的用户不存在  
	139  已经申请过好友关系了  
	141  已经申请过关注了  
	142  添加好友成功  
	143  关注成功  
	144  请求已经被对方处理  
	145  对方处理请求消息已被阅读  
	146  拒绝你的好友请求  
	147  不允许再次提交申请添加为好友  
	148  关注请求已被拒绝  
	149  以后不允许再申请添加为关注  
	151  添加好友到数据库失败  
	152  修改好友成功  
	153  修改好友数据库失败  
	154  删除好友成功  
	155  删除好友数据失败  
	156  删除聊天记录失败  
	157  操作类型有误，不是添加、修改、删除这三种类型  
	158  请求人ID和响应的对象不是同一人  
	159  不能添加自己为好友  
	160  忽略、忽视请求或者响应  
	161  参数为空  
	162  好友：已经把此用户拉入黑名单  
	163  好友：已经被此用户拉入黑名单  
	170  无法解析的URL  
	181  该邮箱账号已经存在  
	182  该手机账号已经存在 ( 账号已经存在了, 且没有设置密码, 需要使用验证码登录) 
	183  修改信息userBean中没有值修改  
	184  修改user失败  
	185  修改user联系方式登录状态失败  
	301  没有权限创建群  
	302  有权限创建群  
	303  该用户创建该级别的群已经超过数量限制  
	304  没有权限修改群信息  
	305  没有权限删除群信息  
	306  该群存在  
	307  该群已不存在  
	308  没有权限激活该群  
	309  该用户不是该群成员  
	310  该群级别，群成员已满  
	311  该群级别，群成员未满  
	312  不是超级管理员不能解散该群  
	313  不是管理员不能删除群成员  
	314  不能删除群超级管理员  
	315  超级管理员不能主动退出群，必须先转让超级管理员  
	316  非管理员不能，添加群成员  
	317  该用户不是该群成员，不能发出邀请  
	318  该群不允许普通人员邀请成员  
	319  该群已经满员，不能再发邀请，请对该群进行升级  
	320  不存在该邀请信息  
	321  该邀请信息已被处理  
	322  邀请人已经不在该群里面，邀请信息处理失效  
	323  该群不允许任何人添加  
	324  提示验证请求信息不存在编码  
	325  验证请求已经处理  
	326  邀请请求处理成功，请需要发送验证请求  
	327  处理人已经不在该群里面  
	328  不是群管理员，不能处理验证请求  
	329  不是管理员，不能修改其他人群名片  
	330  不是群成员，不能查看其他人群名片  
	331  不是群超级管理员，不能转让该群  
	332  不是群成员，不能转让该群给他  
	333  您已经在该群中，不能发送验证请求  
	334  非临时群不允许普通用户邀请  
	335  不是群超级管理员，不能设置群管理员  
	336  应用成员信息不能修改  
	337  移除群活动失败  
	338  没有此级别的群  
	389  修改群成员背景失败  
	340  不是管理员，无权操作  
	341  该群文件不存在  
	342  删除部分群文件成功（部分失败  
	343  用户ID无效或用户不存在  
	344  创建群失败 近距离建群 
	345  房间不存在 近距离建群／加好友 
	381  未指定接收者  
	382  未指定接收者类型  
	383  验证码已过期  
	384  验证码不符  
	385  发送间隔时间太短  
	386  发送失败 发送短信失败 
	387  未发送过验证码  
	388  手机格式不正确  
	389  邮箱格式不正确  
	401  该推送消息截止日期需要大于当前时间  
	402  您不是管理员，不能创建推送消息  
	403  您不是创建者，不能修改投票状态  
	404  您不是管理员，不能修改投票状态  
	405  无此推送信息  
	406  您不在投票人员范围内，不能投票  
	407  投票已经截止，不能投票  
	408  您已经投票，不能重复投票  
	409  您不在投票人员范围内，不能查看投票结果  
	410  不符合投票最大允许选择项设置  
	411  不是投票类型的消息，不能投票  
	412  投票项不允许为空  
	413  该投票不允许补充  
	414  您不在任务人员范围内，不能回复  
	415  任务已经截止，不能回复  
	416  任务已经完成/取消，不能回复  
	417  您不在任务人员范围内，不能查看任务结果  
	418  投票已经取消，不能投票  
	419  没有推送对象成员，不能创建推送消息  
	420  没有投票不能查看投票结果  
	421  投票已经完成/取消,不能再投票  
	422  不是任务，不能回复  
	423  该投票信息不允许查看结果  
	450  双方没有任何关系，不能发起聊天  
	451  对方不在线  
	452  消息包含敏感词  
	501  已经注册过  
	502  账号有误  
	503  账号已经存在  
	504  已经注册成功无需验证了  
	505  账号类型有误  
	506  该自定义帐号已经存在 请使用新code:100004511 
	510  已经绑定过了  
	512  已经绑定别的账号了,是否继续绑定  
	513  还不曾绑定过  
	514  账号不存在  
	515  已经申诉了  
	516  已经邀请过好友  
	517  未邀请好友  
	518  已经处理过  
	519  申诉邀请好友辅助失败（一个都没邀请成功,可能不是好友关系或者邀请的人不存在)  
	520  没有申诉记录  
	521  还没到修改密码这一步  
	522  成功凭证不正确不能设置新密码  
	523  好友辅助申诉成功，请即时设置新密码无需再申诉  
	524  邀请的好友已经回复了不能再回复  
	525  不能邀请好友，不在邀请好友这个阶段或者没有申诉记录  
	541  密码操作：用户不存在  
	542  密码操作：新密码不合法  
	543  密码操作：旧密码不正确  
	544  注册用户数已经大于配置的用户数  
	551  未指定用户ID  
	552  未指定错误日志  
	553  未指定客户端类型  
	554  错误描述太长（200）   
	555  错误日志太长（1000）  
	556  操作失败  

	//下面3个延迟消息使用
	560 送达时间不能早于当前时间
	561 该延迟消息不存在
	562 该延迟消息已经发送成功,不能再修改

	//580-600为公安协查使用
	580 缺少标题
	581 缺少内容
	582 缺少发起人
	583 缺少协查人
	584 标题超过长度
	585 内容超过长度
	586 缺少截止日期
	587 截止日期小于当前日期
	588 无此协查信息
	589 不在协查人列表中，不能回复
	590 回复内容为空
	591 回复内容超长
	592 协查已过期，不能回复
	593 回复信息不存在
	594 未指定评论者
	595 评论者ID与发起协查ID不同，不能评价
	596 评论结果为空
	597 评论说明过长
	598 评论项无效
	599 不能对自己的回复进行评论
	600 无权操作

	601	您没有创建此新鲜事
	602	您不是该新鲜事的创建者，不能删除
	603	您没有关注此人，不能获取此人的新鲜事
	604	该条新鲜事禁止评论
	605	您已经设置屏蔽此人的信息
	650:没有此备忘录信息

	701	此评论信息不存在
	702	您不是此评论信息创建人，不能删除
	1101 session丢失,请自动重连
	1102 重试次数太多,需要输入验证码
	1105  登陆太频繁  
	1303  需要修改密码才能登陆  
	1304  系统禁止本次登录  
	1305  账号被冻结  
	1306  账号以停用  
	1307  账号使用非常用登陆设备或者非常用地址登陆  
	1308  账号被锁定 

	//预登录错误码
	2001  预登录未知错误
	2002  请求参数错误
	2003  Mark信息与服务器不一致
	2004  服务器配置为拒绝该设备类型登陆
	2005  提交版本号错误
	2006  GA unauthorized

	//这两个为系统错误
	11100 无法回避的内部错误,服务无法找到
	11101 服务器获取数据异常

	10001:获取access_token时AppSecret错误，或者access_token无效
	10002:不合法的appID
	10003:不合法的获取访问凭证类型
	10004:不合法的access_oken值
	10008:务必注意, 此错误码表示调用接口已经被服务器遗弃 
	11001:缺少应用标识参数
	11002:缺少应用名称参数
	11003:缺少appID参数
	11004:缺少appSecret参数
	11005:缺少access_token参数
	12001:access_token超时
	13001:需要接收者关注
	14001:POST数据包为空
	14002:用户账号参数为空
	14003:消息内容为空
	15001:应用标识超过长度限制
	15002:应用名称超过长度限制
	15003:消息内容超过长度限制
	16001:企业ID不存在
	16002:不存在的用户
	16003:企业应用不存在
	16004:用户不存在企业中
	20001:企业应用服务器未响应
	20002:企业应用服务器验证未通过
	30001:企业应用服务器响应url不存在

	// AG
	// 企业互联使用的错误码
	40001 路由服务端异常
	40002 不允许连接到外企业
	40003 没有外部企业操作权限
	40004 外部企业操作失败
	40005 非法的参数

	100001000  内存申请失败
	100001100  sessionID错误 重连
	100001201 证书标识不存在，请找在该服务器注册该证书。
	100001301 证书标识格式不正确
	100001201 	证书标识查询失败	
	100001301 	证书标识格式不正确	
	100001302 	证书不可用, 无效状态
	100001401 	analysis服务异常	
	100001402 	连接analysis服务超时	
	100001403 	未能连接analysis服务	
	100001411 	buddy服务异常	
	100001412 	连接buddy服务超时	
	100001413 	未能连接buddy服务	
	100001421 	chat服务异常	
	100001422 	连接chat服务超时	
	100001423 	未能连接chat服务	
	100001431 	emoticon服务异常	
	100001432 	连接emoticon服务超时	
	100001433 	未能连接emoticon服务	
	100001441 	EnterpriseDictionary服务异常	
	100001442 	连接EnterpriseDictionary服务超时	
	100001443 	未能连接EnterpriseDictionary服务	
	100001451 	EnterpriseOrganization服务异常	
	100001452 	连接EnterpriseOrganization服务超时	
	100001453 	未能连接EnterpriseOrganization服务	
	100001461 	EnterpriseRegister服务异常	
	100001462 	连接EnterpriseRegister服务超时	
	100001463 	未能连接EnterpriseRegister服务	
	100001471 	EnterpriseShow服务异常	
	100001472 	连接EnterpriseShow服务超时	
	100001473 	未能连接EnterpriseShow服务	
	100001481 	EnterpriseUser服务异常	
	100001482 	连接EnterpriseUser服务超时	
	100001483 	未能连接EnterpriseUser服务	
	100001491 	fullsearch服务异常	
	100001492 	连接fullsearch服务超时	
	100001493 	未能连接fullsearch服务	
	100001501 	groupfile服务异常	
	100001502 	连接groupfile服务超时	
	100001503 	未能连接groupfile服务	
	100001511 	groupmember服务异常	
	100001512 	连接groupmember服务超时	
	100001513 	未能连接groupmember服务	
	100001521 	group服务异常	
	100001522 	连接group服务超时	
	100001523 	未能连接group服务	
	100001531 	GroupVerify服务异常	
	100001532 	连接GroupVerify服务超时	
	100001533 	未能连接GroupVerify服务	
	100001541 	ImageVerify服务异常	
	100001542 	连接ImageVerify服务超时	
	100001543 	未能连接ImageVerify服务	
	100001551 	iosnotice服务异常	
	100001552 	连接iosnotice服务超时	
	100001553 	未能连接iosnotice服务	
	100001561 	lbs服务异常	
	100001562 	连接lbs服务超时	
	100001563 	未能连接lbs服务	
	100001571 	login服务异常	
	100001572 	连接login服务超时	
	100001573 	未能连接login服务
	100001574  mac地址被锁定(登录失败次数过多)
    100001575   手机已更换设备
    100001576   第三方登录认证失败
	100001581 	mdm服务异常	
	100001582 	连接mdm服务超时	
	100001583 	未能连接mdm服务	
	100001591 	message服务异常	
	100001592 	连接message服务超时	
	100001593 	未能连接message服务	
	100001601 	online服务异常	
	100001602 	连接online服务超时	
	100001603 	未能连接online服务	
	100001611 	platform服务异常	
	100001612 	连接platform服务超时	
	100001613 	未能连接platform服务	
	100001621 	recommend服务异常	
	100001622 	连接recommend服务超时	
	100001623 	未能连接reommend服务	
	100001631 	RegisterUser服务异常	
	100001632 	连接RegisterUser服务超时	
	100001633 	未能连接RegisterUser服务	
	100001641 	RouteCenter服务异常	
	100001642 	连接RouteCenter服务超时	
	100001643 	未能连接RouteCenter服务	
	100001651 	setting服务异常	
	100001652 	连接setting服务超时	
	100001653 	未能连接setting服务	
	100001661 	subkey服务异常	
	100001662 	连接subkey服务超时	
	100001663 	未能连接subkey服务	
	100001671 	task服务异常	
	100001672 	连接task服务超时	
	100001673 	未能连接task服务	
	100001681 	TimeStamp服务异常	
	100001682 	连接TimeStamp服务超时	
	100001683 	未能连接TimeStamp服务	
	100001691 	user服务异常	
	100001692 	连接user服务超时	
	100001693 	未能连接user服务	
	100001701 	VerifyBox服务异常	
	100001702 	连接VerifyBox服务超时	
	100001703 	未能连接VerifyBox服务	
	100001711 	VerifyCode服务异常	
	100001712 	连接VerifyCode服务超时	
	100001713 	未能连接VerifyCode服务	
	100001721 	BuddyVerify服务异常	
	100001722 	连接BuddyVerify服务超时	
	100001723 	未能连接BuddyVerify服务

	---------------------预登陆错误 Begin
	100002501  外部访问预登陆接口，预登陆没有该接口
	100002502  客户端传递的必填参数为空
	100002503  客户端为维护状态，不允许登录
	100002504  测试人员禁止登录标准版移动端
	100002505  证书的mac地址与本服务器的mac地址不一致
	100002506  服务器证书有效期已过
	100002507  证书elogo与本服务器连豆豆配置的不一致
	100002508  客户端Mark值为comm.as、AppStore、inte.as
	100002509  客户端传来的信息为空
	100002510  客户端与服务器的客户端升级信息比较版本失败
	100002511  解析post请求传递的客户端信息失败
	100002512  客户单未知请求方式（非post和get请求）
	100002513  未获取到ap信息(检查到apinfo.json配置文件的ap信息的长度是为0)
	100002514  预登陆地址不匹配，需要客户端重新填写  
	---------------------预登陆错误 End

	100004501  豆豆号设置格式错误
	100004502  超过本次导入限制数
	100004503  导入数据库操作失败
	100004504  用户名称为空
	100004505  用户密码格式不正确
	100004506  用户联系方式为空
	100004507  未指定影子用户ID
	100004508  豆豆号已存在
	100004509  邮箱账号已存在
	100004510  手机账号已存在
	100004511  自定义账号已存在
	100012501  无权删除群文件
	100011501  群设置不能主动退出
	100001714  邀请码不存在
	100001715  邀请码已过期
	100001716  邀请码生成失败(服务器原因)
	100001717  此人没有权限生成邀请码
	100001718  使用邀请码者没有在被邀请列表
	100001801  服务器还没实现该接口
	100001802  服务不可用
	100008011  elogo不正确
	100008009  elogo不能为空
	100008010  loginData不能为空
	100008011  elogo不正确
	100008012  qrCodeId不能为空
	100008013  二维码已过期
	100008014  二维码已被其他人使用
	100008015  userId不能为空
	100008016  add New:userid 不匹配
	100008017  confirmLogin不正确
	100008018  用户不存在
	100008019  失败其他错误
	100008020  成功
	100008021  qrCodeIdEv不能为空
	100008022  qrCodeIdEv不正确
	100008027  macCode不能为空
	100008028  macCode不匹配
	100008029  上一次登录时间超过7天
    100022001  收藏接口参数错误
    100022002  收藏用户id不能为空
    100022003  保存收藏文件到云盘失败
    100022004  保存收藏数据失败
    100022005  删除收藏数据失败
    100022006  该收藏信息不存在
    100022007  收藏id不能为空
	100011012	群公告接口失败   
	100011013  群公告接口服务异常  
	100011014	群公告接口非群管理员、群主无权操作
	100011015	群公告校验非群成员   
	100023003  智能客服接口操作失败
	100023010  智能客服接口, 客服与客户同一人不能接入
	100008007  删除登录设备列表失败
};*/
/**
 *  SDK 错误.
 */
enum {
	err_net = -1,
	err_ok = 0,
	err_logined = 113,//已经登录
	err_cookie_Expire = 115, //cookie  过期
	err_lock_verfiyimg = 117,
	err_verfiyimg = 1102,
	err_sessionLost = 1101,
	err_needChgPassWord = 1303,
	err_forbid = 1304, //
	err_noInEnterpriseOrg = 16004,
	err_noIdentityKey = 2001000307,
	err_noSignedKey = 2001000308,
	err_noPreKey = 2001000309,
	err_serverErr = 11100,
	err_removeLocalData = 100008001,           ///服务器返回该code值，客户端清除该账号的所有数据
	err_verifyOk = 100008006,              ///验证信息成功
	err_qrloginok = 100008020,             ///扫描二维码 成功
	err_changedDevice = 100001575,		   	///手机已更换设备
    err_loginThirdAuthFailed = 100001576,       ///第三方登录认证失败
	err_loginForbidden   = 100002503,      ///客户端为维护状态，不允许登录
	//<--------------SDK自定义错误---------------->
	err_sdk_unknownMethod = 100008008,			//未知的方法名，可能是服务器还没上线该功能(此枚举不能为负数)
	err_sdk_start = 0xFF000000,  //-16777216
	err_sdk_openDbFailed,//打开本地数据库失败
	err_sdk_srvUpdate,   //服务器维护中，无法连接，请稍后重新登录。
	err_sdk_cancle,   //被取消执行
	err_sdk_param,    //参数错误
	err_sdk_rcNoexsit,//资源不存在
	err_sdk_dbNoAccess,//数据库不能访问
	err_sdk_dbUpdate, //数据库正在升级
	err_sdk_dbupdateFail,///SDK升级失败
	err_sdk_certInvalidate,///证书校验失败，可能是没有设置证书
	err_sdk_rcOverdue = 0xFF00000A,//-16777206 资源已过期
	err_sdk_tooOften,
	err_sdk_licTypeFail,//证书权限不够  该错误码已废弃
	err_sdk_muchOtherEntMem,  //建立群时，邀请互联人员不能大于1
	err_sdk_transferGroupToOtherEnt,	//不能转让群给互联的人员
	err_sdk_setOtherEntMemToAdmin,		//不能设置互联人员为管理员
	err_setMsgreaded_invalidMsgid = 0xFF000010,//-16777200设置已读消息号大于最大消息ID
	err_sdk_paramInvalidat, ///输入参数有误
	err_sdk_srvCertInvalidat,///服务器证书检验失败

	err_sdk_mustNetLogin, //离线登录失败,必须使用网络登录一次
	err_sdk_olLoginPwInvalidat,//离线密码校验失败,

	err_sdk_noAchieve = 0xFF000015, ///-16777195命令没有实现
	err_sdk_offLineLoginStatus,///离线登录状态，不能执行网络消息

	err_sdk_notHasp2p, ///没有P2P模块
	err_sdk_notp2pUser,///传输对象不是局域网用户，不能传输
	err_sdk_p2pClose,  ///p2p模块关闭
	err_sdk_p2pNotReach = 0xFF00001A,///-16777190 对方不可达
	err_sdk_p2pUnAcessable,///资源无法访问
	err_sdk_p2pTimeOut, /// 传输任务超时
	err_sdk_uploadErr, ///文件上传失败

	err_sdk_dicAlreadyExsit,//当前目录存已经在消息数据
	err_sdk_DBFail,//数据库错误
	err_sdk_noMsgs = 0xFF000020,//-16777184 本地数据库没有消息
	err_sdk_jsonFile,//解析json文件失败
	err_sdk_jsonFileNotExist,//消息文件不存在
	err_sdk_jsonInner,//json解析内部错误
	err_sdk_version,//协议版本错误

	err_sdk_forceUp,  ///需要强制升级
	err_sdk_sendMsgEro,  ///发送消息失败
	err_sdk_avBusy,     ///会议中
	err_sdk_erroCmd, //消息错误
	err_sdk_groupNotExist,   //操作的群不在群列表中
	err_sdk_systemBusy = 0xFF00002A, //-16777174 系统正忙
	err_sdk_alreadyIn, //被邀请的人已经在会议中
	err_sdk_noConference, //本地会议不存在
	err_sdk_tryLater,    //稍后再请求 -16777171
	err_sdk_rtcBusy,         // 已在会议中
	err_sdk_alreadyExec, ///已经执行中
	err_sdk_notOwner = 0xFF000030,///-16777168 不是房主 非法操作
	err_sdk_videoMax,///<视频人数已经最大
	err_sdk_audioMax,///<音频人数已经最大
	err_sdk_getHostFailed,//解析域名失败
	err_sdk_getAgoraPermitFailed,//声网认证失败
	err_sdk_gaSendBack,//核查发送人在后台被加入黑名单
	err_sdk_gaReceiveBack,//核查接收人在后台被加入黑名单
	err_sdk_loginfoErr, ///登录缓存文件失败
	err_sdk_avTimeOut,      //已经超时
	err_sdk_tclBusy,        //正在进行远程控制
	err_sdk_tclDisconnect= 0xFF00003A,  //-16777158 连接已断开
	err_sdk_tclNoIPAddr,    //受控方未发送IP

	///mailPlugin
	err_sdk_unKnownEncode,   //未知编码类型
	err_sdk_emailAddress,    //错误的email地址
	err_sdk_mailAlreadyExsit,  //邮箱已经存在
	err_sdk_AccountNotExsit,  //邮箱不存在
	err_sdk_CURLError= 0xFF000040,         //16777152 curl执行出错
	err_sdk_unKnownTrashFolderName,    //不识别Trash Folder Name

	err_sdk_localSettingError,    //本地设置失败
	err_sdk_avP2PFileFinished = 0xFF000044,     //文件已下载完成
	
	err_sdk_ownerDiscon = 0xFF000045,			//房主已经断开
	err_sdk_orgTacticsChaged = 0xFF000046,	//16777146 策略发生改变，销毁当前组织机构，提示用户从根组织开始重新拉取（代替之前的16005）
    err_sdk_preLoginWait,              //-16777145 预登陆等待其他端口
    err_sdk_codeExpired,            //-16777144 授权码已过期（公安互联）
	err_sdk_filePathDelay,              //文件路径过期
    err_sdk_updateUserPath,             //-16777142 更新用户目录失败(使用新客户端首次登录某个账号)
	err_sdk_allowOfflogin,				//-16777141 不允许离线登录，当前未开启
	err_sdk_checkWhiteListFailed,       //-16777140 调试白名单校验失败
	err_sdk_nospportNewInviteCode,       //-16777139 不支持新格式邀请码
	err_sdk_clearUserData,				///-16777138 已清空用户缓存，请重新登录(重置服务器后，用户再次注册了相同userID的账号)
	err_sdk_compressDataFailed,			///-16777137 压缩用户数据失败
	err_sdk_extractDataFailed,			///-16777136 解压缩用户数据失败
	err_sdk_nginxError,					///-16777135 NGINX服务器错误，请重新登录
	err_sdk_signalError,               ///-16777134 signal相关逻辑出错
	err_sdk_secNoDataThreeEnd,               ///-16777133 端到端解密三端都没有消息
	err_sdk_secNoDataMyPcMobile,               ///-16777132 端到端解密我的PC和我的Mobile没有消息
	err_sdk_secNoDataMyPc,               ///-16777131 端到端解密我的PC没有消息
	err_sdk_secNoDataMyMobile,               ///-16777130 端到端解密我的移动端没有消息
	err_sdk_secNoDataSenderOther,               ///-16777129 端到端解密发送者的另一端没有消息
	err_sdk_secDecryptFailMyPc,               ///-16777128 端到端解密接收者的PC消息失败
	err_sdk_secDecryptFailMyMobile,               ///-16777127 端到端解密接收者的Mobile消息失败
	err_sdk_secDecryptFailSenderOther,               ///-16777126 端到端解密发送者的另一端消息失败
	err_sdk_secOpenFlagConflict,                 ///-16777125 端到端会话开关和总开关冲突
	err_sdk_certOutData,                   ///-16777124 证书过期
	err_sdk_checkMD5Failed,                   ///-16777123 MD5校验失败
	err_sdk_jasonGetPwdErr,					///-16777122 取出加密密码数据失败
	err_sdk_checkJssdkAuth,							///-16777121 jssdk鉴权失败
	err_sdk_checkJssdkAuthOverTime,							///-16777120 jssdk鉴权超时
	err_sdk_getAgencyListCompleteCnt,							///-16777119 待办事项获取已完成和未完成列表数
	err_sdk_setAgencyListRead,							///-16777118 工作台任务设置已读和未读
	err_sdk_getAgencyListScreenItem,							///-16777117 获取本地筛选条件（来源和标签展示）
	err_sdk_disHistoryAgencyListRecords,							///-16777116 展示历史搜索记录
	err_sdk_delHistoryAgencyListRecords,							///-16777115 清空历史搜索记录
	err_sdk_getAppListByMenuCode,								///-16777114 获取栏目应用列表失败
	err_sdk_spareSpaceNotEnough,							///-16777113 剩余空间不足
	err_sdk_not_Certified,					              ///-16777112 反欺诈，未实名认证
	err_sdk_authority_inblacklist,                         ///-16777111 黑名单中的管理员登陆
	err_sdk_getFileExpiry,									///-16777110 获取将过期未下载文件提醒失败
	err_sdk_getFileExpiryResult,									///-16777109 获取将过期未下载文件提醒失败
	err_sdk_fileExpiryInfoStore,									///-16777108 存储将过期未下载文件信息失败
	err_sdk_fileExpiryInfoAsk									///-16777107 获取将过期未下载文件信息失败
};

#endif /* PROTOCOL_ERROREXPORT_H_ */
