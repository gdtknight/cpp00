/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:25:56 by yoshin            #+#    #+#             */
/*   Updated: 2025/11/02 16:49:43 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
  sIdx = 0;
  size = 0;
}

void PhoneBook::addContact(Contact const &contact) {
  contacts[(sIdx + size) % MAX_CONTACTS] = contact;
  if (size == MAX_CONTACTS)
    sIdx = (sIdx + 1) % MAX_CONTACTS;
  else
    size++;
  ;
}

// clang-format off
void PhoneBook::displayContacts() {
  std::cout << std::endl
            << "+" << "----------"
            << "+" << "----------"
            << "+" << "----------"
            << "+" << "----------" << "+" << std::endl;
  std::cout << "|"
            << std::right << std::setw(10) << "INDEX" << "|"
            << std::right << std::setw(10) << "FIRST NAME" << "|"
            << std::right << std::setw(10) << "LAST NAME" << "|"
            << std::right << std::setw(10) << "NICKNAME" << "|"
            << std::endl;
  std::cout << "+" << "----------"
            << "+" << "----------"
            << "+" << "----------"
            << "+" << "----------" << "+" << std::endl;

  for (size_t idx = 0; idx < size; idx++) {
    std::cout << "|";
    std::cout << std::right << std::setw(10) << (idx + 1) << "|"
      << std::right << std::setw(10)
      << truncateString(contacts[(sIdx + idx) % MAX_CONTACTS].getFirstName()) << "|"
      << std::right << std::setw(10)
      << truncateString(contacts[(sIdx + idx) % MAX_CONTACTS].getLastName()) << "|"
      << std::right << std::setw(10)
      << truncateString(contacts[(sIdx + idx) % MAX_CONTACTS].getNickname()) << "|"
      << std::endl;
  }
  // clang-format on
  std::cout << "+" << "----------"
            << "+" << "----------"
            << "+" << "----------"
            << "+" << "----------"
            << "+" << std::endl
            << std::endl;
}

void PhoneBook::displayContactDetails(size_t index) {
  if (index < 1 || index > size)
    throw std::out_of_range("Invalid index. Out of range.");

  Contact const &contact = contacts[(sIdx + index - 1) % MAX_CONTACTS];

  std::cout << std::endl
            << "First Name     : " << contact.getFirstName() << std::endl
            << "Last Name      : " << contact.getLastName() << std::endl
            << "Nickname       : " << contact.getNickname() << std::endl
            << "Phone Number   : " << contact.getPhoneNumber() << std::endl
            << "Darkest Secret : " << contact.getDarkestSecret() << std::endl
            << std::endl;
}

size_t PhoneBook::getSize(void) { return (size); }

std::string PhoneBook::truncateString(std::string const &str) {
  if (str.length() > 10) {
    return str.substr(0, 9) + ".";
  }
  return str;
}
