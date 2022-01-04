// package org.bytedeco.javacpp.presets;
package vrv.imsdk.api;

import org.bytedeco.javacpp.annotation.Platform;
import org.bytedeco.javacpp.annotation.Properties;
import org.bytedeco.javacpp.tools.Info;
import org.bytedeco.javacpp.tools.InfoMap;
import org.bytedeco.javacpp.tools.InfoMapper;

@Properties(
        value = {
                @Platform(
                        value = {
                                "android"
                                //"windows"
                                //"linux"
                                //"macosx"
                        },
                        //compiler = {"cpp11"},// armeabi 编译
                        compiler = {"cpp11", "fastfpu1"}, // armv7a 编译
                        define = {
                                //"NDEBUG",
                                "UNIQUE_PTR_NAMESPACE std",
                                "SHARED_PTR_NAMESPACE std",
                                "SDK_FOR_ANDROID"
                        },

                        include = {
                                "interface/IAuthService.h",
                                "interface/IRtcService.h",
                                "interface/IChatService.h",
                                "interface/IConfigService.h",
                                "interface/IContactService.h",
                                "interface/IExtService.h",
                                "interface/IFaceToFaceService.h",
                                "interface/IFileService.h",
                                "interface/IGroupService.h",
                                "interface/ISearchService.h",
                                "interface/ISysMsgService.h",
                                "interface/IUserService.h",
                                "interface/IService.h",
                                "interface/IMClient.h",
								"interface/ICloudService.h",
                                "interface/IGaInterService.h",
                                //                                "interface/IMUnkown.h",
                                "interface/jsonToolExport.h",
                                "interface/jsonTransTool.h",
                                "extModel/packet.h",
								"extModel/avpacket.h",
								"extModel/extpacket.h",
								"extModel/gapacket.h",
								"extModel/mailpacket.h",
								"extModel/rtcpacket.h",
								"extModel/mrtcpacket.h",
								"extModel/sopstorepacket.h",
								"extModel/tclpacket.h",
                                "extModel/gaInterpacket.h",
                                //                                "sdkCore/SdkConfig.h",
                                "model/Account.h",
                                "model/Chat.h",
                                "model/Contact.h",
                                "model/Emoticon.h",
                                "model/Group.h",
                                "model/LoginInfo.h",
                                "model/Member.h",
                                "model/Msg.h",
                                "model/Optional.h",
                                "model/Packet.h",
                                "model/SDKTypes.h",
                                "model/SysMsg.h",
                                "model/TinyGroup.h",
                                "model/User.h"
                        },
                        //link = {"service"},//引用库
                        //linkpath = ""),//引用库绝对路径
                        includepath = "/root/git/optimize/apiService/service")//头文件绝对路径
        },
        target = "vrv.imsdk.api.VimService",
        helper = "vrv.imsdk.api.VimCallBack")

