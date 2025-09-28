/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <bchallat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:07:25 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/15 13:07:26 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <string>
#include <iostream>

std::string	InputContact(void)
{
	std::string	input = "";
	
	while (input == "")
		if (!std::getline(std::cin, input))
			return "";		
	return (input);
}

void	Contact::setContact()
{
	std::cout << "First Name: ";
	FirstName = InputContact();
	if (FirstName == "")
		return ;
	std::cout << "Last Name: ";
	LastName = InputContact();
	if (LastName == "")
		return ;
	std::cout << "NickName: ";
	NickName = InputContact();
	if (NickName == "")
		return ;
	std::cout << "PhoneNumber: ";
	PhoneNumber = InputContact();
	if (PhoneNumber == "")
		return ;
	std::cout << "DarkestSecret: ";
	DarkestSecret = InputContact();
	if (DarkestSecret == "")
		return ;
}

std::string Contact::getFirstName() const
{
    return (FirstName);
}

std::string Contact::getLastName() const
{
    return (LastName);
}

std::string Contact::getNickName() const
{
    return (NickName);
}
std::string	Contact::getContact() const
{
	std::cout << "First Name: " << FirstName;
	std::cout << "\nLast Name: " << LastName;
	std::cout << "\nNickName: " << NickName;
	std::cout << "\nPhoneNumber: " << PhoneNumber;
	std::cout << "\nDarkestSecret: " << DarkestSecret;
	return "" ;
}
