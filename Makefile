
# COLORS

# Targets
NAME	= fractol
MLX		= libmlx
PRINTF  = printf
LIBFT	= libft

# Directories 
LIBFT_DIR	:= ./libs/libft
PRINTF_DIR	:= ./libs/ft_printf
MLX_DIR		:= ./libs/minilix
INCS_DIR	:= ./includes
SRCS_DIR 	:= ./srcs

# Makfile
MF			:= Makefile

# Bibliotecas
LIBFT_LIB		= $(abspath $(LIBFT_DIR)/libft.a)
PRINTF_LIB		= $(abspath $(PRINTF_DIR)/libftprintf.a)
MLX_LIB			= $(abspath $(MLX_DIR)/libmlx.a)

# Compiler
CC 			:= gcc
CFLAGS 		:= -g -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(MLX_DIR)/include 
CCFLAGS 	:= -g -Wall -Wextra -Werror -I$(INCS_DIR) -I$(MLX_DIR) 
LDFLAGS 	:= -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf 
LMLXFLAGS	:= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit 

# Files
SRCS_FILES	= fractol.c  math-utils.c complex_nums.c render.c init.c randomize.c events.c \
			events2.c mandelbrot.c julia.c burningships.c 
INCS_FILES	= fractol.h libft.h ft_printf.h events.h

#Route to Includes
SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
INCS		= $(addprefix $(INCS_DIR)/, $(INCS_FILES))

# Routes to Objects
OBJS		= $(SRCS_DIR/%.c=%.o)


# Basic Rules
all: $(PRINTF) $(LIBFT) $(MLX) $(NAME)

# Compilation of Object files
#$(OBJS): $(SRCS)
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR) 
	$(CC) -c $< $(CFLAGS) -o $@

# Target Compilation
$(NAME) : $(MF) $(OBJS) $(INCS)  
	$(CC) $(SRCS) $(CFLAGS) $(LDFLAGS) $(LMLXFLAGS) -o $(NAME)

# MLX LIBS
$(MLX) :
	@echo "=== MLX Lib compiling"
	@make -C $(MLX_DIR)

# Complilacion LIBFT
$(LIBFT) :
	@echo "=== Libft compiling"
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF) :
	@echo "=== Printf compiling"
	$(MAKE) -C $(PRINTF_DIR)

# Start or Run the program
run1 : $(NAME)
	./$(NAME) "mandelbrot"

run2 : $(NAME)
	./$(NAME) "julia" -0.70176  -0.3842 

run3 : $(NAME)
	./$(NAME) "burningships"

clean:
	@echo ":: Removing object files..."
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	@rm -vf $(SRC_OBJS)

fclean: clean
	@echo ":: Removing execs"
	@rm -vf $(NAME)

re: fclean all 

.PHONY: clean fclean re all
