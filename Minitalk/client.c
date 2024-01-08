/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanger <psanger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:24:30 by psanger           #+#    #+#             */
/*   Updated: 2023/12/21 17:09:38 by psanger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "LIBFT/libft.h"


// int** char_to_bin(char* str)
// {
//     int** ptr;
//     int  byte_index;
//     int  bit_index;
//     int  i;

//     byte_index = 0;
//     while (str[++byte_index]);
//     ptr = calloc(byte_index + 1, sizeof(int*));
//     if (!ptr)
//       return(NULL);
//     byte_index = 0;
//     // printf("Binary value -> ");
//     while (str[byte_index])
//     {
//         ptr[byte_index] = calloc(sizeof(int), 8);
//         if (!ptr[byte_index])
//             return(NULL);
//         bit_index = 7;
//         i = 0;
//         while (bit_index >= 0) {
//            ptr[byte_index][i++] = (str[byte_index] >> bit_index) & 1;
//         //    printf("%d -> %d\n", str[byte_index] >> bit_index, (str[byte_index] >> bit_index) & 1);
//            bit_index--;
//         }
//         // printf(" : ");
//         byte_index++;
//     }
//     return (ptr);
// }

// void test(char *str)
// {
// 	int	**ptr;

// 	ptr = char_to_bin(str);
// 	int i = 0;
// 	int	j = 0;
// 	printf("\n");
// 	printf("\n");
// 	while (i < ft_strlen(str))
// 	{
// 		while (j < 8)
// 		{
// 			printf("%d", ptr[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		j = 0;
// 		i++;
// 	}
// 	while (i)
// 	{
// 		free(ptr[i]);
// 		i--;
// 	}
// 	free(ptr);
// }

// void print_char(int num) {
//     static int bit_sequence[8];
//     static int bit_stelle;

//     if (bit_stelle == 0)
//         bit_stelle = 8;

//     if (num == 0 || num == 1) {
//         bit_sequence[bit_stelle] = num;
//         bit_stelle--;
//         // printf ("%d    ", num);
//         // printf ("test %d\n", bit_stelle);
//     }
//     if (bit_stelle <= 0) {
//         int Zahl = 0;
//         // for (int k = 0; k < 9; k++)
//         //     printf("%d", bit_sequence[k]);
//         // printf("\n");
//         Zahl = bit_sequence[8] * 128 + bit_sequence[7] * 64 + bit_sequence[6] * 32 + bit_sequence[5] * 16 + bit_sequence[4] * 8 + bit_sequence[3] * 4 + bit_sequence[2] * 2 + bit_sequence[1] * 1;
//         printf("%c", Zahl);
//         // printf("%d\n", Zahl);
//         bit_stelle = 8;
//     }
// }

void    send_signal(int zahl, int pid_server)
{
    int anzahl_bits = 8;
    for (int i = anzahl_bits - 1; i >= 0; i--) {
        usleep(20);
        int bit = (zahl >> i) & 1;
        if (bit == 1)
        {
            kill(pid_server, SIGUSR1);
        }
        if (bit == 0)
        {
            kill(pid_server, SIGUSR2);
        }
    }
}

int main(int argc, char **argv)
{
    int pid_server;
    int i = 0;

    if (argc != 3)
        return (0);
    pid_server = ft_atoi(argv[1]);
    while (argv[2][i] != '\0')
    {
        send_signal(argv[2][i], pid_server);
        i++;
    }
    return (0);
}
