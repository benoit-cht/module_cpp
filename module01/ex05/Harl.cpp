/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 15:06:20 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/05 15:06:23 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	void	(Harl::*f[4])() = {&Harl::_debug,
				&Harl::_info,
				&Harl::_warning,
				&Harl::_error};
	std::string	list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int index=0; index < 4; index++)
	{
		if (level == list[index])
			return ((this->*f[index])());	
	}
	std::cout << "[ Probably complaining about insignificant "
              << "problems ]" << std::endl;
}

void	Harl::_debug(void) 
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void) 
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::_warning(void) 
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void) 
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
