/* ***************************************************************************
 * Author  : Kura Peng (kpeng) <https://github.com/sayakura>
 * Created : 2018/10/05
 * Updated : 2018/10/05
 * ***************************************************************************/

#include <unistd.h>

#define is_alpha(c) (c >= 'a' && c <='z') ? 1 : 0
enum status{INVALID, HELP, SUCESS};
int 	g_mem;

void	print_bin(int num)
{
	long r = 1;
	r <<= 32;
	char count = 1;
	while (r >>= 1)
	{
		(r & num) ? write(1, "1", 1) : write(1, "0", 1);
		if (count % 8 == 0 && count != 32)
			write(1, " ", 1);
		count++;
	}
}

int		check_flags(char *str)
{
	unsigned i = 0;
	char valid = 1;
	if (str[i] != '-')
		return (INVALID);
	while (str[++i])
		if (!is_alpha(str[i]))
			return (INVALID);
	i = 1;
	while (str[i])
	{
		if (str[i] == 'h')
			return (HELP);
		g_mem |= (1 << (str[i] - 'a'));
		i++;
	}
	return (SUCESS);
}

int		main(int ac, char **av)
{
	unsigned i = 1;
	unsigned char status = 0;
	
	if (ac < 2)
	{
 		write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
		return (0);
	}
	else
	{
		while (av[i])
		{
			status = check_flags((av[i]));
			if (status == INVALID)
			{
				 write(1, "Invalid Option\n", 15);
				 return (0);
			}
			else if (status == HELP)
			{
				write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
				return (0);
			}
			i++;
		}
		print_bin(g_mem); 
	}
	return (0);
}

/* ***************************************************************************
Assignment name  : options
Expected files   : *.c *.h
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes an undefined number of arguments which could be 
considered as options and writes on standard output a representation of those
options as groups of bytes followed by a newline.

An option is an argument that begins by a '-' and have multiple characters 
which could be : abcdefghijklmnopqrstuvwxyz

All options are stocked in a single int and each options represents a bit of that
int, and should be stocked like this : 

00000000 00000000 00000000 00000000
******zy xwvutsrq ponmlkji hgfedcba

Launch the program without arguments or with the '-h' flag activated must print
an usage on the standard output, as shown in the following examples.

A wrong option must print "Invalid Option" followd by a newline.

Examples :
$>./options
options: abcdefghijklmnopqrstuvwxyz
$>./options -abc -ijk
00000000 00000000 00000111 00000111
$>./options -z
00000010 00000000 00000000 00000000
$>./options -abc -hijk
options: abcdefghijklmnopqrstuvwxyz
$>./options -%
Invalid Option
 * ***************************************************************************/