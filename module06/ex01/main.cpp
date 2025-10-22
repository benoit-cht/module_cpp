/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:36:22 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/22 15:36:50 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"
# include <iostream>

int main() {
	
	Data data;
	data.value = 42;
	data.name = "Test";

	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "Deserialized pointer: " << deserialized << std::endl;
	std::cout << "Values match: " << (deserialized == &data) << std::endl;

	return EXIT_SUCCESS;
}

