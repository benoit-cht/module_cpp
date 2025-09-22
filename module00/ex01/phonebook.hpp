/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <bchallat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:07:37 by bchallat          #+#    #+#             */
/*   Updated: 2025/09/15 13:07:38 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "contact.hpp"

class	PhoneBook {

	private:
		Contact contact[8];
		int	numb_contact;
		int	last_add;
	
	public:
		PhoneBook();
		void	add_contact(const Contact& c);
		void	search_contact() const;

};

#endif
