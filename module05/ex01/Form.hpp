/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:52 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/20 17:06:53 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Bureaucrat.hpp"

class Form {
	
	public :
		Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		virtual ~Form();

	public :
		const std::string&	getName() const;
		void			setName(std::string name);

		bool			getIsSigned() const;
		bool			setIsSigned(bool value);
		
		const int		getGradeTooSign() const;
		const int		getGradeTooExecute() const;

	public :
		void	beSigned(const Bureaucrat& bureaucrat);

	public :
		class GradeTooHighExeception : public std::exeception{
			public :
				const char* what() const throw();
		};

		class GradeTooLowExeception : public std::exception{
			public :
				const char* what() const throw();
		};

	private :
		const std::string	_name;
		const int		_gradeTooSign;
		const int		_gradeTooExecute;
	
	protected :
		bool		isSigned;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

# ifndef
