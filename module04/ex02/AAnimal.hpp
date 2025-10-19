/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:25:00 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:25:03 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

# include "Brain.hpp"

class	AAnimal {

	protected :
		std::string	_type;

	public :
		AAnimal( void );
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal( void );
	public :
		std::string	getType( void ) const;
		void		setType( std::string type );

	public :
		virtual void	makeSound( void ) const = 0;
};

#endif
