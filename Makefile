# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 09:44:22 by amazurie          #+#    #+#              #
#    Updated: 2019/03/31 19:37:53 by amazurie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_retro
CC	= clang++
FLAGS	= -Wall -Wextra -Werror -lncurses

SRC	= main.cpp \
	  AEntity.cpp \
	  FakeVec.cpp \
	  WindowHelper.cpp \
	  Player.cpp \
	  EntityList.cpp \
	  Enemy.cpp \
	  Bullet.cpp \
	  Wall.cpp \
	  Boss.cpp \
	  Star.cpp

OBJS	= $(SRC:.cpp=.o)
DEPS	= $(OSRC:.o=.d)

GRN	= \033[0;32m
RED	= \033[0;31m
CYN	= \033[0;36m
NC	= \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@echo "\r\c"
	@tput cd
	@echo "${GRN}$(NAME) created${NC}"
	@echo "${CYN}PROCESSING DONE !\n${NC}"

$%.o: %.c
	@echo "\r\c"
	@tput cd
	@echo "${OK_COLOR}Compiling ${NO_COLOR} $@\c"
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	@echo "${RED}Cleaning ...${NC}"
	@rm -rf $(OBJS)

fclean: clean
	@echo "${RED}Cleaning $(NAME)${NC}"
	@rm -rf $(NAME)
	@echo "${RED}DELETE DONE !${NC}\n"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
