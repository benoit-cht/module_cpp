/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:24:38 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/06 10:24:40 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* ************************************************************************** */

Fixed::Fixed(): _rawBits(0) 
{ 
	std::cout << "Default constructor called " << std::endl; 
}

Fixed::Fixed(int const value): _rawBits(value << _fractionalBits) 
{ 
	std::cout << "Int constructor called " << std::endl; 
}

Fixed::Fixed(float const value): _rawBits(roundf(value * (1 << _fractionalBits))) 
{ 
	std::cout << "float constructor called " << std::endl; 
}

Fixed::~Fixed() 
{ 
	std::cout << "Destructor called" << std::endl; 
}

Fixed::Fixed( const Fixed& other ) : _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called " << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=( const Fixed& other )
{
	if ( this != &other )
		this->_rawBits = other.getRawBits();
	std::cout << "Copy assignement operator called " << std::endl;
	return ( *this );
}

/* ************************************************************************** */

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawbits meber fonction called " << std::endl;
	return ( _rawBits );

}

void	Fixed::setRawBits( int const raw ) { _rawBits = raw; }

/* ************************************************************************** */

int	Fixed::toInt ( void ) const { return ( _rawBits >> _fractionalBits ); }

float	Fixed::toFloat ( void ) const { return ((float)_rawBits / ( 1 << _fractionalBits)); }

/* ************************************************************************** */
//	Surchage d'un operateur de comparaison 

bool	Fixed::operator==( const Fixed &other ) const
{
	return ( _rawBits == other._rawBits );
}

/* ************************************************************************** */
//	Surchage d'un operateur de aritmetique 


Fixed	Fixed::operator+(const Fixed &other) const 
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

/* ************************************************************************** */
//	Surchage d'un operateur d'incrementation 

Fixed	&Fixed::operator++()
{
	_rawBits += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	_rawBits += 1;
	return (temp);
}

Fixed	Fixed::operator--()
{
	_rawBits -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	_rawBits -= 1;
	return (temp);
}

/* ************************************************************************** */
//	fonction static min/max


/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &out, const Fixed &fixed )
{
	out << fixed.toFloat();
	return ( out );
}
