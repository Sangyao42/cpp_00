/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:25:43 by sawang            #+#    #+#             */
/*   Updated: 2023/09/04 17:03:24 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>

#include <cstdlib>
#include <iostream>
#include <string>

typedef bool (*IsValid)(const std::string);

namespace cmdExec
{
	bool	IsValidStr(const std::string input)
	{
		int	i;

		if (input.empty())
			return (false);
		i = 0;
		while (i < (static_cast<int>(input.length())))
		{
			if (!std::isalpha(input[i]))
				return (false);
			i++;
		}
		return (true);
	}

	bool	IsValidDigit(const std::string input)
	{
		int	i;

		if (input.empty())
			return (false);
		i = 0;
		if (input[0] == '+')
			i++;
		while (i < (static_cast<int>(input.length())))
		{
			if (!std::isdigit(input[i]))
				return (false);
			i++;
		}
		return (true);
	}

	bool IsValidDarkSecret(const std::string input)
	{
		if (input.empty())
			return (false);
		return (true);
	}

	int	GetUserInput(const std::string prompt, std::string *input, IsValid IsValid)
	{
		std::cout << prompt << ": ";
		std::getline(std::cin, *input);
		while (!std::cin.eof())
		{
			if (IsValid && !(*IsValid)(*input))
			{
				std::cerr << "Please enter a valid " << prompt << ": ";
				std::getline(std::cin, *input);
			}
			else
				return (EXIT_SUCCESS);
		}
		return (EXIT_FAILURE);
	}

	int	AddContact(PhoneBook *phoneBook)
	{
		Contact		contact;
		std::string	input;

		if (GetUserInput("First Name", &input, IsValidStr) == EXIT_SUCCESS)
			contact.setFirstName(input);
		else
			return (EXIT_FAILURE);
		if (GetUserInput("Last Name", &input, IsValidStr) == EXIT_SUCCESS)
			contact.setLastName(input);
		else
			return (EXIT_FAILURE);
		if (GetUserInput("Nickname", &input, IsValidStr) == EXIT_SUCCESS)
			contact.setNickname(input);
		else
			return (EXIT_FAILURE);
		if (GetUserInput("Phone Number", &input, IsValidDigit) == EXIT_SUCCESS)
			contact.setPhoneNumber(input);
		else
			return (EXIT_FAILURE);
		if (GetUserInput("Darkest Secret", &input, IsValidDarkSecret) == EXIT_SUCCESS)
			contact.setDarkestSecret(input);
		else
			return (EXIT_FAILURE);
		return (phoneBook->addContact(contact));
	}

	int SearchContact(PhoneBook phoneBook)
	{
		std::string		input;
		const Contact	*contact;

		phoneBook.displayContacts();
		if (phoneBook.getNbContacts() == 0)
			return (EXIT_SUCCESS);
		if (GetUserInput("Index to search", &input, IsValidDigit) == EXIT_SUCCESS)
		{
			contact = phoneBook.searchContact(atoi(input.c_str()));
			if (contact != NULL)
			{
				contact->displayContact();
				return (EXIT_SUCCESS);
			}
			else
				return (EXIT_FAILURE);
		}
		else
			return (EXIT_FAILURE);
	}
};


int	main(int argc, char *argv[])
{
	std::string		cmd;
	PhoneBook		phoneBook;

	(void)	argc;
	(void)	argv;
	std::cout << "Welcome to your phonebook" << std::endl;
	std::cout << "Please enter a command (ADD, SEARCH or EXIT)" << std::endl;
	std::cout << "ADD: Add a new contact" << std::endl;
	std::cout << "SEARCH: Search for a contact" << std::endl;
	std::cout << "EXIT: Exit the phonebook" << std::endl;

	std::getline(std::cin, cmd);
	while (!std::cin.eof())
	{
		if (cmd == "ADD")
		{
			if (cmdExec::AddContact(&phoneBook))
				std::cerr << "Failed to add contact" << std::endl;
			else
				std::cout << "Contact added" << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			if (cmdExec::SearchContact(phoneBook))
				std::cerr << "Failed to search contact" << std::endl;
		}
		else if (cmd == "EXIT")
			return (EXIT_SUCCESS);
		else
			std::cerr << "Invalid command" << std::endl;
		std::getline(std::cin, cmd);
	}
	return (EXIT_FAILURE);
}
