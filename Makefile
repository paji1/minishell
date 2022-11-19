# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akharraz <akharraz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/11/19 05:05:57 by akharraz         ###   ########.fr        #
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
CFLAG := -Wall -Wextra -Werror -g  -pthread -I include $$LDFLAGS $$CPPFLAGS  
OS = $(shell uname -s)
ifneq ($(OS),Linux)
	CFLAG := $(CFLAG) $$LDFLAGS $$CPPFLAGS -Qunused-arguments  
endif

# -fsanitize=address 

# ################SRCS_Objs##########################

SRC = main.c dir.c init.c free_all.c free_all2.c parse.c startend.c quote.c lexer.c\
	type.c type_handle.c handle_tree.c node.c herdoc.c  cmd.c\
	parse_op.c is_sub.c parse_block.c \
	execute_bin.c execute.c execute_recurs.c execute_close.c execute_redirection.c execute_redirection_cases.c\
	execute_cmd.c execute_sub_shell.c execute_utils.c execute_check_cmd.c execute_check_cmd_two.c\
	parse_env.c parse_env_utils.c parse_env_manipulation.c parse_env_manipulation_two.c\
	expander.c expander_utils.c expand_quote.c execute_builtins.c\
	hide_ctrlc.c handle_history.c handle_signal.c handle_signal_herdoc.c expand_wildcard.c
OBJ = $(addprefix obj/, $(SRC:.c=.o))

# ################SRCS_Objs_Utils####################

SRC_UTILS = queue.c q_n_get.c free_q.c is_space.c is_special.c stack.c\
	free_stack.c get_nextline.c export_print.c export_exec.c print_to_error.c
OBJ_UTILS = $(addprefix obj/utils/, $(SRC_UTILS:.c=.o))
# ################SRCS_Objs_Builtins####################

SRC_BUILTINS = ft_echo.c ft_isbuiltin.c ft_pwd.c ft_env.c ft_cd.c ft_unset.c ft_export.c ft_exit.c
OBJ_BUILTINS = $(addprefix obj/builtins/, $(SRC_BUILTINS:.c=.o))

# ################ALL_OBJS####################

ALL_OBJS = $(OBJ) $(OBJ_UTILS) $(OBJ_BUILTINS)

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


$(NAME): $(ALL_OBJS)  | library
	@ printf "\033[$(lines);0f"
	@ tput el
	@printf  ${CODE_RESTORE_CURSOR}""
	@tput el
	@ printf ${GREEN}"\rMaking is done ✅\n"${NC}
	@ $(CC) $(CFLAG) $(ALL_OBJS) -I $(ILIBFT) $(LIBFT) -lreadline -o $(NAME)
	@ tput cvvis
	@ echo "---------------------------------------------------" >> lastcompiled.log

library : 
	@ make -C libft

obj/%.o : src/%.c  $(HEADERS) $(UHEADERS)
	@ mkdir -p obj
	@ mkdir -p obj/utils
	@ mkdir -p obj/builtins
	@$ nu=$x ; if [[ $$nu -eq -1 ]] ; then \
	printf ${RE}"🔷 Making the--> "${NC} \
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
	@ $(RM) $(ALL_OBJS)
	@ make clean -C libft

fclean : clean
	@ $(RM) $(NAME)
	@ make fclean -C libft

re :
	@make fclean
	@make -C libft
	@make all