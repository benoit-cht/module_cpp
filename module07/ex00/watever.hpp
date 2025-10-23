/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watever.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:21:56 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/23 09:21:58 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WATEVER_HPP
# define WATEVER_HPP

template<typename T>
void	swap(T &a, T&b)
{
	T	swap = a;
	a = b;
	b = swap;
}

template<typename T>
T const &min(T const &a, T const &b)
{
	return ((a < b) ? a : b);
}

template<typename T>
T const &max(T const &a, T const &b)
{
	return ((a > b) ? a : b);
}

# endif
