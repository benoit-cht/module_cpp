/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:33:08 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 13:33:10 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB
{
	private :
		std::string	name;
		Weapon*		weapon;
	public :
		HumanB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack() const;
};

#endif

