/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:29:22 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/24 13:29:26 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template<typename T>
typename	T::iterator easyfind(T& container, int n)
{
	typename T::iterator	iterator = std::find(container.begin(), container.end(), n) ;

	if (iterator == container.end())
		throw std::runtime_error("Value not fond in container") ;

	return ( iterator ) ;
}

# endif

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

