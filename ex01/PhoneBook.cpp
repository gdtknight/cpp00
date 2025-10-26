/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:25:56 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/26 22:30:07 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "PhoneBook.hpp"

static std::string truncateString(const std::string &str);

PhoneBook::PhoneBook(void) {
  sIdx = 0;
  eIdx = 0;
}

void PhoneBook::addContact(const Contact &contact) {
  if ((eIdx + 1) % (MAX_CONTACTS + 1) == sIdx)
    sIdx = (sIdx + 1) % (MAX_CONTACTS + 1);
  contacts[eIdx] = contact;
  eIdx = (eIdx + 1) % (MAX_CONTACTS + 1);
}

void PhoneBook::displayContacts() {
  std::cout << "|";
  std::cout << std::right << std::setw(10) << "INDEX" << "|" << std::right
            << std::setw(10) << "FIRST NAME" << "|" << std::right
            << std::setw(10) << "LAST NAME" << "|" << std::right
            << std::setw(10) << "NICKNAME" << "|" << std::endl;
  for (size_t i = sIdx; (i + 1) % MAX_CONTACTS != eIdx;
       i = (i + 1) % MAX_CONTACTS) {
    std::cout << "|";
    std::cout << std::right << std::setw(10) << i + 1 << "|" << std::right
              << std::setw(10) << truncateString(contacts[i].getFirstName())
              << "|" << std::right << std::setw(10)
              << truncateString(contacts[i].getLastName()) << "|" << std::right
              << std::setw(10) << truncateString(contacts[i].getNickname())
              << "|" << std::endl;
  }
}

void PhoneBook::displayContactDetails(size_t index) {
  if ((sIdx <= eIdx && sIdx + index < eIdx) ||
      (eIdx < sIdx && sIdx + index < eIdx + 8)) {
    const Contact &contact = contacts[index - 1];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
  } else {
    throw std::out_of_range("Invalid index. Out of range.");
  }
}

std::string truncateString(const std::string &str) {
  if (str.length() > 10) {
    return str.substr(0, 9) + ".";
  }
  return str;
}
