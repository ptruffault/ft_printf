# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:16:13 by ptruffau          #+#    #+#              #
#    Updated: 2018/01/07 16:59:07 by ptruffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libftprintf.a
GIT 		= https://github.com/ptruffault/ft_printf.git

FLAG		= -Wall -Wextra -Werror

FILES		= 	get_val.c \
				ft_printf.c \
				param.c  

TOOLS 		= 	error.c \
				wchar_utils.c \
				fun_tools.c \
				get_ox.c \
				tools_tparam.c

FILE_FOLDER	= ./srcs/
TOOLS_FOLDER= ./srcs/tools/
OBJ_FOLDER 	= ./bin/
SRC			= $(addprefix $(FILE_FOLDER), $(FILES)) $(addprefix $(TOOLS_FOLDER), $(TOOLS)) 
OBJ			= $(addprefix $(OBJ_FOLDER), $(FILES:.c=.o)) $(addprefix $(OBJ_FOLDER), $(TOOLS:.c=.o))

COLOR		= \033[01;34m
NO_COLOR	= \033[00m
OP_COLOR	= \033[1;31m
DONE 		= $(NO_COLOR)[\033[1;32mOK$(NO_COLOR)]

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft all
	@echo "$(OP_COLOR) building $(NAME)"
	@ar rc $@ $^ libft/bin/*.o
	@ranlib $@
	@echo "$(DONE)"

bin/%.o: srcs/%.c 
	@gcc $(FLAG) -I includes/ -c $< -o $@
	@echo "$(COLOR)$< : $(DONE)"

bin/%.o: srcs/tools/%.c
	@gcc $(FLAG) -I includes/ -c $< -o $@		
	@echo "$(COLOR)$< : $(DONE)"

clear:
	@clear

clean:
	@rm -rf $(NAME)

fclean: clean
	@rm -rf $(OBJ)

mrpropre: fclean
	@make -C libft fclean

re: clear fclean all


chmod:
	@chmod 777 * $(SRC) includes/ft_printf.h 
	@make -C ./libft chmod

save: clear mrpropre
	@git add * srcs/* srcs/tools/* includes/*
	@git commit -m  "make save"
	@git push
	@echo "$(DONE)"

load:
	@rm -rf *
	@git clone $(GIT) TMP
	@mv TMP/* .
	@rm -rf TMP libft
	@git clone https://github.com/ptruffault/libft.git
