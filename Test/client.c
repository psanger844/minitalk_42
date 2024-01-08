/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:57:00 by psanger           #+#    #+#             */
/*   Updated: 2023/12/30 09:40:44 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	send_signal(int ascii, int server_pid)
{
	int i;
	int bit;

	i = 7;
	while (i >= 0)
	{
		usleep(2000);
		bit = (ascii >> i) & 1;
		if (bit == 1)
		{
			kill(server_pid, SIGUSR1);
			printf ("1");
		}
		else if (bit == 0)
		{
			kill(server_pid, SIGUSR2);
			printf("0");
		}
		i--;
	}
	printf("  | %c\n", ascii);
}

void	test(char *str, int server_pid)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		send_signal(str[i], server_pid);
		i++;
	}
	send_signal(0, server_pid);
}

int main(int argc, char **argv)
{
	int client_pid;

	client_pid = getpid();
	printf("client pit = %d\n", client_pid);
	if (argc != 3)
		return (0);
	test(argv[2], atoi(argv[1]));
    return (0);
}
