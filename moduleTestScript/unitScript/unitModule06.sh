#!/bin/bash

# Couleurs pour une meilleure lisibilité
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Nom du programme
PROGRAM="./ex00"

# Vérifie si le programme existe et est exécutable
if [ ! -x $PROGRAM ]; then
    echo -e "${RED}Erreur : Le programme '$PROGRAM' n'existe pas ou n'est pas exécutable.${NC}"
    echo -e "${YELLOW}Compilation en cours...${NC}"
    make ex00
    if [ ! -x "$PROGRAM" ]; then
        echo -e "${RED}Erreur : La compilation a échoué.\${NC}"
        exit 1
    fi
fi

# Fonction pour exécuter un test
run_test() {
    local input="$1"
    local description="$2"

    echo -e "${YELLOW}Test : $description${NC}"
    echo -e "${GREEN}Entrée : $input${NC}"

    # Exécute le programme et capture la sortie
    output=$($PROGRAM $input 2>&1)
    echo -e "Sortie :"
    echo "$output"
    echo -e "${GREEN}✅ Test exécuté (vérification manuelle requise).\${NC}"
    echo "----------------------------------------"
}

# Tests pour les char
run_test "a" "Littéral char simple"
run_test " " "Littéral char espace"
run_test "\n" "Littéral char non affichable"

# Tests pour les int
run_test "0" "Littéral int zéro"
run_test "42" "Littéral int positif"
run_test "-42" "Littéral int négatif"
run_test "2147483647" "Littéral int max"
run_test "-2147483648" "Littéral int min"
run_test "100000000000000000000000000000000000000000000000000000000" "Littéral int trop grand"

# Tests pour les float
run_test "0.0f" "Littéral float zéro"
run_test "42.0f" "Littéral float positif"
run_test "-42.0f" "Littéral float négatif"
run_test "3.14f" "Littéral float avec décimales"
run_test "nanf" "Littéral float nan"
run_test "+inff" "Littéral float +inf"
run_test "-inff" "Littéral float -inf"

# Tests pour les double
run_test "0.0" "Littéral double zéro"
run_test "42.0" "Littéral double positif"
run_test "-42.0" "Littéral double négatif"
run_test "3.14" "Littéral double avec décimales"
run_test "nan" "Littéral double nan"
run_test "+inf" "Littéral double +inf"
run_test "-inf" "Littéral double -inf"

# Tests pour les cas invalides
run_test "abc" "Chaîne invalide"
run_test "42.0.0" "Double point décimal"
run_test "42f" "Float sans point décimal"
run_test "'abcd'" "Char invalide"

# Tests supplémentaires
run_test "123.456f" "Float avec plusieurs décimales"
run_test "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999

