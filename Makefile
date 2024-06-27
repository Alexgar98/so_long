# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 12:43:59 by alexigar          #+#    #+#              #
#    Updated: 2024/04/08 12:07:46 by alexigar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

SOURCES = so_long.c \
		  endgame.c \
		  errors.c \
		  graphics.c \
		  map_checks.c \
		  place_chests.c \
		  free_stuff.c \
		  reading.c \
		  utils/get_next_line/get_next_line.c \

NORMAL = movements.c

BONUS = movements_bonus.c \
		animations.c

OBJS = $(SOURCES:.c=.o)

OBJNORMAL = $(NORMAL:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

$(NAME) : $(OBJS) $(OBJNORMAL)
	@$(CC) $(OBJS) $(OBJNORMAL) utils/libft/libft.a utils/ft_printf/libftprintf.a MLX42/libmlx42.a -I include -L "/Users/alexigar/.brew/opt/glfw/lib/" -lglfw -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

bonus : $(OBJS) $(OBJBONUS)
	@$(CC) $(OBJS) $(OBJBONUS) utils/libft/libft.a utils/ft_printf/libftprintf.a MLX42/libmlx42.a -I include -L "/Users/alexigar/.brew/opt/glfw/lib/" -lglfw -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

all : $(NAME)

%.o : %.c
	@$(CC) -c $(CCFLAGS) $< -o $@

clean :
	@rm -rf $(OBJS) $(OBJNORMAL) $(OBJBONUS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
.PHONY : all clean fclean re bonus