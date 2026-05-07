/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ton_utilisateur_42 <ton_email@student.42.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:31:42 by ton_utilisate     #+#    #+#             */
/*   Updated: 2026/05/07 21:03:12 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP_INCLUDED
#define PMERGEME_HPP_INCLUDED

#include <iostream>

template<typename Container>
class PmergeMe {

  public:
    PmergeMe( void );
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    virtual   ~PmergeMe( void );

  public:
    Container merge(const Container& raw_cont);
    Container fusion(const Container& cont1, const Container& cont2);
  
  private:
    Container _container;

};

/* ============================================================================= */
/*    DÉFINITIONS DES MÉTHODES (doivent être dans le .hpp en C++98)              */
/* ============================================================================= */

template<typename Container>
PmergeMe<Container>::PmergeMe(void) {}

template<typename Container>
PmergeMe<Container>::~PmergeMe(void) {}

/* ************************************************************************** */

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& other) { *this = other; }

template<typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& other) 
{
    if (this != &other) 
    {
        this->_container = other._container;
    }
    return ( *this );
}

/* ************************************************************************** */

template<typename Container>
Container PmergeMe<Container>::fusion(const Container& cont1, const Container& cont2)
{
  Container fusion;
  typename  Container::const_iterator itr1 = cont1.begin();
  typename  Container::const_iterator itr2 = cont2.begin();

  while (itr1 != cont1.end() && itr2 != cont2.end())
  {
    if ( *itr1 < *itr2 )
    {
      fusion.push_back(*itr1);
      itr1++;
    }
    else
    {
      fusion.push_back(*itr2);
      itr2++;
    }
  }
  
  while (itr1 != cont1.end())
  {
    fusion.push_back(*itr1);
    itr1++;
  }

  while (itr2 != cont2.end())
  {
    fusion.push_back(*itr2);
    itr2++;
  }

  return ( fusion );
}

template<typename Container>
Container PmergeMe<Container>::merge(const Container& cont)
{
  if (cont.size() <= 1)
  {
    return cont;
  }

  typename Container::const_iterator it = cont.begin();
  typename Container::const_iterator mid = cont.begin();
  std::advance(mid, cont.size() / 2);

  Container cont1(it, mid);
  Container cont2(mid, cont.end());

  cont1 = this->merge(cont1);
  cont2 = this->merge(cont2);

  return ( this->fusion(cont1, cont2) );
}

#endif // !PMERGEME_HPP_INCLUDED

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

