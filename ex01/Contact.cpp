/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 09:43:14 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/26 22:27:24 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {};

Contact::Contact(std::string const &firstName, std::string const &lastName,
                 std::string const &nickname, std::string const &phoneNumber,
                 std::string const &darkestSecret)
    : firstName(firstName), lastName(lastName), nickname(nickname),
      phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

Contact::Contact(Contact const &contact)
    : firstName(contact.getFirstName()), lastName(contact.getLastName()),
      nickname(contact.getNickname()), phoneNumber(contact.getPhoneNumber()),
      darkestSecret(contact.getDarkestSecret()) {}

Contact &Contact::operator=(Contact const &contact) {
  if (this != &contact) {
    this->firstName = contact.firstName;
    this->lastName = contact.lastName;
    this->nickname = contact.nickname;
    this->phoneNumber = contact.phoneNumber;
    this->darkestSecret = contact.darkestSecret;
  }
  return (*this);
}

void Contact::setFirstName(std::string const &firstName) {
  this->firstName = firstName;
}

void Contact::setLastName(std::string const &lastName) {
  this->lastName = lastName;
}

void Contact::setNickname(std::string const &nickname) {
  this->nickname = nickname;
}

void Contact::setPhoneNumber(std::string const &phoneNumber) {
  this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string const &darkestSecret) {
  this->darkestSecret = darkestSecret;
}

std::string const &Contact::getFirstName() const { return (this->firstName); }

std::string const &Contact::getLastName() const { return (this->lastName); }

std::string const &Contact::getNickname() const { return (this->nickname); }

std::string const &Contact::getPhoneNumber() const {
  return (this->phoneNumber);
}
std::string const &Contact::getDarkestSecret() const {
  return (this->darkestSecret);
}
