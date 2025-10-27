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

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);

        ShrubberyCreationForm shrubbery("garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Marvin");

        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);

        bob.signForm(robotomy);
        alice.executeForm(robotomy);

        alice.signForm(pardon);
        alice.executeForm(pardon);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0) ;
}
