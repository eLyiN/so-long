# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarribas <aarribas@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 09:08:07 by aarribas          #+#    #+#              #
#    Updated: 2022/08/11 01:22:03 by aarribas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# //= Variables =//

NAME	= so_long
NAME_B	= so_long_bonus
CFLAGS	= -Wall -Werror -Wextra
LIN_FL	= -ldl -lglfw -pthread -lm
MAC_FL	= -lglfw -L "/Users/aarribas/.brew/Cellar/glfw/3.3.8/lib" 
LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/libft


HEADERS	= -I ./includes -I $(LIBMLX)/include -I $(LIBFT)
LIBS	= $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
SRCS	= $(shell find ./src -iname "*.c")
SRCS_B	= $(shell find ./bonus -iname "*.c")
OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# //= Recipes =//

all: libft libmlx $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@$(MAKE) -C $(LIBMLX)

#%.o: %.c
#	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(CFLAGS) $(LIN_FL) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_B)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean


re: clean all

bonus: libft libmlx $(NAME_B)
	
$(NAME_B): $(OBJS_B)
	@$(CC) $(OBJS_B) $(LIBS) $(CFLAGS) $(LIN_FL) $(HEADERS) -o $(NAME_B)
	
.PHONY: all, clean, fclean, re, libmlx, libft, bonus