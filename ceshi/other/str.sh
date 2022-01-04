sleep 3
PROC_NAME=vstest
platfrom=$1
#cd /root/workspace/SDK-For-Unitest-fangde/Bin/Release
ProcNumber=`ps -ef|grep -w $PROC_NAME|grep -v grep|wc -l`
if [ $ProcNumber -le 0 ];then
   echo "vstest is not run"
else
   echo "vstest is  running.."
   python ./monitor.py vstest $platfrom
fi
