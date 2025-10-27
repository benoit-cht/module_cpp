/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:52 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:24:54 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int arraySize = 4;
	Animal* animals[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2) 
			animals[i] = new Dog(); 
		else
            animals[i] = new Cat();
	}

	for (int i = 0; i < arraySize; i++)
        	delete animals[i];

    return EXIT_SUCCESS;
}
*/
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    // 1. Création d'un chien et d'un chat originaux
    std::cout << "=== Création des animaux originaux ===" << std::endl;
    Dog* dog1 = new Dog();
    Cat* cat1 = new Cat();

    // 2. Remplissage des idées dans le Brain de dog1
    std::cout << "\n=== Remplissage des idées du chien ===" << std::endl;
    dog1->getBrain()->setIdeas("Manger des croquettes", 0);
    dog1->getBrain()->setIdeas("Jouer avec une balle", 1);
    std::cout << "Idée 0 de dog1 : " << dog1->getBrain()->getIdeas(0) << std::endl;
    std::cout << "Idée 1 de dog1 : " << dog1->getBrain()->getIdeas(1) << std::endl;

    // 3. Copie profonde de dog1 vers dog2
    std::cout << "\n=== Copie profonde de dog1 vers dog2 ===" << std::endl;
    Dog* dog2 = new Dog(*dog1); // Appelle le constructeur de copie de Dog

    // 4. Vérification que dog2 a bien ses propres idées (copie profonde)
    std::cout << "\n=== Vérification de la copie profonde ===" << std::endl;
    std::cout << "Idée 0 de dog2 : " << dog2->getBrain()->getIdeas(0) << std::endl;
    std::cout << "Idée 1 de dog2 : " << dog2->getBrain()->getIdeas(1) << std::endl;

    // 5. Modification d'une idée de dog1 (ne doit pas affecter dog2)
    std::cout << "\n=== Modification d'une idée de dog1 ===" << std::endl;
    dog1->getBrain()->setIdeas("Dormir sur le canapé", 0);
    std::cout << "Nouvelle idée 0 de dog1 : " << dog1->getBrain()->getIdeas(0) << std::endl;
    std::cout << "Idée 0 de dog2 (doit rester inchangée) : " << dog2->getBrain()->getIdeas(0) << std::endl;

    // 6. Test de l'opérateur d'affectation (=)
    std::cout << "\n=== Test de l'opérateur d'affectation ===" << std::endl;
    Dog* dog3 = new Dog();
    *dog3 = *dog1; // Appelle l'opérateur d'affectation de Dog
    std::cout << "Idée 0 de dog3 (après affectation) : " << dog3->getBrain()->getIdeas(0) << std::endl;

    // 7. Nettoyage
   
 std::cout << "\n=== Nettoyage ===" << std::endl;
    delete dog1;
    delete dog2;
    delete dog3;

    delete cat1;

    return 0;
}
