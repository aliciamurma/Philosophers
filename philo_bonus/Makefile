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


run: $(NAME)
#	@ ./$(NAME) 1 800 200 200
	@ ./$(NAME) 5 800 200 200
#	@ ./$(NAME) 5 800 200 200 5
#	@ ./$(NAME) 4 410 200 200
#	@ ./$(NAME) 5 420 200 100
#	@ ./$(NAME) 100 470 200 200

norm:
	@norminette philosophers | sh ../norminette.sh

PHONY: clean re fclean all