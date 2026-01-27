/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:31:03 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/24 13:31:04 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>() {}

template<typename T>
MutantStack<T>::~MutantStack( void ) {}

/* ************************************************************************** */

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& other): std::vector<T>(other) {}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& other) 
{
	if (this != &other)
		this = std::stack<T>::operator=(other);
	return ( *this ) ;
}

/* ************************************************************************** */

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() 
{ 
	return ( std::stack<T>::c.begin() ) ;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return ( std::stack<T>::c.end() ) ; 
}
