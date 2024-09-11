# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 13:54:50 by rteoh             #+#    #+#              #
#    Updated: 2024/09/11 00:18:10 by rteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDES = -I ./includes
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

SRC = philo.c utils.c init_life.c
SRC_DIR = src/
SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	$(CC) -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(OBJS) $(LIBFT) -o $(NAME) $(INCLUDES)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all