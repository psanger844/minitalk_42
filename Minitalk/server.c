/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:28:20 by psanger           #+#    #+#             */
/*   Updated: 2023/12/21 17:10:23 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void print_char(int num) {
    static int bit_sequence[8];
    static int bit_stelle;

    if (bit_stelle == 0)
        bit_stelle = 8;

    if (num == 0 || num == 1) {
        bit_sequence[bit_stelle] = num;
        bit_stelle--;
    }
    if (bit_stelle <= 0) {
        int Zahl = 0;
        Zahl = bit_sequence[8] * 128 + bit_sequence[7] * 64 + bit_sequence[6] * 32 + bit_sequence[5] * 16 + bit_sequence[4] * 8 + bit_sequence[3] * 4 + bit_sequence[2] * 2 + bit_sequence[1] * 1;
        printf("%c", Zahl);
        bit_stelle = 8;
    }
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		print_char(1);
	if (sig == SIGUSR2)
		print_char(0);
}

void	handle_process()
{
	struct sigaction sa;

	sa.sa_handler = &signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int main(void)
{
	printf("The Process ID is : %d\n", getpid());

	while (1)
		handle_process();
	return (0);
}
