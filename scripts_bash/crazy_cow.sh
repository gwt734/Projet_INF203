#!/bin/bash
#initialisation des deux premier termes
u0=1
#premier termes calculé
cowsay $u0
sleep 1
u=u0
u_tmp=u
nb_de_1=0
nb_de_2=0
nb_de_3=0
i=10
while [ u/10 -gt 0 ]
do
    #calcul du nombre de 1
    if 
#calcul des autres termes jusqu a la fin
while [ $u -le $1 ]
do
cowsay $u
sleep 1
un2=$un1
un1=$u
u=$(expr $un1 + $un2)
done
#vache tire la langue
cowsay -T "U " meuh