/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:40:05 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/22 15:40:06 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <string>

struct	Data 
{
	int value;
	std::string name;
};

class Serializer {
	public :
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private :
		Serializer( void );
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer( void );
};

# endif

/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */

