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
static void	convertionFoat(const std::string& literal);
static void	convertionDouble(const std::string& literal);
static void	convertSpecialCase(const std::string& literal);

/* ************************************************************************** */

void	ScalarConverter::convert(const std::string literal)
{
	if (isChar(literal))
	{
		//print la convertion de char
	}
	else if (isInt(literal))
	{
		//print la convertion de int
	}
	else if (isFloat(literal))
	{
		// print la convertion de float
	}
	else if (isDouble(literal))
	{
		//print la convertion de double 
	}
	else
	{
		// gestion des cas speciaux (nan, inf, ect.)
	}
}

/* ************************************************************************** */

static void	convertChar(const std::string& literal)
{
	char c = literal[1];
	printChar(static_cast<double>(c));
	printInt(static_cast<double>(c));
	printFloat(static_cast<float>(c));
	printFloat(static_cast<double>(c));
}

static void	convertionInt(const std::string& literal)
{
	try{
		long intValue = std::stol(literal);
		if (intValue < std::numeric_limit<int>::min() || intValue > std::numeric_limit<int>::max())
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		else
		{
			printChar(static_cast<double>(intValue));
			printInt(static_cast<double>(intValue))
		}
		printFloat(static_cast<float>(inValue));
		printDouble(static_cast<double>(intValue));
	
	}catch (...) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		printFloat(0.0f);
		printDouble(0.0);
	}
}

static void	convertionFoat(const std::string& literal)
{
	try{
		float floatValue = std::stof(literal);
		printChar(static_cast<double>(floatValue));
		printInt(static_cast<double>(floatValue));
		printFloat(floatValue);
		printDouble(static_cast<double>(floatValue));
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
		printChar(doubleValue);
		printInt(doubleValue);
		printFloat(static_cast<float>(doubleValue));
		printDouble(doubleValue);
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

