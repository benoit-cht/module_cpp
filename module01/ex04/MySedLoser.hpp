/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySedLoser.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:54:26 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/05 12:54:29 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSEDLOSER_HPP
#define MYSEDLOSER_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class	MySedLoser 
{
	private :
		string	_filename;
		string	_filereplace;
		string	_target;
		string	_replace;
	public :
		MySedLoser(string& _filename, string& _filereplace, string& _target, string& _replace); 
		~MySedLoser ( void );
	public :
		std::string	ReplaceOcurrences(const string& line, const string& s1, const string& s2);
};

#endif
