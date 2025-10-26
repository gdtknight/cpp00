# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/31 05:14:04 by yoshin            #+#    #+#              #
#    Updated: 2025/10/17 13:55:22 by yoshin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***************** #
#    Color Codes    #
# ***************** #

BLACK			=	'\033[38;5;0m'
MAROON			=	'\033[38;5;1m'
GREEN			=	'\033[38;5;2m'
CYAN_BLUE		=	'\033[38;5;69m'
LIGHT_GREEN		=	'\033[38;5;46m'
CYAN			=	'\033[38;5;81m'
OLIVE			=	'\033[38;5;3m'
NAVY			=	'\033[38;5;4m'
PURPLE			=	'\033[38;5;5m'
TEAL			=	'\033[38;5;6m'
SILVER			=	'\033[38;5;7m'
GREY			=	'\033[38;5;8m'
RED				=	'\033[38;5;9m'
LINE			=	'\033[38;5;10m'
YELLOW			=	'\033[38;5;11m'
LIGHT_YELLOW	=	'\033[38;5;226m'
BLUE			=	'\033[38;5;12m'
FUCHSIA			=	'\033[38;5;13m'
AQUA			=	'\033[38;5;14m'
WHITE			=	'\033[38;5;15m'
ORANGE			=	'\033[38;5;208m'
RESET			=	'\033[0m'

# Makefile v1.0

CC				=	g++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98

NAME			=	megaphone

HEADER_DIR		=	includes
SRC_DIR			=	srcs

BUILD_DIR		=	build
BIN_DIR			=	bin

#SRCS			:=	$(shell find ./ -name '*.cpp')
SRCS			:=	megaphone.cpp
OBJS 			:=	$(patsubst ./%.cpp, ./$(BUILD_DIR)/%.cpp.o, $(SRCS))

# **************** #
#    Debug Flag    #
# **************** #

ifeq ($(debug), 1)
	override CFLAGS	+=	--debug -g -DDEBUG
endif

.PHONY: all clean fclean re bonus debug
all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(CYAN_BLUE)[$(NAME)] $(RED)compile $@ ...$(RESET)"
	@$(PREFIX) $(CC) $(CFLAGS) -o $@ $^
	@echo "$(CYAN_BLUE)[$(NAME)] $(ORANGE)$@ compiled!$(RESET)"

$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	@echo "$(CYAN_BLUE)[$(NAME)] $(RED)compile $< ...$(RESET)"
	@$(PREFIX) $(CC) $(CFLAGS) -o $@ -c $<
	@echo "$(CYAN_BLUE)[$(NAME)] $(GREEN)$< compiled!$(RESET)"

clean:
	@echo "$(CYAN_BLUE)[$(NAME)]$(RESET) clean"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "$(CYAN_BLUE)[$(NAME)]$(RESET) fclean"
	@rm -rf $(NAME)
	@echo "$(ORANGE)All binaries and libraries has been deleted.$(RESET)"

re: fclean all

dev: fclean
	@make debug=1 all
