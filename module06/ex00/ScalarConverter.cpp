/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:19:18 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/22 14:19:20 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

/* ************************************************************************** */

static void	convertChar(const std::string& literal);
static void	convertionInt(const std::string& literal);
static void	convertionFloat(const std::string& literal);
static void	convertionDouble(const std::string& literal);
static void	convertSpecialCase(const std::string& literal);

/* ************************************************************************** */

void	ScalarConverter::convert(const std::string literal)
{
	if (isChar(literal))
	{
		//print la convertion de char
		convertChar(literal);
	}
	else if (isInt(literal))
	{
		//print la convertion de int
		convertionInt(literal);
	}
	else if (isFloat(literal))
	{
		// print la convertion de float
		convertionFloat(literal);
	}
	else if (isDouble(literal))
	{
		//print la convertion de double 
		convertionDouble(literal);
	}
	else
	{
		// gestion des cas speciaux (nan, inf, ect.)
		convertSpecialCase(literal);
	}
}

/* ************************************************************************** */

static void	convertChar(const std::string& literal)
{
	char c = literal[1];
	ScalarConverter::printChar(static_cast<double>(c));
	ScalarConverter::printInt(static_cast<double>(c));
	ScalarConverter::printFloat(static_cast<float>(c));
	ScalarConverter::printDouble(static_cast<double>(c));
}

static void	convertionInt(const std::string& literal)
{
	try{
		long intValue = std::stol(literal);
		if (intValue < std::numeric_limits<int>::min() || intValue > std::numeric_limits<int>::max())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			ScalarConverter::printChar(static_cast<double>(intValue));
			ScalarConverter::printInt(static_cast<double>(intValue));
		}
		ScalarConverter::printFloat(static_cast<float>(intValue));
		ScalarConverter::printDouble(static_cast<double>(intValue));
	
	}catch (...) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		ScalarConverter::printFloat(0.0f);
		ScalarConverter::printDouble(0.0);
	}
}

static void	convertionFloat(const std::string& literal)
{
	try{
		float floatValue = std::stof(literal);
		ScalarConverter::printChar(static_cast<double>(floatValue));
		ScalarConverter::printInt(static_cast<double>(floatValue));
		ScalarConverter::printFloat(floatValue);
		ScalarConverter::printDouble(static_cast<double>(floatValue));
	}catch (...) {
		std::cout << "char  : imposible " << std::endl;
		std::cout << "int   : imposible " << std::endl;
		std::cout << "float : nanf "	  << std::endl;
		std::cout << "double: nan "	  << std::endl;
	}
}

static void	convertionDouble(const std::string& literal)
{
	try{
		double doubleValue = std::stod(literal);
		ScalarConverter::printChar(doubleValue);
		ScalarConverter::printInt(doubleValue);
		ScalarConverter::printFloat(static_cast<float>(doubleValue));
		ScalarConverter::printDouble(doubleValue);
	}catch (...) {
		std::cout << "char  : imposible " << std::endl;
		std::cout << "int   : imposible " << std::endl;
		std::cout << "float : nanf "	  << std::endl;
		std::cout << "double: nan "	  << std::endl;
	}
}

static void	convertSpecialCase(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "char  : imposible " << std::endl;
		std::cout << "int   : imposible " << std::endl;
		std::cout << "float : nanf "	  << std::endl;
		std::cout << "double: nan "	  << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "char  : imposible " << std::endl;
		std::cout << "int   : imposible " << std::endl;
		std::cout << "float : +inf "	  << std::endl;
		std::cout << "double: +inff "	  << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "char  : imposible " << std::endl;
		std::cout << "int   : imposible " << std::endl;
		std::cout << "float : -inf "	  << std::endl;
		std::cout << "double: -inff "	  << std::endl;
	}
	else
	{
		std::cout << "char  : imposible " << std::endl;
		std::cout << "int   : imposible " << std::endl;
		std::cout << "float : imposible " << std::endl;
		std::cout << "double: imposible " << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

