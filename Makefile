# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaverty <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 19:44:22 by aaverty           #+#    #+#              #
#*   Updated: 2016/03/17 10:49:18 by aaverty          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRC_PATH = ./src/
SRC_NAME = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
 ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c\
 ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strcchr.c\
 ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
 ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
 ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c\
 ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
 ft_strjoin.c ft_strtrim.c ft_strtrim2.c ft_strsplit.c ft_itoa.c ft_putchar.c\
 ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c\
 ft_putnbr.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c\
 ft_lstiter.c ft_lstmap.c ft_lstgetn.c ft_lst_push_back.c ft_strrev.c\
 ft_lstlen.c ft_create_dlist.c ft_create_node.c ft_dlst_push_back.c\
 ft_itoa_base.c ft_putaddr.c ft_get_next_line.c ft_cat.c ft_isspace.c \
 ft_without_space_len.c ft_strupcase.c ft_strnrev.c ft_sqrt.c ft_swap.c\
 ft_strlowcase.c ft_strcapitalize.c ft_str_is_uppercase.c ft_str_is_printable.c\
 ft_str_is_numeric.c ft_str_is_lowercase.c ft_str_is_alhpa.c ft_nbword.c\
 ft_recursive_power.c ft_recursive_factorial.c ft_is_prime.c ft_is_negative.c\
 ft_find_next_prime.c ft_power.c ft_lstaddend.c ft_floorl.c ft_wstrlen.c


SRC_PRINTF_PATH = ./ft_printf/
SRC_PRINTF_NAME = ft_printf.c check_arg.c lstdel.c printf_a.c printf_ls.c \
		   printf_d.c printf_o.c printf_u.c printf_x.c printf_f.c printf_e.c \
		   printf_g.c printf_p.c printf_n.c printf_b.c printf_r.c printf_k.c \
		   ft_putstr_args.c printf_s.c printf_percent.c \
		   va_arg1.c va_arg2.c va_arg3.c va_arg4.c printf_lc.c \
		   find_percent.c printf_hhd.c printf_hhu.c printf_hho.c printf_hd.c \
		   printf_ho.c printf_hhx.c printf_hu.c check_color.c

OBJ_PATH = ./obj/
OBJ_PRINTF_NAME = $(SRC_PRINTF_NAME:.c=.o)
OBJ_NAME = $(SRC_NAME:.c=.o)

CFLAGS =  -Wall -Wextra -Werror -g

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
SRC_PRINTF = $(addprefix $(SRC_PRINTF_PATH),$(SRC_PRINTF_NAME))
OBJ_PRINTF = $(addprefix $(OBJ_PATH),$(OBJ_PRINTF_NAME))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "\033[36mLIBFT:\033[0m [\033[35mCompilation:\033[0m\033[32m $@\033[0m]"
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) -I./inc -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PRINTF_PATH)%.c
	@echo "\033[34mFT_PRINTF:\033[0m [\033[35mCompilation:\033[0m\033[32m $@\033[0m]"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(OBJ_PRINTF)
	@ar rc $(NAME) $(OBJ) $(OBJ_PRINTF)
	@ranlib $(NAME)
	@echo "[\033[36m------------------------------------------\033[0m]"
	@echo "[\033[36m---------------- LIBFT - OK --------------\033[0m]"
	@echo "[\033[36m------------------------------------------\033[0m]"
	@echo "                                                           "
	@echo "[\033[34m------------------------------------------\033[0m]"
	@echo "[\033[34m-------------- FT_PRINTF - OK ------------\033[0m]"
	@echo "[\033[34m------------------------------------------\033[0m]"

clean:
	@rm -fv $(OBJ) $(OBJ_PRINTF)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "[\033[31mSuppression des .o\033[0m]"

fclean: clean
	@rm -fv $(NAME)
	@echo "[\033[31mSuppression des .o\033[0m]"
	@echo "[\033[31mSuppression de \033[36m$(NAME)\033[0m\033[0m]"

re: fclean all

.PHONY: all clean fclean re
