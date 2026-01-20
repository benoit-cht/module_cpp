/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:46:05 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/28 14:46:06 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
# include "ScalarConverter.hpp"

int main(int ac, char *av[])
{    
    if (ac == 2)
    {
      ScalarConverter::convert(av[1]);
      return ( EXIT_SUCCESS );
    }
    else
    {
      std::cerr << "Error : Number of incorrect arguments " << std::endl;
      return ( EXIT_FAILURE );
    }
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

