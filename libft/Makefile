# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 14:55:22 by jrey-roj          #+#    #+#              #
#    Updated: 2023/10/24 14:54:19 by jrey-roj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	   ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	   ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
	   ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
	   ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	   ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	   get_next_line/get_next_line.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
		ft_lstmap_bonus.c ft_lstlast_bonus.c ft_lstiter_bonus.c

DIR_PRINTF =		ft_printf/
SOURCES_PRINTF = 	ft_mayushex.c ft_minushex.c ft_printf.c ft_ptohex.c \
					ft_putchar.c ft_putnbr.c ft_putstr.c ft_putunsnbr.c
S_PRINTF = 			$(addprefix $(DIR_PRINTF), $(SOURCES_PRINTF))
OBJ_PRINTF = 		$(S_PRINTF:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rcs

OBJECTS = $(SOURCE:.c=.o)

BONUSOBJECTS = $(BONUS:.c=.o)

INCLUDE = libft.h

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus:	$(BONUS) $(BONUSOBJECTS) $(INCLUDE)
	@$(AR) $(NAME) $(BONUSOBJECTS)
	@echo "Libft bonus created"

$(NAME): $(OBJECTS) $(OBJ_PRINTF) $(INCLUDE)
	@$(AR) $(NAME) $(OBJECTS) $(OBJ_PRINTF)
	@echo "Libft created"

clean:
	@$(RM) $(OBJECTS) $(BONUSOBJECTS) $(OBJ_PRINTF)
	@echo "Libft bonus, Libft and Printf objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all bonus clean fclean re printf