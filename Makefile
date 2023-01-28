SOURCES = $(wildcard ./mandatory/*.c)

BSOURCES = $(wildcard ./bonus/*.c)
		
CC		=	cc

CFLAGS	=	 -g -Wall -Wextra -Werror -fsanitize=address

NAME	=	push_swap
BNAME	=	checker
MK_FILE = Makefile
LIBFT	=	./libft/libft.a

all:	$(NAME)

$(NAME):	$(SOURCES) $(MK_FILE)
		make -C libft
		$(CC) $(CFLAGS) $(SOURCES) $(LIBFT)  -o $(NAME)

bonus:	$(BNAME)

$(BNAME):	$(BSOURCES) $(MK_FILE)
		make -C libft
		$(CC) $(CFLAGS) $(BSOURCES) $(LIBFT)  -o $(BNAME)

clean:
		make clean -C libft

fclean:	clean
			rm -rf $(NAME) $(BNAME) $(LIBFT) 

re:	fclean all