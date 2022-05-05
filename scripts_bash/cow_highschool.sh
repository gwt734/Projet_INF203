#!/bin/bash
#boucle répétée n fois 
for i in $(eval echo {1..$1})
do
#la vache prononcera la multiplication des deux mêmes chiffres donc le carré
cowsay $(expr $i \* $i)
#pause de 1 seconde
sleep 1
done
#vache qui tire la langue
cowsay -T "U " meuh
