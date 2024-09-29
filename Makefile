# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 13:54:50 by rteoh             #+#    #+#              #
#    Updated: 2024/09/29 05:24:00 by rteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDES = -I ./includes
CC = cc -g3
CFLAGS = -Wall -Wextra -Werror
FSAN_THREAD = -fsanitize=thread
FSAN_ADD = -fsanitize=address
# CFLAGS += $(FSAN_THREAD)
LIBFT = ./libft/libft.a

SRC = philo.c utils.c init_life.c \
	init_life2.c start_life.c waiter_routine.c life_cycle.c free.c
SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(INCLUDES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all