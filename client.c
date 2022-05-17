/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbugday <mbugday@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:46:10 by mbugday           #+#    #+#             */
/*   Updated: 2022/05/17 15:09:30 by mbugday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	convert_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc > 1 && argc < 4)
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0)
		{
			write(2, "Error.\nMissing PID.\n", 21);
			exit (EXIT_FAILURE);
		}
		if (argc == 3)
		{
			while (argv[2][i])
				convert_char(argv[2][i++], pid);
		}
		else if (argc == 2)
		{
			write(2, "Error.\nYou did not inputed a string.\n", 39);
			exit (EXIT_FAILURE);
		}
	}
	exit (EXIT_SUCCESS);
}
