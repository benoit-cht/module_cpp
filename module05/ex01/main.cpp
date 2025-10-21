/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:04:12 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/20 14:04:14 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 50);
        Form form("Formulaire A", 60, 30);

        std::cout << alice << std::endl;
        std::cout << form << std::endl;

        alice.signForm(form); // Alice peut signer (grade 50 < 60)
        std::cout << form << std::endl;

        Bureaucrat bob("Bob", 70);
        bob.signForm(form); // Bob ne peut pas signer (grade 70 > 60)
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

