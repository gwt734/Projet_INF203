#!/bin/bash
#initialisation des deux premier termes
u0=$1
#premier termes calculé
cowsay $u0
sleep 1
u=$u0
j=0

#boucle jusqua atteindre le nombre de termes requis
while [ $j -lt $2 ]
do
    #initialisation de variables utiles
    u_tmp=$u
    i=0
    u=0
    chiffre_actuel=$(( $u_tmp % 10 ))
    nb_du_chiffre_actuel=0

    #boucle pour parcourir chaque chiffre du nombre
    while [ $u_tmp -gt 0 ]
    do
        #on verifie si le chiffre actuel est le meme que le precedent
        if [ $(($u_tmp % 10)) -eq $chiffre_actuel ]
        then
            #si oui, on incremente le nombre de fois ou le chiffre est present
            nb_du_chiffre_actuel=$(( $nb_du_chiffre_actuel + 1 ))
            # on se décale de 1 pour ne pas compter le meme chiffre
            u_tmp=$(( $u_tmp / 10 ))
        else
            #si non, on ajoute le nombre de fois ou le chiffre est present et le chiffre au terme suivant
            u=$(($u+($chiffre_actuel*10**($i*2)+$nb_du_chiffre_actuel*10**(1+($i*2)))))
            #on met a jour le chiffre actuel
            chiffre_actuel=$(( $u_tmp % 10 ))
            #on se décale de 1 pour ne pas compter le meme chiffre
            u_tmp=$(($u_tmp/10))
            nb_du_chiffre_actuel=1
            #on incremente le nombre de groupes de chiffres identiques qui sert a placer un chiffre et son nombre d'occurences au bon endroit
            i=$(( $i + 1 ))
        fi
    done
    #on ajoute le nombre de fois ou le chiffre est present et le chiffre au terme suivant
    u=$(($u+($chiffre_actuel*10**($i*2))+$nb_du_chiffre_actuel*10**(1+($i*2))))
    #on affiche le resultat
    cowsay $u
    sleep 1
    #on incremente le nombre de termes calculés
    j=$(( $j + 1 ))
done
#vache tire la langue
cowsay -T "U " meuh