/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_print_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qpeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 22:15:15 by qpeng             #+#    #+#             */
/*   Updated: 2018/10/01 22:21:29 by qpeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 1;
	i <<= 8;
	while (i >>= 1)
		(octet & i) ? write(1, "1", 1) : write(1, "0", 1);
}

// i = 256(1 0000 0000) at line 18 and i = 1000 0000 at the first while loop
// by using & operator, we can compare every bit of octect starting from the
// left to the right, and print 1 if there's 1.
/*------------------------------------------------------------------------------
int		main(void)
{
	print_bits(255);
	return (0);
}
------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Your function must be declared as follows:

void	print_bits(unsigned char octet);

Example, if you pass 2 to print_bits, it will print "00000010"
------------------------------------------------------------------------------*/
