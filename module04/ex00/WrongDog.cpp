/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:44 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:24:46 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

/* ************************************************************************** */

WrongDog::WrongDog( void ) : WrongAnimal()
{
	_type = "WrongDog";
	std::cout << "constructor of WrongDog called " << std::endl;
}

WrongDog::~WrongDog( void )
{
	std::cout << "Destructor of WrongDog called " << std::endl;
}

/* ************************************************************************** */

WrongDog::WrongDog(const WrongDog& other)
{
	std::cout << "WrongDog copy constructor called" << std::endl;	
}

WrongDog&	WrongDog::operator=(const WrongDog& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

/* ************************************************************************** */

void	WrongDog::makeSound( void ) const
{
	std::cout << "Woooof" << std::endl;
}
