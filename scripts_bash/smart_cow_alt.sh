#!/bin/bash
resultat=$(($1))
cowsay -e $resultat "$1"
sleep 1
cowsay -T "U " meuh