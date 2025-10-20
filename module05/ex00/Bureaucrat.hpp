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

#include <iostream>
#include <exeption>
#include <string>

class Bureaucrat {

	private :
		std::string	_name;
		int		_grade;

	public :
		Bureaucrat( void );
		virtual ~Bureaucrat ( void );
		Bureaucrat(const Bureaucrat& other);
		Bureaucrate& operator=(const Bureaucrat &other);
	
	public :
		std::string	getName() const;
		int		getGrade() const;
		void		setName();
		void		setGrade();

	public :
		class GradeTooHighExeption : public std::expection {
			const char* what() const throw()
		};

		class GradeTooLowExeption : public std::exeption {
			const char* what() const throw()
		};
};

# endif 
