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

# include <string>

class	ScalarConverter {
	
	public :
		static	convert(const std::string literal);

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
		ScalarConverter (const ScalarConvert& other);
		ScalerConverter& operator=(const ScalarConvert& other);
};

# endif

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

