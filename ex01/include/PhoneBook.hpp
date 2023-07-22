/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:26:19 by sawang            #+#    #+#             */
/*   Updated: 2023/07/21 21:31:08 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <Contact.hpp>

#include <iostream>

class PhoneBook
{
	public:

		PhoneBook() : _index_to_add(0), _nbContacts(0) {};
		~PhoneBook();

		int				addContact(Contact contact);
		const Contact	*searchContact(unsigned int index) const;
		void			displayContacts() const;

	private:
		static const unsigned int	_maxContacts = 8;
		Contact						_contacts[_maxContacts];
		unsigned int				_index_to_add;
		unsigned int				_nbContacts;
};

#endif
