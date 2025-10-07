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
		int	toInt( void ) const;
		float	toFloat( void ) const;
		void	setRawBits( int const raw );
};

std::ostream	&operator<<( std::ostream &out, const Fixed &fixed);

#endif

