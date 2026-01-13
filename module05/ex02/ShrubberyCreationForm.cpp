/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:56:11 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/27 10:56:12 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", 145, 137), _Target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _Target(other._Target) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if ( this != &other)
	{
		AForm::operator=(other);
		_Target = other._Target;
	}
	return ( *this );
}

/* ************************************************************************** */

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
	if (!isSigned())
		throw AForm::FormNotSignedException(); 
	if (executor.getGrade() > getGradeTooExecute())
		throw AForm::GradeTooLowException();
	
	std::ofstream file((_Target + "_strubbery").c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Faile to create shrubbery file! ");
	}
	else 
	{
		file	<< "       _-_\n"
         		<< "    /~~   ~~\\\n"
			<< " /~~         ~~\\\n"
			<< "{               }\n"
			<< " \\  _-     -_  /\n"
			<< "   ~  \\\\ //  ~\n"
			<< "_- -   | | _- _\n"
			<< "  _ -  | |   -_\n"
			<< "      // \\\\";

		file.close();
	}
}	

/* ************************************************************************** */
/* ************************************************************************** */
