/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:18:27 by sawang            #+#    #+#             */
/*   Updated: 2023/07/19 22:52:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static	std::string	string_to_upper(std::string str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		str[i] = static_cast<char>(std::toupper(static_cast<unsigned char>(str[i])));
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	unsigned int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (argv[i])
		{
			std::cout << string_to_upper(argv[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
