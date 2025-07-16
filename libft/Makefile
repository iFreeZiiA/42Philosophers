# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/12 12:24:45 by alearroy          #+#    #+#              #
#    Updated: 2025/02/04 18:31:31 by alearroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ifdef TERM
#$(info TERM is set to $(TERM))
#else
#export TERM = xterm
#$(info TERM was not set, defaulting to $(TERM))
#endif

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g3
RM = rm -f
PRINT		= echo
WAIT1		= sleep 1
WAIT0.3		= sleep 0.3
ERASE		= printf "\033[2K\r"

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRC = ft_isascii.c ft_isdigit.c ft_isprint.c ft_isalnum.c 	\
	ft_isalpha.c ft_tolower.c ft_toupper.c ft_bzero.c 		\
	ft_calloc.c ft_memcmp.c ft_memcpy.c ft_memmove.c 		\
	ft_memset.c ft_memchr.c ft_atoi.c ft_strlcat.c 			\
	ft_strlcpy.c ft_strlen.c ft_strchr.c ft_strncmp.c 		\
	ft_strnstr.c ft_strrchr.c ft_itoa.c ft_split.c 			\
	ft_strdup.c ft_striteri.c ft_strjoin.c ft_strmapi.c 	\
	ft_strtrim.c ft_substr.c ft_putchar_fd.c 				\
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c 			\
	ft_printf.c ft_printf_utils.c ft_strcmp.c				\
	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c 			\
	ft_lstlast_bonus.c ft_lstnew_bonus.c					\
	ft_lstsize_bonus.c ft_checker.c ft_printerr.c			\
	ft_printerr_utils.c ft_lstfree.c ft_lstprint.c			\
	get_next_line.c get_next_line_utils.c					\

OBJS_DIR	= obj
OBJS		= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))

################################################################################
##                                    COLOURS                                 ##
################################################################################

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW= \033[33m
COLOUR_MAGENTA=\033[35m
COLOUR_TURQUOISE=\033[36m	
COLOUR_END=\033[0m


################################################################################
##                                     RULES                                  ##
################################################################################

all : head $(NAME)

head : 
	@$(PRINT) -n "$(COLOUR_YELLOW)\n ⏱  Creating $(NAME)";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT1);$(ERASE)
	@$(PRINT) "$(COLOUR_GREEN)\r  ✓   Created  $(NAME) $(COLOUR_END)\n"
	@$(PRINT) "$(COLOUR_MAGENTA) (      (             (              "
	@$(PRINT) "$(COLOUR_MAGENTA) )\ )   )\ )     (    )\ )    *   )  "
	@$(PRINT) "$(COLOUR_MAGENTA)(()/(  (()/(   ( )\  (()/(    )  /(  "
	@$(PRINT) "$(COLOUR_MAGENTA) /(_))  /(_))  )((_)  /(_))  ( )(_)) "
	@$(PRINT) "$(COLOUR_MAGENTA)(_))   (_))   ((_)_  (_))_| (_(_())  "
	@$(PRINT) "$(COLOUR_MAGENTA)| |    |_ _|   | _ ) | |_   |_   _|  "
	@$(PRINT) "$(COLOUR_MAGENTA)| |__   | |    | _ \ | __|    | |    "
	@$(PRINT) "$(COLOUR_MAGENTA)|____| |___|   |___/ |_|      |_|    "
	@$(PRINT) "$(COLOUR_TURQUOISE)                42MLG: by alearroy \n"
	@$(PRINT) "Project: \033[36m libft $(COLOUR_TURQUOISE)"
	@$(PRINT) "Commands:\033[36m all bonus clean fclean re rebonus $(COLOUR_END)\n"\

$(OBJS_DIR):
			@mkdir -p $(OBJS_DIR)

$(NAME) : $(OBJS)
	@$(PRINT) "\n ⏱  Creating $(NAME)"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(PRINT) "$(COLOUR_GREEN)\r  ✓   Created  $(NAME) $(COLOUR_END)\n"

$(OBJS_DIR)/%.o:	%.c | $(OBJS_DIR)
	@$(PRINT) " ⏱  $(COLOUR_END)Compiling $@"
	@$(CC) $(FLAGS) -c $< -o $@
	@$(PRINT) "$(COLOUR_GREEN)\r  ✓   Compiled  $@ $(COLOUR_END)"

clean :
	@$(PRINT) "$(COLOUR_YELLOW) 🗑   Removing objects$(COLOUR_END)"
	@$(RM)r $(OBJS_DIR) $(LIB_DIR)/obj
	@$(PRINT) "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed  objects $(COLOUR_END)"

fclean: clean
	@$(PRINT) "$(COLOUR_YELLOW) 🗑   Removing $(NAME)$(COLOUR_END)"
	@$(RM) $(NAME)
	@$(PRINT) "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed  $(NAME) $(COLOUR_END)\n"

re :
	@$(MAKE) fclean
	@clear
	@$(MAKE) all


.PHONY: all clean fclean re
