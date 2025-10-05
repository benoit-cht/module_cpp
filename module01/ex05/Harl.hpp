/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:06:29 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/05 15:06:32 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl{
	private :
		void	_debug( void );
		void	_info( void );
		void	_warning( void );
		void	_error( void );
	public :
		void	complain(std::string level);
};

#endif
