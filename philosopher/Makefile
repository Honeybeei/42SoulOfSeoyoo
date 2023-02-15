# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:02:01 by seoyoo            #+#    #+#              #
#    Updated: 2022/12/06 15:16:39 by seoyoo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# color setting
Color_Off = \033[0m		# Text Reset
Black = \033[0;30m		# Black
Green = \033[0;31m		# Green
Green = \033[0;32m		# Green
Yellow = \033[0;33m		# Yellow
Blue = \033[0;34m		# Blue
Purple = \033[0;35m		# Purple
Cyan = \033[0;36m		# Cyan
White = \033[0;37m		# White

# **************************************************************************** #

# target
NAME = philo

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
EXTRAFLAGS = -pthread			# -pthread to use pthread
# EXTRAFLAGS = -fsanitize=thread	# check data racing
# EXTRAFLAGS = -fsanitize=address	# check mem leak

# basic directories
SRC_DIR = ./src/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# include
INC_DIR = ./inc/
INC_FLAGS = -I $(INC_DIR)

COMPILE_FLAGS = $(CC) $(EXTRAFLAGS) $(CFLAGS) $(INC_FLAGS)
COMPILE_FLAGS_FOR_TEST = $(CC) $(EXTRAFLAGS) $(INC_FLAGS)	# without -WWW
LINKING_FLAGS = $(CC) $(EXTRAFLAGS) $(CFLAGS)

# **************************************************************************** #

# main_function

MAIN_FUNCTION_DIR = ./main_function/

MAIN_FUNCTION_SRC_DIR = $(SRC_DIR)$(MAIN_FUNCTION_DIR)

MAIN_FUNCTION_SRC_FILE = \
		main_philo.c

MAIN_FUNCTION_SRCS = \
		$(addprefix $(MAIN_FUNCTION_SRC_DIR), \
		$(MAIN_FUNCTION_SRC_FILE))

MAIN_FUNCTION_OBJ_DIR = $(OBJ_DIR)$(MAIN_FUNCTION_DIR)
MAIN_FUNCTION_OBJ_FILE = $(MAIN_FUNCTION_SRC_FILE:.c=.o)
MAIN_FUNCTION_OBJS = \
		$(addprefix $(MAIN_FUNCTION_OBJ_DIR), \
		$(MAIN_FUNCTION_OBJ_FILE))

# **************************************************************************** # 

# utils

UTILS_DIR = ./utils/

UTILS_SRC_DIR = $(SRC_DIR)$(UTILS_DIR)
UTILS_SRC_FILE = \
		check_arguments.c \
		errors.c \
		etc_tools_1.c \
		etc_tools_2.c \
		initialize_ptrs.c \
		libft_functions.c \
		philosophers_1.c \
		philosophers_2.c

UTILS_SRCS = \
		$(addprefix $(UTILS_SRC_DIR), \
		$(UTILS_SRC_FILE))

UTILS_OBJ_DIR = $(OBJ_DIR)$(UTILS_DIR)
UTILS_OBJ_FILE = $(UTILS_SRC_FILE:.c=.o)
UTILS_OBJS = \
		$(addprefix $(UTILS_OBJ_DIR), \
		$(UTILS_OBJ_FILE))

# **************************************************************************** #

OBJS_WITHOUT_MAIN = \
		$(UTILS_OBJS)

OBJS = $(MAIN_FUNCTION_OBJS) $(OBJS_WITHOUT_MAIN)

# **************************************************************************** #

# main rules

all : $(NAME)

#	linking
$(NAME) : $(OBJS)
	$(LINKING_FLAGS) -o $@ $^
	@printf "$(Blue)\n[ STUPID PHILOSOPHERS...... ]\n$(Color_Off)"

#	compiling
$(MAIN_FUNCTION_OBJ_DIR)%.o : $(MAIN_FUNCTION_SRC_DIR)%.c
	@mkdir -p $(MAIN_FUNCTION_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

$(UTILS_OBJ_DIR)%.o : $(UTILS_SRC_DIR)%.c
	@mkdir -p $(UTILS_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

# **************************************************************************** #

# test

TEST_NAME = philo_test
TEST_SRC_FILE = \
		test_main_philo.c \
		utils_for_test.c

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE))

TEST_OBJS = $(TEST_SRCS:.c=.o) $(OBJS_WITHOUT_MAIN)

#	test argvs
TEST_ARGS = 10 2 3 4 

# To activate testing area, decommentize the code below and also .PONEY
# # test : clean $(TEST_NAME)
# 	@printf "$(Green)\n[ LETS TEST THOSE STUPID PHILOSOPHERS! ]\n\n$(Color_Off)"
# 	@./$(TEST_NAME) $(TEST_ARGS)

$(TEST_NAME) : $(TEST_OBJS)
	$(LINKING_FLAGS) -o $@ $^

$(TEST_DIR)%.o : $(TEST_DIR)%.c
	$(COMPILE_FLAGS_FOR_TEST) -c $< -o $@

# **************************************************************************** #

# etc rules

clean :
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_OBJS)

fclean : clean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re : fclean all

ree : clean all

norm :
	@norminette ./inc ./src

.PONEY : all clean fclean re ree norm #test

# **************************************************************************** #
