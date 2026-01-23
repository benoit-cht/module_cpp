/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:23:22 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/23 09:23:23 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T> class Array {
	
	public :
		Array( void ) ;
		Array(unsigned int n) ;
		Array(const Array &other) ;
		Array& operator=(const Array &other) ;
		virtual ~Array( void ) ;

	public :
		unsigned int	getSize( void ) ;

	public :
		T	&operator[](unsigned int	index) ;
		T const &operator[](unsigned int index) const ;

	private :
		T*		_array ;
		unsigned int	_size ;
};

# include "Array.tpp"
# endif

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

