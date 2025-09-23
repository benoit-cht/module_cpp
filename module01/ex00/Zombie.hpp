/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 10:50:29 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/23 10:50:32 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <>
#include <>

class Zombie {

	private:
		std::string	name;
	public:
		Zombie	*newzombie( std::string name );
};

#endif
