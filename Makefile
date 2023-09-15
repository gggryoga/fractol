NAME = fractol
CC	=	cc -g
MLX = -lmlx -Lmlx -framework OpenGL -framework AppKit 
CFLAGS = -Wall -Wextra -Werror -I include
RM = rm -rf
LIBFT_DIR = libft
LIBFT = libft/libft.a
SRCS_LST	=	main.c
SRCS_OBJS = $(SRCS_LST:.c=.o)

all:	$(NAME) 

$(NAME): $(LIBFT) $(SRCS_OBJS)
	$(CC) $(SRCS_OBJS) $(MLX) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)
clean:	
		$(RM) $(SRCS_OBJS)
		make clean -C libft

fclean:	clean
		$(RM) $(SRCS_OBJS)
		$(RM) libft/libft.a

re:		fclean $(NAME)



.PHONY: all clean fclean re