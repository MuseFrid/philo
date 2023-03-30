# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduchesn <gduchesn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 21:45:24 by gduchesn          #+#    #+#              #
#    Updated: 2023/03/30 22:24:02 by gduchesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -pthread
INCLUDES = -I$(HEADERS_DIRECTORY)
REMOVE = rm -Rf
.PHONY: all clean fclean re

HEADERS_LIST = philo.h
HEADERS_DIRECTORY = ./include/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST =	$(LST) \
				main.c \
				check_arg.c \
				philo_utils.c \
				struct_init.c \
				gd_error.c \
				free_philo.c \
				init_thread.c \
				print_action.c \
				custom_usleep.c \
				routine.c \
				are_they_living.c \
				info_check.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

LST = $(addprefix lst/, $(LIST))
LIST = 			lstadd_back.c \
				lstclear.c \
				lstnew.c \
				lstlast.c

CREATE_O_DIRECTORY = $(OBJECTS_DIRECTORY) objects/lst/
OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(CREATE_O_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

clean:
	$(REMOVE) $(OBJECTS_DIRECTORY)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

#-fsanitize=thread -g
#-fsanitize=address -g
