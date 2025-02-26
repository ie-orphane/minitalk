BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

NAME = client server

SRCS_DIR = srcs
SRCS = 

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

INCLUDE_DIR = include
_INCLUDES = main.h
INCLUDES = $(addprefix $(INCLUDE_DIR)/,$(_INCLUDES))

LIB = libft
LIB_FILE = libft/libft.a

CC = cc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -O3
IFLAGS =  -I$(INCLUDE_DIR) -I$(LIB)
LFLAGS = -L$(LIB) -l$(subst lib,,$(LIB)) # -fsanitize=address -g3

DEV_NULL = 1> /dev/null
NO_PRINT = --no-print-directory


all : $(NAME)

$(NAME): $(LIB_FILE) $(OBJS) $(INCLUDES)
	@$(CC) $(addprefix $(SRCS_DIR)/, $(@:=.c)) $(OBJS) $(LFLAGS) $(IFLAGS) -o $(@)
	@echo "🔗 $(CYAN)$(notdir $(OBJS)) $(@:=.o) $(BLACK)=> $(YELLOW)$(@)$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@echo "🔨 $(BLUE)$(notdir $<) $(BLACK)=> $(CYAN)$(notdir $@)$(RESET)"

$(LIB_FILE):
	@$(MAKE) -C $(LIB) $(DEV_NULL)
	@echo "🏗️  $(MAGENTA)$@$(RESET)"

clean :
	@$(MAKE) -C $(LIB) clean $(DEV_NULL)
	@echo "🗑  $(BLACK)$(LIB)$(RESET)"
	@$(RM) $(OBJS_DIR)
	@echo "🧹 $(BLACK)$(notdir $(OBJS))$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "🧹 $(BLACK)$(NAME)$(RESET)"
	@$(MAKE) -C $(LIB) fclean $(DEV_NULL)

re : fclean all

run :
	@$(MAKE) $(NO_PRINT) $(DEV_NULL)
	@./$(NAME) $(ARGS)

valgrind :
	@$(MAKE) $(NO_PRINT) $(DEV_NULL)
	@valgrind ./$(NAME) $(ARGS)

.PHONY : all clean fclean re run valgrind
