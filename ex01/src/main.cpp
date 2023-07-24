/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:25:43 by sawang            #+#    #+#             */
/*   Updated: 2023/07/24 16:37:00 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <Contact.hpp>

#include <iostream>
#include <string>

namespace cmdExec
{
	bool	IsValidStr(const std::string input)
	{
		int	i;

		if (input.empty())
			return (false);
		i = 0;
		while (i < input.length())
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
		while (i < input.length())
		{
			if (!std::isdigit(input[i]))
				return (false);
			i++;
		}
		return (true);
	}

	int	GetUserInput(const std::string prompt, std::string *input, bool (*IsValid)(const std::string))
	{
		std::cout << prompt << ": ";
		std::getline(std::cin, *input);
		while (!(*IsValid)(*input))
		{
			std::cout << "Please enter a valid " << prompt << ": ";
			std::getline(std::cin, *input);
		}
		return (EXIT_SUCCESS);
	}

	int	AddContact(PhoneBook *phoneBook)
	{
		Contact		contact;
		std::string	input;

		if (GetUserInput("First Name", &input, IsValidStr));
			contact.setFirstName(input);
		if (GetUserInput("Last Name", &input, IsValidStr));
			contact.setLastName(input);
		if (GetUserInput("Nickname", &input, IsValidStr));
			contact.setNickname(input);
		if (GetUserInput("Phone Number", &input, IsValidDigit));
			contact.setPhoneNumber(input);
		if (GetUserInput("Darkest Secret", &input, IsValidStr));
			contact.setDarkestSecret(input);
		return (phoneBook->addContact(contact));
	}

	int SearchContact(PhoneBook phoneBook)
	{
		std::string	input;

		phoneBook.displayContacts();
		if (GetUserInput("Index to search", &input, IsValidDigit))
		{
			phoneBook.searchContact(std::stoi(input))->displayContact();
			return (EXIT_SUCCESS);
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
			{
				std::cerr << "Failed to add contact" << std::endl;
				return (EXIT_FAILURE);
			}
		}
		else if (cmd == "SEARCH")
		{
			if (cmdExec::SearchContact(phoneBook))
			{
				std::cerr << "Failed to search contact" << std::endl;
				return (EXIT_FAILURE);
			}
		}
		else if (cmd == "EXIT")
			return (EXIT_SUCCESS);
		else
			std::cout << "Invalid command" << std::endl;\
		std::getline(std::cin, cmd);
	}
	return (EXIT_SUCCESS);
}
