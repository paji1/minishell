# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/10/18 13:11:57 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash # Use bash syntax

# #################HEADERS###########################
HEADERS = libft.h
HEADERS := $(addprefix include/, $(HEADERS))

# ################COMMANDS###########################

RM = rm -rf
CC = gcc
AR = ar rcs
CFLAG = -g -pthread -Wall -Werror -Wextra -I include

# ################SRCS_Objs##########################

SRC = ft_abs.c      ft_memcpy.c      ft_strlcat.c \
	ft_atoi.c     ft_memmove.c     ft_strlcpy.c \
	ft_bzero.c    ft_memset.c      ft_strlen.c \
	ft_calloc.c   ft_putchar_fd.c  ft_strmapi.c \
	ft_in_tab.c   ft_putendl_fd.c  ft_strncmp.c \
	ft_isalnum.c  ft_putnbr_fd.c   ft_strnstr.c \
	ft_isalpha.c  ft_putstr_fd.c   ft_strrchr.c \
	ft_isascii.c  ft_split.c       ft_strtrim.c \
	ft_isdigit.c  ft_strchr.c      ft_substr.c \
	ft_isprint.c  ft_strcmp.c      ft_tolower.c \
	ft_itoa.c     ft_strdup.c      ft_toupper.c \
	ft_memchr.c   ft_striteri.c    ft_strstr.c\
	ft_memcmp.c   ft_strjoin.c
OBJ = $(addprefix obj/, $(SRC:.c=.o))

# ################SRCS_Objs_Utils####################

SRC_UTILS = 
OBJ_UTILS = $(addprefix obj/utils/, $(SRC_UTILS:.c=.o))

# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;35m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'

lines=$(shell tput lines)
cols=$(shell tput cols)
num=$(shell echo `ls src/*.c | wc -l`)
i_num=$(shell echo "($(cols)/$(num))"  | bc)
# i_num:=$(shell expr $(cols) / $(num))
CODE_SAVE_CURSOR='\033[s'
CODE_RESTORE_CURSOR='\033[u'
CODE_CURSOR_IN_SCROLL_AREA="\033[1A"
BC=/usr/bin/bc

# ###############executable##########################

NAME = library/libft.a
x  = -1

# ###################################################

all : $(NAME)
	

$(NAME): $(OBJ) $(OBJ_UTILS) $(BC)
	@ mkdir -p library
	@ printf "\033[$(lines);0f"
	@ tput el
	@ printf  ${CODE_RESTORE_CURSOR}""
	@ tput el
	@ printf ${RE}"\rLibft Created successfully\n"${NC}
	@ printf ${RE}"\r-----------------------------------\n"${NC}
	@ tput cvvis
	@ $(AR) $(NAME) $(OBJ) 

$(BC):
	@echo "bc not found"

obj/%.o : src/%.c $(HEADERS)
	@ mkdir -p obj
	@ mkdir -p obj/utils
	@ $(CC) $(CFLAG) -c $< -o $@
	@tput civis
	$(eval x=$(shell expr $(x) + $(i_num) ))
	@ printf $(notdir $@)"\n"
	@ printf  ${CODE_SAVE_CURSOR}""
	@ printf "\033[$(lines);0f"
	@number=$x ; while [[ $$number -ge 0 ]] ; do \
		if [[ $$(( $$number % 2 )) -eq 0 ]]; then printf ${YELLOW}"🟪"${NC} ; fi ;\
        ((number = number - 1)) ; \
    done
	@printf  ${CODE_RESTORE_CURSOR}""
	@printf  ${CODE_CURSOR_IN_SCROLL_AREA}""
	@printf  ${CODE_SAVE_CURSOR}""
	@printf ${RE}"💎 Making the  --> "${NC} 
	@tput el

clean :
	@ $(RM) $(OBJ)
	@ $(RM) $(OBJ_UTILS)

fclean : clean
	@ $(RM) $(NAME)
	@ $(RM) $(NAME)

re : fclean all