/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:37 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:24:40 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ************************************************************************** */

Cat::Cat( void ) : Animal()
{
	std::cout << "constructor of Cat called " << std::endl;
	_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat( void )
{
	std::cout << "Destructor of Cat called " << std::endl;
	delete this->_brain;
}

/* ************************************************************************** */

Cat::Cat(const Cat& other) : Animal(other) 
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) 
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &other) 
	{
		Animal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

/* ************************************************************************** */

void	Cat::makeSound( void ) const
{
	std::cout << "Meooow ! " << std::endl;
}

Brain* Cat::getBrain() const 
{
    return this->_brain;
}