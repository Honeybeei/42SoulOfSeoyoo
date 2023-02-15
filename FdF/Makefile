# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 17:02:01 by seoyoo            #+#    #+#              #
#    Updated: 2022/11/18 15:36:30 by seoyoo           ###   ########.fr        #
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
NAME = fdf

# compiler
CC = cc
DBFLAGS = -g
CFLAGS = -Wall -Wextra -Werror

# basic directories
SRC_DIR = ./src/
OBJ_DIR = ./obj/
TEST_DIR = ./test/

# include
INC_DIR = ./inc/
INC_FLAGS = -I $(INC_DIR)

# my_lib
MY_LIB_DIR = ./my_lib/
MY_LIB_ARC = my_lib.a
MY_LIB = $(MY_LIB_DIR)$(MY_LIB_ARC)

# mlx related
MLX_DIR = ./mlx/
MLX_ARC = libmlx.a
MLX = $(MLX_DIR)$(MLX_ARC)
API_FLAGS = -framework OpenGL -framework AppKit
# API_FLAGS = -framework Metal -framework Metalkit

# only for M1 processor
M1_COMPILE_CMD = arch -x86_64

# so...... in this project, we wil use 
ifdef MAKE_IN_M1
	COMPILE_FLAGS = $(M1_COMPILE_CMD) $(CC) $(DBFLAGS) $(CFLAGS) $(INC_FLAGS) -I $(MLX_DIR)
	LINKING_FLAGS = $(M1_COMPILE_CMD) $(CC) $(MLX) $(MY_LIB) $(API_FLAGS)
else
	COMPILE_FLAGS = $(CC) $(DBFLAGS) $(CFLAGS) $(INC_FLAGS) -I $(MLX_DIR)
	LINKING_FLAGS = $(CC) $(MLX) $(MY_LIB) $(API_FLAGS)
endif


# **************************************************************************** #

# main_function

MAIN_FUNCTION_DIR = ./main_function/

MAIN_FUNCTION_SRC_DIR = $(SRC_DIR)$(MAIN_FUNCTION_DIR)

MAIN_FUNCTION_SRC_FILE = \
		fdf_main.c 

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
		actions.c \
		draw_2d_segment.c \
		draw_2d_vector.c \
		draw_projection_to_img.c \
		error_handling.c \
		map_object_management.c \
		p_map_object_management.c \
		projection.c \
		view_point.c

UTILS_SRCS = \
		$(addprefix $(UTILS_SRC_DIR), \
		$(UTILS_SRC_FILE))

UTILS_OBJ_DIR = $(OBJ_DIR)$(UTILS_DIR)
UTILS_OBJ_FILE = $(UTILS_SRC_FILE:.c=.o)
UTILS_OBJS = \
		$(addprefix $(UTILS_OBJ_DIR), \
		$(UTILS_OBJ_FILE))

# **************************************************************************** # 

# figures

FIGURES_DIR = ./figures/

FIGURES_SRC_DIR = $(SRC_DIR)$(FIGURES_DIR)
FIGURES_SRC_FILE = \
		get_distance_between.c \
		printable_2d_vector.c \
		three_dimensional_vector.c \
		two_dimensional_segment.c \
		two_dimensional_vector.c

FIGURES_SRCS = \
		$(addprefix $(FIGURES_SRC_DIR), \
		$(FIGURES_SRC_FILE))

FIGURES_OBJ_DIR = $(OBJ_DIR)$(FIGURES_DIR)
FIGURES_OBJ_FILE = $(FIGURES_SRC_FILE:.c=.o)
FIGURES_OBJS = \
		$(addprefix $(FIGURES_OBJ_DIR), \
		$(FIGURES_OBJ_FILE))

# **************************************************************************** # 

# parsing_tools

PARSING_TOOLS_DIR = ./parsing_tools/

