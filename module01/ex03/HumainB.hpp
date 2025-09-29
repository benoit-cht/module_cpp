/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainB.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:33:08 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 13:33:10 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAINB_HPP
#define HUMAINB_HPP

#include <string>
#inlcude "Weapon.hpp"

class	HumainB
{
	private :
		std::string	name;
		Waepon&		weapon;
	public :
		HumainB(std::string name);
		void	setWeapon(Weapon& weapon);
		void	attack() const;
};

#endif

