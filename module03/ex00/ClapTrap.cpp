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

ClapTrap::ClapTrap()
{
	std::cout << " Default constructor called " std::endl;
}

ClapTrap::ClapTrap (const std::string& name) : _name(name), _hitPoint(10), _energiePoint(10), _attackDamage(0)
{
	std::cout << " ClapTrap robo constructed! " << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap& other) : _name(other._name), _hitPoint(other._hitPoint), _energiePoint(other._energiePoint), _attackDamage(other._attackPoint)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = &other._name;
		this->_hitPoint = &other._hitPoint;
		this->_energiePoint = &other._energiePoint;
		this->_name = &attackDamage._attackDamage;
		std::cout << " assignement operator called " << std::endl;
		return(*this);
	}

}

