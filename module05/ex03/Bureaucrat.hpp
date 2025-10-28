/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:04:27 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/20 14:04:28 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <string>

class AForm;

class Bureaucrat {

	public :
		Bureaucrat( const std::string& name, int grade );
		virtual ~Bureaucrat ( void );

		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat &other);
	
	public :
		void	incrementGrade();
		void	decrementGrade();
	
	public :
		const std::string&	getName() const;
		int			getGrade() const;
	
	public :
		void 	signForm(AForm& Form) const;
		void	executeForm(const AForm& form) const ;

	public :
		class GradeTooHighException : public std::exception {
		public :
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public :
			const char* what() const throw();
		};

	private :
		const std::string	_name;
		int			_grade;

};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrate);

# endif 

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
