#!/bin/bash
for i in $(eval echo {1..$1})
do
cowsay $i
sleep 1
done
cowsay -T \U meuh
