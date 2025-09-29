/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:32:13 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 13:32:16 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumainA.hpp"

HuamanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

void	HumanA::attack() const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() <<std::endl;
}

