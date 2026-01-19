/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:19:16 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/22 17:19:18 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base {
	
	public :
		Base();
		virtual ~Base();
};

class A : public Base {
	
	public :
		A();
		virtual ~A();
};

class B : public Base {
	
	public :
		B();
		virtual ~B();
};

class C : public Base {

	public :
		C();
		virtual ~C();
};

# endif


/* ************************************************************************** */
/*                                                                            */
/* ************************************************************************** */
