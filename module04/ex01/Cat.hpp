/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:25:09 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:25:12 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private :
		Brain*	_brain;
	public :
		Cat( void );
		virtual ~Cat( void );
		Cat(const Cat& other);
    		Cat& operator=(const Cat& other);
	public :
		void	makeSound( void ) const;
};


#endif
