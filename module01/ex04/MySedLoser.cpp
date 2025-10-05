/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MySedLoser.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:38:34 by bchallat          #+#    #+#             */
/*   Updated: 2025/10/05 13:38:38 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MySedLoser.hpp"

MySedLoser::MySedLoser(std::ifstream& inputfile, std::ofstream& outputfile, std::string& s1, std::string& s2) : 
	_filename(inputfile), 
	_filereplace(outputfile), 
	_target(s1), 
	_replace(s2) 
{};

MySedLoser::~MySedLoser( void ) {} ;

std::string	MySedLoser::ReplaceOcurrences(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string	newline = "";
	size_t		start 	= 0;
	size_t		pos 	= line.find(s1, start);

	while (pos != std::string::npos)
	{
		newline += line.substr(start, pos - start);
		newline += s2;
		start = pos + s1.length();
		pos = line.find(s1, start);
	}
	newline += line.substr(start);
	return (newline);
}

void	MySedLoser::WriteInFile(std::ifstream& inputfile, std::ofstream& outputfile, std::string& s1, std::string& s2)
{
	std::string	line;
	std::string	newline;

	while(std::getline(inputfile, line))
	{
		newline = MySedLoser::ReplaceOcurrences(line, s1, s2);
		outputfile << newline << std::endl;
	}
}

