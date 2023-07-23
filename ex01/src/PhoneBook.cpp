/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:33:00 by sawang            #+#    #+#             */
/*   Updated: 2023/07/23 13:10:41 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

int	PhoneBook::addContact(Contact contact)
{
	if (contact.contactIsValid() == false)
		return (EXIT_FAILURE);
	this->_contacts[this->_index_to_add] = contact;
	this->_nbContacts++;
	this->_index_to_add = this->_nbContacts % _maxContacts;
	return (EXIT_SUCCESS);
}

const Contact	*PhoneBook::searchContact(int index) const
{
	if (index < this->_nbContacts && index < _maxContacts && index >= 0)
		return (&this->_contacts[index]);
	else
	{
		std::cout << "Invalid index" << std::endl;
		return (NULL);
	}
}

void	PhoneBook::displayContacts() const
{
	int	total_contacts;
	int	i;

	if (this->_nbContacts == 0)
	{
		std::cout << "No contacts to display" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	if (this->_nbContacts > _maxContacts)
		total_contacts = _maxContacts;
	else
		total_contacts = this->_nbContacts;
	i = 0;
	while (i < total_contacts)
	{
		std::cout << std::setw(10) << i << "|";
		this->_contacts[i].displayContactAbbriviated();
		i++;
	}
}
