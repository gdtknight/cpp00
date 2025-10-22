#include "Contact.hpp"

Contact::Contact() {}
Contact::Contact(std::string &firstName, std::string &lastName, std::string &nickname,
          std::string &phoneNumber, std::string &darkestSecret)
{
	this->firstName = std::string(firstName);
	this->lastName = std::string(lastName);
	this->nickname = std::string(nickname);
	this->phoneNumber = std::string(phoneNumber);
	this->darkestSecret = std::string(darkestSecret);
}

void Contact::setFirstName(std::string const &firstName) {
    this->firstName = std::string(firstName);
}

void Contact::setLastName(std::string const &lastName) {
    this->lastName = std::string(lastName);
}

void Contact::setNickname(std::string const &nickname) {
    this->nickname = std::string(nickname);
}

void Contact::setPhoneNumber(std::string const &phoneNumber) {
    this->phoneNumber = std::string(phoneNumber);
}

void Contact::setDarkestSecret(std::string const &darkestSecret) {
    this->darkestSecret = std::string(darkestSecret);
}

std::string Contact::getFirstName() const {
    return (this->firstName);
}

std::string Contact::getLastName() const {
    return (this->lastName);
}

std::string Contact::getNickname() const {
    return (this->nickname);
}

std::string Contact::getPhoneNumber() const {
    return (this->phoneNumber);
}

std::string Contact::getDarkestSecret() const {
    return (this->darkestSecret);
}

