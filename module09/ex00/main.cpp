/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ton_utilisateur_42 <ton_email@student.42.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:30:00 by ton_utilisate     #+#    #+#             */
/*   Updated: 2025/11/21 09:30:02 by ton_utilisate    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char *av[])
{
  if( ac != 2 || av[1] == NULL )
  {
    std::cerr << "Error : bad number of argument or not file." << std::endl;
    return ( EXIT_FAILURE );
  }

  std::string input = av[1];

  try {
    
    DataFile  data;
    InputFile inpufile(input);
    
    data.parseFile();

    data.setMapFile();
    
    inpufile.be_calculator_value(input, data);

    //std::cout << "(Test data)2015-06-05: " << data.getExchangeRate("2015-06-05") << std::endl;
    //std::cout << "(Test input)2009-02-01: " << inpufile.getExchangeRate("2009-02-01") << std::endl;

  } catch (const std::exception& e){

    std::cout << "Error data: " << e.what() << std::endl;
  }

  return ( EXIT_SUCCESS );
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

