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

# include "WrongCat.hpp"
# include "WrongDog.hpp"

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* Wmeta = new WrongAnimal();
	const WrongAnimal* Wj = new WrongDog();
	const WrongAnimal* Wi = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << Wj->getType() << " " << std::endl;
	std::cout << Wi->getType() << " " << std::endl;


	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	Wi->makeSound(); //will output the cat sound!
	Wj->makeSound();
	Wmeta->makeSound();

//...
	delete meta;
	delete i;
	delete j;

	delete Wmeta;
	delete Wi;
	delete Wj;

	return (0);

}
