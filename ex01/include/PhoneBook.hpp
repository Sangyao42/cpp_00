/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:26:19 by sawang            #+#    #+#             */
/*   Updated: 2023/07/24 21:54:49 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <Contact.hpp>

#include <iostream>
#include <iomanip>

class PhoneBook
{
	public:

		PhoneBook();
		~PhoneBook();

		int				addContact(Contact contact);
		const Contact	*searchContact(int index) const;
		void			displayContacts() const;
		unsigned int	getNbContacts() const;

	private:
		static const unsigned int	_maxContacts = 8;
		Contact						_contacts[_maxContacts];
		unsigned int				_index_to_add;
		unsigned int				_nbContacts;
};

#endif
