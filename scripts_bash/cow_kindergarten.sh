#!/bin/bash
#boucle qui sera répétée 10 fois
for i in {1..10}
do
#La vache dira la valeur que i aura
cowsay $i
#pause de 1 seconde
sleep 1
done
#la vache tire la langue
cowsay -T "U " meuh
