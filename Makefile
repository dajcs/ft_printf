# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anemet <anemet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/28 17:34:01 by anemet            #+#    #+#              #
#    Updated: 2025/07/02 15:11:25 by anemet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME of the final library
NAME = libftprintf.a

# compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# archiver command
AR = ar rcs

# remove command
RM = rm -f

# libft location and library file
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# ft_printf source files
SRCS = ft_printf.c \
       ft_parse_dispatch.c \
	   ft_print_cs.c \
	   ft_print_diu.c \
	   ft_print_px.c \
	   ft_print_utils.c \
	   ft_utoa.c

# object files
OBJS = $(SRCS:.c=.o)

# header file
INCS = ft_printf.h

# default rule
all: $(NAME)

# The bonus rule -- same as 'all'
bonus: $(NAME)

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
	$(RM) $(OBJS)

# full clean rule: clean + library removal
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

# rebuild rule
re: fclean all

# phony targets
.PHONY: all clean fclean re bonus
