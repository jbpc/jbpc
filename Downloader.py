#!/usr/bin/python2.7
import  urllib
import  os
from    os.path    import join, getsize
#**************************************************************************************************************************
# Configuration
URL             = "http://ftp.sjtu.edu.cn/centos/7/isos/x86_64/CentOS-7-x86_64-Everything-1511.iso"
File_Name       = "CentOS_7_x86_64_Everything_1511.iso"
File_Directory  = "./"
#**************************************************************************************************************************
# Download_Status
def Download_Status(a, b ,Total_Size):
    print "Received: %d\nTotal:    %d"%(os.path.getsize(File_Name), Total_Size)
#**************************************************************************************************************************
# Download
Destination = os.path.join(File_Directory, File_Name)
urllib.urlretrieve(URL, Destination, Download_Status)
