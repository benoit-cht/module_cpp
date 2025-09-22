/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <bchallat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:07:35 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/15 13:07:36 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <cstdlib>
#include <ctype.h>

PhoneBook::PhoneBook() : numb_contact(0) {}

void	PhoneBook::add_contact(const Contact& c)
{
	if (numb_contact < 8)
	{
		contact[numb_contact] = c;
		numb_contact++;
	}
}

void	PhoneBook::search_contact() const
{
	std::string	search = "";

	for (int index = 0; index < numb_contact; index++)
	{
		std::cout << contact[index].getName() << std::endl;
	}
	std::cin >> search;
	if (search.length() == 1 && isdigit(search[0]) && std::stoi(search) <= numb_contact)
		std::cout << contact[std::stoi(search) - 1].getContact() << std::endl;
}
