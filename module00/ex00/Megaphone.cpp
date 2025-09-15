/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchallat <bchallat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:12:48 by bchallat          #+#    #+#             */
/*   Updated: 2025/07/04 14:12:49 by bchallat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

int	main(int argc, char **args)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int index=1; args[index] != NULL; index++)
		{
			for (int length=0; args[index][length]; length++)
			{
				if (isalpha(args[index][length]))
					std::cout << (char) std::toupper(args[index][length]);
				else
					std::cout << args[index][length];
			}
		}
	}
	std::cout << "" << std::endl;
}
