#!/bin/bash
./pull_lib.sh /Users/clain/Desktop/workspace/SDK-For-Unitest-Mac $1 mac optimize_threadpool
install_name_tool -change @executable_path/../Frameworks/libimsdkapi.dylib /Users/clain/Desktop/workspace/SDK-For-Unitest-Mac/SDK/lib/mac/libimsdkapi.dylib /Users/clain/Desktop/workspace/SDK-For-Unitest-Mac/SDK/lib/mac/libservice.dylib
cd Bin/
cd xmlconfig
mv vrvconfig.xml config.xml
cd ..
lldb vstest