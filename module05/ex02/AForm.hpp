/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:06:52 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/20 17:06:53 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <string>

class Bureaucrat;

class AForm {
	
	public :
		AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

	public :
		const std::string&	getName() const;
		void			setName(const std::string& name);

		bool			getIsSigned() const;
		void			setIsSigned(bool value);
		
		const int		getGradeTooSign() const;
		const int		getGradeTooExecute() const;

	public :
		void		beSigned(const Bureaucrat& bureaucrat);
		bool		isSigned() const ;
		virtual void	execute(const Bureaucrat& executor) const = 0;

	public :
		class GradeTooHighException : public std::exception{
			public :
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public :
				const char* what() const throw();
		};

		class FormNotSignedException : public std::exception{
			public :
				const char* what() const throw();
		};

	private :
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeTooSign;
		const int		_gradeTooExecute;
	
	protected :
		//bool		isSigned;
};

std::ostream&	operator<<(std::ostream& os, const AForm& AForm);

# endif
