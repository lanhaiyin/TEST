#coding:utf-8
import csv
import matplotlib.pyplot as plt
import matplotlib.ticker as mticker
import pandas as pd
import sys
import importlib
import os
if os.name != 'nt':
    importlib.reload(sys)
    #reload(sys)
    #sys.setdefaultencoding('utf-8')
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['font.family']='sans-serif'
plt.rcParams['axes.unicode_minus'] = False
if os.name != 'nt':
    data = pd.read_csv("process_monitor_vstest.csv", encoding="utf_8_sig")
    fields = ["cpu", "men_used","thread_num","read_count","write_count","disk_percent"]
else:
    data = pd.read_csv("process_monitor_vstest.exe.csv", encoding="utf_8_sig")
    fields = ["cpu", "men_used","num_handles","thread_num","read_count","write_count","disk_percent"]
ydata = []
xdata = data.loc[:,'time']
#plt.title(u"sdk",size=10)   #设置表名为“表名”
#plt.xlabel(u'时间',size=10)   #设置x轴名为“x轴名”
#plt.ylabel(u'cpu%',size=10)   #设置y轴名为“y轴名”
for field in fields:
    if field == "cpu":
        ydata = data.loc[:,'cpu']
        print(ydata)
        plt.ticklabel_format(useOffset=False,axis = 'x')
        plt.ylabel('cpu(%)')
        plt.xlabel('date')
        plt.gcf().autofmt_xdate()  # 自动旋转日期标记
        plt.plot(xdata,ydata,'bo-',color='#1494da',linewidth=1.5,linestyle='-',label=u'cpu_percent')
        plt.legend()
        plt.draw()
        plt.savefig('cpu.png')
        plt.close()
    elif field == "men_used":
        ydata = data.loc[:,'men_used']
        plt.ticklabel_format(useOffset=False,axis = 'x')
        plt.ylabel('men_used(M)')
        plt.xlabel('date')
        plt.gcf().autofmt_xdate()  # 自动旋转日期标记
        plt.plot(xdata,ydata,'bo-',color='#1494da',linewidth=1.5,linestyle='-',label=u'mem(M)')
        plt.legend()
        plt.draw()
        plt.savefig('mem.png')
        plt.close()
    elif field == "thread_num":
        ydata = data.loc[:,'thread_num']
        plt.ticklabel_format(useOffset=False,axis = 'x')
        plt.ylabel('thread_num')
        plt.xlabel('date')
        plt.gcf().autofmt_xdate()  # 自动旋转日期标记
        plt.plot(xdata,ydata,'bo-',color='#1494da',linewidth=1.5,linestyle='-',label=u'thread_num')
        plt.legend()
        plt.draw()
        plt.savefig('thread.png')
        plt.close()
    elif field == "read_count":
        ydata1 = data.loc[:,'read_count']
        plt.ticklabel_format(useOffset=False,axis = 'x')
        ydata2 = data.loc[:,'write_count']
        plt.ylabel('read_count')
        plt.xlabel('date')
        plt.gcf().autofmt_xdate()  # 自动旋转日期标记
        plt.plot(xdata,ydata1,'bo-',color='#eb2d55',linewidth=1.5, linestyle='-',label=u'io_read_count')
        plt.plot(xdata,ydata2,'bo-',color='#1494da',linewidth=1.5, linestyle='-',label=u'io_write_count')
        plt.legend()
        plt.draw()
        plt.savefig('rw_count.png')
        plt.close()
    elif field == "num_handles":
        ydata = data.loc[:,'num_handles']
        plt.ylabel('num_handles')
        plt.xlabel('日期')
        plt.gcf().autofmt_xdate()  # 自动旋转日期标记
        plt.plot(xdata,ydata,'bo-',color='#1494da',linewidth=1.5,linestyle='-',label=u'句柄数')
        plt.legend()
        plt.draw()
        plt.savefig('num_handles.png')
        plt.close()
    elif field == "disk_percent":
        ydata = data.loc[:,'disk_percent']
        plt.ticklabel_format(useOffset=False,axis = 'x')
        plt.ylabel('disk_percent(%)')
        plt.xlabel('date')
        plt.gcf().autofmt_xdate()  # 自动旋转日期标记
        plt.plot(xdata,ydata,'bo-',color='#1494da',linewidth=1.5,linestyle='-',label=u'disk_percent')
        plt.legend()
        plt.draw()
        plt.savefig('disk.png')
        plt.close()
    else:
        print("hello")
#ydata = data.loc[:,'cpu%']
#plt.xlabel('日期')
#plt.ylabel('人数')
#plt.gcf().autofmt_xdate()  # 自动旋转日期标记
#plt.show()
#xdata = data.loc[:,'time']   #将csv中列名为“列名1”的列存入xdata数组中
							#如果ix报错请将其改为loc
#ydata = data.loc[:,'cpu%']   #将csv中列名为“列名2”的列存入ydata数组中
#plt.plot(xdata,ydata,'bo-',label=u'cpu百分比',linewidth=3)
#plt.title(u"sdk",size=10)   #设置表名为“表名”
#plt.xlabel(u'时间',size=10)   #设置x轴名为“x轴名”
#plt.ylabel(u'cpu%',size=10)   #设置y轴名为“y轴名”
#plt.gcf().autofmt_xdate()
#plt.savefig('cpu.pdf')
#plt.show()
