# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/09/20 10:57:31 by akharraz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash # Use bash syntax

# #################HEADERS###########################
HEADERS = minishell.h types.h
HEADERS := $(addprefix include/, $(HEADERS))
# #################HEADERS_utils###########################
UHEADERS = queue.h types_q.h
UHEADERS := $(addprefix include/, $(UHEADERS))

# ################COMMANDS###########################

RM = rm -rf
CC = gcc 
# CFLAG = -g -pthread -Wall -Werror -Wextra -I include 

# ################SRCS_Objs##########################

# SRC = main.c dir.c init.c free_all.c parse.c startend.c quote.c lexer.c\
	type.c handle_tree.c print_tree.c node.c
# OBJ = $(addprefix obj/, $(SRC:.c=.o))

# ################SRCS_Objs_Utils####################

# SRC_UTILS = queue.c free_q.c is_space.c is_special.c
# OBJ_UTILS = $(addprefix obj/utils/, $(SRC_UTILS:.c=.o))

# ################ADAM_Work####################

SRC_ADAM = pipe.c t_list_func.c
OBJ_ADAM = $(addprefix obj/adam_work/, $(SRC_ADAM:.c=.o))
# ####################OBJ##########################
ALLOBJ := $(OBJ_ADAM) $(OBJ) $(OBJ_UTILS)
# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;34m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'

# #################bar_line##############################

lines=$(shell tput lines)
cols=$(shell tput cols)
num=$(shell echo `ls src/*.c src/utils/*.c | wc -l`)
i_num:=$(shell expr $(cols) / $(num))
i_num:=$(shell expr $(i_num) / 2)
x  = -1
CODE_SAVE_CURSOR='\033[s'
CODE_RESTORE_CURSOR='\033[u'
CODE_CURSOR_IN_SCROLL_AREA="\033[1A"

# ###############executable##########################

NAME = ./minishell
LIBFT = libft/library/libft.a
ILIBFT = libft/include

# ###################################################

all : $(NAME)


$(NAME): $(OBJ_ADAM) | library
	@ printf "\033[$(lines);0f"
	@ tput el
	@printf  ${CODE_RESTORE_CURSOR}""
	@tput el
	@ printf ${GREEN}"\rMaking is done ✅\n"${NC}
	@ $(CC) $(CFLAG) $(ALLOBJ) -I $(ILIBFT) $(LIBFT) -lreadline -o $(NAME)
	@ tput cvvis
	@ echo "---------------------------------------------------" >> lastcompiled.log

library : 
	@ make -C libft

obj/%.o : src/%.c  $(HEADERS) $(UHEADERS)
	@ mkdir -p obj
	@ mkdir -p obj/utils
	@ mkdir -p obj/adam_work
	@$ nu=$x ; if [[ $$nu -eq -1 ]] ; then \
	printf ${RE}"🔷 Making the  --> "${NC} \
	 ; fi
	@ $(CC) $(CFLAG) -c $< -o $@
	@tput civis
	$(eval x=$(shell expr $(x) + $(i_num) ))
	@ printf $(notdir $@)"\n"
	@ printf  ${CODE_SAVE_CURSOR}""
	@ printf "\033[$(lines);0f"
	@ echo $< >> lastcompiled.log
	@number=$x ; while [[ $$number -ge 0 ]] ; do \
        printf ${YELLOW}"🟩"${NC}  ;\
        ((number = number - 1)) ; \
    done
	@printf  ${CODE_RESTORE_CURSOR}""
	@printf  ${CODE_CURSOR_IN_SCROLL_AREA}""
	@printf  ${CODE_SAVE_CURSOR}""
	@printf ${RE}"🔷 Making the  --> "${NC} 
	@tput el

clean :
	@ $(RM) $(OBJ)
	@ $(RM) $(OBJ_UTILS)
	@ make clean -C libft

fclean : clean
	@ $(RM) $(NAME)
	@ make fclean -C libft

re : 
	@make fclean
	@make -C libft
	@make all