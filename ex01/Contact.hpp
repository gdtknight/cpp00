/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 09:43:11 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/26 22:26:45 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact(void);
  Contact(std::string const &firstName, std::string const &lastName,
          std::string const &nickname, std::string const &phoneNumber,
          std::string const &darkestSecret);
  Contact(Contact const &contact);

  Contact &operator=(Contact const &contact);

  void setFirstName(std::string const &firstName);
  void setLastName(std::string const &lastName);
  void setNickname(std::string const &nickname);
  void setPhoneNumber(std::string const &phoneNumber);
  void setDarkestSecret(std::string const &darkestSecret);

  std::string const &getFirstName() const;
  std::string const &getLastName() const;
  std::string const &getNickname() const;
  std::string const &getPhoneNumber() const;
  std::string const &getDarkestSecret() const;

private:
  std::string firstName;
  std::string lastName;
  std::string nickname;
  std::string phoneNumber;
  std::string darkestSecret;
};

#endif
