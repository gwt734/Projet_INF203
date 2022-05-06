#!/bin/bash
#on decoupe chaque partie de l agument pour récuperer les deux chiffres et l opérateur
n1=$(echo $1 | cut -d ' ' -f1)
n2=$(echo $1 | cut -d ' ' -f3)
operateur=$(echo $1 | cut -d ' ' -f2)

#en fonction de l operateur on adapte le calul a faire
if [ $operateur = "+" ]
then
echo "+"
resultat=$(expr $n1 + $n2)
elif [ $operateur = "-" ]
then
echo "-"
resultat=$(expr $n1 - $n2)
elif [ "$operateur" = "*" ]
then
echo "*"
resultat=$(expr $n1 \* $n2)
elif [ $operateur = "/" ]
then
echo "/"
resultat=$(expr $n1 / $n2)
elif [ $operateur = "%" ]
then
echo "%"
resultat=$(expr $n1 % $n2)
fi

#on met le résultat dans ses yeux et le calul dans sa bulle 
cowsay -e $resultat $1
sleep 1
cowsay -T \U meuh
 