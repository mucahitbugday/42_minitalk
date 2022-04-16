#include "./minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

// Karakteri yeniden oluşturmak için gönderilen farklı bitlerin çevirisi
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

//8 bit iletildikten sonra karakteri görüntüleyebileceğim
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
		while (42)
			pause();
	}
	return (0);
}
