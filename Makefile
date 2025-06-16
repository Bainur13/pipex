#Libft

LIBFT_DIR		= Includes/libft/
LIBFT_NAME		= libft.a
LIBFT			= $(LIBFT_DIR)$(LIBFT_NAME)

#Printf

PRINTF_DIR		= Includes/ft_printf/
PRINTF_NAME		= libftprintf.a
PRINTF			= $(PRINTF_DIR)$(PRINTF_NAME)

#Variables

NAME	= pipex
CC		= cc
FLAGS	= -Wall -Werror -Wextra -g3
RM				= rm -f
AR				= ar rcs
NORM			= ./includes\
					./libft/include/\
					s./libft/src_lib
INCLUDE			= 	-I ./includes/\
					-I ./libft/\
					-I ./ft_printf/\
					-I ./get_next_line/

#Sources

OBJ_DIR_F 		= obj/
SRC_DIR_F		= src/
SRC_FUNCTIONS_F = pipex \
					utils

PS_SRC		= $(addprefix $(SRC_DIR_F), $(addsuffix .c, $(SRC_FUNCTIONS_F))) Includes/get_next_line/get_next_line.c Includes/get_next_line/get_next_line_utils.c
PS_OBJ		= $(addprefix $(OBJ_DIR_F), $(addsuffix .o, $(SRC_FUNCTIONS_F))) Includes/get_next_line/get_next_line.c Includes/get_next_line/get_next_line_utils.c

#Bonus 
BONUS_NAME		= pipex_bonus
BONUS_SRC_FUNCTIONS_F = pipex_bonus \
					pipex_utils_bonus \
					pipex_utils2_bonus

BONUS_SRC		= $(addprefix $(SRC_DIR_F), $(addsuffix .c, $(BONUS_SRC_FUNCTIONS_F))) Includes/get_next_line/get_next_line.c Includes/get_next_line/get_next_line_utils.c
BONUS_OBJ		= $(addprefix $(OBJ_DIR_F), $(addsuffix .o, $(BONUS_SRC_FUNCTIONS_F))) Includes/get_next_line/get_next_line.c Includes/get_next_line/get_next_line_utils.c
#Cache

IFMAKE_DIR_F	= .cache_exists

#instructions

all: 		$(LIBFT) $(PRINTF) $(NAME)

$(IFMAKE_DIR_F):
			@mkdir -p $(OBJ_DIR_F)
			@mkdir -p $(OBJ_DIR_F)pipex/

$(LIBFT):
					@echo "Getting libft ready"
					@make -sC $(LIBFT_DIR)

$(PRINTF):
					@echo "Getting printf ready"
					@make -sC $(PRINTF_DIR)

$(OBJ_DIR_F)%.o: $(SRC_DIR_F)%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@


$(OBJ_DIR_F)pipex/%.o: $(SRC_DIR_F)pipex/%.c | $(IFMAKE_DIR_F)
					@echo "$(ORANGE)Loading... $< $(DEF_COLOR)"
					@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(PS_OBJ) $(LIBFT) $(PRINTF)
					@echo "Compiling pipex..."
					@$(CC) $(FLAGS) -o $(NAME) $(PS_OBJ) $(LIBFT) $(PRINTF) $(INCLUDE) -g3
					@echo "pipex ready."


bonus : $(BONUS_OBJ) $(LIBFT) $(PRINTF)
					@echo "Compiling pipex_bonus..."
					@$(CC) $(FLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) $(LIBFT) $(PRINTF) $(INCLUDE) -g3
					@echo "pipex_bonus ready."


clean:
					@echo "Removing object files"
					@rm -rf $(OBJ_DIR_F)
					@make clean -C $(LIBFT_DIR)
					@make clean -C $(PRINTF_DIR)

fclean:			clean
					@echo "Removing pipex..."
					@echo "Removing pipex_bonus..."
					@rm -f $(BONUS_NAME)
					@rm -f $(NAME)
					@rm -f $(LIBFT_DIR)$(LIBFT_NAME)
					@rm -f $(PRINTF_DIR)$(PRINTF_NAME)

re:				fclean all
					@echo "$(BLUE)Cleaned and rebuilt everything for push_swap$(DEF_COLOR)"

.PHONY: all re clean fclean norm bonus