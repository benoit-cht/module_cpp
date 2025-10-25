/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:30:46 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/24 13:30:48 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <algorithm>
# include <vector>

class Span {
	
	public :
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		virtual ~Span( void );

	public :
		void		addNumber(int newValue);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		template<typename ITR>
		void		addRange(ITR begin, ITR end);

	public :
		class FullSpanException: public std::exception 
		{
			const char* what() const throw();
		};

		class SmallSpanException: public std::exception
		{
			const char* what() const throw();
		};

	private :
		unsigned int		_N;
		std::vector<int>	_Number;
};

# endif
