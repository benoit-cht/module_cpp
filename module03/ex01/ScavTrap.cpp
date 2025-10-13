/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:16:12 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/13 15:16:15 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ScavTrap::ScavTrap (const std::string& name) : ClapTrap(name)
{
	_hitPoint = 100;
	_energypoint = 50;
	_attackDamage = 20;

	std::count << "ScavTrap " << _name << " constructed! " << std::endl; 
}

ScavTrap::~ScavTrap ()
{
	std::cout << "ScavTrap " << _name << " destroyed!" << std::endl;
}

/* ************************************************************************** */

void	ScavTrap::attack(const std::string& target)
{
	if (_energyPoint == 0 || _hitPoints == 0)
		std::cout << "ScavTrap " << _name << " can't attack; no energy or hit points left!" << std::endl;
	else
	{
		energyPoint--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
