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

class	Fixed {

	private :
		int	_value;

	public :
		Fixed();
		Fixed(const Fixed&);
		Fixed &operator=(const Fixed&);
		~Fixed();

	public :
		int	getRawBits( void ) const;
		void	setRawBits(int const raw);
};

#endif

/* ************************************************************************** */
/*									      */
/* ************************************************************************** */
