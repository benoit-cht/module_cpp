/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:49:57 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/23 10:49:59 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name) : name(name)
{
	std::cout << "Zombie" << name << std::endl;
}

void	Zombie:anouce(void)
{
	std::cout << name << "BraiiiiiiinnnnnzZ ..." << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie" << name << "over" << std::endl;
}
