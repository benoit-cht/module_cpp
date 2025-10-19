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

Brain::~Brain( void )
{
	std::cout << "Default Brain constructor called" << std::endl;
}

/* ************************************************************************** */

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy called" << std::endl;

	for (int index = 0; index < 100; index++)
		this->_ideas[index] = other._ideas[index];
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Operator assigment called" << std::endl;

	for (int index = 0; index < 100; index++)
		this->_ideas[index] = other._ideas[index];
	return (*this);
}

/* ************************************************************************** */

std::string	Brain::getIdeas(unsigned int index) const
{
	if ( index >= 100 )
		std::cerr << "This ideas is not in the array !" << std::endl;
	else
		return (this->_ideas[index]);
	return ("\0");
}		

void		Brain::setIdeas(const std::string& str, unsigned int index)
{
	if (index >= 100 || str == "\0")
		std::cerr << "Dont can't change ideas" << std::endl;
	else
		this->_ideas[index] = str;
}
/* ************************************************************************** */
