# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acyrenna <acyrenna@school21.ru>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 10:56:29 by acyrenna          #+#    #+#              #
#    Updated: 2021/02/13 23:55:38 by acyrenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a
ECHO =			echo
CC =			cc
CFLAGS =		-g -Wall -Werror -Wextra

INC_DIR =		./includes
HEADERS = 		$(INC_DIR)/ft_printf.h $(INC_DIR)/libft.h

SRCS = 			ft_abs.c ft_atoi.c ft_bzero.c ft_chrcmp.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isnotprint.c ft_isprint.c ft_isspace.c ft_itoa.c \
				ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
				ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
				ft_memdel.c ft_memmove.c ft_memset.c ft_min.c ft_putchar.c ft_putchar_fd.c \
				ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
				ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
				ft_strdup.c ft_strequ.c ft_strisize.c ft_striter.c ft_striteri.c \
				ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
				ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnlen.c \
				ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
				ft_tolower.c ft_toupper.c ft_memcpy.c ft_isupper.c ft_strndigc.c \
				ft_atoi_base.c ft_range.c ft_power.c ft_realloc.c ft_lstcreate.c get_next_line.c \
				ft_lstlast.c ft_lstfirst.c ft_strnchr.c ft_strrev.c ft_atol.c gexit.c ft_stack.c \
				ft_queue.c ft_btol.c

PRINTF_SRCS =	ft_get_nb_size.c ft_power_l.c ft_itoa_base.c  ft_ltoa_base.c  \
				write.c flags.c float.c ft_printf.c handle_chars.c handle_number.c \
				modificators.c parse.c print.c undefined.c pointer.c float_toa.c \
				float_helpers.c float_nan_inf.c float_operations.c float_write_long.c \

SRCS += 		$(PRINTF_SRCS)
OBJ_DIR =		.objects
SRC_DIR =		./sources
OBJ =			$(SRCS:%.c=$(OBJ_DIR)/%.o)

PURPLE_COLOR =	"\033[0;35m"
DEFAULT_COLOR =	"\033[0m"

all: $(NAME)
	@$(ECHO) "\n"

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(ECHO) "Libft:" $(PURPLE_COLOR) $(NAME) $(DEFAULT_COLOR) "\r"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@$(ECHO) "Libft:" $(PURPLE_COLOR) $< $(DEFAULT_COLOR) "\r"
	@$(CC) $(CFLAGS) -c $< -I$(INC_DIR) -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
