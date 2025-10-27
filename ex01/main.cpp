/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:51:49 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/27 12:50:50 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

static std::string getInput(std::string const &prompt) {
  std::string input;

  while (true) {
    std::cout << prompt;
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cout << "exit with unexpected eof" << std::endl;
      exit(EXIT_FAILURE);
    }
    if (input.empty()) {
      std::cout << "Field cannot be empty. Please try again." << std::endl;
    } else {
      return (input);
    }
  }
}

static std::string getNumericInput(std::string const &prompt) {
  std::string input;

  while (true) {
    std::cout << prompt;
    std::getline(std::cin, input);

    if (std::cin.eof()) {
      std::cout << "exit with unexpected eof" << std::endl;
      exit(EXIT_FAILURE);
    }

    if (input.empty()) {
      std::cout << "Field cannot be empty. Please try again." << std::endl;
      continue;
    }

    bool isNumeric = true;
    for (std::string::size_type i = 0; i < input.size(); ++i) {
      if (!std::isdigit(input[i])) {
        isNumeric = false;
        break;
      }
    }

    if (!isNumeric) {
      std::cout << "Phone Number must contain only digits. Please try again."
                << std::endl;
    } else
      return (input);
  }
}

static int stoi_(const std::string &str, std::size_t *pos = 0) {
  std::stringstream ss(str);
  long long value = 0;
  std::string parsed;

  ss >> std::ws;
  if (!(ss >> value))
    throw std::invalid_argument("stoi_compat: invalid argument");

  std::streampos consumed = ss.tellg();
  if (consumed == -1)
    consumed = static_cast<std::streampos>(str.size());
  if (pos)
    *pos = static_cast<std::size_t>(consumed);

  if (value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max())
    throw std::out_of_range("stoi_compat: out of range");

  return static_cast<int>(value);
}

static void add(PhoneBook &phoneBook) {
  Contact newContact;

  newContact.setFirstName(getInput("Enter first name: "));
  newContact.setLastName(getInput("Enter last name: "));
  newContact.setNickname(getInput("Enter nickname: "));
  newContact.setPhoneNumber(getNumericInput("Enter phone number: "));
  newContact.setDarkestSecret(getInput("Enter darkest secret: "));

  phoneBook.addContact(newContact);
  std::cout << "Contact added!" << std::endl;
}

static void search(PhoneBook &phoneBook) {
  std::string index_str;
  int index;

  phoneBook.displayContacts();

  std::cout << "Enter the index of the entry to display: ";
  std::getline(std::cin, index_str);
  if (std::cin.eof()) {
    std::cout << "exit with unexpected eof" << std::endl;
    exit(EXIT_FAILURE);
  }

  try {
    index = stoi_(index_str);
    phoneBook.displayContactDetails(index);
  } catch (const std::invalid_argument &e) {
    std::cout << e.what() << std::endl;
  } catch (const std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  }
}

// clang-format off
static void banner(void)
{
  std::cout << "\n"
    "__________ .__                             __________                  __    \n"
    "\\______   \\|  |__    ____    ____    ____  \\______   \\  ____    ____  |  | __\n"
    " |     ___/|  |  \\  /  _ \\  /    \\ _/ __ \\  |    |  _/ /  _ \\  /  _ \\ |  |/ /\n"
    " |    |    |   Y  \\(  <_> )|   |  \\\\  ___/  |    |   \\(  <_> )(  <_> )|    < \n"
    " |____|    |___|  / \\____/ |___|  / \\___  > |______  / \\____/  \\____/ |__|_ \\\n"
    "                \\/              \\/      \\/         \\/                      \\/\n\n"
    << std::endl;
}
// clang-format on

int main() {
  PhoneBook phoneBook;
  std::string command;

  banner();

  while (true) {
    std::cout << "Enter command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);
    if (std::cin.eof()) {
      std::cout << std::endl;
      break;
    }

    if (command == "ADD") {
      add(phoneBook);
    } else if (command == "SEARCH") {
      search(phoneBook);
    } else if (command == "EXIT") {
      std::cout << "Exiting PhoneBook. Contacts lost forever!" << std::endl;
      break;
    } else {
      std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT."
                << std::endl;
    }
  }
  return 0;
}
