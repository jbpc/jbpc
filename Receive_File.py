from socket import *
import struct
ADDR = ('192.168.0.100',8000)
BUFSIZE = 1024
FILEINFO_SIZE=struct.calcsize('128s32sI8s')
recvSock = socket(AF_INET,SOCK_STREAM)
recvSock.bind(ADDR)
recvSock.listen(True)
print "Receive: Waiting for connection"
conn,addr = recvSock.accept()
fhead = conn.recv(FILEINFO_SIZE)
filename,temp1,filesize,temp2=struct.unpack('128s32sI8s',fhead)
print filename,len(filename),type(filename)
print filesize
filename = "new_" + filename.strip('\00')
fp = open(filename,'wb')
restsize = filesize
print "Receive: Receiving file"
while 1:
    if restsize > BUFSIZE:
        filedata = conn.recv(BUFSIZE)
    else:
        filedata = conn.recv(restsize)
    if not filedata: break
    fp.write(filedata)
    restsize = restsize-len(filedata)
    if restsize == 0:
        break
print "Receive: Done"
fp.close()
conn.close()
recvSock.close()