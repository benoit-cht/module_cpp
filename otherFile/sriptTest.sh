#!/bin/bash

# Couleurs pour l'affichage
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Fonction pour compiler et tester un exercice
test_exercice() {
    local ex_dir=$1
    local binary_name=$ex_dir  # Le binaire a le même nom que le dossier (ex00, ex01, etc.)
    echo -e "${YELLOW}|--Compilation de l'exercice $ex_dir ${NC}"
    make -C "$ex_dir" > /tmp/make_output.txt 2>&1
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}| |-Compilation $ex_dir[OK: ✅] ${NC}"
    else
        echo -e "${RED}Échec de la compilation pour $ex_dir${NC}"
        cat /tmp/make_output.txt
        return 1
    fi

    # Vérifie si le binaire existe
    if [ -f "$ex_dir/$binary_name" ]; then
        echo -e "${YELLOW}|--Exécution de valgrind pour $binary_name ${NC}"
        valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes "$ex_dir/$binary_name" > /tmp/valgrind_output.txt 2>&1
        if grep -q "All heap blocks were freed" /tmp/valgrind_output.txt; then
            echo -e "${GREEN}| |-Aucune fuite mémoire détectée pour $binary_name [OK: ✅] ${NC}"
        else
            echo -e "${RED}Fuites mémoire détectées pour $binary_name :${NC}"
            cat /tmp/valgrind_output.txt
        fi
    else
        echo -e "${RED}Le binaire '$binary_name' n'existe pas dans $ex_dir${NC}"
    fi
}

# Boucle sur tous les exercices (ex00, ex01, etc.)
for ex in ex??; do
    if [ -d "$ex" ]; then
        test_exercice "$ex"
        # Nettoyage individuel pour chaque exercice
        echo -e "${YELLOW}|-Nettoyage de $ex ${NC}"
        make fclean -C "$ex" > /dev/null 2>&1
        echo -e "${GREEN}|--Nettoyage terminé pour $ex${NC}"
    fi
done

# Suppression des fichiers temporaires
rm -f /tmp/make_output.txt /tmp/valgrind_output.txt
