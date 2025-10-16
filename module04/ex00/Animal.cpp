/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:30 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:24:33 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

/* ************************************************************************** */

Animal::Animal( void ) 
{ 
	std::cout << "Default constructor called"<< std::endl; 
}

Animal::~Animal( void ) 
{ 
	std::cout << "Default destructor called"<< std::endl; 
}

/* ************************************************************************** */

Animal::Animal( const Animal& other ) : _type(other._type) 
{ 
	std::cout << "Copy constructor called"<< std::endl; 
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this->_type != other._type)
	{
		_type = other._type;
		std::cout << "assignement operator called " << std::endl;
	}
	return (*this);
}

/* ************************************************************************** */

std::string	Animal::getType( void ) const 
{
	std::cout << "getType meber fonction called" << std::endl;
	return (this->_type);
}

void		Animal::setType(std::string type) const
{
	this->_type = type;
}

/* ************************************************************************** */

void	Animal::makeSound( void ) const
{
	std::cout << "..." << std::endl;	
}
