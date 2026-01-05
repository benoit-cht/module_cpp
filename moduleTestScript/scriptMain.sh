#!/bin/bash

# Couleurs pour l'affichage (correction : ajout du guillemet fermant)
MAGENTA='\033[0;35m'
BLUE='\033[1;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}\n ******  *******  *******        ****     ****               **          **        
  **////**/**////**/**////**      /**/**   **/**              /**         /**        
 **    // /**   /**/**   /**      /**//** ** /**  ******      /** **   ** /**  ***** 
/**       /******* /*******       /** //***  /** **////**  ******/**  /** /** **///**
/**       /**////  /**////        /**  //*   /**/**   /** **///**/**  /** /**/*******
//**    **/**      /**            /**   /    /**/**   /**/**  /**/**  /** /**/**//// 
 //****** /**      /**            /**        /**//****** //******//****** ***//******
  //////  //       //             //         //  //////   //////  ////// ///  ////// ${NC}"

for i in {0..8}; do
  echo -e "${BLUE}\n[ Module0$i ]_____[compilation]_____[Valgrind]_____[clean]${NC}"

  if [[ "$i" -eq 0 ]]; then
    (cd "./module0$i" && ../testScript/unitScript/unitModule00.sh) || {
      echo -e "\033[0;31mErreur : Impossible d'exécuter le test dans module0$i\033[0m"
    }
  # Vérifie que le répertoire existe avant de s'y déplacer
  else
    if [ -d "./module0$i" ]; then
      (cd "./module0$i" && ../testScript/sriptTest.sh) || {
        echo -e "\033[0;31mErreur : Impossible d'exécuter le test dans module0$i\033[0m"
      }
    else
      echo -e "\033[0;31mErreur : Le répertoire module0$i n'existe pas\033[0m"
    fi
  fi
done
