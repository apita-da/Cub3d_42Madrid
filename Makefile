# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/27 11:29:48 by apita-da          #+#    #+#              #
#    Updated: 2021/02/16 17:52:28 by apita-da         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=  raycasting.c movement.c main.c readmap.c window.c\
					utils1.c utils2.c utils3.c parse_map.c\
					line.c get_res.c textures.c ceiling.c floor.c\
					
					
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBS			=  -Lmlx -lmlx -framework OpenGL -framework AppKit -o
# linux?
LIBS			= -lmlx -lX11 -lXext -lbsd -lm
MLX				= libmlx.dylib

NAME			= cub3d

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} libmlx.dylib

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .


clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
