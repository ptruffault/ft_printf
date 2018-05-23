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

NAME		= ft_printf

FOLDERS 	= ft_printf/
			
GIT 		= https://github.com/ptruffault/ft_printf.git

SRC			= 	srcs/*.c \
				srcs/tools/*.c

CFLAGS		= -Wall -Werror -Wextra

LIB_PATH	= ./libft/

LIB			= -Llibft/ -lft

COULEUR		= \033[01;34m

SUCESS		= [\033[1;32mOK\033[00m]\n

all: $(NAME)

clear:
	@clear

$(NAME):
	@echo "$(COULEUR) -Creating libft.a \033[00m"
	@make -C $(LIB_PATH) all
	@echo "$(SUCESS)"
	@echo "$(COULEUR) -Creating $(NAME) \033[00m"
	@gcc $(CFLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "$(SUCESS)"

small_clean:
	@rm -rf $(NAME)
	@echo "$(COULEUR) -delete $(NAME) \033[00m"

clean:
	@make -C $(LIB_PATH) clean

fclean:
	@echo "$(COULEUR) -Cleaning\033[00m"
	@make -C $(LIB_PATH) fclean
	@echo "$(COULEUR)\t +delete $(NAME) \033[00m"
	@rm -f $(NAME)
	@echo "$(SUCESS)"

re:	clear all

fast_re: clear small_clean
	@echo "$(COULEUR) -Creating $(NAME) \033[00m"
	@gcc $(CFLAGS) $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "$(SUCESS)"


no_flag: clear small_clean
	@echo "$(COULEUR) -Creating $(NAME) \033[00m"
	@gcc $(SRC) -I $(LIB_PATH) $(LIB) -o $(NAME)
	@echo "$(SUCESS)"



chmod:
	@echo "$(COULEUR) -giving permission\033[00m"
	@chmod 777 *
	@chmod 777 libft/*
	@chmod 777 srcs/*
	@chmod 777 srcs/tools/*
	@chmod 777 includes/*
	@make -C $(LIB_PATH) chmod
	@echo "$(SUCESS)"

valgrind:fast_re
	@echo "$(COULEUR) -test leaks with valgrind \033[00m"
	@valgrind --tool=memcheck --leak-check=full ./$(NAME)

zam: fast_re
	./$(NAME)

save: clear fclean
	@git add *
	@git commit -m "make save"
	@git push

load: clear fclean
	@rm -rf srcs
	@rm -rf includes
	@rm -rf libft
	@rm -rf auteur
	@git clone $(GIT)
	@cp -r $(FOLDERS)srcs .
	@cp -r $(FOLDERS)includes .
	@cp -r $(FOLDERS)libft .
	@cp $(FOLDERS)auteur .
	@rm -rf $(FOLDERS)
	@echo "$(SUCESS)"

build_folders:
	@echo "$(COULEUR)*Creating folders\033[00m"
	@mkdir srcs
	@mkdir srcs/tools
	@mkdir includes

build_tools:
	@echo "#include \"../../includes/$(NAME).h\"" > srcs/tools/tools_1.c

build_file:
	@echo "#include \"../includes/$(NAME).h\"" > srcs/file_1.c

build_h:
	@echo "$(COULEUR)*Creating $(NAME).h main.c and files\033[00m"
	@echo "#ifndef $(MAJ_NAME)_H\n#define $(MAJ_NAME)_H\n# include \"libft/libft.h\"\n#endif" > includes/$(NAME).h

download_libft:
	@echo "$(COULEUR)*download libft\033[00m"
	@git clone https://github.com/ptruffault/libft.git
	@echo "$(SUCESS)"

build_main:
	@echo "#include \"../includes/$(NAME).h\"\n\nint\tmain(void)\n{\n\n\treturn (0);\n}" > srcs/main.c

build: build_folders build_file build_tools build_h build_main download_libft
	@echo ptruffau > auteur
	@echo "$(SUCESS)"




.PHONY: all small_clean clean fclean re fast_re