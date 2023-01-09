/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:26:47 by nouahidi          #+#    #+#             */
/*   Updated: 2022/12/20 19:02:58 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(const char *st)
{
	int	i;
	int	r;
	int	nb;

	r = 1;
	nb = 0;
	i = 0;
	while ((st[i] >= 9 && st[i] <= 13) || st[i] == ' ')
		i++;
	if (st[i] == '+' || st[i] == '-')
	{
		if (st[i] == '-')
			r = -1;
	i++;
	}
	while (st[i] >= '0' && st[i] <= '9')
	{
		nb = (nb * 10) + (st[i] - '0');
		i++;
	}
	return (nb * r);
}

static void	send_char_to_server(char c, int pid)
{
	unsigned char	bt;
	int				i;

	i = 8;
	while (i--)
	{
		bt = (c >> i & 1);
		if (bt == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(0);
		}
		usleep(800);
	}
	return ;
}

static void	display_message(int signum)
{
	(void)signum;
	write(1, "message received\n", 18);
	exit(1);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			return (0);
		if (av[2][0] == '\0')
			return (0);
		while (av[2][i])
		{
			send_char_to_server(av[2][i], pid);
			i++;
		}
		signal(SIGUSR1, display_message);
		send_char_to_server('\n', pid);
		send_char_to_server('\0', pid);
	}
	return (0);
}
