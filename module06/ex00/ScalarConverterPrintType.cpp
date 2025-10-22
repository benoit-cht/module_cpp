/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterPrintType.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:47:42 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/22 13:47:43 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"
# include <iostream>

void	ScalarConverter::printChar(double value)
{
	if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: imposible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(value);
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: not displayable " << std::endl
	}
}

void	ScalarConverter::printInt(double value)
{
	if (value < std::numeric_limit<int>::min() || value > std::numeric_limits<int>::max() \
		|| std::isnan(value) || std::isinf(value)){
		std::cout << "int: impossible " << std::endl;
	}
	else
	{
		std::cout << "int :" << static_cat<int>(value) << std::endl; 
	}
}

void	ScalarConverter::printFloat(float value)
{
	std::cout << "float : ";
	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
	}
	else if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	}
}

void	ScalarConverter::printDouble(double value)
{
	std::cout << "double : ";
	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
	}
	else if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

