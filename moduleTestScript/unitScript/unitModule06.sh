#!/bin/bash

# Couleurs pour une meilleure lisibilité
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Nom du programme
PROGRAM="./convert"

# Vérifie si le programme existe et est exécutable
if [ ! -x "$PROGRAM" ]; then
    echo -e "${RED}Erreur : Le programme '$PROGRAM' n'existe pas ou n'est pas exécutable.${NC}"
    echo -e "${YELLOW}Compilation en cours...${NC}"
    make
    if [ ! -x "$PROGRAM" ]; then
        echo -e "${RED}Erreur : La compilation a échoué.\${NC}"
        exit 1
    fi
fi

# Fonction pour exécuter un test
run_test() {
    local input="\$1"
    local expected="\$2"
    local description="$3"

    echo -e "${YELLOW}Test : $description${NC}"
    echo -e "Entrée : \${GREEN}$input${NC}"

    # Exécute le programme et capture la sortie
    output=\$(\$PROGRAM "\$input" 2>&1)
    echo -e "Sortie :\n\$output"

    # Vérifie si la sortie correspond à l'attendu (optionnel)
    if [ -n "\$expected" ]; then
        if [[ "\$output" == *"$expected"* ]]; then
            echo -e "${GREEN}✅ Test réussi !\${NC}\n"
        else
            echo -e "\${RED}❌ Test échoué !\${NC}\n"
        fi
    else
        echo -e "\${GREEN}✅ Test exécuté (vérification manuelle requise).\${NC}\n"
    fi
}

# Tests pour les char
run_test "'a'" "char: 'a'" "Littéral char simple"
run_test "' '" "char: ' '" "Littéral char espace"
run_test "'\n'" "char: Non displayable" "Littéral char non affichable"

# Tests pour les int
run_test "0" "int: 0" "Littéral int zéro"
run_test "42" "int: 42" "Littéral int positif"
run_test "-42" "int: -42" "Littéral int négatif"
run_test "2147483647" "int: 2147483647" "Littéral int max"
run_test "-2147483648" "int: -2147483648" "Littéral int min"
run_test "100000000000000000000000000000000000000000000000000000000" "int: overflow" "Littéral int trop grand"

# Tests pour les float
run_test "0.0f" "float: 0.0f" "Littéral float zéro"
run_test "42.0f" "float: 42.0f" "Littéral float positif"
run_test "-42.0f" "float: -42.0f" "Littéral float négatif"
run_test "3.14f" "float: 3.14f" "Littéral float avec décimales"
run_test "nanf" "float: nanf" "Littéral float nan"
run_test "+inff" "float: +inff" "Littéral float +inf"
run_test "-inff" "float: -inff" "Littéral float -inf"

# Tests pour les double
run_test "0.0" "double: 0.0" "Littéral double zéro"
run_test "42.0" "double: 42.0" "Littéral double positif"
run_test "-42.0" "double: -42.0" "Littéral double négatif"
run_test "3.14" "double: 3.14" "Littéral double avec décimales"
run_test "nan" "double: nan" "Littéral double nan"
run_test "+inf" "double: +inf" "Littéral double +inf"
run_test "-inf" "double: -inf" "Littéral double -inf"

# Tests pour les cas invalides
run_test "abc" "impossible" "Chaîne invalide"
run_test "42.0.0" "impossible" "Double point décimal"
run_test "42f" "impossible" "Float sans point décimal"
run_test "'abcd'" "impossible" "Char invalide"

# Tests supplémentaires
run_test "123.456f" "float: 123.4f" "Float avec plusieurs décimales"
run_test "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999

