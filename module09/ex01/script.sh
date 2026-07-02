#!/bin/bash

# =============================================================================
# Configuration des couleurs
# =============================================================================
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# =============================================================================
# Fonction pour exécuter un test et vérifier son succès
# =============================================================================
run_test() {
  local test_name=$1
  local input=$2
  local expected_output=$3
  echo -n "🔹 ${test_name}... "

  # Exécute la commande et capture la sortie (stdout + stderr)
  output=$(./RPN "$input" 2>&1 | tr -d '\n' | xargs)
  exit_code=$?

  # Normalise la sortie attendue
  normalized_expected=$(echo "$expected_output" | tr -d '\n' | xargs)

  # Vérifie si la commande a réussi (exit_code = 0)
  if [ $exit_code -ne 0 ]; then
    echo -e "${RED}❌ ÉCHEC${NC}"
    echo -e "   Entrée : ${YELLOW}$input${NC}"
    echo -e "   Sortie attendue : ${YELLOW}$normalized_expected${NC}"
    echo -e "   Sortie obtenue : ${YELLOW}$output${NC}"
    return 1
  fi

  # Si une sortie attendue est spécifiée, vérifie si elle correspond
  if [ -n "$expected_output" ]; then
    if [[ "$output" == "$normalized_expected" ]]; then
      echo -e "${GREEN}✅ OK${NC}"
      return 0
    else
      echo -e "${RED}❌ ÉCHEC${NC}"
      echo -e "   Entrée : ${YELLOW}$input${NC}"
      echo -e "   Sortie attendue : ${YELLOW}$normalized_expected${NC}"
      echo -e "   Sortie obtenue : ${YELLOW}$output${NC}"
      return 1
    fi
  else
    echo -e "${GREEN}✅ OK${NC}"
    return 0
  fi
}

# =============================================================================
# Compilation du programme
# =============================================================================
echo -e "${BLUE}🔨 Compilation du programme...${NC}"
make re >/dev/null 2>&1
if [ $? -ne 0 ]; then
  echo -e "${RED}❌ Erreur de compilation${NC}"
  exit 1
fi
echo -e "${GREEN}✅ Compilation réussie${NC}"

# =============================================================================
# Initialisation des compteurs
# =============================================================================
total_tests=0
passed_tests=0
failed_tests=0

# =============================================================================
# LANCEMENT DES TESTS
# =============================================================================
echo -e "\n${BLUE}🧪 Début des tests pour RPN${NC}"
echo "====================================="

# --- Tests valides ---
# Test 1: Addition simple
total_tests=$((total_tests + 1))
if run_test "Test 1: Addition simple" "3 4 +" "7"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 2: Soustraction
total_tests=$((total_tests + 1))
if run_test "Test 2: Soustraction" "9 3 -" "6"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 3: Multiplication
total_tests=$((total_tests + 1))
if run_test "Test 3: Multiplication" "5 6 *" "30"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 4: Division
total_tests=$((total_tests + 1))
if run_test "Test 4: Division" "8 2 /" "4"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 5: Expression complexe
total_tests=$((total_tests + 1))
if run_test "Test 5: Expression complexe" "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 6: Nombres négatifs
total_tests=$((total_tests + 1))
if run_test "Test 6: Nombres négatifs" "5 -3 +" "2"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# --- Tests invalides ---
# Test 7: Division par zéro
total_tests=$((total_tests + 1))
if run_test "Test 7: Division par zéro" "5 0 /" "Error"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 8: Pas assez d'opérandes
total_tests=$((total_tests + 1))
if run_test "Test 8: Pas assez d'opérandes" "5 +" "Error"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 9: Caractère invalide
total_tests=$((total_tests + 1))
if run_test "Test 9: Caractère invalide" "5 3 a +" "Error"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 10: Expression vide
total_tests=$((total_tests + 1))
if run_test "Test 10: Expression vide" "" "Error"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 11: Trop d'opérandes
total_tests=$((total_tests + 1))
if run_test "Test 11: Trop d'opérandes" "5 3 2 +" "Error"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 12: Parentheses (invalide en RPN)
total_tests=$((total_tests + 1))
if run_test "Test 12: Parentheses" "(1 + 1)" "Error"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# =============================================================================
# Résumé final
# =============================================================================
echo -e "\n${BLUE}📊 Résumé des tests${NC}"
echo "====================================="
echo -e "Total: ${total_tests} | ${GREEN}Réussis: ${passed_tests}${NC} | ${RED}Échoués: ${failed_tests}${NC}"

if [ $failed_tests -eq 0 ]; then
  echo -e "\n${GREEN}🎉 Tous les tests ont réussi !${NC}"
  exit 0
else
  echo -e "\n${RED}⚠️ Certains tests ont échoué.${NC}"
  exit 1
fi
