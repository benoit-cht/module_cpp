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

class	MySedLoser 
{
	private :
		std::ifstream&	_filename;
		std::ofstream&	_filereplace;
		std::string	_target;
		std::string	_replace;
	public :
		MySedLoser(std::ifstream& inputfile, std::ofstream& outputfile, std::string& s1, std::string& s2);
		~MySedLoser ( void );
	public :
		std::string	ReplaceOcurrences(const std::string& line, const std::string& s1, const std::string& s2);
		void		WriteInFile(std::ifstream& infile, std::ofstream& outfile, std::string& s1, std::string& s2);
};

#endif
