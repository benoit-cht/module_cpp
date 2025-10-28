/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:46:05 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/28 14:46:06 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
# include "ScalarConverter.hpp"

int main() {
    float f = 42.0f;
    double d = 42.0;

    // Affichage avec 1 chiffre après la virgule
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;  // Affiche "42.0f"
    std::cout << "double: " << d << std::endl;         // Affiche "42.0"

    return 0;
}
