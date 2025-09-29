/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:32:38 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 13:32:40 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string): type(type) {}

const std::string	Weapon::getType() const
{
	return this->type ;
}

void	Weapon::setType(std::string newType)
{
	this->type = newType;
}
