/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:25:54 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/27 12:02:00 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#define MAX_CONTACTS 8

class PhoneBook {
public:
  PhoneBook(void);

  void addContact(Contact const &contact);
  void displayContacts(void);
  void displayContactDetails(size_t index);

private:
  size_t sIdx;
  size_t size;
  Contact contacts[MAX_CONTACTS];

  static std::string truncateString(std::string const &str);
};

#endif
