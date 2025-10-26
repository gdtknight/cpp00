/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:51:49 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/26 22:12:11 by yoshin           ###   ########.fr       */
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

std::string getInput(std::string const &prompt) {
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

int stoi_compat(const std::string &str, std::size_t *pos = 0) {
  std::stringstream ss(str);
  long long value = 0;
  std::string parsed;

  // 공백 제거 없이 숫자 읽기
  ss >> std::ws;      // 앞쪽 공백 무시
  if (!(ss >> value)) // 숫자 읽기 실패 시
    throw std::invalid_argument("stoi_compat: invalid argument");

  // 숫자 다음 문자열 위치 계산
  std::streampos consumed = ss.tellg();
  if (consumed == -1)
    consumed = static_cast<std::streampos>(str.size());
  if (pos)
    *pos = static_cast<std::size_t>(consumed);

  // 범위 검사 (int 범위 벗어남)
  if (value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max())
    throw std::out_of_range("stoi_compat: out of range");

  return static_cast<int>(value);
}

void add(PhoneBook &phoneBook) {
  Contact newContact;

  newContact.setFirstName(getInput("Enter first name: "));
  newContact.setLastName(getInput("Enter last name: "));
  newContact.setNickname(getInput("Enter nickname: "));
  newContact.setPhoneNumber(getInput("Enter phone number: "));
  newContact.setDarkestSecret(getInput("Enter darkest secret: "));
  phoneBook.addContact(newContact);
  std::cout << "Contact added!" << std::endl;
}

void search(PhoneBook &phoneBook) {
  phoneBook.displayContacts();
  std::string index_str;
  int index;
  std::cout << "Enter the index of the entry to display: ";
  std::getline(std::cin, index_str);
  if (std::cin.eof()) {
    std::cout << "exit with unexpected eof" << std::endl;
    exit(EXIT_FAILURE);
  }
  try {
    index = stoi_compat(index_str);
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
