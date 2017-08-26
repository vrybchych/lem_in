#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybchyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/15 11:17:22 by vrybchyc          #+#    #+#              #
#    Updated: 2017/08/24 15:43:49 by vrybchyc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in

SRC = 	add_route.c\
		check_valid.c\
		find_route.c\
		ft_error.c\
		ft_free_tab.c\
		get_rooms.c\
		is_room.c\
		main.c\
		move.c\
		reader.c\
		set_globals.c\
		set_links.c\
		set_next_step.c\
		set_route_status.c\
		set_routes.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;1mmake libft...\033[0m"
	@make -C libft/
	@echo "\033[32;1mmake lem-in\033[0m"
	@gcc $(FLAGS) -o $(NAME) -L libft/ -lft $(OBJ)

.c.o:
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@echo "\033[31mRemoving lem-in...\033[0m"
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

norme:
	norminette $(SRC)
