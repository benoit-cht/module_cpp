/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:56:20 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/27 10:56:21 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    AForm* form;

    try {
        // Test avec un formulaire valide
        form = intern.makeForm("robotomy request", "Bender");
        Bureaucrat alice("Alice", 1);
        alice.signForm(*form);
        alice.executeForm(*form);
        delete form; // Libère la mémoire

        // Test avec un formulaire invalide
        form = intern.makeForm("unknown form", "Target");
         delete form; // Libère la mémoire
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
