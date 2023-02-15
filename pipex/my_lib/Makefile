# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 01:33:15 by seoyoo            #+#    #+#              #
#    Updated: 2022/08/04 21:32:06 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Red = \033[0;31m		# Red
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m		# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m		# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

# target
NAME = my_lib.a

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
DBFLAG = -g3

# archive
AR = ar
ARFLAGS = -rcs

# include
INC_DIR = ./
INC = -I $(INC_DIR)

# **************************************************************************** #

# LIBFT

# libft source
LIBFT_SRC_DIR = ./src/libft/
LIBFT_SRC_FILE = \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

LIBFT_SRCS = $(addprefix $(LIBFT_SRC_DIR), $(LIBFT_SRC_FILE))

# libft object
LIBFT_OBJ_DIR = ./obj/libft/
LIBFT_OBJ_FILE = $(LIBFT_SRC_FILE:.c=.o)
LIBFT_OBJS = $(addprefix $(LIBFT_OBJ_DIR), $(LIBFT_OBJ_FILE))

# **************************************************************************** #

# MY_ITOA

# my_itoa sources
MY_ITOA_SRC_DIR = ./src/my_itoa/
MY_ITOA_SRC_FILE = \
		my_itoa_signed.c \
		my_itoa_unsigned.c

MY_ITOA_SRCS = $(addprefix $(MY_ITOA_SRC_DIR), $(MY_ITOA_SRC_FILE))

# my_itoa object
MY_ITOA_OBJ_DIR = ./obj/my_itoa/
MY_ITOA_OBJ_FILE = $(MY_ITOA_SRC_FILE:.c=.o)
MY_ITOA_OBJS = $(addprefix $(MY_ITOA_OBJ_DIR), $(MY_ITOA_OBJ_FILE))

# **************************************************************************** #

# MY_NSTR

# my_nstr sources
MY_NSTR_SRC_DIR = ./src/my_nstr/
MY_NSTR_SRC_FILE =\
		my_nstr.c

MY_NSTR_SRCS = $(addprefix $(MY_NSTR_SRC_DIR), $(MY_NSTR_SRC_FILE))

# my_nstr object
MY_NSTR_OBJ_DIR = ./obj/my_nstr/
MY_NSTR_OBJ_FILE = $(MY_NSTR_SRC_FILE:.c=.o)
MY_NSTR_OBJS = $(addprefix $(MY_NSTR_OBJ_DIR), $(MY_NSTR_OBJ_FILE))

# **************************************************************************** #

# FT_PRINTF

# ft_printf sources
FT_PRINTF_SRC_DIR = ./src/ft_printf/
FT_PRINTF_SRC_FILE =\
		format_node_utils.c \
		ft_printf.c \
		parse_type_spec.c

FT_PRINTF_SRCS = $(addprefix $(FT_PRINTF_SRC_DIR), $(FT_PRINTF_SRC_FILE))

# ft_printf object
FT_PRINTF_OBJ_DIR = ./obj/ft_printf/
FT_PRINTF_OBJ_FILE = $(FT_PRINTF_SRC_FILE:.c=.o)
FT_PRINTF_OBJS = $(addprefix $(FT_PRINTF_OBJ_DIR), $(FT_PRINTF_OBJ_FILE))

# **************************************************************************** #

# SRCS = $(LIBFT_SRCS) $(MY_ITOA_SRCS) $(MY_NSTR_SRCS)

OBJS = $(LIBFT_OBJS) $(MY_ITOA_OBJS) $(MY_NSTR_OBJS) $(FT_PRINTF_OBJS)

# **************************************************************************** #

# rules
all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(LIBFT_OBJ_DIR)%.o : $(LIBFT_SRC_DIR)%.c
	@mkdir -p $(LIBFT_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# @printf "$(Red)LIBFT COMPILE FINISHED$(Color_Off)"

$(MY_ITOA_OBJ_DIR)%.o : $(MY_ITOA_SRC_DIR)%.c
	@mkdir -p $(MY_ITOA_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(MY_NSTR_OBJ_DIR)%.o : $(MY_NSTR_SRC_DIR)%.c
	@mkdir -p $(MY_NSTR_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


$(FT_PRINTF_OBJ_DIR)%.o : $(FT_PRINTF_SRC_DIR)%.c
	@mkdir -p $(FT_PRINTF_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


clean:
	rm -rf ./obj

fclean: clean
	rm -f $(NAME)

re: fclean all

test: bonus
	$(CC) $(CFLAGS) $(NAME) my_test.c
	@./a.out
	@ rm ./a.out

.PONEY: all bonus clean fclean re
