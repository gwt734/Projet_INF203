#!/bin/bash
j=1
#prononce le premier nombre premier
cowsay 2
sleep 1
#boucle pour aller jusqu a la valeur en argument
while [ $j -le $1 ]
do
if [ $j -gt 1 ]
then
estPremier=1 
for i in $(eval echo {2..$(expr 1 + $(expr $j / 2 ))})
do
#condition pour être un nombre premier
if [ $(expr $j % $i) -eq 0 ]
then
estPremier=0
fi
done
fi
#affichage du nombre si il est premier
if [[ $estPremier -eq 1 ]]
then
cowsay $j
sleep 1
fi
#itération pour ne pas etre dans une boucle infinie
j=$(expr $j + 1)
done
cowsay -T "U " meuh