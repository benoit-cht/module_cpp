/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ton_utilisateur_42 <ton_email@student.42.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:24:49 by ton_utilisate     #+#    #+#             */
/*   Updated: 2025/11/21 09:24:51 by ton_utilisate    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int ac, char *av[])
{
  if (ac != 2 || av[1] == NULL) {

    std::cerr << "Error: argument is invalide " << std::endl;
    return (EXIT_FAILURE);
  }
  
  std::string  input = av[1];

  try {

    RPN polishNoptaition;
    polishNoptaition.setStack(input);

  } catch(const std::exception& e)  {
    
    std::cerr << "Error:" << e.what() << std::endl;
  }

  return (EXIT_SUCCESS);
}


/* ========================================================================== */
/*                                                                            */
/* ========================================================================== */
