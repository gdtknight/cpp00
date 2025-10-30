# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/30 17:41:03 by yoshin            #+#    #+#              #
#    Updated: 2025/10/30 21:34:11 by yoshin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

NAME		=	phonebook

SRCS		=	main.cpp PhoneBook.cpp Contact.cpp
HEADERS		=	PhoneBook.hpp Contact.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

dev: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -g -o $(NAME).dev
