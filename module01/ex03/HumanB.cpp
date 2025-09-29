/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainB.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:32:31 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 13:32:32 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL);

void	HumanB::attack() const
{
	if (this->weapon)
	{
		std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
	}else{
		std::cout << this->name << " has no weapon for attack!! " << std::endl;
	}
}
