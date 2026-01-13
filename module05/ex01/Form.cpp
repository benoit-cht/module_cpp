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
#include "Bureaucrat.hpp"

/* ************************************************************************** */

Form::Form(const std::string name, const int gradeTooSign, const int gradeTooExecute)
	: _name(name), _isSigned(false), _gradeTooSign(gradeTooSign), _gradeTooExecute(gradeTooExecute)
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

Form::~Form( void ) {}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _gradeTooSign(other._gradeTooSign), _gradeTooExecute(other._gradeTooExecute){}

Form&	Form::operator=(const Form& other)
{
	if ( this != &other )
		_isSigned = other._isSigned ;
	return ( *this );
}

/* ************************************************************************** */

const std::string&	Form::getName() const { return (_name); }
bool			Form::getIsSigned() const { return (_isSigned); }

// void			Form::setName(const std::string& name) { _name = name; }
void			Form::setIsSigned(bool value) { _isSigned = value; }

const int		Form::getGradeTooSign() const {return (_gradeTooSign); }
const int		Form::getGradeTooExecute() const { return (_gradeTooExecute); }

/* ************************************************************************** */

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeTooSign)
		throw Form::GradeTooLowExeception();
	_isSigned = true;
}

/* ************************************************************************** */

const char*	Form::GradeTooHighExeception::what() const throw()
{
	return ("Form grade is too high!");
}

const char*	Form::GradeTooLowExeception::what() const throw()
{
	return ("Form grade is too low!");
}

/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << " is signed status" 
	   << ", form is : " << (form.getIsSigned() ? "signed" : "not signed")
	   << ", grade to sign: " << form.getGradeTooSign()
	   << ", grade to execute: " << form.getGradeTooExecute() << std::endl;

	return ( os );
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
