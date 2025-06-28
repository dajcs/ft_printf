# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemet <anemet@student.42luxembourg.lu>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 17:34:01 by anemet            #+#    #+#              #
#    Updated: 2025/06/28 17:54:41 by anemet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME of the final library
NAME = libftprintf.a

# compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# archiver command
AR = ar rcs

# remove command
RM = rm -f

# libft location and library file
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# ft_printf source files
SRCS = ft_printf.c \
       ft_print_primitives.c \
       ft_print_numbers.c \
       ft_print_hex.c \
       ft_print_ptr_utils.c

# object files
OBJS = $(SRCS:.c=.o)

# header file
INCS = ft_printf.h

# default rule
all: $(NAME)

# rule to build the final library
$(NAME): $(OBJS) $(LIBFT)
		# copy libft.a to create our library, then add our new objects to it
		cp $(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

# rule to build the libft dependency
$(LIBFT):
		@make -C $(LIBFT_DIR)

# rule to compile .c files into .o files
%.o: %.c $(INCS)
		$(CC) $(CFLAGS) -c $< -o $@

# clean rule: remove object files
clean:
		@make clean -C $(LIBFT_DIR)
		$(RM) $(NAME)

# full clean rule: clean + library removal
fclean: clean
		@make fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)

# rebuild rule
re: fclean all

# phony targets
.PHONY: all clean fclean re
