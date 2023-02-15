# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 03:16:26 by seoyoo            #+#    #+#              #
#    Updated: 2022/10/28 12:23:02 by seoyoo           ###   ########.fr        #
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
NAME = pipex

# compiler
CC = cc
ifdef LETS_DEBUG
	CFLAGS = -Wall -Wextra -Werror -g3
else
	CFLAGS = -Wall -Wextra -Werror
endif

# archive
AR = ar
ARFLAGS = -rcs

# include
INC_DIR = ./
INC = -I $(INC_DIR)

# my_lib
MY_LIB_DIR = ./my_lib/
MY_LIB_ARC = my_lib.a
MY_LIB = $(MY_LIB_DIR)$(MY_LIB_ARC)

# directories
SRC_DIR = ./src/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# bonus
BONUS_NAME = checker

# **************************************************************************** #

# main_function

MAIN_FUNCTION_DIR = ./main_function/

MAIN_FUNCTION_SRC_DIR = $(SRC_DIR)$(MAIN_FUNCTION_DIR)

MAIN_FUNCTION_SRC_FILE = \
		pipex_main.c 

MAIN_FUNCTION_SRCS = \
		$(addprefix $(MAIN_FUNCTION_SRC_DIR), \
		$(MAIN_FUNCTION_SRC_FILE))

MAIN_FUNCTION_OBJ_DIR = $(OBJ_DIR)$(MAIN_FUNCTION_DIR)
MAIN_FUNCTION_OBJ_FILE = $(MAIN_FUNCTION_SRC_FILE:.c=.o)
MAIN_FUNCTION_OBJS = \
		$(addprefix $(MAIN_FUNCTION_OBJ_DIR), \
		$(MAIN_FUNCTION_OBJ_FILE))

# **************************************************************************** # 

# utils_and_etc

UTILS_AND_ETC_DIR = ./utils_and_etc/

UTILS_AND_ETC_SRC_DIR = $(SRC_DIR)$(UTILS_AND_ETC_DIR)
UTILS_AND_ETC_SRC_FILE = \
		errors.c \
		execute_command.c \
		terminate.c

UTILS_AND_ETC_SRCS = \
		$(addprefix $(UTILS_AND_ETC_SRC_DIR), \
		$(UTILS_AND_ETC_SRC_FILE))

UTILS_AND_ETC_OBJ_DIR = $(OBJ_DIR)$(UTILS_AND_ETC_DIR)
UTILS_AND_ETC_OBJ_FILE = $(UTILS_AND_ETC_SRC_FILE:.c=.o)
UTILS_AND_ETC_OBJS = \
		$(addprefix $(UTILS_AND_ETC_OBJ_DIR), \
		$(UTILS_AND_ETC_OBJ_FILE))

# **************************************************************************** #

OBJS_WITHOUT_MAIN = \
		$(UTILS_AND_ETC_OBJS)

OBJS = $(MAIN_FUNCTION_OBJS) $(OBJS_WITHOUT_MAIN)

# **************************************************************************** #

# main rules

all : $(NAME)
	@printf "$(Red)\n[ PIPEX compile finished!!] \n$(Color_Off)"
ifdef LETS_DEBUG
	@printf "$(Red)\n[ DEBUGGING MODE ENABLED!!] \n$(Color_Off)"
endif

$(NAME) : $(OBJS)
	@make mylib
	$(CC) $(CFLAGS) -o $@ $^ $(MY_LIB_DIR)$(MY_LIB_ARC)

$(MAIN_FUNCTION_OBJ_DIR)%.o : $(MAIN_FUNCTION_SRC_DIR)%.c
	@mkdir -p $(MAIN_FUNCTION_OBJ_DIR)
	$(CC) $(CFLAGS) $(DBFLAG) $(INCLUDE) -c $< -o $@

$(UTILS_AND_ETC_OBJ_DIR)%.o : $(UTILS_AND_ETC_SRC_DIR)%.c
	@mkdir -p $(UTILS_AND_ETC_OBJ_DIR)
	$(CC) $(CFLAGS) $(DBFLAG) $(INCLUDE) -c $< -o $@

# **************************************************************************** #

# test

TEST_NAME = pipex_test
TEST_SRC_FILE = \
		pipex_test_main.c

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE));

TEST_OBJS = $(TEST_SRCS:.c=.o)

test : mylib $(TEST_NAME)
	@printf "$(Red)\n[ PIPEX TEST VER compile finished!!] \n$(Color_Off)"
	@./$(TEST_NAME)

$(TEST_NAME) : $(OBJS_WITHOUT_MAIN) $(TEST_OBJS)
	$(CC) $(DBFLAG) $(MY_LIB) -o $@ $^

$(TEST_DIR)%.o : $(TEST_DIR)%.c
	$(CC) $(DBFLAG) $(INCLUDE) -c $< -o $@

# **************************************************************************** #

debug : clean
	LETS_DEBUG=1 make

clean :
	rm -rf ./obj
	rm -rf ./test/*.o

fclean : clean
	@make fclean -C $(MY_LIB_DIR)
	rm -f $(NAME)
	rm -f $(TEST_NAME)
	rm -f infile.txt outfile.txt

re : fclean all

mylib :
	@make -C $(MY_LIB_DIR)

.PONEY : all test clean fclean re mylib
