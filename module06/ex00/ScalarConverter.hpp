/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:37:19 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/22 10:37:20 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cctype>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <cmath>
# include <limits>

class	ScalarConverter {
	
	public :
		static void	convert(const std::string literal);

	public :
		static bool	isChar(const std::string& literal);
		static bool	isInt(const std::string& literal);
		static bool	isFloat(const std::string& literal);
		static bool	isDouble(const std::string& literal);
	public :
		static void	printChar(double value);
		static void	printInt(double value);
		static void	printFloat(float value);
		static void	printDouble(double value);

	private :
		ScalarConverter ( void );
		virtual ~ScalarConverter ( void );
		ScalarConverter (const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
};

# endif

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

