/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 10:41:29 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/13 10:41:31 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	private :
		unsigned int			_hitPoint;
		unsigned int			_energyPoint;
		unsigned int			_attackDamage
		const std::string	_name;
	
	public :
		ClapTrap ( void );
		ClapTrap (const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~CalpTrap();
	
	public :
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
}
# endi
