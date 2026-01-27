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

template<typename ITR>
void	Span::addRange(ITR begin, ITR end)
{
	if (_Number.size() + std::distance(begin, end) > _N)
		throw FullSpanException();
	_Number.insert(_Number.end(), begin, end);
}
