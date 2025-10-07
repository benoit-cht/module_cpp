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

Fixed::Fixed(): _rawBits(0) { std::cout << "Default constructor called " << std::endl; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed( const Fixed& other )
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

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawbits meber fonction called " << std::endl;
	return ( _rawBits );

}

void	Fixed::setRawBits( int const raw ) { _rawBits = raw; }
