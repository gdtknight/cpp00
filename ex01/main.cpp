#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"

static std::string getInput(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << std::endl;
            exit(0);
        }
        if (input.empty()) {
            std::cout << "Field cannot be empty. Please try again." << std::endl;
        } else {
            return input;
        }
    }
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }

        if (command == "ADD") {
            Contact newContact;
            newContact.setFirstName(getInput("Enter first name: "));
            newContact.setLastName(getInput("Enter last name: "));
            newContact.setNickname(getInput("Enter nickname: "));
            newContact.setPhoneNumber(getInput("Enter phone number: "));
            newContact.setDarkestSecret(getInput("Enter darkest secret: "));
            phoneBook.addContact(newContact);
            std::cout << "Contact added!" << std::endl;
        } else if (command == "SEARCH") {
            phoneBook.displayContacts();
            std::string index_str;
            int index;
            std::cout << "Enter the index of the entry to display: ";
            std::getline(std::cin, index_str);
            if (std::cin.eof()) {
                std::cout << std::endl;
                break;
            }
            try {
                index = std::stoi(index_str);
                phoneBook.displayContactDetails(index);
            } catch (const std::invalid_argument& e) {
                std::cout << "Invalid input. Please enter a number." << std::endl;
            } catch (const std::out_of_range& e) {
                std::cout << "Invalid index. Out of range." << std::endl;
            }
        } else if (command == "EXIT") {
            std::cout << "Exiting PhoneBook. Contacts lost forever!" << std::endl;
            break;
        } else {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}
