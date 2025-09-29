/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:33:01 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 13:33:02 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanA
{
	private :
		std::string	name;
		Weapon&		weapon;
	public :
		HumanA(std::string name, Weapon& weapon);
		void	attack() const;
};

#endif

