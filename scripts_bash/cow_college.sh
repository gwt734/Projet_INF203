#!/bin/bash
u0=0
u1=1
echo $u0
cowsay zero
sleep 1
cowsay $u1
sleep 1
un1=$u1
un2=$u0
u=$(expr $un1 + $un2)
while [ $u -le $1 ]
do
cowsay $u
sleep 1
un2=$un1
un1=$u
u=$(expr $un1 + $un2)
done
cowsay -T "U " meuh
