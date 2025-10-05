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
	public :
		void	_Debug( void );
		void	_Info( void );
		void	_Warning( void );
		void	_Error(void );
	private :
		void	complain(std:string level);
};

#endif
