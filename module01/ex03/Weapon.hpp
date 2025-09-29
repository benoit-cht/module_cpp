/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:33:17 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/29 13:33:18 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
#define	WEAPON_HPP

#include <string>

class Weapon()
{
	private :
		std::string	type;
	public	:
		Weapon( std::string type);
		const std::string& getType() const;
		void	setType(std::string newtype);
};

#endif
