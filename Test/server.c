/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:56:36 by psanger           #+#    #+#             */
/*   Updated: 2024/01/08 13:35:45 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
#include <stdio.h>
# include <sys/types.h>

void signal_handler(int sig) {
	static int bit_arr[8];
	static int bit_stelle;
	int	int_char = 0;

	if (bit_stelle > 7)
		bit_stelle = 0;
	if (sig == SIGUSR1) {
		bit_arr[bit_stelle] = 1;
		bit_stelle++;
	}
	else if (sig == SIGUSR2) {
		bit_arr[bit_stelle] = 0;
		bit_stelle++;
	}
	if (bit_stelle == 8) {
		for (int j = 0; j < 8; j++) {
			int_char = int_char + bit_arr[j] * pow(2, 7 - j);
		}
		if (int_char == 0) {
			printf("\n");
			exit (0);
		}
		printf("%c", int_char);;
	}
}

void handle_process() {
	struct sigaction	sa;

	sa.sa_handler = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
		perror("Fehler bei der Signalbehandlung");
		exit(EXIT_FAILURE);
	}
}

int main(void) {
	printf("The Process ID is: %d\n", getpid());
	handle_process();
	while (1)
		usleep(100);
	return 0;
}
