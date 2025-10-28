/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:46 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/20 17:06:48 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ************************************************************************** */

AForm::AForm(const std::string name, const int gradeTooSign, const int gradeTooExecute)
	: _name(name), _isSigned(false), 
	_gradeTooSign(gradeTooSign), 
	_gradeTooExecute(gradeTooExecute)
{
	if ( gradeTooSign < 1 || gradeTooExecute < 1)
	{
		throw GradeTooHighExeception();
	}
	else if (gradeTooSign > 150 || gradeTooExecute > 150)
	{
		throw GradeTooLowExeception();
	}
}

AForm::~AForm( void ) {}

AForm::AForm(const AForm& other)
	: _name(other._name), 
	_isSigned(other._isSigned), 
	_gradeTooSign(other._gradeTooSign), 
	_gradeTooExecute(other._gradeTooExecute){}

AForm&	AForm::operator=(const AForm& other)
{
	if ( this != &other )
		_isSigned = other._isSigned ;
	return ( *this );
}

/* ************************************************************************** */

const std::string&	AForm::getName() const { return (_name); }
bool			AForm::getIsSigned() const { return (_isSigned); }

// void			AForm::setName(const std::string& name) { _name = name; }
void			AForm::setIsSigned(bool value) { _isSigned = value; }

const int		AForm::getGradeTooSign() const {return (_gradeTooSign); }
const int		AForm::getGradeTooExecute() const { return (_gradeTooExecute); }

/* ************************************************************************** */

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeTooSign)
		throw AForm::GradeTooLowExeception();
	_isSigned = true;
}

bool	AForm::isSigned() const { return (_isSigned) ;}

/* ************************************************************************** */

const char*	AForm::GradeTooHighExeception::what() const throw()
{
	return ("AForm grade is too high!");
}

const char*	AForm::GradeTooLowExeception::what() const throw()
{
	return ("AForm grade is too low!");
}

const char*	AForm::FormNotSignedExeption:: what() const throw()
{
	return ("AForm is not signed !");
}

/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const AForm& AForm)
{
	os << "AForm " << AForm.getName() << " is signed status" 
	   << ", AForm is : " << (AForm.getIsSigned() ? "signed" : "not signed")
	   << ", grade to sign: " << AForm.getGradeTooSign()
	   << ", grade to execute: " << AForm.getGradeTooExecute() << std::endl;

	return ( os );
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
