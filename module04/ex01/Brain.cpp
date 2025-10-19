/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:30:54 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:30:56 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


/* ************************************************************************** */

Brain::Brain( void )
{
	std::cout << "Default Brain constructor called " << std::endl;
}

virtual	Brain::~Brain( void )
{
	std::cout << "Default Brain constructor called" << std::endl;
}

/* ************************************************************************** */

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy called" << std::endl;

	for (int index, index < 100, index++)
		this->_ideas[index] = other._ideas[index];
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Operator assigment called" << std::endl;

	for (int index, index < 100, index++)
		this->_ideas[index] = other._ideas[index];
	return (*this);
}

/* ************************************************************************** */

std::string	getIdeas(unsigned int index) const
{
	if ( index >= 100 )
		std::err << "This ideas is not in the array !" << std::endl;
	else
		return (*this->_ideas[index]);
	return ("\0");
}		

void		setIdeas(const std::string str, unsigned int index)
{
	if (index >= 100 || str == "\0")
		std::err << "Dont can't change ideas" << std::endl;
	else
		*this->_ideas[index] == str;
}
/* ************************************************************************** */
