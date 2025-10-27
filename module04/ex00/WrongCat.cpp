/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:37 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:24:40 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* ************************************************************************** */

WrongCat::WrongCat( void ) : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "constructor of WrongCat called " << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "Destructor of WrongCat called " << std::endl;
}

/* ************************************************************************** */

WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return (*this);
}

/* ************************************************************************** */

void	WrongCat::makeSound( void ) const
{
	std::cout << "Meooow ! " << std::endl;
}
