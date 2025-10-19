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

Dog::Dog( void ) : Animal()
{
	_type = "Dog";
	std::cout << "constructor of Dog called " << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Destructor of dog called " << std::endl;
}

/* ************************************************************************** */

Dog::Dog(const Dog& other)
{
	std::cout << "Dog copy constructor called" << std::endl;	
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

/* ************************************************************************** */

void	Dog::makeSound( void ) const
{
	std::cout << "Woooof" << std::endl;
}
