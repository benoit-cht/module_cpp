/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:13:33 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/13 17:13:36 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

FragTrap::FragTrap (const std::string& name) : 
	ClapTrap(name){
		_hitPoint = 100;
		_energyPoint = 100;
		_attackDamage = 30;
		std::cout << "FragTrap " << _name << " constructed! " << std::endl; 
	}

FragTrap::~FragTrap ()
{
	std::cout << "FragTrap " << _name << " destroyed!" << std::endl;
}

/* ************************************************************************** */

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high five! 🖐️" << std::endl;
}
