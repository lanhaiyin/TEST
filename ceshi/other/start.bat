@rem 开始测试vrv服务器
@echo off
if not exist TestResult (
 mkdir TestResult
)
SET SourceFile=vstest.exe
	if exist %SourceFile% (
	rename .\xmlconfig\vrvconfig.xml config.xml
	vstest.exe
	taskkill /f /im  vstest.exe
	start /wait python draw.py
	start /wait python gtest_parser.py test_detail.xml vrv
	del cpu.png
	del mem.png
	del thread.png
	del rw_count.png
	del disk.png
	del num_handles.png
	del process_monitor_vstest.exe.csv
	del test_detail.xml
	rename .\xmlconfig\config.xml vrvconfig.xml


	@rem 开始测试bxy服务器
	rename .\xmlconfig\bxyconfig.xml config.xml
	vstest.exe
	taskkill /f /im  vstest.exe
	start /wait python draw.py
	start /wait python gtest_parser.py test_detail.xml bxy
	del cpu.png
	del mem.png
	del thread.png
	del rw_count.png
	del disk.png
	del num_handles.png
	del process_monitor_vstest.exe.csv
	del test_detail.xml
	rename .\xmlconfig\config.xml bxyconfig.xml

	@rem 开始测试im服务器
	rename .\xmlconfig\imconfig.xml config.xml
	vstest.exe
	taskkill /f /im  vstest.exe
    start /wait python draw.py
	start /wait python gtest_parser.py test_detail.xml im
	del cpu.png
	del mem.png
	del thread.png
	del rw_count.png
	del disk.png
	del num_handles.png
	del process_monitor_vstest.exe.csv
	del test_detail.xml
	rename .\xmlconfig\config.xml imconfig.xml
) else (
	echo %SourceFile% is not exist!
)
@rem copy *.pdb TestResult /Y
exit 0