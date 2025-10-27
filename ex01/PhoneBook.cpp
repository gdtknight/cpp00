/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:25:56 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/27 12:18:38 by yoshin           ###   ########.fr       */
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

void PhoneBook::displayContacts() {
  std::cout << "|";
  std::cout << std::right << std::setw(10) << "INDEX" << "|";
  std::cout << std::right << std::setw(10) << "FIRST NAME" << "|";
  std::cout << std::right << std::setw(10) << "LAST NAME" << "|";
  std::cout << std::right << std::setw(10) << "NICKNAME" << "|" << std::endl;
  std::cout << "|";
  std::cout << "----------" << "|";
  std::cout << "----------" << "|";
  std::cout << "----------" << "|";
  std::cout << "----------" << "|" << std::endl;

  // clang-format off
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
}

void PhoneBook::displayContactDetails(size_t index) {
  if (index < 1 || index > size)
    throw std::out_of_range("Invalid index. Out of range.");

  Contact const &contact = contacts[(sIdx + index - 1) % MAX_CONTACTS];

  std::cout << "First Name: " << contact.getFirstName() << std::endl;
  std::cout << "Last Name: " << contact.getLastName() << std::endl;
  std::cout << "Nickname: " << contact.getNickname() << std::endl;
  std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
  std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

std::string PhoneBook::truncateString(std::string const &str) {
  if (str.length() > 10) {
    return str.substr(0, 9) + ".";
  }
  return str;
}
