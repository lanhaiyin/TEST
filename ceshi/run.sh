#!/bin/bash
Cur_dir=$1
cd $Cur_dir/Bin/xmlconfig/
mv vrvconfig.xml config.xml
cd $Cur_dir/Bin/
chmod -R 777 str.sh
chmod 777 libHkApi.so
if [ "$2" = "mac" ]; then
export DYLD_LIBRARY_PATH=./
./str.sh mac &
fi
if [ "$2" = "fangde" ]; then
./str.sh fangde &
unset LD_PRELOAD
#export LD_PRELOAD=$Cur_dir/Bin/libHkApi.so
fi
./vstest
sleep 5
python draw.py
python ./gtest_parser.py test_detail.xml vrv
rm cpu.png
rm mem.png
rm thread.png
rm disk.png
rm rw_count.png
rm process_monitor_vstest.csv
rm test_detail.xml
cd $Cur_dir/Bin/xmlconfig/
mv config.xml vrvconfig.xml


mv bxyconfig.xml config.xml
cd $Cur_dir/Bin/
if [ "$2" = "mac" ]; then
./str.sh mac &
fi
if [ "$2" = "fangde" ]; then
./str.sh fangde &
#export LD_PRELOAD=$Cur_dir/Bin/libHkApi.so
fi
./vstest
#unset LD_PRELOAD
sleep 5
python draw.py
python ./gtest_parser.py test_detail.xml bxy
rm cpu.png
rm mem.png
rm thread.png
rm disk.png
rm rw_count.png
rm process_monitor_vstest.csv
rm test_detail.xml
cd $Cur_dir/Bin/xmlconfig/
mv config.xml bxyconfig.xml


mv imconfig.xml config.xml
cd $Cur_dir/Bin/
if [ "$2" = "mac" ]; then
./str.sh mac &
fi
if [ "$2" = "fangde" ]; then
./str.sh fangde &
export LD_PRELOAD=$Cur_dir/Bin/libHkApi.so
fi
./vstest
sleep 5
unset LD_PRELOAD
python draw.py
python ./gtest_parser.py test_detail.xml im
rm cpu.png
rm mem.png
rm thread.png
rm disk.png
rm rw_count.png
rm process_monitor_vstest.csv
rm test_detail.xml
cd $Cur_dir/Bin/xmlconfig/
mv config.xml imconfig.xml
