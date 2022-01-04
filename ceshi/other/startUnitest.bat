taskkill /f /im vstest.console.exe
taskkill /f /im vstest.executionengine.x86.exe
del 
rename .\xmlconfig\vrvconfig.xml config.xml
@rem 处理小时小于10点 出现空格的问题
set h=%time:~0,2%
set h=%h: =0%
set trxName=vrv_%date:~0,4%-%date:~5,2%-%date:~8,2%_%h%-%time:~3,2%-%time:~6,2%.trx
echo %trxName%
"%VS140COMNTOOLS%\..\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe"  sdkUnitest.dll /logger:trx  /InIsolation
cd TestResults
ren *.trx %trxName%
cd ..
echo %trxName%
TrxerConsole.exe ./TestResults/%trxName%
del .\TestResults\%trxName%
rename .\xmlconfig\config.xml vrvconfig.xml
rename .\xmlconfig\bxyconfig.xml config.xml
@rem 处理小时小于10点 出现空格的问题
set h=%time:~0,2%
set h=%h: =0%
set trxName=bxy_%date:~0,4%-%date:~5,2%-%date:~8,2%_%h%-%time:~3,2%-%time:~6,2%.trx
echo %trxName%
"%VS140COMNTOOLS%\..\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe"  sdkUnitest.dll /logger:trx  /InIsolation
cd TestResults
ren *.trx %trxName%
cd ..
echo %trxName%
TrxerConsole.exe ./TestResults/%trxName%
del .\TestResults\%trxName%
rename .\xmlconfig\config.xml bxyconfig.xml

@rem rename .\xmlconfig\imconfig.xml config.xml
@rem 处理小时小于10点 出现空格的问题
@rem set h=%time:~0,2%
@rem set h=%h: =0%
@rem set trxName=im_%date:~0,4%-%date:~5,2%-%date:~8,2%_%h%-%time:~3,2%-%time:~6,2%.trx
@rem echo %trxName%
@rem "%VS140COMNTOOLS%\..\IDE\CommonExtensions\Microsoft\TestWindow\vstest.console.exe"  sdkUnitest.dll /logger:trx  /InIsolation
@rem cd TestResults
@rem ren *.trx %trxName%
@rem cd ..
@rem echo %trxName%
@rem TrxerConsole.exe ./TestResults/%trxName%
@rem del .\TestResults\%trxName%
@rem rename .\xmlconfig\config.xml imconfig.xml

cd ../..
cd other
unitTool.exe
