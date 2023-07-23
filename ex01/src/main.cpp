/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:25:43 by sawang            #+#    #+#             */
/*   Updated: 2023/07/23 16:45:02 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>

#include <iostream>
#include <string>

namespace cmdExec
{
	int	getUserInput(const std::string prompt, std::string *input)
	{
		std::cout << prompt << ": ";
		std::getline(std::cin, *input);
		while (!std::cin.eof())
		{
			if(isValid(input))
				
			std::cout << "Please enter a valid " << prompt << ": ";
			std::getline(std::cin, *input);
		}

		return (EXIT_SUCCESS);
	}

	int	addContact(PhoneBook *phoneBook)
	{
		Contact		contact;
		std::string	input;

		getUserInput("First Name", &input);

	}
};

int	main(int argc, char *argv[])
{
	std::string		cmd;
	PhoneBook		phoneBook;

	std::cout << "Welcome to your phonebook" << std::endl;
	std::cout << "Please enter a command (ADD, SEARCH or EXIT)" << std::endl;
	std::cout << "ADD: Add a new contact" << std::endl;
	std::cout << "SEARCH: Search for a contact" << std::endl;
	std::cout << "EXIT: Exit the phonebook" << std::endl;

	std::getline(std::cin, cmd);
	while (!std::cin.eof())
	{
		if (cmd == "ADD")
			cmdExec::addContact(&phoneBook);

	}

}
