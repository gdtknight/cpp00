#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact();
  Contact(std::string &firstName, std::string &lastName, std::string &nickname,
          std::string &phoneNumber, std::string &darkestSecret);
  void setFirstName(const std::string &first_name);
  void setLastName(const std::string &last_name);
  void setNickname(const std::string &nickname);
  void setPhoneNumber(const std::string &phone_number);
  void setDarkestSecret(const std::string &darkest_secret);

  std::string getFirstName() const;
  std::string getLastName() const;
  std::string getNickname() const;
  std::string getPhoneNumber() const;
  std::string getDarkestSecret() const;

private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
};

#endif
