package vrv.imsdk.api;


import org.bytedeco.javacpp.FunctionPointer;
import org.bytedeco.javacpp.Loader;
import org.bytedeco.javacpp.Pointer;
import org.bytedeco.javacpp.annotation.ByRef;
import org.bytedeco.javacpp.annotation.ByVal;
import org.bytedeco.javacpp.annotation.Cast;
import org.bytedeco.javacpp.annotation.Const;
import org.bytedeco.javacpp.annotation.SharedPtr;
import org.bytedeco.javacpp.annotation.StdString;


/**
 * Created by Yang on 2016/11/23 023.
 */

public class VimCallBack extends VimServicePresets {
    public abstract static class FnCbInt extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbInt() {
            allocate();
        }

        public FnCbInt(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int p);
    }

    public abstract static class FnCbErrLong extends FunctionPointer {
        static {
            Loader.load();
        }

        public FnCbErrLong(Pointer p) {
            super(p);
        }

        protected FnCbErrLong() {
            allocate();
        }

        private native void allocate();

        public abstract void call(int code, long code64);
    }

    public abstract static class FnCbByteGroup extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbByteGroup() {
            allocate();
        }

        public FnCbByteGroup(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(byte code8, @ByRef @Cast("const Group&") Pointer p);
    }


    public abstract static class FnCbIntContact extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbIntContact() {
            allocate();
        }

        public FnCbIntContact(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int p, @ByRef @Cast("const Contact&") Pointer p1);
    }

    public abstract static class FnCbIntChatVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbIntChatVector() {

            allocate();
        }

        public FnCbIntChatVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int i, @ByRef @Cast("const std::vector<std::shared_ptr<Chat>>&") Pointer p);
    }

    public abstract static class FnCbIntLongMemberVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbIntLongMemberVector() {
            allocate();
        }

        public FnCbIntLongMemberVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int i, long code64, @ByRef @Cast("const std::vector<std::shared_ptr<Member>>&") Pointer p);
    }

    public abstract static class FnCbIntContactVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbIntContactVector() {
            allocate();
        }

        public FnCbIntContactVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int p, @ByRef @Cast("const std::vector<Contact>&") Pointer p2);
    }
	
	public abstract static class FnCbChannelEvt extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbChannelEvt() {
            allocate();
        }

        public FnCbChannelEvt(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("model::channelEvent&") Pointer p2);
    }
	
	public abstract static class FnCbMultiRtcEvent extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbMultiRtcEvent() {
            allocate();
        }

        public FnCbMultiRtcEvent(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("model::multiRtcEvent&") Pointer p2);
    }
	
    public abstract static class FnCbLong extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLong() {
            allocate();
        }

        public FnCbLong(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(long code64);
    }

    public abstract static class FnCbLongStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLongStr() {
            allocate();
        }

        public FnCbLongStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(long code64, @Cast({"", "const std::string&"}) @StdString String p);
    }

    public abstract static class FnCbLongStrLongStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLongStrLongStr() {
            allocate();
        }

        public FnCbLongStrLongStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(long code1, @Cast({"", "const std::string&"}) @StdString String p, long code2, @Cast({"", "const std::string&"}) @StdString String p2);
    }

    public abstract static class FnCbLongMember extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLongMember() {
            allocate();
        }

        public FnCbLongMember(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(long code64, @ByRef @Cast("const Member&") Pointer p);
    }

    public abstract static class FnCbUpgradeInfo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbUpgradeInfo() {
            allocate();
        }

        public FnCbUpgradeInfo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("const UpgradeInfo&") Pointer p);
    }
    
        public abstract static class FnCbScanQrInfo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbScanQrInfo() {
            allocate();
        }

        public FnCbScanQrInfo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@Cast({"", "const std::string&"}) @StdString String p);
    }

    public abstract static class FnCbMsg extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbMsg() {
            allocate();
        }

        public FnCbMsg(Pointer p) {
            super(p);
        }

        private native void allocate();

        // 现在还没明白为什么要加 @Const
        public abstract void call(@Const @Cast({"", "std::shared_ptr<Msg>"}) @SharedPtr @ByVal Pointer p);
    }

    public abstract static class FnCbAccount extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbAccount() {
            allocate();
        }

        public FnCbAccount(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("Account&") Pointer p);
    }

    public abstract static class FnCbOnlineState extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbOnlineState() {
            allocate();
        }

        public FnCbOnlineState(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("const OnlineState&") Pointer p);
    }

    public abstract static class FnCbSystem extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbSystem() {
            allocate();
        }

        public FnCbSystem(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("const SysMsg&") Pointer p);
    }

    public abstract static class FnCbSysInt extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbSysInt() {
            allocate();
        }

        public FnCbSysInt(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("const SysMsg&") Pointer p, int p1);
    }

    public abstract static class FnCbStrUser extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbStrUser() {
            allocate();
        }

        public FnCbStrUser(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@Cast({"", "const std::string&"}) @StdString String p, @ByRef @Cast("const User&") Pointer p1);
    }

    public abstract static class FnCbStrLongByte extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbStrLongByte() {
            allocate();
        }

        public FnCbStrLongByte(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@Cast({"", "const std::string&"}) @StdString String p, long code64, byte code8);
    }

    public abstract static class FnCbGroupVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbGroupVector() {
            allocate();
        }

        public FnCbGroupVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("const std::vector<std::shared_ptr<TinyGroup>>&") Pointer p);
    }

    public abstract static class FnCbOfflineMsgVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbOfflineMsgVector() {
            allocate();
        }

        public FnCbOfflineMsgVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("const std::vector<OfflineMsg>&") Pointer p);
    }

    public abstract static class FnCbError extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbError() {
            allocate();
        }

        public FnCbError(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code);
    }

    public abstract static class FnCbErrByte extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrByte() {
            allocate();
        }

        public FnCbErrByte(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, byte mode);
    }

    public abstract static class FnCbErr2Long extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr2Long() {
            allocate();
        }

        public FnCbErr2Long(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long code1, long code2);
    }

    public abstract static class FnCbErr2LongVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr2LongVector() {
            allocate();
        }

        public FnCbErr2LongVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<int64>&") Pointer p1, @ByRef @Cast("std::vector<int64>&") Pointer p2);
    }

    public abstract static class FnCbErrLongMsgPtrVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongMsgPtrVector() {
            allocate();
        }

        public FnCbErrLongMsgPtrVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long code64, @ByRef @Cast("const std::vector<MsgPtr>&") Pointer p);
    }

    public abstract static class FnCbErrMsgPtrVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMsgPtrVector() {
            allocate();
        }

        public FnCbErrMsgPtrVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<MsgPtr>&") Pointer p);
    }

    public abstract static class FnCbErr4Str extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr4Str() {
            allocate();
        }

        public FnCbErr4Str(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @Cast({"", "const std::string&"}) @StdString String p, @Cast({"", "const std::string&"}) @StdString String p1, @Cast({"", "const std::string&"}) @StdString String p2, @Cast({"", "const std::string&"}) @StdString String p3);
    }

    public abstract static class FnCbErrInt extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrInt() {
            allocate();
        }

        public FnCbErrInt(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, int code32);
    }

    public abstract static class FnCbErrStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrStr() {
            allocate();
        }

        public FnCbErrStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @Cast({"", "const std::string&"}) @StdString String p);
    }

    public abstract static class FnCbErrIntLong extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrIntLong() {
            allocate();
        }

        public FnCbErrIntLong(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, int code32, long code64);
    }

    public abstract static class FnCbErrIntStringVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrIntStringVector() {
            allocate();
        }

        public FnCbErrIntStringVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, int code32,  @ByRef @Cast("const std::vector<std::string>&") Pointer p);
    }

    public abstract static class FnCbErrVerify extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrVerify() {
            allocate();
        }

        public FnCbErrVerify(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const ContactVerifyType&") Pointer p);
    }

    public abstract static class FnCbErrOnlineStateVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrOnlineStateVector() {
            allocate();
        }

        public FnCbErrOnlineStateVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<OnlineState>&") Pointer p);
    }

    public abstract static class FnCbErrLongVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongVector() {
            allocate();
        }

        public FnCbErrLongVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<int64>&") Pointer p);
    }

    public abstract static class FnCbErrEnterpriseVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrEnterpriseVector() {
            allocate();
        }

        public FnCbErrEnterpriseVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<EnterpriseDictionary>&") Pointer p);
    }

    public abstract static class FnCbErrTaskVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrTaskVector() {
            allocate();
        }

        public FnCbErrTaskVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<Task>&") Pointer p);
    }

    // public abstract static class FnCbErrMsgBeanVector extends FunctionPointer {
    //     static {
    //         Loader.load();
    //     }

    //     protected FnCbErrMsgBeanVector() {
    //         allocate();
    //     }

    //     public FnCbErrMsgBeanVector(Pointer p) {
    //         super(p);
    //     }

    //     private native void allocate();

    //     public abstract void call(int code, @ByRef @Cast("const std::vector<MsgBean>&") Pointer p) {
    //         System.out.println("=>FnCbErrMsgBeanVector call");
    //     }
    // }

    public abstract static class FnCbErrRoomVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrRoomVector() {
            allocate();
        }

        public FnCbErrRoomVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<room>&") Pointer p);
    }

    public abstract static class FnCbErrEntVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrEntVector() {
            allocate();
        }

        public FnCbErrEntVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<entpriseInfo>&") Pointer p);
    }

    public abstract static class FnCbErrOrgVectorEntVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrOrgVectorEntVector() {
            allocate();
        }

        public FnCbErrOrgVectorEntVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<OrganizationInfo>&") Pointer p, @ByRef @Cast("const std::vector<EntpriseUserInfo>&") Pointer p1);
    }
	
		
    public abstract static class FnCbErrPersonalMap extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrPersonalMap() {
            allocate();
        }

        public FnCbErrPersonalMap(Pointer p) {
            super(p);
        }

        private native void allocate();
        public abstract void call(int code,@ByRef @Cast("std::map<int64,std::vector<PersonalDataSwitch>>&") Pointer p1);
    }
    
   public abstract static class FnCbErrStrClientVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrStrClientVector() {
            allocate();
        }

        public FnCbErrStrClientVector(Pointer p) {
            super(p);
        }

        private native void allocate();
        public abstract void call(int code,@Cast({"", "const std::string&"}) @StdString String p,@ByRef @Cast("const std::vector<ClientMenuSet>&") Pointer p1);
    }
	
	
	
	public abstract static class FnCbErrOrgVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrOrgVector() {
            allocate();
        }

        public FnCbErrOrgVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<OrganizationInfo>&") Pointer p);
    }
    public abstract static class FnCbErr2LongEntMap extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr2LongEntMap() {
            allocate();
        }

        public FnCbErr2LongEntMap(Pointer p) {
            super(p);
        }

        private native void allocate();

        //"std::function<void(ErrorInfo,int64,int64,std::map<std::string,std::vector<EntpriseUserInfo>>&)>"
        public abstract void call(int code, long code1, long code64, @ByRef @Cast("std::map<std::string,std::vector<EntpriseUserInfo>>&") Pointer p1);
    }

    public abstract static class FnCbErrEntUserVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrEntUserVector() {
            allocate();
        }

        public FnCbErrEntUserVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<EntpriseUserInfo>&") Pointer p);
    }

    public abstract static class FnCbErrOrg extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrOrg() {
            allocate();
        }

        public FnCbErrOrg(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const OrganizationInfo&") Pointer p);
    }

    public abstract static class FnCbErrLongVectorIntVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongVectorIntVector() {
            allocate();
        }

        public FnCbErrLongVectorIntVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<int64>&") Pointer p, @ByRef @Cast("const std::vector<int>&") Pointer p2);
    }

    public abstract static class FnCbErrNoteVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrNoteVector() {
            allocate();
        }

        public FnCbErrNoteVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<BaseNoteInfo>&") Pointer p);
    }

    public abstract static class FnCbErr2Str extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr2Str() {
            allocate();
        }

        public FnCbErr2Str(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @Cast({"", "const std::string&"}) @StdString String p, @Cast({"", "const std::string&"}) @StdString String p1);
    }

    public abstract static class FnCbErrLongStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongStr() {
            allocate();
        }

        public FnCbErrLongStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long code64, @Cast({"", "const std::string&"}) @StdString String p);
    }
	public abstract static class FnCbErrLongLongStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongLongStr() {
            allocate();
        }

        public FnCbErrLongLongStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long code64,long code2,@Cast({"", "const std::string&"}) @StdString String p);
    }
	public abstract static class FnCbErrLongLongStrByte extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongLongStrByte() {
            allocate();
        }

        public FnCbErrLongLongStrByte(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long code64,long code2,@Cast({"", "const std::string&"}) @StdString String p,byte code3);
    }
	//群文档
	public abstract static class FnCbErrStrLongLongInt extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrStrLongLongInt() {
            allocate();
        }

        public FnCbErrStrLongLongInt(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @Cast({"", "const std::string&"}) @StdString String p,long code64,long code2,int code3);
    }
	public abstract static class FnCbErrStr3LongByte extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrStr3LongByte() {
            allocate();
        }

        public FnCbErrStr3LongByte(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @Cast({"", "const std::string&"}) @StdString String p,long code64,long code2,long code23,byte code4);
    }
	public abstract static class FnCbErrStrLongLongIntGroupDocAttribute extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrStrLongLongIntGroupDocAttribute() {
            allocate();
        }

        public FnCbErrStrLongLongIntGroupDocAttribute(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @Cast({"", "const std::string&"}) @StdString String p,long code64,long code2,int code3,@ByRef @Cast("const std::vector<GroupDocAttribute>&") Pointer q);
    }	
    public abstract static class FnCbErrFileVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrFileVector() {
            allocate();
        }

        public FnCbErrFileVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<Fileinfo>&") Pointer p);
    }

    public abstract static class FnCbErrFileMap extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrFileMap() {
            allocate();
        }

        public FnCbErrFileMap(Pointer p) {
            super(p);
        }

        private native void allocate();

        //"std::function<void(ErrorInfo,std::map<int64,FileInfo>&)>"
        public abstract void call(int code, @ByRef @Cast("std::map<int64,Fileinfo>&") Pointer p1);
    }

    public abstract static class FnCbErrMemberVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMemberVector() {
            allocate();
        }

        public FnCbErrMemberVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<std::shared_ptr<Member>>&") Pointer p);
    }
    
    public abstract static class FnCbErrGroupDocAttributeVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrGroupDocAttributeVector() {
            allocate();
        }

        public FnCbErrGroupDocAttributeVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<GroupDocAttribute>&") Pointer p);
    }
    
    public abstract static class FnCbErrGroupDocUpdownInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrGroupDocUpdownInfoVector() {
            allocate();
        }

        public FnCbErrGroupDocUpdownInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<GroupDocUpdownInfo>&") Pointer p);
    }
	
	public abstract static class FnCbErrMemberVectors extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMemberVectors() {
            allocate();
        }

        public FnCbErrMemberVectors(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<Member>&") Pointer p);
    }

    public abstract static class FnCbErr2Byte extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr2Byte() {
            allocate();
        }

        public FnCbErr2Byte(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, byte code1, byte code2);
    }
	
	public abstract static class FnCbErr4Byte extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr4Byte() {
            allocate();
        }

        public FnCbErr4Byte(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, byte code1, byte code2, byte code3, byte code4);
    }
	
    public abstract static class FnCbErrSearch extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrSearch() {
            allocate();
        }

        public FnCbErrSearch(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const SearchResult&") Pointer p);
    }

    public abstract static class FnCbErrUser extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrUser() {
            allocate();
        }

        public FnCbErrUser(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const User&") Pointer p);
    }

    public abstract static class FnCbErrContact extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrContact() {
            allocate();
        }

        public FnCbErrContact(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const Contact&") Pointer p);
    }

    public abstract static class FnCbErrMsgSearch extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMsgSearch() {
            allocate();
        }

        public FnCbErrMsgSearch(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const MsgSearchResult&") Pointer p);
    }

    public abstract static class FnCbErrMsgDetail extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMsgDetail() {
            allocate();
        }

        public FnCbErrMsgDetail(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const MsgDetailSearchResult&") Pointer p);
    }

    public abstract static class FnCbErrSysVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrSysVector() {
            allocate();
        }

        public FnCbErrSysVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<SysMsg>&") Pointer p);
    }

    public abstract static class FnCbErrUserSetting extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrUserSetting() {
            allocate();
        }

        public FnCbErrUserSetting(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const UserSetting&") Pointer p);
    }

    public abstract static class FnCbErrLongVectorBoolean extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongVectorBoolean() {
            allocate();
        }

        public FnCbErrLongVectorBoolean(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<int64>&") Pointer p, boolean b);
    }

    public abstract static class FnCbErr2IntBoolean extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr2IntBoolean() {
            allocate();
        }

        public FnCbErr2IntBoolean(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, int code0, int code1, boolean b);
    }

    public abstract static class FnCbErrLongByte extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongByte() {
            allocate();
        }

        public FnCbErrLongByte(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long code64, byte code8);
    }

    public abstract static class FnCbErrLocalVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLocalVector() {
            allocate();
        }

        public FnCbErrLocalVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<LocalSetting>&") Pointer p);
    }

    public abstract static class FnCbErrDataVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrDataVector() {
            allocate();
        }

        public FnCbErrDataVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<PersonalData>&") Pointer p);
    }

    public abstract static class FnCbErrEntApp extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrEntApp() {
            allocate();
        }

        public FnCbErrEntApp(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const EntAppinfo&") Pointer p);
    }

    public abstract static class FnCbErrMsgVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMsgVector() {
            allocate();
        }

        public FnCbErrMsgVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<Msg>&") Pointer p);
    }

    public abstract static class FnCbErrAppPage extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrAppPage() {
            allocate();
        }

        public FnCbErrAppPage(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const SmallMarketAppPage&") Pointer p);
    }
	
    public abstract static class FnCbErrAppListMenu extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrAppListMenu() {
            allocate();
        }

        public FnCbErrAppListMenu(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const AppListMenuInfo&") Pointer p);
    }
	
    public abstract static class FnCbErrAppVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrAppVector() {
            allocate();
        }

        public FnCbErrAppVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<SmallMarketAppInfo>&") Pointer p);
    }
	
	    public abstract static class FnCbErrAppMenuVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrAppMenuVector() {
            allocate();
        }

        public FnCbErrAppMenuVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<GroupAppListMenuResult>&") Pointer p);
    }

    public abstract static class FnCbErrEmoPackVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrEmoPackVector() {
            allocate();
        }

        public FnCbErrEmoPackVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<EmoticonPackage>&") Pointer p);
    }

    public abstract static class FnCbErrEmoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrEmoVector() {
            allocate();
        }

        public FnCbErrEmoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<Emoticon>&") Pointer p);
    }

    public abstract static class FnCbErrEmoPack extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrEmoPack() {
            allocate();
        }

        public FnCbErrEmoPack(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const EmoticonPackage&") Pointer p);
    }

    public abstract static class FnCbErrPageQueryEmo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrPageQueryEmo() {
            allocate();
        }

        public FnCbErrPageQueryEmo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const PageQueryEmoticon&") Pointer p);
    }

    public abstract static class FnCbErrInt2Vector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrInt2Vector() {
            allocate();
        }

        public FnCbErrInt2Vector(Pointer p) {
            super(p);
        }

        private native void allocate();

        //"std::function<void(ErrorInfo,int32,std::string,std::vector<EmoticonResult>&,std::vector<EmoticonResult>&)>"
        public abstract void call(int code, @Cast("int32") int code32, @ByRef @Cast("std::vector<EmoticonResult>&") Pointer p, @ByRef @Cast("std::vector<EmoticonResult>&") Pointer p2);
    }

    public abstract static class FnCbErrStrLong extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrStrLong() {
            allocate();
        }

        public FnCbErrStrLong(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @Cast({"", "const std::string&"}) @StdString String p, long code64);
    }

    public abstract static class FnCbErrLong2Str extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLong2Str() {
            allocate();
        }

        public FnCbErrLong2Str(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long code64, @Cast({"", "const std::string&"}) @StdString String p, @Cast({"", "const std::string&"}) @StdString String p2);
    }

    public abstract static class FnCb2IntStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCb2IntStr() {
            allocate();
        }

        public FnCb2IntStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code32, int code1, @Cast({"", "const std::string&"}) @StdString String p);
    }

    public abstract static class FnCbErrP2pUserVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrP2pUserVector() {
            allocate();
        }

        public FnCbErrP2pUserVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        //    .put(new Info("std::function<void(ErrorInfo, )>").pointerTypes("FnCbErrP2pUserVector"))
        public abstract void call(int code, @ByRef @Cast("std::vector<p2pUser>&") Pointer p);
    }

    public abstract static class FnCbLongByte2 extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLongByte2() {
            allocate();
        }

        public FnCbLongByte2(Pointer p) {
            super(p);
        }

        private native void allocate();

        //    .put(new Info("std::function<void(int64, int8, int8)>").pointerTypes("FnCbLongByte2"))
        public abstract void call(long code64, byte b1, byte b2);
    }

    public abstract static class FnCbP2pSendFileReq extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbP2pSendFileReq() {
            allocate();
        }

        public FnCbP2pSendFileReq(Pointer p) {
            super(p);
        }

        private native void allocate();

        //    .put(new Info("std::function<void(P2pSendFileReq&)>").pointerTypes("FnCbP2pSendFileReq"))
        public abstract void call(@ByRef @Cast("P2pSendFileReq&") Pointer p);
    }

    public abstract static class FnCbByteLong extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbByteLong() {
            allocate();
        }

        public FnCbByteLong(Pointer p) {
            super(p);
        }

        private native void allocate();

        //    .put(new Info("std::function<void(int8, int64)>").pointerTypes("FnCbByteLong"))
        public abstract void call(byte code8, long code64);
    }

    public abstract static class FnCbErrrecommendVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrrecommendVector() {
            allocate();
        }

        public FnCbErrrecommendVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        // std::function<void(ErrorInfo,std::vector<RecommendContact>&)>
        public abstract void call(int errCode, @ByRef @Cast("std::vector<RecommendContact>&") Pointer p);
    }

    public abstract static class FnCbErrUserVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrUserVector() {
            allocate();
        }

        public FnCbErrUserVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        // std::function<void(ErrorInfo,std::vector<User>&)>
        public abstract void call(int errCode, @ByRef @Cast("std::vector<User>&") Pointer p);
    }

    public abstract static class FnCbErrGroup extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrGroup() {
            allocate();
        }

        public FnCbErrGroup(Pointer p) {
            super(p);
        }

        private native void allocate();

        // std::function<void(ErrorInfo, Group&)>
        public abstract void call(int errCode, @ByRef @Cast("Group&") Pointer p);
    }

    public abstract static class FnCbErrLongStr2Byte extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongStr2Byte() {
            allocate();
        }

        public FnCbErrLongStr2Byte(Pointer p) {
            super(p);
        }

        private native void allocate();

        // std::function<void(ErrorInfo,int64,const std::string&,int8,int8)>
        public abstract void call(int errCode, long int64, @Cast({"", "const std::string&"}) @StdString String p, byte b1, byte b2);
    }

    public abstract static class FnCb3Long extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCb3Long() {
            allocate();
        }

        public FnCb3Long(Pointer p) {
            super(p);
        }

        private native void allocate();

        // std::function<void(int64,int64,int64)>
        public abstract void call(long userID, long targetID, long maxReadID);
    }    
    
	public abstract static class FnCb2LongByte extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCb2LongByte() {
            allocate();
        }

        public FnCb2LongByte(Pointer p) {
            super(p);
        }

        private native void allocate();

        // std::function<void(int64,int64,int64)>
        public abstract void call(long userID, long targetID, byte maxReadID);
    }
