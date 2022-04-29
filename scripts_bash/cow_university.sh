#!/bin/bash
j=1
cowsay 2
sleep 1
while [ $j -le $1 ]
do
if [ $j -gt 1 ]
then
estPremier=1
for i in $(eval echo {2..$(expr 1 + $(expr $j / 2 ))})
do

if [ $(expr $j % $i) -eq 0 ]
then
estPremier=0
fi
done
fi
if [[ $estPremier -eq 1 ]]
then
cowsay $j
sleep 1
fi
j=$(expr $j + 1)
done
cowsay -T "U " meuh