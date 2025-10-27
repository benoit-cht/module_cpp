/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:04:20 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/20 14:04:22 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

/* ************************************************************************** */

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw	Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw	Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat( void ) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade){}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if ( this != &other )
		_grade = other._grade ;
	return ( *this );
}

/* ************************************************************************** */

const std::string&	Bureaucrat::getName() const { return (_name); }
int			Bureaucrat::getGrade() const{ return (_grade); }

/* ************************************************************************** */

void	Bureaucrat::signForm(AForm& form) const 
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& exception) {
		std::cout << _name << " couldn't sign " << form.getName() << " because " << exception.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const 
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	
	}catch (const std::exception& e){
		std::cout << _name << " cloudn't execute " << form.getName() << " because " << e.what() << sdt::endl;

	}
}

/* ************************************************************************** */

void	Bureaucrat::incrementGrade()
{
	if (_grade <=1)
		throw	Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw	Bureaucrat::GradeTooLowException();
	_grade++;
}

/* ************************************************************************** */

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ( "Grade is too high !" );
}
const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}

/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return ( os );
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
