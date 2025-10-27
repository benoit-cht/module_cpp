/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:57:41 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/27 10:57:42 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>

class AForm;

class Intern {
	
	public :
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		virtual ~Intern( void );
	
	public :
		AForm*	makeForm(std::string name, std::string target) const ; 
};

# endif
