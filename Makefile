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
SRCS	= main.c colors.c calculate_fractal.c

# list of external libraries
LIBS	= minilibx libft

# Compiler
CC		= gcc
# Compiler flags
CFLAGS	+= -Wall -Wextra -Ofast
# Assembly flags (add the libraries here for linux)
LDFLAGS	+= -lmlx -framework OpenGL -framework AppKit

# The rest is automatic

CFLAGS	+= -I$I
CFLAGS	+= $(foreach lib,$(LIBS),-I $(lib))
LDFLAGS	+= $(foreach lib,$(LIBS),-L $(lib))

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
	@echo "Compiling $^: "
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "✓"

$D:
	@mkdir $@

$(DEPS): | $D

$(DEPS): $D%.d: $S%
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<

$(NAME): $(OBJS)
	@echo "Building external libraries"
	@$(foreach lib, $(LIBS),make --directory=$(lib) > /dev/null 2> /dev/null;)
	@echo "Assembling $(NAME)"
	@$(CC) $(LDFLAGS) $^ -o $@

clean:
	@echo "Cleaning up..."
	@$(foreach lib, $(LIBS),make --directory=$(lib) clean 2> /dev/null > /dev/null;)
	@$(RM) $D $O

fclean: clean
	@echo "Everything!"
	@$(foreach lib, $(LIBS),make --directory=$(lib) fclean 2> /dev/null > /dev/null;)
	@$(RM) $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

-include $(DEPS)
