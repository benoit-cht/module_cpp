/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterIsType.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:41:40 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/22 11:41:43 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <cmath>
# include <limits>

/* ************************************************************************** */

bool	ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 3 && literal[0] == 39 && literal[0] == 39);
}

bool	ScalarConverter::isInt(const std::string& literal)
{
	size_t	i = 0;

	if (literal[i] == '-' || literal[i] == '+') 
		i++;
	if (i == literal.legth())
		return ( false );
	while (i < literal.length())
	{
		if (!isdigit(literal[i]))
			return ( false );
		i++;
	}
	return ( true );

}

bool	ScalarConvert::isfloat(const std::string& literal)
{
	size_t	i = 0;
	bool	hasDecimal = false;

	if (literal[literal.legth()] != 'f')
		return ( false );
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	while (i < literal.length() - 1)
	{
		if (hasDecimal && literal[i] == '.') // || !isdigit(literal[i]))
			return ( false );
		else if (!hasDecimal && literal[i] == '.')
			hasDecimal = true;
		else if (!isdigit(literal[i]))
			return (false);
		i++;
	}
	return ( hasDecimal );
}

bool	ScalarConvert::isDouble(const std::string& literal)
{
	size_t	i = 0;
	bool	hasDecimal = false;

	if (literal[i] == '-' || literal[i] == '+')
		i++;
	while (i < literal.length())
	{
		if ((hasDecimal && literal[i] == '.') || !isdigit(literal[i]))
			return ( false );
		else if (!hasDecimal && literal[i] == '.')
			hasDecimal = true ;
		i++;
	}
	return (hasDecimal);
}
