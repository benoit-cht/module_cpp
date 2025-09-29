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

	std::cout	<< "" << &string << std::endl
			<< "" << stringPTR << std::endl
			<< "" << &stringREF << std::endl
			<< std::endl;

	std::cout 	<< "" << string << std::endl
			<< "" << *stringPTR << std::endl
			<< "" << stringREF << std::endl;

	return (0);
}
