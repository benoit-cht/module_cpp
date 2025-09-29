/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:50:03 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/23 10:50:04 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int	N = 5;
	Zombie* horde = zombieHorde(N, "my_horde");

	for (int index = 0; index < N; index++)
		horde[index].announce();
	delete[] horde;
    return EXIT_SUCCESS;
}
