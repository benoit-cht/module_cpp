/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:44:21 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 12:44:22 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout	<< " Adress de la string en memoire : " << &string    << std::endl
			<< " Adress stockee  dans stringPTR : " << stringPTR  << std::endl
			<< " Adress stockee  dans stringREF : " << &stringREF << std::endl
			<< "------------------------------------------------" <<std::endl;

	std::cout 	<< " Valeur de la string via la variable : " << string << std::endl
			<< " Valeur de la string via   stringPTR : " << *stringPTR << std::endl
			<< " Valeur de la string via   stringREF : " << stringREF << std::endl;

	return (0);
}
