/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:44 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:24:46 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* ************************************************************************** */

Dog::Dog( void ) : AAnimal()
{
	std::cout << "constructor of Dog called " << std::endl;
	_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog( void )
{
	std::cout << "Destructor of dog called " << std::endl;
	delete this->_brain;
}

/* ************************************************************************** */

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}
/* ************************************************************************** */

void	Dog::makeSound( void ) const
{
	std::cout << "Woooof" << std::endl;
}
