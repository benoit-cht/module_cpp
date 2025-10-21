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

Form::Form(const std::string name, const int gradeTooSign, const int gradeTooExecute)
	: _nam(name), isSigned(false), _gradeTooSign(gradeTooSign), _gradeTooExecute(gradeTooExecute)
{
	if ( gradeTooSign < 1 || gradeTooExecute < 1)
	{
		throw GradeTooHighException();
	}
	else if (gradeTooSign > 150 || gradeTooExecute > 150)
	{
		throw GradeTooLowException();
	}
}

Form::~Form( void ) {}

Form::Form(const Form& other)
	: _name(other._name), isSigned(other.isSigned), _gradeTooSign(other.gradeTooSign), _gradeTooExecute(other.gradeTooExecute){}

Form&	Form::operator=(const Form& other)
{
	if ( this != other )
		isSigned = other.isSigned ;
	return ( *this );
}

/* ************************************************************************** */

const std::string&	Form::getName() const { return (_name); }
bool			Form::getIsSigned() const { return (isSigned); }

void			Form::setName(std::string& name) { _name = name; }
void			Form::setIsSigned(bool value) { isSigned = value; }

const int		Form::getGradeTooSign() const {return (_gradeTooSign); }
const int		Form::getGradeTooExecute() const { return (_gradeTooExecute); }

/* ************************************************************************** */

void	Form::beSigned(const Bureaucrat& bureaucrat);
{
	if (buraucrat.getGrade() > _gradeTooSign)
		throw Form::GradTooLowException();
	_isSigned = true;
}

/* ************************************************************************** */

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "Form" << form.getName() << "is signed status" 
	   << ", form is signed" << (form.getIsSigned() ? "signed" : "not signed")
	   << ", grade to sign: " << form.getGradeTooSign()
	   << ", grade to execute: " << form.getGradeTooExecute() ;

	return ( os );
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
