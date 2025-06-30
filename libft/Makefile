# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemet <anemet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 11:43:39 by anemet            #+#    #+#              #
#    Updated: 2025/06/13 15:28:21 by anemet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                 libft                                        #
# **************************************************************************** #

# Library name
NAME 	:= libft.a

# Compiler and flags
CC 		:= cc
CFLAGS	:= -Wall -Wextra -Werror

# Public header
HEADER	:= libft.h

# **************************************************************************** #
# Mandatory Source files
# **************************************************************************** #
SRC		:= ft_atoi.c  ft_isascii.c ft_memcpy.c  ft_strlcat.c ft_strrchr.c \
           ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_tolower.c \
           ft_calloc.c ft_isprint.c ft_memset.c  ft_strlen.c  ft_toupper.c \
           ft_isalnum.c ft_memchr.c ft_strchr.c  ft_strncmp.c \
           ft_isalpha.c ft_memcmp.c ft_strdup.c  ft_strnstr.c \
           ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
           ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
           ft_putendl_fd.c ft_putnbr_fd.c

# Object files
OBJ		:= $(SRC:.c=.o)

# **************************************************************************** #
# Bonus Source files
# **************************************************************************** #
BONUS_SRC := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
             ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
             ft_lstmap.c

BONUS_OBJ := $(BONUS_SRC:.c=.o)

# ---------------------------------------------------------------------------- #
# Build rules                                                                  #
# ---------------------------------------------------------------------------- #

# Pattern rule: compile each .c -> .o (needs header for prototypes)
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Archive objects into the static library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Default target
all: $(NAME)

# Bonus target
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

# Remove object files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Remove objects + library
fclean: clean
	rm -f $(NAME)

# Rebuild from scratch
re: fclean all

.PHONY: all clean fclean re bonus
