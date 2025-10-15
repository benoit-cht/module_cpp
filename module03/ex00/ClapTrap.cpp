/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:41:23 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/13 10:41:25 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called " << std::endl;
}

ClapTrap::ClapTrap (const std::string& name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap robo constructed! " << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& other) : 
	_name(other._name), 
	_hitPoint(other._hitPoint), 
	_energyPoint(other._energyPoint), 
	_attackDamage(other._attackDamage)
{ std::cout << "Copy constructor called" << std::endl;}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hitPoint = other._hitPoint;
		_energyPoint = other._energyPoint;
		_attackDamage = other._attackDamage;
		std::cout << "assignement operator called " << std::endl;
	}
	return(*this);

}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap " << _name << " destroyed!" << std::endl; }

/* ************************************************************************** */

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoint == 0 || _hitPoint ==0)	
		std::cout << "ClapTrap " << _name << " can't attack; no energy or hit points left! " << std::endl;
	else
	{
		_energyPoint--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint < amount)
		_hitPoint = 0;
	else
		_hitPoint -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoint == 0 || _hitPoint == 0)
		std::cout << "ClapTrap " << _name << " can't be repaired; no energy or hit points left!" << std::endl;
	else
	{
		_energyPoint--;
		_hitPoint += amount;
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
	}
}
