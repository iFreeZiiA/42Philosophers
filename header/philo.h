#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "struct.h"

int	is_number(const char *str);
int	ft_atoi(const char *str);
int	ft_checkarg(int argc, char** argv, t_params *params);

#endif