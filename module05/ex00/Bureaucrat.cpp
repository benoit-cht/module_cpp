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

/* ************************************************************************** */

Bureacrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw	Bureaucrat::GradeTooHighExeception();
	else if (grade > 150)
		throw	Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat( void ) {}

/* ************************************************************************** */

const std::string	Bureaucrat::getName() const { return (_name); }
int			Bureaucrat::getGrade() const{ return (_grade); }

/* ************************************************************************** */

void	Bureaucrat::incrementGrade()
{
	if (_grade <=1)
		throw	Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrate::decrementGrade()
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
	os << bureaucrat::getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return ( os );
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
