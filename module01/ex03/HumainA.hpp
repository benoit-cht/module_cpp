/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainA.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:33:01 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 13:33:02 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAINA_HPP
#define HUMAINA_HPP

#include <string>
#inlcude "Weapon.hpp"

class	HumainA
{
	private :
		std::string	name;
		Waepon&		weapon;
	public :
		HumainA(std::string name, Weapon& weapon);
		void	attack() const;
};

#endif

