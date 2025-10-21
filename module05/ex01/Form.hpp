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

#include <iostream>
#include <exception>
#include <string>

class Form {
	
	public :
		Form(std::string name);
		Form(const Form& other);
		Form& operator=(const Form& other);
		virtual ~Form();

	public :
		std::string	getName() const;
		void		setName(std::string name);

		bool		getIsSigned() const;
		bool		setIsSigned(bool value);

	public :
		//exception

	private :
		std::string	_name;
	
	protected :
		bool		isSigned;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

# ifndef
