#!/bin/bash
Cur_dir=$1
#win
rm -rf $Cur_dir/SDK/include/
rm -f $Cur_dir/SDK/lib/win/{commLib.dll,imsdkapi.dll,service.dll,service.lib}
rm -f $Cur_dir/SDK/lib/win/sdkplugins/*.dll
#mac
rm -f $Cur_dir/SDK/lib/mac/{libimsdkapi.dylib,libservice.dylib}
rm -f $Cur_dir/SDK/lib/mac/sdkplugins/*.dylib
#fangde
rm -f $Cur_dir/SDK/lib/linux/fangde/{libcommLib.so,libimsdkapi.so,libservice.so}
rm -f $Cur_dir/SDK/lib/linux/fangde/sdkplugins/*.so
#longxin
rm -f $Cur_dir/SDK/lib/linux/longxin/{libcommLib.so,libimsdkapi.so,libservice.so}
rm -f $Cur_dir/SDK/lib/linux/longxin/sdkplugins/*.so
#yinhe
rm -f $Cur_dir/SDK/lib/linux/yinhe/{libcommLib.so,libimsdkapi.so,libservice.so}
rm -f $Cur_dir/SDK/lib/linux/yinhe/sdkplugins/*.so
#zhaoxin
rm -f $Cur_dir/SDK/lib/linux/zhaoxin/{libcommLib.so,libimsdkapi.so,libservice.so}
rm -f $Cur_dir/SDK/lib/linux/zhaoxin/sdkplugins/*.so
#ios
rm -f $Cur_dir/SDK/lib/ios/*.a

#判断bin目录是否存在
if [ -d "$Cur_dir/Bin/" ];then
  rm -r $Cur_dir/Bin
  echo "已删除Bin目录"
fi
mkdir $Cur_dir/Bin

#add IF else  $1 git_dir  $2 git_count  $3  system_type  $4  branch
if  [ "$3" = "android" ]; then
	FTP_down_dir=asec/sdk/android/
elif [ "$3" = "ios" ]; then
	FTP_down_dir=asec/sdk/iOS/
elif [ "$3" = "win" ]; then
	FTP_down_dir=asec/sdk/pc_win/
elif [ "$3" = "mac" ]; then
    FTP_down_dir=asec/sdk/pc_mac/
elif [ "$3" = "fangde" ]; then
	FTP_down_dir=asec/sdk/pc_linux/ukylin_15.10_x64/
elif [ "$3" = "longxin" ]; then
	FTP_down_dir=asec/sdk/pc_linux/NeoKylin_6.0_mips_64/
elif [ "$3" = "yinhe" ]; then
	FTP_down_dir=asec/sdk/pc_linux/NeoKylin_4.0_aarch64/
elif [ "$3" = "zhaoxin" ]; then
	FTP_down_dir=asec/sdk/pc_linux/NeoKylin_4.0_x64/
fi

#根据输入git_count匹配FTP中文件
if [[ "$3" = "win" ]] || [[ "$3" = "mac" ]]; then
FTP_down_Fname=$(curl ftp://asec:asec@192.168.139.2/$FTP_down_dir | grep "$4_" | grep "$2.zip" | awk '{print $9}')
echo $FTP_down_Fname
#FTP下载lib包
ftp -v -n 192.168.139.2<<EOF
user asec asec
binary
cd $FTP_down_dir
lcd $Cur_dir
prompt
get $FTP_down_Fname 
bye
EOF
echo "download from ftp successfully" 
else
wget -nH -P ./ ftp://asec:asec@192.168.139.2/$FTP_down_dir$4_*$2.zip
FTP_down_Fname=`ls ./ | grep "$2.zip"`
fi

#判断文件是否存在，如果不存在从备用ftp下载
if [ ! -f "$FTP_down_Fname" ]; then
	if [[ "$3" = "win" ]] || [[ "$3" = "mac" ]] || [[ "$3" = "android" ]]; then
	FTP_down_Fname=$(curl ftp://asec:asec@192.168.140.117/$FTP_down_dir | grep "$4_" | grep "$2.zip" | awk '{print $9}')
	echo $FTP_down_Fname
	#FTP下载lib包
	ftp -v -n 192.168.140.117<<EOF
	user asec asec
	binary
	cd $FTP_down_dir
	lcd $Cur_dir
	prompt
	get $FTP_down_Fname 
	bye
EOF
	echo "download from ftp successfully" 
	else
	wget -nH -P ./ ftp://asec:asec@192.168.140.117/$FTP_down_dir$4_*$2.zip
	FTP_down_Fname=`ls ./ | grep "$2.zip"`
	fi
fi

echo $FTP_down_Fname
unzip $FTP_down_Fname

#删除下载压缩包
rm $FTP_down_Fname
#解压后文件夹
unzip_dir=${FTP_down_Fname%.*}


#win与其他zip包结构不同，拷贝include目录分开判断
if [ "$3" = "win" ]; then
	cp -rf $unzip_dir/include $Cur_dir/SDK/
else
	cp -rf $3_${unzip_dir##*_}/include $Cur_dir/SDK/
fi

if [ "$3" = "win" ]; then
	#拷贝dll
	cp -f $unzip_dir/Release/{commLib.dll,imsdkapi.dll,service.dll,service.lib} $Cur_dir/SDK/lib/win/
	#拷贝插件dll
	cp -f $unzip_dir/Release/{lddplugin.dll,mrtcplugin.dll,rtcplugin.dll,secplugin.dll} $Cur_dir/SDK/lib/win/sdkplugins
elif [ "$3" = "mac" ]; then
    cp -f $3_${unzip_dir##*_}/{libimsdkapi.dylib,libservice.dylib} $Cur_dir/SDK/lib/mac/
	cp -f $3_${unzip_dir##*_}/{libhttpServerplugin.dylib,liblddplugin.dylib,libmrtcplugin.dylib,librtcplugin.dylib,libsecplugin.dylib} $Cur_dir/SDK/lib/mac/sdkplugins
elif [ "$3" = "fangde" ]; then
	cp -f $3_${unzip_dir##*_}/{libcommLib.so,libimsdkapi.so,libservice.so} $Cur_dir/SDK/lib/linux/fangde/
	cp -f $3_${unzip_dir##*_}/{liblddplugin.so,libmrtcplugin.so,librtcplugin.so} $Cur_dir/SDK/lib/linux/fangde/sdkplugins
elif [ "$3" = "longxin" ]; then
	cp -f $3_${unzip_dir##*_}/{libcommLib.so,libimsdkapi.so,libservice.so} $Cur_dir/SDK/lib/linux/longxin/
	cp -f $3_${unzip_dir##*_}/{liblddplugin.so,libmrtcplugin.so,librtcplugin.so} $Cur_dir/SDK/lib/linux/longxin/sdkplugins
elif [ "$3" = "yinhe" ]; then
	cp -f $3_${unzip_dir##*_}/{libcommLib.so,libimsdkapi.so,libservice.so} $Cur_dir/SDK/lib/linux/yinhe/
	cp -f $3_${unzip_dir##*_}/{liblddplugin.so,libmrtcplugin.so,librtcplugin.so} $Cur_dir/SDK/lib/linux/yinhe/sdkplugins
elif [ "$3" = "zhaoxin" ]; then
	cp -f ${unzip_dir##*_}/{libcommLib.so,libimsdkapi.so,libservice.so} $Cur_dir/SDK/lib/linux/zhaoxin/
	cp -f ${unzip_dir##*_}/{liblddplugin.so,libmrtcplugin.so,librtcplugin.so} $Cur_dir/SDK/lib/linux/zhaoxin/sdkplugins
fi

#删除zip解压后文件夹（mac的zip与其他结构不同）
if [[ "$3" = "win" ]] || [[ "$3" = "mac" ]]; then
	rm -rf $unzip_dir
else
	rm -rf ${unzip_dir##*_}
fi

#删除Cmake缓存文件
cd $Cur_dir/sdkUnitest/
rm -rf CMakeCache.txt cmake_install.cmake Makefile CMakeFiles/*
rm -rf build/*
rm -rf $FTP_down_Fname

#运行脚本
if [ "$3" = "android" ]; then
    echo $Cur_dir
	cp -r $Cur_dir/sdkUnitest/libs/armeabi-v7a/* $Cur_dir/Bin/
	cp -r $Cur_dir/SDK/lib/$3/* $Cur_dir/Bin/
	#默认ARCH为armv7-a 对应的ARCH_ABI为armeabi-v7a 默认STL为gnustl_static
	cmake -P arcbuild.cmake -DPLATFORM=$3 -DARCH=x86 -DOS=$3 -DBUILD_TYPE=Release -DROOT=$NDK_PATH -DAPI_VERSION=14 -DTOOLCHAIN=clang -S . -B build
elif [ "$3" = "ios" ]; then
    cmake -P arcbuild.cmake -DPLATFORM=ios -DARCH=arm64 -DOS=$3 -B build -S .
elif [ "$3" = "win" ]; then
	cp $Cur_dir/other/build.bat $Cur_dir/sdkUnitest/
	echo $Cur_dir
	cd $Cur_dir/sdkUnitest/
	cmake -P arcbuild.cmake -DPLATFORM=vs2015 -DARCH=x86 -DOS=$3 -DBUILD_TYPE=Release  -S . -B build  
	cp -r $Cur_dir/SDK/lib/win/* $Cur_dir/Bin/
elif [ "$3" = "mac" ]; then
	cd $Cur_dir/sdkUnitest/
	cmake -P arcbuild.cmake -DPLATFORM=$3 -DARCH=x64 -DOS=$3 -DBUILD_TYPE=Release -S . -B build 
	cp -r $Cur_dir/SDK/lib/mac/* $Cur_dir/Bin/
elif [ "$3" = "yinhe" ]; then
	cd $Cur_dir/sdkUnitest/
	cmake -DOS=$3 -DCMAKE_BUILD_TYPE=Release -B build -S .
	cp -r $Cur_dir/SDK/lib/linux/$3/* $Cur_dir/Bin/
elif [ "$3" = "longxin" ]; then
	cd $Cur_dir/sdkUnitest/
	cmake -P arcbuild.cmake -DPLATFORM=linux -DARCH=mips -DOS=$3 -DBUILD_TYPE=Release -S . -B build
	cp -r $Cur_dir/SDK/lib/linux/$3/* $Cur_dir/Bin/
else
	cd $Cur_dir/sdkUnitest/
	cmake -P arcbuild.cmake -DPLATFORM=linux -DARCH=x64 -DOS=$3 -DBUILD_TYPE=Release -S . -B build  
	cp -r $Cur_dir/SDK/lib/linux/$3/* $Cur_dir/Bin/
fi
echo "start compiling!!!!!"
cmake --build build --config Release
cp -rf $Cur_dir/other/* $Cur_dir/Bin/
cp -f $Cur_dir/SDK/lib/linux/fangde/libHkApi.so $Cur_dir/Bin
mkdir $Cur_dir/Bin/xmlconfig/
cp -rf $Cur_dir/xmlconfig/* $Cur_dir/Bin/xmlconfig/
mkdir $Cur_dir/Bin/TestResult
