# COLORS
GREEN			:= \033[32m
NC				:= \033[m

NAME = philo

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = philo_main.c philo_print.c philo_utils.c philo_check.c philo_init.c philo_create.c philo_routine.c philo_finish.c philo_delete.c
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