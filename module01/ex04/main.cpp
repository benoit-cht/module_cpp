/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 10:36:10 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/05 10:36:14 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

#include "MySedLoser.hpp"

int	main (int ac, char *av[])
{
	std::string	filename = "";
	std::string	s1 = "";
	std::string	s2 = "";
	
	if (ac != 4)
	{
		std::cerr << "Error: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return (EXIT_FAILURE);
	}

	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	std::ifstream	inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "ERROR: Could not open file " << std::endl;
		return(EXIT_SUCCESS);
	}

	std::ofstream	outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "ERROR : Could not create output file " << std::endl;
		inputFile.close();
		return (EXIT_SUCCESS);
	}

	inputFile.close();
	outputFile.close();
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*									      */
/* ************************************************************************** */
