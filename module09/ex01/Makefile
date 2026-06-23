# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchallat <bchallat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/19 09:18:13 by bchallat          #+#    #+#              #
#    Updated: 2025/03/12 13:32:00 by bchallat         ###   ########.fr        #
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
	ECHO_FLAG = echo
	CC	= clang++
	FLAG	= -g3 -Wall -Wextra -Werror -std=c++98 -fsanitize=address
else
	ECHO_FLAG = echo -e
	CC	= c++
	FLAG	= -Wall -Wextra -Werror -std=c++98
endif

CCFLAG	= $(CC) $(FLAG) 
RMF	= rm -rf
NAME	= RPN 

# **************************************************************************** #
#					SOURCES				       #
# **************************************************************************** #

SRC	=	main.cpp RPN.cpp	\
		
OBJS	=	$(SRC:.cpp=.o)

%.o: %.cpp
	@${ECHO_FLAG}  "$(GREEN)[OK]       	🛠️ $(YELLOW)Compiling ... $(BLUE)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
#					RULES				       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)
	@${ECHO_FLAG}  "$(GREEN)[OK]       	✅ $(YELLOW)CREATED   EXE$(BLUE) -- ex02 --\n $(RESET)" 
	@$(CCFLAG) -g3 $(OBJS) -o $(NAME)

clean:
	@${ECHO_FLAG} "$(RED)[DELETE]	🧹$(BLUE) Delete file obj $(RESET)\n" 
	@$(RMF) $(OBJDIR) $(OBJS)

fclean:
	@${ECHO_FLAG} "$(RED)[DELETE]	🧹$(BLUE) Delete all file obj $(RESET)\n"
	@$(RMF) $(OBJDIR) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#									       #
# **************************************************************************** #
