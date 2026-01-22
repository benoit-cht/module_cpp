/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:28:06 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/22 17:28:08 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate( void ) 
{
    std::srand(std::time(NULL));
    int const random = std::rand() % 3;

    if (random == 0) return ( new A() );
    if (random == 1) return ( new B() );
    if (random == 2) return ( new C() );

    return ( NULL );
}

void identify(Base* p)
{
    if (p)
    {
      if (dynamic_cast<A*>(p))  std::cout << "ptr points to class A" << std::endl;
      if (dynamic_cast<B*>(p))  std::cout << "ptr points to class B" << std::endl;
      if (dynamic_cast<C*>(p))  std::cout << "ptr points to class C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "ptr ref to class A " << std::endl;
   
    } catch (...) {
    
    }    
    try {
        static_cast<void>(dynamic_cast<B&>(p));
        std::cout << "ptr ref to class B" << std::endl;
    } catch (...) {
    
    }      
    try {
      static_cast<void>(dynamic_cast<C&>(p));
      std::cout << "ptr ref to class C" << std::endl;
    } catch (...) {

    }
}
    


int main() 
{
  for (int i=0; i <= 5; i++){
    Base* base = generate();

    identify(base);    // Affiche "A", "B", ou "C" aléatoirement
    identify(*base);   // Même résultat, mais avec une référence

    delete base;       // Libère la mémoire
    std::cout << "---------------------" << std::endl;
  }
}

