/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:55:56 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/27 10:55:58 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:AForm("PresidentialPardonForm", 25, 5), _Target(target) {}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:AForm(other), _Target(other._Target) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if ( this != &other )
	{
		AForm::operator=(other);
		_Target = other._Target;
	}
	return ( *this );
}
/* ************************************************************************** */

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned())
		//throw AForm::FormNotSigned();
	if (executor.getGrade() >= getGradeTooExecute())
		//throw AForm::GradeTooLowException();
	std::cout << _Target << "Has been pardoned by Zaphod Beeblebrox. " << std::endl;
}


/* ************************************************************************** */


