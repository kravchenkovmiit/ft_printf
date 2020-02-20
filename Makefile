
NAME = libftprintf.a

FF = -Wall -Wextra -Werror

LIB_DIR = ./libft
SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./inc

SRC = convert.c convert_float.c convert_lfloat.c \
      display.c float.c get_from_string.c get_numbers.c \
      join_pf.c l_float.c printf.c tools.c tools_float.c \
      types_1.c types_2.c types_3.c types_4.c \
      wildcard.c f_check_neg.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))

LIB = $(LIB_DIR)/libft.a

LIB_INC = $(LIB_DIR)/

all : $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@make -C libft

$(NAME) : $(OBJ_DIR) $(LIB) $(OBJ)
	@ar rc $(NAME) $(OBJ) $(LIB_DIR)/*.o
	@ranlib $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@gcc $(FF) -I$(INC_DIR) -I$(LIB_INC) $< -c -o $@

clean :
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean : clean
	@rm -rf $(NAME)
	@make -C libft fclean

re : fclean all
