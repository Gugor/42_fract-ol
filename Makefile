
# COLORS

# Targets
NAME	= fractol
MLX		= libmlx
PRINTF  = printf
LIBFT	= libft

# Directories 
LIBFT_DIR	:= ./libs/libft
PRINTF_DIR	:= ./libs/ft_printf
MLX_DIR		:= ./libs/MLX42
INCS_DIR	:= ./includes
SRCS_DIR 	:= ./srcs

# Makfile
MF			:= Makefile

# Bibliotecas
LIBFT_LIB		= $(abspath $(LIBFT_DIR)/libft.a)
PRINTF_LIB		= $(abspath $(PRINTF_DIR)/libftprintf.a)
MLX_LIB			= $(abspath $(MLX_DIR)/build/libmlx42.a)

# Compiler
CC 			:= gcc
CFLAGS 		:= -g -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)/include 
LDFLAGS 	:= -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf 
LMLXFLAGS	:= -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
## -L$(MLX) -lmlx -framework OpenGL -framework AppKit  -Wdeprecated-declarations

# Files
SRCS_FILES	= fractol.c math-utils.c complex_nums.c render.c init.c events.c randomize.c
INCS_FILES	= fractol.h libft.h ft_printf.h events.h

#Route to Includes
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
INCS		= $(addprefix $(INCS_DIR)/, $(INCS_FILES))

# Routes to Objects
OBJS		= $(SRCS_DIR/%.c=%.o)


# Basic Rules
all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

# Compilation of Object files
$(OBJS): $(SRCS)
	$(CC) -c $< $(CFLAGS) -o $@

# Target Compilation
$(NAME) : $(MF) $(OBJS) $(INCS)  
	$(CC) $(SRCS) $(CFLAGS) $(LDFLAGS) $(LMLXFLAGS) -o $(NAME)

# MLX LIBS
$(MLX) :
	@echo "=== MLX Lib compiling"
	@cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

# Complilacion LIBFT
$(LIBFT) :
	@echo "=== Libft compiling"
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF) :
	@echo "=== Printf compiling"
	$(MAKE) -C $(PRINTF_DIR)

# Start or Run the program
run : $(NAME)
	./$(NAME)

clean:
	@echo ":: Removing object files..."
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MLX_DIR)/build clean
	@rm -vf $(OBJS)

fclean: clean
	@echo ":: Removing execs"
	@rm -vf $(NAME)

re: fclean all 

.PHONY: clean fclean re all