/*
    public abstract static class FnCbAVEvent extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbAVEvent() {
            allocate();
        }

        public FnCbAVEvent(Pointer p) {
            super(p);
        }

        private native void allocate();

        // std::function<void(model::AVEvent)>
        public abstract void call(@ByRef @Cast("AVEvent") Pointer p);
    }
*/
    public abstract static class FnCbIntLong extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbIntLong() {
            allocate();
        }

        public FnCbIntLong(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long userId);
    }

    public abstract static class FnCbErr2Byte2EntVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr2Byte2EntVector() {
            allocate();
        }

        public FnCbErr2Byte2EntVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        //std::function<void(ErrorInfo,int8,int8,std::vector<OrganizationInfo>&,std::vector<EntpriseUserInfo>&)>
        public abstract void call(int code, byte allowChat, byte contactVisiable, @ByRef @Cast("std::vector<OrganizationInfo>&") Pointer p, @ByRef @Cast("std::vector<EntpriseUserInfo>&") Pointer p1);
    }
       
     public abstract static class FnCbErrStrLongMap extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrStrLongMap() {
            allocate();
        }

        public FnCbErrStrLongMap(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("std::map<std::string, int64>&") Pointer p);
    }

	 public abstract static class FnCbErrEmoticon extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrEmoticon() {
            allocate();
        }

        public FnCbErrEmoticon(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("Emoticon&") Pointer p);
    }
	public abstract static class FnCbErrSgEmoticonResult extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrSgEmoticonResult() {
            allocate();
        }

        public FnCbErrSgEmoticonResult(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("singleEmoticonResult&") Pointer p);
    }

	public abstract static class FnCbErrGetConfer extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrGetConfer() {
            allocate();
        }

        public FnCbErrGetConfer(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("getConfer&") Pointer p);
    }
	public abstract static class FnCbLongIntIntResult extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLongIntIntResult() {
            allocate();
        }

        public FnCbLongIntIntResult(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(long code,int code0,int code1);
    }
	public abstract static class FnCbErrYMDIntVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrYMDIntVector() {
            allocate();
        }

        public FnCbErrYMDIntVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("std::vector<model::YMD>&") Pointer p,@ByRef @Cast("std::vector<int32>&") Pointer p1);
    }	
	 public abstract static class FnCbErrMsgPtrVectorTaskVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMsgPtrVectorTaskVector() {
            allocate();
        }

        public FnCbErrMsgPtrVectorTaskVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("const std::vector<MsgPtr>&") Pointer p,@ByRef @Cast("std::vector<model::Task>&") Pointer p1);
    }
	 public abstract static class FnCbLongIntIntStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLongIntIntStr() {
            allocate();
        }

        public FnCbLongIntIntStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(long code0, int code32, int code1, @Cast({"", "const std::string&"}) @StdString String p);
    }
	public abstract static class FnCbErrGetAVServer extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrGetAVServer() {
            allocate();
        }

        public FnCbErrGetAVServer(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("p2pServerInfo&") Pointer p);
    }
	public abstract static class FnCbErrLongLongBadWord extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongLongBadWord() {
            allocate();
        }

        public FnCbErrLongLongBadWord(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,long l1,long l2,@ByRef @Cast("BadWord&") Pointer p);
    }
	public abstract static class FnCbErroneLongBadWord extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErroneLongBadWord() {
            allocate();
        }

        public FnCbErroneLongBadWord(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,long l1,@ByRef @Cast("BadWord&") Pointer p);
    }
	 public abstract static class FnCbErrintStrStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrintStrStr() {
            allocate();
        }

        public FnCbErrintStrStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, int retcode,@Cast("std::string&") @StdString String p, @Cast("std::string&") @StdString String p1);
    }
	
	 public abstract static class FnCbLongLongEntAppInfo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLongLongEntAppInfo() {
            allocate();
        }

        public FnCbLongLongEntAppInfo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long retcode1,long retcode2,@ByRef @Cast("std::vector<model::EntAppinfo>&") Pointer p);
    }
	
	public abstract static class FnCbLongStringMap extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLongStringMap() {
            allocate();
        }

        public FnCbLongStringMap(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("std::map<int64,std::string>&") Pointer p);
    }
	public abstract static class FnCbErrMapStrStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMapStrStr() {
            allocate();
        }

        public FnCbErrMapStrStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("std::map<std::string,std::string>&") Pointer p);
    }
	
	public abstract static class FnCbErrIntStrLongMap extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrIntStrLongMap() {
            allocate();
        }

        public FnCbErrIntStrLongMap(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,int type,@ByRef @Cast("std::map<std::string,int64>&") Pointer p);
    }
	
	public abstract static class FnCbByteStrStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbByteStrStr() {
            allocate();
        }

        public FnCbByteStrStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call( byte code, @Cast({"", "std::string&"}) @StdString String p, @Cast({"", "std::string&"}) @StdString String p2);
    }
	public abstract static class FnCbStringLongVectorMap extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbStringLongVectorMap() {
            allocate();
        }

        public FnCbStringLongVectorMap(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("std::map<std::string,std::vector<int64>>&") Pointer p);
    }
	public abstract static class FnCbErrAuthUserBean extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrAuthUserBean() {
            allocate();
        }

        public FnCbErrAuthUserBean(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("AuthUserBean&") Pointer p);
    }
	public abstract static class FnCbErrVectorAPPType extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrVectorAPPType() {
            allocate();
        }

        public FnCbErrVectorAPPType(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("std::vector<smallMarketAppType>&") Pointer p);
    }
	 public abstract static class FnCbIntStr extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbIntStr() {
            allocate();
        }

        public FnCbIntStr(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code64, @Cast({"", "const std::string&"}) @StdString String p);
    }
	public abstract static class FnCbErrCloudFileInfo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrCloudFileInfo() {
            allocate();
        }

        public FnCbErrCloudFileInfo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("CloudFileInfo&") Pointer p);
    }
	
	public abstract static class FnCbErrVectorCloudFileInfo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrVectorCloudFileInfo() {
            allocate();
        }

        public FnCbErrVectorCloudFileInfo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<CloudFileInfo>&") Pointer p);
    }
	
	public abstract static class FnCbErrCloudRoleInfo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrCloudRoleInfo() {
            allocate();
        }

        public FnCbErrCloudRoleInfo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,  @ByRef @Cast("CloudRoleInfo&") Pointer p);
    }
	public abstract static class FnCbErrCloudPermission extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrCloudPermission() {
            allocate();
        }

        public FnCbErrCloudPermission(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,  @ByRef @Cast("CloudPermission&") Pointer p);
    }
	
	public abstract static class FnCbErrTeamMemberInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrTeamMemberInfoVector() {
            allocate();
        }

        public FnCbErrTeamMemberInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<TeamMemberInfo>&") Pointer p);
    }
	public abstract static class FnCbErrCloudRoleInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrCloudRoleInfoVector() {
            allocate();
        }

        public FnCbErrCloudRoleInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<CloudRoleInfo>&") Pointer p);
    }
    public abstract static class FnCbErrAppNodeInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrAppNodeInfoVector() {
            allocate();
        }

        public FnCbErrAppNodeInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<AppNodeInfo>&") Pointer p);
    }
    public abstract static class FnCbLongOrgInfoVectorOrgUserVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbLongOrgInfoVectorOrgUserVector() {
            allocate();
        }

        public FnCbLongOrgInfoVectorOrgUserVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long l, @ByRef @Cast("std::vector<OrganizationInfo>&") Pointer p, @ByRef @Cast("std::vector<OrgSearchUserInfo>&") Pointer p1);
    }
    public abstract static class FnCbErrWorkbenchBannerVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrWorkbenchBannerVector() {
            allocate();
        }

        public FnCbErrWorkbenchBannerVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<WorkbenchBanner>&") Pointer p);
    }
    public abstract static class FnCbErrHelpSysInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrHelpSysInfoVector() {
            allocate();
        }

        public FnCbErrHelpSysInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<HelpSystemInfo>&") Pointer p);
    }
    public abstract static class FnCbErrMsgUnreadCountVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMsgUnreadCountVector() {
            allocate();
        }

        public FnCbErrMsgUnreadCountVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<MsgUnreadCounter>&") Pointer p);
    }
    public abstract static class FnCbErrOnlineState extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrOnlineState() {
            allocate();
        }

        public FnCbErrOnlineState(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("OnlineState&") Pointer p);
    }
	public abstract static class FnCbErrOAuth extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrOAuth() {
            allocate();
        }

        public FnCbErrOAuth(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("OAuthResult&") Pointer p);
    }
	public abstract static class FnCbErrAdminRoleInfo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrAdminRoleInfo() {
            allocate();
        }

        public FnCbErrAdminRoleInfo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("AdminRoleInfo&") Pointer p);
    }
	public abstract static class FnCbErrCloudUser extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrCloudUser() {
            allocate();
        }

        public FnCbErrCloudUser(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("CloudUserInfo&") Pointer p);
    }
	public abstract static class FnCbErrBoolMarketAppGroupVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrBoolMarketAppGroupVector() {
            allocate();
        }

        public FnCbErrBoolMarketAppGroupVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, boolean b, @ByRef @Cast("std::vector<MarketAppGroup>&") Pointer p);
    }
	public abstract static class FnCbErrGroupIssueVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrGroupIssueVector() {
            allocate();
        }

        public FnCbErrGroupIssueVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<GroupIssue>&") Pointer p);
    }
	public abstract static class FnCbErrGroupIssue extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrGroupIssue() {
            allocate();
        }

        public FnCbErrGroupIssue(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("GroupIssue&") Pointer p);
    }
	public abstract static class FnCbErrGroupAnnouncementList extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrGroupAnnouncementList() {
            allocate();
        }

        public FnCbErrGroupAnnouncementList(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("GroupAnnouncementList&") Pointer p);
    }
	public abstract static class FnCbErrLocalAppInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLocalAppInfoVector() {
            allocate();
        }

        public FnCbErrLocalAppInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<LocalAppInfo>&") Pointer p);
    }
	public abstract static class FnCbErrNotebookVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrNotebookVector() {
            allocate();
        }

        public FnCbErrNotebookVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<Notebook>&") Pointer p);
    }
	public abstract static class FnCbErrNoteEntryVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrNoteEntryVector() {
            allocate();
        }

        public FnCbErrNoteEntryVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<NoteEntry>&") Pointer p);
    }
	public abstract static class FnCbErrBool extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrBool() {
            allocate();
        }

        public FnCbErrBool(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, boolean b);
    }
	public abstract static class FnCbErrCustomerPoolVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrCustomerPoolVector() {
            allocate();
        }

        public FnCbErrCustomerPoolVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<CustomerPoolBean>&") Pointer p);
    }
	public abstract static class FnCbErrCustomerLastMsg extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrCustomerLastMsg() {
            allocate();
        }

        public FnCbErrCustomerLastMsg(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @Const @Cast({"", "std::shared_ptr<Msg>"}) @SharedPtr @ByVal Pointer p);
    }
	public abstract static class FnCbErrCustomAppInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrCustomAppInfoVector() {
            allocate();
        }

        public FnCbErrCustomAppInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<CustomAppInfo>&") Pointer p);
    }
	public abstract static class FnCbErrLongLongMsgPtrVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongLongMsgPtrVector() {
            allocate();
        }

        public FnCbErrLongLongMsgPtrVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,long appId64, long userId64, @ByRef @Cast("std::vector<MsgPtr>&") Pointer p);
    }
	
	public abstract static class FnCbErrAppCustomerInfo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrAppCustomerInfo() {
            allocate();
        }

        public FnCbErrAppCustomerInfo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("AppCustomerInfo&") Pointer p);
    }
	public abstract static class FnCbIntCustomChatVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbIntCustomChatVector() {

            allocate();
        }

        public FnCbIntCustomChatVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<CustomChat>&") Pointer p);
    }
	public abstract static class FnCbErrCustomChatVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrCustomChatVector() {

            allocate();
        }

        public FnCbErrCustomChatVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::vector<CustomChat>&") Pointer p);
    }
	
	public abstract static class FnCbErrglobalNoDisturbModeInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrglobalNoDisturbModeInfoVector() {

            allocate();
        }

        public FnCbErrglobalNoDisturbModeInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::vector<globalNoDisturbModeInfo>&") Pointer p);
    }
	public abstract static class FnCbErrDeviceLoginRecordVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrDeviceLoginRecordVector() {

            allocate();
        }

        public FnCbErrDeviceLoginRecordVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::vector<DeviceLoginRecord>&") Pointer p);
    }
	public abstract static class FnCbErrLongLongreminderMsgVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongLongreminderMsgVector() {

            allocate();
        }

        public FnCbErrLongLongreminderMsgVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, long retcode1,long retcode2, @ByRef @Cast("std::vector<reminderMsg>&") Pointer p);
    }
	public abstract static class FnCbErragencymsgVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErragencymsgVector() {

            allocate();
        }

        public FnCbErragencymsgVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::vector<agencymsg>&") Pointer p);
    }
    
	public abstract static class FnCbErrLongLoginClientRecordVectorMap extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongLoginClientRecordVectorMap() {

            allocate();
        }

        public FnCbErrLongLoginClientRecordVectorMap(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::map<int64,std::vector<LoginClientRecord>>&") Pointer p);
    }
	
	public abstract static class FnCbGroupInfoOrSettingInfo extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbGroupInfoOrSettingInfo() {
            allocate();
        }

        public FnCbGroupInfoOrSettingInfo(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(@ByRef @Cast("GroupInfoOrSettingInfo&") Pointer p);
    }
	
	
	public abstract static class FnCbErrSmallAppHelpVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrSmallAppHelpVector() {
            allocate();
        }

        public FnCbErrSmallAppHelpVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::vector<SmallAppHelp>&") Pointer p);
    }
	
	public abstract static class FnCbErrstrc_UserToAppConfigVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrstrc_UserToAppConfigVector() {
            allocate();
        }

        public FnCbErrstrc_UserToAppConfigVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::vector<strc_UserToAppConfig>&") Pointer p);
    }
		
	public abstract static class FnCbErrSecurityVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrSecurityVector() {
            allocate();
        }

        public FnCbErrSecurityVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::vector<Security>&") Pointer p);
    }
	
	
	public abstract static class FnCbErr4ContactVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr4ContactVector() {
            allocate();
        }

        public FnCbErr4ContactVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::vector<Contact>&") Pointer p, @ByRef @Cast("std::vector<Contact>&") Pointer p1, @ByRef @Cast("std::vector<Contact>&") Pointer p2, @ByRef @Cast("std::vector<Contact>&") Pointer p3);
    }
	
	
	public abstract static class FnCbErrLong4ContactVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLong4ContactVector() {
            allocate();
        }

        public FnCbErrLong4ContactVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, long retcode, @ByRef @Cast("std::vector<Contact>&") Pointer p, @ByRef @Cast("std::vector<Contact>&") Pointer p1, @ByRef @Cast("std::vector<Contact>&") Pointer p2, @ByRef @Cast("std::vector<Contact>&") Pointer p3);
    }
	public abstract static class FnCbErr3MemberMap extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr3MemberMap() {
            allocate();
        }

        public FnCbErr3MemberMap(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<std::shared_ptr<Member>>&") Pointer p1, @ByRef @Cast("std::vector<std::shared_ptr<Member>>&") Pointer p2, @ByRef @Cast("std::map<int64,std::vector<int64>>&") Pointer p3);
    }
	public abstract static class FnCbErrGetNodeInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrGetNodeInfoVector() {
            allocate();
        }

        public FnCbErrGetNodeInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<OutEntNodeInfo>&") Pointer p1);
    }
	
	public abstract static class FnCbErr4LongElevatorAuthorityVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr4LongElevatorAuthorityVector() {
            allocate();
        }

        public FnCbErr4LongElevatorAuthorityVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, long retcode1, long retcode2, long retcode3, long retcode4, @ByRef @Cast("std::vector<ElevatorAuthority>&") Pointer p);
    }	
	
	public abstract static class FnCbErrElevatorAuthorityVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrElevatorAuthorityVector() {
            allocate();
        }

        public FnCbErrElevatorAuthorityVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int flag, @ByRef @Cast("std::vector<ElevatorAuthority>&") Pointer p);
    }	

				
	public abstract static class FnCbErragencyTaskMsg extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErragencyTaskMsg() {
            allocate();
        }

        public FnCbErragencyTaskMsg(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,@ByRef @Cast("agencyTaskMsg&") Pointer p);
    }
	public abstract static class FnCbErrToDoTaskMsgVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrToDoTaskMsgVector() {
            allocate();
        }

        public FnCbErrToDoTaskMsgVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<ToDoTaskMsg>&") Pointer p);
    }
    public abstract static class FnCbErrLongVectorStrVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrLongVectorStrVector() {
            allocate();
        }

        public FnCbErrLongVectorStrVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<int64>&") Pointer p1, @ByRef @Cast("std::vector<std::string>&") Pointer p2);
    }

    public abstract static class FnCbErr2StrVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErr2StrVector() {
            allocate();
        }

        public FnCbErr2StrVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<std::string>&") Pointer p1, @ByRef @Cast("std::vector<std::string>&") Pointer p2);
    }


    public abstract static class FnCbErrStrVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrStrVector() {
            allocate();
        }

        public FnCbErrStrVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code,  @ByRef @Cast("const std::vector<std::string>&") Pointer p);
    }

	public abstract static class FnCbIntBifactorSt extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbIntBifactorSt() {
            allocate();
        }

        public FnCbIntBifactorSt(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("BifactorSt&") Pointer p);
    }
	public abstract static class FnCbErrMarketAppInfoVector extends FunctionPointer {
        static {
            Loader.load();
        }

        protected FnCbErrMarketAppInfoVector() {
            allocate();
        }

        public FnCbErrMarketAppInfoVector(Pointer p) {
            super(p);
        }

        private native void allocate();

        public abstract void call(int code, @ByRef @Cast("std::vector<MarketAppInfo>&") Pointer p);
    }
}