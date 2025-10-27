/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:56:47 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/27 10:56:49 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	
	public :
		ShrubberyCreationForm( void );
		ShrubberyCreationForm(const  ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const  ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm( void );

	public :
		virtual void execute(const Buraucrat& executor) const ;

	private :
		std::string	_Target;

};

#endif
