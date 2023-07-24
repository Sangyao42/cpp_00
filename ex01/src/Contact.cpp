/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:32:50 by sawang            #+#    #+#             */
/*   Updated: 2023/07/24 16:12:03 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

Contact::Contact() {}

Contact::~Contact() {}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

bool	Contact::contactIsValid() const
{
	if (this->_firstName.empty() ||
		this->_lastName.empty()||
		this->_nickname.empty()||
		this->_phoneNumber.empty()||
		this->_darkestSecret.empty())
		return (false);
	return (true);
}

void	Contact::displayContact() const
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

void	Contact::displayContactAbbriviated() const
{
	std::cout << std::setw(10) << _subField(this->_firstName) << "|";
	std::cout << std::setw(10) << _subField(this->_lastName) << "|";
	std::cout << std::setw(10) << _subField(this->_nickname) << std::endl;
}

std::string	Contact::_subField(std::string field) const
{
	if (field.length() > 10)
		return (field.substr(0,9) + ".");
	else
		return (field);
}
