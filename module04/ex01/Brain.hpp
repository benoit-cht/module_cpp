/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:30:59 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:31:00 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain {

	private :
		std::string _ideas[100] ;
	
	public :
		Brain( void );
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		virtual	~Brain( void );
	
	public :
		std::string	getIdeas(unsigned int index) const;
		void		setIdeas(const std::string str, unsigned int index);


};

#endif
