#!/bin/bash

# Couleurs pour l'affichage (correction : ajout du guillemet fermant)
BLUE='\033[0;34m'
NC='\033[0m' # No Color

for i in {1..8}; do
    echo -e "${BLUE}\n----------------- Module0$i --------------${NC}"

    # Vérifie que le répertoire existe avant de s'y déplacer
    if [ -d "./module0$i" ]; then
        (cd "./module0$i" && ../otherFile/sriptTest.sh) || {
            echo -e "\033[0;31mErreur : Impossible d'exécuter le test dans module0$i\033[0m"
        }
    else
        echo -e "\033[0;31mErreur : Le répertoire module0$i n'existe pas\033[0m"
    fi
done
