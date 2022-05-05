#!/bin/bash
#boucle qui sera répétée n fois
for i in $(eval echo {1..$1})
do
#La vache dira la valeur que i aura
cowsay $i
#pause de 1 seconde
sleep 1
done
#la vache tire la langue
cowsay -T "U " meuh
