/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:24:53 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/06 10:24:55 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {

	private :
		int			_rawBits;
		static const int	_fractionalBits = 8;

	public :
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		Fixed( const Fixed& other );
		Fixed& operator=(const Fixed& other);
		~Fixed();

	public :
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
	public :
		int	toInt( void ) const;
		float	toFloat( void ) const;
	public :
		bool	operator>( const Fixed &other ) const;
		bool	operator<( const Fixed &other ) const;
		bool	operator>=( const Fixed &other ) const;
		bool	operator<=( const Fixed &other ) const;
		bool	operator==( const Fixed &other ) const;
		bool	operator!=( const Fixed &other ) const;
	public :
		Fixed	operator+( const Fixed &other ) const;
		Fixed	operator-( const Fixed &other ) const;
		Fixed	operator*( const Fixed &other ) const;
		Fixed	operator/( const Fixed &other ) const;
	public :
		Fixed	&operator++();
		Fixed	operator++( int );
		Fixed	&operator--();
		Fixed	operator--( int );
	public :
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

};

std::ostream	&operator<<( std::ostream &out, const Fixed &fixed);

#endif

/* ************************************************************************** */
/*									      */
/* ************************************************************************** */
