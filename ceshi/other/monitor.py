#!/usr/bin/python 
#-*- encoding:UTF-8 -*-
import os
import sys
import string 
import psutil
import time

import collections
import argparse
# 使用psutil来判断
import psutil

def proc_exist(process_name):
    pl = psutil.pids()
    for pid in pl:
        try:
            if psutil.Process(pid).name() == process_name:
                return pid
        except:
            print("get process name with pid failed!!!")
            
def get_pid(name,platfrom):
    '''
     作用：根据进程名获取进程pid
    '''
    pids = psutil.process_iter()
    print("[" + name + "]'s pid is:")
    vspid = 0
    for pid in pids:
        if(pid.name() == name):
            print(pid.pid)
            vspid = pid.pid
        p = psutil.Process(proc_exist(name))
    # monitor process and write data to file
    interval = 5 # polling seconds
    with open("process_monitor_" + p.name() +".csv", "a+") as f:
        if(platfrom == 'win'):
            f.write("time,cpu,men_used,num_handles,cpu_time,,,,ctx_num,,read_count,,write_count,,thread_num,net,,,,,,,,disk_percent\n")
        elif(platfrom == 'mac'):
            f.write("time,cpu,men_used,cpu_time,,,,ctx_num,,read_count,write_count,thread_num,net,,,,,,,,disk_percent\n")
        elif(platfrom == 'fangde'):
            f.write("time,cpu,men_used,cpu_time,,ctx_num,,,,,read_count,,write_count,,thread_num,net,,,,,,,,disk_percent\n")
        else:
            print("no find other platfrom")
        while (proc_exist(name)):
            #current_time = time.strftime('%H:%M:%S',time.localtime(time.time()))
            cpu_percent = p.cpu_percent()
            men_used = p.memory_info().rss
            men_used = float(men_used)/1024/1024
            total = psutil.virtual_memory().total
            print('total: %.2f(M)' % (float(total)/1024/1024))
            #print('percent: %.2f%%'%(100*float(men_used)/total))
            print('%.2f(M)' % (men_used))
            mem_percent = p.memory_percent()
            print('percent: %.2f%%' %(mem_percent))
            if(platfrom == 'win'):
                num_handles = p.num_handles()
                print('num_handles: %d' %(num_handles))
            cpu_time = p.cpu_times()
            ctx_num =p.num_ctx_switches()
            thread_num = p.num_threads()
            #memory_info = p.memory_info()
            if(platfrom == 'win' or platfrom == 'fangde'):
                current_time = time.strftime('%H:%M:%S',time.localtime(time.time()))
                io_counters = str(p.io_counters())
                read_count = io_counters.split('=')[1].split(' ')[0]
                write_count = io_counters.split('=')[2].split(' ')[0]
            else:
                current_time = time.strftime('%H%M%S',time.localtime(time.time()))
                io_counters = str(psutil.disk_io_counters())
                read_count = io_counters.split('=')[1].split('L')[0]
                write_count = io_counters.split('=')[2].split('L')[0]
            net = psutil.net_io_counters()
            disk = str(psutil.disk_usage('/'))
            disk = disk.split('=')[-1].split(')')[0]
            #disk_io = psutil.disk_io_counters()
            if(platfrom == 'win'):
                line = current_time + ',' + str(cpu_percent) + ',' + str(men_used) + ',' + str(num_handles) + ',' + str(cpu_time) + ',' + str(ctx_num) + ',' + str(read_count) + ',' + str(write_count) + ',' + str(thread_num) + ',' + str(net) + ',' + str(disk)
            else:
                line = current_time + ',' + str(cpu_percent) + ',' + str(men_used) + ',' + str(cpu_time) + ',' + str(ctx_num) + ',' + str(read_count) + ',' + str(write_count) + ',' + str(thread_num) + ',' + str(net) + ',' + str(disk)
            print (line)
            f.write(line + "\n")
            f.flush()
            time.sleep(interval)
    csvFile.close()      
    
if __name__ == "__main__":
    get_pid(sys.argv[1],sys.argv[2])
