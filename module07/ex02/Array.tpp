/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:34:28 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/23 11:34:29 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

/* ************************************************************************** */

template <typename T> Array<T>::Array( void ) : _array(nullptr), _size(0) {}

template <typename T> Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T> Array<T>::~Array( void ) { delete[] _array ;}

/* ************************************************************************** */

template <typename T> Array<T>::Array(Array const &other) : _array(nullptr), _size(0) { *this = other; }

template <typename T> Array<T>	&Array<T>::operator=(Array const &other) 
{
	if (this != &other)
	{
		delete[] _array ;
		_size = other._size ;
		_array = new T[_size] ;

		for  (unsigned int index = 0; index < _size; index++)
		{
			_array[index] = other._array[index] ;	
		}
	}
	return ( *this ) ;
}

/* ************************************************************************** */

template <typename T> unsigned int	Array<T>::getSize( void ) { return (_size) ;}

/* ************************************************************************** */

template<typename T> T		&Array<T>::operator[](unsigned int index) 
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds") ;

	return (_array[index]) ;
}

template<typename T> T const		&Array<T>::operator[](unsigned int index) const 
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds") ;
	
	return (_array[index]) ;
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
