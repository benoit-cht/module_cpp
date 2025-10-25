/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:29:15 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/24 13:29:17 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <vector>
# include <list>
# include <iostream>

int	main ()
{
	std::vector<int>	vec = {1, 2, 3, 4, 5};
	std::list<int>		lis = {5, 10, 15, 20};

	try
	{
		std::vector<int>::iterator	itv = easyfind(vec, 5);
		std::list<int>::iterator	itl = easyfind(lis, 5);
		std::cout << "Found<vector>: " << *itv << std::endl;
		std::cout << "Found<list>  : " << *itl << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator itv = easyfind(vec, 0);
		std::list<int>::iterator itl = easyfind(lis, 0);
		std::cout << "Found<vector>: " << *itv << std::endl;
		std::cout << "Found<list>  : " << *itl << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return EXIT_SUCCESS ;
}
