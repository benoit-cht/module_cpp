/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:25:00 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:25:03 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# include "Brain.hpp"

class	Animal {

	protected :
		std::string	_type;

	public :
		Animal( void );
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal( void );
	public :
		std::string	getType( void ) const;
		void		setType( std::string type );

	public :
		virtual void	makeSound( void ) const;
};

#endif
