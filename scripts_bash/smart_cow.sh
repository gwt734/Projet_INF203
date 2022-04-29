#!/bin/bash
n1=$(echo $1 | cut -d ' ' -f 1 )
n2=$(echo $1 | cut -d ' ' -f 3)
operateur=$(echo $1 | cut -d ' ' -f 2)

echo "Operateur: $operateur"
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


cowsay -e $resultat $1
sleep 1
cowsay -T \U meuh
 