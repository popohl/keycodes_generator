# Folders and Names
NAME		= libft.a
SRCSDIR		= srcs
OBJSDIR		= objs
INCLUDES	= incs

SRCS		= checker/ft_isalnum.c checker/ft_isalpha.c checker/ft_isascii.c \
			  checker/ft_isdigit.c checker/ft_isprint.c checker/ft_isnumber.c \
			  checker/ft_iswhitespace.c \
			  conv/ft_atoi.c conv/ft_itoa.c \
			  io/ft_getopt.c io/ft_putchar_fd.c io/ft_putendl_fd.c \
			  io/ft_putnbr_fd.c io/ft_putstr_fd.c io/get_next_line.c \
			  linked_list/one_way_list/ft_lstadd_back.c \
			  linked_list/one_way_list/ft_lstadd_front.c \
			  linked_list/one_way_list/ft_lstclear.c \
			  linked_list/one_way_list/ft_lstdelone.c \
			  linked_list/one_way_list/ft_lstiter.c \
			  linked_list/one_way_list/ft_lstlast.c \
			  linked_list/one_way_list/ft_lstmap.c \
			  linked_list/one_way_list/ft_lstnew.c \
			  linked_list/one_way_list/ft_lstsize.c \
			  math/ft_pow.c \
			  mem/ft_bzero.c mem/ft_calloc.c mem/ft_memccpy.c mem/ft_memchr.c \
			  mem/ft_memcmp.c mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c \
			  num/ft_intlen.c str/ft_split.c str/ft_strcmp.c str/ft_strjoin.c \
			  str/ft_strlcpy.c str/ft_strmapi.c str/ft_strnstr.c \
			  str/ft_strtrim.c str/ft_tolower.c str/ft_strchr.c \
			  str/ft_strdup.c str/ft_strlcat.c str/ft_strlen.c \
			  str/ft_strncmp.c str/ft_strrchr.c str/ft_substr.c \
			  str/ft_toupper.c str/ft_strreplace.c str/ft_strncpy.c \
			  str/ft_strcpy.c

# Compiler options
CC			= gcc
CFLAGS		= -Wall -Wextra -g3

###################################################
# The rest is done by the MakeFile automatically, #
# you should not have to modify it				  #
###################################################

OBJS		= $(SRCS:%.c=$(OBJSDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJS)
	@echo "Done!"

$(OBJS): $(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	./$(NAME)

.PHONY: all clean fclean re test

