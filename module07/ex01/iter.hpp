/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:23:36 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/23 09:23:38 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void	iter(T *array, size_t length, void (*func)(T const &))
{
	for (size_t ind = 0; ind < length; ind++)
		func(array[ind]);
}

template<typename T>
void	iter(T *array, const size_t length, void (*func)(T &))
{
	for (size_t ind = 0; ind < length ; ind++)
		func(array[ind]);
}

# endif

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