PARSING_TOOLS_SRC_DIR = $(SRC_DIR)$(PARSING_TOOLS_DIR)
PARSING_TOOLS_SRC_FILE = \
		ect_functions.c \
		get_map_data.c \
		get_next_line_utils.c \
		get_next_line.c \
		string_list_1.c \
		string_list_2.c

PARSING_TOOLS_SRCS = \
		$(addprefix $(PARSING_TOOLS_SRC_DIR), \
		$(PARSING_TOOLS_SRC_FILE))

PARSING_TOOLS_OBJ_DIR = $(OBJ_DIR)$(PARSING_TOOLS_DIR)
PARSING_TOOLS_OBJ_FILE = $(PARSING_TOOLS_SRC_FILE:.c=.o)
PARSING_TOOLS_OBJS = \
		$(addprefix $(PARSING_TOOLS_OBJ_DIR), \
		$(PARSING_TOOLS_OBJ_FILE))


# **************************************************************************** #

OBJS_WITHOUT_MAIN = \
		$(UTILS_OBJS) \
		$(FIGURES_OBJS) \
		$(PARSING_TOOLS_OBJS)

OBJS = $(MAIN_FUNCTION_OBJS) $(OBJS_WITHOUT_MAIN)

# **************************************************************************** #

# main rules

all : $(NAME)

#	linking
$(NAME) : $(OBJS)
	@make mylib
	@make minilibx
	@printf "$(Green)\n[ mylib & minilibx compile finished!!] \n$(Color_Off)"
	$(LINKING_FLAGS) -o $@ $^
	@printf "$(Blue)\n[ ENJOY FDF!! ]\n$(Color_Off)"

#	compiling
$(MAIN_FUNCTION_OBJ_DIR)%.o : $(MAIN_FUNCTION_SRC_DIR)%.c
	@mkdir -p $(MAIN_FUNCTION_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

$(UTILS_OBJ_DIR)%.o : $(UTILS_SRC_DIR)%.c
	@mkdir -p $(UTILS_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

$(FIGURES_OBJ_DIR)%.o : $(FIGURES_SRC_DIR)%.c
	@mkdir -p $(FIGURES_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

$(PARSING_TOOLS_OBJ_DIR)%.o : $(PARSING_TOOLS_SRC_DIR)%.c
	@mkdir -p $(PARSING_TOOLS_OBJ_DIR)
	$(COMPILE_FLAGS) -c $< -o $@

# **************************************************************************** #

# test

TEST_NAME = fdf_test
TEST_SRC_FILE = \
		fdf_test_main.c \
		print_map_data.c

TEST_SRCS = $(addprefix $(TEST_DIR), $(TEST_SRC_FILE));

TEST_OBJS = $(TEST_SRCS:.c=.o)

#	Change map file here
TEST_ARGS = ./maps/42.fdf

test : mylib minilibx $(TEST_NAME)
	@printf "$(Green)\n[ FDF TEST VER compile finished!!] \n\n\n$(Color_Off)"
	@./$(TEST_NAME) $(TEST_ARGS)

$(TEST_NAME) : $(OBJS_WITHOUT_MAIN) $(TEST_OBJS)
	$(LINKING_FLAGS) -o $@ $^

$(TEST_DIR)%.o : $(TEST_DIR)%.c
	$(COMPILE_FLAGS) -c $< -o $@

# **************************************************************************** #

# Works well in M1 processor without using M1_COMPILE_CMD...... 
# m1 : clean
# 	MAKE_IN_M1=1 make

clean :
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_DIR)*.o

fclean : clean
	@make fclean -C $(MY_LIB_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(NAME)
	rm -f $(TEST_NAME)

re : fclean all

ree : clean all

mylib :
	@make -C $(MY_LIB_DIR)

minilibx : 
	@make -C $(MLX_DIR)

norm :
	@norminette ./inc ./my_lib ./src

.PONEY : all test clean fclean re ree mylib minilibx norm
