/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:56:04 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/27 10:56:06 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:AForm("RobotomyRequestForm", 72, 45), _Target(target) 
{
	// time(0) # include <ctime>
	// std::srand(std::time(0));
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:AForm(other), _Target(other._Target) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if ( this != &other)
	{
		AForm::operator=(other);
		_Target = other._Target;
	}
	return ( *this );
}

/* ************************************************************************** */

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned())
		//throw AForm::FormSignedException();
	if (executor.getGrade() > getGradeTooExecute())
		//throw AForm::GradeTooLowException();

	std::cout << "Drilling noises: BZZZ.. " << std::endl;

	if (std::rand() % 2 == 0)
		std::cout << _Target << "Has been robotomized successfully !" << std::endl;
	else
		std::cout << "Robotomy failed for "<< _Target << "." << std::endl;
}
/* ************************************************************************** */

