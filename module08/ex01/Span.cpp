/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:30:33 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/24 13:30:35 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* ************************************************************************** */

Span::Span(unsigned int n): _N(n) {}

Span::~Span( void ) {}

/* ************************************************************************** */

Span::Span(const Span& other): _Number(other._Number), _N(other._N) {}

Span&	Span::operator=(const Span& other) 
{
	_Number = other._Number;
	_N = other._N;

	return (*this);
}

/* ************************************************************************** */

void	Span::addNumber(int newValue)
{
	if (_Number.size() >= _N)
		throw FullSpanException();
	_Number.push_back(newValue);
}

unsigned int	Span::shortestSpan() const
{
	std::vector<int>	vec = _Number;
	int			minSpan = 0;
	int			currSpan = 0;

	if (_N <= 1)
		throw SmallSpanException();
	
	std::sort(vec.begin(), vec.end());
	minSpan = vec[1] - vec[0];

	for(size_t x = 2; x < _N; x++)
	{
		currSpan = vec[x] - vec[x - 1];
		if (currSpan < minSpan)
			minSpan = currSpan;
	}
	return ( minSpan ) ;
}

unsigned int	Span::longestSpan() const
{
	std::vector<int> vec = _Number;

	if (_Number.size() < 2)
		throw SmallSpanException();
	
	std::sort(vec.begin(), vec.end());
	return ( vec.back() - vec.front() ) ;
}

/* ************************************************************************** */

const char*	Span::FullSpanException::what() const throw()
{
	return ( "Span is full " ) ;
}

const char*	Span::SmallSpanException::what() const throw()
{
	return ( "Span is small ") ;
}

