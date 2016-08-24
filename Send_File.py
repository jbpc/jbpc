from socket import *
import os
import struct
Address         = ('192.168.0.100',8000)
BUFSIZE         = 1024
filename        = 'select.c'
FILEINFO_SIZE   = struct.calcsize('128s32sI8s')
Socket          = socket(AF_INET,SOCK_STREAM)
Socket.connect(Address)
fhead           = struct.pack('128s11I',filename,0,0,0,0,0,0,0,0,os.stat(filename).st_size,0,0)
Socket.send(fhead)
File            = open(filename,'rb')
while 1:
    filedata = File.read(BUFSIZE)
    if not filedata: break
    Socket.send(filedata)
print "Send: Done"
File.close()
Socket.close()