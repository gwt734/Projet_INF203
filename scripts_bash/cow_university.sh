#!/bin/bash
if [ $1 -gt 1 ]
then
for i in $(eval echo {2..$(expr 1 + $(expr $1 / 2 ))})
do
if [ $(expr $1 % $i) -ne 0 ]
then
cowsay $i
sleep 1
fi
done
fi
cowsay -T \U meuh