#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
public:
    PhoneBook();
    void addContact(const Contact& contact);
    void displayContacts() const;
    void displayContactDetails(int index) const;

private:
    Contact contacts[8];
    int num_contacts;
    int oldest_contact_index; // To track the oldest contact for replacement
};

#endif
