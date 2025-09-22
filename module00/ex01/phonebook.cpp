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

PhoneBook::PhoneBook() : numb_contact(0),last_add(0) {}

void	Format_chain(std::string str)
{
	for (int length = 0; length < 9; length++)
	{
		if (length <= str.length())
			std::cout << str[length];
		else
			std::cout << " ";
	}
	if (str.length() > 10)
		std::cout << ".";
	else
		std::cout << " ";
	std::cout << "|";
}

void	PhoneBook::add_contact(const Contact& c)
{
	if (last_add < 8)
	{
		contact[last_add] = c;
		last_add++;
	}
	else
	{
		last_add = 0;
		add_contact(c);
	}
	if (numb_contact < 8)
		numb_contact++;

}

void	PhoneBook::search_contact() const
{
	std::string	search = "";

	for (int index = 0; index < numb_contact; index++)
	{
		std::cout << "\n" << index + 1 << "|";
		Format_chain(contact[index].getFirstName());
		Format_chain(contact[index].getLastName());
		Format_chain(contact[index].getNickName());
	}
	std::cout << "\n" << std::endl;
	std::cin >> search;
	if (search.length() == 1 && isdigit(search[0]) && std::stoi(search) <= numb_contact)
		std::cout << contact[std::stoi(search) - 1].getContact() << std::endl;
	else
		std::cout << "ERROR: input is not valid\n" << std::endl;
}
