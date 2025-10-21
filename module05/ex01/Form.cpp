/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:46 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/20 17:06:48 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

/* ************************************************************************** */

Form::Form(std::string name): _nam(name) , isSigned(false) {}

Form::~Form( void ) {}


Form::Form(const Form& other): _name(other._name), isSigned(other.isSigned) {}

Form&	Form::operator=(const Form& other)
{
	if ( this != other )
		_name = other._name, isSigned = other.isSigned ;
	return ( *this );
}

/* ************************************************************************** */

std::string	Form::getName() const { return (_name) }
bool		Form::getIsSigned() const { return (isSigned) }

void		Form::setName(std::string& name) { _name = name; }
void		Form::setIsSigned(bool value) { isSigned = value; }

/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << form.getName() << ", form is signed" << form.getIsSigned();
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
