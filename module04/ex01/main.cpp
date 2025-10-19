/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:24:52 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/15 13:24:54 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const int arraySize = 4;
	Animal* animals[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2) 
			animals[i] = new Dog(); 
		else
            		animals[i] = new Cat();
	}

	for (int i = 0; i < arraySize; i++)
        	delete animals[i];

    return EXIT_SUCCESS;
}

