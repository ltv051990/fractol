#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 19:10:24 by tlutsyk           #+#    #+#              #
#    Updated: 2018/02/21 19:10:25 by tlutsyk          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
ST_NORM =	$(SWITCH)0m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_SGREEN = $(SWITCH)33m

NAME = fractol
CFILES = main.c read.c julia.c celtic.c burningship.c batman.c mandelbar_4.c \
		mandelbrot_5.c mandelbar_cubic.c mandelbrot.c hooks.c

OFILES = $(CFILES:.c=.o)
FOLDER = libft
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
		@gcc -c $? $(FILES)

$(NAME): $(OFILES)
		@make -C $(FOLDER)
		@gcc $(FLAGS) $(OFILES) -L $(FOLDER) -lft -o $(NAME) -lpthread -lmlx -lm -framework OpenGL -framework AppKit
		@echo "$(STYLE_BOLD)$(COLOR_SGREEN) OK!!! fractal is READY!!!"
		@./bonus
		@say no problems

clean:
	@/bin/rm -f $(OFILES)
	@make clean -C $(FOLDER)
	@echo "$(STYLE_BOLD)$(COLOR_SGREEN) OK!!! ALL O_FILES DELETED!!!"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(FOLDER)
	@echo "$(STYLE_BOLD)$(COLOR_RED) fractal have been deleted"

re: fclean all

.PHONY: all clean fclean