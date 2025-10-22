#include <iomanip>
#include <iostream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : num_contacts(0), oldest_contact_index(0) {}

void PhoneBook::addContact(const Contact &contact) {
  if (num_contacts < 8) {
    contacts[num_contacts] = contact;
    num_contacts++;
  } else {
    // Replace the oldest contact
    contacts[oldest_contact_index] = contact;
    oldest_contact_index = (oldest_contact_index + 1) % 8;
  }
}

static std::string truncateString(const std::string &str) {
  if (str.length() > 10) {
    return str.substr(0, 9) + ".";
  }
  return str;
}

void PhoneBook::displayContacts() const {
  std::cout << "|";
  std::cout << std::right << std::setw(10) << "INDEX" << "|"
            << std::right << std::setw(10) << "FIRST NAME" << "|"
            << std::right << std::setw(10) << "LAST NAME" << "|"
            << std::right << std::setw(10) << "NICKNAME" << "|"
            << std::endl;
  for (int i = 0; i < num_contacts; ++i) {
    std::cout << "|";
    std::cout << std::right << std::setw(10) << i + 1 << "|"
	          << std::right << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|"
	          << std::right << std::setw(10) << truncateString(contacts[i].getLastName()) << "|"
	          << std::right << std::setw(10) << truncateString(contacts[i].getNickname()) << "|"
              << std::endl;
  }
}

void PhoneBook::displayContactDetails(int index) const {
  if (index >= 1 && index <= num_contacts) {
    const Contact &contact = contacts[index - 1];
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
  } else {
    std::cout << "Invalid index." << std::endl;
  }
}
