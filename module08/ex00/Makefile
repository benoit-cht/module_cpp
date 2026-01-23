# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchallat <bchallat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 09:18:13 by bchallat          #+#    #+#              #
#    Updated: 2026/01/23 15:10:11 by ton_utilisate    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#					VAR				       #
# **************************************************************************** #

GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
RED 	= \033[0;91m
RESET	= \033[0m

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	CC	= clang++
	FLAG	= -g3 -Wall -Wextra -Werror -std=c++98 -fsanitize=address
else
	CC	= c++
	FLAG	= -Wall -Wextra -Werror -std=c++98
endif

CCFLAG	= $(CC) $(FLAG) 
RMF	= rm -rf
NAME	= ex00 

# **************************************************************************** #
#					SOURCES				       #
# **************************************************************************** #

SRC	=	main.cpp	\
		
OBJS	=	$(SRC:.cpp=.o)

%.o: %.cpp
	@echo  "$(GREEN)[OK]       	🛠️ $(YELLOW)Compiling ... $(BLUE)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
#					RULES				       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	@echo  "$(GREEN)[OK]       	✅ $(YELLOW)CREATED   EXE$(BLUE) -- ex00 --\n $(RESET)" 
	@$(CCFLAG) -g3 $(OBJS) -o $(NAME)

clean:
	@echo "$(RED)[DELETE]	🧹$(BLUE) Delete file obj $(RESET)\n" 
	@$(RMF) $(OBJDIR) $(OBJS)

fclean:
	@echo "$(RED)[DELETE]	🧹$(BLUE) Delete all file obj $(RESET)\n"
	@$(RMF) $(OBJDIR) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#									       #
# **************************************************************************** #
