# COLORS
GREEN			:= \033[32m
NC				:= \033[m

NAME = philo_bonus

SRC_DIR = src_bonus
OBJ_DIR = obj_bonus
INC_DIR = inc_bonus

SRC = philo_main_bonus.c philo_check_bonus.c \
		philo_utils_bonus.c philo_init_bonus.c \
		philo_create_bonus.c philo_routine_bonus.c philo_print_bonus.c 

INC = -I $(INC_DIR)
	  
OBJ             = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DEP             = $(addsuffix .d, $(basename $(OBJ)))

CC = gcc

CFLAGS 			= -Werror -Wall -Wextra -MMD $(INC)
PTHREADS        = -lpthread
RM_DIR          = rm -rf
MKDIR           = mkdir -p

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c Makefile
	@$(MKDIR) $(dir $@)
	@gcc -c -g $(CFLAGS) -o $@ $<
	@echo "Compiling..."

all: $(NAME)

-include $(DEP)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(PTHREADS) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled!$(NC)"

clean :
	@$(RM) $(OBJ)
	@$(RM_DIR) $(OBJ_DIR)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

fclean : clean
	@$(RM) $(NAME)

re : fclean all

PHONY: clean re fclean all