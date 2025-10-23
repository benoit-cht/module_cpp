/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 09:21:10 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/23 09:21:12 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "iter.hpp"

template<typename T>
void	printElement(T const &element)
{
	std::cout << element << " " ;
}

template<typename T>
void	incrementElement(T &element)
{
	element += 1;
}

int	main() 
{
	int	tab[] = {1,2,3};

	std::cout << "Avant incrementation : ";
	::iter(tab, 3, printElement<int>);

	std::cout << "\n -- incrementation -- \n";
	::iter(tab, 3, incrementElement<int>);

	std::cout << "Apres incrementatition :";
	::iter(tab, 3, printElement<int>);
}
