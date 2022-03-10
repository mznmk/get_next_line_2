# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 23:12:52 by mmizuno           #+#    #+#              #
#    Updated: 2022/03/11 06:50:34 by mmizuno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ================================= Variable ================================= #

NAME			= get_next_line
NAME_BONUS		= get_next_line_bonus

INC_DIR			= ./
SRC_DIR			= ./

SRC_NAME		= get_next_line_utils.c \
				  get_next_line.c \
				  main.c
SRCS			= $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS			= $(SRCS:.c=.o)					  

SRC_NAME_BONUS	= get_next_line_utils_bonus.c \
				  get_next_line_bonus.c \
				  main.c
SRCS_BONUS		= $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS_BONUS		= $(SRCS:.c=.o)					  

CC				= gcc
CFLAG			= -Wall -Wextra -Werror -g -fsanitize=address

RM				= rm -f

# ---------------------------------- color ----------------------------------- #

ESC_RESET			= \033[0m
ESC_FNT_BOLD		= \033[1m
ESC_FNT_FINE		= \033[2m
ESC_FNT_ITALIC		= \033[3m
ESC_FNT_ULINE		= \033[4m
ESC_CLR_BLACK		= \033[38;5;00m
ESC_CLR_RED			= \033[38;5;01m
ESC_CLR_GREEN		= \033[38;5;02m
ESC_CLR_YELLOW		= \033[38;5;03m
ESC_CLR_BLUE		= \033[38;5;04m
ESC_CLR_MAGENTA		= \033[38;5;05m
ESC_CLR_CYAN		= \033[38;5;06m
ESC_CLR_WHITE		= \033[38;5;07m
ESC_CLR_PINK		= \033[38;5;213m

# =============================== Make Command =============================== #

# ---------------------------------- .c.o ------------------------------------ #

.c.o:
					$(CC) $(CFLAGS) $(INCDIR) -c $< -o $(<:.c=.o)

# --------------------------------- $(NAME) ---------------------------------- #

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ----------------------------------- all ------------------------------------ #

all:				$(NAME)

# ---------------------------------- bonus ----------------------------------- #

bonus:				$(OBJS_BONUS)
					$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
					@echo "$(ESC_FNT_BOLD)$(ESC_CLR_GREEN)[ $(NAME) successfully compiled !! ]$(ESC_RESET)"

# ---------------------------------- clean ----------------------------------- #

clean:
					$(RM) $(OBJS)

# ---------------------------------- fclean ---------------------------------- #

fclean:				clean
					$(RM) $(NAME)

# ------------------------------------ re ------------------------------------ #

re:					fclean all

# ---------------------------------- .PHONY ---------------------------------- #

.PHONY:				all bonus clean fclean re
