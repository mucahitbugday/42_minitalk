/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbugday <mbugday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:46:01 by mbugday           #+#    #+#             */
/*   Updated: 2022/05/17 15:08:26 by mbugday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	message(int num)
{
	static int	power;
	static int	byte;

	if (num == SIGUSR1)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_putchar(byte);
		power = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_putstr("-----------------------------");
		ft_putchar('\n');
		ft_putstr("| Server running PID : ");
		ft_putnbr(pid);
		ft_putchar('\n');
		ft_putstr("-----------------------------");
		ft_putchar('\n');
		signal(SIGUSR1, message);
		signal(SIGUSR2, message);
		while (1)
			pause();
	}
	return (0);
}
