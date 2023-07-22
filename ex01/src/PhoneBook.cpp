/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:33:00 by sawang            #+#    #+#             */
/*   Updated: 2023/07/22 08:42:17 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

int	PhoneBook::addContact(Contact contact)
{
	// if (contact == NULL)
	// 	return (-1);
	this->_contacts[this->_index_to_add] = contact;
	this->_nbContacts++;
	this->_index_to_add = this->_nbContacts % _maxContacts;
}

const Contact	*PhoneBook::searchContact(unsigned int index) const
{
	this->displayContacts();
	if (index < this->_nbContacts && index < _maxContacts && index >= 0)
		return (&this->_contacts[index]);
	else
		return (NULL);
}

void	PhoneBook::displayContacts() const
{
}
