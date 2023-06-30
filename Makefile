CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread #-fsanitize=thread -g
#MLXFLAGS	= -lmlx -framework OpenGL -framework AppKit
RM			= rm -f

NAME		=	mlx-tutorial

# DEPS		=	libft/libft.a get_next_line/get_next_line.a
# INCLUDE		=	-I cub3d.h
SRCS_		=	main.c \
				window.c \
				image.c
	

SRCS		=	$(addprefix $(_SRC), $(SRCS_))

_OBJ		=	./obj/
_SRC		= 	./src/
OBJS		=	$(patsubst $(_SRC)%.c, $(_OBJ)%.o, $(SRCS))

all:		$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	
$(NAME): $(_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx_Linux -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 
#$(DEPS)

#bonus:		$(SRCS_B) $(OBJS_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -o $(NAME_B)
#			$(CC) $(CFLAGS) $(SRCS_B) -c

# libft/libft.a:
# 	make libft.a -C libft

# get_next_line/get_next_line.a:
# 	make get_next_line.a -C get_next_line

$(_OBJ):
	mkdir $@
	mkdir $(_OBJ)checks
	mkdir $(_OBJ)raycasting
	mkdir $(_OBJ)movement

clean:
	# make clean -C libft
	# make clean -C get_next_line
	$(RM) -r $(_OBJ)

fclean:	clean
	# make fclean -C libft
	# make fclean -C get_next_line
	$(RM) $(NAME)

re:	fclean all
