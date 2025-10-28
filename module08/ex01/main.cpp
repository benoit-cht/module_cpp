/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:30:40 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/24 13:30:42 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib> // Pour rand()

int main() {
    // Test 1: Ajout de nombres un par un
    {
        std::cout << "=== Test 1: Ajout de nombres un par un ===" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Test 2: Tentative d'ajout au-delà de la capacité
    {
        std::cout << "\n=== Test 2: Tentative d'ajout au-delà de la capacité ===" << std::endl;
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        try {
            sp.addNumber(4); // Devrait lever une exception
        } catch (const std::exception& e) {
            std::cerr << "Erreur: " << e.what() << std::endl;
        }
    }

    // Test 3: Ajout d'une plage d'itérateurs
    {
        std::cout << "\n=== Test 3: Ajout d'une plage d'itérateurs ===" << std::endl;
        Span sp(10);
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i) {
            vec.push_back(rand() % 100); // Nombres aléatoires entre 0 et 99
        }

        sp.addRange(vec.begin(), vec.end());

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    // Test 4: Cas limite avec 0 ou 1 élément
    {
        std::cout << "\n=== Test 4: Cas limite avec 0 ou 1 élément ===" << std::endl;
        Span sp1(1);
        try {
            std::cout << "Shortest span (1 élément): " << sp1.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erreur: " << e.what() << std::endl;
        }

        Span sp2(0);
        try {
            std::cout << "Longest span (0 élément): " << sp2.longestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Erreur: " << e.what() << std::endl;
        }
    }

    // Test 5: Test avec 10 000 nombres
    {
        std::cout << "\n=== Test 5: Test avec 10 000 nombres ===" << std::endl;
        Span sp(10000);
        std::vector<int> largeVec;
        for (int i = 0; i < 10000; ++i) {
            largeVec.push_back(rand() % 1000000); // Nombres aléatoires entre 0 et 999 999
        }

        sp.addRange(largeVec.begin(), largeVec.end());

        std::cout << "Shortest span (10 000 éléments): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (10 000 éléments): " << sp.longestSpan() << std::endl;
    }

    return 0;
}
