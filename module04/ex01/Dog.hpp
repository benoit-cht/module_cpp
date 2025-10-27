/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:25:17 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:25:21 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	private :
		Brain*	_brain;

	public :
		Dog( void );
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual ~Dog( void );
		
	public :
		void	makeSound( void ) const;
		Brain*	getBrain() const;
};

# endif
