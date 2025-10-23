/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:21:10 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/23 09:21:12 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() {
    // Test constructeur par défaut
    Array<int> empty;
    std::cout << "Taille de empty : " << empty.getSize() << std::endl; // 0

    // Test constructeur avec taille
    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.getSize(); ++i) {
        numbers[i] = i * 2;
    }

    // Test opérateur []
    std::cout << "numbers[2] : " << numbers[2] << std::endl; // 4

    // Test constructeur de copie
    Array<int> copy(numbers);
    std::cout << "copy[2] : " << copy[2] << std::endl; // 4

    // Test opérateur d'affectation
    Array<int> assign;
    assign = numbers;
    std::cout << "assign[2] : " << assign[2] << std::endl; // 4

    // Test exception
    try {
        std::cout << numbers[10] << std::endl; // Doit lancer une exception
    } catch (std::exception &e) {
        std::cerr << "Erreur : " << e.what() << std::endl; // "Index out of bounds"
    }

    return 0;
}

