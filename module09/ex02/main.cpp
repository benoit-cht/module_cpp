/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ton_utilisateur_42 <ton_email@student.42.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 09:31:36 by ton_utilisate     #+#    #+#             */
/*   Updated: 2026/05/07 21:05:40 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

#include "PmergeMe.hpp"

template<typename T>
static void print_cont(T& cont, std::string msg);
static int string_to_int(const std::string& s);
static bool is_positive_integer(const std::string& s);
static bool parsing(int ac, char *av[], std::vector<int>& vec);

/* ============================================================================= */
/*                                                                               */
/* ============================================================================= */

int main(int ac, char *av[])
{
  std::vector<int>            vec;
  PmergeMe<std::vector<int>>  pmerge_vec;
  PmergeMe<std::list<int>>    pmerge_lst; 

  if( ac < 2 || !parsing(ac, av, vec))
  {
    std::cerr << "Error : bad argument." << std::endl;
    return ( EXIT_FAILURE );
  }
  std::list<int> lst(vec.begin(), vec.end());
  
  std::clock_t start_vec = std::clock();
  std::vector<int> sorted_vec = pmerge_vec.merge(vec);
  std::clock_t end_vec = std::clock();
  double time_vec = (double)(end_vec - start_vec) * 1000000.0 / CLOCKS_PER_SEC;

  std::clock_t start_lst = std::clock();
  std::list<int> sorted_lst = pmerge_lst.merge(lst);
  std::clock_t end_lst = std::clock();
  double time_lst = (double)(end_lst - start_lst) * 1000000.0 / CLOCKS_PER_SEC;

 
  print_cont(vec, "Before: ");
  print_cont(sorted_vec, "After: ");

  std::cout << "Time to process a range of " << vec.size() 
            << " elements with std::vector: " << time_vec << " us" << std::endl;
  
  std::cout << "Time to process a range of " << lst.size() 
            << " elements with std::list: " << time_lst << " us" << std::endl;

  return ( EXIT_SUCCESS );

}

/* ============================================================================= */
/*                       DÉFINITIONS DES FONCTION STATIC                         */
/* ============================================================================= */


static bool is_positive_integer(const std::string& s)
{
    size_t i = 0;

    if ( s.empty() ) 
      return false;

    if (s[0] == '+') 
      i = 1;
    
    if (i == s.size()) 
      return (false);    

    while (i < s.size()) 
    {
        if (!isdigit(s[i])) 
          return (false);
        i++;
    }
    
    return (true);
}

static int string_to_int(const std::string& s)
{ 
  return (static_cast<int>(strtol(s.c_str(), NULL, 10)));
}

static bool parsing(int ac, char *av[], std::vector<int>& vec)
{
  for (int i = 1; i < ac; i++) 
  {
    std::string arg = av[i];
    if (!is_positive_integer(arg)) 
    {
      std::cerr << "Error " << std::endl;
      return (false);
    }
    
    int num = string_to_int(arg);
    vec.push_back(num);
  }
  
  return (true);
}

template<typename T>
static void print_cont(T& cont, std::string msg)
{
  std::cout << msg;
  for (size_t i = 0; i < cont.size(); i++) 
  {
    std::cout << cont[i] << " ";
  }
  std::cout << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
