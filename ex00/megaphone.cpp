/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:18:24 by yoshin            #+#    #+#             */
/*   Updated: 2025/10/26 21:59:57 by yoshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string arg;

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }

  for (int idx = 1; idx < argc; idx++) {
    arg = argv[idx];
    std::size_t spos = arg.find_first_not_of(" \f\n\r\t\v");
    std::size_t epos = arg.find_last_not_of(" \f\n\r\t\v");
    if (spos != std::string::npos) {
      for (std::size_t pos = spos; pos <= epos; pos++) {
        std::cout << (char)toupper(arg.at(pos));
      }
      if (idx != argc - 1)
        std::cout << " ";
    }
  }
  std::cout << std::endl;
  return (0);
}
