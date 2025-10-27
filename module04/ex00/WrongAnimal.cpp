/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:30 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:24:33 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

/* ************************************************************************** */

WrongAnimal::WrongAnimal( void ) 
{ 
	std::cout << "Default constructor called"<< std::endl; 
}

WrongAnimal::~WrongAnimal( void ) 
{ 
	std::cout << "Default destructor called"<< std::endl; 
}

/* ************************************************************************** */

WrongAnimal::WrongAnimal( const WrongAnimal& other ) : _type(other._type) 
{ 
	std::cout << "Copy constructor called"<< std::endl; 
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this->_type != other._type)
	{
		_type = other._type;
		std::cout << "assignement operator called " << std::endl;
	}
	return (*this);
}

/* ************************************************************************** */

std::string	WrongAnimal::getType( void ) const 
{
	std::cout << "getType meber fonction called" << std::endl;
	return (this->_type);
}

void		WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

/* ************************************************************************** */

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "..." << std::endl;	
}
