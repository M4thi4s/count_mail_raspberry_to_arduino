#!/bin/bash
#exec >&/dev/null
sudo wget 'https://USERNAME:MDP@mail.google.com/mail/feed/atom' 2> /dev/null  #do a first request for show a first bug page 
while true;do  #this program doesn't stop
sudo wget 'https://USERNAME:MDP@mail.google.com/mail/feed/atom' 2> /dev/null  #recover the source code
nombre_deux_foix=$(grep -o entry atom | wc -l) #count the repetion of the iteration
nombre=0
((resultat=$nombre_deux_foix/2))
if [ $resultat == $nombre ]
then
	echo -e "no mail"
        echo 0 > nb_mail.txt
else
	echo -e "you've \033[31m$resultat\033[00m new mail"
	echo $resultat > nb_mail.txt
fi
sudo rm atom
python communication_serial.py
sleep 1
done
