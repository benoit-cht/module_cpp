/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:30:57 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/24 13:30:59 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <vector>

template<typename T>
class MutantStack: public std::stack<T> {

	public :
		MutantStack( void );
		MutantStack(const MutantStack& other);
		MutantStack&	operator=(const MutantStack& other);
		virtual	~MutantStack( void );

	public :
		typedef typename std::vector<T>::container_type::iterator iterator;
		iterator	begin();
		iterator	end();

};

# include "MutantStack.tpp"

# endif
