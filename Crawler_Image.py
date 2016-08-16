#!/usr/bin/python2.7
import urllib
import re
import os
import sys
#**************************************************************************************************************************
URL = "http://tieba.baidu.com"
for i in (re.findall( r'<img .*?src="(.*?)".*?>', urllib.urlopen(URL).read())):
    urllib.urlretrieve(i, i.split('/')[-1])
