#!/usr/bin/python2.7
import smtplib
import string
import os
import sys
#**************************************************************************************************************************
# Account
Host        = "p45-smtp.mail.me.com"
From        = "johnblackphone@icloud.com"
Password    = "Nocountryfor3515*"
To          = "johnblackphone@icloud.com"
#**************************************************************************************************************************
# Content
Subject = "Hi john"
Text    = '''
This is just a test.
You can just ignore it.
'''
#File    = open("/root/03_C/00_Trick/03_Module/Journal_Status/01_Journal_Status.h", "r")
Content = string.join((
            "From:      %s"%From,
            "To:        %s"%To,
            "Subject:   %s"%Subject,
            Text
            #File.read()
            ), "\r\n")
#File.close()
#**************************************************************************************************************************
try:
    Send = smtplib.SMTP()
    Send.connect(Host, "587")
    Send.starttls()
    Send.login(From, Password)
    Send.sendmail(From, [To], Content)
    Send.quit()
    print "Success"
except Exception, e:
    print "Error: " + str(e)
