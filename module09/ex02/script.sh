#!/bin/bash

# =============================================================================
# Couleurs pour l'affichage
# =============================================================================
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# =============================================================================
# Détection du système d'exploitation
# =============================================================================
OS="$(uname -s)"
case "$OS" in
Darwin)
  RANDOM_CMD="jot -r"
  ;;
Linux)
  RANDOM_CMD="shuf -i"
  ;;
*)
  echo -e "${RED}❌ Système non supporté${NC}"
  exit 1
  ;;
esac

# =============================================================================
# Fonction pour générer des nombres aléatoires
# =============================================================================
generate_random_numbers() {
  local count=$1
  local min=$2
  local max=$3
  if [ "$OS" = "Darwin" ]; then
    $RANDOM_CMD $count $min $max | tr '\n' ' '
  else
    $RANDOM_CMD $min-$max -n $count | tr '\n' ' '
  fi
}

# =============================================================================
# Fonction pour exécuter un test et vérifier son succès
# =============================================================================
run_test() {
  local test_name=$1
  local command=$2
  local expected_output=$3

  echo -n "🔹 ${test_name}... "

  # Exécute la commande et capture la sortie (stdout + stderr)
  output=$($command 2>&1 | tr -d '\n' | xargs)
  exit_code=$?

  # Normalise la sortie attendue (supprime les sauts de ligne et espaces superflus)
  normalized_expected=$(echo "$expected_output" | tr -d '\n' | xargs)

  # Vérifie si la commande a réussi (exit_code = 0)
  if [ $exit_code -ne 0 ]; then
    echo -e "${RED}❌ ÉCHEC${NC}"
    echo -e "   Commande exécutée : ${YELLOW}$command${NC}"
    echo -e "   Sortie attendue : ${YELLOW}$normalized_expected${NC}"
    echo -e "   Sortie obtenue : ${YELLOW}$output${NC}"
    return 1
  fi

  # Si une sortie attendue est spécifiée, vérifie si elle correspond
  if [ -n "$expected_output" ]; then
    if [[ "$output" == *"$normalized_expected"* ]]; then
      echo -e "${GREEN}✅ OK${NC}"
      return 0
    else
      echo -e "${RED}❌ ÉCHEC${NC}"
      echo -e "   Commande exécutée : ${YELLOW}$command${NC}"
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
echo -e "\n${BLUE}🧪 Début des tests${NC}"
echo "====================================="

# Test 1: Petits nombres (5 éléments)
total_tests=$((total_tests + 1))
if run_test "Test 1: Petits nombres" "./PmergeMe 3 5 9 7 4" "Before: 3 5 9 7 4"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 2: Nombres invalides (négatif)
total_tests=$((total_tests + 1))
if run_test "Test 2: Nombres invalides" "./PmergeMe -1 2" "Error"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 3: Un seul nombre
total_tests=$((total_tests + 1))
if run_test "Test 3: Un seul nombre" "./PmergeMe 42" "Before: 42"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 4: 3000 nombres aléatoires (1-100000)
total_tests=$((total_tests + 1))
if run_test "Test 4: 3000 nombres aléatoires" "./PmergeMe $(generate_random_numbers 3000 1 100000)" "Before:"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 5: 10000 nombres aléatoires (1-1000000)
total_tests=$((total_tests + 1))
if run_test "Test 5: 10000 nombres aléatoires" "./PmergeMe $(generate_random_numbers 10000 1 1000000)" "Before:"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 6: Nombres déjà triés
total_tests=$((total_tests + 1))
if run_test "Test 6: Nombres déjà triés" "./PmergeMe 1 2 3 4 5 6 7 8 9 10" "Before: 1 2 3 4 5 6 7 8 9 10"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 7: Nombres en ordre inverse
total_tests=$((total_tests + 1))
if run_test "Test 7: Nombres en ordre inverse" "./PmergeMe 10 9 8 7 6 5 4 3 2 1" "Before: 10 9 8 7 6 5 4 3 2 1"; then
  passed_tests=$((passed_tests + 1))
else
  failed_tests=$((failed_tests + 1))
fi

# Test 8: Doublons
total_tests=$((total_tests + 1))
if run_test "Test 8: Doublons" "./PmergeMe 5 3 5 1 3 2 2 4" "Before: 5 3 5 1 3 2 2 4"; then
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