public class VimServicePresets implements InfoMapper {
    public void map(InfoMap infoMap) {
        infoMap
                //C Macro
                .put(new Info("_WIN32", "__linux__", "__APPLE__").define(false))
                .put(new Info("SDK_FOR_ANDROID").define(true))
                .put(new Info("(defined SDK_FOR_ANDROID) || (defined OEM_OS_YUANXIN)").define(true))
                .put(new Info("SSharedPtr").skip())
                .put(new Info("SFunction").skip())
				.put(new Info("SNull").skip())
                .put(new Info("_CDECL_", "stdcall").skip())
                .put(new Info("VER_IMCLIENT", "VER_IAUTH", "VER_IChatService", "VER_CONFIG", "VER_CONTACT", "VER_EXT", "VER_FACETOFACE", "VER_FILE", "VER_GROUP", "VRV_IMUNKOWN", "VER_SEARCH", "VER_SYSMSG", "VER_USER", "VER_IRTC","VER_ICLOUD").skip())
                .put(new Info("__attribute__((__cdecl__))", "_CDECL_").skip())
				.put(new Info("SERVICE_EXPORTS").define(true))
                .put(new Info("VRVIID").skip()) //.cppTypes("VRVGUID"))
                //shared_ptr var
                .put(new Info("SSharedPtr<IService>").annotations("@SharedPtr").pointerTypes("IService"))
                .put(new Info("SSharedPtr<IMClient>").annotations("@SharedPtr").pointerTypes("IMClient"))
                .put(new Info("SSharedPtr<Msg>", "SSharedPtr<model::Msg>", "MsgPtr").annotations("@SharedPtr").pointerTypes("Msg"))
                .put(new Info("SSharedPtr<MsgText>", "SSharedPtr<model::MsgText>").annotations("@SharedPtr").pointerTypes("MsgText"))
                .put(new Info("SSharedPtr<MsgImg>", "SSharedPtr<model::MsgImg>").annotations("@SharedPtr").pointerTypes("MsgImg"))
				.put(new Info("SSharedPtr<MsgRedPacket>", "SSharedPtr<model::MsgRedPacket>").annotations("@SharedPtr").pointerTypes("MsgRedPacket"))
                .put(new Info("SSharedPtr<Chat>").annotations("@SharedPtr").pointerTypes("Chat"))
                .put(new Info("SSharedPtr<Contact>").annotations("@SharedPtr").pointerTypes("Contact"))
                .put(new Info("SSharedPtr<TinyGroup>").annotations("@SharedPtr").pointerTypes("TinyGroup"))
                .put(new Info("SSharedPtr<Member>").annotations("@SharedPtr").pointerTypes("Member"))
                .put(new Info("std::vector<EmoticonResult>").pointerTypes("EmoticonResultVector").define())
                .put(new Info("std::vector<int32>").pointerTypes("IntegerVector").define())
				.put(new Info("std::vector<model::YMD>","std::vector<YMD>").pointerTypes("ymdVector").define())
                .put(new Info("std::vector<int16>").pointerTypes("FloatVector").define())
                .put(new Info("std::vector<std::string>").pointerTypes("StringVector").define())
                .put(new Info("std::vector<int64>", "const std::vector<int64>").pointerTypes("LongVector").define())
                .put(new Info("std::vector<SSharedPtr<TinyGroup> >").pointerTypes("TinyGroupSharedVector").define())
                .put(new Info("std::vector<SSharedPtr<Chat> >").pointerTypes("ChatSharedVector").define())
                .put(new Info("std::vector<SSharedPtr<Contact> >").pointerTypes("ContactSharedVector").define())
                .put(new Info("std::vector<SSharedPtr<model::Msg> >", "std::vector<MsgPtr>").pointerTypes("MsgPtrVector").define())
                .put(new Info("std::vector<SSharedPtr<model::MsgText> >").pointerTypes("MsgTextPtrVector").define())
                .put(new Info("std::vector<SSharedPtr<model::MsgImg> >").pointerTypes("MsgImgPtrVector").define())
                .put(new Info("std::vector<model::OrgUserinfo>").pointerTypes("OrgVector").define())
                .put(new Info("std::vector<Contact>").pointerTypes("ContactVector").define())
                .put(new Info("std::vector<st_dbBadWord>").pointerTypes("st_dbBadWordVector").define())
                .put(new Info("std::vector<st_dbBWLib>").pointerTypes("st_dbBWLibVector").define())
                .put(new Info("std::vector<EnterpriseDictionary>").pointerTypes("EntDictVector").define())
                .put(new Info("std::vector<OnlineState>").pointerTypes("OnlineStateVector").define())
                .put(new Info("std::vector<Fileinfo>").pointerTypes("FileInfoVector").define())
                .put(new Info("std::vector<SSharedPtr<Member> >").pointerTypes("MemberSharedVector").define())
				.put(new Info("std::vector<Member>").pointerTypes("MemberVector").define())
                .put(new Info("std::vector<SysMsg>").pointerTypes("SysMsgVector").define())
                .put(new Info("std::vector<room>").pointerTypes("RoomVector").define())
                .put(new Info("std::vector<Task>").pointerTypes("TaskVector").define())
                .put(new Info("std::vector<entpriseInfo>").pointerTypes("EntpriseInfoVector").define())
                .put(new Info("std::vector<BaseNoteInfo>").pointerTypes("BaseNoteInfoVector").define())
                .put(new Info("std::vector<model::Msg>").pointerTypes("MsgVector").define())
                .put(new Info("std::vector<model::MsgImg>","std::vector<MsgImg>").pointerTypes("MsgImgVector").define())
				.put(new Info("std::vector<model::MsgText>","std::vector<MsgText>").pointerTypes("MsgTextVector").define())
				.put(new Info("std::vector<model::MsgWeb>","std::vector<MsgWeb>").pointerTypes("MsgWebVector").define())
				.put(new Info("std::vector<model::MsgAudio>","std::vector<MsgAudio>").pointerTypes("MsgAudioVector").define())
				.put(new Info("std::vector<model::MsgPosition>","std::vector<MsgPosition>").pointerTypes("MsgPositionVector").define())
				.put(new Info("std::vector<model::MsgFile>","std::vector<MsgFile>").pointerTypes("MsgFileVector").define())
				.put(new Info("std::vector<model::MsgCard>","std::vector<MsgCard>").pointerTypes("MsgCardVector").define())
				.put(new Info("std::vector<model::MsgTip>","std::vector<MsgTip>").pointerTypes("MsgTipVector").define())
				.put(new Info("std::vector<model::MsgPicWithText>","std::vector<MsgPicWithText>").pointerTypes("MsgPicWithTextVector").define())
				.put(new Info("std::vector<model::MsgDynExpression>","std::vector<MsgDynExpression>").pointerTypes("MsgDynExpressionVector").define())
				.put(new Info("std::vector<model::MsgVoice>","std::vector<MsgVoice>").pointerTypes("MsgVoiceVector").define())
				.put(new Info("std::vector<model::MsgTask>","std::vector<MsgTask>").pointerTypes("MsgTaskVector").define())
				.put(new Info("std::vector<model::MsgMasterplate>","std::vector<MsgMasterplate>").pointerTypes("MsgMasterplateVector").define())
				.put(new Info("std::vector<model::MsgMiniVedio>","std::vector<MsgMiniVedio>").pointerTypes("MsgMiniVedioVector").define())
				.put(new Info("std::vector<model::MsgDynExpression2>","std::vector<MsgDynExpression2>").pointerTypes("MsgDynExpression2Vector").define())
				.put(new Info("std::vector<model::MsgNineBlock>","std::vector<MsgNineBlock>").pointerTypes("MsgNineBlockVector").define())
				.put(new Info("std::vector<model::MsgAppShare>","std::vector<MsgAppShare>").pointerTypes("MsgAppShareVector").define())
                .put(new Info("std::vector<OrganizationInfo>","std::vector<model::OrganizationInfo>").pointerTypes("OrganizationInfoVector").define())
                .put(new Info("std::vector<OrgSearchUserInfo>","std::vector<model::OrgSearchUserInfo>").pointerTypes("OrgSearchUserInfoVector").define())
                .put(new Info("std::vector<EntpriseUserInfo>").pointerTypes("EntpriseUserInfoVector").define())
                .put(new Info("std::vector<LocalSetting>").pointerTypes("LocalSettingVector").define())
                .put(new Info("std::vector<model::SmallMarketAppInfo>").pointerTypes("SmallMarketAppInfoVector").define())
				.put(new Info("std::vector<model::GroupAppListMenuResult>").pointerTypes("GroupAppListMenuResultVector").define())
				.put(new Info("std::vector<model::UserContact>").pointerTypes("UserContactVector").define())
                .put(new Info("std::vector<model::EmoticonPackage>","std::vector<EmoticonPackage>").pointerTypes("EmoticonPackageVector").define())
                .put(new Info("std::vector<Emoticon>","std::vector<model::Emoticon>").pointerTypes("EmoticonVector").define())
                .put(new Info("std::vector<PersonalData>").pointerTypes("PersonalDataVector").define())
                .put(new Info("std::vector<model::User>","std::vector<User>").pointerTypes("UserVector").define())
                .put(new Info("std::vector<model::TinyGroup>").pointerTypes("TinyGroupVector").define())
                .put(new Info("std::vector<model::EntInfo>").pointerTypes("EntInfoVector").define())
                .put(new Info("std::vector<model::OrGroupinfo>").pointerTypes("OrGroupinfoVector").define())
                .put(new Info("std::vector<model::EntAppinfo>").pointerTypes("EntAppinfoVector").define())
				.put(new Info("std::vector<model::LocalSearchMemberInfo>","std::vector<LocalSearchMemberInfo>").pointerTypes("LocalSearchMemberInfoVector").define())
                .put(new Info("std::vector<LoginInfo>").pointerTypes("LoginInfoVector").define())
                .put(new Info("std::vector<model::picTextBean>").pointerTypes("PicTextBeanVector").define())
                .put(new Info("std::vector<model::MsgSearchResult::info>").pointerTypes("InfoVector").define())
                .put(new Info("model::MsgSearchResult::info").pointerTypes("MsgSearchResult.info"))
                .put(new Info("std::vector<p2pUser>", "std::vector<model::p2pUser>").pointerTypes("P2pUserVector").define())
                .put(new Info("std::vector<OrgUserinfo>").pointerTypes("OrgUserinfoVector").define())
                .put(new Info("std::vector<OfflineMsg>").pointerTypes("OfflineMsgVector").define())
                .put(new Info("std::vector<PhoneBookContact>").pointerTypes("PhoneBookContactVector").define())
                .put(new Info("std::vector<RecommendContact>").pointerTypes("RecommendContactVector").define())
                .put(new Info("std::vector<SubServerInfo>").pointerTypes("SubServerInfoVector").define())
                .put(new Info("std::vector<service::jst_picTextBean>").pointerTypes("JstPicTextBeanVector").define())
                .put(new Info("std::vector<ImgMsgInner>","std::vector<model::ImgMsgInner>").pointerTypes("ImgMsgInnerVector").define())
                .put(new Info("std::vector<singleEmoticon>","std::vector<model::singleEmoticon>").pointerTypes("SingleEmoticonVector").define())
				.put(new Info("std::vector<localPhoneBook>","std::vector<model::localPhoneBook>").pointerTypes("localPhoneBookVector").define())
				.put(new Info("std::vector<stupdateInfo>","std::vector<model::stupdateInfo>").pointerTypes("stupdateInfoVector").define())
				.put(new Info("std::vector<smallMarketAppType>","std::vector<model::smallMarketAppType>").pointerTypes("marketAppVector").define())
				.put(new Info("std::vector<queryTag>","std::vector<model::queryTag>").pointerTypes("queryVector").define())
				.put(new Info("std::vector<AccountType>","std::vector<model::AccountType>").pointerTypes("acctTypeVector").define())
				.put(new Info("std::vector<CloudFileInfo>","std::vector<model::CloudFileInfo>").pointerTypes("CloudFileVector").define())
				.put(new Info("std::vector<TeamMemberInfo>","std::vector<model::TeamMemberInfo>").pointerTypes("TeamMemberInfoVector").define())
				.put(new Info("std::vector<CloudRoleInfo>","std::vector<model::CloudRoleInfo>").pointerTypes("CloudRoleInfoVector").define())
                .put(new Info("std::vector<AppNodeInfo>","std::vector<model::AppNodeInfo>").pointerTypes("AppNodeInfoVector").define())
                .put(new Info("std::vector<WorkbenchBanner>","std::vector<model::WorkbenchBanner>").pointerTypes("WorkbenchBannerVector").define())
                .put(new Info("std::vector<HelpSystemInfo>","std::vector<model::HelpSystemInfo>").pointerTypes("HelpSystemInfoVector").define())
                .put(new Info("std::vector<SnapshotInfo>","std::vector<model::SnapshotInfo>").pointerTypes("SnapshotInfoVector").define())
                .put(new Info("std::vector<MsgUnreadCounter>","std::vector<model::MsgUnreadCounter>").pointerTypes("MsgUnreadCounterVector").define())
				.put(new Info("std::vector<p2pServerInfo>").pointerTypes("P2pServerInfoVector").define())
				.put(new Info("std::vector<AppOrderInfo>").pointerTypes("AppOrderVector").define())
				.put(new Info("std::vector<MarketAppGroup>").pointerTypes("MarketAppGroupVector").define())
				.put(new Info("std::vector<GroupIssue>").pointerTypes("GroupIssueVector").define())
				.put(new Info("std::vector<GroupAnnouncementInfo>").pointerTypes("GroupAnnouncementInfoVector").define())
				.put(new Info("std::vector<LocalAppInfo>").pointerTypes("LocalAppInfoVector").define())
				.put(new Info("std::vector<Notebook>").pointerTypes("NotebookVector").define())
				.put(new Info("std::vector<NoteEntry>").pointerTypes("NoteEntryVector").define())
				.put(new Info("std::vector<CustomerPoolBean>").pointerTypes("CustomerPoolBeanVector").define())
				.put(new Info("std::vector<CustomChat>").pointerTypes("CustomChatVector").define())
				.put(new Info("std::vector<CustomAppInfo>").pointerTypes("CustomAppInfoVector").define())
				.put(new Info("std::vector<globalNoDisturbModeInfo>").pointerTypes("globalNoDisturbModeInfoVector").define())
				.put(new Info("std::vector<DeviceLoginRecord>").pointerTypes("DeviceLoginRecordVector").define())
				.put(new Info("std::vector<reminderMsg>").pointerTypes("reminderMsgVector").define())
				.put(new Info("std::vector<agencymsg>").pointerTypes("agencymsgVector").define())
				.put(new Info("std::vector<LoginClientRecord>").pointerTypes("LoginClientRecordVector").define())
				.put(new Info("std::vector<SmallAppHelp>").pointerTypes("SmallAppHelpVector").define())
				.put(new Info("std::vector<strc_UserToAppConfig>").pointerTypes("strc_UserToAppConfigVector").define())
				.put(new Info("std::vector<PersonalDataSwitch>").pointerTypes("PersonalDataSwitchVector").define())
				.put(new Info("std::vector<ClientMenuSet>").pointerTypes("ClientMenuSetVector").define())
				.put(new Info("std::vector<Security>").pointerTypes("SecurityVector").define())
				.put(new Info("std::vector<OutEntNodeInfo>").pointerTypes("OutEntNodeInfoVector").define())
				.put(new Info("std::vector<ElevatorAuthority>","std::vector<model::ElevatorAuthority>").pointerTypes("ElevatorAuthorityVector").define())
                .put(new Info("std::vector<ToDoTaskMsg>").pointerTypes("ToDoTaskMsgVector").define())
				.put(new Info("std::vector<MarketAppInfo>").pointerTypes("MarketAppInfoVector").define())
				.put(new Info("std::vector<GroupDocAttribute>").pointerTypes("GroupDocAttributeVector").define())
				.put(new Info("std::vector<GroupDocUpdownInfo>").pointerTypes("GroupDocUpdownInfoVector").define())
                //map transform
                .put(new Info("std::map<int64,model::SimpleSearchInfo>").pointerTypes("LongSearchMap").define())
                .put(new Info("std::map<std::string,std::string>").pointerTypes("MapStr2").define())
                .put(new Info("std::map<std::string,std::vector<model::OrgUserinfo> >").pointerTypes("StrVectorMap").define())
                .put(new Info("std::map<std::string,std::vector<EntpriseUserInfo> >").pointerTypes("StrEntpriseUserInfoVectorMap").define())
                .put(new Info("std::map<int64,std::vector<PersonalDataSwitch> >").pointerTypes("LongPersonalDataSwitchVectorMap").define())
                .put(new Info("std::map<int64,Fileinfo>").pointerTypes("LongFileInfoMap").define())
                .put(new Info("std::map<std::string,std::vector<OrgUserinfo> >").pointerTypes("StrOrgVectorMap").define())
                .put(new Info("std::map<std::string,int64>").pointerTypes("StrLongMap").define())
                .put(new Info("std::map<int64,std::string>").pointerTypes("LongStrMap").define())
                .put(new Info("std::map<int64,int>").pointerTypes("LongIntMap").define())
				.put(new Info("std::map<std::string,std::vector<int64> >").pointerTypes("StrLongVectorMap").define())
                .put(new Info("std::map<std::string,int>","std::map<std::string,int32>").pointerTypes("StringIntMap").define())
				.put(new Info("std::map<int64,std::vector<LoginClientRecord> >").pointerTypes("LongLoginClientRecordVectorMap").define())
				.put(new Info("std::map<int64,std::vector<int64> >").pointerTypes("LongVectorLongMap").define())
				//map map
                .put(new Info("std::map<int64,model::SmallMarketAppInfo>").pointerTypes("LongSmallMarketAppInfoMap").define())
                .put(new Info("std::map<int8,std::map<int64,model::SmallMarketAppInfo> >").pointerTypes("ByteLongSmallMarketAppInfoMapMap").define())

                //基本类型转换
                .put(new Info("int8", "int8_t", "uint8", "uint8_t", "__int8", "signed char", "char", "unsigned char").cast().valueTypes("byte").pointerTypes("BytePointer"))
                .put(new Info("int16", "int16_t", "uint16", "uint16_t", "__int16", "jshort", "short", "signed short", "short int", "signed short int", "int32", "int32_t", "__int32", "jint", "int", "signed int", "signed", "uint32", "uint32_t").cast().valueTypes("int").pointerTypes("IntPointer"))
                .put(new Info("int64", "uint64", "int64_t", "__int64", "uint64_t", "unsigned __int64", "unsigned long long", "long long", "unsigned long long int").cast().valueTypes("long").pointerTypes("LongPointer"))
                .put(new Info("std::string", "const std::string&").annotations("@StdString ").valueTypes("String"))
                //                .put(new Info("std::string").annotations("@StdString").valueTypes("String").pointerTypes("@Cast({\"char*\", \"std::string*\"}) BytePointer"))
                .put(new Info("LogLevel").cast().valueTypes("int").pointerTypes("LogLevel"))
                .put(new Info("SysOperType").cast().valueTypes("int").pointerTypes("SysOperType"))
                //Optional参数
                .put(new Info("model::Optional<int>").pointerTypes("OptionalInt").define())
                .put(new Info("model::Optional<int8>").pointerTypes("OptionalByte").define())
                .put(new Info("model::Optional<int16>").pointerTypes("OptionalShort").define())
                .put(new Info("model::Optional<int32>").pointerTypes("OptionalInt").define())
                .put(new Info("model::Optional<int64>").pointerTypes("OptionalLong").define())
                .put(new Info("model::Optional<std::string>").pointerTypes("OptionalString").define())
                .put(new Info("model::Optional<std::vector<std::string> >").pointerTypes("OptionalStringVector").define())
                .put(new Info("model::Optional<bool>").pointerTypes("OptionalBool").define())
                .put(new Info("model::Optional<TinyGroup>").pointerTypes("OptionalGroup").define())
                .put(new Info("model::Optional<std::vector<int64> >").pointerTypes("OptionaVectorInt64").define())
                .put(new Info("model::Optional<std::vector<AccountType> >","model::Optional<std::vector<model::AccountType> >").pointerTypes("OptionaAccountTypeVector").define())
                .put(new Info("model::Optional<std::vector<OrganizationInfo> >","model::Optional<std::vector<model::OrganizationInfo> >").pointerTypes("OptionaOrganizationInfoVector").define())

                //std function
                .put(new Info("SFunction<void(int8,const Group&)>").pointerTypes("FnCbByteGroup"))
                .put(new Info("SFunction<void(int)>").pointerTypes("FnCbInt"))
                .put(new Info("SFunction<void(int,int64)>").pointerTypes("FnCbIntLong"))
                .put(new Info("SFunction<void(int,const Contact&)>").pointerTypes("FnCbIntContact"))
                .put(new Info("SFunction<void(int,std::vector<SSharedPtr<Chat>>&)>").pointerTypes("FnCbIntChatVector"))
                .put(new Info("SFunction<void(int,int64,std::vector<SSharedPtr<Member>>&)>").pointerTypes("FnCbIntLongMemberVector"))
                .put(new Info("SFunction<void(int,std::vector<Contact>&)>").pointerTypes("FnCbIntContactVector"))
                .put(new Info("SFunction<void(int64)>").pointerTypes("FnCbLong"))
                .put(new Info("SFunction<void(int64,const std::string&)>").pointerTypes("FnCbLongStr"))
                .put(new Info("SFunction<void(int64,const std::string&,int64,const std::string&)>").pointerTypes("FnCbLongStrLongStr"))
                .put(new Info("SFunction<void(int64,const Member&)>").pointerTypes("FnCbLongMember"))
                .put(new Info("SFunction<void(UpgradeInfo&)>").pointerTypes("FnCbUpgradeInfo"))
                .put(new Info("SFunction<void(const std::string&)>").pointerTypes("FnCbScanQrInfo"))
                .put(new Info("SFunction<void(SSharedPtr<Msg>)>").pointerTypes("FnCbMsg"))
                .put(new Info("SFunction<void(Account&)>", "SFunction<void(const Account&)>").pointerTypes("FnCbAccount"))
                .put(new Info("SFunction<void(const OnlineState&)>").pointerTypes("FnCbOnlineState"))
                .put(new Info("SFunction<void(const SysMsg&)>").pointerTypes("FnCbSystem"))
                .put(new Info("SFunction<void(const SysMsg&,int)>").pointerTypes("FnCbSysInt"))
                .put(new Info("SFunction<void(const std::string&,User&)>").pointerTypes("FnCbStrUser"))
                .put(new Info("SFunction<void(const std::string&,int64,int8)>").pointerTypes("FnCbStrLongByte"))
                .put(new Info("SFunction<void(std::vector<SSharedPtr<TinyGroup>>&)>").pointerTypes("FnCbGroupVector"))
                .put(new Info("SFunction<void(std::vector<OfflineMsg>&)>").pointerTypes("FnCbOfflineMsgVector"))
                .put(new Info("SFunction<void(int64,int8,int8)>").pointerTypes("FnCbLongByte2"))
                .put(new Info("SFunction<void(P2pSendFileReq&)>").pointerTypes("FnCbP2pSendFileReq"))
                .put(new Info("SFunction<void(int8,int64)>").pointerTypes("FnCbByteLong"))
                .put(new Info("SFunction<void(model::channelEvent&)>").pointerTypes("FnCbChannelEvt"))
				.put(new Info("SFunction<void(model::multiRtcEvent&)>").pointerTypes("FnCbMultiRtcEvent"))
				.put(new Info("SFunction<void(int32,const std::string&)>").pointerTypes("FnCbIntStr"))
				.put(new Info("SFunction<void(int8,std::string&,std::string&)>").pointerTypes("FnCbByteStrStr"))
                //含错误返回
                .put(new Info("SFunction<void(ErrorInfo,std::vector<p2pUser>&)>").pointerTypes("FnCbErrP2pUserVector"))
                //.put(new Info("SFunction<void(ErrorInfo,std::vector<p2pUser>&>").pointerTypes("FnCbErrP2pUserVector"))
                .put(new Info("SFunction<void(ErrorInfo)>").pointerTypes("FnCbError").define())
                .put(new Info("SFunction<void(ErrorInfo,int8)>").pointerTypes("FnCbErrByte").define())
                .put(new Info("SFunction<void(ErrorInfo,std::vector<WorkbenchBanner>&)>").pointerTypes("FnCbErrWorkbenchBannerVector"))
                .put(new Info("SFunction<void(ErrorInfo,int64,int64)>").pointerTypes("FnCbErr2Long"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<int64>&,std::vector<int64>&)>").pointerTypes("FnCbErr2LongVector"))
                .put(new Info("SFunction<void(ErrorInfo,int64,std::vector<MsgPtr>&)>").pointerTypes("FnCbErrLongMsgPtrVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<MsgPtr>&)>").pointerTypes("FnCbErrMsgPtrVector"))
                .put(new Info("SFunction<void(ErrorInfo,const std::string&,const std::string&,const std::string&,const std::string&)>").pointerTypes("FnCbErr4Str"))
                .put(new Info("SFunction<void(ErrorInfo,int)>", "SFunction<void(ErrorInfo,int32)>").pointerTypes("FnCbErrInt"))
                .put(new Info("SFunction<void(ErrorInfo,int64)>").pointerTypes("FnCbErrLong"))
                .put(new Info("SFunction<void(ErrorInfo,const std::string&)>", "SFunction<void(ErrorInfo,std::string&)>").pointerTypes("FnCbErrStr"))
                .put(new Info("SFunction<void(ErrorInfo,int32,int64)>").pointerTypes("FnCbErrIntLong"))
                .put(new Info("SFunction<void(ErrorInfo,int32,std::vector<std::string>&)>").pointerTypes("FnCbErrIntStringVector"))
                .put(new Info("SFunction<void(ErrorInfo,ContactVerifyType&)>").pointerTypes("FnCbErrVerify"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<OnlineState>&)>").pointerTypes("FnCbErrOnlineStateVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<int64>&)>").pointerTypes("FnCbErrLongVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<EnterpriseDictionary>&)>").pointerTypes("FnCbErrEnterpriseVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<Task>&)>").pointerTypes("FnCbErrTaskVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<room>&)>").pointerTypes("FnCbErrRoomVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<entpriseInfo>&)>").pointerTypes("FnCbErrEntVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<OrganizationInfo>&,std::vector<EntpriseUserInfo>&)>").pointerTypes("FnCbErrOrgVectorEntVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<OrganizationInfo>&)>").pointerTypes("FnCbErrOrgVector"))
                .put(new Info("SFunction<void(ErrorInfo,int64,int64,std::map<std::string,std::vector<EntpriseUserInfo>>&)>").pointerTypes("FnCbErr2LongEntMap"))
                .put(new Info("SFunction<void(ErrorInfo,std::map<int64,std::vector<PersonalDataSwitch>>&)>").pointerTypes("FnCbErrPersonalMap"))
                .put(new Info("SFunction<void(ErrorInfo,const std::string&,std::vector<ClientMenuSet>&)>").pointerTypes("FnCbErrStrClientVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<EntpriseUserInfo>&)>").pointerTypes("FnCbErrEntUserVector"))
                .put(new Info("SFunction<void(ErrorInfo,OrganizationInfo&)>").pointerTypes("FnCbErrOrg"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<int64>&,std::vector<int>&)>").pointerTypes("FnCbErrLongVectorIntVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<BaseNoteInfo>&)>").pointerTypes("FnCbErrNoteVector"))
                .put(new Info("SFunction<void(ErrorInfo,const std::string&,const std::string&)>", "SFunction<void(ErrorInfo,std::string&,std::string&)>").pointerTypes("FnCbErr2Str"))
				.put(new Info("SFunction<void(ErrorInfo,int,std::string&,std::string&)>").pointerTypes("FnCbErrintStrStr"))
                .put(new Info("SFunction<void(ErrorInfo,int64,const std::string&)>").pointerTypes("FnCbErrLongStr"))
				.put(new Info("SFunction<void(ErrorInfo,int64,int64,const std::string&)>").pointerTypes("FnCbErrLongLongStr"))
				.put(new Info("SFunction<void(ErrorInfo,int64,int64,const std::string&,int8)>").pointerTypes("FnCbErrLongLongStrByte"))
				//群文档
				.put(new Info("SFunction<void(ErrorInfo,const std::string&,int64,int64,int32)>").pointerTypes("FnCbErrStrLongLongInt"))
				.put(new Info("SFunction<void(ErrorInfo,const std::string&,int64,int64,int64,int8)>").pointerTypes("FnCbErrStr3LongByte"))
				.put(new Info("SFunction<void(ErrorInfo,const std::string&,int64,int64,int32,std::vector<GroupDocAttribute>&)>").pointerTypes("FnCbErrStrLongLongIntGroupDocAttribute"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<GroupDocAttribute>&)>").pointerTypes("FnCbErrGroupDocAttributeVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<GroupDocUpdownInfo>&)>").pointerTypes("FnCbErrGroupDocUpdownInfoVector"))
				
                .put(new Info("SFunction<void(ErrorInfo,std::vector<Fileinfo>&)>").pointerTypes("FnCbErrFileVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::map<int64,Fileinfo>&)>").pointerTypes("FnCbErrFileMap"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<SSharedPtr<Member>>&)>").pointerTypes("FnCbErrMemberVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<Member>&)>").pointerTypes("FnCbErrMemberVectors"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<SSharedPtr<Member>>&,std::vector<SSharedPtr<Member>>&,std::map<int64,std::vector<int64>>&)>").pointerTypes("FnCbErr3MemberMap"))
				.put(new Info("SFunction<void(ErrorInfo,int8,int8)>").pointerTypes("FnCbErr2Byte"))
				.put(new Info("SFunction<void(ErrorInfo,int8,int8,int8,int8)>").pointerTypes("FnCbErr4Byte"))
                .put(new Info("SFunction<void(ErrorInfo,SearchResult&)>").pointerTypes("FnCbErrSearch"))
                .put(new Info("SFunction<void(ErrorInfo,User&)>").pointerTypes("FnCbErrUser"))
                .put(new Info("SFunction<void(ErrorInfo,Contact&)>").pointerTypes("FnCbErrContact"))
                .put(new Info("SFunction<void(ErrorInfo,MsgSearchResult&)>").pointerTypes("FnCbErrMsgSearch"))
                .put(new Info("SFunction<void(ErrorInfo,MsgDetailSearchResult&)>").pointerTypes("FnCbErrMsgDetail"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<SysMsg>&)>").pointerTypes("FnCbErrSysVector"))
                .put(new Info("SFunction<void(ErrorInfo,UserSetting&)>").pointerTypes("FnCbErrUserSetting"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<int64>&,bool)>").pointerTypes("FnCbErrLongVectorBoolean"))
                .put(new Info("SFunction<void(ErrorInfo,int32,int32,bool)>").pointerTypes("FnCbErr2IntBoolean"))
                .put(new Info("SFunction<void(ErrorInfo,int64,int8)>").pointerTypes("FnCbErrLongByte"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<LocalSetting>&)>").pointerTypes("FnCbErrLocalVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<PersonalData>)>", "SFunction<void(ErrorInfo,std::vector<PersonalData>&)>").pointerTypes("FnCbErrDataVector"))
                .put(new Info("SFunction<void(ErrorInfo,EntAppinfo&)>").pointerTypes("FnCbErrEntApp"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<Msg>&)>").pointerTypes("FnCbErrMsgVector"))
                .put(new Info("SFunction<void(ErrorInfo,SmallMarketAppPage&)>").pointerTypes("FnCbErrAppPage"))
				.put(new Info("SFunction<void(ErrorInfo,AppListMenuInfo&)>").pointerTypes("FnCbErrAppListMenu"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<SmallMarketAppInfo>&)>").pointerTypes("FnCbErrAppVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<GroupAppListMenuResult>&)>").pointerTypes("FnCbErrAppMenuVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<EmoticonPackage>&)>").pointerTypes("FnCbErrEmoPackVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<Emoticon>&)>").pointerTypes("FnCbErrEmoVector"))
                .put(new Info("SFunction<void(ErrorInfo,EmoticonPackage&)>").pointerTypes("FnCbErrEmoPack"))
                .put(new Info("SFunction<void(ErrorInfo,PageQueryEmoticon&)>").pointerTypes("FnCbErrPageQueryEmo"))
                .put(new Info("SFunction<void(ErrorInfo,int32,std::vector<EmoticonResult>&,std::vector<EmoticonResult>&)>").pointerTypes("FnCbErrInt2Vector"))
                .put(new Info("SFunction<void(ErrorInfo,const std::string&,int64)>").pointerTypes("FnCbErrStrLong"))
                .put(new Info("SFunction<void(ErrorInfo,int64,const std::string&,const std::string&)>").pointerTypes("FnCbErrLong2Str"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<RecommendContact>&)>").pointerTypes("FnCbErrrecommendVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<User>&)>").pointerTypes("FnCbErrUserVector"))
                .put(new Info("SFunction<void(ErrorInfo,Group&)>").pointerTypes("FnCbErrGroup"))
                .put(new Info("SFunction<void(ErrorInfo,int64,const std::string&,int8,int8)>").pointerTypes("FnCbErrLongStr2Byte"))
                .put(new Info("SFunction<void(int64,int64,int64)>").pointerTypes("FnCb3Long"))
				.put(new Info("SFunction<void(int64,int64,int8)>").pointerTypes("FnCb2LongByte"))
                //.put(new Info("SFunction<void(model::AVEvent)>").pointerTypes("FnCbAVEvent"))
                .put(new Info("SFunction<void(ErrorInfo,int8,int8,std::vector<OrganizationInfo>&,std::vector<EntpriseUserInfo>&)>").pointerTypes("FnCbErr2Byte2EntVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::map<std::string,int64>&)>").pointerTypes("FnCbErrStrLongMap"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<MsgPtr>&,std::vector<model::Task>&)>").pointerTypes("FnCbErrMsgPtrVectorTaskVector"))
                .put(new Info("SFunction<void(ErrorInfo,Emoticon&)>").pointerTypes("FnCbErrEmoticon"))
                .put(new Info("SFunction<void(ErrorInfo,getConfer&)>").pointerTypes("FnCbErrGetConfer"))
				.put(new Info("SFunction<void(ErrorInfo,p2pServerInfo&)>").pointerTypes("FnCbErrGetAVServer"))
                .put(new Info("SFunction<void(ErrorInfo,singleEmoticonResult&)>").pointerTypes("FnCbErrSgEmoticonResult"))
				.put(new Info("SFunction<void(ErrorInfo,int64,int64,BadWord&)>").pointerTypes("FnCbErrLongLongBadWord"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<model::YMD>&,std::vector<int32>&)>").pointerTypes("FnCbErrYMDIntVector"))
				.put(new Info("SFunction<void(int64,int32,int32)>").pointerTypes("FnCbLongIntIntResult"))
				.put(new Info("SFunction<void(int64,int32,int32,const std::string&)>").pointerTypes("FnCbLongIntIntStr"))
				.put(new Info("SFunction<void(ErrorInfo,int64,int64,std::vector<model::EntAppinfo>&)>").pointerTypes("FnCbLongLongEntAppInfo"))
				.put(new Info("SFunction<void(ErrorInfo,std::map<int64,std::string>&)>").pointerTypes("FnCbLongStringMap"))				
				.put(new Info("SFunction<void(ErrorInfo,std::map<std::string,std::vector<int64>>&)>").pointerTypes("FnCbStringLongVectorMap"))
				.put(new Info("SFunction<void(ErrorInfo,AuthUserBean&)>").pointerTypes("FnCbErrAuthUserBean"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<smallMarketAppType>&)>").pointerTypes("FnCbErrVectorAPPType"))
				.put(new Info("SFunction<void(ErrorInfo,CloudFileInfo&)>").pointerTypes("FnCbErrCloudFileInfo"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<CloudFileInfo>&)>").pointerTypes("FnCbErrVectorCloudFileInfo"))
				//.put(new Info("SFunction<void(ErrorInfo,CloudTeamInfo&)>").pointerTypes("FnCbErrCloudTeamInfo"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<TeamMemberInfo>&)>").pointerTypes("FnCbErrTeamMemberInfoVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<CloudRoleInfo>&)>").pointerTypes("FnCbErrCloudRoleInfoVector"))
				.put(new Info("SFunction<void(ErrorInfo,CloudRoleInfo&)>").pointerTypes("FnCbErrCloudRoleInfo"))
				.put(new Info("SFunction<void(ErrorInfo,CloudPermission&)>").pointerTypes("FnCbErrCloudPermission"))
				.put(new Info("SFunction<void(ErrorInfo,int64,BadWord&)>").pointerTypes("FnCbErroneLongBadWord"))
				.put(new Info("SFunction<void(ErrorInfo,std::map<std::string,std::string>&)>").pointerTypes("FnCbErrMapStrStr"))
				.put(new Info("SFunction<void(ErrorInfo,int,std::map<std::string,int64>&)>").pointerTypes("FnCbErrIntStrLongMap"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<AppNodeInfo>&)>").pointerTypes("FnCbErrAppNodeInfoVector"))
                .put(new Info("SFunction<void(ErrorInfo,int64,std::vector<OrganizationInfo>&,std::vector<OrgSearchUserInfo>&)>").pointerTypes("FnCbLongOrgInfoVectorOrgUserVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<HelpSystemInfo>&)>").pointerTypes("FnCbErrHelpSysInfoVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<MsgUnreadCounter>&)>").pointerTypes("FnCbErrMsgUnreadCountVector"))
                .put(new Info("SFunction<void(ErrorInfo,OnlineState&)>").pointerTypes("FnCbErrOnlineState"))
				.put(new Info("SFunction<void(ErrorInfo,OAuthResult&)>").pointerTypes("FnCbErrOAuth"))
				.put(new Info("SFunction<void(ErrorInfo,AdminRoleInfo&)>").pointerTypes("FnCbErrAdminRoleInfo"))
				.put(new Info("SFunction<void(ErrorInfo,CloudUserInfo&)>").pointerTypes("FnCbErrCloudUser"))
				.put(new Info("SFunction<void(ErrorInfo,bool,std::vector<MarketAppGroup>&)>").pointerTypes("FnCbErrBoolMarketAppGroupVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<GroupIssue>&)>").pointerTypes("FnCbErrGroupIssueVector"))
				.put(new Info("SFunction<void(ErrorInfo,GroupIssue&)>").pointerTypes("FnCbErrGroupIssue"))
				.put(new Info("SFunction<void(ErrorInfo,GroupAnnouncementList&)>").pointerTypes("FnCbErrGroupAnnouncementList"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<LocalAppInfo>&)>").pointerTypes("FnCbErrLocalAppInfoVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<Notebook>&)>").pointerTypes("FnCbErrNotebookVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<NoteEntry>&)>").pointerTypes("FnCbErrNoteEntryVector"))
                .put(new Info("SFunction<void(ErrorInfo,bool)>").pointerTypes("FnCbErrBool").define())
				.put(new Info("SFunction<void(ErrorInfo,std::vector<CustomerPoolBean>&)>").pointerTypes("FnCbErrCustomerPoolVector"))
				.put(new Info("SFunction<void(ErrorInfo,SSharedPtr<Msg>)>").pointerTypes("FnCbErrCustomerLastMsg"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<CustomAppInfo>&)>").pointerTypes("FnCbErrCustomAppInfoVector"))
				.put(new Info("SFunction<void(ErrorInfo,int64,int64,std::vector<MsgPtr>&)>").pointerTypes("FnCbErrLongLongMsgPtrVector"))
				.put(new Info("SFunction<void(ErrorInfo,AppCustomerInfo&)>").pointerTypes("FnCbErrAppCustomerInfo"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<CustomChat>&)>").pointerTypes("FnCbErrCustomChatVector"))
				.put(new Info("SFunction<void(int,std::vector<CustomChat>&)>").pointerTypes("FnCbIntCustomChatVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<globalNoDisturbModeInfo>&)>").pointerTypes("FnCbErrglobalNoDisturbModeInfoVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<DeviceLoginRecord>&)>").pointerTypes("FnCbErrDeviceLoginRecordVector"))
				.put(new Info("SFunction<void(ErrorInfo,int64,int64,std::vector<reminderMsg>&)>").pointerTypes("FnCbErrLongLongreminderMsgVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<OutEntNodeInfo>&)>").pointerTypes("FnCbErrGetNodeInfoVector"))

                //std function 可为空回调
                .put(new Info("SFunction<void(int32,int32,const std::string&)>").pointerTypes("FnCb2IntStr"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<agencymsg>&)>").pointerTypes("FnCbErragencymsgVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::map<int64,std::vector<LoginClientRecord>>&)>").pointerTypes("FnCbErrLongLoginClientRecordVectorMap"))
                .put(new Info("SFunction<void(GroupInfoOrSettingInfo&)>").pointerTypes("FnCbGroupInfoOrSettingInfo"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<Contact>&,std::vector<Contact>&,std::vector<Contact>&,std::vector<Contact>&)>").pointerTypes("FnCbErr4ContactVector"))
				.put(new Info("SFunction<void(ErrorInfo,int64,std::vector<Contact>&,std::vector<Contact>&,std::vector<Contact>&,std::vector<Contact>&)>").pointerTypes("FnCbErrLong4ContactVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<SmallAppHelp>&)>").pointerTypes("FnCbErrSmallAppHelpVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<strc_UserToAppConfig>&)>").pointerTypes("FnCbErrstrc_UserToAppConfigVector"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<Security>&)>").pointerTypes("FnCbErrSecurityVector"))
                .put(new Info("SFunction<void(ErrorInfo,int64,int64,int64,int64,std::vector<ElevatorAuthority>&)>").pointerTypes("FnCbErr4LongElevatorAuthorityVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<ElevatorAuthority>&)>").pointerTypes("FnCbErrElevatorAuthorityVector"))
				.put(new Info("SFunction<void(ErrorInfo,agencyTaskMsg&)>").pointerTypes("FnCbErragencyTaskMsg"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<ToDoTaskMsg>&)>").pointerTypes("FnCbErrToDoTaskMsgVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<int64>&,std::vector<std::string>&)>").pointerTypes("FnCbErrLongVectorStrVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<std::string>&)>").pointerTypes("FnCbErrStrVector"))
                .put(new Info("SFunction<void(int,BifactorSt&)>").pointerTypes("FnCbIntBifactorSt"))
				.put(new Info("SFunction<void(ErrorInfo,std::vector<MarketAppInfo>&)>").pointerTypes("FnCbErrMarketAppInfoVector"))
                .put(new Info("SFunction<void(ErrorInfo,std::vector<std::string>&,std::vector<std::string>&)>").pointerTypes("FnCbErr2StrVector"))
        ;
    }
}
