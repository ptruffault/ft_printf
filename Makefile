 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 11:16:13 by ptruffau          #+#    #+#              #
#    Updated: 2018/06/26 17:08:06 by ptruffau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libftprintf.a
GIT 		= https://github.com/ptruffault/ft_printf.git

FLAG		= 

FILES		= 	get_val.c \
				ft_printf.c \
				param.c \
				get_tmpval.c \
				disp.c

TOOLS 		= 	wchar_utils.c \
				fun_tools.c \
				get_ox.c \
				get_type.c \
				tools_tparam.c

FILE_FOLD	= ./srcs/
TOOLS_FOLD	= ./srcs/tools/
HANDLER_FOLD= ./srcs/handler/
OBJ_FOLD 	= ./bin/
SRC			= $(addprefix $(FILE_FOLD), $(FILES)) \
			$(addprefix $(TOOLS_FOLD), $(TOOLS)) \
			$(addprefix $(HANDLER_FOLD), $(HANDLER)) 
OBJ			= $(addprefix $(OBJ_FOLD), $(FILES:.c=.o)) \
			$(addprefix $(OBJ_FOLD), $(TOOLS:.c=.o)) \
			$(addprefix $(OBJ_FOLD), $(HANDLER:.c=.o)) 

COLOR		= \033[01;34m
NO_COLOR	= \033[00m
OP_COLOR	= \033[1;31m
DONE 		= $(NO_COLOR)[\033[1;32mOK$(NO_COLOR)]

all: bin $(NAME)

$(NAME): $(OBJ)
	@make -C libft all
	@echo "$(OP_COLOR) building $(NAME)"
	@ar rc $@ $^ libft/bin/*.o
	@ranlib $@
	@echo "$(DONE)"

bin:
	@mkdir $@

bin/%.o: srcs/%.c 
	@gcc $(FLAG) -I includes/ -c $< -o $@
	@echo "$(DONE) $(COLOR)$<"

bin/%.o: srcs/tools/%.c
	@gcc $(FLAG) -I includes/ -c $< -o $@		
	@echo "  $(DONE) $(COLOR)$<"

bin/%.o: srcs/handler/%.c
	@gcc $(FLAG) -I includes/ -c $< -o $@		
	@echo "  $(DONE) $(COLOR)$<"

clean:
	@rm -rf  bin/*
	@make -C libft clean

fclean: clean
	rm -rf $(NAME)
	@make -C libft fclean

re: clear fclean all


.PHONY: clear clean fclean re chmod save update
