/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 10:44:46 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 10:44:50 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if (N < 1){
		std::cout << "N mist be >= 1" << std::endl;
		return (NULL);
	}
	Zombie*	horde = new Zombie[N];
	for(int index = 0; index < N; index++)
		horde[index].setname(name);
	return horde ;
}
