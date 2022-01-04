@rem 
@rem 1分支名称

@rem 以前的用法
@rem set MSVC_PATH=%VS140COMNTOOLS%
@rem call "%MSVC_PATH%..\..\VC\vcvarsall.bat" x86

@rem 开始编译程序
@rem del CMakeCache.txt
@rem cmake -DCMAKE_BUILD_TYPE=Release  -DPLAT_FORM=win  -DBRANCH_NAME=tmp_branch_e2ee . -G "NMake Makefiles"
@rem nmake
cmake -P arcbuild.cmake -DPLATFORM=vs2015 -DARCH=x86 -DOS=$3 -DBUILD_TYPE=Release  -S . -B build
cmake --build build --config Release