# 工程目录说明
+  DuiDemo 存放sdkDemo 源代码
+  Duilib  存放duilib源代码
+  lib  存放第三方ImageOleCtrl.lib
+  other 存放依赖的第三方库及证书文件
+  SDK 目录存放SDK库文件
+  Bin 存放编译生成的二进制文件 
+  Build 编译生成的中间文件
# 编译说明
## 编译参数PLAT_FORM 值说明
+ win windows平台
+ mac mac平台
+ fangde linux平台中科方德系统
+ yinhe  linux平台银河麒麟系统
+ zhaoxin linux平台中标兆芯系统
+ longxin linux平台中标龙芯系统
## 编译方法
+  mkdir build
+  cd build
+  cmake  -DPLAT_FORM=平台信息 ../sdkUnitest 
