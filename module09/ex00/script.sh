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
  local input_file=$2
  local expected_output_file=$3

  echo -n "🔹 ${test_name}... "

  # Exécute la commande et capture la sortie
  output=$(./btc "$input_file" 2>&1)
  exit_code=$?

  # Vérifie si la commande a réussi (exit_code = 0)
  if [ $exit_code -ne 0 ]; then
    echo -e "${RED}❌ ÉCHEC${NC}"
    echo -e "   Sortie obtenue : ${YELLOW}$output${NC}"
    return 1
  fi

  # Compare la sortie obtenue avec la sortie attendue
  if [ -f "$expected_output_file" ]; then
    expected_output=$(cat "$expected_output_file")
    if [ "$output" == "$expected_output" ]; then
      echo -e "${GREEN}✅ OK${NC}"
      return 0
    else
      echo -e "${RED}❌ ÉCHEC${NC}"
      echo -e "   Sortie attendue :"
      echo -e "${YELLOW}$expected_output${NC}"
      echo -e "   Sortie obtenue :"
      echo -e "${YELLOW}$output${NC}"
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
echo -e "\n${BLUE}🧪 Début des tests${NC}"
echo "====================================="

# Test 1: Fichier d'entrée avec des cas variés (valides et invalides)
total_tests=$((total_tests + 1))
if run_test "Test 1: Cas variés (valides et invalides)" "test_files/input.txt" "test_files/expected_output.txt"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 2: Fichier vide
total_tests=$((total_tests + 1))
if run_test "Test 2: Fichier vide" "test_files/empty_input.txt" "test_files/expected_empty_output.txt"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 3: Fichier avec uniquement des erreurs
total_tests=$((total_tests + 1))
if run_test "Test 3: Uniquement des erreurs" "test_files/invalid_input.txt" "test_files/expected_invalid_output.txt"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# =============================================================================
# RÉSUMÉ DES TESTS
# =============================================================================
echo -e "\n${BLUE}📊 Résumé des tests${NC}"
echo "====================================="
echo -e "Total: ${total_tests} | Réussis: ${GREEN}${passed_tests}${NC} | Échoués: ${RED}${failed_tests}${NC}"

if [ $failed_tests -eq 0 ]; then
  echo -e "${GREEN}✅ Tous les tests ont réussi !${NC}"
  exit 0
else
  echo -e "${RED}⚠️ Certains tests ont échoué.${NC}"
  exit 1
fi
