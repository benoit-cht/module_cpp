/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <bchallat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:07:33 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/15 13:07:34 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	repertoire;
	Contact		c1;
	std::string	input = "";

	while (1)
	{
		std::cout << "Enter a command [ADD, SEARCH, EXIT] : ";
		std::cin >> input;
		if (input == "EXIT")
			break;
		else if (input == "ADD")
		{
			c1.setContact();
			repertoire.add_contact(c1);
		}
		else if (input == "SEARCH")
		{
			repertoire.search_contact();
		}
		else
			std::cerr << "ERROR : Unknown commande " << input << std::endl;
	}
	return (EXIT_SUCCESS);
}
