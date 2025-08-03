# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alearroy <alearroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 15:12:46 by alearroy          #+#    #+#              #
#    Updated: 2025/08/03 15:57:01 by alearroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME	= philosophers
CC 		= cc
FLAGS 	= -Wall -Wextra -Werror
RM 		= rm -f
PRINT	= echo
WAIT1	= sleep 1
WAIT0.3	= sleep 0.3
ERASE	= printf "\033[2K\r"
MAN = mandatory/
PAR = $(MAN)parsing/
PHI = $(MAN)philo/

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRC	= $(MAN)main.c $(PAR)lib.c $(PAR)parsing.c $(PAR)init.c $(PHI)routine.c		\
$(PHI)thread.c $(PHI)monitor.c $(PHI)routine_utils.c

OBJ = $(SRC:.c=.o)



################################################################################
##                                    COLOURS                                 ##
################################################################################

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW=\033[33m
COLOUR_MAGENTA=\033[35m
COLOUR_TURQUOISE=\033[36m	
COLOUR_END=\033[0m


################################################################################
##                                     RULES                                  ##
################################################################################

all : head $(NAME)

head :
	@$(PRINT) "$(COLOUR_MAGENTA)______ _     _ _       "
	@$(PRINT) "$(COLOUR_MAGENTA)| ___ \ |   (_) |      "
	@$(PRINT) "$(COLOUR_MAGENTA)| |_/ / |__  _| | ___  "
	@$(PRINT) "$(COLOUR_MAGENTA)|  __/| '_ \| | |/ _ \ "
	@$(PRINT) "$(COLOUR_MAGENTA)| |   | | | | | | (_) |"
	@$(PRINT) "$(COLOUR_MAGENTA)\_|   |_| |_|_|_|\___/ "
	@$(PRINT) "$(COLOUR_TURQUOISE)42MLG: by alearroy \n"
	@$(PRINT) "Project: \033[36m Push_swap $(COLOUR_TURQUOISE)"
	@$(PRINT) "Commands:\033[36m all clean fclean re $(COLOUR_END)\n"

$(NAME):	$(OBJ)
	@$(CC) $(FLAGS) -o $@ $^
	@$(PRINT) -n "$(COLOUR_YELLOW)\n ⏱  Creating $(NAME)";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT1);$(ERASE)
	@$(PRINT) "$(COLOUR_GREEN)\r  ✓   Created  $(NAME) $(COLOUR_END)\n"

%.o: %.c
	@$(PRINT) " ⏱  $(COLOUR_END)Compiling $@"
	@$(CC) $(FLAGS) -c $< -o $@
	@$(PRINT) "$(COLOUR_GREEN)\r  ✓   Compiled  $@ $(COLOUR_END)"

clean :
	@$(PRINT) "$(COLOUR_YELLOW) 🗑   Removing objects$(COLOUR_END)";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT1);$(ERASE)
	@$(RM) $(OBJ) $(BONUS_OB)
	@$(PRINT) "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed objects $(COLOUR_END)"

fclean: clean
	@$(PRINT) "$(COLOUR_YELLOW) 🗑   Removing $(NAME) $(COLOUR_END)";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT0.3)
	@$(PRINT) -n ".";$(WAIT1);$(ERASE)
	@$(RM) $(NAME) $(NAME_B)
	@$(PRINT) "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed  $(NAME) $(COLOUR_END)\n"

re :
	@$(MAKE) fclean
	@clear
	@$(MAKE) all

.PHONY: all clean fclean re
