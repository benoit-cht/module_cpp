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
		std::getline(std::cin, input);		
	return (input);
}

void Contact::setContact()
{
	std::cout << "First Name: ";
	FirstName = InputContact();
	std::cout << "Last Name: ";
	LastName = InputContact();
	std::cout << "NickName: ";
	NickName = InputContact();
	std::cout << "PhoneNumber: ";
	PhoneNumber = InputContact();
	std::cout << "DarkestSecret: ";
	DarkestSecret = InputContact();

}

std::string Contact::getName() const
{
    return (FirstName);
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
