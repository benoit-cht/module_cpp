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

# include <iostream>
# include "Bureaucrat.hpp"

int	main ( void )
{
	try 
		Bureaucrat alice("Alice", 151); // Trop bas
	catch (const std::exception& e) 
		std::cerr << "Error: " << e.what() << std::endl;

	try 
		Bureaucrat bob("Bob", 0); // Trop haut
	catch (const std::exception& e) 
		std::cerr << "Error: " << e.what() << std::endl;

	return EXIT_SUCCESS;
}
