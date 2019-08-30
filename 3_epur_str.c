/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
 */

#include <unistd.h>

#define is_space(c) (c == ' ' || c == '\t')
#define is_char(c) (c && !is_space(c))

int main(int ac, char **av)
{
	char *word;
	unsigned len;

	if (ac == 2)
	{
		word = av[1];
		while (is_space(*word)) /** leading space */
			word++;
		while (*word)
		{
			len = 0;
			while (is_char(*(word + len)))
				len++;
			if (len)
				word += write(1, word, len);
			while (is_space(*word))
				word++;
			if (*word)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}

/** Evilcat(Evilcat325) 's solution(https://github.com/Evilcat325) 
int main(int ac, char **av)
{
	char *word;
	unsigned len;

	len = 0;
	if (ac == 2)
	{
		word = av[1];
		while (*word)
			if (is_char(*word) && !(len = 0))
				while (is_char(*(word)) && word++ && ++len)
					len = is_char(*(word)) ? len : write(1, word - len, len);
			else if (len && is_char(*(word + 1)) && word++)
				write(1, " ", 1);
			else
				word++;
	}
	write(1, "\n", 1);
	return (0);
}
*/