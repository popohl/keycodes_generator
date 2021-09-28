# Source files directory
S		= srcs/
# Object files directory
O		= objs/
# Include files directory
I		= incs/
# Dependency files directory
D		= deps/

# Name of your program
NAME	= fractol

# list of your source files
SRCS	= main.c \
		  algorithms/calculate_fractal.c algorithms/values_updating.c \
		  algorithms/zoom.c algorithms/calculate_fractal_2.c \
		  initialization/config_initialisation.c initialization/error.c \
		  initialization/hooks.c \
		  draw/draw.c draw/bmp_creator.c draw/generate_screenshot.c draw/hud.c \
		  draw/help.c draw/color_functions.c

# list of external libraries
LIBS	= minilibx libft
LIB_INC	= minilibx/ libft/incs/
LIB_BIN	= libft/libft.a

# Compiler
CC		= gcc
# Compiler flags
CFLAGS	+= -Wall -Wextra -Ofast#-fsanitize=address -g3 
# Assembly flags (add the libraries here for linux)
LDFLAGS	= -lmlx

# Operating system specific actions
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIB_BIN += minilibx/libmlx_Linux.a
	CCFLAGS += -D LINUX
	LDFLAGS	+= -lm -lX11 -lXext -FOpenGL -FAppKit
	I		+= incs/linux_specific/
endif
ifeq ($(UNAME_S),Darwin)
	LIB_BIN += minilibx/libmlx_Macos.a
	CCFLAGS += -D OSX
	LDFLAGS	+= -framework OpenGL -framework AppKit
	I		+= incs/macos_specific/
endif

CFLAGS	+= $(foreach inc,$I,-I $(inc))
CFLAGS	+= $(foreach lib_inc,$(LIB_INC),-I $(lib_inc))
LDFLAGS	+= $(foreach lib,$(LIBS),-L$(lib))

SRCS	:= $(foreach file,$(SRCS),$S$(file))
OBJS	= $(SRCS:$S%=$O%.o)
DEPS	= $(SRCS:$S%=$D%.d)

RM		= /bin/rm -rf

.PHONY: all clean fclean re test

all: $(NAME)

$O:
	@mkdir $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
	@mkdir -p $(@D)
	@echo "Compiling $<: "
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "✓"

$D:
	@mkdir $@

$(DEPS): | $D

$(DEPS): $D%.d: $S%
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJS)
	@echo "Building external libraries:"
	@$(foreach lib, $(LIBS),echo "$(lib):"&& make --directory=$(lib) > /dev/null&& echo "Done ✓";)
	@echo "Assembling $(NAME)"
	@$(CC) $(CFLAGS) $^ $(LIB_BIN) $(LDFLAGS) -o $@
	@mkdir -p screenshots/

clean:
	@echo "Cleaning up..."
	@$(RM) $D $O

libclean:
	@echo "Cleaning up, including libraries..."
	@$(foreach lib, $(LIBS),make --directory=$(lib) clean 2> /dev/null > /dev/null;)
	@$(RM) $D $O

fclean: clean
	@echo "Everything!"
	@$(RM) $(NAME)

libfclean: libclean
	@echo "Everything!"
	@$(foreach lib, $(LIBS),make --directory=$(lib) fclean 2> /dev/null > /dev/null;)
	@$(RM) $(NAME)

re: fclean all

libre: libfclean all

test: $(NAME)
	./$(NAME) mandelbrot

-include $(DEPS)
