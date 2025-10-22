/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:28:06 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/22 17:28:08 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate() {
    int random = std::rand() % 3;
    if (random == 0) return new A();
    else if (random == 1) return new B();
    else return new C();
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "A" << std::endl;
    } catch (...) {
        try {
            static_cast<void>(dynamic_cast<B&>(p));
            std::cout << "B" << std::endl;
        } catch (...) {
            try {
                static_cast<void>(dynamic_cast<C&>(p));
                std::cout << "C" << std::endl;
            } catch (...) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

int main() {
    Base* base = generate();
    identify(base);    // Affiche "A", "B", ou "C" aléatoirement
    identify(*base);   // Même résultat, mais avec une référence

    delete base;       // Libère la mémoire
    return 0;
}

