#!/bin/bash
Cur_dir=$1
Android_moudleDir=data/workspace/
#win
if [ "$3" = "win" ];then
	rm -rf $Cur_dir/SDK/include/
	rm -f $Cur_dir/SDK/lib/win/{commLib.dll,imsdkapi.dll,service.dll,service.lib}
	rm -f $Cur_dir/SDK/lib/win/sdkplugins/*.dll
#mac
elif [ "$3" = "mac" ]; then
	rm -f $Cur_dir/SDK/lib/mac/{libimsdkapi.dylib,libservice.dylib}
	rm -f $Cur_dir/SDK/lib/mac/sdkplugins/*.dylib
#fangde
elif [ "$3" = "fangde" ]; then
	rm -f $Cur_dir/SDK/lib/linux/fangde/{libcommLib.so,libimsdkapi.so,libservice.so}
	rm -f $Cur_dir/SDK/lib/linux/fangde/sdkplugins/*.so
#longxin
elif [ "$3" = "longxin" ]; then
	rm -f $Cur_dir/SDK/lib/linux/longxin/{libcommLib.so,libimsdkapi.so,libservice.so}
	rm -f $Cur_dir/SDK/lib/linux/longxin/sdkplugins/*.so
#yinhe
elif [ "$3" = "yinhe" ]; then
	rm -f $Cur_dir/SDK/lib/linux/yinhe/{libcommLib.so,libimsdkapi.so,libservice.so}
	rm -f $Cur_dir/SDK/lib/linux/yinhe/sdkplugins/*.so
#zhaoxin
elif [ "$3" = "zhaoxin" ]; then
	rm -f $Cur_dir/SDK/lib/linux/zhaoxin/{libcommLib.so,libimsdkapi.so,libservice.so}
	rm -f $Cur_dir/SDK/lib/linux/zhaoxin/sdkplugins/*.so
fi
#判断bin目录是否存在
if [ -d "$Cur_dir/Bin/" ];then
  rm -r $Cur_dir/Bin
  echo "已删除Bin目录"
fi



android_cpotherDir()
{
	adb devices
	adb push $Cur_dir/other/. $Android_moudleDir
	adb push $Cur_dir/other/android.sh $Android_moudleDir

}


android_cpxmlDir()
{
	adb devices
	adb push $Cur_dir/xmlconfig/ $Android_moudleDir
	
}

android_cpvstest()
{
	adb devices
	adb push $Cur_dir/sdkUnitest/libs/x86/vstest $Android_moudleDir
	
}

#add IF else  $1 git_dir  $2 git_count  $3  system_type  $4  branch
if  [ "$3" = "android" ]; then
	FTP_down_dir=asec/sdk/android/
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
if [[ "$3" = "win" ]] || [[ "$3" = "mac" ]] || [[ "$3" = "android" ]]; then
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
rm -rf $FTP_down_Fname

#解压后文件夹
unzip_dir=${FTP_down_Fname%.*}


#win与其他zip包结构不同，拷贝include目录分开判断
if [[ "$3" = "win" ]]; then
	cp -r $unzip_dir/include $Cur_dir/SDK/
elif [[ "$3" = "android" ]]; then
	cp -r ${unzip_dir#*_}/include $Cur_dir/SDK/
else
    rm -rf ${unzip_dir}
    mv -f *.$2 ${unzip_dir}
	cp -r ${unzip_dir}/include $Cur_dir/SDK/
fi

android_cplibs()
{
	adb devices
	adb push $Cur_dir\\${unzip_dir#*_}\\x86\\libjniVimServicePresets.so $Android_moudleDir
	#adb push $Cur_dir\\${unzip_dir#*_}\\x86\\libsecmsgplugin.so $Android_moudleDir
	#adb push $Cur_dir\\${unzip_dir#*_}\\x86\\liblddplugin.so $Android_moudleDir
	#adb push $Cur_dir\\${unzip_dir#*_}\\x86\\librtcplugin.so $Android_moudleDir
	#adb push $Cur_dir\\${unzip_dir#*_}\\x86\\libmrtcplugin.so $Android_moudleDir

}

if [ "$3" = "win" ]; then
	#拷贝dll
	cp $unzip_dir/Release/{commLib.dll,imsdkapi.dll,service.dll,service.lib} $Cur_dir/SDK/lib/win/
	#拷贝插件dll
	cp $unzip_dir/Release/{lddplugin.dll,mrtcplugin.dll,rtcplugin.dll,secplugin.dll} $Cur_dir/SDK/lib/win/sdkplugins
elif [ "$3" = "mac" ]; then
    cp ${unzip_dir}/{libimsdkapi.dylib,libservice.dylib} $Cur_dir/SDK/lib/mac/
	cp ${unzip_dir}/{libhttpServerplugin.dylib,liblddplugin.dylib,libmrtcplugin.dylib,librtcplugin.dylib,libsecplugin.dylib} $Cur_dir/SDK/lib/mac/sdkplugins
elif [ "$3" = "fangde" ]; then
	cp ${unzip_dir}/{libcommLib.so,libimsdkapi.so,libservice.so} $Cur_dir/SDK/lib/linux/fangde/
	cp ${unzip_dir}/{liblddplugin.so,libmrtcplugin.so,librtcplugin.so} $Cur_dir/SDK/lib/linux/fangde/sdkplugins
elif [ "$3" = "longxin" ]; then
	cp ${unzip_dir#*_}/{libcommLib.so,libimsdkapi.so,libservice.so} $Cur_dir/SDK/lib/linux/longxin/
	cp ${unzip_dir#*_}/{liblddplugin.so,libmrtcplugin.so,librtcplugin.so} $Cur_dir/SDK/lib/linux/longxin/sdkplugins
elif [ "$3" = "yinhe" ]; then
	cp ${unzip_dir#*_}/{libcommLib.so,libimsdkapi.so,libservice.so} $Cur_dir/SDK/lib/linux/yinhe/
	cp ${unzip_dir#*_}/{liblddplugin.so,libmrtcplugin.so,librtcplugin.so} $Cur_dir/SDK/lib/linux/yinhe/sdkplugins
elif [ "$3" = "zhaoxin" ]; then
	cp ${unzip_dir#*_}/{libcommLib.so,libimsdkapi.so,libservice.so} $Cur_dir/SDK/lib/linux/zhaoxin/
	cp ${unzip_dir#*_}/{liblddplugin.so,libmrtcplugin.so,librtcplugin.so} $Cur_dir/SDK/lib/linux/zhaoxin/sdkplugins
elif [ "$3" = "android" ]; then
	android_cplibs
fi

#删除zip解压后文件夹（mac的zip与其他结构不同）
if [ "$3" != "android" ]; then
	rm -rf $unzip_dir
else
	rm -rf ${unzip_dir#*_}
fi

#删除Cmake缓存文件
cd $Cur_dir/sdkUnitest/
rm -rf CMakeCache.txt cmake_install.cmake Makefile CMakeFiles/*


#运行脚本
if [ "$3" = "android" ]; then
	mkdir $Cur_dir/Bin/
	mkdir $Cur_dir/Bin/TestResult
    echo $Cur_dir
	cd $Cur_dir/
	start C:\\cygwin64\\bin\\mintty.exe E:/android-ndk-r13b-windows-x86_64/android-ndk-r13b/build/ndk-build.cmd -B -C  ./sdkUnitest/jni/
	ping -n 5 127.0.0.1
	ret=`tasklist | grep "mintty.exe" | wc -l`
	while [ $ret -eq 3 ]
	do
		ret=`tasklist | grep "mintty.exe" | wc -l`
		ping -n 5 127.0.0.1
	done
elif [ "$3" = "win" ]; then
	cp $Cur_dir/other/build.bat $Cur_dir/sdkUnitest/
	echo $Cur_dir
	cd $Cur_dir/sdkUnitest/
	./build.bat $4
	rm -f ./build.bat
	cp -r $Cur_dir/SDK/lib/win/* $Cur_dir/Bin/Release/
elif [ "$3" = "mac" ]; then
	cd $Cur_dir/sdkUnitest/
	cmake -DCMAKE_BUILD_TYPE=Release  -DPLAT_FORM=$3 -DBRANCH_NAME=$4 . 
	make
	cp -r $Cur_dir/SDK/lib/mac/* $Cur_dir/Bin/Release/
else
	cd $Cur_dir/sdkUnitest/
	cmake cmake -DCMAKE_BUILD_TYPE=Release  -DPLAT_FORM=$3 -DBRANCH_NAME=$4 .
	make
	cp -r $Cur_dir/SDK/lib/linux/$3/* $Cur_dir/Bin/Release/
fi

if [ "$3" = "android" ]; then
	android_cpotherDir
	android_cpxmlDir
	android_cpvstest
else
	cp $Cur_dir/other/* $Cur_dir/Bin/Release/
	mkdir $Cur_dir/Bin/Release/xmlconfig/
	cp $Cur_dir/xmlconfig/* $Cur_dir/Bin/Release/xmlconfig/
	mkdir $Cur_dir/Bin/Release/TestResult
fi






























