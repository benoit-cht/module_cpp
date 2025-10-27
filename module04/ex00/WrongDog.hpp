/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:25:17 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:25:21 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public :
		WrongDog( void );
		WrongDog(const WrongDog& other);
		WrongDog& operator=(const WrongDog& other);
		virtual ~WrongDog( void );
	
	public :
		void	makeSound( void ) const;
};

# endif
