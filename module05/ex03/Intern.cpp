/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:57:31 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/27 10:57:32 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

static AFrom*	createShrubbery(const std::string& target);
static AFrom*	createRobotomy(const std::string& target);
static AForm*	createPresidential(const std::string& target);

/* ************************************************************************** */

Intern::Intern( void ) {}

Intern::~Intern( void ) {}

/* ************************************************************************** */

Intern::Intern(const Intern& other) { (void)other; }

Intern&	Intern::operator=(const Intern& other)
{
	(void)other;
	return ( *this ) ;
}

/* ************************************************************************** */

const char* Intern::UknownFormException::what() const throw() {
	return ("Error: Uknow form type !") ;
}

/* ************************************************************************** */

AForm*	makeForm(std::string name, std::string target) const 
{
	typedef AFrom* (*FromCreator)(const std::string&);

	static const struct
	{
		const char*	name;
		FromCreator	creator;
	}

	formTypes[] = {
		
		{"shrubbery creation", &createShrubbery}
		{"robotomy request", &createRobotomy}
		{"presidential pardon", &createPresidential}
		{NULL, NULL}
	}

	for (int i = 0; formtype[i].name != NULL ; i++)
	{
		if (name == formeTypes[i].name)
		{
			std::cout << "Intern create: " << name << std::endl;
			return (formTypes[i].creator(target)) ;
		}
	}

	throw UknownFormException();
}

/* ************************************************************************** */

static AFrom*	createShrubbery(const std::string& target)
{
	return ( new ShrubberyCreationForm(target) ) ;
}

static AFrom*	createRobotomy(const std::string& target)
{
	return ( new RobotomyRequestForm(target) ) ;
}

static AForm*	createPresidential(const std::string& target)
{
	return ( new PresidentialPardonForm(target) ) ;
}

/* ************************************************************************** */
