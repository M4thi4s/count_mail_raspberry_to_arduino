#!/usr/bin/env python
# -*- coding: utf-8 -*-

import serial
import time
ser = serial.Serial('/dev/ttyACM0', 9600) #you need to plug the rpi for use this program, if a bug is signaled in this line you need to change the file path
time.sleep(1);    #reboot arduino
mon_fichier = open("nb_mail.txt", "r")
contenu = mon_fichier.read(1)
ser.write(str(contenu)) #send the number of mail to the rpi
print ("send to arduino")
