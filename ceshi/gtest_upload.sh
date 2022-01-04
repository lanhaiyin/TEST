#$1 work_dir $2 git_count  $3 system
Cur_dir=$1
if [ "$3" != "android" ];then
	cd $Cur_dir/Bin/public/coreDump
	cp *.dmp $Cur_dir/Bin/TestResult/
	if [ $? -eq 0 ]; then
		 echo "check dumpfile,load log!!!!"
		 cp -r $Cur_dir/Bin/*.pdb $Cur_dir/Bin/TestResult/ /Y
		 if [ "$3" = "mac" ]; then
			cd $Cur_dir/Bin/public/
			log_dir=`ls sdklog_*`
			cd $Cur_dir/Bin/TestResult/
			mkdir $log_dir
			cp -r $Cur_dir/Bin/log/public/sdklog_*/ $Cur_dir/Bin/TestResult/$log_dir/
		 else
		    if [ "$3" = "win" ]; then
			   cp -r $Cur_dir/Bin/log $Cur_dir/Bin/TestResult/
			else
			   cp -r $Cur_dir/Bin/public/sdklog_*/ $Cur_dir/Bin/TestResult/
			fi
		 fi
	else
		 echo "no dump"
	fi
else
	cp $Cur_dir/other/{gtest_parser.py,gtest_template.html} $Cur_dir/Bin/
	cd $Cur_dir/Bin/
	python ./gtest_parser.py bxy_test_detail.xml bxy
	python ./gtest_parser.py vrv_test_detail.xml vrv
	python ./gtest_parser.py im_test_detail.xml im
fi

cd $Cur_dir/Bin/
if [ "$3" = "fangde" ];then
cp vstest-* TestResult/
fi
tar -czvf TestResult.tar.gz TestResult/
if [ "$3" != "win" ] && [ "$3" != "mac" ]; then
chmod 777 TestResult.tar.gz
fi
finalZipName=$3_sdkunitest_$2
mv TestResult.tar.gz  $finalZipName.tar.gz

if [ "$3" != "win" ] && [ "$3" != "mac" ]; then
chmod 777 $finalZipName.tar.gz
fi

FTP_upload_dir=asec/sdk/sdk_unitest/

ftp -v -n 192.168.139.2<<EOF
user asec asec
binary
passive
cd $FTP_upload_dir
prompt
put $finalZipName.tar.gz
bye
EOF
echo "gtest_output upload finish!"