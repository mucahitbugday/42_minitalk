#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	message(int num);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	convert_char(char c, int pid);

#endif
